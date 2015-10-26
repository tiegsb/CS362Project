/**************************************************************************************
File Name: unittest4.c
Created by: Wisam Thalij
Date created: 10-20-2015
Last Modified: 10-20-2015

Description: This file is a test unit fot gainCard() in dominion.c, The program will
first create a new game, set hand, deck and discard counts to 5, set all the card for
hand, deck and dicard to copper for testing purposes.
The program will set the toFlag to (0,1 and 2) and test it gainCard:
1) added a new card to the hand, deck or discard piles
2) added the value of copper (1) to the total count of coins in each pile( expected 6 each)
3) decreased the number of Supplycount once it uses the card.
**************************************************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

void testGainCard() {

// Initial game values
int seed = 1000;
int numPlayer = 2;
int player = 0;
int game = 0;
int i;
int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
int totalCoins = 0;

// Create a temp game state
struct gameState tempGame;

// clear the game state
memset(&tempGame, 23, sizeof(struct gameState));

// initialize a new game
game = initializeGame(numPlayer, k, seed, &tempGame); 


printf ("\n****************************************************************\n");
printf ("TESTING gainCard():\n");

// Intialize the player 0 handscount, decCount and discardCount
tempGame.handCount[player]= 5;
tempGame.deckCount[player] = 5;
tempGame.discardCount[player] = 5;

// Initialize the supply pile count to 20 cards
tempGame.supplyCount[copper] = 20; 

/******************************************************************************************
							toFlag = 0 : add to discard
Will be testing two value for each toflag:
1) if the gainCard() added new card to discard pile (discardCount[player] = 6)
2) if the gainCard() added the card value to the discard total coins
*******************************************************************************************/

// Initialize all the discard pile to be copper (total coins = 5)
for (i = 0; i < tempGame.discardCount[player] ; i++)
{
  tempGame.discard[player][i] = copper;
}

// Testing gainCard for the discard pile with one copper card added
gainCard(copper, &tempGame, 0, player);

// Calculate the total number of coins for discard pile after adding the card
// Ecpected value to be = 6
for (i = 0; i < tempGame.discardCount[player] ; i++)
{
	if (tempGame.discard[player][i] == copper)
	{
		totalCoins++;
	}
}

// Ckeck it discard count increased and the card value added to the discard total coins
if (tempGame.discardCount[player] == 6)
{
	printf ("The gainCard() Added new card to the discard pile, PASSED!\n");
	if (totalCoins == 6)
	{
		printf ("The gainCard() added the value of the gained card (copper) to the total coins in the discard pile, PASSED\n");
		printf ("Total coins now = %d\n", totalCoins);
	} else
	{
		printf ("The gainCard() FAILED to add the correct card to total coins, coins = %d\n", totalCoins);
	}
} else
{
	printf ("The gainCard() Did NOT add a new card to the discard pile, FAILED!\n");
}

assert(tempGame.discardCount[player] == 6);
assert(totalCoins == 6);

if (tempGame.supplyCount[copper] == 19)
{
	printf ("The gainCard() decreased the supplyCount by one!, PASSED\n");
} else
{
	printf ("The gainCard() did NOT decrease the supplyCount by one!, FAILED\n");
}
assert(tempGame.supplyCount[copper] == 19);


/******************************************************************************************
							toFlag = 1 : add to deck
Will be testing two value for this toflag:
1) if the gainCard() added new card to deck pile (deckCount[player] = 6)
2) if the gainCard() added the card value to the deck total coins
*******************************************************************************************/

// Initialize the supply pile count to 20 cards
tempGame.supplyCount[copper] = 20; 
totalCoins = 0;

// Initialize all the deck pile to be copper (total coins = 5)
for (i = 0; i < tempGame.deckCount[player] ; i++)
{
  tempGame.deck[player][i] = copper;
}

// Testing gainCard for the deck pile with one copper card added
gainCard(copper, &tempGame, 1, player);

// Calculate the total number of coins for deck pile after adding the card
// Ecpected value to be = 6
for (i = 0; i < tempGame.deckCount[player] ; i++)
{
	if (tempGame.deck[player][i] == copper)
	{
		totalCoins++;
	}
}

// Ckeck it deck count increased and the card value added to the deck total coins
if (tempGame.deckCount[player] == 6)
{
	printf ("The gainCard() Added new card to the deck pile, PASSED!\n");
	if (totalCoins == 6)
	{
		printf ("The gainCard() added the value of the gained card (copper) to the total coins in the deck pile, PASSED\n");
		printf ("Total coins now = %d\n", totalCoins);
	} else
	{
		printf ("The gainCard() FAILED in DECK test with total coins : %d\n", totalCoins);
	}
} else
{
	printf ("The gainCard() Did NOT add a new card to the deck pile, FAILED!\n");
}

assert(tempGame.deckCount[player] == 6);
assert(totalCoins == 6);

if (tempGame.supplyCount[copper] == 19)
{
	printf ("The gainCard() decreased the supplyCount by one!, PASSED\n");
} else
{
	printf ("The gainCard() did NOT decrease the supplyCount by one!, FAILED\n");
}

assert(tempGame.supplyCount[copper] == 19);
/******************************************************************************************
							toFlag = 2 : add to hand
Will be testing two value for this toflag:
1) if the gainCard() added new card to player hand (handCount[player] = 6)
2) if the gainCard() added the card value to the hand total coins
*******************************************************************************************/

// Initialize the supply pile count to 20 cards
tempGame.supplyCount[copper] = 20; 
totalCoins = 0;

// Initialize all the player hand to be copper (total coins = 5)
for (i = 0; i < tempGame.handCount[player] ; i++)
{
  tempGame.hand[player][i] = copper;
}

// Testing gainCard for the hand cards with one copper card added
gainCard(copper, &tempGame, 2, player);

// Calculate the total number of coins in the player's hand after adding the card
// Ecpected value to be = 6
for (i = 0; i < tempGame.handCount[player] ; i++)
{
	if (tempGame.hand[player][i] == copper)
	{
		totalCoins++;
	}
}

// Ckeck it deck count increased and the card value added to the deck total coins
if (tempGame.handCount[player] == 6)
{
	printf ("The gainCard() Added new card to the player hand, PASSED!\n");
	if (totalCoins == 6)
	{
		printf ("The gainCard() added the value of the gained card (copper) to the total coins in the player's hand, PASSED\n");
		printf ("Total coins now = %d\n", totalCoins);
	} else
	{
		printf ("The gainCard() FAILED in HAND test with total coins : %d\n", totalCoins);
	}
} else
{
	printf ("The gainCard() Did NOT add a new card to the player hand, FAILED!\n");
}

assert(tempGame.handCount[player] == 6);
assert(totalCoins == 6);

if (tempGame.supplyCount[copper] == 19)
{
	printf ("The gainCard() decreased the supplyCount by one!, PASSED\n");
} else
{
	printf ("The gainCard() did NOT decrease the supplyCount by one!, FAILED\n");
}

assert(tempGame.supplyCount[copper] == 19);

}

int main() {

	testGainCard();

	return 0;
}
