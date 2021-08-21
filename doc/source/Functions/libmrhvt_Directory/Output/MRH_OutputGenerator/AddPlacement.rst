AddPlacement
============
The AddPlacement function is used to add a new placement to the 
output generator.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/Output/MRH_OutputGenerator.h>


Syntax
------
.. code-block:: c

    void AddPlacement(MRH_Placement const& c_Placement) noexcept;


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - c_Placement
      - The new placement to add.
      

Return Value
------------
None.

Remarks
-------
* Make sure that words for the placement word group exist.

Code Examples
-------------
None.