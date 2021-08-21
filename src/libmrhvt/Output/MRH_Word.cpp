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

// External

// Project
#include "../../../include/libmrhvt/libmrhvt/Output/MRH_Word.h"


//*************************************************************************************
// Constructor / Destructor
//*************************************************************************************

const MRH_Sfloat64 MRH_Word::f64_UseChanceMax = 1.f;
const MRH_Sfloat64 MRH_Word::f64_UseChanceMin = 0.f;

MRH_Word::MRH_Word(std::string const& s_String,
                   MRH_Uint32 u32_GroupID,
                   MRH_Sfloat64 f64_UseChance) : s_String(s_String),
                                                 u32_GroupID(u32_GroupID)
{
    if (s_String.length() == 0)
    {
        throw MRH_VTException("Invalid string given!");
    }
    
    SetUseChance(f64_UseChance);
}

MRH_Word::~MRH_Word() noexcept
{}

//*************************************************************************************
// Getters
//*************************************************************************************
 
std::string MRH_Word::GetString() const noexcept
{
    return s_String;
}
 
MRH_Uint32 MRH_Word::GetGroupID() const noexcept
{
    return u32_GroupID;
}
 
MRH_Sfloat64 MRH_Word::GetUseChance() const noexcept
{
    return f64_UseChance;
}
 
//*************************************************************************************
// Setters
//*************************************************************************************
 
void MRH_Word::SetString(std::string const& s_String)
{
    if (s_String.length() == 0)
    {
        throw MRH_VTException("Invalid string given!");
    }
    
    this->s_String = s_String;
}
 
void MRH_Word::SetUseChance(MRH_Sfloat64 f64_UseChance) noexcept
{
    if (f64_UseChance < f64_UseChanceMin)
    {
        this->f64_UseChance = f64_UseChanceMin;
    }
    else if (f64_UseChance > f64_UseChanceMax)
    {
        this->f64_UseChance = f64_UseChanceMax;
    }
    else
    {
        this->f64_UseChance = f64_UseChance;
    }
}
