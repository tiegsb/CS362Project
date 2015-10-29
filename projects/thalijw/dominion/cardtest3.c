/**************************************************************************************
File Name: cardtest3.c
Created by: Wisam Thalij
Date created: 10-22-2015
Last Modified: 10-22-2015

Description: This file is a test unit fot Steward Card in dominion.c, The test will
first create a new game, set the count of the palyer's hand cards to 5 cards, then 
test to make sure the outcome of playing the Steward card is correct.
**************************************************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

void StewardCardTest() {

// Initial game values
int seed = 1000;
int numPlayer = 2;
int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
int game = 0;
int player = 0;

// Create a temp game state
struct gameState tempGame;

// clear the game state
memset(&tempGame, 23, sizeof(struct gameState));

// initialize a new game
game = initializeGame(numPlayer, k, seed, &tempGame); 
printf ("\n************************************************************************\n");
printf ("TESTING Steward Card:\n");

/*************************************************************************************
				            Steward Card Test (Choice 1)
Expected Effect from plaing the card:
1) Add 2 cards to the current player's hand count +2
2) discard the card played from player's hand -1
results:
new hand Count = old hand count + 1
*************************************************************************************/

// intialize the player 0 handscount and playedCardCount to 5 to test against
tempGame.handCount[player] = 5;
tempGame.playedCardCount = 5; 

// initialize the refactored function variables
int handPos = 0;

// Get the pre card effect handCount for testing
int oldHandCount = tempGame.handCount[player];

// Playing Choice 1
steward_refactor(player, &tempGame, handPos, 1, -1, -1 );

// Get the post card effect handCount for testing
int NewHandCount = tempGame.handCount[player];

printf ("--------------------------------- Choice 1 ------------------------------\n");

if (NewHandCount == oldHandCount + 1)
{
	printf ("Steward Card Added two cards to the player's hand, PASSED\n");
	printf ("Expected total number of player's hand cards = 6\n");
	printf ("Outcome total number of player's hand cards = %d\n", NewHandCount);
} else
{
	printf ("Steward Card did NOT add two cards to the player's hand, FAILED\n");
	printf ("Expected total number of player's hand cards = 6\n");
	printf ("Outcome total number of player's hand cards = %d\n", NewHandCount);
}

assert(NewHandCount == 6);

if (tempGame.playedCardCount > 5)
{
	printf ("Steward Card discarded the played card and added it to the playedCardCount, PASSED\n");
	printf ("Expected total number of player's played cards = 6\n");
	printf ("Outcome of total number of player's hand cards = %d\n", tempGame.playedCardCount);
} else
{
	printf ("Steward Card did NOT add the played card to the playedCardCount, FAILED\n");
	printf ("Expected total number of player's played cards = 6\n");
	printf ("Outcome of total number of player's hand cards = %d\n", tempGame.playedCardCount);
}

assert(tempGame.playedCardCount == 6);
/*************************************************************************************
				            Steward Card Test (Choice 2)
Expected Effect from plaing the card:
1) Add 2 coins to the current player's total coins
2) discard the card played from player's hand -1
results:
new hand Count = old hand count - 1
new Coins = old Coins + 2 = 4 + 2 = 6 
*************************************************************************************/
int preCoins = tempGame.coins; 
tempGame.handCount[player] = 5;
tempGame.playedCardCount = 5; 


// initialize the refactored function variables
handPos = 0;

// Get the pre card effect handCount for testing
oldHandCount = tempGame.handCount[player];

// Playing Choice 1
steward_refactor(player, &tempGame, handPos, 2, -1, -1 );

// Get the post card effect handCount for testing
NewHandCount = tempGame.handCount[player];

printf ("--------------------------------- Choice 2 ------------------------------\n");

if (tempGame.coins > preCoins)
{
	printf ("Steward Card added two coins to the players total coins, PASSED\n");
	printf ("Expected total number of coins = 6\n");
	printf ("Outcome of total number of coins = %d\n", tempGame.coins);
} else
{
	printf ("Steward Card did NOT add two coins to the players total coins, FAILED\n");
	printf ("Expected total number of coins = 6\n");
	printf ("Outcome of total number of coins = %d\n", tempGame.coins);
}

//assert(tempGame.coins == 6);

if (NewHandCount == oldHandCount - 1)
{
	printf ("Steward Card removed the played card from the player's hand, PASSED\n");
	printf ("Expected total number of player's hand cards = 4\n");
	printf ("Outcome total number of player's hand cards = %d\n", NewHandCount);
} else
{
	printf ("Steward Card did NOT removed the played card from the player's hand, FAILED\n");
	printf ("Expected total number of player's hand cards = 4\n");
	printf ("Outcome total number of player's hand cards = %d\n", NewHandCount);
}

assert(NewHandCount == 4);

/*************************************************************************************
				            Steward Card Test (Choice 3)
Expected Effect from plaing the card:
1) Trash two cards from the player's hand - 2
2) discard the card played from player's hand -1
results:
new hand Count = old hand count - 3
*************************************************************************************/

// initialize the refactored function variables
handPos = 0;
tempGame.handCount[player] = 5;

// Get the pre card effect handCount for testing
oldHandCount = tempGame.handCount[player];

// Playing Choice 1
steward_refactor(player, &tempGame, handPos, -1, 1, 2 );

// Get the post card effect handCount for testing
NewHandCount = tempGame.handCount[player];

printf ("--------------------------------- Choice 3 ------------------------------\n");
if (NewHandCount == oldHandCount - 3)
{
	printf ("Steward Card Trashed two cards from the player's hand, PASSED\n");
	printf ("Expected total number of player's hand cards = 2\n");
	printf ("Outcome total number of player's hand cards = %d\n", NewHandCount);
} else
{
	printf ("Steward Card did NOT Trash two cards from the player's hand, FAILED\n");
	printf ("Expected total number of player's hand cards = 2\n");
	printf ("Outcome total number of player's hand cards = %d\n", NewHandCount);
}

assert(NewHandCount == 2);

}


int main() {

	StewardCardTest();

	return 0;
}
