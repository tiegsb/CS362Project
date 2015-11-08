//tests smithy
//there are 27 different types of cards in the deck

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dominion.h"
#include "assert.h"
#include <time.h> 


struct testResults
{
	int correctNumInDeck;
	int correctNumInHand;
	int correctSmithyInPlayed;
	int correctNumInPlayed;	
};

int getHandPos()
{
	//randomly generate number from 0-4
	return rand()%5;
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
		array[i]=rand()%27;
	}
}

int countSmithy(int *array, int length)
{
	int i =0;
	int numSmithy = 0;

	for( i = 0; i<length; ++i)
	{
		if (array[i] == smithy)
		{
			++numSmithy;
		}
	}

	return numSmithy;
}




void testSmithy(struct testResults *pResults)
{
	//create gameState
	struct gameState state;
	initState(&state);
	

	//changing hand pos (fomr 1-5)
	//randomly generate my deck, and add smithy to ramdomly generated handPos
	int handPos = getHandPos();
	fillCardArray(state.hand[0], 5);
	state.hand[0][handPos] = smithy;
	state.handCount[0] = 5;


	//change draw deck to change what cards are added to hand, random number of cards in deck
	int deckCount = state.deckCount[0] = getDeckCount();
	int discardCount = state.discardCount[0] = 15-deckCount;
	int playedCardCount = state.playedCardCount = getPlayedCardCount();
	fillCardArray(state.deck[0], deckCount);
	fillCardArray(state.discard[0], discardCount);
	fillCardArray(state.playedCards, playedCardCount);

//checking discard & cards added

	// Checking card totals
	int smithyDeckCount = countSmithy(state.deck[0], deckCount);
	int smithyHandCount = countSmithy(state.hand[0], 5);
	int smithyPlayedCardCount = countSmithy(state.playedCards, playedCardCount);

	// Figure out expected counts
	int expectedDeckCount = deckCount - 3;
	int expectedHandCount = 7;
	int expectedPlayedCardCount = playedCardCount + 1;
	int expectedSmithyPlayedCardCount = smithyPlayedCardCount + 1;


	//check if I am going to have to shuffle the deck. If so reset expected variables
	int shuffling = expectedDeckCount < 0;

	if (shuffling) 
	{
		expectedDeckCount += discardCount;
		
	}

//call smithy_effect
	smithy_effect(&state, 0, handPos);

	// did the discard get shuffled into the deck

	// is last card in discard a smithy
	
	// are the last three cards in hand the drawn cards

	// if not shuffling, then make sure the three cards drawn were from the top of the deck.

	// make sure the final count of smithies in your hand is correct

	// make sure the final count of smithies in your deck is correct


// make sure 3 cards were taken from the deck
	

	if(expectedDeckCount == state.deckCount[0])
	{
		pResults->correctNumInDeck ++;
	}

//check if you now have 7 cards in hand (+3 -smithy discard)

	if(expectedHandCount == state.handCount[0])
	{
		pResults->correctNumInHand ++;
	}

// make sure enough smithys in the played card deck
	
	if(expectedSmithyPlayedCardCount == countSmithy(state.playedCards, state.playedCardCount))
	{
		pResults->correctSmithyInPlayed++;
	}


// make sure the final count in playecCardCount is correct
	
	if(expectedPlayedCardCount == state.playedCardCount)
	{
		pResults->correctNumInPlayed ++;
	}

	return;
}	







void randomtestcard()
{
	srand(time(NULL));

	struct testResults results = {0,0,0,0};
	
	int i;
	int testNum = 300;

	for(i=0; i<testNum; ++i)
	{
		testSmithy(&results); 
	}

	printf("The smithy() tests were run %i times\n", i);

	//print test results for if there were the correct cards in the hand at the end of the turn
	if(results.correctNumInDeck < i)
	{
		printf("FAIL: Smithy() had the correct cards in the deck at the end %i or %i times\n", results.correctNumInDeck, i);
	}
	else
	{
		printf("PASS: Smithy() had the correct cards in the deck at the end %i or %i times\n", results.correctNumInDeck, i); 
	}

	//print test results for if there were the correct number of cards in the hand at the end of the turn
	if(results.correctNumInHand < i)
	{
		printf("FAIL: Smithy() had the correct number of cards in the hand %i of %i times\n", results.correctNumInHand, i);
	}
	else
	{
		printf("PASS: Smithy() had the correct number of cards in the hand %i of %i times\n", results.correctNumInHand, i);
	}

	//print results for if the correct number of cards in the played cards deck at the end of the turn
	if(results.correctNumInPlayed < i)
	{
		printf("FAIL: Smithy() had the correct number of cards in the Played Cards at the end %i times\n", results.correctNumInPlayed, i);
	}
	else
	{
		printf("PASS:  Smithy() had the correct number of cards in the Played Cards at the end %i times\n", results.correctNumInPlayed, i);
	}

	//print result for if the correct number of smithies were in the played card deck at the end of the turn
	if(results.correctSmithyInPlayed < i)
	{
		printf("FAIL: Smithy() had the correct number of Smithies in the played Cards %i of %i times\n", results.correctSmithyInPlayed, i);
	}
	else
	{
		printf("PASS: Smithy() had the correct number of Smithies in the played Cards %i of %i times\n", results.correctSmithyInPlayed, i);
}
	return;
}

int main()
{
	randomtestcard();
	return 0;
}

/*
int smithy_effect(struct gameState *state, int currentPlayer, int handPos)
{
  
  return 0;
}

*/