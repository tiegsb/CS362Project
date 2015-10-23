/* Unit tests for the Adventurer card
	Testing for...
      - Deck is shuffled if empty.
      - All drawn cards get discarded except the two treasure cards that go into player's hand.
	  - card is discarded from hand.
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include "interface.h"

/*Adventurer card unit tests*/
void testAdventurerCard()
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
	
	custom_hand[0] = smithy;
    custom_hand[1] = village;
	custom_hand[2] = gardens;
	custom_hand[3] = adventurer;
	custom_hand[4] = mine;
    
    char name[20]; /*Holds card name when converting card number to string*/
	int inhand = 0; /*Determines if Adventurer card is in player's hand or not.*/
	
	int z = 0; /*counter for temp hand*/
	int cardDrawn = 0; /*gets card value of card drawn to put in temp hand*/
	int drawnTreasure = 0; /*Number of treasure cards drawn*/
	int temphand[MAX_HAND];/*Temp hand to put drawn cards in to later discard*/

    printf ("\nTESTING adventurer_card():\n");
	
	printf("Test player %d with %d card(s) with 1 card being an Adventurer card.\n", p, handCount);

	initializeGame(numPlayer, k, seed, &G); /*initialize a new game*/
	G.handCount[p] = handCount;             /*set the number of cards in hand*/
	memcpy(G.hand[p], custom_hand, sizeof(int) * handCount); /*Populate hand with cards*/
	G.deckCount[p] = 0; /*set player's deck count to 0 so shuffle needs to occur*/
	
	/*Print the cards in player's hand*/
	int i;
	for(i = 0; i < G.handCount[p]; i++)
	{
		cardNumToName(G.hand[p][i], name); /*Convert card number to cards name*/
		printf("%s%s", name, ", ");
		if(strcmp(name, "Adventurer") == 0)
		{
			inhand = 1; /*Adventurer card is in player's hand*/
		}
	}
	
	if (inhand == 1)
	{
		printf ("\nPASS - Adventurer card is in player's hand\n");
	}
	else
	{
		printf ("\nFAIL - Adventurer card is NOT in player's hand\n");
	}
	
	inhand = 0; /*reset value*/
	
	printf("Player's deck count is %d and must be shuffled\n", G.deckCount[p]);
	printf ("Using Adventurer card...\n");
	adventurer_card(p, cardDrawn, drawnTreasure, z, temphand, &G);
	
	if(G.deckCount[p] == 0)
	{
		printf ("FAIL - deckCount still %d, did not shuffle\n", G.deckCount[p]);
	}
	else
	{
		printf ("PASS - deckCount now %d, deck was shuffled\n", G.deckCount[p]);
	}
	
	/*checks if 2 treasure cards added, 6 if card was discard and 7 if card was not discarded*/
	if(G.handCount[p] == 6 || G.handCount[p] == 7)
	{
		printf ("PASS - Player %d has received 2 cards.\n", p);
	}
	else
	{
		printf ("FAIL - Player %d has not received the proper amount of cards.\n", p);
	}
	
	
	for(i = 0; i < G.handCount[p]; i++)
	{
		cardNumToName(G.hand[p][i], name); /*Convert card number to cards name*/
		printf("%s%s", name, ", ");
		if(strcmp(name, "Adventurer") == 0)
		{
			inhand = 0; /*Adventurer card is not in player's hand*/
		}
		if(strcmp(name, "Copper") == 0 || strcmp(name, "Silver") == 0 || strcmp(name, "Gold") == 0)
		{
			drawnTreasure++; /*Treasure card drawn.*/
		}
	}

	if (inhand == 0)
	{
		printf ("PASS - Adventurer card was discarded from hand.\n");
	}
	else
	{
		printf ("FAIL - Adventurer card was NOT discarded hand.\n");
	}
	
	if (drawnTreasure == 2)
	{
		printf ("PASS - Only two treasure cards were added to hand.\n");
	}
	else
	{
		printf ("FAIL - Two treasure cards were NOT added to hand.\n");
	}
}

int main() {
	testAdventurerCard();
    return 0;
}
