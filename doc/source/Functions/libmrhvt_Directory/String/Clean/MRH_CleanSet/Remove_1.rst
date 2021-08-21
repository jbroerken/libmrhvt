Remove (Clean Set String Compare)
=================================
The clean set string compare Remove function is used to remove strings from the 
clean set based on a reference string given.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/String/Clean/MRH_CleanSet.h>


Syntax
------
.. code-block:: c

    void Remove(std::string const& s_String) noexcept;


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - s_String
      - The UTF-8 string to compare set strings with.


Return Value
------------
None.

Remarks
-------
* This function will remove all matches.

Code Examples
-------------
None.