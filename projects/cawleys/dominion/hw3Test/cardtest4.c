//tests great hall -- should be +1 card, +1 action

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dominion.h"
#include "assert.h"
#include "cardtest3.h"


int testGreatHall(struct gameState *state, int handPos)
{	
	//number of errors to return
	int errors = 0;

	//number of cards before village_effect was called
	int p0NumInHand1 = state->handCount[0];
	int p1NumInHand1 = state->handCount[1];

	int p0NumInDeck1 = state->deckCount[0];
	int p1NumInDeck1 = state->deckCount[1];

	//number of actions for player 0
	int actions1 = state->numActions;

	//call function to change the state of the game, 0 is for player 0
	great_hall_effect(state, 0,handPos);

//number of cards in hand should be the same after the card is added and then discarded
	if(state->handCount[0] == p0NumInHand1)
	{
		printf("PASS: great_hall() Player 0 has the same number of cards before and after in their hand\n");
	}
	else
	{
		printf("Fail: great_hall() Player 0 does not have the same number of cards, there are now %i cards\n", (state->handCount[0]-p1NumInHand1));
		errors++;
	}
//tests that plaer 2 does not have extra cards
	if(state->handCount[1] == p1NumInHand1)
	{
		printf("PASS: great_hall() Player 1 has the same number of cards before and after in their hand\n");
	}
	else
	{
		printf("Fail: great_hall() Player 1 does not have the same number of cards, there are now %i cards\n", (state->handCount[0]-p1NumInHand1));
		errors++;
	}

//tests that card was taken from player 0s deck
	if(state->deckCount[0] == (p0NumInDeck1-1))
	{
		printf("PASS: great_hall() 1 card was taken from player 0's deck\n");
	}
	else
	{
		printf("Fail: great_hall() %i cards were taken from player 0's deck\n", (p1NumInDeck1 - state->deckCount[0]));
		errors++;
	}

//tests that card no cards were taken from player 1's deck
	if(state->deckCount[1] == (p1NumInDeck1))
	{
		printf("PASS: great_hall() 0 cards were taken from player 1's deck\n");
	}
	else
	{
		printf("Fail: great_hall() %i cards were taken from player 1's deck\n", (p1NumInDeck1 - state->deckCount[0]));
		errors++;
	}

//tests that action cards were added to player 0, after playing the card, there should be 1 actions available
	if(state->numActions == 1)
	{
		printf("PASS: great_hall() player 0 has the correct number of actions\n");
	}
	else
	{
		printf("FAIL: great_hall() player 0 should have 1 actions, but has %i\n", state->numActions);
		errors++;
	}


	return errors;

}

int cardtest4()
{
	struct gameState state;
	initState(&state);


	//set great hall to be in possition 5 of player 0's hand
	state.hand[0][5] = great_hall;

			//sending in 5 as the handPos of great_hall
	return testGreatHall(&state, 5);
}




/*
int great_hall_effect(struct gameState *state, int currentPlayer, int handPos)
{
  //+1 Card
  drawCard(currentPlayer, state);
                    
  //+1 Actions
  state->numActions--;
                    
  //discard card from hand
  discardCard(handPos, currentPlayer, state, 0);
  return 0;
}*/