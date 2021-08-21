GetTrigger (Reference)
======================
The reference GetTrigger function is used to get a specified trigger 
to be edited.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/Input/MRH_InputTrigger.h>


Syntax
------
.. code-block:: c

    MRH_Trigger& GetTrigger(size_t us_Trigger);


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
The requested trigger as a reference.

Remarks
-------
* Make sure to not remove the trigger if a reference is still active.

Code Examples
-------------
None.