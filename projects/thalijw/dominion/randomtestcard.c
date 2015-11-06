/**************************************************************************************
File Name: randomtestcard.c
Created by: Wisam Thalij
Date created: 10-29-2015
Last Modified: 10-29-2015

Description: This file is a random test unit for Baron card effect, The program
will initialize a game, initialize a random input for the game, Save a copy of the game
state, preform baron card action on one of the games by calling the cardEffect() function
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

void RandBaronTest(struct gameState *post, int player, int * FirstPlayerNumCoins, int Choice, int * NumOfMatchGame, int * NumOfNotMatchGame) {

// Create a temp game state to store the pre state of the game 
struct gameState PreGame;

// Save the state of the game for later comparision
memcpy(&PreGame, post, sizeof(struct gameState));

int t;
int k;
int Firstplayer = 0;
int Secondplayer = 1;
int PostNewNumBuy;
int PreGameNewNumBuy;
// Save the number of buys for the current player
int PostOldNumBuy = post->numBuys ;
int PreGameOldNumBuy = PreGame.numBuys;
int PostTotalcoinsBeforeGame = post->coins ;
int PostTotalcoinsAfterGame;
int test = 0;

// Save the number of estatecards in the player's hand
int OldHandEstateCards = 0;
for(k = 0; k < 100 ; k++)
{
	if (post->hand[Firstplayer][k] == estate)
		OldHandEstateCards +=1;
}
// Save the number of estate cards in the discarded pile
int OldDiscardEstateCards = 0;
for(k = 0; k < post->discardCount[Firstplayer] ; k++)
{
	if (post->discard[Firstplayer][k] == estate)
		OldDiscardEstateCards +=1;
}

if (Choice == 1) {

	// Call the card effect on the card
	int statusEFFECT = cardEffect(baron, Choice, -1, -1, post, 1, 0);

	PostNewNumBuy = post->numBuys ;
	PostTotalcoinsAfterGame = post->coins;
	if (PostNewNumBuy == PostOldNumBuy + 1) 
	{
		printf("A +Buy has been added, PASSED!\n");
	} else {
		printf("A +Buy has NOT been added, FAILED!\n");
	}

	if (PostTotalcoinsAfterGame == PostTotalcoinsBeforeGame + 4)
	{
		test +=1;
		printf("A +4 coins had been added to the player's state coins, PASSED!\n");
	} else {
		printf("Did Not add +4 coins to the player's state coins, FAILED!\n");
	}

	// Get the number of estatecards in the player's hand
	int NewHandEstateCards = 0;
	for(k = 0; k < post->handCount[Firstplayer] ; k++)
	{
		if (post->hand[Firstplayer][k] == estate)
			NewHandEstateCards +=1;
	}
	// Get the number of estate cards in the discarded pile
	int NewDiscardEstateCards = 0;
	for(k = 0; k < post->discardCount[Firstplayer] ; k++)
	{
		if (post->discard[Firstplayer][k] == estate)
			NewDiscardEstateCards +=1;
	}

	if (NewDiscardEstateCards == OldDiscardEstateCards + 1){
		printf("One Estate card added to the Discard pile, PASSED!\n");
	} else {
		printf("Did NOT add Estate card to the Discard pile, FAILED!\n");
	}

	if (NewHandEstateCards == OldHandEstateCards -1) {
		printf("One Estate card discarded from the player's hand, PASSED!\n");
	} else {
		printf("Did not discard one Estate card from the player's hand, FAILED!\n");
	}

} else if (Choice == 0) {

	// Call the card effect on the card
	int statusEFFECT = cardEffect(baron, Choice, -1, -1, post, 1, 0);

	PostNewNumBuy = post->numBuys ;
	PostTotalcoinsAfterGame = post->coins;

	if (PostNewNumBuy == PostOldNumBuy + 1) 
	{
		printf("A +Buy has been added, PASSED!\n");
	} else {
		printf("A +Buy has NOT been added, FAILED!\n");
	}

	if (PostTotalcoinsAfterGame == PostTotalcoinsBeforeGame )
	{
		printf("The total Number of coins stayed the same, PASSED!\n");
	} else {
		printf("The total Number of coins stayed Changed, FAILED!\n");
	}
	// Get the number of estatecards in the player's hand
	int NewHandEstateCards = 0;
	for(k = 0; k < post->handCount[Firstplayer] ; k++)
	{
		if (post->hand[Firstplayer][k] == estate)
			NewHandEstateCards +=1;
	}
	// Get the number of estate cards in the discarded pile
	int NewDiscardEstateCards = 0;
	for(k = 0; k < post->discardCount[Firstplayer] ; k++)
	{
		if (post->discard[Firstplayer][k] == estate)
			NewDiscardEstateCards +=1;
	}

	if (NewDiscardEstateCards == OldDiscardEstateCards + 1){
		printf("One Estate card added to the Discard pile, PASSED!\n");
	} else {
		printf("Did NOT add Estate card to the Discard pile, FAILED!\n");
	}

	if (NewHandEstateCards == OldHandEstateCards ) {
		printf("Nothing Changed in the player's hand, PASSED!\n");
	} else {
		printf("Number of player's hand did not match (Changed), FAILED!\n");
	}

}

// Now we will change the PreGame
// Add +Buy
PreGame.numBuys +=1;
if (Choice == 1) 
{
	int s;
	int CardNotDiscarded = 1;
	while(CardNotDiscarded)
	{
		// If we found estate card in hand
		if (PreGame.hand[Firstplayer][s] == estate)
		{
			//Add 4 coins to the amount of coins
	    	PreGame.coins += 4;
	    	PreGame.discard[Firstplayer][PreGame.discardCount[Firstplayer]] = PreGame.hand[Firstplayer][s];
	    	PreGame.discardCount[Firstplayer]+=1;
	    	for (s = 0 ;s < PreGame.handCount[Firstplayer]; s++)
	    	{
	      		PreGame.hand[Firstplayer][s] = PreGame.hand[Firstplayer][s+1];
	    	}
	    	PreGame.hand[Firstplayer][PreGame.handCount[Firstplayer]] = -1;
	    	PreGame.handCount[Firstplayer]--;
	    	CardNotDiscarded = 0;
	  	} else if (s > PreGame.handCount[Firstplayer])
	  	{
	    	if (supplyCount(estate, &PreGame) > 0)
		    {
		    	gainCard(estate, &PreGame, 0, Firstplayer);
		      	PreGame.supplyCount[estate]--;
		      	if (supplyCount(estate, &PreGame) == 0)
		      	{
					isGameOver(&PreGame);
		      	}
		    }
		    CardNotDiscarded = 0;
		} else
	  	{
		  	//Next card
		    s++;
	  	}
	}
} else
{
	// Case Choice = 0
	// Only add one estate card to the player's dicard pile
	if (supplyCount(estate, &PreGame) > 0)
	{
		gainCard(estate, &PreGame, 0, Firstplayer);
		PreGame.supplyCount[estate]--;
		if (supplyCount(estate, &PreGame) == 0)
		{
			isGameOver(&PreGame);
		}
	}
}

if (memcmp(&PreGame, post, sizeof(struct gameState)) == 0) {
	printf("The Two game states after calling the card matched! PASSED\n");
	*NumOfMatchGame += 1; 
} else {
	printf("The Two game states after calling the card matched! FAILED!\n");
	*NumOfNotMatchGame +=1;
}
 printf("\ntest result is %d\n",test );
}

int main() {

	// Initialize what will be the pre game 
    int Handcount, Deckcount, Discardcount;
    int i, j, n, p, r;
    int Firstplayer = 0;
	int Secondplayer = 1;

 	struct gameState newGame;
 	// Set variable for checking the game
 	int NumOfMatchGame;
 	int NumOfNotMatchGame;
 	int FirstPlayerNumCoins;
 	int Choice; 
 	int ChoiceA = 0;
 	int ChoiceB = 0;

 	SelectStream(2);
 	PutSeed(3);

 	printf ("Random Testing for Baron card\n");
 	printf ("\n****************************************************************\n");

 	// Set random values to the game state
 	for (n = 0; n < 1000; n++)
 	{
 		// Initialize a random game state
 		for(i = 0 ; i < sizeof(struct gameState); i++)
 		{
 			((char*)&newGame)[i] = floor(Random() * 256);
  		}
  		// Set Random player, deckCount, discardCount and handCount
   		p = (int)(Random() * 2);
		newGame.deckCount[Firstplayer] = (int)(Random() * MAX_DECK);
		newGame.discardCount[Firstplayer] = (int)(Random() * MAX_DECK);
		newGame.handCount[Firstplayer] = (int)(Random() * MAX_HAND);

		//printf("newGame.deckCount[p](%d) and newGame.discardCount[p] (%d) and newGame.handCount[p](%d)\n",newGame.deckCount[Firstplayer] ,newGame.discardCount[Firstplayer], newGame.handCount[Firstplayer]);

		// // Initilaze Random input for player's hand cards, deck cards and discard cards
		for (j = 0; j < newGame.handCount[p] ; j++)
		{
		  newGame.hand[Firstplayer][j] = (int)(Random() * 20);
		  //newGame.hand[Secondplayer][j] = (int)(Random() * 20);
		}
		for (j = 0; j < newGame.discardCount[p] ; j++)
		{
		  newGame.discard[Firstplayer][j] = (int)(Random() * 20);
		  //newGame.discard[Secondplayer][j] = (int)(Random() * 20);
		}
		for (j = 0; j < newGame.deckCount[p] ; j++)
		{
		  newGame.deck[Firstplayer][j] =  (int)(Random() * 20);
		  //newGame.deck[Secondplayer][j] =  (int)(Random() * 20);
		}
		// limit the random selection to fit the cardEffect fucntion
		newGame.hand[Firstplayer][1] = baron;
		newGame.whoseTurn = 0;
		newGame.supplyCount[estate] = (int)(Random() * 10);
		Choice = rand() % 2 ;
		if (Choice == 0)
			ChoiceA +=1;
		else
			ChoiceB	+=1;
		
	 	// Call The random test function
		RandBaronTest(&newGame, p, &FirstPlayerNumCoins, Choice, &NumOfMatchGame, &NumOfNotMatchGame);
		printf ("\n****************************************************************\n");

 	}

 	printf ("\n************************ Final Results ***************************\n");
 	printf("Number of matched games = %d\n", NumOfMatchGame);
 	printf("Number of Not matched games = %d\n", NumOfNotMatchGame);
 	printf("The Number of cases where we chose to discard estate card and gain +4 is : %d\n", ChoiceB);
 	printf("The Number of cases where we chose to gain s estate card : %d\n", ChoiceA);
 	printf ("\n******************************************************************\n");

	return 0;
}
