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
const int Max_Deck_Size = 500;

int main() {

printf("* * * * * * * * * * * * * * * * randomtestadventurer * * * * * * * * * * * * * * * * \n");
    int i;
    int j;
    struct gameState G;
    struct gameState D;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
    sea_hag, tribute, smithy};
    initializeGame(2, k, 2, &G);

    //default gamestate.
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
    int deckSize; 

    
    int handPlayed;

    D = G;


    for (i = 0; i < numTestRuns; i++)
    {
        G= D;
        deckSize = rand() % MAX_DECK + 1;
        //fill deck with random cards
        for (j = 0; j < deckSize; j++)
        {
            deckCounter = G.deckCount[0];
            card = rand() % 27; 
            G.deck[0][deckCounter] = card;
            G.deckCount[0]++;
        }

        //this makes the deckCount artificially small so that the shuffle function gets called
        // G.deckCount[0] = rand() % 10;



        //fill hand with adventurer cards - We're not testing the playcard function so we're not checking to 
        //see if it's played or not
        for (j = 0; j < numHandCards(&G); j++)
        {
            G.hand[0][j] = adventurer;
        }

 
        printf("Running test # %i \n", i);
        //printHand(0, &G);

    	shuffle(0, &G);
    	cardsDrawnCount = 0;
    	treasureCardCount = 0; 
    	expectedHandSize = numHandCards(&G) + 1;
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
    			// printf("found copper\n");
    			treasureCardCount++;
    			expectedMoney++;
    		}
    		else if (G.deck[0][j] == silver)
    		{
    			// printf("found silver\n");
    			treasureCardCount++;
    			expectedMoney += 2;
    		}
    		else if (G.deck[0][j] == gold)
    		{
    			// printf("Found gold\n");
    			treasureCardCount++;
    			expectedMoney += 3;
    		}	
    		
    		// cardsDrawn[cardsDrawnCount] = G.deck[0][G.deckCount[0]];
    		cardsDrawnCount++;

    		//printf("*******expected money %i /n", expectedMoney);
    		if(treasureCardCount == 2){
    			// printf("Drew %i cards\n", cardsDrawnCount);
                // printf("expected treasure found is %i \n", expectedMoney );
    			break;
    		}
    	}

        //acount for the two treasure cards being kept and the adventurer card being discarded
    	expectedDiscardCount = cardsDrawnCount-1;

        handPlayed = rand() % numHandCards(&G);
    	int status = playCard(handPlayed, -1, -1, -1, &G);

    	for (j = 0; j < numHandCards(&G); j++) {
	      if (handCard(j, &G) == copper)
	    	actualMoney++;
	      else if (handCard(j, &G) == silver)
	    	actualMoney += 2;
	      else if (handCard(j, &G) == gold)
	      	actualMoney += 3;
	  	}

         // printf("actual treasure found is %i \n", actualMoney );

	  	// printf("actual money %i\n", actualMoney);

	  	//make sure that the hand, discard and money count are all accurate.
    	if (numHandCards(&G) != expectedHandSize)
        {
            printf ("************* Error: expected hand size is wrong because adventurer not discarded. ************* \n");

        }

    	// printf("expected discard %i, discard count % i \n", expectedDiscardCount, G.discardCount[0] );
    	if (expectedDiscardCount != G.discardCount[0])
        {
            printf ("************* Error: played card (adventurer) was not discarded after use. ************* \n");

        }

    	if (actualMoney != expectedMoney)
        {
            printf ("*************  Error: Total treasure (%i) did not match expected (%i). ************* \n", actualMoney, expectedMoney);
        }



    }


    return 0;
}
