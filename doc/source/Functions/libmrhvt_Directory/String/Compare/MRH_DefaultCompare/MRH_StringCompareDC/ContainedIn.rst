ContainedIn (Default Compare)
=============================
The default compare ContainedIn function is used to check is a substring is 
contained in a given string using default STL library methods.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/String/Compare/MRH_DefaultCompare.h>


Syntax
------
.. code-block:: c

    bool ContainedIn(std::string const& s_Contained, 
                     std::string const& s_In) noexcept;


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


Return Value
------------
true if the string was found, false if not.

Remarks
-------
None.

Code Examples
-------------
None.