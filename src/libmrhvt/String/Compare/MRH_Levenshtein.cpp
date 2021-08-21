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
#include <algorithm>

// External

// Project
#include "../../../../include/libmrhvt/libmrhvt/String/Compare/MRH_Levenshtein.h"
#include "../../../../include/libmrhvt/libmrhvt/String/MRH_Convert.h"

// Pre-defined
namespace
{
    constexpr char s8_Whitespace = ' ';
}


//*************************************************************************************
// Levenshtein Distance
//*************************************************************************************

size_t MRH_StringCompareLS::Distance(std::string const& s_Compare, std::string const& s_With) noexcept
{
    // Get Length
    size_t us_SourceLength = s_Compare.length();
    size_t us_TargetLength = s_With.length();
    
    // Check if a length is 0
    if (us_SourceLength == 0)
    {
        return us_TargetLength;
    }
    else if (us_TargetLength == 0)
    {
        return us_SourceLength;
    }
    
    // Define distance info
    size_t p_Distance[us_SourceLength + 1][us_TargetLength + 1];
    
    for (size_t i = 0; i <= us_SourceLength; p_Distance[i][0] = i, ++i);
    for (size_t i = 0; i <= us_TargetLength; p_Distance[0][i] = i, ++i);
    
    // Compare
    size_t us_Cost;
    size_t us_Minimum;
    
    for (size_t i = 1; i <= us_SourceLength; i++)
    {
        for (size_t j = 1; j <= us_TargetLength; j++)
        {
            // Get cost value
            us_Cost = (s_With[j - 1] == s_Compare[i - 1]) ? 0 : 1;
            
            // Set the distance
            us_Minimum = std::min(p_Distance[i - 1][j - 1] + 1, p_Distance[i][j - 1] + 1);
            p_Distance[i][j] = std::min(us_Minimum, p_Distance[i - 1][j - 1] + us_Cost);
        }
    }
    
    // Distance result
    return p_Distance[us_SourceLength][us_TargetLength];
}
 
//*************************************************************************************
// String Similarity
//*************************************************************************************
 
MRH_Sfloat64 MRH_StringCompareLS::GetSimilarity(std::string const& s_Compare, std::string const& s_With) noexcept
{
    // Get Distance
    MRH_Sfloat64 f64_Levenshtein = static_cast<MRH_Sfloat64>(Distance(s_Compare, s_With));
    MRH_Sfloat64 f64_Max = static_cast<MRH_Sfloat64>(std::max(s_Compare.length(), s_With.length()));
    
    // Percentage
    return f64_RequiredMax - (f64_Levenshtein / f64_Max);
}
 
//*************************************************************************************
// Is Similar
//*************************************************************************************

bool MRH_StringCompareLS::IsSimilar(std::string const& s_Compare, std::string const& s_With, MRH_Sfloat64 f64_Required) noexcept
{
    return GetSimilarity(s_Compare, s_With) < f64_Required ? false : true;
}

//*************************************************************************************
// Contains
//*************************************************************************************

bool MRH_StringCompareLS::ContainedIn(std::string const& s_Contained, std::string const& s_In, MRH_Sfloat64 f64_Required) noexcept
{
    size_t us_Start = 0;
    size_t us_End;
    
    // Strings with whitespaces are checked on a word basis, allowing us to make use of special string comparison.
    // For languages without whitespaces, we try a step by step approach.
    // A searched string which is a word combination will also be checked step by step.
    if (s_Contained.find_first_of(s8_Whitespace) == std::string::npos && (us_End = s_In.find_first_of(s8_Whitespace)) != std::string::npos)
    {
        do
        {
            if ((us_End = s_In.find_first_of(s8_Whitespace, us_Start)) == std::string::npos)
            {
                us_End = s_In.length();
            }
            
            if (IsSimilar(s_Contained, s_In.substr(us_Start, us_End - us_Start), f64_Required) == true)
            {
                return true;
            }
            
            us_Start = (us_End + 1);
        }
        while (us_End < s_In.length());
    }
    else
    {
        us_End = s_Contained.length();
        
        while (us_Start + us_End <= s_In.length())
        {
            if (IsSimilar(s_Contained, s_In.substr(us_Start, us_End), f64_Required) == true)
            {
                return true;
            }
            
            ++us_Start;
        }
    }
    
    return false;
}
