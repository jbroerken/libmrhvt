MRH_Word (Default Constructor)
==============================
The default MRH_Word constructor function is used to construct the MRH_Word class.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/Output/MRH_Word.h>


Syntax
------
.. code-block:: c

    MRH_Word(std::string const& s_String,
             MRH_Uint32 u32_GroupID,
             MRH_Sfloat64 f64_UseChance);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - s_String
      - The UTF-8 word string to place.
    * - u32_GroupID
      - The placement word group id.
    * - f64_UseChance
      - The word use chance.


Return Value
------------
None.

Remarks
-------
* The use chance percentage is in the range of 0.f (0 percent) to 1.f (100 percent).
* A 0 percent use chance does not disable the word.
* Values below 0.f will be corrected to 0.f.
* Values above 1.f will be corrected to 1.f.

Code Examples
-------------
None.