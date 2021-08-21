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

#ifndef MRH_StringClean_h
#define MRH_StringClean_h

// C / C++

// External

// Project
#include "./Clean/MRH_CleanSet.h"


namespace MRH_StringClean
{
    //*************************************************************************************
    // Clean
    //*************************************************************************************
    
    /**
     *  Clean all supplied strings from a string. This function is thread safe.
     *
     *  \param s_String The UTF-8 string to clean.
     *  \param c_Set The cleaning set to use.
     */
    
    void Clean(std::string& s_String, MRH_CleanSet const& c_Set) noexcept;
}

#endif /* MRH_StringClean_h */
