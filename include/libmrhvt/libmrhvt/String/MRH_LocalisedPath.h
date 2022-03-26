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
     *  The path will include the "Default" directory in the path if the directory for
     *  the locale does not exist.
     *
     *  \param s_ToPath The path to the directory containing localised directories.
     *  \param s_FromPath The path inside the locale directory to append.
     */
    
    std::string GetPath(std::string s_ToPath, std::string const& s_FromPath) noexcept;
    
    /**
     *  Get a localised file. The locale file name is chosen with the system locale.
     *  The file will use the "Default" file name if the file for the locale does not 
     *  exist.
     *
     *  \param s_DirPath The path to the directory containing localised file.
     *  \param s_FileExtension The file extension to append
     */
    
    std::string GetFile(std::string s_DirPath, std::string const& s_FileExtension) noexcept;
}

#endif /* MRH_LocalisedPath_h */
