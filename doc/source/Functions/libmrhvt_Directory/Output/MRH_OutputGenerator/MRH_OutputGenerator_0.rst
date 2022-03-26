MRH_OutputGenerator (Default Constructor)
=========================================
The default MRH_OutputGenerator constructor function is used to construct a 
MRH_OutputGenerator object with given output information.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/Output/MRH_OutputGenerator.h>


Syntax
------
.. code-block:: c

    MRH_OutputGenerator(std::deque<MRH_Sentence>& dq_Sentence,
                        std::deque<MRH_Placement>& dq_Placement,
                        std::unordered_map<MRH_Uint32, std::deque<MRH_Word>>& m_Word);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - dq_Sentence
      - The sentences for the generator. The deque is consumed.
    * - dq_Placement
      - The placements for the generator. The deque is consumed.
    * - m_Word
      - The words for the generator. The words are consumed.


Return Value
------------
None.

Remarks
-------
None.

Code Examples
-------------
None.