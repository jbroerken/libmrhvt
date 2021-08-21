Distance
========
The Distance function is used to calculate the levenshtein distance.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/String/Compare/MRH_Levenshtein.h>


Syntax
------
.. code-block:: c

    size_t Distance(std::string const& s_Compare, 
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
The calculated levenshtein distance.

Remarks
-------
None.

Code Examples
-------------
None.