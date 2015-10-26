//tests the adventurer card

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dominion.h"
#include "assert.h"
#include "cardtest1.h"

int countCoins(struct gameState *state, int player)
{
	//size of array of cards in hand
	int handSize = state->handCount[player];
	int i =0;
	int coins = 0;

	for (i=0; i<handSize; ++i)
	{
		if(state->hand[0][i] == gold || state->hand[0][i] == copper || state->hand[0][i] == silver)
		{
			++coins;
		}
	}

	return coins;

}


int testAdventurer(struct gameState *state, int player, int numInHand, const char* message)
{
	//add one to the hand to see if the total ends up being the same
	numInHand ++;
	int errors = 0;

	//get number of coins in current state before more are drawn for test2
	int coins1 = countCoins(state, 0);
	//get number of coins in player 2's hand to start
	int  p2coins1 = countCoins(state, 1);
	//to get number of in player 0's deck to start
	int p0hand1 = state->handCount[0];

//call adventurer to change to state for all tests;
	adventurer_effect(state, 0);


//test to see if player 0 has 1 more card in their hand (2 new cards - adventurer)
	errors += assert( state->handCount[player] == numInHand, "Adventurer()", message);
	printf("       %i cards in hand\n", state->handCount[0]);
	
//test to see if player 0 has more 2 more coin cards
	int coins2 = countCoins(state, 0);
	
	if((coins1+2) == coins2)
	{
		printf("PASS: Adventurer added 2 new coin cards to the hand\n");
	}
	else
	{
		printf("FAIL: Adventurer added %i new coin cards to the hand\n", (coins2-coins1));
		printf("    There were %i coins before adventurer and %i coins after\n", coins1, coins2);
		++errors;
	}

//test to see if player 2 has more cards in their hand
	//get number of coins in player 2's hand
	int  p2coins2 = countCoins(state, 1);
	if(p2coins1 == p2coins2)
	{
		printf("PASS: adventurer() did not add any coin cards to player 2\n");
	}
	else
	{
		printf("FAIL: adventurer added %i coins to player 2's hand", (p2coins2 - p2coins1));
		++errors;
	}

//test that cards were taken from player 0's deck
	//get number of cards in deck
	int p0hand2 = state->handCount[0];

	if(p0hand2 > p0hand1)
	{
		printf("PASS: Adventurer() player 0 had %i cards in thier deck before and %i after\n", p0hand1, p0hand2);
	}
	else
	{
		printf("FAIL: Adventurer() player 0 had %i cards in thier deck before and %i after\n", p0hand1, p0hand2);
		++errors;
	}

	return errors;
}


int cardtest2()
{
	struct gameState state;
	initState(&state);

	state.deck[0][0] = silver;
	state.deck[0][1] = estate;
	state.deck[0][2] = gold;
	state.deck[0][3] = copper;
	state.deck[0][4] = estate;
	

	int failcount = 0;

	//takes the state, the # for the current payer (0), the number of cards starting in the hand (6)
	failcount += testAdventurer( &state, 0, 6, "This hand started with 6, should now have 7");

	return failcount;
}

/*

int adventurer_effect(struct gameState *state, int currentPlayer)
{
  int drawntreasure=0;
  int cardDrawn;
  int temphand[MAX_HAND];
  int z = 0;

  while(drawntreasure<3){
    if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
      shuffle(currentPlayer, state);
    }
    drawCard(currentPlayer, state);
    cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
    if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
      drawntreasure++;
    else{
      temphand[z]=cardDrawn;
      state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
      z++;
    }
  }

  while(z-1>=0){
    state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
    z=z-1;
  }
  return 0; 
  */

