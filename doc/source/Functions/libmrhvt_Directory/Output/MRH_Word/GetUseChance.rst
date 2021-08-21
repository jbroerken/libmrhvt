GetUseChance (Output Word)
==========================
The GetUseChance function is used to retrieve the word use chance.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/Output/MRH_Word.h>


Syntax
------
.. code-block:: c

    MRH_Sfloat64 GetUseChance() const noexcept;


Parameters
----------
None.

Return Value
------------
The word use chance in percent.

Remarks
-------
* The returned value is in the range from 0.f (0 percent) to 1.f (100 percent).

Code Examples
-------------
None.