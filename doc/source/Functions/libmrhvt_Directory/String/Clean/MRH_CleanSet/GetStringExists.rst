GetStringExists
===============
The GetStringExists function is used to check for a matching string inside the 
clean set.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/String/Clean/MRH_CleanSet.h>


Syntax
------
.. code-block:: c

    bool GetStringExists(std::string const& s_String) const noexcept;


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - s_String
      - The UTF-8 string to check for.


Return Value
------------
true if the string exists, false if not.

Remarks
-------
* The string has to match exactly.
* This function will return on the first match, ignoring others.

Code Examples
-------------
None.