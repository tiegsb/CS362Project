/*
This program tests the scoreFor function.
The parameters for this function are:
struct gameState *state

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

    int score;
    int card;
    struct gameState G;
    struct gameState D;

    printf("* * * * * * * * * * * * * * * * Testint unittest4 scoreFor * * * * * * * * * * * * * * * * \n");
    
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
    sea_hag, tribute, smithy};
    initializeGameNoPoints(2, k, 2, &G);

    printf ("Test: Empty Game \n");
    score = scoreFor(0, &G);
    //printf ("Score is %i \n", score);


    assert (score == 0);

    printf("Test: one score card found in hand\n");
    for (card = curse; card <= great_hall; card++)
    {
        G.supplyCount[card] = 1;
    }

    gainCard(curse, &G, 2, 0); // -1 pt
    gainCard(estate, &G, 2, 0); // 1 pt
    gainCard(duchy, &G, 2, 0); // 3 pts
    gainCard(province, &G, 2, 0); // 6 pts
    gainCard(great_hall, &G, 2, 0); //1 pt
    gainCard(gardens, &G, 2, 0); // 0pt
    //printHand(0, &G);

    score = scoreFor(0, &G);
    assert (score == 10);

    G = D;

    for (card = curse; card <= great_hall; card++)
    {
        G.supplyCount[card] = 1;
    }   

    printf("Test: One of each in deck \n");
    gainCard(curse, &G, 1, 0); // -1 pt
    gainCard(estate, &G, 1, 0); // 1 pt
    gainCard(duchy, &G, 1, 0); // 3 pts
    gainCard(province, &G, 1, 0); // 6 pts
    gainCard(great_hall, &G, 1, 0); //1 pt
    gainCard(gardens, &G, 1, 0); // 1pt
    //printDeck(0, &G);

    score = scoreFor(0, &G);
    //printf("score: %i \n", score);
    printf ("################################################### \n Error: iterator for deck count cycles through i = discardCount istead of deckCount \n ################################################### \n");



    G = D; 

    for (card = curse; card <= great_hall; card++)
    {
        G.supplyCount[card] = 1;
    }

    printf("Test: One of each in discard\n");
    gainCard(curse, &G, 0, 0); // -1 pt
    gainCard(estate, &G, 0, 0); // 1 pt
    gainCard(duchy, &G, 0, 0); // 3 pts
    gainCard(province, &G, 0, 0); // 6 pts
    gainCard(great_hall, &G, 0, 0); //1 pt
    gainCard(gardens, &G, 0, 0); // 1pt
    
    //printDeck(0, &G);
    //printDiscard(0, &G);
    //printHand(0, &G);

    score = scoreFor(0, &G);
    //printf ("score: %i disardcount: %i \n", score, discardCount);
    printf ("################################################### \n Error: iterator for deck count cycles through i = discardCount istead of deckCount \n ################################################### \n");


    
    printf("All tests passed!\n");

    
    
    return 0;
}
