#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define NUMTESTS 100

int randomtestGreatHall(struct gameState *state);

int main()
{
    int retValue;
    int seed = rand();
    int i;
    int card = 16; //int value of great_hall card
    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;
    int handPos = 0;
    int *bonus = 0;
    int p = 0;
    int numPlayers;
    int preDeckCount, preNumAct;
    int fail = 0;
    int pass = 0;

    struct gameState G;

    int kings[10] = {adventurer, council_room, feast, gardens, mine,
                     remodel, smithy, village, baron, great_hall};

    printf("*****Random Testing of Great Hall Card function*****\n");
    printf("The Great Hall Card allows the player to draw 1 extra card and use 1 extra action\n");

    for(i = 0; i < NUMTESTS; i++) {
        numPlayers = 1 + (rand() % 4);

        initializeGame(numPlayers, kings, seed, &G);
        p = rand() % numPlayers;

        G.deckCount[p] = rand() % MAX_DECK;
        G.discardCount[p] = rand() % MAX_DECK;

        preDeckCount = G.deckCount[p];

        cardEffect(card, choice1, choice2, choice3, &G, handPos, bonus);

        printf("Testing card drawn\n");
        printf("Pre-function count %d, post-function count %d\n", preDeckCount, G.deckCount[p]);
        if(preDeckCount != (G.deckCount[p] + 1))
        {
            printf("Test failed\n");
            fail++;
        }
        else
        {
            printf("Test passed\n");
            pass++;
        }

        preNumAct = G.numActions;

        printf("\n");
        printf("Testing increased number of actions\n");
        printf("Pre-function count %d, post-function count %d\n", preNumAct, G.numActions);
        if(preNumAct != (G.numActions + 1))
        {
            printf("Test failed\n");
            fail++;
        }
        else
        {
            printf("Test passed\n");
            pass++;
        }
        printf("\n");
    }

      printf("%d tests passed, %d tests failed\n", pass, fail);



    return 0;
}

int randomtestGreatHall(struct gameState *state) {

//      //+1 Card
//      drawCard(currentPlayer, state);
//
//      //+1 Actions
//      state->numActions++;
//
//      //discard card from hand
//      discardCard(handPos, currentPlayer, state, 0);

//    if(retValue == 0)
//    {
//        printf("Test passed: return value = 0.\n");
//    }
//    else {
//        printf("Test failed: return value = 1.\n");
//    }
//    printf("\n");

      return 0;

}
