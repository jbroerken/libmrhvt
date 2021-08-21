SelectElement
=============
The SelectElement function is used to pick a random element based 
on given chances.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/Output/MRH_OutputGenerator.h>


Syntax
------
.. code-block:: c

    size_t SelectElement(std::vector<std::pair<size_t, MRH_Sfloat64>>& v_Chance) const noexcept;


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - v_Chance
      - The vector containing pairs of positions and their 
        use chance.


Return Value
------------
The index of the selected element as given in the chance 
vector.

Remarks
-------
None.

Code Examples
-------------
None.