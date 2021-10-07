*********
Functions
*********
The list of functions shown here includes information about their use case as 
well as the required parameters and return values. Code examples are given if 
deemed neccessary.

Internal functions are used by the library itself. These functions are not 
meant to be used directly for application development.

Library Functions
-----------------
.. toctree::
  :maxdepth: 1

  libmrhvt_Directory/Input/MRH_Trigger/MRH_Trigger_0
  libmrhvt_Directory/Input/MRH_Trigger/MRH_Trigger_1
  libmrhvt_Directory/Input/MRH_Trigger/~MRH_Trigger
  libmrhvt_Directory/Input/MRH_Trigger/GetString
  libmrhvt_Directory/Input/MRH_Trigger/GetWeight
  libmrhvt_Directory/Input/MRH_Trigger/GetValue
  libmrhvt_Directory/Input/MRH_Trigger/SetString
  libmrhvt_Directory/Input/MRH_Trigger/SetWeight
  libmrhvt_Directory/Input/MRH_Trigger/SetValue
  libmrhvt_Directory/Input/MRH_InputTrigger/MRH_InputTrigger_0
  libmrhvt_Directory/Input/MRH_InputTrigger/MRH_InputTrigger_1
  libmrhvt_Directory/Input/MRH_InputTrigger/~MRH_InputTrigger
  libmrhvt_Directory/Input/MRH_InputTrigger/Evaluate
  libmrhvt_Directory/Input/MRH_InputTrigger/AddTrigger
  libmrhvt_Directory/Input/MRH_InputTrigger/RemoveTrigger
  libmrhvt_Directory/Input/MRH_InputTrigger/GetTriggerCount
  libmrhvt_Directory/Input/MRH_InputTrigger/GetTrigger_0
  libmrhvt_Directory/Input/MRH_InputTrigger/GetTrigger_1
  libmrhvt_Directory/Input/MRH_InputTrigger/GetCompareMethod
  libmrhvt_Directory/Input/MRH_InputTrigger/GetLSSimilarity
  libmrhvt_Directory/Input/MRH_InputTrigger/SetCompareMethod
  libmrhvt_Directory/Input/MRH_InputTrigger/SetLSSimilarity
  libmrhvt_Directory/Output/MRH_Word/MRH_Word_0
  libmrhvt_Directory/Output/MRH_Word/~MRH_Word
  libmrhvt_Directory/Output/MRH_Word/GetString
  libmrhvt_Directory/Output/MRH_Word/GetGroupID
  libmrhvt_Directory/Output/MRH_Word/GetUseChance
  libmrhvt_Directory/Output/MRH_Word/SetString
  libmrhvt_Directory/Output/MRH_Word/SetUseChance
  libmrhvt_Directory/Output/MRH_Sentence/MRH_Sentence_0
  libmrhvt_Directory/Output/MRH_Sentence/~MRH_Sentence
  libmrhvt_Directory/Output/MRH_Sentence/GetString
  libmrhvt_Directory/Output/MRH_Sentence/GetUseChance
  libmrhvt_Directory/Output/MRH_Sentence/SetString
  libmrhvt_Directory/Output/MRH_Sentence/SetUseChance
  libmrhvt_Directory/Output/MRH_Placement/MRH_Placement_0
  libmrhvt_Directory/Output/MRH_Placement/~MRH_Placement
  libmrhvt_Directory/Output/MRH_Placement/GetString
  libmrhvt_Directory/Output/MRH_Placement/GetGroupID
  libmrhvt_Directory/Output/MRH_Placement/SetString
  libmrhvt_Directory/Output/MRH_Placement/SetGroupID
  libmrhvt_Directory/Output/MRH_OutputGenerator/MRH_OutputGenerator_0
  libmrhvt_Directory/Output/MRH_OutputGenerator/MRH_OutputGenerator_1
  libmrhvt_Directory/Output/MRH_OutputGenerator/~MRH_OutputGenerator
  libmrhvt_Directory/Output/MRH_OutputGenerator/Generate
  libmrhvt_Directory/Output/MRH_OutputGenerator/AddWord
  libmrhvt_Directory/Output/MRH_OutputGenerator/AddPlacement
  libmrhvt_Directory/Output/MRH_OutputGenerator/AddSentence
  libmrhvt_Directory/Output/MRH_OutputGenerator/RemoveWord
  libmrhvt_Directory/Output/MRH_OutputGenerator/RemovePlacement
  libmrhvt_Directory/Output/MRH_OutputGenerator/RemoveSentence
  libmrhvt_Directory/Output/MRH_OutputGenerator/GetSentenceCount
  libmrhvt_Directory/Output/MRH_OutputGenerator/GetPlacementCount
  libmrhvt_Directory/Output/MRH_OutputGenerator/GetWordCount
  libmrhvt_Directory/Output/MRH_OutputGenerator/GetSentence_0
  libmrhvt_Directory/Output/MRH_OutputGenerator/GetSentence_1
  libmrhvt_Directory/Output/MRH_OutputGenerator/GetPlacement_0
  libmrhvt_Directory/Output/MRH_OutputGenerator/GetPlacement_1
  libmrhvt_Directory/Output/MRH_OutputGenerator/GetWord_0
  libmrhvt_Directory/Output/MRH_OutputGenerator/GetWord_1
  libmrhvt_Directory/String/Compare/MRH_DefaultCompare/MRH_StringCompareDC/IsSimilar
  libmrhvt_Directory/String/Compare/MRH_DefaultCompare/MRH_StringCompareDC/ContainedIn
  libmrhvt_Directory/String/Compare/MRH_Levenshtein/MRH_StringCompareLS/Distance
  libmrhvt_Directory/String/Compare/MRH_Levenshtein/MRH_StringCompareLS/GetSimilarity
  libmrhvt_Directory/String/Compare/MRH_Levenshtein/MRH_StringCompareLS/IsSimilar
  libmrhvt_Directory/String/Compare/MRH_Levenshtein/MRH_StringCompareLS/ContainedIn
  libmrhvt_Directory/String/MRH_StringConvert/ToLower
  libmrhvt_Directory/String/MRH_StringConvert/ToUpper
  libmrhvt_Directory/String/MRH_LocalisedPath/GetPath
  libmrhvt_Directory/String/MRH_SpeechString/MRH_SpeechString_0
  libmrhvt_Directory/String/MRH_SpeechString/MRH_SpeechString_1
  libmrhvt_Directory/String/MRH_SpeechString/~MRH_SpeechString
  libmrhvt_Directory/String/MRH_SpeechString/SplitString
  libmrhvt_Directory/String/MRH_SpeechString/Reset_0
  libmrhvt_Directory/String/MRH_SpeechString/Reset_1
  libmrhvt_Directory/String/MRH_SpeechString/Add
  libmrhvt_Directory/String/MRH_SpeechString/GetState
  libmrhvt_Directory/String/MRH_SpeechString/GetString
  libmrhvt_Directory/String/MRH_SpeechString/GetID
  libmrhvt_Directory/MRH_VTException/MRH_VTException_0
  libmrhvt_Directory/MRH_VTException/MRH_VTException_1
  libmrhvt_Directory/MRH_VTException/~MRH_VTException
  libmrhvt_Directory/MRH_VTException/what
  libmrhvt_Directory/MRH_VTException/what2
  libmrhvt_Directory/MRH_VTRevision/MRH_GetLibraryVersionMajor
  libmrhvt_Directory/MRH_VTRevision/MRH_GetLibraryVersionMinor
  libmrhvt_Directory/MRH_VTRevision/MRH_GetLibraryVersionPatch

Internal Functions
------------------
.. toctree::
  :maxdepth: 1

  _Internal/libmrhvt_Directory/Input/MRH_InputTrigger/SetupFile
  _Internal/libmrhvt_Directory/Input/MRH_InputTrigger/SearchTrigger
  _Internal/libmrhvt_Directory/Output/MRH_OutputGenerator/SetupFile
  _Internal/libmrhvt_Directory/Output/MRH_OutputGenerator/SelectElement
  _Internal/libmrhvt_Directory/Output/MRH_OutputGenerator/RandomSentence
  _Internal/libmrhvt_Directory/Output/MRH_OutputGenerator/RandomWord
  
  