/**
 *  libmrhvt
 *  Copyright (C) 2021 Jens Brörken
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
#include <cstdlib>
#include <ctime>

// External
#include <libmrhbf.h>

// Project
#include "../../../include/libmrhvt/libmrhvt/Output/MRH_OutputGenerator.h"
#include "../../../include/libmrhvt/libmrhvt/String/MRH_LocalisedPath.h"

// Pre-defined
namespace
{
    enum Identifier
    {
        // Block Names
        BLOCK_SENTENCE = 0,
        BLOCK_PLACEMENT = 1,
        BLOCK_WORD = 2,
        
        // Sentence Keys
        KEY_SENTENCE_STRING = 3,
        KEY_SENTENCE_CHANCE = 4,
        
        // Placement Keys
        KEY_PLACEMENT_STRING = 5,
        KEY_PLACEMENT_WORDGROUP = 6,
        
        // Word Keys
        KEY_WORD_STRING = 7,
        KEY_WORD_CHANCE,
        KEY_WORD_WORDGROUP,
        
        // Bounds
        IDENTIFIER_MAX = KEY_WORD_WORDGROUP,
        
        IDENTIFIER_COUNT = IDENTIFIER_MAX + 1
    };

    const char* p_Identifier[IDENTIFIER_COUNT] =
    {
        // Block Names
        "Sentence",
        "Placement",
        "Word",
        
        // Sentence Keys
        "String",
        "Chance",
        
        // Placement Keys
        "String",
        "WordGroup",
        
        // Word Keys
        "String",
        "Chance",
        "WordGroup"
    };
}


//*************************************************************************************
// Constructor / Destructor
//*************************************************************************************

MRH_OutputGenerator::MRH_OutputGenerator(std::string const& s_FilePath)
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

MRH_OutputGenerator::MRH_OutputGenerator(std::string s_DirPath,
                                         std::string const& s_FileName)
{
    try
    {
        SetupFile(MRH_LocalisedPath::GetPath(s_DirPath, s_FileName));
    }
    catch (...)
    {
        try
        {
            SetupFile(MRH_LocalisedPath::GetPathDefault(s_DirPath, s_FileName));
        }
        catch (MRH_VTException& e)
        {
            throw;
        }
    }
}

MRH_OutputGenerator::~MRH_OutputGenerator() noexcept
{}

//*************************************************************************************
// Setup
//*************************************************************************************

void MRH_OutputGenerator::SetupFile(std::string const& s_FilePath)
{
    try
    {
        MRH_BlockFile c_File(s_FilePath);
        
        for (auto& Block : c_File.l_Block)
        {
            std::string s_Name(Block.GetName());
            
            if (s_Name.compare(p_Identifier[BLOCK_SENTENCE]) == 0)
            {
                dq_Sentence.emplace_back(Block.GetValue(p_Identifier[KEY_SENTENCE_STRING]),
                                         static_cast<MRH_Sfloat64>(std::stod(Block.GetValue(p_Identifier[KEY_SENTENCE_CHANCE]))));
            }
            else if (s_Name.compare(p_Identifier[BLOCK_PLACEMENT]) == 0)
            {
                dq_Placement.emplace_back(Block.GetValue(p_Identifier[KEY_PLACEMENT_STRING]),
                                          static_cast<MRH_Uint32>(std::stoull(Block.GetValue(p_Identifier[KEY_PLACEMENT_WORDGROUP]))));
            }
            else if (s_Name.compare(p_Identifier[BLOCK_WORD]) == 0)
            {
                MRH_Uint32 u32_GroupID = static_cast<MRH_Uint32>(std::stoull(Block.GetValue(p_Identifier[KEY_WORD_WORDGROUP])));
                
                auto Word = m_Word.find(u32_GroupID);
                if (Word == m_Word.end())
                {
                    if (m_Word.insert(std::make_pair(u32_GroupID, std::deque<MRH_Word>())).second == false)
                    {
                        continue;
                    }
                    
                    Word = m_Word.find(u32_GroupID);
                }
                
                Word->second.emplace_back(Block.GetValue(p_Identifier[KEY_WORD_STRING]),
                                          u32_GroupID,
                                          static_cast<MRH_Sfloat64>(std::stod(Block.GetValue(p_Identifier[KEY_WORD_CHANCE]))));
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
// Generate
//*************************************************************************************

size_t MRH_OutputGenerator::SelectElement(std::vector<std::pair<size_t, MRH_Sfloat64>>& v_Chance) const noexcept
{
    MRH_Sfloat64 f64_Required;
    size_t us_Pos;
    
#ifdef __APPLE__
    sranddev();
#else
    srand(time(NULL));
#endif
    
    while (v_Chance.size() > 1)
    {
        f64_Required = static_cast<MRH_Sfloat64>(((rand() % 100) + 1) / 100.f);
        us_Pos = rand() % v_Chance.size();
        
        if (v_Chance[us_Pos].second < f64_Required)
        {
            v_Chance.erase(v_Chance.begin() + us_Pos);
        }
    }
    
    return v_Chance[0].first;
}

const MRH_Sentence& MRH_OutputGenerator::RandomSentence() const
{
    if (dq_Sentence.size() == 1)
    {
        return dq_Sentence[0];
    }
    
    std::vector<std::pair<size_t, MRH_Sfloat64>> v_Chance;
    
    for (size_t i = 0; i < dq_Sentence.size(); ++i)
    {
        v_Chance.emplace_back(i, dq_Sentence[i].GetUseChance());
    }
    
    return dq_Sentence[SelectElement(v_Chance)];
}

const MRH_Word& MRH_OutputGenerator::RandomWord(MRH_Uint32 u32_GroupID) const
{
    auto Group = m_Word.find(u32_GroupID);
    
    if (Group == m_Word.end() || Group->second.size() == 0)
    {
        throw MRH_VTException("No word available!");
    }
    else if (Group->second.size() == 1)
    {
        return Group->second[0];
    }
    
    std::vector<std::pair<size_t, MRH_Sfloat64>> v_Chance;
    
    for (size_t i = 0; i < Group->second.size(); ++i)
    {
        v_Chance.emplace_back(i, Group->second[i].GetUseChance());
    }
    
    return Group->second[SelectElement(v_Chance)];
}

std::string MRH_OutputGenerator::Generate() const
{
    if (dq_Sentence.size() == 0)
    {
        throw MRH_VTException("Missing output elements!");
    }
    
    try
    {
        // Select a sentence
        const MRH_Sentence& c_Sentence = RandomSentence();
        std::string s_Result(c_Sentence.GetString());
        
        // Now try placements
        for (auto& Placement : dq_Placement)
        {
            std::string s_Placement(Placement.GetString());
            MRH_Uint32 u32_GroupID = Placement.GetGroupID();
            size_t us_Start;
            
            while ((us_Start = s_Result.find(s_Placement)) != std::string::npos)
            {
                // Randomize word each time for multiple placement instances
                s_Result.replace(us_Start, s_Placement.size(), RandomWord(u32_GroupID).GetString());
            }
        }
        
        return s_Result;
    }
    catch (MRH_VTException& e)
    {
        throw;
    }
}

//*************************************************************************************
// Add
//*************************************************************************************

void MRH_OutputGenerator::AddWord(MRH_Word const& c_Word) noexcept
{
    auto Group = m_Word.find(c_Word.GetGroupID());
    
    if (Group == m_Word.end())
    {
        m_Word.insert(std::make_pair(c_Word.GetGroupID(), std::deque<MRH_Word>()));
        Group = m_Word.find(c_Word.GetGroupID());
    }
    
    Group->second.emplace_back(c_Word);
}

void MRH_OutputGenerator::AddPlacement(MRH_Placement const& c_Placement) noexcept
{
    dq_Placement.emplace_back(c_Placement);
}

void MRH_OutputGenerator::AddSentence(MRH_Sentence const& c_Sentence) noexcept
{
    dq_Sentence.emplace_back(c_Sentence);
}

//*************************************************************************************
// Remove
//*************************************************************************************

void MRH_OutputGenerator::RemoveWord(MRH_Uint32 u32_GroupID, size_t us_Word)
{
    auto Group = m_Word.find(u32_GroupID);
    
    if (Group == m_Word.end())
    {
        throw MRH_VTException("Invalid group id " + std::to_string(u32_GroupID) + " given!");
    }
    else if (Group->second.size() <= us_Word)
    {
        throw MRH_VTException("Invalid word position " + std::to_string(us_Word) + " given!");
    }
    
    Group->second.erase(Group->second.begin() + us_Word);
}

void MRH_OutputGenerator::RemovePlacement(size_t us_Placement)
{
    if (dq_Placement.size() <= us_Placement)
    {
        throw MRH_VTException("Invalid placement position " + std::to_string(us_Placement) + " given!");
    }
    
    dq_Placement.erase(dq_Placement.begin() + us_Placement);
}

void MRH_OutputGenerator::RemoveSentence(size_t us_Sentence)
{
    if (dq_Sentence.size() <= us_Sentence)
    {
        throw MRH_VTException("Invalid sentence position " + std::to_string(us_Sentence) + " given!");
    }
    
    dq_Sentence.erase(dq_Sentence.begin() + us_Sentence);
}

//*************************************************************************************
// Getters
//*************************************************************************************

size_t MRH_OutputGenerator::GetSentenceCount() const noexcept
{
    return dq_Sentence.size();
}

size_t MRH_OutputGenerator::GetPlacementCount() const noexcept
{
    return dq_Placement.size();
}

size_t MRH_OutputGenerator::GetWordCount(MRH_Uint32 u32_GroupID) const noexcept
{
    auto Group = m_Word.find(u32_GroupID);
    return Group != m_Word.end() ? Group->second.size() : 0;
}

MRH_Placement& MRH_OutputGenerator::GetPlacement(size_t us_Placement)
{
    if (dq_Placement.size() <= us_Placement)
    {
        throw MRH_VTException("Invalid placement position " + std::to_string(us_Placement) + " given!");
    }
    
    return dq_Placement[us_Placement];
}

MRH_Placement const& MRH_OutputGenerator::GetPlacement(size_t us_Placement) const
{
    if (dq_Placement.size() <= us_Placement)
    {
        throw MRH_VTException("Invalid placement position " + std::to_string(us_Placement) + " given!");
    }
    
    return dq_Placement[us_Placement];
}

MRH_Sentence& MRH_OutputGenerator::GetSentence(size_t us_Sentence)
{
    if (dq_Sentence.size() <= us_Sentence)
    {
        throw MRH_VTException("Invalid sentence position " + std::to_string(us_Sentence) + " given!");
    }
    
    return dq_Sentence[us_Sentence];
}

MRH_Sentence const& MRH_OutputGenerator::GetSentence(size_t us_Sentence) const
{
    if (dq_Sentence.size() <= us_Sentence)
    {
        throw MRH_VTException("Invalid sentence position " + std::to_string(us_Sentence) + " given!");
    }
    
    return dq_Sentence[us_Sentence];
}

MRH_Word& MRH_OutputGenerator::GetWord(MRH_Uint32 u32_GroupID, size_t us_Word)
{
    auto Group = m_Word.find(u32_GroupID);
    
    if (Group == m_Word.end())
    {
        throw MRH_VTException("Invalid group id " + std::to_string(u32_GroupID) + " given!");
    }
    else if (Group->second.size() <= us_Word)
    {
        throw MRH_VTException("Invalid word position " + std::to_string(us_Word) + " given!");
    }
    
    return Group->second[us_Word];
}

MRH_Word const& MRH_OutputGenerator::GetWord(MRH_Uint32 u32_GroupID, size_t us_Word) const
{
    auto Group = m_Word.find(u32_GroupID);
    
    if (Group == m_Word.end())
    {
        throw MRH_VTException("Invalid group id " + std::to_string(u32_GroupID) + " given!");
    }
    else if (Group->second.size() <= us_Word)
    {
        throw MRH_VTException("Invalid word position " + std::to_string(us_Word) + " given!");
    }
    
    return Group->second[us_Word];
}
