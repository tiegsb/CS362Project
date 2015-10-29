/**************************************************************************************
File Name: unittest2.c
Created by: Wisam Thalij
Date created: 10-20-2015
Last Modified: 10-20-2015

Description: This file is a test unit fot fullDeckCount() in dominion.c, The program will
first create a new game, set the full deck card counts( Player hand cards = 5, deck =10 )
and discard pile =10, then will set all the cards to value zero except for one card in 
each pile to 1, Then call the function to make sure the Count for Card(0) = 22 and 
the Count for card(1) = 3
**************************************************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

void testFullDeckCount() {

// Initial game values
int seed = 1000;
int numPlayer = 2;
int player = 0;
int game = 0;
int i;
int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};

// Create a temp game state
struct gameState tempGame;

// clear the game state
memset(&tempGame, 23, sizeof(struct gameState));

// initialize a new game
game = initializeGame(numPlayer, k, seed, &tempGame); 


printf ("\n****************************************************************\n");
printf ("TESTING fullDeckCount():\n");

// intialize the player 0 handscount, decCount and discardCount
tempGame.handCount[player]= 5;
tempGame.deckCount[player] = 10;
tempGame.discardCount[player] = 10;

int testCard = 1;
int testCount = 0;

// Initilaze all player hand to card zero except one of test card 1
for (i = 0; i < tempGame.handCount[player] -1 ; i++)
{
  tempGame.hand[player][i] = 0;
}
tempGame.hand[player][4] = 1;

// Initilaze the deck cards to card zero except one of test card 1
for (i = 0; i < tempGame.deckCount[player] -1 ; i++)
{
  tempGame.deck[player][i] = 0;
}
tempGame.deck[player][9] = 1;

// Initilaze the dicard cards to card zero except one of test card 1
for (i = 0; i < tempGame.discardCount[player] -1 ; i++)
{
  tempGame.discard[player][i] = 0;
}
tempGame.discard[player][9] = 1;

// Get the count of the testCard # Should be 3
testCount = fullDeckCount(player, testCard, &tempGame);

printf ("The Count returned from fullDeckCount for Card (1) is : %d\n", testCount);
printf ("The expected count from fullDeckCount for Card (1) is : 3\n");

if (testCount == 3)
{
  printf ("The fullDeckCount() test PASSED with matching counts\n");
} else
{
  printf ("The fullDeckCount() test FAILED with unmatching counts\n");
}

assert(testCount == 3);

// Get the count of the testCard # Should be 22
testCount = fullDeckCount(player, 0, &tempGame);

printf ("The Count returned from fullDeckCount for Card (0) is : %d\n", testCount);
printf ("The expected count from fullDeckCount for Card (0) is : 22\n");

if (testCount == 22)
{
  printf ("The fullDeckCount() test PASSED with matching counts\n");
} else
{
  printf ("The fullDeckCount() test FAILED with unmatching counts\n");
}

assert(testCount == 22);
}

int main() {

	testFullDeckCount();

	return 0;
}
