MRH_OutputGenerator
===================
The MRH_OutputGenerator class is used to generate output sentences from the 
stored base word groups and sentences.

Header
------
The class definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/Output/MRH_OutputGenerator.h>


Functions
---------
.. list-table::
    :header-rows: 1

    * - Function
      - Visibility
    * - :doc:`../../../Functions/libmrhvt_Directory/Output/MRH_OutputGenerator/MRH_OutputGenerator_0`
      - Public
    * - :doc:`../../../Functions/libmrhvt_Directory/Output/MRH_OutputGenerator/MRH_OutputGenerator_1`
      - Public
    * - :doc:`../../../Functions/libmrhvt_Directory/Output/MRH_OutputGenerator/~MRH_OutputGenerator`
      - Public
    * - :doc:`../../../Functions/libmrhvt_Directory/Output/MRH_OutputGenerator/Generate`
      - Public
    * - :doc:`../../../Functions/libmrhvt_Directory/Output/MRH_OutputGenerator/AddWord`
      - Public
    * - :doc:`../../../Functions/libmrhvt_Directory/Output/MRH_OutputGenerator/AddPlacement`
      - Public
    * - :doc:`../../../Functions/libmrhvt_Directory/Output/MRH_OutputGenerator/AddSentence`
      - Public
    * - :doc:`../../../Functions/libmrhvt_Directory/Output/MRH_OutputGenerator/RemoveWord`
      - Public
    * - :doc:`../../../Functions/libmrhvt_Directory/Output/MRH_OutputGenerator/RemovePlacement`
      - Public
    * - :doc:`../../../Functions/libmrhvt_Directory/Output/MRH_OutputGenerator/RemoveSentence`
      - Public
    * - :doc:`../../../Functions/libmrhvt_Directory/Output/MRH_OutputGenerator/GetSentenceCount`
      - Public
    * - :doc:`../../../Functions/libmrhvt_Directory/Output/MRH_OutputGenerator/GetPlacementCount`
      - Public
    * - :doc:`../../../Functions/libmrhvt_Directory/Output/MRH_OutputGenerator/GetWordCount`
      - Public
    * - :doc:`../../../Functions/libmrhvt_Directory/Output/MRH_OutputGenerator/GetSentence_0`
      - Public
    * - :doc:`../../../Functions/libmrhvt_Directory/Output/MRH_OutputGenerator/GetSentence_1`
      - Public
    * - :doc:`../../../Functions/libmrhvt_Directory/Output/MRH_OutputGenerator/GetPlacement_0`
      - Public
    * - :doc:`../../../Functions/libmrhvt_Directory/Output/MRH_OutputGenerator/GetPlacement_1`
      - Public
    * - :doc:`../../../Functions/libmrhvt_Directory/Output/MRH_OutputGenerator/GetWord_0`
      - Public
    * - :doc:`../../../Functions/libmrhvt_Directory/Output/MRH_OutputGenerator/GetWord_1`
      - Public
    * - :doc:`../../../Functions/_Internal/libmrhvt_Directory/Output/MRH_OutputGenerator/SetupFile`
      - Private
    * - :doc:`../../../Functions/_Internal/libmrhvt_Directory/Output/MRH_OutputGenerator/SelectElement`
      - Private
    * - :doc:`../../../Functions/_Internal/libmrhvt_Directory/Output/MRH_OutputGenerator/RandomSentence`
      - Private
    * - :doc:`../../../Functions/_Internal/libmrhvt_Directory/Output/MRH_OutputGenerator/RandomWord`
      - Private


Enumerations
------------
None.

Nested Classes
--------------
None.

Inherited Classes
-----------------
None.

Variables
---------
.. list-table::
    :header-rows: 1

    * - Name
      - Type
      - Description
      - Visbility
    * - dq_Sentence
      - std::deque<MRH_Sentence>
      - All sentences bases to use.
      - Private
    * - dq_Placement
      - std::deque<MRH_Placement>
      - All known sentence placements.
      - Private
    * - m_Word
      - std::unordered_map<MRH_Uint32, std::deque<MRH_Word>>
      - All words sorted by their group id.
      - Private


Remarks
-------
None.