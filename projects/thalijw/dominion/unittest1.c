/**************************************************************************************
File Name: unittest1.c
Created by: Wisam Thalij
Date created: 10-13-2015
Last Modified: 10-13-2015

Description: This file is a test unit fot updateCoins() in dominion.c, The program will
first create a new game, set the values of the hand cards to some treature values and
then test to make sure the outcome of updateCoins() is correct.
**************************************************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

void testUpdateCoins() {

// Initial game values
int seed = 1000;
int numPlayer = 2;
int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
int player = 0;
int game = 0;
int bonus = 0;
int i;

// variables to test the game
int totalCoins = 0;
int coppers[MAX_HAND];
int silvers[MAX_HAND];
int golds[MAX_HAND];
for (i = 0; i < MAX_HAND; i++)
{
    coppers[i] = copper;
    silvers[i] = silver;
    golds[i] = gold;
}

// Create a temp game state
struct gameState tempGame;

// clear the game state
memset(&tempGame, 23, sizeof(struct gameState));

// initialize a new game
game = initializeGame(numPlayer, k, seed, &tempGame); 

printf ("TESTING updateCoins():\n");

/*********************************************************************
					     All Copper Cards Test
We first initialize all player hand cards to copper, player will have
5 cards of copper with total coins 5. and bouns = 0

before the updateCoins() Total Coins = 0 and Player Coins = 4
after the updateCoins()	 Total Coins = 5 and Player Coins = 5

*********************************************************************/

printf ("----------------- Testing all hand cards as a copper -----------------\n");
printf ("Total number of Coins before the update is: %d\n", tempGame.coins);
//printf ("TotalCoins before the update is: %d\n", totalCoins);

// intialize the player 0 handscount
tempGame.handCount[player] = 5;

// Making all cards as Copper and cheking the Updatecoins()
for (i = 0; i < 5; i++)
{
	tempGame.hand[player][i] = copper;
	totalCoins++;
} 

if (updateCoins(player, &tempGame, bonus) == 0)
{
	printf ("Total number of Coins after the update is: %d\n", tempGame.coins);
	//printf ("TotalCoins after the update is: %d\n", totalCoins);

  	if (tempGame.coins == totalCoins)
  	{
  		printf("updateCoins() Updated the correct number of Coins (5 Coppers = 5 Coins) ,PASSED!\n");
  	}
  	else
  	{
  		printf("updateCoins() did not Update the correct number of Coins and the test FAILED!\n");
  	}
} else
{
  	printf("updateCoins():  Failed to execute!!!\n");
}

assert(tempGame.coins == 5);

/*********************************************************************
					       All Silver Cards Test
We first initialize all player hand cards to Silver, player will have
5 cards of silver with total coins 10. and bouns = 0

before the updateCoins() Total Coins = 0 and Player Coins = 5
after the updateCoins()	 Total Coins = 10 and Player Coins = 10

*********************************************************************/

totalCoins = 0; // reset the total number of Coins

printf ("----------------- Testing all hand cards as a Silver -----------------\n");
printf ("Total number of Coins before the update is: %d\n", tempGame.coins);
//printf ("TotalCoins before the update is: %d\n", totalCoins);

// intialize the player 0 handscount
tempGame.handCount[player] = 5;

// Making all cards as Copper and cheking the Updatecoins()
for (i = 0; i < 5; i++)
{
	tempGame.hand[player][i] = silver;
	totalCoins += 2;
} 

if (updateCoins(player, &tempGame, bonus) == 0)
{
	printf ("Total number of Coins after the update is: %d\n", tempGame.coins);
	//printf ("TotalCoins after the update is: %d\n", totalCoins);

  	if (tempGame.coins == totalCoins)
  	{
  		printf("updateCoins() Updated the correct number of Coins (5 Silver = 10 Coins), PASSED!\n");
  	}
  	else
  	{
  		printf("updateCoins() did not Update the correct number of Coins and the test FAILED!\n");
  	}
} else
{
  	printf("updateCoins():  Failed to execute!!!\n");
}
assert(tempGame.coins == 10);
/*********************************************************************
					       All Gold Cards Test
We first initialize all player hand cards to Gold, player will have
5 cards of gold with total coins 10. and bouns = 0

before the updateCoins() Total Coins = 0 and Player Coins = 10
after the updateCoins()	 Total Coins = 15 and Player Coins = 15

*********************************************************************/

totalCoins = 0; // reset the total number of Coins

printf ("----------------- Testing all hand cards as a Gold -----------------\n");
printf ("Total number of Coins before the update is: %d\n", tempGame.coins);
//printf ("TotalCoins before the update is: %d\n", totalCoins);

// intialize the player 0 handscount
tempGame.handCount[player] = 5;

// Making all cards as Copper and cheking the Updatecoins()
for (i = 0; i < 5; i++)
{
	tempGame.hand[player][i] = gold;
	totalCoins += 3;
} 

if (updateCoins(player, &tempGame, bonus) == 0)
{
	printf ("Total number of Coins after the update is: %d\n", tempGame.coins);
	//printf ("TotalCoins after the update is: %d\n", totalCoins);

  	if (tempGame.coins == totalCoins)
  	{
  		printf("updateCoins() Updated the correct number of Coins (5 Gold = 15 Coins), PASSED!\n");
  	}
  	else
  	{
  		printf("updateCoins() did not Update the correct number of Coins and the test FAILED!\n");
  	}
} else
{
  	printf("updateCoins():  Failed to execute!!!\n");
}

assert(tempGame.coins == 15);
/*********************************************************************
				        Adding the correct bonus Test
We first initialize all player hand cards to Gold, player will have
5 cards of gold with total coins 10. and bouns = 5

before the updateCoins() Total Coins = 0 , Player Coins = 10 and bouns = 5
after the updateCoins()	 Total Coins = 20,  Player Coins = 20

*********************************************************************/

totalCoins = 0; // reset the total number of Coins
bonus = 5;
printf ("----------------- Testing adding the correct bonus -----------------\n");
printf ("Total number of Coins before the update is: %d\n", tempGame.coins);
//printf ("TotalCoins before the update is: %d\n", totalCoins);

// intialize the player 0 handscount
tempGame.handCount[player] = 5;

// Making all cards as Copper and cheking the Updatecoins()
for (i = 0; i < 5; i++)
{
	tempGame.hand[player][i] = gold;
	totalCoins += 3;
} 

// Adding the bonus to the total
totalCoins += 5;

if (updateCoins(player, &tempGame, bonus) == 0)
{
	printf ("Total number of Coins after the update is: %d\n", tempGame.coins);
	//printf ("TotalCoins after the update is: %d\n", totalCoins);

  	if (tempGame.coins == totalCoins)
  	{
  		printf("updateCoins() Updated the correct number of (5 Gold + 5 bonus = 20), PASSED!\n");
  	}
  	else
  	{
  		printf("updateCoins() did not Update the correct number of Coins and the test FAIL!\n");
  	}
} else
{
  	printf("updateCoins():  Failed to execute!!!\n");
}

assert(tempGame.coins == 20);
}


int main() {

	testUpdateCoins();

	return 0;
}
