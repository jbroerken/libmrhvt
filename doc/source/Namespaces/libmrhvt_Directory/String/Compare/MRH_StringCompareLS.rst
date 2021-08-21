MRH_StringCompareLS
===================
The MRH_StringCompareLS namespace contains functions used for various string 
comparision methods using the levenstein method.

Header
------
The namespace definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/String/Comprare/MRH_Levenshtein.h>


Classes
-------
None.

Functions
---------
.. list-table::
    :header-rows: 1

    * - Function
      - Visibility
    * - :doc:`../../../../Functions/libmrhvt_Directory/String/Compare/MRH_Levenshtein/MRH_StringCompareLS/Distance`
      - Public
    * - :doc:`../../../../Functions/libmrhvt_Directory/String/Compare/MRH_Levenshtein/MRH_StringCompareLS/GetSimilarity`
      - Public
    * - :doc:`../../../../Functions/libmrhvt_Directory/String/Compare/MRH_Levenshtein/MRH_StringCompareLS/IsSimilar`
      - Public
    * - :doc:`../../../../Functions/libmrhvt_Directory/String/Compare/MRH_Levenshtein/MRH_StringCompareLS/ContainedIn`
      - Public

      
Variables
---------
.. list-table::
    :header-rows: 1

    * - Name
      - Type
      - Description
      - Visbility
    * - f64_RequiredMin
      - static const MRH_Sfloat64
      - The minimal percentage match possible when using the levenshtein 
        comparison method.
      - Public
    * - f64_RequiredMax
      - static const MRH_Sfloat64
      - The maximal percentage match possible when using the levenshtein 
        comparison method.
      - Public


Remarks
-------
None.