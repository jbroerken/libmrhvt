SetWeight (Input Trigger)
=========================
The SetWeight function is used to update the trigger weight.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/Input/MRH_Trigger.h>


Syntax
------
.. code-block:: c

    void SetWeight(MRH_Uint32 u32_Weight) noexcept;


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - u32_Weight
      - The trigger weight.


Return Value
------------
None.

Remarks
-------
* Weight greater than 1000 will be corrected to 1000.

Code Examples
-------------
None.