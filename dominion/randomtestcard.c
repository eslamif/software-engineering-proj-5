//Frank Eslami, CS362-400, Assignment 4
//randomtestcard.c performs random testing on the village card in dominion.c

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
		printf("Village Card Random Testing\n");
        printf("======================================================\n");

	//Village card functionality:
	//draw 1 card
	//Add 2 actions
	//discard village card
	
#if (NOISY_TEST == 2)
	printf("Test Plan\n" 
	"Testing 50,000 times with random generated game states\n"
	"Upon game initialization, make player's 1st card village\n"
	"get numActions\n"
	"play village card\n"
	"get numActions, which should be increased by 2\n");
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

	    G.hand[0][0] = village; //replace player 0's 1st card with village
	    int numActions = G.numActions;
	#if (NOISY_TEST == 2)
	    printf("numActions before village = %d\n", numActions);
	#endif

	    cardEffect(village, 0, 0, 0, &G, 0, 0);

	#if (NOISY_TEST == 2)
	    printf("numActions after village = %d, expected %d\n", G.numActions, numActions + 2);
	#endif

	    assert(G.numActions == numActions + 2);

	}	//end testCounter for-loop

#if (NOISY_TEST == 1)
		printf("Test ran %d times\n", testCounter);
		printf("All tests passed!\n");
#endif

    return 0;
}
