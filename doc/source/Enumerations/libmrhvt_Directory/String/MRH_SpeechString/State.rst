State
=====
The State enumeration lists all possible states for a speech string.

Header
------
The enumeration definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/String/MRH_SpeechString.h>


Definition
----------
The defined enumeration values are as follows:

.. code-block:: c

    enum State
    {
        UNFINISHED = 0, // No end
        END_KNOWN = 1, // End known but gaps
        COMPLETE = 2, // Fully assembled
        
        STATE_MAX = COMPLETE,
        
        STATE_COUNT = STATE_MAX + 1
    };


Values
------
The meaning behind the enumeration values is as follows:

.. list-table::
    :header-rows: 1

    * - Enumeration
      - Description
    * - UNFINISHED
      - The string has no known end.
    * - END_KNOWN
      - The end part was recieved but not all parts between beginning and
        end exist.
    * - COMPLETE
      - The string end is known and all parts exist.
    * - STATE_MAX
      - The highest value in this enumeration.
    * - STATE_COUNT
      - The amount of values in this enumeration.