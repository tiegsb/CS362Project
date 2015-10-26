/* Name: Kathryn McDonald
 * Class: CS 362
 * File name: unittest1.c
 * Purpose: Tests the "updateCoins" function in dominion.c */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h>

// to remove printfs, set PRINT_TEST to 0
#define PRINT_TEST 1

// to enable asserts, set ENABLE_ASSERTS to 1
#define ENABLE_ASSERTS 0

int main() {
 
  /* set up game state */
  int i;
  int seed = 1000;
  int numPlayer = 2;
  int maxBonus = 10;
  int p, r, handCount;
  int bonus;
  int k[10] = {adventurer, council_room, feast, gardens, mine, 
    remodel, smithy, village, baron, great_hall};
  struct gameState G;
  int maxHandCount = 5;
  
  /* set up coins */
  int coppers[MAX_HAND];
  int silvers[MAX_HAND];
  int golds[MAX_HAND];
  for (i = 0; i < MAX_HAND; i++) {
    coppers[i] = copper;
    silvers[i] = silver;
    golds[i] = gold;
  }
  
  /* define duchy */
   int duchies[MAX_HAND];
   for (i = 0; i < MAX_HAND; i++) {
    duchies[i] = duchy;
   }
  
  printf("Setup complete.\n");
  
  /* test */
  printf("Testing updateCoins()...\n");
  for (p = 0; p < numPlayer; p++) {
    for (handCount = 1; handCount <= maxHandCount; handCount++) {
     for (bonus = 0; bonus <= maxBonus; bonus++) {
#if (PRINT_TEST == 1)
       printf("Test player %d with %d card(s) and %d bonus.\n", p, handCount, bonus);
#endif
       memset(&G, 23, sizeof(struct gameState)); // clear game state
       r = initializeGame(numPlayer, k, seed, &G); // initialize new game
       G.handCount[p] = handCount; // set number of cards in hand
       
       /* set all cards to copper */
       memcpy(G.hand[p], coppers, sizeof(int) * handCount);
       updateCoins(p, &G, bonus);
#if (PRINT_TEST == 1)
       printf("Treasure Cards: %d\nG.coins = %d, expected = %d\n", handCount, G.coins, handCount * 1 + bonus);
       if (G.coins == handCount * 1 + bonus)
	 printf("Pass!\n");
       else
	 printf("Fail!\n");
#endif
       /* check that number of coins is correct */
#if (ENABLE_ASSERTS == 1)
       assert(G.coins == handCount * 1 + bonus);
#endif
       
       /* set all cards to silver */
       memcpy(G.hand[p], silvers, sizeof(int) * handCount);
       updateCoins(p, &G, bonus);
#if (PRINT_TEST == 1)
       printf("Treasure Cards: %d\nG.coins = %d, expected = %d\n", handCount, G.coins, handCount * 2 + bonus);
       if (G.coins == handCount * 2 + bonus)
	 printf("Pass!\n");
       else
	 printf("Fail!\n");
#endif
       /* check that number of coins is correct */
#if (ENABLE_ASSERTS == 1)
       assert (G.coins == handCount * 2 + bonus);
#endif
       
       /* set all cards to gold*/
       memcpy(G.hand[p], golds, sizeof(int) * handCount);
       updateCoins(p, &G, bonus);
#if (PRINT_TEST == 1)
       printf("Treasure Cards: %d\nG.coins = %d, expected = %d\n", handCount, G.coins, handCount * 3 + bonus);
       if (G.coins == handCount * 3 + bonus)
	 printf("Pass!\n");
       else
	 printf("Fail!\n");
#endif
       /* check that number of coins is correct */
#if (ENABLE_ASSERTS == 1)
       assert(G.coins == handCount * 3 + bonus);
#endif
       
       /* set all cards to non-Treasure cards */
       memcpy(G.hand[p], duchies, sizeof(int) * handCount);
       updateCoins(p, &G, bonus);
#if (PRINT_TEST == 1)
       printf("Treasure Cards: 0\nG.coins = %d, expected = %d\n", G.coins, bonus);
       if (G.coins == bonus)
	 printf("Pass!\n");
       else
	 printf("Fail!\n");
#endif
       /* check that number of coins is correct */
#if (ENABLE_ASSERTS == 1)
       assert(G.coins == bonus);
#endif
     }
    }
  }
  
#if (ENABLE_ASSERTS == 1)  
  printf("All tests passed!\n");
#endif  
  
  return 0;
}