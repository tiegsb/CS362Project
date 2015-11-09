/**************************************************************************************
File Name: randomtestadventurer.c
Created by: Wisam Thalij
Date created: 10-28-2015
Last Modified: 10-29-2015

Description: This file is a random test uint for the adventurer card effect. The program
will initialize a game, initialize a random input for the game, Save a copy of the game
state, preform adventurer card action on one of the games by calling the refactored function
, preform the card action manually on the second game state and compare the results at the
end.
**************************************************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int RandAdventurerTest(struct gameState *post, int player, int * NumOfMatchGame, int * NumOfNotMatchGame, int * NumOfMatchHandCount, int * NumOfMatchDeckCount , int * NumOfMatchDiscardCount, int * NumOfMatchCoins)
{

	// Create a temp game state to store the pre state of the game 
	struct gameState PreGame;

	// Save the state of the game for later comparision
	memcpy(&PreGame, post, sizeof(struct gameState));

	// initialize the refactored function variables
	int drawntreasure = 0;
	int z = 0;
	int cardDrawn = 0;
	int temphand[MAX_HAND];
	int k;
	int PostGameBeforeCount, PostGameAfterCount;
	int PreGameBeforeCount, PreGameAfterCount;

	// Count the number of coins (tresure cards) in the players hand before the card effect
	PostGameBeforeCount = 0;
	for(k = 0; k < post->handCount[player] ; k++)
	{
		if (post->hand[player][k] == copper)
			PostGameBeforeCount ++;
		else if (post->hand[player][k] == silver)
			PostGameBeforeCount +=2;
		else
			PostGameBeforeCount +=3;
	}

	printf("Player's Hand has (%d) coins before playing Adventurer card\n", PostGameBeforeCount);


	// Call the card Effect refactored function for the adventurer on the post game
	int status = adventurer_refactor(drawntreasure, post, temphand, z, cardDrawn, player );

	// Count the number of coins after the card effect
	PostGameAfterCount = 0;
	for(k = 0; k < post->handCount[player] ; k++)
	{
		if (post->hand[player][k] == copper)
			PostGameAfterCount ++;
		else if (post->hand[player][k] == silver)
			PostGameAfterCount +=2;
		else
			PostGameAfterCount +=3;
	}
	printf("Player's Hand has (%d) coins after playing Adventurer card\n", PostGameAfterCount);


	// Count the number of coins for the saved game state (PreGame)
	PreGameBeforeCount = 0;
	for(k = 0; k < PreGame.handCount[player] ; k++)
	{
		if (PreGame.hand[player][k] == copper)
			PreGameBeforeCount ++;
		else if (PreGame.hand[player][k] == silver)
			PreGameBeforeCount +=2;
		else
			PreGameBeforeCount +=3;
	}
	printf("PreGame: Player's Hand has (%d) coins before adding the card effect\n", PreGameBeforeCount);
	

	// Set the preGame state to gain two tresure cards and check if the two states match at the end
	drawntreasure = 0;
	z = 0;
	cardDrawn = 0;
	temphand[MAX_HAND];
	memset(temphand, 0, sizeof temphand);

    // The following code preforms the drawCard() and the Adventure cardEfect()
    while(drawntreasure < 2)
    {
    	if (PreGame.deckCount[player] <1){//if the deck is empty we need to shuffle discard and add to deck
	      shuffle(player, &PreGame);
	    }
    	// The drawCard()
    	// If the player's deck not empty, then draw a card and add it to the hand
    	// else add the discarded pile to the players deck and add one card to the hand
    	if(PreGame.deckCount[player] > 0)
    	{
    		PreGame.handCount[player]++;
    		PreGame.hand[player][PreGame.handCount[player]-1] = PreGame.deck[player][PreGame.deckCount[player]-1];
    		PreGame.deckCount[player]--;
    	} else if (PreGame.discardCount[player] > 0) {
    		memcpy(PreGame.deck[player], post->deck[player] , sizeof(int) * PreGame.discardCount[player]);
    		memcpy(PreGame.discard[player], post->discard[player] , sizeof(int) * PreGame.discardCount[player]);
    		PreGame.hand[player][post->handCount[player]-1] = post->hand[player][post->handCount[player]-1];
    		PreGame.handCount[player]++;
    		PreGame.deckCount[player] = PreGame.discardCount[player]-1;
    		PreGame.discardCount[player] = 0;
    	}
    	// Get the card drawn and check if it's a tresure card, if it is leave it in hand
    	// else add it to a list to discard later
    	cardDrawn = PreGame.hand[player][PreGame.handCount[player]-1];
	    if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
	      drawntreasure++;
	    else{
	      temphand[z] = cardDrawn;
	      PreGame.handCount[player]--;
	      z++;
	    }
	    // Discard all cards that is not a tresure cards
	    while(z-1>=0){
		    PreGame.discard[player][PreGame.discardCount[player]++]=temphand[z-1]; // discard all cards in play that have been drawn
		    z=z-1;
        }	
    }

    // Count the number of coins after adding the card effect
    PreGameAfterCount = 0;
	for(k = 0; k < PreGame.handCount[player] ; k++)
	{
		if (PreGame.hand[player][k] == copper)
			PreGameAfterCount ++;
		else if (PreGame.hand[player][k] == silver)
			PreGameAfterCount +=2;
		else
			PreGameAfterCount +=3;
	}

	printf("PreGame: Player's Hand has (%d) coins before adding the card effect\n", PreGameAfterCount);

	if (PreGameAfterCount == PostGameAfterCount) {
		*NumOfMatchCoins += 1;
		printf("PreGame and Post have the same number of coins after playing the card, Test PASSED!\n");
	} else
		printf("PreGame and Post number of coins Didn't match, Test FAILED!\n");

	if (post->handCount[player] == PreGame.handCount[player]){
		*NumOfMatchHandCount += 1;
		printf("PreGame and Post have the same Hand count after playing the card, Test PASSED!\n");
	} else
		printf("PreGame and Post Hand count Didn't match, Test FAILED!\n");

	if (post->deckCount[player] == PreGame.deckCount[player]) {
		*NumOfMatchDeckCount += 1;
		printf("PreGame and Post have the same Deck count after playing the card, Test PASSED!\n");
	} else
		printf("PreGame and Post Deck count Didn't match, Test FAILED!\n");

	if (post->discardCount[player] == PreGame.discardCount[player]) {
		*NumOfMatchDiscardCount += 1;
		printf("PreGame and Post have the same Discard count after playing the card, Test PASSED!\n");
	} else
		printf("PreGame and Post Discard count Didn't match, Test FAILED!\n");

	if (memcmp(&PreGame, post, sizeof(struct gameState)) == 0){
		*NumOfMatchGame += 1;
		printf("\n The Two game state Matched!\n");
	} else {
		*NumOfNotMatchGame += 1;
		printf("\n The Two game state Matched DID NOT Match !!!\n");
	}
		

	printf ("\n****************************************************************\n");
	return 0;
}
int main() {

	// Initialize what will be the pre game 
	// int k[10] = {adventurer, council_room, feast, gardens, mine
 	//               , remodel, smithy, village, baron, great_hall};
    int Handcount, Deckcount, Discardcount;
    int i, j, n, p, r;

 	struct gameState newGame;
 	int NumOfMatchGame;
 	int NumOfNotMatchGame;
 	int NumOfMatchHandCount;
 	int NumOfMatchDeckCount;
 	int NumOfMatchDiscardCount;
 	int NumOfMatchCoins;

 	SelectStream(2);
 	PutSeed(3);

 	printf ("Random Testing for adventurer card\n");
 	printf ("\n****************************************************************\n");

 	// Set random values to the game state
 	for (n = 0; n < 1000; n++)
 	{
 		// Initialize a random game state
 		for(i = 0 ; i < sizeof(struct gameState); i++)
 		{
 			((char*)&newGame)[i] = (int)(Random() * 256);
  		}
  		// Set Random player, deckCount, discardCount and handCount
  		p = (int)(Random() * 2);
		newGame.deckCount[p] = (int)(Random() * MAX_DECK);
		newGame.discardCount[p] = (int)(Random() * MAX_DECK);
		newGame.handCount[p] = (int)(Random() * MAX_HAND);

		// Initilaze Random input for player's hand cards, deck cards and discard cards
		for (j = 0; j < newGame.handCount[p] ; j++)
		{
		  newGame.hand[p][j] = (int)(Random() * 20);
		}
		for (j = 0; j < newGame.discardCount[p] ; j++)
		{
		  newGame.discard[p][j] = (int)(Random() * 20);
		}
		for (j = 0; j < newGame.deckCount[p] ; j++)
		{
		  newGame.deck[p][j] =  (int)(Random() * 20);
		}

	 	// Call The random test function
		RandAdventurerTest(&newGame, p, &NumOfMatchGame, &NumOfNotMatchGame, &NumOfMatchHandCount, &NumOfMatchDeckCount , &NumOfMatchDiscardCount, &NumOfMatchCoins);

 	}
 	printf ("\n************************ Final Results ***************************\n");
 	printf("Number of matched games = %d\n", NumOfMatchGame);
 	printf("Number of Not matched games = %d\n", NumOfNotMatchGame);
 	printf("Number of matched Handcounts = %d\n", NumOfMatchHandCount);
 	printf("Number of matched Deckcounts = %d\n", NumOfMatchDeckCount);
 	printf("Number of matched Discardcounts = %d\n", NumOfMatchDiscardCount);
 	printf("Number of matched Coins = %d\n", NumOfMatchCoins);
 	printf ("\n******************************************************************\n");
	return 0;
}
