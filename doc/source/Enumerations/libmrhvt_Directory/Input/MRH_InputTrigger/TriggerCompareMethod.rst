TriggerCompareMethod
====================
The TriggerCompareMethod enumeration lists all possible string parts usable to 
compare string parts to trigger strings.

Header
------
The enumeration definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/Input/MRH_InputTrigger.h>


Definition
----------
The defined enumeration values are as follows:

.. code-block:: c

    enum TriggerCompareMethod
    {
        DEFAULT_COMPARE = 0,
        LEVENSHTEIN = 1,
        
        TRIGGER_COMPARE_METHOD_MAX = LEVENSHTEIN,
        
        TRIGGER_COMPARE_METHOD_COUNT = TRIGGER_COMPARE_METHOD_MAX + 1
    };


Values
------
The meaning behind the enumeration values is as follows:

.. list-table::
    :header-rows: 1

    * - Enumeration
      - Description
    * - DEFAULT_COMPARE
      - Default strcmp / compare operation.
    * - LEVENSHTEIN
      - Levenshtein algorithm for percentage matching.
    * - TRIGGER_COMPARE_METHOD_MAX
      - The highest value in this enumeration.
    * - TRIGGER_COMPARE_METHOD_COUNT
      - The amount of values in this enumeration.