RemovePlacement
===============
The RemovePlacement function is used to remove a known placement.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/Output/MRH_OutputGenerator.h>


Syntax
------
.. code-block:: c

    void RemovePlacement(size_t us_Placement);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - us_Placement
      - The index of the placement to remove.
      

Return Value
------------
None.

Remarks
-------
* Make sure to not remove the placement if a reference is 
  still active.

Code Examples
-------------
None.