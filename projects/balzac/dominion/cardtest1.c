/* Unit tests for the Smithy card
	Testing for...
      - 3 cards were added to players hand.
      - Smithy card was discarded from players hand.
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include "interface.h"

/*Smithy card unit tests*/
void testSmithyCard()
{
	int seed = 1000; /*Used for initializeGame parameter for setting up random # generator*/
    int numPlayer = 2; /*number of players in game. Maximum # of players is 4*/
    int p = 1; /*holds the value of the player, example player 0, player 1.*/
	int handCount = 5; /*Number of cards player starts with*/
	
	/*Kingdom cards used in this game*/
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
			   
    struct gameState G; /*start a new game*/
	
	/*create a custom hand to give to player */
    int custom_hand[handCount];
	
	custom_hand[0] = copper;
    custom_hand[1] = village;
	custom_hand[2] = silver;
	custom_hand[3] = smithy;
	custom_hand[4] = mine;
    
    char name[20]; /*Holds card name when converting card number to string*/
	int inhand = 0; /*Determines if Smithy card is in player's hand or not.*/

    printf ("\nTESTING smithy_card():\n");
	
	printf("Test player %d with %d card(s) with 1 card being a Smithy card.\n", p, handCount);

	initializeGame(numPlayer, k, seed, &G); /*initialize a new game*/
	G.handCount[p] = handCount;             /*set the number of cards in hand*/
	memcpy(G.hand[p], custom_hand, sizeof(int) * handCount); /*Populate hand with cards*/
	
	/*Print the cards in player's hand*/
	int i;
	for(i = 0; i < G.handCount[p]; i++)
	{
		cardNumToName(G.hand[p][i], name); /*Convert card number to cards name*/
		printf("%s%s", name, ", ");
		if(strcmp(name, "Smithy") == 0)
		{
			inhand = 1; /*Smithy card is in player's hand*/
		}
	}
	
	if (inhand == 1)
	{
		printf ("\nPASS - Smithy card is in player's hand\n");
	}
	else
	{
		printf ("\nFAIL - Smithy card is NOT in player's hand\n");
	}
	
	inhand = 0; /*reset value*/
	printf ("Using Smithy card...\n");
	smithy_card(p, 3, &G);
	
	/*checks if 3 cards added, 7 if card was discard and 8 if card was not discarded*/
	if(G.handCount[p] == 7 || G.handCount[p] == 8)
	{
		printf ("PASS - Player %d has received 3 cards.\n", p);
	}
	else
	{
		printf ("FAIL - Player %d has not received the proper amount of cards.\n", p);
	}
	
	for(i = 0; i < G.handCount[p]; i++)
	{
		cardNumToName(G.hand[p][i], name); /*Convert card number to cards name*/
		printf("%s%s", name, ", ");
		if(strcmp(name, "Smithy") == 0)
		{
			inhand = 0; /*Smithy card is not in player's hand*/
		}
	}

	if (inhand == 0)
	{
		printf ("\nPASS - Smithy card was discarded from hand.\n");
	}
	else
	{
		printf ("\nFAIL - Smithy card was NOT discarded hand.\n");
	}
}

int main() {
    testSmithyCard();
    return 0;
}
