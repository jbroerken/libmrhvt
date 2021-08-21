MRH_Output
==========
The MRH_Output struct stores conversation output information.

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
    * - :doc:`../../../../Functions/_Internal/libmrhvt_Directory/Log/Output/Output_0`
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
      - The string id for the output.
      - Public
    * - s_String
      - std::string
      - The completed output string.
      - Public
    * - b_Performed
      - bool
      - If the speech output has been performed.
      - Public


Remarks
-------
* This struct is used internally in the conversation log.