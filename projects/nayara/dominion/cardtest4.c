/* Author: Ashok Nayar
 * cs362, Fall 2015
 * Assignment 3: Unit Testing
 * cardtest4.c (Testing council card function)
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int p, r, handCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine
        , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    int dummyCard = adventurer;
    int testCard = council_room;
    
    
    printf("Testing councilEffect()\n");
    // Loop through each player
    for (p = 0; p < numPlayer; p++)
    {
        // Intialize game and set explicit values
        r = initializeGame(numPlayer, k, seed, &G);
        G.whoseTurn = p;
        G.coins = 5;
        G.discardCount[p]= 0;
        G.numActions = 5;
        G.deckCount[p] = MAX_DECK;
        // Set every card in the deck to dummy cards
        // so we can compare easily
        for (i=0; i< MAX_DECK; i++)
        {
            G.deck[p][i] = dummyCard;
        }

        // Create different sized hands
        for (handCount = 1; handCount <= maxHandCount; handCount++)
        {
            int i;
            G.handCount[p] = handCount;
            
            // Set the other player's hand count to 0
            if (p ==0)
            {
                G.handCount[1] = 0;
            }
            else
            {
                G.handCount[0] = 0;
            }
            
            // Set the current player cards to dummy cards
            for(i = 0; i<handCount;i++)
            {
                G.hand[p][i] = dummyCard;
            }
            
            // Add one council card
            G.hand[p][0] = testCard;
            
            
            // Double check to make sure intial values are correct
#if (NOISY_TEST == 1)
            printf("***Test for player %d with %d  cards in hand\n",p,i);
#endif
            

#if (NOISY_TEST == 1)
            printf("Num actions. Expected %d, received %d\n",5,G.numActions);
#endif
            assert(G.numActions == 5);
            
#if (NOISY_TEST == 1)
            printf("Num coins. Expected %d, received %d\n",5,G.coins);
#endif
            assert(G.coins == 5);
#if (NOISY_TEST == 1)
            printf("Testing for village card. Expected %d, received %d\n",testCard, G.hand[p][0]);
#endif
            assert(G.hand[p][0] == testCard);
#if (NOISY_TEST == 1)
            printf("Hand count. Expected %d, received %d\n",handCount, G.handCount[p]);
#endif
            assert(G.handCount[p] == handCount);
            // Check other player hand counts
#if (NOISY_TEST == 1)
            if (p == 0)
            {
                printf("Hand count for player %d: Expected %d, received %d\n",p,handCount, G.handCount[p] );
                printf("Hand count for player %d: Expected %d, received %d\n",1,0, G.handCount[1] );
            }
            else
            {
                printf("Hand count for player %d: Expected %d, received %d\n",p,handCount, G.handCount[p] );
                printf("Hand count for player %d: Expected %d, received %d\n",0,0, G.handCount[0] );
            }
#endif
            if (p ==0 )
            {
                assert(G.handCount[p] == handCount);
                assert(G.handCount[1] == 0);
            }
            else
            {
                assert(G.handCount[p] == handCount);
                assert(G.handCount[0] == 0);
            }
            
#if (NOISY_TEST == 1)
            printf("*Calling council function.\n");
#endif
            councilEffect(p, 0, &G); // Call council card function
      
            // Check results
            // Cards are not added to other players' hands but
            // instead added to current player's hand

#if (NOISY_TEST == 1)
            printf("Num actions. Expected %d, received %d\n",5,G.numActions);
#endif
            assert(G.numActions == 5);
            
#if (NOISY_TEST == 1)
            printf("Num coins. Expected %d, received %d\n",5,G.coins);
#endif
            assert(G.coins == 5);
#if (NOISY_TEST == 1)
            printf("Testing for replaced village card. Expected %d, received %d\n",testCard, G.hand[p][0]);
#endif
            assert(G.hand[p][0] != testCard);
#if (NOISY_TEST == 1)
            printf("Hand count. Expected %d, received %d\n",handCount, G.handCount[p]);
#endif
            //assert(G.handCount[p] == handCount);
            if(G.handCount[p] != handCount)
            {
                printf("FAILURE: Hand counts do not match.\n");
            }
#if (NOISY_TEST == 1)
            if (p == 0)
            {
                printf("Hand count for player %d: Expected %d, received %d\n",p,handCount, G.handCount[p] );
                printf("Hand count for player %d: Expected %d, received %d\n",1,0, G.handCount[1] );
            }
            else
            {
                printf("Hand count for player %d: Expected %d, received %d\n",p,handCount, G.handCount[p] );
                printf("Hand count for player %d: Expected %d, received %d\n",0,0, G.handCount[0] );
            }
#endif
            if (p ==0 )
            {
                //assert(G.handCount[p] == handCount);
                //assert(G.handCount[1] == 0);
                if (G.handCount[p] != handCount || G.handCount[1] !=0)
                {
                    printf("FAILURE: Hands have too many or too few cards.\n");
                }
            }
            else
            {
                //assert(G.handCount[p] == handCount);
                //assert(G.handCount[0] == 0);
                if (G.handCount[p] != handCount || G.handCount[1] !=0)
                {
                    printf("FAILURE: Hands have too many or too few cards.\n");
                }
                
            }
            printf("\n");
            
            
        }
    }

    
    printf("All tests passed!\n");
    
    return 0;
}