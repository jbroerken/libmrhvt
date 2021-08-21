IsSimilar (Default Compare)
===========================
The default compare IsSimilar function is used to check string similarity using 
default STL library methods.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/String/Compare/MRH_DefaultCompare.h>


Syntax
------
.. code-block:: c

    bool IsSimilar(std::string const& s_Compare, 
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
true if the strings are similar, false if not.

Remarks
-------
None.

Code Examples
-------------
None.