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
#include "../../../include/libmrhvt/libmrhvt/String/MRH_Clean.h"


//*************************************************************************************
// Clean
//*************************************************************************************

void MRH_StringClean::Clean(std::string& s_String, MRH_CleanSet const& c_Set) noexcept
{
    if (s_String.length() == 0 || c_Set.GetStringCount() == 0)
    {
        return;
    }
    
    size_t us_Pos;
    
    for (size_t i = 0; i < c_Set.GetStringCount(); ++i)
    {
        while ((us_Pos = s_String.find(c_Set.GetString(i))) != std::string::npos)
        {
            // Remove
            s_String.erase(s_String.begin() + us_Pos, s_String.begin() + (us_Pos + c_Set.GetString(i).length()));
            
            // Clear whitespace
            if (s_String.length() > 0)
            {
                if (us_Pos == 0)
                {
                    if (s_String[0] == ' ')
                    {
                        s_String.erase(s_String.begin());
                    }
                }
                else if (us_Pos == s_String.length())
                {
                    if (s_String[us_Pos - 1] == ' ')
                    {
                        s_String.erase(s_String.begin() + us_Pos);
                    }
                }
                else if (us_Pos == s_String.length() - 1)
                {
                    if (s_String[us_Pos] == ' ')
                    {
                        s_String.erase(s_String.begin() + us_Pos);
                    }
                }
                else if (s_String[us_Pos] == ' ' && s_String[us_Pos + 1] == ' ')
                {
                    s_String.erase(s_String.begin() + us_Pos);
                }
            }
        }
    }
}
