RemoveTrigger
=============
The RemoveTrigger function is used to remove a known trigger.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/Input/MRH_InputTrigger.h>


Syntax
------
.. code-block:: c

    void RemoveTrigger(size_t us_Trigger);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - us_Trigger
      - The index of the trigger to remove.
      

Return Value
------------
None.

Remarks
-------
* Make sure to not remove the trigger if a reference is still 
  active.

Code Examples
-------------
None.