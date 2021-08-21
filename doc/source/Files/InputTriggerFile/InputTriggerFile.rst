Input Trigger Files
===================
Input trigger files are used to specify triggers contained in voice input. 
These triggers contain weights and values to specify actions which should be 
taken by the application providing the input trigger files.

All trigger files are simple text files with a **.mrhit** file ending. 
These files are simple MRH block files with a special extension. As 
such, all block file rules apply.

Triggers are used to broadly determine that a action can be used by checking their
given value.

Example File
------------
The following example file shows a simple trigger file which is used to 
specify information gathering.

.. literalinclude:: InputExample.txt


Compare Method Block
--------------------
The compare method block defines information about the comparison method used 
for the triggers listed.

The compare method block is defined by the **<CompareMethod>** name and should 
only be included once. Further blocks will replace the ones before it.

**<Identifier>**: The type of comparison method used, relates to 
:doc:`../../Enumerations/libmrhvt_Directory/Input/MRH_InputTrigger/TriggerCompareMethod`.

**<LS_Similarity>**: The required similarity in percent for a trigger to be 
recognized when using the Levenshtein comparison method.

Trigger Block
-------------
The trigger block lists all possible trigger matches, which are used to find a 
specific action to take with the help of trigger values.

Multiple trigger blocks can be defined. Each trigger block is defined by 
the **<Trigger>** name.

**<String>**: The identification string of a trigger. Input will be matched to 
the given string with the chosen comparison method.
This value is case-sensitive! Using upper and lowercase values can have an 
impact on accuracy.

**<Weight>**: The weight applied to a specific trigger is added to a total of 
all the triggers which had matches found. This value is used reduce accidental 
matches. This value will be interpreted as a unsigned 32-bit integer.

**<Value>**: Trigger values should be used to assign actions. Values can be 
chosen at will, however every value < 0 will be interpreted as invalid. 
The values should be matched to actions available to a user program.
matches. This value will be interpreted as a signed 32-bit integer.