MRH_Input
=========
The MRH_Input struct stores conversation input information.

Header
------
The struct definition can be found in the following file:

.. code-block:: c

    #include "libmrhvt/Log/MRH_ConversationLog.h"


Functions
---------
.. list-table::
    :header-rows: 1

    * - Function
      - Visibility
    * - :doc:`../../../../Functions/_Internal/libmrhvt_Directory/Log/Input/Input_0`
      - Public
      
      
Variables
---------
.. list-table::
    :header-rows: 1

    * - Name
      - Type
      - Description
      - Visibility
    * - u32_StringID
      - MRH_Uint32
      - The string id for the input.
      - Public
    * - b_Completed
      - bool
      - The completion state (all parts in speech string).
      - Public
    * - s_String
      - std::string
      - The completed input string.
      - Public
    * - p_Parts
      - std::unique_ptr<MRH_SpeechString>
      - The speech string parts.
      - Public
    * - u64_Timestamp
      - MRH_Uint64
      - The time stamp on which the first part was recieved.
      - Public


Remarks
-------
* This struct is used internally in the conversation log.
* The speech parts will only be allocated if the input is not 
  finished.
* The completed string will be empty if the input was not finished.