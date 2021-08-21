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
#include "../../../../include/libmrhvt/libmrhvt/String/Compare/MRH_DefaultCompare.h"


//*************************************************************************************
// Is Similar
//*************************************************************************************

bool MRH_StringCompareDC::IsSimilar(std::string const& s_Compare, std::string const& s_With) noexcept
{
    if (s_Compare.compare(s_With) == 0)
    {
        return true;
    }
    
    return false;
}

//*************************************************************************************
// Contains
//*************************************************************************************

bool MRH_StringCompareDC::ContainedIn(std::string const& s_Contained, std::string const& s_In) noexcept
{
    if (s_In.size() == 0 || s_In.size() > s_Contained.size())
    {
        return false;
    }
    
    return s_In.find(s_Contained) != std::string::npos ? true : false;
}
