Frank Eslami, CS 362-400
Assignment 4 Writeup
==========================

randomtestadventurer.c
=======================
Coverage results:
Lines executed:97.22% of 36
Branches executed:100.00% of 10
Taken at least once:80.00% of 10
Calls executed:93.33% of 15

Test Plan:
1. Tested 50,000 times with random generated treasure cards in deck
2. Upon game initialization, make player's 1st card an adventurer
3. Generate 2 random treasure cards and set them on top of the deck
4. Get coins sum for these 2 random treasure cards
5. Get coins sum before adventurer card is played
6. Play the adventurer card
7. Get coins sum after adventurer card is played
8. Coins sum after should have increased by coins sum before plus the deck's coins

In addition, the seed to initialize the game is randomely generated.

Future Improvements:
1. The test only runs with a single player. What if the test is done with two
players?

2. The test always places the adventurer card in the first position of the
player's hand. What if the card was placed randomely in other hand positions?

Overall, I believe the code coverage and results of this are good. This random test tested one
aspect of adventurer card's functionality. In the future, other random test should
be implemented to test other functionalities.


randomtestcard.c - Village Card
=============================== 
Lines executed:100.00% of 20
Branches executed:100.00% of 4
Taken at least once:75.00% of 4
Calls executed:91.67% of 12

Test Plan:
1. Tested 50,000 times with random generated game states
2. Upon game initialization, make player's 1st card village
3. Get numActions
4. Play village card
5. Get numActions, which should be increased by 2

Future Improvements:
1. As randomtestadventurer.c, the test only runs with a single player. What if the test is done with two players?

2. The test always places the adventurer card in the first position of the
player's hand. What if the card was placed randomely in other hand positions?

3. Further testing of the village card can be done by also checking that the number
of cards at hand is corret. For example, the village card itself is supposed to be 
discarded after it is used.

Overall, I believe the code coverage and results are good. The village card is relative
simple to test for.