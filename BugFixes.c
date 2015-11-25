Frank Eslami, cs362, Assignment 5

========================================
BUGS FIXED THAT WERE FOUND BY TEAM MATES
========================================

Bug 1- found by Kenny Lu
=========================
The first bug found by my cardtest1 test which looks at the smithy function of the code. The output of the test was the following:

INITIALIZING GAME...
PLAYING SMITHY...
NUMBER OF CARDS IN HAND BEFORE SMTHY: 5
NUMBER OF CARDS EXPECTED AFTER PLAYING SMTHY: 7
ACTUAL NUMBER OF CARDS: 6
There was an error with number of cards drawn for smithy card.

END OF SMTHY CARD TEST...

According to this test, there seems to be a bug with how many cards are drawn. Only 2 cards are drawn from the deck instead of the expected 3.


Bug 1 fixed as follows
=======================
The bug was found and fixed in the smithy_refactor function. The for-loop which is supposed to add 3 cards has i = 1 until i < 3. Therefore, only 2 cards are drawn instead of 3. I fixed this by setting i = 0.


Bug 2- found by Robert Ottolia
==============================
Bug Number: D1
Title: Smithy gives incorrect amount of cards
Steps to reproduce:
-Save handcount of current player before calling Smithy()
-Call smithy with current gameState
-Compare handcount after with the saved handcount.
Estimated Severity / Priority: High
Description:

Testing Franks 'Smithy' function with my 'cardtest1.c' (testing Smithy).
On first execution, my assertion that the gameState's handcount
after calling smithy on it is equal gameState's prehandcount + 2 after calling
smithy on it fails.  This means that somewhere in Frank's dominion source
code it is not drawing the right amount of cards as it should.

flip3 ~/ecampus/teammate1Dominion 22% ./cardtest1
Card Test 1: Testing Smithy
cardtest1: cardtest1.c:50: testSmithy: Assertion `after->handCount[currentPlayer] == handCountSaved + 2' failed.
Abort (core dumped)


Bug 2 fixed as follows
=======================
Bug 2 had the same issue as bug 1, where only 2 cards were drawn instead of 3. Therefore, by fixing bug 1, bug 2 was also fixed.


Bug 3- found by Kenny Lu
=========================
The second bug found by my cardtest4 test which tests the adventurer card. The output of the test looked like this:

TEST FOR ADVENTURER CARD

INITIALIZING GAME...
DECK HAS TREASURE ONLY SO 2 CARDS SHOULD BE DRAWN...

My test seemed to have terminated before being able to draw cards looking for treasure. Since my test calls the cardeffect function instead of the adventurer function directly, there could be a bug within either the two functions that causes the program to end abruptly before being able to do anything.


Bug 3 fixed as follows
=======================
The bug was found and fixed in the cardEffect() function. When the switch statement in cardEffect() calls adventurer_refactor, the return value is compared to a 1, which is incorrect. This indicates that even when the function ran successfully, it return that it didn't run successfully, therefore, terminating the function. That is why Kenny's test kept aborting at this point. 

The return value in the call in the switch statement should be compared to a 0, which would indicate the function was successful. 


Bug 4- found by Robert Ottolia
==============================
Bug Number: D2
Title: Premature crash upon playing Adventurer() card.
Steps to reproduce:
-Call adventurer on current gameState
-Repeat until program terminates early (seems to involve some sort
	of randomness)
Estimated Priority / Severity: very high
Description:

Testing Frank's adventurer card with my 'cardtest3.c' (testing Adventurer).
On first execution of my test on Frank's dominion.c file this was the output:

flip3 ~/ecampus/teammate1Dominion 26% ./cardtest3
Card Test 3: Testing Adventurer
HAND COUNT BEFORE ADVENTURER: 5
flip3 ~/ecampus/teammate1Dominion 27% 

The program terminated abruptly without printing anymore statements from my cardtest.
Looking at my cardtest, there are two more print statements along with two assertions
later on in the code.  Not a single one of these printed, so it is easy to see that there is a bug(s)
in Frank's dominion.c file that is causing premature termination of the program.


Bug 4 fixed as follows
=======================
Bug 4 was fixed by fixing bug 3. The reason Robert's code terminated prematurely was because the return value of adventurer_refactor returned false, even when the function ran successfully.



============================================
BUGS FIXED THAT I INTRODUCED IN ASSIGNMENT 2
============================================

adventurer_refactor
====================
Bug introduced: when the switch statement in cardEffect() calls adventurer_refactor, the return value is compared to a 1, which is incorrect. The return value should be compared to a 0, which would indicate the function wasfg successful. Therefore, the program terminates if the function was successful.

Bug fixed: the return value of the switch statement in cardEffect() call to adventurer_refactor was correctly compared to 0 when the function returned successfully, instead of 1.


smithy_refactor
===============
Bug introduced: when the switch statement in cardEffect() calls adventurer_refactor, the return value is compared to a 1, which is incorrect. The return value should be compared to a 0, which would indicate the function wasfg successful. Therefore, the program terminates if the function was successful.

Bug fixed: I change i = 1 to i = 0, which iterated through 3 cards correctly.


council_room_refactor
======================
Bug introduced: the number of buys is set to 1 instead of being incremented by 1.

Bug fixed: increment state->numBuys by 1 instead of setting it to 1.


remodel_refactor
================
Bug introduced: when remodel_refactor is called, the order of choice1 and choice2 arguments are reversed. choice2 is being passed first, but it should be choice1.

Bug fixed: reversed the arguments of remodel_refactor on line 879 to have choice 1 come before choice 2.


gardens_refactor
================
Bug introduced: instead of returning -1, a 1 is returned.

Bug fixed: gardens_refactor now returns a -1 instead of a 1.

