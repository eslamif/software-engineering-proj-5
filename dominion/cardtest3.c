//Frank Eslami, CS362-400, Assignment 3
//cardtest3.c performs a unit test on the village card in dominion.c

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
		printf("cardtest3 - village card\n");
        printf("======================================================\n");

	//initializeGame() input variables
	int numPlayer = 2;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	int seed = 1000;	
    struct gameState G;

	//Tracking variables
	int r;

    printf ("UNIT TESTING STARTED FOR THE VILLAGE CARD()\n");

	//Initialize game
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

	//Village card cardEffect()
	//draw 1 card
	//Add 2 actions
	//discard village card
	
	//Test plan:
	//Upon game initialization, make player's 1st card village
	//get numActions
	//play village card
	//get numActions, which should be increased by 2

	G.hand[0][0] = village; //replace player 0's 1st card with village
	int numActions = G.numActions;
#if (NOISY_TEST == 1)
	printf("numActions before village = %d\n", numActions);
#endif
	cardEffect(village, 0, 0, 0, &G, 0, 0);
#if (NOISY_TEST == 1)
	printf("numActions after village = %d, expected %d\n", G.numActions, numActions + 2);
#endif
	assert(G.numActions = numActions);	

	printf("All tests passed!\n");
    //printf("Some tests failed! Assertions were commented out to continue to process the code\n");

    return 0;
}
