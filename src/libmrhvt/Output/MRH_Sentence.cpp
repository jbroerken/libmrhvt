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

// Project
#include "../../../include/libmrhvt/libmrhvt/Output/MRH_Sentence.h"


//*************************************************************************************
// Constructor / Destructor
//*************************************************************************************

const MRH_Sfloat64 MRH_Sentence::f64_UseChanceMax = 1.f;
const MRH_Sfloat64 MRH_Sentence::f64_UseChanceMin = 0.f;

MRH_Sentence::MRH_Sentence(std::string const& s_String,
                           MRH_Sfloat64 f64_UseChance) : s_String(s_String)
{
    if (s_String.length() == 0)
    {
        throw MRH_VTException("Invalid string given!");
    }
    
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

MRH_Sentence::~MRH_Sentence() noexcept
{}

//*************************************************************************************
// Getters
//*************************************************************************************
 
std::string MRH_Sentence::GetString() const noexcept
{
    return s_String;
}
 
MRH_Sfloat64 MRH_Sentence::GetUseChance() const noexcept
{
    return f64_UseChance;
}
