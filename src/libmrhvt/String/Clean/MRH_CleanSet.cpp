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

// External
#include <libmrhbf.h>

// Project
#include "../../../../include/libmrhvt/libmrhvt/String/Clean/MRH_CleanSet.h"
#include "../../../../include/libmrhvt/libmrhvt/String/MRH_LocalisedPath.h"

// Pre-defined
namespace
{
    const char* p_BlockCleanSet = "CleanSet";
}


//*************************************************************************************
// Constructor / Destructor
//*************************************************************************************

MRH_CleanSet::MRH_CleanSet(std::string const& s_FilePath)
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

MRH_CleanSet::MRH_CleanSet(std::string s_DirPath,
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

MRH_CleanSet::~MRH_CleanSet() noexcept
{}

//*************************************************************************************
// Setup
//*************************************************************************************

void MRH_CleanSet::SetupFile(std::string const& s_FilePath)
{
    try
    {
        MRH_BlockFile c_File(s_FilePath);
        
        for (auto& Block : c_File.l_Block)
        {
            if (Block.GetName().compare(p_BlockCleanSet) != 0)
            {
                continue;
            }
            
            MRH_ValueBlock::ValueList l_List(Block.GetValues());
            
            for (auto& Pair : l_List)
            {
                v_String.emplace_back(Pair.second);
            }
        }
    }
    catch (MRH_BFException& e)
    {
        throw MRH_VTException(e.what2() + " (" + e.filepath2() + ")");
    }
    catch (std::exception& e)
    {
        throw MRH_VTException(e.what());
    }
}

//*************************************************************************************
// Add
//*************************************************************************************

void MRH_CleanSet::Add(std::string const& s_String)
{
    if (s_String.length() == 0)
    {
        throw MRH_VTException("Invalid string length!");
    }
    
    v_String.push_back(s_String);
}

//*************************************************************************************
// Remove
//*************************************************************************************

void MRH_CleanSet::Remove(size_t us_String)
{
    if (v_String.size() <= us_String)
    {
        throw MRH_VTException("Invalid string position " + std::to_string(us_String) + " given!");
    }
    
    v_String.erase(v_String.begin() + us_String);
}

void MRH_CleanSet::Remove(std::string const& s_String) noexcept
{
    for (size_t i = 0; i < v_String.size();)
    {
        if (v_String[i].compare(s_String) == 0)
        {
            v_String.erase(v_String.begin() + i);
        }
        else
        {
            ++i;
        }
    }
}

//*************************************************************************************
// Getters
//*************************************************************************************

size_t MRH_CleanSet::GetStringCount() const noexcept
{
    return v_String.size();
}

std::string MRH_CleanSet::GetString(size_t us_String) const
{
    if (v_String.size() <= us_String)
    {
        throw MRH_VTException("Invalid string position " + std::to_string(us_String) + " given!");
    }
    
    return v_String[us_String];
}

bool MRH_CleanSet::GetStringExists(std::string const& s_String) const noexcept
{
    for (auto String : v_String)
    {
        if (String.compare(s_String) == 0)
        {
            return true;
        }
    }
    
    return false;
}

//*************************************************************************************
// Setters
//*************************************************************************************

void MRH_CleanSet::SetString(std::string const& s_String, size_t us_String)
{
    if (v_String.size() <= us_String)
    {
        throw MRH_VTException("Invalid string position " + std::to_string(us_String) + " given!");
    }
    else if (s_String.length() == 0)
    {
        throw MRH_VTException("Invalid string length!");
    }
    
    v_String[us_String] = s_String;
}
