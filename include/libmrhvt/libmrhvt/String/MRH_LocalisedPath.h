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

#ifndef MRH_LocalisedPath_h
#define MRH_LocalisedPath_h

// C / C++
#include <string>

// External

// Project


namespace MRH_LocalisedPath
{
    //*************************************************************************************
    // Getters
    //*************************************************************************************
    
    /**
     *  Get a localised path. The locale directory name is chosen with the system locale.
     *
     *  \param s_DirPath The path to the directory containing localised directories.
     *  \param s_FileName The file to point to.
     */
    
    std::string GetPath(std::string s_DirPath, std::string const& s_FileName) noexcept;

    /**
     *  Get a localised path for the default locale directory.
     *
     *  \param s_DirPath The path to the directory containing localised directories.
     *  \param s_FileName The file to point to.
     */

    std::string GetPathDefault(std::string s_DirPath, std::string const& s_FileName) noexcept;
}

#endif /* MRH_LocalisedPath_h */
