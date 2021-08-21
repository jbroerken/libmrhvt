GetTrigger (Const Reference)
============================
The const reference GetTrigger function is used to get a specified 
trigger as a const reference.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/Input/MRH_InputTrigger.h>


Syntax
------
.. code-block:: c

    MRH_Trigger const& GetTrigger(size_t us_Trigger);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - us_Trigger
      - The index of the trigger requested.
      

Return Value
------------
The requested trigger as a const reference.

Remarks
-------
* Make sure to not remove the trigger if a reference is still active.

Code Examples
-------------
None.