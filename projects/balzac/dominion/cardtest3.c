/* Unit tests for the Village card
	Testing for...
      - 1 card added to hand
      - Player gains +2 actions
	  - card is discarded from hand.
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include "interface.h"

/*Village card unit tests*/
void testVillageCard()
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
	
	custom_hand[0] = copper;
    custom_hand[1] = village;
	custom_hand[2] = silver;
	custom_hand[3] = gold;
	custom_hand[4] = mine;
    
    char name[20]; /*Holds card name when converting card number to string*/
	int inhand = 0; /*Determines if Village card is in player's hand or not.*/
	int actions_b = 0; /*Holds number of actions player has before using card*/
	int actions_a = 0; /*Holds number of actions player has after using card*/
	
	
    printf ("\nTESTING Village card:\n");
	
	printf("Test player %d with %d card(s) with 1 card being a Village card.\n", p, handCount);

	initializeGame(numPlayer, k, seed, &G); /*initialize a new game*/
	G.handCount[p] = handCount;             /*set the number of cards in hand*/
	memcpy(G.hand[p], custom_hand, sizeof(int) * handCount); /*Populate hand with cards*/
	actions_b = G.numActions;
	/*Print the cards in player's hand*/
	int i;
	for(i = 0; i < G.handCount[p]; i++)
	{
		cardNumToName(G.hand[p][i], name); /*Convert card number to cards name*/
		printf("%s%s", name, ", ");
		if(strcmp(name, "Village") == 0)
		{
			inhand = 1; /*Village card is in player's hand*/
		}
	}
	
	if (inhand == 1)
	{
		printf ("\nPASS - Village card is in player's hand\n");
	}
	else
	{
		printf ("\nFAIL - Village card is NOT in player's hand\n");
	}
	
	inhand = 0; /*reset value*/
	
	printf ("Using Village card...\n");
	cardEffect(village, 0, 0, 0, &G, 1, 0);
	actions_a = G.numActions; /*get number of actions*/
	
	/*checks if 1 cards added, 5 if card was discard and 6 if card was not discarded*/
	if(G.handCount[p] == 5 || G.handCount[p] == 6)
	{
		printf ("PASS - Player %d has received 1 card.\n", p);
	}
	else
	{
		printf ("FAIL - Player %d has not received a card.\n", p);
	}
	
	/*check if actions = 2 in case 1 action not removed and +1 if action was removed.*/
	if(actions_a == actions_b + 1)
	{
		printf ("PASS - Player %d has gained +2 actions.\n", p);
	}
	else if (actions_a == actions_b + 2)
	{
		printf ("FAIL - Player gained 2 actions but action to play card was not decremented.\n", p);
	}
	else
	{
		printf ("FAIL - Player %d has NOT gained +2 actions.\n", p);
	}
	
	for(i = 0; i < G.handCount[p]; i++)
	{
		cardNumToName(G.hand[p][i], name); /*Convert card number to cards name*/
		printf("%s%s", name, ", ");
		if(strcmp(name, "Village") == 0)
		{
			inhand = 1; /*Village card is in player's hand*/
		}
	}
	
	if (inhand == 0)
	{
		printf ("\nPASS - Village card has been discarded from player's hand\n");
	}
	else
	{
		printf ("\nFAIL - Village card has NOT been discarded from player's hand\n");
	}
}

int main() {
	testVillageCard();
    return 0;
}
