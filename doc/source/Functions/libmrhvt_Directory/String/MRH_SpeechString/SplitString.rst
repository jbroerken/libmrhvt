SplitString
===========
The SplitString function is used to split a given UTF-8 string into 
string parts for use with the MRH speech events.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/String/MRH_SpeechString.h>


Syntax
------
.. code-block:: c

    static std::map<MRH_Uint32, std::string> SplitString(std::string s_String);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - s_String
      - The UTF-8 string to split into parts.


Return Value
------------
A map containing all string parts ordered by the part ids as 
the map key.

Remarks
-------
* This function is static and can be used without a class instance.
* String part ids are ordered from 0 (Start) to the last part (End).
* There will be no gaps in the part ids.
* Each part string size is matching for the speech event type buffers.

Code Examples
-------------
None.