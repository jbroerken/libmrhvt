RandomWord
==========
The RandomWord function is used to pick a random word from a 
word group which is chosen from all known word groups. 

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/Output/MRH_OutputGenerator.h>


Syntax
------
.. code-block:: c

    const MRH_Word& RandomWord(MRH_Uint32 u32_GroupID) const;


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - u32_GroupID
      - The group id of the group to choose a random word 
        from.


Return Value
------------
The seletected word from the word group.

Remarks
-------
None.

Code Examples
-------------
None.