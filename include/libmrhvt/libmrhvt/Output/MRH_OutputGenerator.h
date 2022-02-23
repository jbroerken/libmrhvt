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

#ifndef MRH_OutputGenerator_h
#define MRH_OutputGenerator_h

// C / C++
#include <unordered_map>
#include <deque>
#include <vector>

// External

// Project
#include "./MRH_Sentence.h"
#include "./MRH_Placement.h"
#include "./MRH_Word.h"


class MRH_OutputGenerator
{
public:

    //*************************************************************************************
    // Constructor / Destructor
    //*************************************************************************************
    
    /**
     *  Default constructor.
     *
     *  \param s_FilePath The full path to the output file.
     */
    
    MRH_OutputGenerator(std::string const& s_FilePath);
    
    /**
     *  Locale based constructor.
     *
     *  \param s_DirPath The full path to the output directory.
     *  \param s_FileName The name of the output file.
     */
    
    MRH_OutputGenerator(std::string s_DirPath,
                        std::string const& s_FileName);
    
    /**
     *  Default destructor.
     */
    
    ~MRH_OutputGenerator() noexcept;
    
    //*************************************************************************************
    // Generate
    //*************************************************************************************
    
    /**
     *  Generate a random output sentence.
     *
     *  \return The generated UTF-8 output sentence.
     */
    
    std::string Generate() const;
    
    //*************************************************************************************
    // Add
    //*************************************************************************************
    
    /**
     *  Add a word to the output generator.
     *
     *  \param c_Word The word to add.
     */
    
    void AddWord(MRH_Word const& c_Word) noexcept;
    
    /**
     *  Add a placement to the output generator.
     *
     *  \param c_Placement The placement to add.
     */
    
    void AddPlacement(MRH_Placement const& c_Placement) noexcept;
    
    /**
     *  Add a sentence to the output generator.
     *
     *  \param c_Sentence The sentence to add.
     */
    
    void AddSentence(MRH_Sentence const& c_Sentence) noexcept;
    
    //*************************************************************************************
    // Remove
    //*************************************************************************************
    
    /**
     *  Remove a word from the output generator.
     *
     *  \param u32_GroupID The group id of the word to remove.
     *  \param us_Word The index of the word word in the group to remove.
     */
    
    void RemoveWord(MRH_Uint32 u32_GroupID, size_t us_Word);
    
    /**
     *  Remove a placement from the output.
     *
     *  \param us_Placement The index of the sentence to remove.
     */
    
    void RemovePlacement(size_t us_Placement);
    
    /**
     *  Remove a sentence from the output.
     *
     *  \param us_Sentence The index of the sentence to remove.
     */
    
    void RemoveSentence(size_t us_Sentence);
    
    //*************************************************************************************
    // Getters
    //*************************************************************************************
    
    /**
     *  Get the sentence count.
     *
     *  \return The sentence count.
     */
    
    size_t GetSentenceCount() const noexcept;
    
    /**
     *  Get the placement count.
     *
     *  \return The placement count.
     */
    
    size_t GetPlacementCount() const noexcept;
    
    /**
     *  Get the word count.
     *
     *  \param u32_GroupID The word group id.
     *  
     *  \return The word count.
     */
    
    size_t GetWordCount(MRH_Uint32 u32_GroupID) const noexcept;
    
    /**
     *  Get a sentence.
     *
     *  \param us_Sentence The index of the sentence to get.
     *
     *  \return The requested sentence.
     */
    
    MRH_Sentence& GetSentence(size_t us_Sentence);
    
    /**
     *  Get a sentence.
     *
     *  \param us_Sentence The index of the sentence to get.
     *
     *  \return The requested sentence.
     */
    
    MRH_Sentence const& GetSentence(size_t us_Sentence) const;
    
    /**
     *  Get a placement.
     *
     *  \param us_Placement The index of the placement to get.
     *
     *  \return The requested placement.
     */
    
    MRH_Placement& GetPlacement(size_t us_Placement);
    
    /**
     *  Get a placement.
     *
     *  \param us_Placement The index of the placement to get.
     *
     *  \return The requested placement.
     */
    
    MRH_Placement const& GetPlacement(size_t us_Placement) const;
    
    /**
     *  Get a word.
     *
     *  \param u32_GroupID The word group id of the word.
     *  \param us_Word The index of the word in the group to get.
     *
     *  \return The requested word.
     */
    
    MRH_Word& GetWord(MRH_Uint32 u32_GroupID, size_t us_Word);
    
    /**
     *  Get a word.
     *
     *  \param u32_GroupID The word group id of the word.
     *  \param us_Word The index of the word in the group to get.
     *
     *  \return The requested word.
     */
    
    MRH_Word const& GetWord(MRH_Uint32 u32_GroupID, size_t us_Word) const;
    
private:

    //*************************************************************************************
    // Setup
    //*************************************************************************************

    /**
     *  Setup output with file data.
     *
     *  \param s_FilePath The full path to the output file.
     */

    void SetupFile(std::string const& s_FilePath);
    
    //*************************************************************************************
    // Generate
    //*************************************************************************************
    
    /**
     *  Select an element from given chances.
     *
     *  \param v_Chance The output element chances.
     *
     *  \return The chosen element.
     */
    
    size_t SelectElement(std::vector<std::pair<size_t, MRH_Sfloat64>>& v_Chance) const noexcept;
    
    /**
     *  Recieve a random sentence.
     *
     *  \return The sentence chosen.
     */
    
    const MRH_Sentence& RandomSentence() const;
    
    /**
     *  Recieve a random word from a group.
     *
     *  \param u32_GroupID The word group id.
     *
     *  \return The word chosen.
     */
    
    const MRH_Word& RandomWord(MRH_Uint32 u32_GroupID) const;
    
    //*************************************************************************************
    // Data
    //*************************************************************************************
    
    std::deque<MRH_Sentence> dq_Sentence;
    std::deque<MRH_Placement> dq_Placement;
    std::unordered_map<MRH_Uint32, std::deque<MRH_Word>> m_Word;
    
protected:
    
};

#endif /* MRH_OutputGenerator_h */
