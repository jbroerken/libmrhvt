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

#ifndef MRH_Sentence_h
#define MRH_Sentence_h

// C / C++
#include <string>

// External
#include <MRH_Typedefs.h>

// Project
#include "../MRH_VTException.h"


class MRH_Sentence
{
public:
    
    //*************************************************************************************
    // Constructor / Destructor
    //*************************************************************************************
    
    /**
     *  Default constructor.
     *
     *  \param s_String The UTF-8 sentence string.
     *  \param f64_UseChance The word use chance.
     */
    
    MRH_Sentence(std::string const& s_String,
                 MRH_Sfloat64 f64_UseChance);
    
    /**
     *  Default destructor.
     */
    
    ~MRH_Sentence() noexcept;
    
    //*************************************************************************************
    // Getters
    //*************************************************************************************
    
    /**
     *  Get the sentence string.
     *
     *  \return The UTF-8 sentence string.
     */
    
    std::string GetString() const noexcept;
    
    /**
     *  Get the sentence use chance.
     *
     *  \return The sentence use chance.
     */
    
    MRH_Sfloat64 GetUseChance() const noexcept;
    
    //*************************************************************************************
    // Setters
    //*************************************************************************************
    
    /**
     *  Set the sentence string.
     *
     *  \param s_String The new UTF-8 string.
     */
    
    void SetString(std::string const& s_String);
    
    /**
     *  Set the sentence use chance.
     *
     *  \param f64_UseChance The sentence use chance.
     */
    
    void SetUseChance(MRH_Sfloat64 f64_UseChance) noexcept;
    
    //*************************************************************************************
    // Data
    //*************************************************************************************
    
    static const MRH_Sfloat64 f64_UseChanceMax;
    static const MRH_Sfloat64 f64_UseChanceMin;
    
private:
    
    //*************************************************************************************
    // Data
    //*************************************************************************************
    
    std::string s_String;
    MRH_Sfloat64 f64_UseChance;
    
protected:
    
};

#endif /* MRH_Sentence_h */
