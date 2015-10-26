

//test for draw card function this should check if the players hand increases by 1 and if the deck decreases by 1.
//this also checks if the deck is empty then discard pile is deck, anytime you see dc in comments it means draw card

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

void drawcard_test()
{
	//basic game cards
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	int rando = 512; //seed for random numbers I have heard base 2 is best
    
    int p_id = 0; //player id, 2 player game so ids are 0 and 1	   
	int playercount = 2; 
	int handCount = 5;
    int test_h[handCount];
	test_h[0] = copper;
    test_h[1] = silver;
	test_h[2] = gold;
	test_h[3] = copper;
	test_h[4] = silver;
    
	int before_hand, before_discard, before_deck; //these hold the number of cards in hand, discard, and deck before we call draw card
	int after_hand, after_discard, after_deck; //holds number of cards in hand, discard and deck before draw card is called
	
	struct gameState G;  //sets up new game
	
    printf ("\n Running Draw Card Unit Test:");

	initializeGame(playercount, k, rando, &G); //sets up new game
	G.handCount[p_id] = handCount;             //sets player hand size to 5
	memcpy(G.hand[p_id], test_h, sizeof(int) * handCount); //fills up the players hand with cards
	
	printf ("\n Testing draw card with non empty deck.\n");
	before_deck = G.deckCount[p_id];// initializes number of cards in deck before draw card is called
	before_hand = G.handCount[p_id]; // initializes number of cards in hand before draw card is called
	
	
	drawCard(p_id, &G); //draws a card
	after_deck = G.deckCount[p_id];//gets number of cards in deck after draw card (should decrease by 1)
	after_hand = G.handCount[p_id];//gets number of cards in players hand after dc (should increase by 1)
	
	//check deck
	if(after_deck == before_deck - 1)
	{
		printf ("PASS deck decrease by 1.\n");
	}
	else
	{
		printf ("FAIL deck did not decrease by 1.\n");
	}
	
	if(after_deck < 0)
	{
		printf ("FAIL deck cant be less then 0.\n");
	}
	else
	{
		printf ("PASS no illegal deck moves.\n");
	}
	
	//checks if hand count increased by 1
	if(after_hand == before_hand + 1)
	{
		printf ("PASS player hand count up by 1.\n");
	}
	else
	{
		printf ("FAIL player hand count not up by 1.\n");
	}
	
	
	
	printf ("\n Testing draw card with empty deck.\n");
	
	memset(&G, 23, sizeof(struct gameState)); 
	initializeGame(playercount, k, rando, &G); //clears then initializes new game 
	G.handCount[p_id] = handCount;             //sets up hand count
	
	G.deckCount[p_id] = 0; //deck to 0 discard to 5
	G.discardCount[p_id] = 5;
	
	before_deck = G.deckCount[p_id];// initializes number of cards in deck before draw card is called
	before_hand = G.handCount[p_id]; // initializes number of cards in hand before draw card is called
	before_discard = G.discardCount[p_id];//intializes number of cards in discard before dc
	
	
	drawCard(p_id, &G);
	after_deck = G.deckCount[p_id];//gets number of cards in deck after draw card (should decrease by 1)
	after_hand = G.handCount[p_id];//gets number of cards in players hand after dc (should increase by 1)
	after_discard = G.discardCount[p_id];//gets number of cards in discard pile
	
	if(before_discard - 1 == after_deck)
	{
		printf ("PASS deck descreased by 1.\n");
	}
	else
	{
		printf ("FAIL deck size did not change \n");
	}
	
	if(after_deck < 0)
	{
		printf ("FAIL deck cant be below 0.\n");
	}
	else
	{
		printf ("PASS legal deck.\n");
	}
	
	if(before_hand + 1 == after_hand)
	{
		printf ("PASS player hand increased by 1.\n");
	}
	else
	{
		printf ("FAIL players hand did not increase by 1.\n");
	}
	
	
	//checks to make sure deck properly shuffled
	if(after_deck == before_discard || after_deck + 1 == before_discard)
	{
		printf ("PASS deck was shuffled.\n");
	}
	else
	{
		printf ("FAIL discard was not moved to deck n");
	}
	
	//checks to make sure no cards are lost when they go from discard to deck
	if(after_discard == before_deck)
	{
		printf ("PASS all cards moved to deck.\n");
	}
	else
	{
		printf ("FAIL not all cards moved to deck.\n");
	}
	
}

int main() {
    drawcard_test();
    return 0;
}