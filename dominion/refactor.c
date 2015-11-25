Frank Eslami, CS362-400, Assignment 2 - refactor.txt
The following 5 cards were refactored with bugs included
========================================================

aventurer card (line 652)
========================
The refactored function is called adventurer_refactor. 
Bugs introduced:

When the switch statement in cardEffect() calls adventurer_refactor, the return value is compared to a 1, which is incorrect. The return value should be compared to a 0, which would indicate the function wasfg successful. Therefore, the program terminates if the function was successful.


smithy card (line 679)
======================
The refactored function is called smithy_refactor. 
Bugs introduced:

The for-loop starts with i = 1 instead of 0. Therefore, only 2 cards are drawn instead of 3.


council_room card (line 693)
============================
The refactored function is called council_room_refactor. 
Bugs introduced:

The number of buys is set to 1 instead of being incremented by 1.


remodel card (line 720)
=======================
The refactored function is called remodel_refactor. 
Bugs introduced:

When remodel_refactor is called, the order of choice1 and choice2 arguments are reversed. choice2 is being passed first, but it should be choice1.


gardens card (line 748)
=======================
The refactored function is called gardens_refactor. 
Bugs introduced:

Instead of return -1, a 1 is returned.
