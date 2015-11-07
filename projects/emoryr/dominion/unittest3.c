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

int main() {
    int seed = 1000;
    int numPlayer = 4;
    int p, r, handCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    int trashFlag = 0;
    srand(seed);
    int card;

    printf ("TESTING discardCard():\n");
    r = initializeGame(numPlayer, k, seed, &G);
      
    for (p = 0; p < numPlayer; p++)
    {
        for (int handPos = 5; handPos > 0; handPos--) {
                   
            //trashFlag = 0: card is not trashed
            //trashFlag >= 1: card is trashed
                trashFlag = (trashFlag + 1) %2;
 
            int handPrev = numHandCards(&G);                                    


            int k = discardCard(handPos, p, &G, trashFlag);             //testing randomly drawn cards from deck
                
#if (NOISY_TEST == 1)
            printf("PASSED. whoseTurn OUTPUT: %d RESULT: %d\n", p, whoseTurn(&G));
#endif         
            assert(whoseTurn(&G) == p);
 

 #if (NOISY_TEST == 1)
            printf("PASSED. handNumTest OUTPUT: %d RESULT: %d \n", handPrev -1, numHandCards(&G)); 
 #endif              
            assert(handPrev - 1 == numHandCards(&G));
 
#if (NOISY_TEST == 1)
            printf("PASSED. functionTest OUTPUT: 0 RESULT %d \n", k);
#endif
            assert(k == 0);
                
        }
        endTurn(&G);
    }            

    
    for (p = 0; p < numPlayer; p++)
    {
        for (handCount = 0; handCount < maxHandCount; handCount++) {
                int handPos = 999;
                while (handPos > numHandCards(&G)) {
                    handPos = rand() % 4;              
                }
            //trashFlag = 0: card is not trashed
            //trashFlag >= 1: card is trashed
                trashFlag = (trashFlag + 1) %2;

                
                int handPrev = numHandCards(&G);
                int prevCardCount = G.playedCardCount;
                int curCard = G.hand[p][handPos];
                int cntPrev = 0;


                for (int i = 0; i < numHandCards(&G); i++){
                    if (G.hand[p][i] == curCard)
                        cntPrev += 1;
                }
                                                       //
                int k = discardCard(handPos, p, &G, trashFlag);

#if (NOISY_TEST == 1)
            printf("PASSED. whoseTurn OUTPUT: %d RESULT: %d\n", p, whoseTurn(&G));
#endif
            assert(whoseTurn(&G) == p); 


#if (NOISY_TEST == 1)
           printf("PASSED. handNumTest OUTPUT: %d RESULT: %d \n", handPrev -1, numHandCards(&G));       
#endif
           assert(handPrev - 1 == numHandCards(&G));
                
#if (NOISY_TEST == 1)
            printf("PASSED. functionTest OUTPUT: 0 RESULT %d \n", k); 
#endif         
           assert(k == 0);

    
            if (trashFlag == 0) {
                assert(prevCardCount + 1 == G.playedCardCount);
                assert(curCard == G.playedCards[G.playedCardCount-1]);
                printf("PASSED. cardTest OUTPUT: %d RESULT: %d \n", prevCardCount + 1, G.playedCardCount);
                printf("PASSED. playedTest OUTPUT: %d RESULT: %d \n", curCard, G.playedCards[G.playedCardCount-1]);
            }

            int cnt = 0;          
            for (int i = 0; i < numHandCards(&G); i++){
                if (G.hand[p][i] == curCard)
                    cnt += 1;    
            }

            if (cntPrev != 0)
                assert (cntPrev - cnt == 1);
                printf("PASSED. countTest OUTPUT: %d RESULT: %d \n",cntPrev, cnt + 1);
            }  
        endTurn(&G);
    } 

    printf("All tests passed!\n");

    return 0;
}
