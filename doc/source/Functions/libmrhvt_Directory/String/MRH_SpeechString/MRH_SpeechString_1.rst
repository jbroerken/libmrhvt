MRH_SpeechString (Initial Part Constructor)
===========================================
The initial MRH_SpeechString constructor function is used to construct 
a new speech string with a initial part.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/String/MRH_SpeechString.h>


Syntax
------
.. code-block:: c

    MRH_SpeechString(std::string const& s_String,
                     MRH_Uint32 u32_Part,
                     MRH_Uint32 u32_ID,
                     bool b_End) noexcept;


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