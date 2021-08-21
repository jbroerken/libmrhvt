SetValue (Input Trigger)
========================
The SetValue function is used to update the trigger value.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/Input/MRH_Trigger.h>


Syntax
------
.. code-block:: c

    void SetValue(MRH_Sint32 s32_Value) noexcept;


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - s32_Value
      - The trigger value.


Return Value
------------
None.

Remarks
-------
* Values lower than 0 will be corrected to 0.

Code Examples
-------------
None.