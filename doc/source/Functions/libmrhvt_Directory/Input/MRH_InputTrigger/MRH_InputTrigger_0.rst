MRH_InputTrigger (Default Constructor)
======================================
The default MRH_InputTrigger constructor function is used to construct the 
MRH_InputTrigger class by defining compare method information and a list 
of triggers to use.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/Input/MRH_InputTrigger.h>


Syntax
------
.. code-block:: c

    MRH_InputTrigger(TriggerCompareMethod e_CompareMethod,
                     MRH_Sfloat64 f64_LSSimilarity,
                     std::deque<MRH_Trigger>& dq_Trigger) noexcept;


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - e_CompareMethod
      - The trigger compare method to use.
    * - f64_LSSimilarity
      - The minimal required levenstein similarity.
    * - dq_Trigger
      - The triggers to include. The deque is consumed.


Return Value
------------
None.

Remarks
-------
None.

Code Examples
-------------
None.