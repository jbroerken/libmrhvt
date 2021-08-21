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

#ifndef MRH_CleanSet_h
#define MRH_CleanSet_h

// C / C++
#include <vector>
#include <string>

// External

// Project
#include "../../MRH_VTException.h"


class MRH_CleanSet
{
public:

    //*************************************************************************************
    // Constructor / Destructor
    //*************************************************************************************
    
    /**
     *  Default constructor.
     *
     *  \param s_FilePath The full path to the clean set file.
     */
    
    MRH_CleanSet(std::string const& s_FilePath);
    
    /**
     *  Locale based constructor.
     *
     *  \param s_DirPath The full path to the clean set directory.
     *  \param s_FileName The name of the clean set file.
     */
    
    MRH_CleanSet(std::string s_DirPath,
                 std::string const& s_FileName);
    
    /**
     *  Default destructor.
     */
    
    ~MRH_CleanSet() noexcept;
    
    //*************************************************************************************
    // Add
    //*************************************************************************************
    
    /**
     *  Add a string to the set.
     *
     *  \param s_String The UTF-8 string to add.
     */
    
    void Add(std::string const& s_String);
    
    //*************************************************************************************
    // Remove
    //*************************************************************************************
    
    /**
     *  Remove a string from the set.
     *
     *  \param us_String The string to remove.
     */
    
    void Remove(size_t us_String);
    
    /**
     *  Remove a string from the set.
     *
     *  \param s_String The UTF-8 string to remove.
     */
    
    void Remove(std::string const& s_String) noexcept;
    
    //*************************************************************************************
    // Getters
    //*************************************************************************************
    
    /**
     *  Get the string count.
     *
     *  \return The string count.
     */
    
    size_t GetStringCount() const noexcept;
    
    /**
     *  Get a string from the set.
     *
     *  \param us_String The string to get.
     *
     *  \return The requested UTF-8 string.
     */
    
    std::string GetString(size_t us_String) const;
    
    /**
     *  Check if a string is contained in the set.
     *
     *  \param s_String The UTF-8 string to search for.
     *
     *  \return true if the string exists, false if not.
     */
    
    bool GetStringExists(std::string const& s_String) const noexcept;
    
    //*************************************************************************************
    // Setters
    //*************************************************************************************
    
    /**
     *  Update a string in the set.
     *
     *  \param s_String The new UTF-8 string.
     *  \param us_String The string to update.
     */
    
    void SetString(std::string const& s_String, size_t us_String);
    
private:

    //*************************************************************************************
    // Setup
    //*************************************************************************************

    /**
     *  Setup clean set with file data.
     *
     *  \param s_FilePath The full path to the input trigger file.
     */

    void SetupFile(std::string const& s_FilePath);
    
    //*************************************************************************************
    // Data
    //*************************************************************************************
    
    std::vector<std::string> v_String;
    
protected:
    
};

#endif /* MRH_CleanSet_h */
