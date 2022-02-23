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

// External
#include <MRH_Event.h>

// Project
#include "../../../include/libmrhvt/libmrhvt/String/MRH_SpeechString.h"

// Pre-defined
#define MRH_SPEECH_STRING_CHUNK_SIZE (MRH_EVENT_DATA_SIZE_MAX - 9) // ID, Part, Type


//*************************************************************************************
// Constructor / Destructor
//*************************************************************************************

MRH_SpeechString::MRH_SpeechString(MRH_Uint32 u32_ID) noexcept : u32_ID(u32_ID),
                                                                 c_End(false, 0)
{}

MRH_SpeechString::MRH_SpeechString(std::string const& s_String,
                                   MRH_Uint32 u32_Part,
                                   MRH_Uint32 u32_ID,
                                   bool b_End) : u32_ID(u32_ID),
                                                 c_End(b_End, u32_Part)
{
    auto It = m_Part.insert(std::make_pair(u32_Part, s_String));
    if (It.second == false)
    {
        throw MRH_VTException("Failed to create initial string part " + std::to_string(u32_Part) + "!");
    }
}

MRH_SpeechString::~MRH_SpeechString() noexcept
{}

//*************************************************************************************
// Split
//*************************************************************************************

std::map<MRH_Uint32, std::string> MRH_SpeechString::SplitString(std::string s_String)
{
    std::map<MRH_Uint32, std::string> m_Result;
    std::string s_Chunk;
    MRH_Uint32 u32_PartID = 0;
    
    while (s_String.size() > 0)
    {
        if (s_String.size() > MRH_SPEECH_STRING_CHUNK_SIZE)
        {
            s_Chunk = s_String.substr(0, MRH_SPEECH_STRING_CHUNK_SIZE);
            s_String.erase(s_String.begin(), s_String.begin() + MRH_SPEECH_STRING_CHUNK_SIZE);
        }
        else
        {
            s_Chunk = s_String;
            s_String = "";
        }
        
        try
        {
            if (m_Result.insert(std::make_pair(u32_PartID, s_Chunk)).second == false)
            {
                throw MRH_VTException("Map insertion failed for part " + std::to_string(u32_PartID));
            }
            
            ++u32_PartID;
        }
        catch (std::exception& e)
        {
            throw MRH_VTException("Failed to split string: " + std::string(e.what()));
        }
    }
    
    return m_Result;
}

//*************************************************************************************
// Reset
//*************************************************************************************

void MRH_SpeechString::Reset(MRH_Uint32 u32_ID) noexcept
{
    m_Part.clear();
    c_End.first = false;
    c_End.second = 0;
    this->u32_ID = u32_ID;
}

void MRH_SpeechString::Reset(std::string const& s_String, MRH_Uint32 u32_ID, MRH_Uint32 u32_Part, bool b_End)
{
    Reset(u32_ID);
    
    try
    {
        Add(s_String, u32_Part, b_End);
    }
    catch (...)
    {
        throw;
    }
}

//*************************************************************************************
// Add
//*************************************************************************************

MRH_SpeechString::State MRH_SpeechString::Add(std::string const& s_String, MRH_Uint32 u32_Part, bool b_End)
{
    if (m_Part.find(u32_Part) != m_Part.end())
    {
        throw MRH_VTException("The given part already exists!");
    }
    else if (c_End.first == true)
    {
        if (c_End.second <= u32_Part)
        {
            throw MRH_VTException("The given part exceeds the already set end part!");
        }
        else if (b_End == true)
        {
            throw MRH_VTException("The end part is already set!");
        }
    }
    
    auto It = m_Part.insert(std::make_pair(u32_Part, s_String));
    if (It.second == false)
    {
        throw MRH_VTException("Failed to add string part " + std::to_string(u32_Part) + "!");
    }
    
    // Is this the end?
    if (c_End.first == false && b_End == true)
    {
        c_End.first = true;
        c_End.second = u32_Part;
        
        // Anything left after end? Remove in our ordered map
        auto End = m_Part.find(u32_Part);
        
        if (End != --(m_Part.end()))
        {
            m_Part.erase(++End, m_Part.end());
        }
    }
    
    // Check completion
    return GetState();
}

//*************************************************************************************
// Getters
//*************************************************************************************

MRH_SpeechString::State MRH_SpeechString::GetState() const noexcept
{
    MRH_Uint32 u32_Part = 0;
    
    for (auto& Part : m_Part)
    {
        if (Part.first != u32_Part)
        {
            return c_End.first == true ? END_KNOWN : UNFINISHED;
        }
        
        // Increase part for next matching check
        ++u32_Part;
    }
    
    return c_End.first == true ? COMPLETE : UNFINISHED;
}

std::string MRH_SpeechString::GetString() const noexcept
{
    std::string s_Result = "";
    
    for (auto& Part : m_Part)
    {
        s_Result += Part.second;
    }
    
    return s_Result;
}

MRH_Uint32 MRH_SpeechString::GetID() const noexcept
{
    return u32_ID;
}
