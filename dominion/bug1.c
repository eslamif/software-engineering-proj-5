Frank Eslami, cs362-400, Assignment 3
Bug Report

unittest1.c - updateCoins()
===========================
When the number players = 4, treasure cards = 5 and bonus = 0, the following assertion is triggered:
unittest1: unittest1.c:68: main: Assertion `G.coins == handCount * 1 + bonus' failed.
Abort (core dumped)

unittest2.c - gainCard()
========================
All assertions failed for toFlag = 1, 2, and 3. I commented out the assertions
in order to continue to process the remaining code. Problem: deckCount, handCount,
and discardCount are not being incremented properly.

unittest3.c - isGameOver()
==========================
All tests passed for the following cases:
province was empty
Any supply pile = 0
Any supply pile > 0

unittest4.c - getCost()
=======================
All tests passed for every card

cardtest1.c - smithy card
=========================
Test fails when playing the smithy card. The handCount is not increased by 3 cards and
then reduced by 1 to get rid of the smithy card.

cardtest2.c - adventurer card
=============================
I ran into a problem on line 53 of the code. cardEffect will not process the 
adventurer card. Therefore, further testing was not able to be done. However, my 
test plan was noted in the code on lines 38 - 44.

cardtest3.c - village card
===========================
All tests passed successfully

cardtest4.c - council_room card
===============================
All tests passed successfully