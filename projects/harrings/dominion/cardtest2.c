

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include "interface.h"


//tests the smithy card which has the player draw 3 cards and discard smithy card
//checking that hand size increases by 2 (draw 3 discard 1) and that deck
//and discard stay in equalibrium



void smithy_test()
{
	//basic game cards
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	int rando = 512; //seed for random numbers I have heard base 2 is best
    
    int p_id = 0; //player id, 2 player game so ids are 0 and 1	   
	int playercount = 2; 
	int handCount = 5;
    int test_h[handCount];
	
	int i;
    
	int before_hand, before_discard, before_deck; //these hold the number of cards in hand, discard, and deck before we call draw card
	int after_hand, after_discard, after_deck; //holds number of cards in hand, discard and deck before draw card is called
	
	struct gameState G;  //sets up new game
	initializeGame(playercount, k, rando, &G); //sets up new game
	
    before_deck = G.deckCount[p_id];// initializes number of cards in deck
	before_hand = G.handCount[p_id]; // initializes number of cards in hand 
	before_discard = G.discardCount[p_id];//intializes number of cards in discard before dc
	
	smithyfunction (&G, p_id, 2);
	after_deck = G.deckCount[p_id];//gets number of cards in deck 
	after_hand = G.handCount[p_id];//gets number of cards in players hand 
	after_discard = G.discardCount[p_id];//gets number of cards in discard pile
	
	printf ("Testing Smithy card.\n");
	
	if (before_deck-after_deck!=after_discard-before_discard)
	{
		printf ("PASS discard pile increased by same amount deck decreased.\n");
	}	
	else
	{
		printf ("FAIL discard pile changed different amount from deck.\n");
	}
	//checks if card was played
	if( before_hand + 2==after_hand)
	{
		printf ("PASS hand size increased by 2 (3 drawn 1 discarded).\n");
	}
	else
	{
		printf ("FAIL hand size did not increase by 2 \n");
	}
	
		
	
}

int main() {
    smithy_test();
    return 0;
}
