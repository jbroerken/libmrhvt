ContainedIn (Levenshtein)
==========================
The levenshtein ContainedIn function is used to check is a substring is 
contained in a given string using default the levenstein method.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/String/Compare/MRH_Levenshtein.h>


Syntax
------
.. code-block:: c

    bool ContainedIn(std::string const& s_Contained, 
                     std::string const& s_In,
                     MRH_Sfloat64 f64_Required) noexcept;


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - s_Contained
      - The UTF-8 string to search for.
    * - s_In
      - The UTF-8 string to search in.
    * - f64_Required
      - The required similarity in percent (0.f - 1.f).


Return Value
------------
true if the string was found, false if not.

Remarks
-------
None.

Code Examples
-------------
None.