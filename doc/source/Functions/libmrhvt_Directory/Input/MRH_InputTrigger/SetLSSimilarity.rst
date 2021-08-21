SetLSSimilarity
===============
The SetLSSimilarity function is used to update the leveshtein match percentage.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/Input/MRH_InputTrigger.h>


Syntax
------
.. code-block:: c

    void SetLSSimilarity(MRH_Sfloat64 f64_Similarity) noexcept;


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - f64_Similarity
      - The required levenstein similarity.


Return Value
------------
None.

Remarks
-------
* The levenshtein percentage is in the range of 0.f (0 percent) to 1.f (100 percent).
* Values below 0.f will be corrected to 0.f.
* Values above 1.f will be corrected to 1.f.

Code Examples
-------------
None.