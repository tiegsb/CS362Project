/**************************************************************************************
File Name: cardtest2.c
Created by: Wisam Thalij
Date created: 10-22-2015
Last Modified: 10-22-2015

Description: This file is a test unit fot Adventurer Card in dominion.c, The test will
first create a new game, set the count of the palyer's hand cards to 5 cards, initialize 
all to be copper for testing, then test to make sure the outcome of playing the adventurer
card is correct.
**************************************************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

void AdventurerCardTest() {

// Initial game values
int seed = 1000;
int numPlayer = 2;
int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
int player = 0;
int game = 0;
int i;

// Create a temp game state
struct gameState tempGame;

// clear the game state
memset(&tempGame, 23, sizeof(struct gameState));

// initialize a new game
game = initializeGame(numPlayer, k, seed, &tempGame); 
printf ("\n************************************************************************\n");
printf ("TESTING Adventurer Card:\n");

/*************************************************************************************
				            	   Adventurer Card Test
Expected Effect from plaing the card:
1) Add 2 treature cards to the current player hand count ( new hand Count = old hand count + 2)
2) The total value of players hand cards is > 5 
3) the discarded pile count > 5 (not treature card should be added to the discard pile)
*************************************************************************************/

// intialize the player 0 handscount to 5 to test against
tempGame.handCount[player] = 5;
tempGame.deckCount[player] = 5;
tempGame.discardCount[player] = 5;
// Initilaze all player hand to card Copper except one of test card 1
for (i = 0; i < tempGame.handCount[player] ; i++)
{
  tempGame.hand[player][i] = copper;
}

// initialize the refactored function variables
int drawntreasure = 0;
int z = 0;
int cardDrawn = 0;
int temphand[MAX_HAND];

// Get the pre card effect handCount for testing
int oldHandCount = tempGame.handCount[player];

// Get the pre card effect handCount for testing
adventurer_refactor(drawntreasure, &tempGame, temphand, z, cardDrawn, player );

// Get the post card effect handCount for testing
int NewHandCount = tempGame.handCount[player];

// Ckecing if the card added two cards to the hand
if (NewHandCount == oldHandCount+2)
{
	printf ("The Adventurer Card added two card to the player's hand, PASSES\n");
	printf ("Expected of Player hand Count = 7!\n");
	printf ("Outcome of Player hand Count = %d!\n", NewHandCount);
} else
{
	printf ("The Adventurer Card did NOT add two card to the player's hand, FAILED\n");
	printf ("Expected of Player hand Count = 7!\n");
	printf ("Outcome of Player hand Count = %d!\n", NewHandCount);
}

//assert(NewHandCount == 7);

// Checking if the added cards are a 'Treature' ones
int totalCoins = 0;

for (i = 0; i < tempGame.handCount[player] ; i++)
{
  if (tempGame.hand[player][i] == copper) 
  {
  	totalCoins++;
  } else if (tempGame.hand[player][i] == silver)
  {
  	totalCoins += 2;
  } else 
  {
  	totalCoins += 3;
  }
}

if (totalCoins > 5)
{
	printf ("The Adventurer added two Treature cards, PASSES\n");
	printf ("Total Hand coins before playing the cards (5 Copper = 5 Coins)\n");
	printf ("Total Hand coins after playing the cards = %d Coins\n", totalCoins);
} else
{
	printf ("The Adventurer did NOT add a Treature cards, FAILED\n");
	printf ("Total Hand coins before playing the cards (5 Copper = 5 Coins)\n");
	printf ("Total Hand coins after playing the cards = %d Coins\n", totalCoins);
}


//assert(totalCoins == 7);
// Checking the discard pile after playing the card
if (tempGame.discardCount[player] > 5)
{
	printf ("The Adventurer discarded the cardDrawn from hand and added to the discard pile, PASSES\n");
}	else 
{
	printf ("The Adventurer did not add the discarded card to the discard pile, FAILED\n");
}

}

int main() {

	AdventurerCardTest();

	return 0;
}
