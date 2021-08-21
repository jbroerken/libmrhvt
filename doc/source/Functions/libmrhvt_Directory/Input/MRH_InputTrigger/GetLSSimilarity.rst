GetLSSimilarity
===============
The GetLSSimilarity function is used to retrieve the required levenshtein similarity in percent 
to recognize a trigger as found.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/Input/MRH_InputTrigger.h>


Syntax
------
.. code-block:: c

    MRH_Sfloat64 GetLSSimilarity() const noexcept;


Parameters
----------
None.

Return Value
------------
The required levenshtein similarity in percent.

Remarks
-------
* The returned value ranges from 0.f (0 percent) to 1.f (100 percent).

Code Examples
-------------
None.