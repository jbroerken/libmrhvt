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

#ifndef MRH_Trigger_h
#define MRH_Trigger_h

// C / C++
#include <string>

// External
#include <MRH_Typedefs.h>

// Project
#include "../MRH_VTException.h"


class MRH_Trigger
{
public:

    //*************************************************************************************
    // Constructor / Destructor
    //*************************************************************************************
    
    /**
     *  Default constructor.
     *
     *  \param s_String The UTF-8 trigger string.
     *  \param u32_Weight The trigger weight.
     *  \param s32_Value The trigger value.
     */
   
    MRH_Trigger(std::string const& s_String,
                MRH_Uint32 u32_Weight,
                MRH_Sint32 s32_Value);
    
    /**
     *  Copy constructor.
     *
     *  \param c_Trigger MRH_Trigger class source.
     */
    
    MRH_Trigger(MRH_Trigger const& c_Trigger) noexcept;
    
    /**
     *  Default destructor.
     */
    
    ~MRH_Trigger() noexcept;
    
    //*************************************************************************************
    // Getters
    //*************************************************************************************
    
    /**
     *  Get the trigger string.
     *
     *  \return The UTF-8 trigger string.
     */
    
    std::string GetString() const noexcept;
    
    /**
     *  Get the trigger weight.
     *
     *  \return The trigger weight.
     */
    
    MRH_Uint32 GetWeight() const noexcept;
    
    /**
     *  Get the trigger value.
     *
     *  \return The trigger value.
     */
    
    MRH_Sint32 GetValue() const noexcept;
    
    //*************************************************************************************
    // Data
    //*************************************************************************************
    
    static const MRH_Uint32 u32_WeightMin;
    static const MRH_Uint32 u32_WeightMax;
    static const MRH_Sint32 s32_ValueInvalid;
    
private:
    
    //*************************************************************************************
    // Data
    //*************************************************************************************
    
    std::string s_String;
    MRH_Uint32 u32_Weight;
    MRH_Sint32 s32_Value;
    
protected:
    
};

#endif /* MRH_Trigger_h */
