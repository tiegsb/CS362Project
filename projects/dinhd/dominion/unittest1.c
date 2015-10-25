/*
This program tests the gainCard function.
The parameters for this function are:
int supplyPos, struct gameState *state, int toFlag, int player

*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include "interface.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {

    int numPlayer = 2;
    int p, flag, card;
    struct gameState G;




    //printSupply(&G);
    //testing to see if all the cards can be added. 

    char name[32];

    printf ("* * * * * * * * * * * * * * * * TESTING unittest1 gainCard():* * * * * * * * * * * * * * * * \n");
    for (p = 0; p < numPlayer; p++)
    {
        //test to see if you can gain a card without supply
        for (flag = 1; flag <= 3; flag++)
        {
            for (card = adventurer; card <= great_hall; card++)
            {
                
                cardNumToName(card, name);  

                printf("Test: Card %s added with no supply with flag %i for player %i \n", name, flag, p);
                assert ( gainCard(card, &G, flag, p) == -1);
    
            }
        }
        //test to see if you can gain the card desired to deck.
        for (card = adventurer; card <= great_hall; card++)
        {
            cardNumToName(card, name); 
            
            //add a card to deck
            G.supplyCount[card] = 1;
            printf("Test: Card %s was added to deck for player %i \n", name, p);
            gainCard(card, &G, 1, p);

            int foundCard = 0;
            int deckIndex;
            int deckCount = G.deckCount[p];

            for ( deckIndex = 0; deckIndex < deckCount; deckIndex++)
            {
                int deckCard = G.deck[p][deckIndex];
                if (card == deckCard)
                    foundCard = 1;
            } 
            assert (foundCard == 1);
           
        }

        //test to see if you can gain the card desired to hand.
        for (card = adventurer; card <= great_hall; card++)
        {
            cardNumToName(card, name); 
            
            //add a card to hand
            G.supplyCount[card] = 1;
            printf("Test: Card %s was added to hand for player %i \n", name, p);
            gainCard(card, &G, 2, p);

            int foundCard = 0;
            int handIndex;
            int handCount = G.handCount[p];

            //search hand fo card added
            for ( handIndex = 0; handIndex < handCount; handIndex++)
            {
                int deckCard = G.hand[p][handIndex];
                if (card == deckCard)
                    foundCard = 1;
            } 
            assert (foundCard == 1);        
        }

        //test to see if you can gain the card desired to discard. 
                for (card = adventurer; card <= great_hall; card++)
        {
            cardNumToName(card, name); 
            
            //add a card to hand
            G.supplyCount[card] = 1;
            printf("Test: Card %s was added to discard for player %i \n", name, p);
            gainCard(card, &G, 0, p);

            int foundCard = 0;
            int discardIndex;
            int discardCount = G.discardCount[p];

            //search hand fo card added
            for ( discardIndex = 0; discardIndex < discardCount; discardIndex++)
            {
                int discardedCard = G.hand[p][discardIndex];
                if (card == discardedCard)
                    foundCard = 1;
            } 
            assert (foundCard == 1);        
        }
    }
   // printf ("deck count: %i", fullDeckCount(p, adventurer, &G));
    printf("All tests passed!\n");

    return 0;
}
