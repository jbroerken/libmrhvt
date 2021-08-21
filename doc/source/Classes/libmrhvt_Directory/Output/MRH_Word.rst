MRH_Word
========
The MRH_Word class represents a word from a word group.

Header
------
The class definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/Output/MRH_Word.h>


Functions
---------
.. list-table::
    :header-rows: 1

    * - Function
      - Visibility
    * - :doc:`../../../Functions/libmrhvt_Directory/Output/MRH_Word/MRH_Word_0`
      - Public
    * - :doc:`../../../Functions/libmrhvt_Directory/Output/MRH_Word/~MRH_Word`
      - Public
    * - :doc:`../../../Functions/libmrhvt_Directory/Output/MRH_Word/GetString`
      - Public
    * - :doc:`../../../Functions/libmrhvt_Directory/Output/MRH_Word/GetGroupID`
      - Public
    * - :doc:`../../../Functions/libmrhvt_Directory/Output/MRH_Word/GetUseChance`
      - Public
    * - :doc:`../../../Functions/libmrhvt_Directory/Output/MRH_Word/SetString`
      - Public
    * - :doc:`../../../Functions/libmrhvt_Directory/Output/MRH_Word/SetUseChance`
      - Public


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
    * - f64_UseChanceMax
      - static const MRH_Sfloat64
      - The highest use chance in percent for all words.
      - Public
    * - f64_UseChanceMin
      - static const MRH_Sfloat64
      - The lowest use chance in percent for all words.
      - Public
    * - s_String
      - std::string
      - The UTF-8 word string.
      - Private
    * - u32_GroupID
      - MRH_Uint32
      - The word group id for this word.
      - Private
    * - f64_UseChance
      - MRH_Sfloat64
      - The use chance in percent for this word.
      - Private


Remarks
-------
None.