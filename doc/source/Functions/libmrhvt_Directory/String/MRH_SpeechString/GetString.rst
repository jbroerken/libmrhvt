GetString (Speech String)
=========================
The GetString function is used to retrieve the string bytes of the 
speech string.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/String/MRH_SpeechString.h>


Syntax
------
.. code-block:: c

    std::string GetString() const noexcept;


Parameters
----------
None.

Return Value
------------
The combined speech string string bytes.

Remarks
-------
* The string is constructed based on part order.
* The speech string does not have to be completed.

Code Examples
-------------
None.