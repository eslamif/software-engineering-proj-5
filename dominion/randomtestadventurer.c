//Frank Eslami, CS362-400, Assignment 4
//randomtestadventurer.c performs random testing on the adventurer card in dominion.c
//NOTE: for this test I had to fix the bug introduced to cardEffect()'s adventurer card in 
//assignment 2. Otherwise, the test would not run past cardEffect()'s call to adventuerer card

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

//Set NOISY_TEST to the following:
//0 = don't printf anything
//1 = printf minimally
//2 = printf everything 
#define NOISY_TEST 1

int main() {
        printf("\n======================================================\n");
		printf("Adventurer Card Random Testing\n");
        printf("======================================================\n");

	//Adventurer card functionality:
	//Reveal cards from player's deck until 2 treasure cards are revealed
	//Put those treasure cards in player's hand and discard the other revealed cards
	
#if (NOISY_TEST == 2)
	printf("Test Plan - 2 treasure cards from deck are placed in hand & score adjusted\n"
	"Testing 50,000 times with random generated treasure cards in deck\n"
	"Upon game initialization, make player's 1st card an adventurer\n"
	"Generate 2 random treasure cards and set them on top of the deck\n"
	"Get coins sum for these 2 random treasure cards\n"
	"Get coins sum before adventurer card is played\n"
	"Play the adventurer card\n"
	"Get coins sum after adventurer card is played\n"
	"Coins sum after should have increased by coins sum before plus the deck's coins\n");
#endif

	//Run program 50,000 times
	srand(time(NULL));	//random seed
	int testCounter, testCount = 50000;

#if (NOISY_TEST == 1)
		printf("Starting Test\n");
#endif
	for (testCounter = 0; testCounter < testCount; testCounter++) {
		//initializeGame() input variables
		int numPlayer = 2;
    	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    	struct gameState G;
		int seed = rand() % (1001 - 1) + 1;
		//Tracking variables
		int r;

		//Initialize game
    	memset(&G, 23, sizeof(struct gameState));   // clear the game state
    	r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

		G.hand[0][0] = adventurer;	//set first card of player 0 to adventurer
		updateCoins(0, &G, 0);		//update coins with adventurer taken into account	

		//Coin count before playing adventurer card
		int coins_before = G.coins;
#if (NOISY_TEST == 2)
		printf("\ncoins before adventurer card = %d\n", coins_before);
		for (i = 0; i < 5; i++) {
				printf("hand @ %d = %d\n", i, G.hand[0][i]);
		}
#endif
		//Set top 2 cards of deck to a random treasure card
		//Index of copper = 4, silver = 5, gold = 6 
		int randTreasure_1 = rand() % (6 - 4) + 4;
		int randTreasure_2 = rand() % (6 - 4) + 4;

#if (NOISY_TEST == 2)
		printf("treasure 1 = %d\n", randTreasure_1);
		printf("treasure 2 = %d\n", randTreasure_2);
#endif
		G.deck[0][G.deckCount[0] - 1] = randTreasure_1;	//set top deck card to treasure card
		G.deck[0][G.deckCount[0] - 2] = randTreasure_2;	//set second-to-top deck card to treasure card
		int topDeck[2];
		topDeck[0] = G.deck[0][G.deckCount[0] - 1];
		topDeck[1] = G.deck[0][G.deckCount[0] - 2];

		playCard(0, 0, 0, 0, &G);	//play 1st card of player 0, which is adventurer

		int coins_after = G.coins;	//coins after adventurer
#if (NOISY_TEST == 2)
		printf("coins after adventurer card = %d\n", coins_after);
		for (i = 0; i < 5; i++) {
				printf("hand @ %d = %d\n", i, G.hand[0][i]);
		}
#endif
		
		//Coins count after adventurer count
		//Count coins total from the top two treasure cards of the deck that were pulled by adventurer card
		int i, totalCoinsAfter = 0;
		for (i = 0; i < 2; i++) {
				if (topDeck[i] == 4) {
						totalCoinsAfter += 1;
//						printf(">>> 4\n");									
//						printf("%d\n", totalCoinsAfter);									
				}
				else if (topDeck[i] == 5) {
						totalCoinsAfter += 2;
//						printf(">>> 5\n");									
//						printf("%d\n", totalCoinsAfter);									
				}
				else {
						totalCoinsAfter += 3;
//						printf(">>> 6\n");									
//						printf("%d\n", totalCoinsAfter);									
				}
		}

		//Add before coins to coins added by adventurer card
		totalCoinsAfter += coins_before;

		//Assert if coins before and after match
#if (NOISY_TEST == 2) 
		printf("Total coins after adventurer card = %d, should be =%d\n", coins_after, totalCoinsAfter);
#endif
		assert(totalCoinsAfter == coins_after);	
	}

#if (NOISY_TEST == 1)
		printf("Test ran %d times\n", testCounter);
		printf("All tests passed!\n");
#endif

    return 0;
}
