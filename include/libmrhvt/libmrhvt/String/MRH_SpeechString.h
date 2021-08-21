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

#ifndef MRH_SpeechString_h
#define MRH_SpeechString_h

// C / C++
#include <map>
#include <utility>

// External
#include <MRH_Typedefs.h>

// Project
#include "../MRH_VTException.h"


class MRH_SpeechString
{
public:
    
    //*************************************************************************************
    // Types
    //*************************************************************************************
    
    enum State
    {
        UNFINISHED = 0, // No end
        END_KNOWN = 1, // End known but gaps
        COMPLETE = 2, // Fully assembled
        
        STATE_MAX = COMPLETE,
        
        STATE_COUNT = STATE_MAX + 1
    };
    
    //*************************************************************************************
    // Constructor / Destructor
    //*************************************************************************************
    
    /**
     *  Default constructor.
     *
     *  \param u32_ID The id of this string.
     */
    
    MRH_SpeechString(MRH_Uint32 u32_ID) noexcept;
    
    /**
     *  First part constructor.
     *
     *  \param s_String The initial string.
     *  \param u32_Part The initial string part.
     *  \param u32_ID The id of this string.
     *  \param b_End Wether this is the last part or not.
     */
    
    MRH_SpeechString(std::string const& s_String,
                     MRH_Uint32 u32_Part,
                     MRH_Uint32 u32_ID,
                     bool b_End = false);
    
    /**
     *  Default destructor.
     */
    
    ~MRH_SpeechString() noexcept;
    
    //*************************************************************************************
    // Split
    //*************************************************************************************
    
    /**
     *  Split a string into parts. The parts will be split for the MRH_EVENT_SAY_STRING_U
     *  event buffer. The part ids are ordered 0 (Start) to X (End Part) without gaps.
     *
     *  \param s_String The string to split.
     *
     *  \return A ordered map of all string parts.
     */
    
    static std::map<MRH_Uint32, std::string> SplitString(std::string s_String);
    
    //*************************************************************************************
    // Reset
    //*************************************************************************************
    
    /**
     *  Reset the string.
     *
     *  \param u32_ID The new id of this string.
     */
    
    void Reset(MRH_Uint32 u32_ID) noexcept;
    
    /**
     *  Reset the string.
     *
     *  \param s_String The initial string.
     *  \param u32_Part The initial string part.
     *  \param u32_ID The id of this string.
     *  \param b_End Wether this is the last part or not.
     */
    
    void Reset(std::string const& s_String, MRH_Uint32 u32_ID, MRH_Uint32 u32_Part, bool b_End = false);
    
    //*************************************************************************************
    // Add
    //*************************************************************************************
    
    /**
     *  Add a string part.
     *
     *  \param s_String The string to add.
     *  \param u32_Part The string part.
     *  \param b_End Wether this is the last part or not.
     *
     *  \return The current string state after adding the part.
     */
    
    State Add(std::string const& s_String, MRH_Uint32 u32_Part, bool b_End = false);
    
    //*************************************************************************************
    // Getters
    //*************************************************************************************
    
    /**
     *  Check the current string state.
     *
     *  \return The current string state.
     */
    
    State GetState() const noexcept;
    
    /**
     *  Get the currently assembleable string.
     *
     *  \return The current assembleable string.
     */
    
    std::string GetString() const noexcept;
    
    /**
     *  Get the string id.
     *
     *  \return The string id.
     */
    
    MRH_Uint32 GetID() const noexcept;
    
private:
    
    //*************************************************************************************
    // Data
    //*************************************************************************************
    
    std::map<MRH_Uint32, std::string> m_Part;
    std::pair<bool, MRH_Uint32> c_End;
    MRH_Uint32 u32_ID;
    
protected:

};

#endif /* MRH_SpeechString_h */
