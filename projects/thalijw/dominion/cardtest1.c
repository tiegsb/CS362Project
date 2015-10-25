/**************************************************************************************
File Name: cardtest1.c
Created by: Wisam Thalij
Date created: 10-21-2015
Last Modified: 10-21-2015

Description: This file is a test unit fot Smithy Card in dominion.c, The test will
first create a new game, set the countof the palyer's hand cards to 5 cards, then test
to make sure the outcome of playing the Smithy card is correct.
**************************************************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

void SmithyCardTest() {

// Initial game values
int seed = 1000;
int numPlayer = 2;
int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
int player = 0;
int game = 0;
int bonus = 0;

// variables to test the game
int handPos = 0;

// Create a temp game state
struct gameState tempGame;

// clear the game state
memset(&tempGame, 23, sizeof(struct gameState));

// initialize a new game
game = initializeGame(numPlayer, k, seed, &tempGame); 
printf ("\n************************************************************************\n");
printf ("TESTING Smithy Card:\n");

/*************************************************************************************
				            	           Smithy Card Test
Expected Effect from plaing the card:
1) Add 3 cards to the current player hand count ( new hand Count = old hand count + 3)
2) Discard the smithy card from the hand ( new hand Count = old hand count + 2) and 
Initial handCount will be 5 and Expected handCount after playing Smithy is 7
*************************************************************************************/

// intialize the player 0 handscount to 5 to test against
tempGame.handCount[player] = 5;

// Get the pre card effect handCount for testing
int oldHandCount = tempGame.handCount[player];

// Call cardEffect() to play add the card effect to the game state.
cardEffect(smithy, -1, -1, -1, &tempGame, handPos, &bonus);

// Get the post card effect handCount for testing
int NewHandCount = tempGame.handCount[player];

// testing adding three card to the player's hand
if (NewHandCount == oldHandCount + 2)
{
  printf ("Smithy added 3 cards to the hand and discarded the one played, PASSED\n");
  printf ("Player hand Count before smithy was: %d\n", oldHandCount);
  printf ("Player hand Count After smithy is: %d\n", NewHandCount);
} else
{
  printf ("Smithy did NOt add the correct number of cards to the hand1, FAILED\n");
}

assert(NewHandCount == oldHandCount + 2);

// testing if smithy card has been trashed or discarded
if (tempGame.playedCardCount == 2)
{
  printf ("The Smithy Card has been successfully added to the played pile, PASSED\n");
  printf ("Played pile count before playing the card = 1\n");
  printf ("Played pile count After playing the card = %d\n", tempGame.playedCardCount);
} else
{
  printf ("The Smithy Card has been discarded and not added to the played pile, FAILED\n");
  printf ("Played pile count before playing the card = 1\n");
  printf ("Played pile count After playing the card = %d\n", tempGame.playedCardCount);
}

//assert(tempGame.playedCardCount == 2);

}


int main() {

	SmithyCardTest();

	return 0;
}
