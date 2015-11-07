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
const int numTestRuns = 50;
const int Max_Deck_Size = 500;

int main ()
{
	printf("* * * * * * * * * * * * * * * * randomtestcard * * * * * * * * * * * * * * * * \n");

	int i;
    int j;
    int peekIndex;
    struct gameState G;
    char name[30];

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
    int cardsDrawn[27];
    int cardsDrawnCount;
    int actualcardsDrawn[27];
    int expectedDiscardCount;
    int expectedHandSize;


    int deckSize = rand() % MAX_DECK + 1;
    int handPlayed;

    //initialize cardDrawn
    for (i = 0; i < 27; i++)
	{
    		cardsDrawn[i]=0;
    		actualcardsDrawn[i] = 0;
	}

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
    	printf("Run number %i \n", i);
    	G = D;
    	shuffle(0, &G);
    	cardsDrawnCount = 0;
    	expectedHandSize = numHandCards(&G) + 2; // + 3 cards drawn - 1 smithy card discarded
    	expectedDiscardCount = 1;

    	for (j = 0; j < 27; j++)
		{
    		cardsDrawn[j]=0;
    		actualcardsDrawn[j] = 0;
		}

		peekIndex = G.deckCount[0] - 1;
    	//peeks at the deck to see what the next 3 cards are
    	for (j = 0; j < 3; j++)
    	{

    		card = G.deck[0][peekIndex];
    		cardNumToName(card, name);
    		//printf("deck card %i: %s\n", card, name);
    		cardsDrawn[card] = cardsDrawn[card] + 1;
    		cardsDrawnCount++;
    		peekIndex--;
            if (peekIndex < 0)
            {
                break;
            }
    	}

    	//add the other 4 smithy cards not played
    	for (j = 0; j < 4; j++)
    	{
    		cardsDrawn[smithy] = cardsDrawn[smithy] + 1;
    		cardsDrawnCount++;
    	}

    	//printf("before drawing\n");
    	//printHand(0, &G);


    	handPlayed = rand() % numHandCards(&G);
    	playCard(handPlayed, -1, -1, -1, &G);

    	//printf("After drawing\n");
    	//printHand(0, &G);

    	//count actual cards in hand
    	for (j = 0; j < numHandCards(&G); j++)
    	{
    		card = G.hand[0][j];
    		actualcardsDrawn[card] = actualcardsDrawn[card] + 1;
    	}


    	//make sure all cards in hand are accounted for
    	for (j = 0; j < 27; j++)
    	{
    		cardNumToName(j, name);
    		
    		if  (actualcardsDrawn[j] != cardsDrawn[j])
            {
                printf("card %s actual: %i expected: %i\n", name, actualcardsDrawn[j], cardsDrawn[j]);
            }            }
    	}

    	//make sure that the card in discard is 1 and it's smithy
    	//printDiscard(0, &G);
    	if (expectedDiscardCount != G.playedCardCount)
        {
            printf("************** Error: expected discard count and played count different ***************\n");
        }
    	if (expectedDiscardCount == G.discardCount[0])
        {
            printf ("************** Error: expected played and played count different. ************** \n");

        }

    	if (numHandCards(&G) != expectedHandSize)
        {
            printf("************** Error: expected hand size does not match actual hand size **************\n");
        }

    }


	return 0;
}