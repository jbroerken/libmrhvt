GetString (Clean Set)
=====================
The clean set GetString function is used to retrieve a string from the clean 
set.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/String/Clean/MRH_CleanSet.h>


Syntax
------
.. code-block:: c

    std::string GetString(size_t us_String) const;


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - us_String
      - The index of the string to recieve.


Return Value
------------
The requested UTF-8 string.

Remarks
-------
None.

Code Examples
-------------
None.