Frank Eslami, CS 362-400, Assignment 2

documentation.txt

======================================

General Mechanics
=================
The number of cards in a player's hand are denoted by positive integers starting from 0, tracked by variable i.

When the game starts, the initializeGame() function creates starting hands for all players.

At the start of a player's round, the player's cards at hand are iterated to sum the coins and store the hand position number of the smithy and adventurer cards.


smithy card
===========
At the start of a player's round, before a player plays its turn, the player's cards at hand are iterated through. Iterations are tracked with variable i.

If a smithy card is encountered, the variable smithyPos is set to i, which denotes the card position of smithy card in the player's hand.

smithyPos is initially set to -1, indicating it's not part of a player's hand, since cards in a player's hand can only be positive integers.

When its time for the player to play its turn, if smithPos != -1, smithy card is played by calling the function playCard().

A message is printed to the screen showing the player who played the smithy card and from what hand position.

If smithPos == -1, then no smithy card is in the player's hand and the round continues without a smithy card played by the current player.


adventurer card
===============
• At the start of a player's round, before a player plays its turn, the player's cards at hand are iterated through. Iterations are tracked with variable i.

• If a adventurer card is encountered, the variable adventurerPos is set to i, which denotes the card position of adventurer card in the player's hand.

• When its time for the player to play its turn, if adventurerPos != -1, adventurer card is played by calling the function playCard().

• A message is printed to the screen showing the player who played the adventurer card and from what hand position.

• If adventurerPos == -1, then no adventurer card is in the player's hand and the round continues without a adventurer card played by the current player.


discardCard() - in dominion.c
=============================
• Put played card in played card pile
• If card is not trashed, add card to Played pile
• Set played card to -1
• Remove card from player's hand
   • If last card in hand array is played, reduce number of cards in hand.
   • Else if only one card in hand, reduce number of cards in hand.
   • Else, replace discarded card with last card in hand.
      • Set last card to -1.
      • Reduce number of cards in hand.
    

updateCoins() - in dominion.c
=============================
• The updateCoins() function counts the number of coins a player has for its current turn as follows:
• Reset the player's coins
• Add the coins of each treasure card at hand.
• Include bonuses