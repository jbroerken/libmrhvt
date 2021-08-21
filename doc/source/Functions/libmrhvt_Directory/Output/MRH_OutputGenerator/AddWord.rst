AddWord
=======
The AddWord function is used to add a new word to the output generator.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/Output/MRH_OutputGenerator.h>


Syntax
------
.. code-block:: c

    void AddWord(MRH_Word const& c_Word) noexcept;


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - c_Word
      - The new word to add.
      

Return Value
------------
None.

Remarks
-------
* The word group assignment is done using the word group id.

Code Examples
-------------
None.