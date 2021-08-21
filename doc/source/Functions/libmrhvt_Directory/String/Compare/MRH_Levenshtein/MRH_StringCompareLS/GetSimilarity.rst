GetSimilarity
=============
The GetSimilarity function is used to check the similarity between two 
strings in percent based on the levenshtein distance.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/String/Compare/MRH_Levenshtein.h>


Syntax
------
.. code-block:: c

    MRH_Sfloat64 GetSimilarity(std::string const& s_Compare, 
                               std::string const& s_With) noexcept;


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - s_Compare
      - The UTF-8 string to compare.
    * - s_With
      - The UTF-8 string to compare with.


Return Value
------------
The string similarity in percent (0.f - 1.f).

Remarks
-------
None.

Code Examples
-------------
None.