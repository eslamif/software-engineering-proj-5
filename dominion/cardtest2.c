//Frank Eslami, CS362-400, Assignment 3
//cardtest2.c performs a unit test on the adventurer card in dominion.c

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
#define NOISY_TEST 1

int main() {
        printf("\n======================================================\n");
		printf("cardtest2 - adventurer card\n");
        printf("======================================================\n");

	//initializeGame() input variables
	int numPlayer = 2;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	int seed = 1000;	
    struct gameState G;

	//Tracking variables
	int r;

    printf ("UNIT TESTING STARTED FOR THE SMITH CARD()\n");

	//Initialize game
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

	//Adventurer card functionality:
	//Reveal cards from player's deck until 2 treasure cards are revealed
	//Put those treasure cards in player's hand and discard the other revealed cards
	
	//Test plan:
	//Upon game initialization, make player's 1st card an adventurer
	//Make the 1st and 2nd cards in the deck copper treasure cards
	//Get scoreFor()
	//Play the adventurer card
	//Get scoreFor()
	//scoreFor() should have increased by 2 copper cards

	G.hand[0][0] = adventurer; //replace player 0's 1st card with adventurer
	int deckCounter = G.deckCount[0];	//number of cards in deck
	G.deck[0][deckCounter - 1] = copper;
	int score = scoreFor(0, &G);
#if (NOISY_TEST == 1)
	printf("score before adventurer = %d\n", score);
#endif
//	cardEffect(adventurer, 0, 0, 0, &G, 0, 0);	//program doesn't run past this
// <------------ CAN'T GET PAST THIS POING. cardEffect is not processing
	score = scoreFor(0, &G);
#if (NOISY_TEST == 1)
	printf("score after adventurer = %d\n", score);
#endif
	

	//printf("All tests passed!\n");
    printf("Some tests failed! Assertions were commented out to continue to process the code\n");

    return 0;
}
