

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

//tests if game is over, first checks if game ends when 3 piles are empty (ill test gold, silver, copper)
//then checks if game is over when province cards are gone
void gameover_test()
{
	//basic game cards
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	int rando = 512; //seed for random numbers I have heard base 2 is best
    int over=0; 
	int playercount = 2; 
	struct gameState G;  //sets up new game
    printf ("\nUnit test of Game Over function");
	
	printf ("\nChecks if game ends when 3 action card stacks are empty. (feast, mine, smithy) \n");
	
	
	initializeGame(playercount, k, rando, &G); // new game
	
	G.supplyCount[feast] = 0;
	over = isGameOver(&G);
	
	if(over == 0)
	{
		printf ("Pass game is not over with 1 empty stack (feast).\n");
	}
	else
	{
		printf ("Fail game is over with only 1 empty stack \n");
	}
	
	G.supplyCount[mine] = 0;
	over = isGameOver(&G);
	
	if(over == 0)
	{
		printf ("Pass game is not over with 2 empty stacks (feast, mine).\n");
	}
	else
	{
		printf ("Fail game is over with only 2 empty stacks (feast, mine) \n");
	}
	
	G.supplyCount[smithy] = 0;
	over = isGameOver(&G);
	
	if(over == 0)
	{
		printf ("Fail game has not ended with 3 empty stack (feast,mine, smithy).\n");
	}
	else
	{
		printf ("Pass game has ended with 3 empty stacks (feast, mine, smithy) \n");
	}
	
	

	printf ("\nChecks if game ends when the 3 currency stacks are empty.\n");
	
	memset(&G, 23, sizeof(struct gameState)); //resets game
	initializeGame(playercount, k, rando, &G); // new game
	
	G.supplyCount[gold] = 0;
	over = isGameOver(&G);
	
	if(over == 0)
	{
		printf ("Pass game is not over with 1 empty stack (gold).\n");
	}
	else
	{
		printf ("Fail game is over with only 1 empty stack \n");
	}
	
	G.supplyCount[silver] = 0;
	over = isGameOver(&G);
	
	if(over == 0)
	{
		printf ("Pass game is not over with 2 empty stacks (gold, silver).\n");
	}
	else
	{
		printf ("Fail game is over with only 2 empty stacks (gold, silver) \n");
	}
	
	G.supplyCount[copper] = 0;
	over = isGameOver(&G);
	
	if(over == 0)
	{
		printf ("Fail game has not ended with 3 empty stack (gold,silver, copper).\n");
	}
	else
	{
		printf ("Pass game has ended with 3 empty stacks (gold, silver, copper) \n");
	}
	
	
	memset(&G, 23, sizeof(struct gameState)); //resets game
	initializeGame(playercount, k, rando, &G); 
	
	printf ("\nChecks if is over properly ends game when province stack empty\n");
	
	G.supplyCount[province] = 1;
	over = isGameOver(&G);
	
	if(over == 0)
	{
		printf ("Pass game is not over with 1 card in province pile.\n");
	}
	else
	{
		printf ("Fail game has ended with 1 card in province pile \n");
	}
	
	G.supplyCount[province] = 0;
	over = isGameOver(&G);
	
	if(over == 0)
	{
		printf ("Fail game has not ended with empty province stack.\n");
	}
	else
	{
		printf ("Pass game has ended with empty province stack \n");
	}
}

int main() {
    gameover_test();
    return 0;
}