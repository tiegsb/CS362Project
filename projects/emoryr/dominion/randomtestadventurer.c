#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"

#define NOISY_TEST 0
#define EXPECT(condition)  \
    if (!(condition)) {             \
        failed_tests++;             \
        continue;                   \
    } \
    else { \
        passed_tests++; \
    } \


int deckCreate(struct gameState*);
int handPos (struct gameState *G, int handCount);

int main() {
    int failed_tests = 0;
    int total_tests = 0;
    int passed_tests = 0;
    int seed = clock();
    int numPlayer = 4;
    int p, handCount, d;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    srand(seed);
    int randomHand[maxHandCount];
    

printf ("TESTING adventurer:\n");
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

            int k = handPos(&G, handCount);

            if (k == -1) {
                continue;
            }
            else {
                d = adventurer_play(&G, p, k);
            }
            if (d == -1)
                continue;
            
#if (NOISY_TEST == 1)
            printf("Passed. Function Output: 0 Result: %d\n", d);
#endif
            if (d != -1) {
                total_tests++;
               EXPECT(d == 0);
            }
#if (NOISY_TEST == 1)
        printf("Failed. handCount Test Output: %d Result: %d\n", (handCount + 1), G.handCount[p]);
#endif
            //two treasure cards added to hand after call to adventurer_play() one card discarded
            //this fails because adventurer is never discarded
            total_tests++;
            EXPECT(G.handCount[p] == handCount + 1);
#if (NOISY_TEST == 1)
        printf("Failed discardTest Output: no silver, copper, or gold cards Result: Gold cards in discard.");
        printf("assert(G.discard[p][i] != copper && G.discard[p][i] != silver && G.discard[p][i] != gold.\n");
#endif  

            for (int i = G.discardCount[p]-1; i >= 0; i--) {
                total_tests++;
                EXPECT(G.discard[p][i] != copper && G.discard[p][i] != silver && G.discard[p][i] != gold);
                //This assertion fails. See bug5
            }
#if (NOISY_TEST == 1)
                printf("Passed. Output: %d Result %d\n", p, G.whoseTurn);
#endif
            
        }
         endTurn(&G);
    }
}

    
    printf("Total tests run: %d, Passing: %d Failing: %d\n", total_tests, passed_tests, failed_tests);


    return 0;

}

int deckCreate (struct gameState *G) {
    
    enum CARD deck[] = {gold, silver, smithy, gold, village, feast, silver, copper, estate, council_room};
    for (int i = 0; i < G->numPlayers; i++) {
        memcpy(G->deck[i], &deck, sizeof (deck));
        G->deckCount[i] = sizeof(deck) / sizeof(enum CARD);
    }
    return 0;
}

int handPos (struct gameState *G, int handCount) {
    for (int pos = 0; pos < handCount; pos ++) {
        if (G->hand[G->whoseTurn][pos] == adventurer) {
            return pos;
        }
    }
    return -1;
}
