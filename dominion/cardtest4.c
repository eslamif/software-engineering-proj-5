//Frank Eslami, CS362-400, Assignment 3
//cardtest4.c performs a unit test on the council_room card in dominion.c

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
		printf("cardtest4 - council_room card\n");
        printf("======================================================\n");

	//initializeGame() input variables
	int numPlayer = 2;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	int seed = 1000;	
    struct gameState G;

	//Tracking variables
	int r;

    printf ("UNIT TESTING STARTED FOR THE COUNCIL_ROOM CARD()\n");

	//Initialize game
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

	G.hand[0][0] = council_room; //replace player 0's 1st card with council_room
	int numCards0 = G.handCount[0];	//number of cards for player 1
	int numCards1 = G.handCount[1];	//number of cards for player 2
	cardEffect(council_room, 0, 0, 0, &G, 0, 0);

	//Player 1 before and after
#if (NOISY_TEST == 1)
	printf("Player 1: numCards before council_room = %d\n", numCards0);
#endif
#if (NOISY_TEST == 1)
	printf("Player 1: numCards after council_room = %d, expected = %d\n", G.handCount[0], numCards0 + 3);
#endif
	assert(G.handCount[0] == numCards0 + 3);

	//Player 2 before and after
#if (NOISY_TEST == 1)
	printf("Player 2: numCards before council_room = %d\n", numCards1);
#endif
#if (NOISY_TEST == 1)
	printf("Player 2: numCards after council_room = %d, expected = %d\n", G.handCount[1], numCards1 + 1);
#endif
	assert(G.handCount[1] == numCards1 + 1);

	printf("All tests passed!\n");
    //printf("Some tests failed! Assertions were commented out to continue to process the code\n");

    return 0;
}
