Frank Eslami, cs362-400, Assignment 3
Code Coverage

unittest1.c - updateCoins()
===========================
Lines executed:100.00% of 35
Branches executed:100.00% of 16
Taken at least once:81.25% of 16
Calls executed:81.25% of 16

Overall, I believe good test coverage was done.


unittest2.c - gainCard()
========================
Lines executed:100.00% of 26
Branches executed:100.00% of 12
Taken at least once:100.00% of 12
Calls executed:100.00% of 8

Even though the test coverage was good statistically, I hardly scratched the surface
of truly covering the input domain. This was just a simple unit test on one small
part of the domain.


unittest3.c - isGameOver()
==========================
Lines executed:100.00% of 26
Branches executed:100.00% of 10
Taken at least once:70.00% of 10
Calls executed:75.00% of 12

I believe randomization of game states with many iterations would be a better 
reflection of test coverage here.


unittest4.c - getCost()
=======================
Lines executed:100.00% of 90
Branches executed:100.00% of 54
Taken at least once:50.00% of 54
Calls executed:75.68% of 111

This covrage can be better.


cardtest1.c - smithy card
=========================
Lines executed:100.00% of 14
No branches
Calls executed:100.00% of 6

The code needs to have branches, so iterations need to be implemented. Specifically,
random inputs.


cardtest2.c - adventurer card
=============================
Lines executed:100.00% of 16
No branches
Calls executed:100.00% of 7

Same as cardtest1. Need to implement loops with random inputs to test various
states.


cardtest3.c - village card
===========================
Lines executed:100.00% of 15
Branches executed:100.00% of 2
Taken at least once:50.00% of 2
Calls executed:85.71% of 7

More sub-unit tests should be implemented. What I mean is, the unit test is not
complete. Other input domains can be tested.


cardtest4.c - council_room card
===============================
Lines executed:100.00% of 19
Branches executed:100.00% of 4
Taken at least once:50.00% of 4
Calls executed:80.00% of 10

Same as cardtest 3, more sub-unit testing can definitely be performed.