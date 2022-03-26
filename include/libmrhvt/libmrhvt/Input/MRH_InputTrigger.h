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

#ifndef MRH_InputTrigger_h
#define MRH_InputTrigger_h

// C / C++
#include <deque>
#include <utility>

// External

// Project
#include "./MRH_Trigger.h"


class MRH_InputTrigger
{
public:

    //*************************************************************************************
    // Types
    //*************************************************************************************

    enum TriggerCompareMethod
    {
        DEFAULT_COMPARE = 0,
        LEVENSHTEIN = 1,
        
        TRIGGER_COMPARE_METHOD_MAX = LEVENSHTEIN,
        
        TRIGGER_COMPARE_METHOD_COUNT = TRIGGER_COMPARE_METHOD_MAX + 1
    };
    
    typedef std::pair<MRH_Sint32, MRH_Uint32> Evaluation;
    
    //*************************************************************************************
    // Constructor / Destructor
    //*************************************************************************************
    
    /**
     *  Default constructor.
     *
     *  \param e_CompareMethod The trigger compare method to use.
     *  \param f64_LSSimilarity The minimal required levenstein similarity.
     *  \param dq_Trigger The triggers to include. The deque is consumed.
     */
    
    MRH_InputTrigger(TriggerCompareMethod e_CompareMethod,
                     MRH_Sfloat64 f64_LSSimilarity,
                     std::deque<MRH_Trigger>& dq_Trigger) noexcept;
    
    /**
     *  File constructor.
     *
     *  \param s_FilePath The full path to the input trigger file.
     */
     
    MRH_InputTrigger(std::string const& s_FilePath);
     
    /**
     *  Default destructor.
     */
    
    ~MRH_InputTrigger() noexcept;
    
    //*************************************************************************************
    // Evaluate
    //*************************************************************************************
    
    /**
     *  Check a given input string for matching primary triggers.
     *
     *  \param s_String The UTF-8 input string to check.
     *  \param u32_RequiredWeight The required minimal weight for a result.
     *
     *  \return The evaluation pair containing the selected value as its first value and
     *          the weight for the value as its second value.
     */
    
    Evaluation Evaluate(std::string s_String, MRH_Uint32 u32_RequiredWeight) const noexcept;
    
    //*************************************************************************************
    // Trigger
    //*************************************************************************************
    
    /**
     *  Add a trigger.
     *
     *  \param c_Trigger The trigger to add.
     */
    
    void AddTrigger(MRH_Trigger const& c_Trigger) noexcept;
    
    /**
     *  Clear all triggers.
     */
    
    void ClearTriggers() noexcept;
    
    //*************************************************************************************
    // Getters
    //*************************************************************************************
    
    /**
     *  Get all current triggers.
     *
     *  \return All current triggers.
     */
    
    std::deque<MRH_Trigger> const& GetTriggers() const noexcept;
    
    /**
     *  Get the trigger compare method.
     *
     *  \return The trigger compare method.
     */
    
    TriggerCompareMethod GetCompareMethod() const noexcept;
    
    /**
     *  Get the required levenshtein similarity.
     *
     *  \return The required levenshtein similarity.
     */
    
    MRH_Sfloat64 GetLSSimilarity() const noexcept;
    
private:
    
    //*************************************************************************************
    // Evaluate
    //*************************************************************************************
     
    /**
     *  Search for a trigger in a given string.
     *
     *  \param s_String The UTF-8 string to search.
     *  \param s_Trigger The UTF-8 trigger to search for.
     *
     *  \return true if the trigger was found, false if not.
     */
    
    bool SearchTrigger(std::string const& s_String, std::string const& s_Trigger) const noexcept;
    
    //*************************************************************************************
    // Data
    //*************************************************************************************
    
    std::deque<MRH_Trigger> dq_Trigger;
    
    TriggerCompareMethod e_CompareMethod;
    MRH_Sfloat64 f64_LSSimilarity;
    
protected:
    
};

#endif /* MRH_InputTrigger_h */
