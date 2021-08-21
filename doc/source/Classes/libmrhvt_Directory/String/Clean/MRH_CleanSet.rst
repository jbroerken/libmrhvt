MRH_CleanSet
============
The MRH_CleanSet class is used to store all strings intentended to be removed 
from a target.

Header
------
The class definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/String/Clean/MRH_CleanSet.h>


Functions
---------
.. list-table::
    :header-rows: 1

    * - Function
      - Visibility
    * - :doc:`../../../../Functions/libmrhvt_Directory/String/Clean/MRH_CleanSet/MRH_CleanSet_0`
      - Public
    * - :doc:`../../../../Functions/libmrhvt_Directory/String/Clean/MRH_CleanSet/MRH_CleanSet_1`
      - Public
    * - :doc:`../../../../Functions/libmrhvt_Directory/String/Clean/MRH_CleanSet/~MRH_CleanSet`
      - Public
    * - :doc:`../../../../Functions/libmrhvt_Directory/String/Clean/MRH_CleanSet/Add`
      - Public
    * - :doc:`../../../../Functions/libmrhvt_Directory/String/Clean/MRH_CleanSet/Remove_0`
      - Public
    * - :doc:`../../../../Functions/libmrhvt_Directory/String/Clean/MRH_CleanSet/Remove_1`
      - Public
    * - :doc:`../../../../Functions/libmrhvt_Directory/String/Clean/MRH_CleanSet/GetStringCount`
      - Public
    * - :doc:`../../../../Functions/libmrhvt_Directory/String/Clean/MRH_CleanSet/GetString`
      - Public
    * - :doc:`../../../../Functions/libmrhvt_Directory/String/Clean/MRH_CleanSet/GetStringExists`
      - Public
    * - :doc:`../../../../Functions/libmrhvt_Directory/String/Clean/MRH_CleanSet/SetString`
      - Public
    * - :doc:`../../../../Functions/_Internal/libmrhvt_Directory/String/Clean/MRH_CleanSet/SetupFile`
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
    * - v_String
      - std::vector<std::string>
      - All UTF-8 strings to be removed when using the set.
      - Private


Remarks
-------
None.