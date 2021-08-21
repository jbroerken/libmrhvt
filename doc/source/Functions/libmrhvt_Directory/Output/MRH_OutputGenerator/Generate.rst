Generate
========
The Generate function is used to create a output string by adding words 
selected from placement word groups into a base sentence string.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/Output/MRH_OutputGenerator.h>


Syntax
------
.. code-block:: c

    std::string Generate() const;


Parameters
----------
None.

Return Value
------------
The generated UTF-8 output string.

Remarks
-------
* Words, placements and sentences with a 0 percent use chance 
  are still considered (but this is a rare occurence).

Code Examples
-------------
None.