/**
 *  libmrhvt
 *  Copyright (C) 2021 - 2022 Jens Brörken
 *
 *  This software is provided 'as-is', without any express or implied
 *  warranty.  In no event will the authors be held liable for any damages
 *  arising from the use of this software.
 *
 *  Permission is granted to anyone to use this software for any purpose,
 *  including commercial applications, and to alter it and redistribute it
 *  freely, subject to the following restrictions:
 *
 *  1. The origin of this software must not be misrepresented; you must not
 *     claim that you wrote the original software. If you use this software
 *     in a product, an acknowledgment in the product documentation would be
 *     appreciated but is not required.
 *
 *  2. Altered source versions must be plainly marked as such, and must not be
 *     misrepresented as being the original software.
 *
 *  3. This notice may not be removed or altered from any source distribution.
 */

// C / C++
#include <clocale>
#include <unordered_map>
#include <utility>

// External
#include <libmrhbf.h>

// Project
#include "../../../include/libmrhvt/libmrhvt/Input/MRH_InputTrigger.h"
#include "../../../include/libmrhvt/libmrhvt/String/MRH_LocalisedPath.h"
#include "../../../include/libmrhvt/libmrhvt/String/MRH_Convert.h"
#include "../../../include/libmrhvt/libmrhvt/String/MRH_Compare.h"

// Pre-defined
namespace
{
    enum Identifier
    {
        // Block Names
        BLOCK_COMPARE_METHOD = 0,
        BLOCK_TRIGGER = 1,
        
        // Compare Method Keys
        KEY_COMPARE_METHOD_ID = 2,
        KEY_COMPARE_METHOD_LS_SIMILARITY = 3,
        
        // Trigger Keys
        KEY_TRIGGER_STRING = 4,
        KEY_TRIGGER_WEIGHT = 5,
        KEY_TRIGGER_VALUE = 6,
        
        // Bounds
        IDENTIFIER_MAX = KEY_TRIGGER_VALUE,
        
        IDENTIFIER_COUNT = IDENTIFIER_MAX + 1
    };

    const char* p_Identifier[IDENTIFIER_COUNT] =
    {
        // Block Names
        "CompareMethod",
        "Trigger",
        
        // Compare Method Keys
        "Identifier",
        "LS_Similarity",
        
        // Trigger Keys
        "String",
        "Weight",
        "Value"
    };
}


//*************************************************************************************
// Constructor / Destructor
//*************************************************************************************

MRH_InputTrigger::MRH_InputTrigger(std::string const& s_FilePath) : e_CompareMethod(DEFAULT_COMPARE),
                                                                    f64_LSSimilarity(MRH_StringCompareLS::f64_RequiredMax)
{
    try
    {
        SetupFile(s_FilePath);
    }
    catch (MRH_VTException& e)
    {
        throw;
    }
}

MRH_InputTrigger::MRH_InputTrigger(std::string s_DirPath,
                                   std::string const& s_FileName) : e_CompareMethod(DEFAULT_COMPARE),
                                                                    f64_LSSimilarity(MRH_StringCompareLS::f64_RequiredMax)
{
    try
    {
        SetupFile(MRH_LocalisedPath::GetPath(s_DirPath, s_FileName));
    }
    catch (MRH_VTException& e)
    {
        throw;
    }
}

MRH_InputTrigger::~MRH_InputTrigger() noexcept
{}

//*************************************************************************************
// Setup
//*************************************************************************************

void MRH_InputTrigger::SetupFile(std::string const& s_FilePath)
{
    try
    {
        MRH_BlockFile c_File(s_FilePath);
        
        for (auto& Block : c_File.l_Block)
        {
            std::string s_Name(Block.GetName());
            
            if (s_Name.compare(p_Identifier[BLOCK_COMPARE_METHOD]) == 0)
            {
                try
                {
                    e_CompareMethod = static_cast<TriggerCompareMethod>(std::stoull(Block.GetValue(p_Identifier[KEY_COMPARE_METHOD_ID])));
                    f64_LSSimilarity = static_cast<MRH_Sfloat64>(std::stod(Block.GetValue(p_Identifier[KEY_COMPARE_METHOD_LS_SIMILARITY])));
                }
                catch (...)
                {}
            }
            else if (s_Name.compare(p_Identifier[BLOCK_TRIGGER]) == 0)
            {
                try
                {
                    dq_Trigger.emplace_back(Block.GetValue(p_Identifier[KEY_TRIGGER_STRING]),
                                            static_cast<MRH_Uint32>(std::stoull(Block.GetValue(p_Identifier[KEY_TRIGGER_WEIGHT]))),
                                            static_cast<MRH_Sint32>(std::stoi(Block.GetValue(p_Identifier[KEY_TRIGGER_VALUE]))));
                }
                catch (...)
                {}
            }
        }
    }
    catch (MRH_BFException& e)
    {
        throw MRH_VTException(e.what2() + " (" + e.filepath2() + ")");
    }
    catch (MRH_VTException& e)
    {
        throw;
    }
    catch (std::exception& e)
    {
        throw MRH_VTException(e.what());
    }
}

//*************************************************************************************
// Evaluate
//*************************************************************************************

