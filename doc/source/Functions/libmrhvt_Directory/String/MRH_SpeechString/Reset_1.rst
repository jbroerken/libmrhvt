Reset (New Initial Part)
========================
The Reset with new initial part function is used to reset the speech string 
and add a new initial part.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/String/MRH_SpeechString.h>


Syntax
------
.. code-block:: c

    void Reset(std::string const& s_String, 
               MRH_Uint32 u32_ID, 
               MRH_Uint32 u32_Part, 
               bool b_End);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - s_String
      - The string bytes for the initial part.
    * - u32_Part
      - The part id for the initial part.
    * - u32_ID
      - The string id of the speech string.
    * - b_End
      - If this initial part is already the end part.


Return Value
------------
None.

Remarks
-------
None.

Code Examples
-------------
None.