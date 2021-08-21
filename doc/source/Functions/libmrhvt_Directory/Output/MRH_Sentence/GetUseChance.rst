GetUseChance (Output Sentence)
==============================
The GetUseChance function is used to retrieve the sentence use chance.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/Output/MRH_Sentence.h>


Syntax
------
.. code-block:: c

    MRH_Sfloat64 GetUseChance() const noexcept;


Parameters
----------
None.

Return Value
------------
The sentence use chance in percent.

Remarks
-------
* The returned value is in the range from 0.f (0 percent) to 1.f (100 percent).

Code Examples
-------------
None.