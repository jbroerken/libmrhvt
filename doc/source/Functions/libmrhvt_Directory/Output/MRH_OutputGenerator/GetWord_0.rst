GetWord (Reference)
===================
The reference GetWord function is used to get a specified 
word from a word group to be edited.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/Output/MRH_OutputGenerator.h>


Syntax
------
.. code-block:: c

    MRH_Word& GetWord(MRH_Uint32 u32_GroupID, 
                      size_t us_Word);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - u32_GroupID
      - The word group id of the word.
    * - us_Word
      - The index of the word in the word group requested.
      

Return Value
------------
The requested word as a reference.

Remarks
-------
* Make sure to not remove the word if a reference is 
  still active.

Code Examples
-------------
None.