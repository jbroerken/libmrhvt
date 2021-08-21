Clean
=====
The Clean function is used to remove string from a given source with a given 
clean set.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/String/MRH_Clean.h>


Syntax
------
.. code-block:: c

    void Clean(std::string& s_String, 
               MRH_CleanSet const& s_Set);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - s_String
      - The UTF-8 string to clean.
    * - s_Set
      - The clean set to use for cleaning.


Return Value
------------
None.

Remarks
-------
* Only exact matches will be cleaned.
* Whitespace seperators will be kept when possible.

Code Examples
-------------
None.