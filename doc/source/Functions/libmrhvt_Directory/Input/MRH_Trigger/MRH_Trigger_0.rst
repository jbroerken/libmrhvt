MRH_Trigger (Default Constructor)
=================================
The default MRH_Trigger constructor function is used to construct the 
MRH_Trigger class.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/Input/MRH_Trigger.h>


Syntax
------
.. code-block:: c

    MRH_Trigger(std::string const& s_String,
                MRH_Uint32 u32_Weight,
                MRH_Sint32 s32_Value);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - s_String
      - The UTF-8 trigger string.
    * - u32_Weight
      - The trigger weight.
    * - s32_Value
      - The trigger value.


Return Value
------------
None.

Remarks
-------
* The string will be converted to lowercase.
* Weight greater than 1000 will be corrected to 1000.
* Values lower than 0 will be corrected to 0.

Code Examples
-------------
None.