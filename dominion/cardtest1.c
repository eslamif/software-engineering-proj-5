//Frank Eslami, CS362-400, Assignment 3
//cardtest1.c performs a unit test on the smithy card in dominion.c
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
        printf("cardtest1 - smithy card\n");
        printf("======================================================\n");

	//initializeGame() input variables
	int numPlayer = 2;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	int seed = 1000;	
    struct gameState G;

	//Tracking variables
	int testR, r;
	int handCount;

    printf ("UNIT TESTING STARTED FOR THE SMITH CARD()\n");

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

	handCount = G.handCount[0];	//handcount before smithy play
	G.hand[0][0] = smithy; //replace player 0's 1st card with smithy
#if (NOISY_TEST == 1)
	printf("handcount before smith = %d\n", G.handCount[0]);	
#endif
	cardEffect(smithy, 0, 0, 0, &G, 0, 0);	//play the smithy card
#if (NOISY_TEST == 1)
	printf("handcount after smithy = %d, expected 7 (+3 draw & -1 to remove smithy)\n", G.handCount[0]);	
#endif
//	assert(G.handCount[0] == (handCount + 2) ); //assertion fails

	//printf("All tests passed!\n");
    printf("Some tests failed! Assertions were commented out to continue to process the code\n");

    return 0;
}
