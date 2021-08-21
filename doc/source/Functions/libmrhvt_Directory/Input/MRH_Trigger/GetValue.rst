GetValue (Input Trigger)
========================
The GetValue function is used to retrieve the trigger value.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/Input/MRH_Trigger.h>


Syntax
------
.. code-block:: c

    MRH_Sint32 GetValue() const noexcept;


Parameters
----------
None.

Return Value
------------
The trigger value.

Remarks
-------
* Trigger values lower than 0 are seen as invalid.

Code Examples
-------------
None.