Output (Default Constructor)
============================
The Output struct constructor function is used to construct a log output 
struct.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/Log/MRH_ConversationLog.h>


Syntax
------
.. code-block:: c

    Output(std::string const& s_String,
           MRH_Uint32 u32_StringID) noexcept;


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - s_String
      - The UTF-8 output string.
    * - u32_StringID
      - The string id of the speech string.


Return Value
------------
None.

Remarks
-------
None.

Code Examples
-------------
None.