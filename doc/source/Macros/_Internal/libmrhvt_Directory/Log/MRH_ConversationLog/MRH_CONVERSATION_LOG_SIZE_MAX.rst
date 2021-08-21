MRH_CONVERSATION_LOG_SIZE_MAX
=============================
The MRH_CONVERSATION_LOG_SIZE_MAX macro defines the maximum amount of 
stored conversation pieces to keep at a time.

Header
------
The macro definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/Log/MRH_ConversationLog.h>


Definition
----------
The defined backlog size in the source is as follows:

.. code-block:: c

    #ifndef MRH_CONVERSATION_LOG_SIZE_MAX
    #define MRH_CONVERSATION_LOG_SIZE_MAX 100
    #endif