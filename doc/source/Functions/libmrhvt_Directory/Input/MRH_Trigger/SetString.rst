SetString (Input Trigger)
=========================
The SetString method is used to update the trigger string.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/Input/MRH_Trigger.h>


Syntax
------
.. code-block:: c

    void SetString(std::string const& s_String);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - s_String
      - The UTF-8 trigger string.


Return Value
------------
None.

Remarks
-------
* The string will be converted to lowercase.

Code Examples
-------------
None.