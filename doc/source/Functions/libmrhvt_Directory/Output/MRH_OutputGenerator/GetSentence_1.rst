GetSentence (Const Reference)
=============================
The const reference GetSentence function is used to get a specified 
sentence as a const reference.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/Output/MRH_OutputGenerator.h>


Syntax
------
.. code-block:: c

    MRH_Sentence const& GetSentence(size_t us_Sentence) const;


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - us_Sentence
      - The index of the sentence requested.
      

Return Value
------------
The requested sentence as a const reference.

Remarks
-------
* Make sure to not remove the sentence if a reference is still active.

Code Examples
-------------
None.