//Frank Eslami, CS362-400, Assignment 3
//unittest2.c performs a unit test on function gainCard() in dominion.c
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
        printf("unittest2.c - gainCard()\n");
        printf("======================================================\n");
	//initializeGame() input variables
	int numPlayer = 2;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	int seed = 1000;	
    struct gameState G;

	//gainCard(supplyPos, gameState, toFlag, player) input variables
	int supplyPos;  //enumerated card
	int toFlag; //where to put the card (player's hand, deck, or trash)
	int player; //who to give card to	

	//Tracking variables
	int handCount, deckCount, discardCount, supplyCount;
	int r, testR;

    printf ("UNIT TESTING STARTED FOR gainCard()\n");
    for (player = 0; player < numPlayer; player++) {	//which player's turn
		for (toFlag = 1; toFlag <= 3; toFlag++) {
			for (supplyPos = 0; supplyPos < 26; supplyPos++) {
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
			
				//Store number of cards in each pile
				handCount = G.handCount[player];	
				deckCount = G.deckCount[player];	
				discardCount = G.discardCount[player];	
				supplyCount = G.supplyCount[player];

#if (NOISY_TEST == 2)
				printf("Testing player %d, toFlag %d, supplyPos %d\n", player, toFlag, supplyPos);
#endif
				//Test empty supply pile
				G.supplyCount[player] = 0;
				testR = gainCard(supplyPos, &G, toFlag, player);
//				assert(testR == -1);	//fails
				G.supplyCount[player] = supplyCount;	//restore count

				testR = gainCard(supplyPos, &G, toFlag, player);

				//Test toFlag = 1 
				if (toFlag == 1) {
#if (NOISY_TEST == 1)
					printf("deckCount = %d, expected %d\n", G.deckCount[player], deckCount + 1);
#endif
//					assert( (deckCount + 1) == G.deckCount[player]); //fails
				}

				//Test toFlag = 2
				if (toFlag == 2) {
#if (NOISY_TEST == 1)
					printf("handCount = %d, expected %d\n", G.handCount[player], handCount + 1);
#endif
//					assert( (handCount + 1) == G.handCount[player]); //fails
				}

				//Test toFlag = 3
				if (toFlag == 3) {
#if (NOISY_TEST == 1)
					printf("discardCount = %d, expected %d\n", G.discardCount[player], discardCount + 1);
#endif
//					assert( (discardCount + 1) == G.discardCount[player]); //fails
				}

			} //end supplyPos loop
		} //end toFlag loop
	} //end player loop

    //printf("All tests passed!\n");
    printf("Some tests failed! Assertions were commented out to continue to process the code\n");

    return 0;
}
