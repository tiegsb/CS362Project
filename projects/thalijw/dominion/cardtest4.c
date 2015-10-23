/**************************************************************************************
File Name: cardtest4.c
Created by: Wisam Thalij
Date created: 10-22-2015
Last Modified: 10-22-2015

Description: This file is a test unit fot Cutpurse Card in dominion.c, The test will
first create a new game, set the count of both palyer's hand cards to 5 cards, then 
test to make sure the outcome of playing the Cutpurse card is correct.
**************************************************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

void CutpurseCardTest() {

// Initial game values
int seed = 1000;
int numPlayer = 2;
int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
int game = 0;
int Firstplayer = 0;
int Secondplayer = 1;

// Create a temp game state
struct gameState tempGame;

// clear the game state
memset(&tempGame, 23, sizeof(struct gameState));

// initialize a new game
game = initializeGame(numPlayer, k, seed, &tempGame); 
printf ("\n************************************************************************\n");
printf ("TESTING Cutpurse Card:\n");

/*************************************************************************************
				            	Cutpurse Card Test
Expected Effect from plaing the card:
1) Add 2 coins to one who played the card total coins = old coins + 2
2) discard the card played from player's hand -1
3) remove a copper card from the opponent hand if he has any 
results:
new hand Count = old hand count + 1
*************************************************************************************/

// intialize the player 0 handscount and playedCardCount to 5 to test against
tempGame.handCount[Firstplayer] = 5;
tempGame.handCount[Secondplayer] = 5;
int i = 0;
int handPos = 0;
int oldCoins = tempGame.coins;
int SPOldHand = tempGame.handCount[Secondplayer];
// initialize all the second player's hand to copper 
for (i = 0; i < tempGame.handCount[Secondplayer] ; i++)
{
  tempGame.hand[Secondplayer][i] = copper;
}

// Play the card
cardEffect(cutpurse, -1, -1, -1, &tempGame, handPos, 0);

// Testing adding +2 coins to the first player
if (tempGame.coins == oldCoins + 2)
{
	printf ("The Card added two coins to the first player coins Count, PASSED!\n");
	printf ("Total coins before the card = %d\n", oldCoins);
	printf ("Total coins after the card = %d\n", tempGame.coins);
} else
{
	printf ("The Card added two coins to the first player coins Count, FAILED!\n");
	printf ("Total coins before the card = %d\n", oldCoins);
	printf ("Total coins after the card = %d\n", tempGame.coins);
}

assert(tempGame.coins == 6);

// testing the second player hand has removed one copper card
if (tempGame.handCount[Secondplayer] == SPOldHand - 1 )
{
	printf ("The Card removed one copper card from second player hand, PASSED!\n");
	printf ("Expected total cards in hand after playing the Cutpurse = 4\n");
	printf ("Outcome total cards in hand after playing the Cutpurse = %d\n", tempGame.handCount[Secondplayer]);
} else
{
	printf ("The Card did NOT remove one copper card from second player hand, FAILED!\n");
	printf ("Expected total cards in hand after playing the Cutpurse = 4\n");
	printf ("Outcome total cards in hand after playing the Cutpurse = %d\n", tempGame.handCount[Secondplayer]);
}

assert(tempGame.handCount[Secondplayer] == 4);

// testing if the card played has been discarded from first player hand
if (tempGame.handCount[Firstplayer] < 5)
{
	printf ("The Card discarded the played card from the first player, PASSED!\n");
	printf ("Expected total cards in hand after playing the Cutpurse = 4\n");
	printf ("Outcome total cards in hand after playing the Cutpurse = %d\n", tempGame.handCount[Firstplayer]);
} else
{
	printf ("The Card did NOT discard the played card from the first player, FAILED!\n");
	printf ("Expected total cards in hand after playing the Cutpurse = 4\n");
	printf ("Outcome total cards in hand after playing the Cutpurse = %d\n", tempGame.handCount[Firstplayer]);
}

assert(tempGame.handCount[Firstplayer] == 4);

}

int main() {

	CutpurseCardTest();

	return 0;
}
