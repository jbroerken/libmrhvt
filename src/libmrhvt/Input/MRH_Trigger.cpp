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
#include "../../../include/libmrhvt/libmrhvt/Input/MRH_Trigger.h"
#include "../../../include/libmrhvt/libmrhvt/String/MRH_Convert.h"


//*************************************************************************************
// Constructor / Destructor
//*************************************************************************************

const MRH_Uint32 MRH_Trigger::u32_WeightMin = 0;
const MRH_Uint32 MRH_Trigger::u32_WeightMax = 10000;
const MRH_Sint32 MRH_Trigger::s32_ValueInvalid = -1;

MRH_Trigger::MRH_Trigger(std::string const& s_String,
                         MRH_Uint32 u32_Weight,
                         MRH_Sint32 s32_Value) : s_String(s_String)
{
    if (s_String.length() == 0)
    {
        throw MRH_VTException("Invalid string given!");
    }
    
    MRH_StringConvert::ToLower(this->s_String);
    
    if ((this->u32_Weight = u32_Weight) > u32_WeightMax)
    {
        this->u32_Weight = u32_WeightMax;
    }
    
    if ((this->s32_Value = s32_Value) <= s32_ValueInvalid)
    {
        this->s32_Value = 0;
    }
}

MRH_Trigger::MRH_Trigger(MRH_Trigger const& c_Trigger) noexcept : s_String(c_Trigger.s_String),
                                                                  u32_Weight(c_Trigger.u32_Weight),
                                                                  s32_Value(c_Trigger.s32_Value)
{}

MRH_Trigger::~MRH_Trigger() noexcept
{}

//*************************************************************************************
// Getters
//*************************************************************************************

std::string MRH_Trigger::GetString() const noexcept
{
    return s_String;
}

MRH_Uint32 MRH_Trigger::GetWeight() const noexcept
{
    return u32_Weight;
}

MRH_Sint32 MRH_Trigger::GetValue() const noexcept
{
    return s32_Value;
}
