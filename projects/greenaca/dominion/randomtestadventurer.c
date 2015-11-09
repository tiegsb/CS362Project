/* -----------------------------------------------------------------------
 * Random Test for adventurer_card()
 *
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include "mt19937.h"

int main() {
    int i;
    int seed = 1000;
    int numPlayer =2;
    int maxBonus = 10;
    int p, r, handCount;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G, testG;
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

    unsigned long init[4]={0x123, 0x234, 0x345, 0x456}, length=4;
	init_by_array(init, length);

    printf ("TESTING adventurer_card():\n");
    for (int j = 0; j <= 1000; j++){

    	int c = 0;
		int second_treasure = -1;
		int added_money = 0;
		int hand_money = 0;

    	printf("-------------------------------------------------------\n");
        
    	memset(&G, 23, sizeof(struct gameState));   // clear the game state
    	r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

        G.handCount[1] = genrand_int32() % 12 + 1;
        G.discardCount[1] = 0;
        G.deckCount[1] = genrand_int32() % 35;

        for (int d = 0; d <= G.deckCount[1]; d++){
        	int random_deck_card = genrand_int32() % (treasure_map + 1);
        	G.deck[1][d] = random_deck_card;

        	if (random_deck_card == gold || random_deck_card == silver || random_deck_card == copper) {		
        		if (c < 2) {
        			if (random_deck_card == gold)
        				added_money+=3;
        			else if (random_deck_card == silver)
        				added_money+=2;
        			else
        				added_money+=1;
  
        			second_treasure = d;
        		}
        		c++;
        	}
        }

        for (int h = 0; h <= G.handCount[1]; h++){
        	int random_hand_card = genrand_int32() % (treasure_map + 1);
        	G.hand[1][h] = random_hand_card;

        	if (random_hand_card == gold)
        		hand_money+=3;
        	else if (random_hand_card == silver)
        		hand_money+=2;
        	else if (random_hand_card == copper)
        		hand_money+=1;
        }

        G.handCount[0] = genrand_int32() % 5 + 1;
        G.discardCount[0] = genrand_int32() % 35;
        G.deckCount[0] = genrand_int32() % 35;

        memcpy(&testG, &G, sizeof(struct gameState));

        int temphand[MAX_HAND];
        adventurer_card(1, -1, 0, 0, temphand, &G);

        updateCoins(1, &G, 0);

        printf("Expected coin count = %d, Actual coin count = %d\n", hand_money + added_money, G.coins);
        if (G.coins == hand_money + added_money) {
            printf("TEST PASSED\n\n");
        } else {
            printf("TEST FAILED\n\n");
        }
        
        printf("Expected handCount = %d, Actual handCount = %d\n", testG.handCount[1] + 1, G.handCount[1]);
        if (G.handCount[1] == testG.handCount[1] + 1) {
            printf("TEST PASSED\n\n");
        } else {
            printf("TEST FAILED\n\n");
        }

        if (second_treasure != -1) {
        	printf("Expected discardCount = %d, Actual discardCount = %d\n", testG.discardCount[1] + second_treasure - 1, G.discardCount[1]);
        	if (G.discardCount[1] == testG.discardCount[1] + second_treasure - 1) {
            	printf("TEST PASSED\n\n");
        	} else {
            	printf("TEST FAILED\n\n");
        	}
        } else {
        	printf("Expected discardCount = %d, Actual discardCount = %d\n", testG.deckCount[1], G.discardCount[1]);
        	if (G.discardCount[1] == testG.deckCount[1]) {
            	printf("TEST PASSED\n\n");
        	} else {
            	printf("TEST FAILED\n\n");
        	}
        }

        printf("Expected deckCount = %d, Actual deckCount = %d\n", testG.deckCount[1] - (second_treasure + 1), G.deckCount[1]);
        if (G.deckCount[1] == testG.deckCount[1] - (second_treasure + 1)) {
            printf("TEST PASSED\n\n");
        } else {
            printf("TEST FAILED\n\n");
        }

        printf("Expected other player's handCount = %d, Actual other player's handCount = %d\n", testG.handCount[0], G.handCount[0]);
        if (G.handCount[0] == testG.handCount[0]) {
            printf("TEST PASSED\n\n");
        } else {
            printf("TEST FAILED\n\n");
        }

        printf("Expected other player's discardCount = %d, Actual other player's discardCount = %d\n", testG.discardCount[0], G.discardCount[0]);
        if (G.discardCount[0] == testG.discardCount[0]) {
            printf("TEST PASSED\n\n");
        } else {
            printf("TEST FAILED\n\n");
        }

        printf("Expected other player's deckCount = %d, Actual other player's deckCount = %d\n", testG.deckCount[0], G.deckCount[0]);
        if (G.deckCount[0] == testG.deckCount[0]) {
            printf("TEST PASSED\n\n");
        } else {
            printf("TEST FAILED\n\n");
        }
	}
	return 0;
}