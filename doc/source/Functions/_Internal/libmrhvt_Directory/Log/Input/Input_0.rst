Input (Default Constructor)
===========================
The Input struct constructor function is used to construct a log input 
struct.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/Log/MRH_ConversationLog.h>


Syntax
------
.. code-block:: c

    Input(MRH_Uint32 u32_StringID.
          MRH_Uint64 u64_Timestamp) noexcept;


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - u32_StringID
      - The string id of the speech string.
    * - u64_Timestamp
      - The time stamp on which the first string part was recieved.


Return Value
------------
None.

Remarks
-------
None.

Code Examples
-------------
None.