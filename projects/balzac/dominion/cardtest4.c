/* Unit tests for the Steward card
	Testing for...
      - if choice 1 == 2 then player draws 2 cards.
      - if choice1 == 1 then player gains 2 coins.
	  - if choice1 not 1 or 2 then discard 3 cards from player's hand.
	  - card is discarded from hand.
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include "interface.h"

/*Steward card unit tests*/
void testStewardCard()
{
	int seed = 1000; /*Used for initializeGame parameter for setting up random # generator*/
    int numPlayer = 2; /*number of players in game. Maximum # of players is 4*/
    int p = 0; /*holds the value of the player, example player 0, player 1.*/
	int handCount = 5; /*Number of cards player starts with*/
	
	/*Kingdom cards used in this game*/
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
			   
    struct gameState G; /*start a new game*/
	
	/*create a custom hand to give to player */
    int custom_hand[handCount];
	
	custom_hand[0] = feast;
    custom_hand[1] = village;
	custom_hand[2] = steward;
	custom_hand[3] = smithy;
	custom_hand[4] = mine;
    
    char name[20]; /*Holds card name when converting card number to string*/
	int inhand = 0; /*Determines if Steward card is in player's hand or not.*/
	
	int coins_b = 0;/*number of coins before card is used.*/
	int coins_a = 0;/*number of coins after card is used.*/
	
    printf ("\nTESTING steward_card() with three different choices:\n");
	
	printf("Test player %d with %d card(s) with 1 card being a Steward card.\n\n", p, handCount);

	int choice1 = 0;
	for(choice1 = 0; choice1 <= 2; choice1++)
	{
		memset(&G, 23, sizeof(struct gameState)); /*clear the game state*/
		initializeGame(numPlayer, k, seed, &G); /*initialize a new game*/
		G.handCount[p] = handCount;             /*set the number of cards in hand*/
		memcpy(G.hand[p], custom_hand, sizeof(int) * handCount); /*Populate hand with cards*/
		coins_b = G.coins;/*get number of coins before card is used*/
		/*Print the cards in player's hand*/
		int i;
		for(i = 0; i < G.handCount[p]; i++)
		{
			cardNumToName(G.hand[p][i], name); /*Convert card number to cards name*/
			printf("%s%s", name, ", ");
			if(strcmp(name, "Steward") == 0)
			{
				inhand = 1; /*Steward card is in player's hand*/
			}
		}
		
		if (inhand == 1)
		{
			printf ("\nPASS - Steward card is in player's hand\n");
		}
		else
		{
			printf ("\nFAIL - Steward card is NOT in player's hand\n");
		}
		
		inhand = 0; /*reset value*/
		
		printf ("Using steward card choice1 is %d\n", choice1);
		steward_card(p, 2, choice1, 1, 4, &G);
		coins_a = G.coins;/*get number of coins after card is used*/
		
		if(choice1 == 1)
		{
			/*checks if 2 cards added, 6 if card was discard and 7 if card was not discarded*/
			if(G.handCount[p] == 6 || G.handCount[p] == 7)
			{
				printf ("PASS - Player %d has received 2 cards.\n", p);
			}
			else
			{
				printf ("FAIL - Player %d has not received 2 cards.\n", p);
			}
		}
		else if(choice1 == 2)
		{
			if(coins_a == coins_b + 2)
			{
				printf ("PASS - Player %d has received 2 coins.\n", p);
			}
			else
			{
				printf ("FAIL - Player %d has not received 2 coins.\n", p);
			}
		}
		else
		{
			/*checks if 2 cards discarded, 2 if steward card was discard and 3 if steward card was 
			not discarded*/
			if (G.handCount[p] == 2 || G.handCount[p] == 3)
			{
				printf ("PASS - 2 cards discarded.\n");
			}
			else
			{
				printf ("FAIL - 2 cards NOT discarded.\n");
			}
		}
	
		for(i = 0; i < G.handCount[p]; i++)
		{
			cardNumToName(G.hand[p][i], name); /*Convert card number to cards name*/
			printf("%s%s", name, ", ");
			if(strcmp(name, "Steward") == 0)
			{
				inhand = 1; /*Steward card is in player's hand*/
			}
		}
		
		if (inhand == 0)
		{
			printf ("\nPASS - Steward card has been discarded from player's hand\n\n");
		}
		else
		{
			printf ("\nFAIL - Steward card has NOT been discarded from player's hand\n\n");
		}
	}
}

int main() {
    testStewardCard();
    return 0;
}
