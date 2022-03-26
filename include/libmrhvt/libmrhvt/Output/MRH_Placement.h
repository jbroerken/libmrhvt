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

#ifndef MRH_Placement_h
#define MRH_Placement_h

// C / C++
#include <string>

// External
#include <MRH_Typedefs.h>

// Project
#include "../MRH_VTException.h"


class MRH_Placement
{
public:

    //*************************************************************************************
    // Constructor / Destructor
    //*************************************************************************************
    
    /**
     *  Default constructor.
     *
     *  \param s_String The UTF-8 placement string.
     *  \param u32_GroupID The placement word group id.
     */
    
    MRH_Placement(std::string const& s_String,
                  MRH_Uint32 u32_GroupID);
    
    /**
     *  Default destructor.
     */
    
    ~MRH_Placement() noexcept;
    
    //*************************************************************************************
    // Getters
    //*************************************************************************************
    
    /**
     *  Get the word string.
     *
     *  \return The UTF-8 word string.
     */
    
    std::string GetString() const noexcept;
    
    /**
     *  Get the word group id.
     *
     *  \return The word group id.
     */
    
    MRH_Uint32 GetGroupID() const noexcept;
    
private:
    
    //*************************************************************************************
    // Data
    //*************************************************************************************
    
    std::string s_String;
    MRH_Uint32 u32_GroupID;
    
protected:
    
};

#endif /* MRH_Placement_h */
