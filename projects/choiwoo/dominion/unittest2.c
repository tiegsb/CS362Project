//Woo Choi
//unitest2.c

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// Test for isGameOver()
//int isGameOver(struct gameState *state)
/*
isGameOver uses supplyCount[province] to check if it's 0
	and checks to see if at least 3 supply piles are at 0.

struct gameState {
  int numPlayers; //number of players
  int supplyCount[treasure_map+1];  //this is the amount of a specific type of card given a specific number.
  int embargoTokens[treasure_map+1];
  int outpostPlayed;
  int outpostTurn;
  int whoseTurn;
  int phase;
  int numActions; // Starts at 1 each turn 
  int coins; // Use as you see fit! 
  int numBuys; // Starts at 1 each turn 
  int hand[MAX_PLAYERS][MAX_HAND];
  int handCount[MAX_PLAYERS];
  int deck[MAX_PLAYERS][MAX_DECK];
  int deckCount[MAX_PLAYERS];
  int discard[MAX_PLAYERS][MAX_DECK];
  int discardCount[MAX_PLAYERS];
  int playedCards[MAX_DECK];
  int playedCardCount;
};
*/


int main(){

	int p, i;
    struct gameState G;
	printf("******************\n");
	printf("unittest2.c\n");	
	printf("isGameOver() Test:\n");
	memset(&G, 23, sizeof(struct gameState)); 
	// test if game is over with province set to 0.
	printf("Testing End Game with provinces\n");
	G.supplyCount[province] = 0;
	p = isGameOver(&G);
	if ( p != 1)
		printf("Province count to 0 did not end game\n");
	
	// test if game is over with province set to 1
	G.supplyCount[province] = 1;
	p = isGameOver(&G);
	if ( p != 0)
		printf("Province count to 1 causes an unexpected error\n");

	// Test to see if 3 or more supplies == 0 ends game
	// Set the supplycounts of supplies to 1 
	G.supplyCount[province] = 1;
	for (i = 0; i < 25; i++)
    {
      G.supplyCount[i] = 1;
    }
	p = isGameOver(&G);
	if ( p != 0)
		printf("Unexpected error with game ending with supply counts\n");
	
	// Set 3 of supplies to 0;
	for (i = 0; i <3; i++)
	{
	  G.supplyCount[i] = 0;
	}
	p = isGameOver(&G);
	if ( p != 1)
		printf("Unexpected error with game NOT ending with Correct supply counts\n");
	
	// Set 2 of supplies to 0
	G.supplyCount[0] = 1;
	p = isGameOver(&G);
	if ( p != 0)
		printf("Unexpected error with game ending with incorrect supply counts\n");
	
	// Testing sufficient
	
	
	
	printf("isGameOver() Test is now Over\n\n");
	

	return 0;
}