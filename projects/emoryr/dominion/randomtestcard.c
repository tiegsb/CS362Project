#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 0
#define EXPECT(condition)           \
    if (!(condition)) {             \            
        failed_tests++;             \
        continue;                   \
    } \
    else { \
        passed_tests++; \
    } \

int handPos (struct gameState *G, int handCount);
int deckCreate (struct gameState *G);

int main() {
    int passed_tests = 0;
    int failed_tests = 0;
    int total_tests = 0;
    int seed = 1000;
    int numPlayer = 4;
    int p, handCount, d;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    srand(seed);
    int randomHand[maxHandCount];
    printf ("TESTING smithy using smithy_play:\n");
    
for (int i = 0; i < 500000; i++) {
    
    initializeGame(numPlayer, k, seed, &G);
    deckCreate(&G);//initialize a new game
    
    for (p = 0; p < numPlayer; p++)
    {   
        for (handCount = 1; handCount <= maxHandCount; handCount++) {

            for (int i = 0; i < handCount; i++) {
                randomHand[i] = rand() % 9 + 7;
            }

            G.handCount[p] = handCount;                // set the number of cards on hand
            memcpy(G.hand[p], randomHand, sizeof(int) * handCount); // set hand
            total_tests++;
            EXPECT(G.whoseTurn == p);
            
            int handPosition = handPos(&G, handCount);
            
            if (handPosition == -1) {
                continue;
            }
            else {
                d = smithy_play(&G, p, handPosition);
            }

#if (NOISY_TEST == 1)
            printf("Passed. Funciton output: %d, Expected: %d\n", d, 0);
#endif
            total_tests++;
             EXPECT(d == 0);
            
#if (NOISY_TEST == 1)
            printf("Failed. Test output: %d Result: %d \n", handCount + 2, G.handCount[p]);
#endif           
            //one card was discarded and three cards were picked up in smithy_play
            total_tests++;
            EXPECT(G.handCount[p] == handCount + 2);
#if (NOISY_TEST == 1)
        printf("Passed. Top of discard Test Ouput: %d Actual: %d \n" ,smithy, G.playedCards[G.playedCardCount-1]);
#endif  
        total_tests++;
        EXPECT(G.playedCards[G.playedCardCount-1] == smithy);
        
        }
        endTurn(&G);
    }
}

    printf("Total tests run: %d, Passing: %d Failing: %d\n", total_tests, passed_tests, failed_tests);

    return 0;
}
int deckCreate (struct gameState *G) {
    
    enum CARD deck[] = {gold, silver, village, gold, village, feast, silver, copper, estate, council_room};
    for (int i = 0; i < G->numPlayers; i++) {
        memcpy(G->deck[i], &deck, sizeof (deck));
        G->deckCount[i] = sizeof(deck) / sizeof(enum CARD);
    }
    return 0;
}
int handPos (struct gameState *G, int handCount) {
    for (int pos = 0; pos < handCount; pos ++) {
        if (G->hand[G->whoseTurn][pos] == smithy) {
            return pos;
        }
    }
    return -1;
}