//Frank Eslami, CS362-400, Assignment 3
//unittest1.c performs a unit test on function testUpdateCoins() in dominion.c
//Disclaimer: professor Christi's template from testUpdateCoins.c was used below

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
		printf("\n======================================================\n");
		printf("unittest1.c - testUpdateCoins()\n"); 
		printf("======================================================\n");
	srand(time(NULL));
    int i;
    int maxBonus = 10;
    int player, r, handCount;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;

    // arrays of all coppers, silvers, and golds
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];

    for (i = 0; i < MAX_HAND; i++)
    {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }

	//Run test 500 times
	int testRuns = 1, runCount;
	for (runCount = 0; runCount < testRuns; runCount++) {
	
		//Create random seed
		int seed = rand() % (5000 - 1) + 1;
	
		//Create random number of players between 2 - 5
//		int numPlayer = rand() % (6 - 2) + 2; 
		int numPlayer = 2;
		
	    printf ("TESTING updateCoins():\n");
	    for (player = 0; player < numPlayer; player++)
	    {
	        for (handCount = 1; handCount <= maxHandCount; handCount++)
	        {
	            for (bonus = 0; bonus <= maxBonus; bonus++)
	            {
	#if (NOISY_TEST == 1)
	                printf("Test player %d with %d treasure card(s) and %d bonus.\n", player, handCount, bonus);
	#endif
	                memset(&G, 23, sizeof(struct gameState));   // clear the game state
	                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
	                G.handCount[player] = handCount;                 // set the number of cards on hand
	                memcpy(G.hand[player], coppers, sizeof(int) * handCount); // set all the cards to copper
	                updateCoins(player, &G, bonus);
	#if (NOISY_TEST == 1)
	                printf("G.coins = %d, expected = %d\n", G.coins, handCount * 1 + bonus);
	#endif
	                assert(G.coins == handCount * 1 + bonus); // check if the number of coins is correct
	
	                memcpy(G.hand[player], silvers, sizeof(int) * handCount); // set all the cards to silver
	                updateCoins(player, &G, bonus);
	#if (NOISY_TEST == 1)
	                printf("G.coins = %d, expected = %d\n", G.coins, handCount * 2 + bonus);
	#endif
	                assert(G.coins == handCount * 2 + bonus); // check if the number of coins is correct
	
	                memcpy(G.hand[player], golds, sizeof(int) * handCount); // set all the cards to gold
	                updateCoins(player, &G, bonus);
	#if (NOISY_TEST == 1)
	                printf("G.coins = %d, expected = %d\n", G.coins, handCount * 3 + bonus);
	#endif
	                assert(G.coins == handCount * 3 + bonus); // check if the number of coins is correct
	            }
	        }
	    }
	}	
	    printf("All tests passed!\n");

    return 0;
}
