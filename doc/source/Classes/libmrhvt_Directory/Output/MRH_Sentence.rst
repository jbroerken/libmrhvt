MRH_Sentence
============
The MRH_Sentence class represents a usable base sentence.

Header
------
The class definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/Output/MRH_Sentence.h>


Functions
---------
.. list-table::
    :header-rows: 1

    * - Function
      - Visibility
    * - :doc:`../../../Functions/libmrhvt_Directory/Output/MRH_Sentence/MRH_Sentence_0`
      - Public
    * - :doc:`../../../Functions/libmrhvt_Directory/Output/MRH_Sentence/~MRH_Sentence`
      - Public
    * - :doc:`../../../Functions/libmrhvt_Directory/Output/MRH_Sentence/GetString`
      - Public
    * - :doc:`../../../Functions/libmrhvt_Directory/Output/MRH_Sentence/GetUseChance`
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
      - The highest use chance in percent for all sentence.
      - Public
    * - f64_UseChanceMin
      - static const MRH_Sfloat64
      - The lowest use chance in percent for all sentences.
      - Public
    * - s_String
      - std::string
      - The base UTF-8 sentence string.
      - Private
    * - f64_UseChance
      - MRH_Sfloat64
      - The use chance in percent for this sentence.
      - Private


Remarks
-------
None.