AddTrigger
==========
The AddTrigger function is used to add a new trigger to the vector of 
known triggers.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/Input/MRH_InputTrigger.h>


Syntax
------
.. code-block:: c

    void AddTrigger(MRH_Trigger const& c_Trigger) noexcept;


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - c_Trigger
      - The new trigger to add.
      

Return Value
------------
None.

Remarks
-------
* The trigger will be added to the end of the known trigger 
  vector.

Code Examples
-------------
None.