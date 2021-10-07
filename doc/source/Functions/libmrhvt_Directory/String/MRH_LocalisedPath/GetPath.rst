GetPath
=======
The GetPath functions creates a locale including path created from the 
path to the locale directory and the path inside the locale directory.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/String/MRH_LocalisedPath.h>


Syntax
------
.. code-block:: c

    std::string GetPath(std::string s_ToPath, 
                        std::string const& s_FromPath) noexcept;


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - s_ToPath
      - The path to the directory containing localised directories.
    * - s_FromPath
      - The path inside the locale directory to append.


Return Value
------------
The created locale path.

Remarks
-------
* The locale directory names is retrieved with the setlocale() function.
* The "Default" directory will be chosen as the locale directory if no 
  directory for the current locale exists.
* The locale used to append to the path is read from LC_ALL.

Code Examples
-------------
None.