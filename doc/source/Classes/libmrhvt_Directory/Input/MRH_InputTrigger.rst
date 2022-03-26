MRH_InputTrigger
================
The MRH_InputTrigger class is used to store available triggers and evaluate 
them to choose a possible action based on input given.

Header
------
The class definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/Input/MRH_InputTrigger.h>


Functions
---------
.. list-table::
    :header-rows: 1

    * - Function
      - Visibility
    * - :doc:`../../../Functions/libmrhvt_Directory/Input/MRH_InputTrigger/MRH_InputTrigger_0`
      - Public
    * - :doc:`../../../Functions/libmrhvt_Directory/Input/MRH_InputTrigger/MRH_InputTrigger_1`
      - Public
    * - :doc:`../../../Functions/libmrhvt_Directory/Input/MRH_InputTrigger/~MRH_InputTrigger`
      - Public
    * - :doc:`../../../Functions/libmrhvt_Directory/Input/MRH_InputTrigger/Evaluate`
      - Public
    * - :doc:`../../../Functions/libmrhvt_Directory/Input/MRH_InputTrigger/AddTrigger`
      - Public
    * - :doc:`../../../Functions/libmrhvt_Directory/Input/MRH_InputTrigger/ClearTriggers`
      - Public
    * - :doc:`../../../Functions/libmrhvt_Directory/Input/MRH_InputTrigger/GetTriggers`
      - Public
    * - :doc:`../../../Functions/libmrhvt_Directory/Input/MRH_InputTrigger/GetCompareMethod`
      - Public
    * - :doc:`../../../Functions/libmrhvt_Directory/Input/MRH_InputTrigger/GetLSSimilarity`
      - Public
    * - :doc:`../../../Functions/_Internal/libmrhvt_Directory/Input/MRH_InputTrigger/SearchTrigger`
      - Private


Enumerations
------------
.. list-table::
    :header-rows: 1

    * - Enumeration
      - Visibility
    * - :doc:`../../../Enumerations/libmrhvt_Directory/Input/MRH_InputTrigger/TriggerCompareMethod`
      - Public


Nested Classes
--------------
None.

Inherited Classes
-----------------
None.

Variables
---------
.. list-table::
    :header-rows: 1

    * - Name
      - Type
      - Description
      - Visbility
    * - dq_Trigger
      - std::deque<MRH_Trigger>
      - All available triggers to use.
      - Private
    * - e_CompareMethod
      - :doc:`../../../Enumerations/libmrhvt_Directory/Input/MRH_InputTrigger/TriggerCompareMethod`
      - The compare method used to match string parts to triggers.
      - Private
    * - f64_LSSimilarity
      - MRH_Sfloat64
      - The required percentage match for the levenshtein comparison.
      - Private


Remarks
-------
None.