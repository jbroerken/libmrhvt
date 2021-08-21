GetPathDefault
==============
The GetPathDefault functions creates a default locale including path from a 
given directory path and file name.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/String/MRH_LocalisedPath.h>


Syntax
------
.. code-block:: c

    std::string GetPathDefault(std::string s_DirPath, 
                               std::string const& s_FileName) noexcept;


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - s_DirPath
      - The path to the directory containing the default directory.
    * - s_FilePath
      - The name of the file inside the default locale directory.


Return Value
------------
The created default locale path.

Remarks
-------
* The locale directory added is named "Default".

Code Examples
-------------
None.