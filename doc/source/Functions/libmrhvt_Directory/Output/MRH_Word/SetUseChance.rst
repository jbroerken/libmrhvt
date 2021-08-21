SetUseChance (Output Word)
==========================
The SetUseChance function is used to update the word use chance percentage.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/Output/MRH_Word.h>


Syntax
------
.. code-block:: c

    void SetUseChance(MRH_Sfloat64 f64_UseChance) noexcept;


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - f64_UseChance
      - The use chance in percent.


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