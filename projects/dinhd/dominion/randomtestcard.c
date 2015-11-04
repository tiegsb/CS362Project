// This tester tests the function smithy();

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <assert.h>
#include "rngs.h"
#include "interface.h"
#include <time.h> 
#include <stdio.h>   
#include <stdlib.h> 

//number of tests the user wants to run
const int numTestRuns = 10;
const int Max_Deck_Size = 500;

int main ()
{

	int i;
    int j;
    int peekIndex;
    struct gameState G;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
    sea_hag, tribute, smithy};
    initializeGame(2, k, 2, &G);

    //default gamestate.
    struct gameState D;
    srand(time(NULL));
    int card;
    G.deckCount[0] = 0;
    int deckCounter;

    //expected gamestates.
    int cardsDrawn[100];
    int cardsDrawnCount;
    int expectedDiscardCount;
    int expectedHandSize;


    int deckSize = rand() % MAX_DECK + 1;
    int handPlayed;
printHand
    //fill deck with random cards
    for (i = 0; i < deckSize; i++)
    {
    	deckCounter = G.deckCount[0];
    	card = rand() % 27; 
    	G.deck[0][deckCounter] = card;
    	G.deckCount[0]++;
    }

    //fill hand with smithy cards - We're not testing the playcard function so we're not checking to 
    //see if it's played or not
    for (i = 0; i < numHandCards(&G); i++)
    {
    	G.hand[0][i] = smithy;
    }

    shuffle(0, &G);

    //store default state
    D = G;

    for (i = 0; i < numTestRuns; i++)
    {
    	G = D;
    	shuffle(0, &G);
    	cardsDrawnCount = 0;
    	expectedHandSize = numHandCards(&G) + 2; // + 3 cards drawn - 1 smithy card discarded
    	expectedDiscardCount = 1;

    	//peeks at the deck to see what the next 3 cards are
    	for (j = 0; j < 3; j++)
    	{
    		peekIndex = G.deckCount[0] - 1
    		cardsDrawn[G.deck[0][peekIndex]]++;
    		cardsDrawnCount++;
    	}



    	handPlayed = rand() % numHandCards(&G);
    	playCard(handPlayed, -1, -1, -1, &G);

    }


	return 0;
}