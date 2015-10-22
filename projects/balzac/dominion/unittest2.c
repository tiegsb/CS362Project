/* Unit tests for the drawCard()
	Testing for...
      - If player's deck is empty shuffle discard pile into deck pile.
	  - If deck shuffled, discard pile should be 0.
	  - Player's hand should gain 1 card.
	  - Player's deck count should decrease by 1.
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

/*drawCard unit tests*/
void testdrawCard()
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
    
	int handCount_b = 0;/*number of cards in players hand before drawCard()*/
	int handCount_a = 0;/*number of cards in players hand after drawCard()*/
	int discardCount_b = 0;/*number of cards in discard pile before drawCard()*/
	int discardCount_a = 0;/*number of cards in discard pile after drawCard()*/
	int deckCount_b = 0;/*number of cards in deck before drawCard()*/
	int deckCount_a = 0;/*number of cards in deck after drawCard()*/
	
    printf ("\nTESTING drawCard():");

	initializeGame(numPlayer, k, seed, &G); /*initialize a new game*/
	G.handCount[p] = handCount;             /*set the number of cards in hand*/
	memcpy(G.hand[p], custom_hand, sizeof(int) * handCount); /*Populate player 0 hand with cards*/
	
	
	printf ("\nDraw card with cards left in deck.\n");
	handCount_b = G.handCount[p];/*get number of cards in player's hand before drawCard() used*/
	deckCount_b = G.deckCount[p];/*number of cards in deck before drawCard()*/
	
	drawCard(p, &G);
	
	handCount_a = G.handCount[p];/*get number of cards in player's hand after drawCard() used*/
	deckCount_a = G.deckCount[p];/*number of cards in deck after drawCard()*/
	
	/*checks if card was added to played card pile*/
	if(handCount_a == handCount_b + 1)
	{
		printf ("PASS - card added to player's hand.\n");
	}
	else
	{
		printf ("FAIL - card NOT added to player's hand.\n");
	}
	
	/*checks if deck count decreased.*/
	if(deckCount_a == deckCount_b - 1)
	{
		printf ("PASS - card removed from deck pile.\n");
	}
	else
	{
		printf ("FAIL - card NOT removed from deck pile.\n");
	}
	
	if(deckCount_a <= 0)
	{
		printf ("FAIL - deck count is less than 0.\n");
	}
	else
	{
		printf ("PASS - deck count is NOT less than 0.\n");
	}
	
	printf ("\nDraw card with 0 cards left in deck and 5 cards in discard pile.\n");
	
	memset(&G, 23, sizeof(struct gameState)); /*clear the game state*/
	initializeGame(numPlayer, k, seed, &G); /*initialize a new game*/
	G.handCount[p] = handCount;             /*set the number of cards in hand*/
	
	G.deckCount[p] = 0; /*Set deck count to 0*/
	G.discardCount[p] = 5;/*set discard count to 10*/
	
	handCount_b = G.handCount[p];/*get number of cards in player's hand before drawCard() used*/
	discardCount_b = G.discardCount[p];/*get number discarded cards before drawCard()*/
	deckCount_b = G.deckCount[p];/*number of cards in deck before drawCard()*/
	
	
	drawCard(p, &G);
	handCount_a = G.handCount[p];/*get number of cards in player's hand after drawCard() used*/
	discardCount_a = G.discardCount[p];/*get number discarded cards after drawCard()*/
	deckCount_a = G.deckCount[p];/*number of cards in deck after drawCard()*/
	
	/*checks if deck count is same count as discard pile before drawCard() was used.*/
	if(deckCount_a + 1 == discardCount_b || deckCount_a == discardCount_b)
	{
		printf ("PASS - discard pile added to deck pile.\n");
	}
	else
	{
		printf ("FAIL - discard pile NOT added to deck pile.\n");
	}
	
	/*checks if discard count is same count as deck pile before drawCard() was used.*/
	if(discardCount_a == deckCount_b)
	{
		printf ("PASS - discard pile is empty.\n");
	}
	else
	{
		printf ("FAIL - discard pile NOT empty.\n");
	}
	
	/*checks if card was added to played card pile*/
	if(handCount_a == handCount_b + 1)
	{
		printf ("PASS - card added to player's hand.\n");
	}
	else
	{
		printf ("FAIL - card NOT added to player's hand.\n");
	}
	
	/*checks if deck count decreased.*/
	if(deckCount_a == discardCount_b - 1)
	{
		printf ("PASS - card removed from deck pile.\n");
	}
	else
	{
		printf ("FAIL - card NOT removed from deck pile.\n");
	}
	
	if(deckCount_a <= 0)
	{
		printf ("FAIL - deck count is less than 0.\n");
	}
	else
	{
		printf ("PASS - deck count is NOT less than 0.\n");
	}
	
	printf ("\nDraw card with 0 cards left in deck but -1 discard pile.\n");
	
	memset(&G, 23, sizeof(struct gameState)); /*clear the game state*/
	initializeGame(numPlayer, k, seed, &G); /*initialize a new game*/
	G.handCount[p] = handCount;             /*set the number of cards in hand*/

	G.deckCount[p] = 0; /*Set deck count to 0*/
	G.discardCount[p] = -1;/*set discard count to 10*/
	
	handCount_b = G.handCount[p];/*get number of cards in player's hand before drawCard() used*/
	discardCount_b = G.discardCount[p];/*get number discarded cards before drawCard()*/
	deckCount_b = G.deckCount[p];/*number of cards in deck before drawCard()*/
	
	drawCard(p, &G);
	handCount_a = G.handCount[p];/*get number of cards in player's hand after drawCard() used*/
	discardCount_a = G.discardCount[p];/*get number discarded cards after drawCard()*/
	deckCount_a = G.deckCount[p];/*number of cards in deck after drawCard()*/
	
	/*checks if deck count is same count as discard pile before drawCard() was used.*/
	if(deckCount_a + 1 == discardCount_b || deckCount_a == discardCount_b)
	{
		printf ("PASS - discard pile added to deck pile.\n");
	}
	else
	{
		printf ("FAIL - discard pile NOT added to deck pile.\n");
	}
	
	/*checks if discard count is same count as deck pile before drawCard() was used.*/
	if(discardCount_a == deckCount_b)
	{
		printf ("PASS - discard pile is empty.\n");
	}
	else
	{
		printf ("FAIL - discard pile NOT empty.\n");
	}
	
	/*checks if card was added to played card pile*/
	if(handCount_a == handCount_b + 1)
	{
		printf ("PASS - card added to player's hand.\n");
	}
	else
	{
		printf ("FAIL - card NOT added to player's hand.\n");
	}
	
	/*checks if deck count decreased.*/
	if(deckCount_a == discardCount_b - 1)
	{
		printf ("PASS - card removed from deck pile.\n");
	}
	else
	{
		printf ("FAIL - card NOT removed from deck pile.\n");
	}
	
	/*checks if deck count is not less than 0*/
	if(deckCount_a <= 0)
	{
		printf ("FAIL - deck count is less than 0.\n");
	}
	else
	{
		printf ("PASS - deck count is NOT less than 0.\n");
	}
}

int main() {
    testdrawCard();
    return 0;
}