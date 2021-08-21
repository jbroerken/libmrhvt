GetPlacement (Const Reference)
==============================
The const reference GetPlacement function is used to get a specified 
placement as a const reference.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/Output/MRH_OutputGenerator.h>


Syntax
------
.. code-block:: c

    MRH_Placement const& GetPlacement(size_t us_Placement) const;


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - us_Placement
      - The index of the placement requested.
      

Return Value
------------
The requested placement as a const reference.

Remarks
-------
* Make sure to not remove the placement if a reference is still active.

Code Examples
-------------
None.