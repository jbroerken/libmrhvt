String Clean Set Files
======================
Clean set files are used to store a collection of words or sentences which 
should be removed from a string. 

All clean set files are simple text files with a **.mrhcs** file ending. 
These files are simple MRH block files with a special extension. As 
such, all block file rules apply.

Example File
------------
The following example file shows a simple clean set which is intended to remove 
bad words from a string.

.. literalinclude:: CleanSetExample.txt


Clean Set Block
---------------
The clean set block is the only block type inside the file. It contains all 
words or sentences to be cleaned.

Multiple clean set blocks can be defined. Each clean set block is defined by 
the **<CleanSet>** name.

Key names inside the clean set block can be anything, as long as the keys are 
unique for the block they are stored in.