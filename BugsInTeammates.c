======================================================
Bug 1 Kenny Lu - Adventurer Card Random Testing
======================================================
Bug ID: Lu_1
Bug Title: Adventurer card provides incorrect coins after call
Test Plan - 2 treasure cards from deck are placed in hand & score adjusted
Testing 50,000 times with random generated treasure cards in deck
Upon game initialization, make player's 1st card an adventurer
Generate 2 random treasure cards and set them on top of the deck
Get coins sum for these 2 random treasure cards
Get coins sum before adventurer card is played
Play the adventurer card
Get coins sum after adventurer card is played
Coins sum after should have increased by coins sum before plus the deck's
coins
Starting Test

Treasure card index: copper = 4, silver = 5, gold = 6

coins before adventurer card = 3
hand @ 0 = 7
hand @ 1 = 4
hand @ 2 = 4
hand @ 3 = 4
hand @ 4 = 1
treasure 1 = 5
treasure 2 = 4
coins after adventurer card = 7
hand @ 0 = 7
hand @ 1 = 4
hand @ 2 = 4
hand @ 3 = 4
hand @ 4 = 1
Total coins after adventurer card = 7, should be =6
randomtestadventurer: randomtestadventurer.c:127: main: Assertion
`totalCoinsAfter == coins_after' failed.
Abort (core dumped)
flip2 ~/cs362/assignment_5/eslamif/lukenDomion/dominion 435%


======================================================
Bug 2 Robert Ottolia - Adventurer Card Random Testing
======================================================
Bug ID: Otollia_1
Bug Title: Adventurer card provides incorrect coins after call
Test Plan - 2 treasure cards from deck are placed in hand & score adjusted
Testing 50,000 times with random generated treasure cards in deck
Upon game initialization, make player's 1st card an adventurer
Generate 2 random treasure cards and set them on top of the deck
Get coins sum for these 2 random treasure cards
Get coins sum before adventurer card is played
Play the adventurer card
Get coins sum after adventurer card is played
Coins sum after should have increased by coins sum before plus the deck's
coins
Starting Test

Treasure card index: copper = 4, silver = 5, gold = 6

coins before adventurer card = 3
hand @ 0 = 7
hand @ 1 = 4
hand @ 2 = 1
hand @ 3 = 4
hand @ 4 = 4
treasure 1 = 4
treasure 2 = 5
PRINTING FROM INSIDE discardCard() FUNCTION IN DOMINION.C
IF SEGFAULT AFTER THIS WITH DEBUG2 NOT PRINTED, BUG IS IN STATEMENT:
if (trashFlag<1) {...}; BUG WHEN TRASHFLAG == 0
DEBUG2
coins after adventurer card = 8
hand @ 0 = 1
hand @ 1 = 4
hand @ 2 = 1
hand @ 3 = 4
hand @ 4 = 4
Total coins after adventurer card = 8, should be =6
randomtestadventurer: randomtestadventurer.c:127: main: Assertion
`totalCoinsAfter == coins_after' failed.
Abort (core dumped)
flip3 ~/cs362/assignment_5/eslamif/ottoliarDominion/dominion 168%
