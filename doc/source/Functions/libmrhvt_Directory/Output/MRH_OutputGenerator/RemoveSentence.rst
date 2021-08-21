RemoveSentence
==============
The RemoveSentence function is used to remove a known sentence.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/Output/MRH_OutputGenerator.h>


Syntax
------
.. code-block:: c

    void RemoveSentence(size_t us_Sentence);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - us_Sentence
      - The index of the sentence to remove.
      

Return Value
------------
None.

Remarks
-------
* Make sure to not remove the sentence if a reference is 
  still active.

Code Examples
-------------
None.