SearchTrigger
=============
The SearchTrigger function is used to search for a given trigger string in a 
given full string.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/Input/MRH_InputTrigger.h>


Syntax
------
.. code-block:: c

    bool SearchTrigger(std::string const& s_String, 
                       std::string const& s_Trigger) const noexcept;


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - s_String
      - The string to search in.
    * - s_Trigger
      - The trigger string to search for.
      

Return Value
------------
true if the trigger was found, false if not.

Remarks
-------
* The search is done using the selected compare method.

Code Examples
-------------
None.