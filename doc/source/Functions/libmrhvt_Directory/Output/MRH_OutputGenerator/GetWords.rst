GetWords
========
The GetWords function is used to get all generator words for a 
word group.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/Output/MRH_OutputGenerator.h>


Syntax
------
.. code-block:: c

    std::deque<MRH_Word> const& GetWords(MRH_Uint32 u32_WordGroup) const;


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - u32_WordGroup
      - The word group id of the words.
      

Return Value
------------
The requested words of the word group.

Remarks
-------
None.

Code Examples
-------------
None.