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
#include <sys/stat.h>
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

std::string MRH_LocalisedPath::GetPath(std::string s_ToPath, std::string const& s_FromPath) noexcept
{
    // Check dir for end
    if (s_ToPath.length() > 0 && *(s_ToPath.end() - 1) != '/')
    {
        s_ToPath += "/";
    }
    
    // Grab the locale
    char* p_Locale;
    
    if ((p_Locale = std::setlocale(LC_ALL, NULL)) == NULL)
    {
        // Not set, return default
        return s_ToPath + MRH_LOCALE_DIRECTORY_DEFAULT + "/" + s_FromPath;
    }
    
    std::string s_Locale(p_Locale);
    
    // Does the locale have something like .UTF-8 attached?
    size_t us_AddPos;
    
    if ((us_AddPos = s_Locale.find('.')) != std::string::npos)
    {
        s_Locale = s_Locale.substr(0, us_AddPos);
    }
    
    // Check for directory existence
    std::string s_LocaleDir = s_ToPath + s_Locale;
    struct stat c_Stat;
    
    if (stat(s_LocaleDir.c_str(), &c_Stat) == 0 && S_ISDIR(c_Stat.st_mode))
    {
        // Exists, return locale path
        return s_LocaleDir + "/" + s_FromPath;
    }
    
    // Doesn't exist, return default
    return s_ToPath + MRH_LOCALE_DIRECTORY_DEFAULT + "/" + s_FromPath;
}