bool MRH_InputTrigger::SearchTrigger(std::string const& s_String, std::string const& s_Trigger) const noexcept
{
    switch (e_CompareMethod)
    {
        case DEFAULT_COMPARE:
            return MRH_StringCompareDC::ContainedIn(s_Trigger, s_String);
        case LEVENSHTEIN:
            return MRH_StringCompareLS::ContainedIn(s_Trigger, s_String, f64_LSSimilarity);
            
        default:
            return false;
    }
}

MRH_InputTrigger::Evaluation MRH_InputTrigger::Evaluate(std::string s_String, MRH_Uint32 u32_RequiredWeight) const noexcept
{
    if (dq_Trigger.size() == 0 || s_String.size() == 0)
    {
        return Evaluation(MRH_Trigger::s32_ValueInvalid,
                          MRH_Trigger::u32_WeightMin);
    }
    
    // Convert to lowercase (like trigger strings)
    MRH_StringConvert::ToLower(s_String);
    
    // Grab triggers which match the weight requirement
    // NOTE: <Trigger Value, Total Trigger Weight>
    std::unordered_map<MRH_Sint32, MRH_Uint32> m_Matches;
    std::unordered_map<MRH_Sint32, MRH_Uint32>::iterator It;
    
    for (auto& Trigger : dq_Trigger)
    {
        // Grab matches entry
        if ((It = m_Matches.find(Trigger.GetValue())) == m_Matches.end())
        {
            if (m_Matches.insert(std::make_pair(Trigger.GetValue(), MRH_Trigger::u32_WeightMin)).second == false)
            {
                // Insert failed
                continue;
            }
            
            It = m_Matches.find(Trigger.GetValue());
        }
        
        // Search for the trigger
        if (SearchTrigger(s_String, Trigger.GetString()) == true)
        {
            It->second += Trigger.GetWeight();
        }
    }
    
    // Triggers have been found, search for the matching one
    Evaluation c_Result(MRH_Trigger::s32_ValueInvalid,
                        MRH_Trigger::u32_WeightMin);
    
    for (It = m_Matches.begin(); It != m_Matches.end(); ++It)
    {
        if (It->second >= u32_RequiredWeight && It->second > c_Result.second)
        {
            c_Result.first = It->first;
            c_Result.second = It->second;
        }
    }
    
    return c_Result;
}

//*************************************************************************************
// Add
//*************************************************************************************

void MRH_InputTrigger::AddTrigger(MRH_Trigger const& c_Trigger) noexcept
{
    dq_Trigger.emplace_back(c_Trigger);
}

//*************************************************************************************
// Remove
//*************************************************************************************

void MRH_InputTrigger::RemoveTrigger(size_t us_Trigger)
{
    if (dq_Trigger.size() <= us_Trigger)
    {
        throw MRH_VTException("Invalid trigger position " + std::to_string(us_Trigger) + " specified!");
    }
    
    dq_Trigger.erase(dq_Trigger.begin() + us_Trigger);
}

//*************************************************************************************
// Getters
//*************************************************************************************

size_t MRH_InputTrigger::GetTriggerCount() const noexcept
{
    return dq_Trigger.size();
}

MRH_Trigger& MRH_InputTrigger::GetTrigger(size_t us_Trigger)
{
    if (dq_Trigger.size() <= us_Trigger)
    {
        throw MRH_VTException("Invalid trigger position " + std::to_string(us_Trigger) + " specified!");
    }
    
    return dq_Trigger[us_Trigger];
}

MRH_Trigger const& MRH_InputTrigger::GetTrigger(size_t us_Trigger) const
{
    if (dq_Trigger.size() <= us_Trigger)
    {
        throw MRH_VTException("Invalid trigger position " + std::to_string(us_Trigger) + " specified!");
    }
    
    return dq_Trigger[us_Trigger];
}

MRH_InputTrigger::TriggerCompareMethod MRH_InputTrigger::GetCompareMethod() const noexcept
{
    return e_CompareMethod;
}

MRH_Sfloat64 MRH_InputTrigger::GetLSSimilarity() const noexcept
{
    return f64_LSSimilarity;
}

//*************************************************************************************
// Setters
//*************************************************************************************

void MRH_InputTrigger::SetCompareMethod(TriggerCompareMethod e_CompareMethod)
{
    if (e_CompareMethod > TRIGGER_COMPARE_METHOD_MAX)
    {
        throw MRH_VTException("Invalid compare method " + std::to_string(e_CompareMethod) + " specified!");
    }
    
    this->e_CompareMethod = e_CompareMethod;
}

void MRH_InputTrigger::SetLSSimilarity(MRH_Sfloat64 f64_Similarity) noexcept
{
    if (f64_Similarity < MRH_StringCompareLS::f64_RequiredMin)
    {
        f64_LSSimilarity = MRH_StringCompareLS::f64_RequiredMin;
    }
    else if (f64_Similarity > MRH_StringCompareLS::f64_RequiredMax)
    {
        f64_LSSimilarity = MRH_StringCompareLS::f64_RequiredMax;
    }
    else
    {
        f64_LSSimilarity = f64_Similarity;
    }
}
