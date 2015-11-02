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
const int numTestRuns = 1000;

int main() {

    int i;
    int j;
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
    // int cardsDrawn[100];
    int cardsDrawnCount;
    int treasureCardCount;
    int expectedDiscardCount;
    int expectedHandSize;
    int expectedMoney;
    int actualMoney;



    //fill deck with random cards
    for (i = 0; i < 30; i++)
    {
    	deckCounter = G.deckCount[0];
    	card = rand() % 27; 
    	G.deck[0][deckCounter] = card;
    	G.deckCount[0]++;
    }

    // add some coins
    for ( i = 0; i < 15; i++)
    {
    	deckCounter = G.deckCount[0];
    	card = rand() % 3 + 4;
    	G.deck[0][deckCounter] = card;
    	G.deckCount[0]++;


    }

    //fill hand with adventurer cards
    for (i = 0; i < numHandCards(&G); i++)
    {
    	G.hand[0][i] = adventurer;
    }

    shuffle(0, &G);

    D = G;

    for (i = 0; i < numTestRuns; i++)
    {
    	// printf("Running test # %i \n", i);
    	G = D;
    	shuffle(0, &G);
    	cardsDrawnCount = 0;
    	treasureCardCount = 0; 
    	expectedHandSize = numHandCards(&G) + 2;
    	expectedMoney =  0;  
    	actualMoney = 0; 
    	expectedDiscardCount = 0;

    	// printf("%i vs %i on run %i \n", expectedDiscardCount, G.discardCount[0], i);

    	//copied from playdom.c to count the money in hand. 
    	for (j = 0; j < numHandCards(&G); j++) {
	      if (handCard(j, &G) == copper)
	    	expectedMoney++;
	      else if (handCard(j, &G) == silver)
	    	expectedMoney += 2;
	      else if (handCard(j, &G) == gold)
	      	expectedMoney += 3;
	  }

	  // printf("*******%i vs %i on run %i \n", expectedDiscardCount, G.discardCount[0], i);

    	//this loop peeks at the deck to see how many cards need to be drawn and what treasure cards will be picked up.
    	for (j = G.deckCount[0] - 1; j > 0; j--)
    	{
    		// printf("drew card #: %i on deckcount %i \n", cardsDrawnCount, j);
    		if (G.deck[0][j] == copper)
    		{
    			//printf("found copper\n");
    			treasureCardCount++;
    			expectedMoney++;
    		}
    		else if (G.deck[0][j] == silver)
    		{
    			//printf("found silver\n");
    			treasureCardCount++;
    			expectedMoney += 2;
    		}
    		else if (G.deck[0][j] == gold)
    		{
    			//printf("Found gold\n");
    			treasureCardCount++;
    			expectedMoney += 3;
    		}	
    		
    		// cardsDrawn[cardsDrawnCount] = G.deck[0][G.deckCount[0]];
    		cardsDrawnCount++;

    		//printf("*******expected money %i /n", expectedMoney);
    		if(treasureCardCount == 2){
    			// printf("Drew %i cards\n", cardsDrawnCount);
    			break;
    		}
    	}

    	expectedDiscardCount = cardsDrawnCount -1;

    	playCard(0, -1, -1, -1, &G);

    	for (j = 0; j < numHandCards(&G); j++) {
	      if (handCard(j, &G) == copper)
	    	actualMoney++;
	      else if (handCard(j, &G) == silver)
	    	actualMoney += 2;
	      else if (handCard(j, &G) == gold)
	      	actualMoney += 3;
	  	}

	  	// printf("actual money %i\n", actualMoney);

	  	//make sure that the hand, discard and money count are all accurate.
    	assert (numHandCards(&G) == expectedHandSize);

    	// printf("expected discard %i, discard count % i \n", expectedDiscardCount, G.discardCount[0] );
    	assert (expectedDiscardCount == G.discardCount[0]);
    	assert (actualMoney == expectedMoney);

    }

    //fill hand with random cards




    return 0;
}
