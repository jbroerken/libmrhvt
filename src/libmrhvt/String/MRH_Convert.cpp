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
#include <cwctype>
#include <locale>
#include <codecvt>
#include <algorithm>

// External

// Project
#include "../../../include/libmrhvt/libmrhvt/String/MRH_Convert.h"


//*************************************************************************************
// Convert
//*************************************************************************************

void MRH_StringConvert::ToLower(std::string& s_String) noexcept
{
    std::transform(s_String.begin(), s_String.end(), s_String.begin(), ::towlower);
}

void MRH_StringConvert::ToUpper(std::string& s_String) noexcept
{
    std::transform(s_String.begin(), s_String.end(), s_String.begin(), ::towupper);
}
