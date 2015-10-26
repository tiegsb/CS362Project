/**************************************************************************************
File Name: unittest3.c
Created by: Wisam Thalij
Date created: 10-20-2015
Last Modified: 10-20-2015

Description: This file is a test unit fot scoreFor() in dominion.c, The program will
first create a new game, set hand count to 5 cards, deck count to 10 cards and the 
dicard pile to have 10 cards, the program will initialize the hand card to have ( 2 states,
2 duchy and 1 province) with total of 14 points, initialize the deck crads to be all states
with total of 10 and initialize the discard pile to be all states with total of 10 points.
The program then call scoreFor() to calculate the total number of points and test it 
against the number 34.
**************************************************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

void testScoreFor() {

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
printf ("TESTING scoreFor():\n");

// Intialize the player 0 handscount, decCount and discardCount
tempGame.handCount[player]= 5;
tempGame.deckCount[player] = 10;
tempGame.discardCount[player] = 10;

// Initialize the player hand cards to have total score of 14
tempGame.hand[player][0] = estate;
tempGame.hand[player][1] = estate;
tempGame.hand[player][2] = duchy;
tempGame.hand[player][3] = duchy;
tempGame.hand[player][4] = province;


// Initialize the player deck cards to have total score of 10
for (i = 0; i < tempGame.deckCount[player] ; i++)
{
  tempGame.deck[player][i] = estate;
}

// Initialize the player discard cards to have total score of 10
for (i = 0; i < tempGame.discardCount[player] ; i++)
{
  tempGame.discard[player][i] = estate;
}

// Calld the scoreFor() to calculate the total score for a player 0
// The expected score returned should be 14 + 10 + 10 = 34 points
int testScore = scoreFor(player, &tempGame);

printf ("The Score returned from scoreFor() is : %d\n", testScore);
printf ("The expected Score returned from scoreFor() is : 34\n");

if (testScore == 34)
{
  printf ("The scoreFor() test PASS with matching scores\n");
} else
{
  printf ("The scoreFor() test FAILED with unmatching scores\n");
}

assert(testScore == 34);
}

int main() {

	testScoreFor();

	return 0;
}
