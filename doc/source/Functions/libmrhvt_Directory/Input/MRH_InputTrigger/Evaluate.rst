Evaluate
========
The Evaluate function is used to search for known triggers in a given string 
and select the trigger value most likely match.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/Input/MRH_InputTrigger.h>


Syntax
------
.. code-block:: c

    Evaluation Evaluate(std::string s_String, 
                        MRH_Uint32 u32_RequiredWeight) const noexcept;


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - s_String
      - The string to search in.
    * - u32_RequiredWeight
      - The minimal combined weight for a trigger value to be considered.
      

Return Value
------------
A pair with the value and combined weight of the most likely match, or 
the invalid trigger value with a weight of 0 if no matches were found.

Remarks
-------
* The given string will be converted to lowercase.
* The evaluation weight is the combined weight of all found triggers which 
  have the same trigger value.

Code Examples
-------------
None.