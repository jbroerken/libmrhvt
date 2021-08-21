Add (Speech String)
===================
The Add function is used to append string parts to the speech string.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/String/MRH_SpeechString.h>


Syntax
------
.. code-block:: c

    State Add(std::string const& s_String, 
              MRH_Uint32 u32_Part, 
              bool b_End);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - s_String
      - The string bytes for the given part.
    * - u32_Part
      - The part id for the given part.
    * - b_End
      - If this part is already the end part.


Return Value
------------
The state of the string after appending the new part.

Remarks
-------
* Part ids are unique and can not be added multiple times.
* Part ids need to be squential from 0 to the part id of the end.

Code Examples
-------------
None.