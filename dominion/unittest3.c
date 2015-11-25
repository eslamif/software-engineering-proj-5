//Frank Eslami, CS362-400, Assignment 3
//unittest3.c performs a unit test on function isGameOver() in dominion.c
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
        printf("unittest3 - isGameOver()\n");
        printf("======================================================\n");

	//initializeGame() input variables
	int numPlayer = 2;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	int seed = 1000;	
    struct gameState G;

	//Tracking variables
	int provinceCount, testR, r;

    printf ("UNIT TESTING STARTED FOR isGameOver()\n");

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
	provinceCount = G.supplyCount[province];

	//Store number of cards in each pile
	provinceCount = G.supplyCount[province];

	//Test when province pile is empty
	G.supplyCount[province] = 0;
	testR = isGameOver(&G);
#if (NOISY_TEST == 1)
				printf("Province is empty: testR = %d, expected 1\n", testR);
#endif
	assert(testR == 1);
	G.supplyCount[province] = provinceCount; //reset count
	
	//Test when supply piles are > 0
	int i;
	for (i = 0; i < 25; i++) {
		G.supplyCount[i] = 1;
	}	

	testR = isGameOver(&G);
#if (NOISY_TEST == 1)
				printf("Supply piles > 0: testR = %d, expected 0\n", testR);
#endif
	assert(testR == 0);

	//Test when supply piles are = 0
	for (i = 0; i < 25; i++) {
		G.supplyCount[i] = 0;
	}	

	testR = isGameOver(&G);
#if (NOISY_TEST == 1)
				printf("Supply piles = 0: testR = %d, expected 1\n", testR);
#endif
	assert(testR == 1);


printf("All tests passed!\n");
//    printf("Some tests failed! Assertions were commented out to continue to process the code\n");

    return 0;
}
