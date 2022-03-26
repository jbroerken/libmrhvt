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
     *  \param dq_Sentence The sentences for the generator. The deque is consumed.
     *  \param dq_Placement The placements for the generator. The deque is consumed.
     *  \param m_Word The words for the generator. The words are consumed.
     */
    
    MRH_OutputGenerator(std::deque<MRH_Sentence>& dq_Sentence,
                        std::deque<MRH_Placement>& dq_Placement,
                        std::unordered_map<MRH_Uint32, std::deque<MRH_Word>>& m_Word);
    
    /**
     *  File constructor.
     *
     *  \param s_FilePath The full path to the output file.
     */
    
    MRH_OutputGenerator(std::string const& s_FilePath);
    
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
    // Clear
    //*************************************************************************************
    
    /**
     *  Remove all words from the output generator.
     *  
     *  \param u32_WordGroup The word group to clear.
     */
    
    void ClearWords(MRH_Uint32 u32_WordGroup) noexcept;
    
    /**
     *  Remove all placements from the output.
     */
    
    void ClearPlacements() noexcept;
    
    /**
     *  Remove all sentences from the output.
     */
    
    void ClearSentences() noexcept;
    
    //*************************************************************************************
    // Getters
    //*************************************************************************************
    
    /**
     *  Get the generator sentences.
     *
     *  \return The generator sentences.
     */
    
    std::deque<MRH_Sentence> const& GetSentences() const noexcept;
    
    /**
     *  Get the generator placements.
     *
     *  \return The generator placements.
     */
    
    std::deque<MRH_Placement> const& GetPlacements() const noexcept;
    
    /**
     *  Get the generator words for a word group.
     *  
     *  \param u32_WordGroup The word group for the words.
     *
     *  \return The generator words for the group.
     */
    
    std::deque<MRH_Word> const& GetWords(MRH_Uint32 u32_WordGroup) const;
    
private:

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
