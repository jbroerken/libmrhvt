MRH_SpeechString
================
The MRH_SpeechString class is used to store a output string by it's chunks and 
allows for tracking and building the finished speech string.

Header
------
The class definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/String/MRH_SpeechString.h>


Functions
---------
.. list-table::
    :header-rows: 1

    * - Function
      - Visibility
    * - :doc:`../../../../Functions/libmrhvt_Directory/String/MRH_SpeechString/MRH_SpeechString_0`
      - Public
    * - :doc:`../../../../Functions/libmrhvt_Directory/String/MRH_SpeechString/MRH_SpeechString_1`
      - Public
    * - :doc:`../../../../Functions/libmrhvt_Directory/String/MRH_SpeechString/~MRH_SpeechString`
      - Public
    * - :doc:`../../../../Functions/libmrhvt_Directory/String/MRH_SpeechString/SplitString`
      - Public
    * - :doc:`../../../../Functions/libmrhvt_Directory/String/MRH_SpeechString/Reset_0`
      - Public
    * - :doc:`../../../../Functions/libmrhvt_Directory/String/MRH_SpeechString/Reset_1`
      - Public
    * - :doc:`../../../../Functions/libmrhvt_Directory/String/MRH_SpeechString/Add`
      - Public
    * - :doc:`../../../../Functions/libmrhvt_Directory/String/MRH_SpeechString/GetState`
      - Public
    * - :doc:`../../../../Functions/libmrhvt_Directory/String/MRH_SpeechString/GetString`
      - Public
    * - :doc:`../../../../Functions/libmrhvt_Directory/String/MRH_SpeechString/GetID`
      - Public


Enumerations
------------
.. list-table::
    :header-rows: 1

    * - Enumeration
      - Visibility
    * - :doc:`../../../Enumerations/libmrhvt_Directory/String/MRH_SpeechString/State`
      - Public
      

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
    * - m_Part
      - std::map<MRH_Uint32, std::string>
      - All known string part sorted by their part id.
      - Private
    * - c_End
      - std::pair<bool, MRH_Uint32>
      - The end part information (existing, part id).
      - Private
    * - u32_ID
      - MRH_Uint32
      - The string id of the speech string.
      - Private


Remarks
-------
None.