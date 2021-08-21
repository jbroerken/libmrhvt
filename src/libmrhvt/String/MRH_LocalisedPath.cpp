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
#include <cstring>

// External

// Project
#include "../../../include/libmrhvt/libmrhvt/String/MRH_LocalisedPath.h"

// Pre-defined
#ifndef MRH_LOCALE_DIRECTORY_DEFAULT
    #define MRH_LOCALE_DIRECTORY_DEFAULT "Default"
#endif


//*************************************************************************************
// Getters
//*************************************************************************************

std::string MRH_LocalisedPath::GetPath(std::string s_DirPath, std::string const& s_FileName) noexcept
{
    std::string s_Locale = "Default";
    char* p_Locale;
    if ((p_Locale = std::setlocale(LC_CTYPE, NULL)) != NULL && std::strlen(p_Locale) > 5)
    {
        s_Locale = std::string(std::setlocale(LC_CTYPE, NULL), 5);
    }
    
    if (s_DirPath.length() > 0 && *(s_DirPath.end() - 1) != '/')
    {
        s_DirPath += "/";
    }
    
    return s_DirPath + s_Locale + "/" + s_FileName;
}

std::string MRH_LocalisedPath::GetPathDefault(std::string s_DirPath, std::string const& s_FileName) noexcept
{
    if (s_DirPath.length() > 0 && *(s_DirPath.end() - 1) != '/')
    {
        s_DirPath += "/";
    }
    
    return s_DirPath + MRH_LOCALE_DIRECTORY_DEFAULT + "/" + s_FileName;
}
