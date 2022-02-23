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

#ifndef MRH_Levenshtein_h
#define MRH_Levenshtein_h

// C / C++
#include <string>

// External
#include <MRH_Typedefs.h>

// Project


namespace MRH_StringCompareLS
{
    //*************************************************************************************
    // Levenshtein Distance
    //*************************************************************************************
    
    /**
     *  Get the levenshtein distance for two strings.
     *
     *  \param s_Compare The UTF-8 string to check.
     *  \param s_With The UTF-8 string to compare with.
     *
     *  \return The levenshtein distance.
     */
    
    size_t Distance(std::string const& s_Compare, std::string const& s_With) noexcept;
 
    //*************************************************************************************
    // String Similarity
    //*************************************************************************************
     
    /**
     *  Get the similarity in percent for two strings.
     *
     *  \param s_Compare The UTF-8 string to check.
     *  \param s_With The UTF-8 string to compare with.
     *
     *  \return The string similarity in percent.
     */
    
    MRH_Sfloat64 GetSimilarity(std::string const& s_Compare, std::string const& s_With) noexcept;

    //*************************************************************************************
    // Is Similar
    //*************************************************************************************
     
    /**
     *  Check if two supplied strings are similar enough.
     *
     *  \param s_Compare The UTF-8 string to check.
     *  \param s_With The UTF-8 string to compare with.
     *  \param f64_Required The required similarity in percent.
     *
     *  \return true if similar enough, false if not.
     */
    
    bool IsSimilar(std::string const& s_Compare, std::string const& s_With, MRH_Sfloat64 f64_Required) noexcept;

    //*************************************************************************************
    // Contains
    //*************************************************************************************

    /**
     *  Check if a string is contained in another string.
     *
     *  \param s_Contained The UTF-8 string to check for.
     *  \param s_In The UTF-8 string to search.
     *  \param f64_Required The required similarity in percent.  
     */

    bool ContainedIn(std::string const& s_Contained, std::string const& s_In, MRH_Sfloat64 f64_Required) noexcept;
    
    //*************************************************************************************
    // Data
    //*************************************************************************************
    
    static const MRH_Sfloat64 f64_RequiredMin = 0.f;
    static const MRH_Sfloat64 f64_RequiredMax = 1.f;
};

#endif /* MRH_Levenshtein_h */
