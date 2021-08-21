Output Generator Files
======================
Output generator files allow for a more varied output to the user by generating 
for randomized sentences filled with randomized words from word groups.

All output generator files are simple text files with a **.mrhog** file 
ending. These files are simple MRH block files with a special extension. As 
such, all block file rules apply.

A sentence will always be chosen from a output file, event if no sentence has 
a 100% chance to be picked. The same is also true for words. The percentage 
chance is used to make certain combinations appear more often.

Example File
------------
The following example file shows a simple output file containing multiple 
combinations to express the want for food:

.. literalinclude:: OutputExample.txt


Sentence Block
--------------
The sentence blocks define a sentence string, its use chance and the possible 
placements from word groups found in the sentence string.

Multiple sentence blocks can be defined. Each sentence block is defined by the 
**<Sentence>** name.

**<String>**: The string with (or without) placement variables.

**<Chance>**: The use chance for the sentence. This value will be interpreted as 
a 64-bit floating point number.

Sentence Placement Block
------------------------
Sentence placement blocks are used to assign word groups to defined placement 
strings found inside the sentence strings.

Multiple placement blocks can be defined. Each placement block is defined by 
the **<Placement>** name. These placement block will be applied to any chosen 
sentence.

**<String>**: The identification string to replace found in the sentence base 
string.

**<GroupID>**: The group id where the replacement word will be grabbed from. 
This value will be interpreted as a unsigned 32-bit integer.

Word Block
----------
Word blocks contain the word string to use as well as their chance.

Multiple word blocks can be defined. Each word block is defined by the **<Word>** 
name. The defined word group will then be used to group these words together be 
be used in sentence placements. A word block can only belong to one word group.

**<String>**: The string for the word.

**Chance**: The chance for the word to be placed. This value will be interpreted as 
a 64-bit floating point number.

**<WordGroup>**: The word group this word belongs to. This value will be interpreted 
as a unsigned 32-bit integer.