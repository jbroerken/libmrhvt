RemoveWord
==========
The RemoveWord function is used to remove a known word from a 
word group.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/Output/MRH_OutputGenerator.h>


Syntax
------
.. code-block:: c

    void RemoveWord(MRH_Uint32 u32_GroupID, 
                    size_t us_Word);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - u32_GroupID
      - The word group id for the word.
    * - us_Word
      - The index of the word inside the word group.
      

Return Value
------------
None.

Remarks
-------
* Make sure to not remove the word if a reference is still active.

Code Examples
-------------
None.