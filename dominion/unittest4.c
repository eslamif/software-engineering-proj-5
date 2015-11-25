//Frank Eslami, CS362-400, Assignment 3
//unittest4.c performs a unit test on function getCost() in dominion.c
//Disclaimer: professor Christi's template from testUpdateCoins.c was used below

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
        printf("unittest4 - getCost()\n");
        printf("======================================================\n");

	//initializeGame() input variables
	int numPlayer = 2;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	int seed = 1000;	
    struct gameState G;

	//Tracking variables
	int testR, r;

    printf ("UNIT TESTING STARTED FOR getCost()\n");

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

	//Test each card according to its cost
	testR = getCost(0);
#if (NOISY_TEST == 1)
	printf("Curse cost = %d, expected 0\n", testR);
#endif
	assert(getCost(0) == 0);
		
	testR = getCost(1);
#if (NOISY_TEST == 1)
	printf("Estate cost = %d, expected 1\n", testR);
#endif
	assert(getCost(1) == 2);

	testR = getCost(2);
#if (NOISY_TEST == 1)
	printf("Duchy cost = %d, expected 5\n", testR);
#endif
	assert(getCost(2) == 5);

	testR = getCost(3);
#if (NOISY_TEST == 1)
	printf("Province cost = %d, expected 8\n", testR);
#endif
	assert(getCost(3) == 8);

	testR = getCost(4);
#if (NOISY_TEST == 1)
	printf("Copper cost = %d, expected 0\n", testR);
#endif
	assert(getCost(4) == 0);

	testR = getCost(5); 
#if (NOISY_TEST == 1)
	printf("Silver cost = %d, expected 3\n", testR);
#endif
	assert(getCost(5) == 3);

	testR = getCost(6);
#if (NOISY_TEST == 1)
	printf("Gold cost = %d, expected 6\n", testR);
#endif
	assert(getCost(6) == 6);

	testR = getCost(7);
#if (NOISY_TEST == 1)
	printf("Adventurer cost = %d, expected 6\n", testR);
#endif
	assert(getCost(7) == 6);

	testR = getCost(8);
#if (NOISY_TEST == 1)
	printf("Council_room cost = %d, expected 5\n", testR);
#endif
	assert(getCost(8) == 5);

	testR = getCost(9); 
#if (NOISY_TEST == 1)
	printf("Feast cost = %d, expected 4\n", testR);
#endif
	assert(getCost(9) == 4);

	testR = getCost(10);
#if (NOISY_TEST == 1)
	printf("Gardens cost = %d, expected 4\n", testR);
#endif
	assert(getCost(10) == 4);

	testR = getCost(11);
#if (NOISY_TEST == 1)
	printf("Mine cost = %d, expected 5\n", testR);
#endif
	assert(getCost(11) == 5);

	testR = getCost(12);
#if (NOISY_TEST == 1)
	printf("Remodel cost = %d, expected 4\n", testR);
#endif
	assert(getCost(12) == 4);

	testR = getCost(13);
#if (NOISY_TEST == 1)
	printf("Smithy cost = %d, expected 4\n", testR);
#endif
	assert(getCost(13) == 4);

	testR = getCost(14); 
#if (NOISY_TEST == 1)
	printf("Village cost = %d, expected 3\n", testR);
#endif
	assert(getCost(14) == 3);

	testR = getCost(15);
#if (NOISY_TEST == 1)
	printf("Baron cost = %d, expected 4\n", testR);
#endif
	assert(getCost(15) == 4);

	testR = getCost(16);
#if (NOISY_TEST == 1)
	printf("Great_hall cost = %d, expected 3\n", testR);
#endif
	assert(getCost(16) == 3);

	testR = getCost(17);
#if (NOISY_TEST == 1)
	printf("Minion cost = %d, expected 5\n", testR);
#endif
	assert(getCost(17) == 5);

	testR = getCost(18);
#if (NOISY_TEST == 1)
	printf("Steward cost = %d, expected 3\n", testR);
#endif
	assert(getCost(18) == 3);

	testR = getCost(19); 
#if (NOISY_TEST == 1)
	printf("Tribute cost = %d, expected 5\n", testR);
#endif
	assert(getCost(19) == 5);

	testR = getCost(20);
#if (NOISY_TEST == 1)
	printf("Ambassador cost = %d, expected 3\n", testR);
#endif
	assert(getCost(20) == 3);

	testR = getCost(21);
#if (NOISY_TEST == 1)
	printf("Cutpurse cost = %d, expected 4\n", testR);
#endif
	assert(getCost(21) == 4);

	testR = getCost(22);
#if (NOISY_TEST == 1)
	printf("Embargo cost = %d, expected 2\n", testR);
#endif
	assert(getCost(22) == 2);

	testR = getCost(23);
#if (NOISY_TEST == 1)
	printf("Outpost cost = %d, expected 5\n", testR);
#endif
	assert(getCost(23) == 5);

	testR = getCost(24); 
#if (NOISY_TEST == 1)
	printf("Salvager cost = %d, expected 4\n", testR);
#endif
	assert(getCost(24) == 4);

	testR = getCost(25);
#if (NOISY_TEST == 1)
	printf("sea_hag = %d, expected 4\n", testR);
#endif
	assert(getCost(25) == 4);

	testR = getCost(26);
#if (NOISY_TEST == 1)
	printf("Treasure_map cost = %d, expected 4\n", testR);
#endif
	assert(getCost(26) == 4);


printf("All tests passed!\n");
//    printf("Some tests failed! Assertions were commented out to continue to process the code\n");

    return 0;
}
