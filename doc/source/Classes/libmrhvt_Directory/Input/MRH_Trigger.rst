MRH_Trigger
===========
The MRH_Trigger class serves as the base class for all trigger types. It stores 
general information required by all triggers.

Header
------
The class definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/Input/MRH_Trigger.h>


Functions
---------
.. list-table::
    :header-rows: 1

    * - Function
      - Visibility
    * - :doc:`../../../Functions/libmrhvt_Directory/Input/MRH_Trigger/MRH_Trigger_0`
      - Public
    * - :doc:`../../../Functions/libmrhvt_Directory/Input/MRH_Trigger/MRH_Trigger_1`
      - Public
    * - :doc:`../../../Functions/libmrhvt_Directory/Input/MRH_Trigger/~MRH_Trigger`
      - Public
    * - :doc:`../../../Functions/libmrhvt_Directory/Input/MRH_Trigger/GetString`
      - Public
    * - :doc:`../../../Functions/libmrhvt_Directory/Input/MRH_Trigger/GetWeight`
      - Public
    * - :doc:`../../../Functions/libmrhvt_Directory/Input/MRH_Trigger/GetValue`
      - Public


Enumerations
------------
None.

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
    * - u32_WeightMin
      - static const MRH_Uint32
      - The minimal weight value for a trigger.
      - Public
    * - u32_WeightMax
      - static const MRH_Uint32
      - The maximum weight value for a trigger.
      - Public
    * - s32_ValueInvalid
      - static const MRH_Sint32
      - The set value of triggers which is seen as invalid (no action).
      - Public
    * - s_String
      - std::string
      - The UTF-8 string for this trigger (word or sentence part).
      - Protected
    * - u32_Weight
      - MRH_Uint32
      - The weight for this trigger.
      - Private
    * - s32_Value
      - MRH_Sint32
      - The value for this trigger.
      - Private


Remarks
-------
None.