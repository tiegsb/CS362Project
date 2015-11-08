//randomly tests the adventurer card

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dominion.h"
#include "assert.h"
#include <time.h> 

//test results will be save in a testresult struct 
struct testResults
{	
	int twoCoinsInHand;
	int adventurerInPlayedCards;
	int otherCardsDiscarded;
	int correctNumInHand;	
};


int getHandPos()
{
	//randomly generate number from 0-4
	return rand()%27;
}

int getDeckCount()
{
	return rand()%16;
}

int getPlayedCardCount()
{
	return rand()%30;
}

void fillCardArray(int *array, int length)
{
	int i = 0;

	//fill the array with cards
	for( i = 0; i<length; ++i)
	{
		//array[i]=rand()%27;
		array[i]=rand()%6;
	}
}

int countCoins(int *array, int length)
{
	int i =0;
	int numCoins = 0;

	for( i = 0; i<length; ++i)
	{
		if (array[i] == gold || array[i] == silver || array [i] == copper)
		{
			++numCoins;
		}
	}

	return numCoins;
}


int countAdventurer(int *array, int length)
{
	int i =0;
	int numAdventurer = 0;

	for( i = 0; i<length; ++i)
	{
		if (array[i] == adventurer)
		{
			++numAdventurer;
		}
	}

	return numAdventurer;
}

void testAdventurer(struct testResults *pResults)
{
	//create gameState
	struct gameState state;
	initState(&state);
	

	//changing hand pos (fomr 1-5)
	//randomly generate my deck, and add adventurer to ramdomly generated handPos
	int handPos = getHandPos();
	fillCardArray(state.hand[0], 5);
	state.hand[0][handPos] = adventurer;
	int coinsInHand = countCoins(state.hand[0], 5);
	state.handCount[0] = 5;


	

	//change draw deck to change what cards are added to hand, random number of cards in deck
	int deckCount = state.deckCount[0] = getDeckCount();
	int discardCount = state.discardCount[0] = 15-deckCount;
	int playedCardCount = state.playedCardCount = getPlayedCardCount();
	fillCardArray(state.deck[0], deckCount);
	fillCardArray(state.discard[0], discardCount);
	fillCardArray(state.playedCards, playedCardCount);

	//In order for adventurer to work there need to be at least 2 coin cards between the deck and discard piles.
	//check to make sure there are at least 4 coin cards in the deck and discard cards combined. 
	//If not populate the first 2 indices of both the discard pile and deck with coin cards (
	if(countCoins(state.deck[0], deckCount) + countCoins(state.discard[0], discardCount) < 2)
	{
		if(deckCount<2)
		{ 
			state.deck[0][0] = gold;
			state.deck[0][1] = gold;
			deckCount = 2;
			state.deckCount[0] = 2;
		}
		else
		{
			state.deck[0][0] = gold;
			state.deck[0][1] = gold;
		}
	}
	



	// Figure out expected counts
	//int expectedDeckCount = deckCount - 3;
	int expectedHandCount = 6; //2 new coins - discarded adventurer 
	int expectedPlayedCardCount = state.playedCardCount + 1;
	int expectedAdventurerPlayedCardCount = countAdventurer(state.playedCards, state.playedCardCount) + 1;
	int expectedCoinsInHand = coinsInHand + 2;

//call adventurer 
	adventurer_effect(&state, 0);

	//2 coins were added to the hand
	if(expectedCoinsInHand != countCoins(state.hand[0], state.handCount[0]))
	{
		pResults->twoCoinsInHand++;
	}
	//adventurer was added to the played cards pile
	if(expectedAdventurerPlayedCardCount != countAdventurer(state.playedCards, state.playedCardCount))
	{
		pResults->adventurerInPlayedCards++;
	}

	//check that the cards are added to the discard
	if(state.deckCount[0] + state.discardCount[0] == deckCount + discardCount -2)
	{

		pResults->otherCardsDiscarded++ ;
	}

	//There are the correct number of cards in the hand at the end
	if(expectedHandCount != state.handCount[0])
	{
		pResults->correctNumInHand++;
		//printf("%i cards in hand\n", state.handCount[0]); 
	}

	//check that the cards are added to the discard

}




void randomTestAdventurer()
{
	//seed the random number
	srand(time(NULL));

	//create testResults struct
	struct testResults results = {0,0,0,0};

	int i;
	int timesTested = 200;

	for( i=0; i<timesTested; ++i)
	{
		testAdventurer(&results);
	}

	printf("The Adventurer() tests were run %i times\n", i);

	if(results.twoCoinsInHand)
	{
		printf("FAIL: Adventurer() did not have 2 extra coins at the end %i out of %i times\n", results.twoCoinsInHand, timesTested);
	}
	else
	{
		printf("PASS: Adventurer() added 2 cards to the hand every time\n");
	}

	if(results.adventurerInPlayedCards)
	{
		printf("FAIL: Adventurer() the adventurer card was not not added to played cards %i of %i times\n", results.adventurerInPlayedCards, timesTested);
	}
	else
	{
		printf("PASS: Adventurer() the adventurer was added to played cards correctly every time\n");
	}

	if(results.otherCardsDiscarded)
	{
		printf("FAIL: Adventurer() the non coin cards were not properly discarded %i of %i times\n", results.otherCardsDiscarded, timesTested);
	}
	else
	{
		printf("PASS: Adventurer() the non coin cards were always properly discarded\n");
	}



	if(results.correctNumInHand)
	{
		printf("FAIL: Adventurer() did not end with the correct number of cards in the hand %i of %i times\n", results.correctNumInHand, timesTested);
	}
	else
	{
		printf("PASS: Adventurer() ended with the correct number of cards in the hand each time\n");
	}	
}

int main()
{
	randomTestAdventurer();
	return 0;
}