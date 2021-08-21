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
#include "../../../include/libmrhvt/libmrhvt/Output/MRH_Placement.h"


//*************************************************************************************
// Constructor / Destructor
//*************************************************************************************

MRH_Placement::MRH_Placement(std::string const& s_String,
                             MRH_Uint32 u32_GroupID) : s_String(s_String),
                                                       u32_GroupID(u32_GroupID)
{
    if (s_String.length() == 0)
    {
        throw MRH_VTException("Invalid string given!");
    }
}

MRH_Placement::~MRH_Placement() noexcept
{}

//*************************************************************************************
// Getters
//*************************************************************************************
 
std::string MRH_Placement::GetString() const noexcept
{
    return s_String;
}
 
MRH_Uint32 MRH_Placement::GetGroupID() const noexcept
{
    return u32_GroupID;
}
 
//*************************************************************************************
// Setters
//*************************************************************************************
 
void MRH_Placement::SetString(std::string const& s_String)
{
    if (s_String.length() == 0)
    {
        throw MRH_VTException("Invalid string given!");
    }
    
    this->s_String = s_String;
}
 
void MRH_Placement::SetGroupID(MRH_Uint32 u32_GroupID) noexcept
{
    this->u32_GroupID = u32_GroupID;
}
