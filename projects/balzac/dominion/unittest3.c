/* Unit tests for the isGameOver()
	Testing for...
      - If province card stack is empty, game ends.
	  - If three different piles of cards are empty, game ends.
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

/*isGameOver unit tests*/
void testIsGameOver()
{
	int seed = 1000; /*Used for initializeGame parameter for setting up random # generator*/
    int numPlayer = 2; /*number of players in game. Maximum # of players is 4*/
	
	/*Kingdom cards used in this game*/
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
			   
    struct gameState G; /*start a new game*/
	int true = 0;/*Holds return value of isGameOver*/
	
    printf ("\nTESTING isGameOver():");

	initializeGame(numPlayer, k, seed, &G); /*initialize a new game*/
	
	printf ("\nDetermine if game is over when Province card stack is empty.\n");
	
	G.supplyCount[province] = 1;
	true = isGameOver(&G);
	
	if(true == 1)
	{
		printf ("FAIL - Game is over when 1 Province remaining.\n");
	}
	else
	{
		printf ("PASS - Game is NOT over when 1 Province remaining.\n");
	}
	
	G.supplyCount[province] = 0;
	true = isGameOver(&G);
	
	if(true == 1)
	{
		printf ("PASS - Game is over when 0 Province remaining.\n");
	}
	else
	{
		printf ("FAIL - Game is NOT over when 0 Province remaining.\n");
	}

	printf ("\nDetermine if game is over when 3 coin card stacks are empty; copper, silver, gold.\n");
	
	memset(&G, 23, sizeof(struct gameState)); /*clear the game state*/
	initializeGame(numPlayer, k, seed, &G); /*initialize a new game*/
	
	G.supplyCount[copper] = 0;
	true = isGameOver(&G);
	
	if(true == 1)
	{
		printf ("FAIL - Game is over when 1 card stack empty.\n");
	}
	else
	{
		printf ("PASS - Game is NOT over when 1 card stack empty.\n");
	}
	
	G.supplyCount[silver] = 0;
	true = isGameOver(&G);
	
	if(true == 1)
	{
		printf ("FAIL - Game is over when 2 card stacks are empty.\n");
	}
	else
	{
		printf ("PASS - Game is NOT over when 2 card stacks are empty.\n");
	}
	
	G.supplyCount[gold] = 0;
	true = isGameOver(&G);
	
	if(true == 1)
	{
		printf ("PASS - Game is over when 3 card stacks are empty.\n");
	}
	else
	{
		printf ("FAIL - Game is NOT over when 3 card stacks are empty.\n");
	}
	
	printf ("\nDetermine if game is over when 3 action card stacks are empty; Smithy, Village, Treasure Map\n");
	
	memset(&G, 23, sizeof(struct gameState)); /*clear the game state*/
	initializeGame(numPlayer, k, seed, &G); /*initialize a new game*/
	
	G.supplyCount[smithy] = 0;
	true = isGameOver(&G);
	
	if(true == 1)
	{
		printf ("FAIL - Game is over when 1 card stack empty.\n");
	}
	else
	{
		printf ("PASS - Game is NOT over when 1 card stack empty.\n");
	}
	
	G.supplyCount[village] = 0;
	true = isGameOver(&G);
	
	if(true == 1)
	{
		printf ("FAIL - Game is over when 2 card stacks are empty.\n");
	}
	else
	{
		printf ("PASS - Game is NOT over when 2 card stacks are empty.\n");
	}
	
	G.supplyCount[treasure_map] = 0;
	true = isGameOver(&G);
	
	if(true == 1)
	{
		printf ("PASS - Game is over when 3 card stacks are empty.\n");
	}
	else
	{
		printf ("FAIL - Game is NOT over when 3 card stacks are empty.\n");
	}
}

int main() {
    testIsGameOver();
    return 0;
}