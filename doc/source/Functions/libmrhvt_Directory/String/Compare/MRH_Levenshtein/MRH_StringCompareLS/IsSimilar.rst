IsSimilar (Levenshtein)
=======================
The IsSimilar function is used to check string similarity using the 
levenshtein compare method.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/String/Compare/MRH_Levenshtein.h>


Syntax
------
.. code-block:: c

    bool IsSimilar(std::string const& s_Compare, 
                   std::string const& s_With, 
                   MRH_Sfloat64 f64_Required) noexcept;


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
    * - f64_Required
      - The required similarity in percent (0.f - 1.f).


Return Value
------------
true if the strings are similar enough, false if not.

Remarks
-------
None.

Code Examples
-------------
None.