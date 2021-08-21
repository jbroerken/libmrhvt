MRH_CleanSet (Locale Directory Constructor)
===========================================
The locale directory MRH_CleanSet constructor function is used to construct a 
clean set from a directory which contains the given file inside of a locale 
based folder.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/String/Clean/MRH_CleanSet.h>


Syntax
------
.. code-block:: c

    MRH_CleanSet(std::string s_DirPath,
                 std::string const& s_FileName) noexcept;


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - s_DirPath
      - The full path to the directory containing all locale directories.
    * - s_FileName
      - The name of the file to load inside the locale directory.


Return Value
------------
None.

Remarks
-------
None.

Code Examples
-------------
None.