MRH_OutputGenerator (Locale Constructor)
========================================
The locale based MRH_OutputGenerator constructor function is used to construct the 
MRH_OutputGenerator class by creating a locale path from a given directory path and 
file name.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhvt/Output/MRH_OutputGenerator.h>


Syntax
------
.. code-block:: c

    MRH_OutputGenerator(std::string s_DirPath,
                        std::string const& s_FileName);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - s_DirPath
      - The full path to the output generator directory.
    * - s_FileName
      - The name of the output generator file.


Return Value
------------
None.

Remarks
-------
* The locale directory appended to the file path is retrieved by std::setlocale.

Code Examples
-------------
None.