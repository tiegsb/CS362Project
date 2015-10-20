/* Unit tests for the discardCard()
	Testing for...
      - If card does not have trash flag set to 1 add card to played pile.
	  - Remove card from players hand.
	  - If the card being discarded was only card in hand, hand should be empty
	  - If card discarded was last card added, don't move cards around in hand.
	  - If card discarded had a card after last card moves into its position.
	  - If discard count increases.
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include "interface.h"

/*check if card discarded is still in player's hand*/
void cardInHand(char cardName[20], struct gameState *G, int p, char name[20] )
{
	int inhand = 0; /*Determines if card is in player's hand or not.*/
	int i;
	for(i = 0; i < (*G).handCount[p]; i++)
	{
		cardNumToName((*G).hand[p][i], name); /*Convert card number to cards name*/
		printf("%s%s", name, ", ");
		if(strcmp(name, cardName) == 0)
		{
			inhand = 1; /* card is in player's hand*/
		}
	}
	
	if (inhand == 0)
	{
		printf ("\nPASS - card has been discarded from player's hand\n\n");
	}
	else
	{
		printf ("\nFAIL - card has NOT been discarded from player's hand\n\n");
	}
	
}

/*discardCard unit tests*/
void testdiscardCard()
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
    custom_hand[1] = silver;
	custom_hand[2] = village;
	custom_hand[3] = gold;
	custom_hand[4] = smithy;
    
    char name[20]; /*Holds card name when converting card number to string*/
	int played_b = 0;/*number of played cards increases if card discarded and trash flag 0.*/
	int played_a = 0;/*number of played cards increases if card discarded and trash flag 0.*/
	int discardCount_b = 0;/*number of cards discarded before discardCard() used*/
	int discardCount_a = 0;/*number of cards discarded after discardCard() used*/
	
    printf ("\nTESTING discardCard():\n");

	initializeGame(numPlayer, k, seed, &G); /*initialize a new game*/
	G.handCount[p] = handCount;             /*set the number of cards in hand*/
	memcpy(G.hand[p], custom_hand, sizeof(int) * handCount); /*Populate hand with cards*/
	played_b = G.playedCardCount;/*get number of played cards before discardCard() is used*/
	discardCount_b = G.discardCount[p];/*get number discarded cards*/

	/*Print the cards in player's hand*/
	int i;
	for(i = 0; i < G.handCount[p]; i++)
	{
		cardNumToName(G.hand[p][i], name); /*Convert card number to cards name*/
		printf("%s%s", name, ", ");
	}
	
	printf ("\nDiscard village card trash flag set to 0\n");
	discardCard(2, p, &G, 0);/*discard village card*/
	played_a = G.playedCardCount;/*get number of played cards after discardCard() is used*/
	discardCount_a = G.discardCount[p];/*get number discarded cards*/
	
	/*checks if card was added to played card pile*/
	if(played_a == played_b + 1)
	{
		printf ("PASS - card added to played pile when trash flag set to 0.\n");
	}
	else
	{
		printf ("FAIL - card NOT added to played pile when trash flag set to 0.\n");
	}
	
	/*checks if card was added to discard pile*/
	if(discardCount_a == discardCount_b + 1)
	{
		printf ("PASS - card added to discard pile.\n");
	}
	else
	{
		printf ("FAIL - card NOT added to discard pile.\n");
	}
	
	/*Check if last card in player hand replaces discarded card's position.*/
	if(G.hand[p][2] == smithy)
	{
		printf ("PASS - Last card replaced discarded card's position.\n");
	}
	else
	{
		printf ("FAIL - Last card did NOT replace discarded card's position.\n");
	}
	
	/*check if card discarded is still in player's hand*/
	cardInHand("Village", &G, p, name);
	
	/*reset values*/
	played_b = 0;
	played_a = 0;
	discardCount_b = 0;
	discardCount_a = 0;
	
	played_b = G.playedCardCount;/*get number of played cards before discardCard() is used*/
	discardCount_a = G.discardCount[p];/*get number discarded cards*/
	printf ("Discard gold card trash flag set to 1\n");
	discardCard(3, p, &G, 1);/*discard gold card*/
	played_a = G.playedCardCount;/*get number of played cards after discardCard() is used*/
	discardCount_a = G.discardCount[p];/*get number discarded cards*/
	
	/*checks if card was added to played card pile*/
	if(played_a == played_b)
	{
		printf ("PASS - card NOT added to played pile when trash flag set to 1.\n");
	}
	else
	{
		printf ("FAIL - card added to played pile when trash flag set to 1.\n");
	}
	
	/*checks if card was added to discard pile*/
	if(discardCount_a == discardCount_b + 1)
	{
		printf ("PASS - card added to discard pile.\n");
	}
	else
	{
		printf ("FAIL - card NOT added to discard pile.\n");
	}
	
	/*Check if last card in player hand was not replaced with another card.*/
	if(G.hand[p][2] == copper || G.hand[p][2] == smithy || G.hand[p][2] == silver)
	{
		printf ("PASS - Last card's position in hand discarded NOT replaced with another card.\n");
	}
	else
	{
		printf ("FAIL - Last card's position in hand discarded replaced with another card.\n");
	}
	
	/*check if card discarded is still in player's hand*/
	cardInHand("Gold", &G, p, name);
	
	/*Check for when only one card in hand it is removed.*/
	
	discardCard(2, p, &G, 1);/*discard smithy card*/
	discardCard(1, p, &G, 1);/*discard silver card*/
	
	/*Print the cards in player's hand*/
	for(i = 0; i < G.handCount[p]; i++)
	{
		cardNumToName(G.hand[p][i], name); /*Convert card number to cards name*/
		printf("%s%s", name, ", ");
	}
	
	discardCard(0, p, &G, 1);/*discard last remaining card*/
	
	if(G.handCount[p] == 0)
	{
		printf ("\nPASS - Player's hand is empty.");
	}
	else
	{
		printf ("\nFAIL - Player's hand is NOT empty.");
	}
	
	/*check if card discarded is still in player's hand*/
	cardInHand("Copper", &G, p, name);
}

int main() {
    testdiscardCard();
    return 0;
}
