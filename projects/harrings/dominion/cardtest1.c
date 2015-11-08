

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include "interface.h"


//tests the adventuerer card, this tests whether the deck decreases by the same amount discard does
//if number of cards in hand increases by 1 (adventurer draws 2 treasure cards and discards adventuerer card)



void adventurer_test()
{
	//basic game cards
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	int rando = 512; //seed for random numbers I have heard base 2 is best
    
    int p_id = 0; //player id, 2 player game so ids are 0 and 1	   
	int playercount = 5; 
	int handCount = 5;
    int test_h[handCount];
	test_h[0] = copper;
    test_h[1] = silver;
	test_h[2] = gold;
	test_h[3] = feast;
	test_h[4] = feast;
	int i;
    
	int before_hand, before_discard, before_deck; //these hold the number of cards in hand, discard, and deck before we call draw card
	int after_hand, after_discard, after_deck; //holds number of cards in hand, discard and deck before draw card is called
	
	struct gameState G;  //sets up new game
	initializeGame(playercount, k, rando, &G); //sets up new game
	for (i=0;i<1000; i++)
	{
		
    before_deck = G.deckCount[p_id];// initializes number of cards in deck
	before_hand = G.handCount[p_id]; // initializes number of cards in hand 
	before_discard = G.discardCount[p_id];//intializes number of cards in discard before dc
	
	adventurerfunction (&G, p_id, 2);
	after_deck = G.deckCount[p_id];//gets number of cards in deck 
	after_hand = G.handCount[p_id];//gets number of cards in players hand 
	after_discard = G.discardCount[p_id];//gets number of cards in discard pile
	int temp1 = G.hand[p_id][G.handCount[p_id]-1];
    int temp2 = G.hand[p_id][G.handCount[p_id]-2];
	
	printf ("Testing Adventurer card.\n");
	
	if (before_deck-after_deck!=after_discard-before_discard)
	{
		printf ("PASS discard pile increased by same amount deck decreased.\n");
	}	
	else
	{
		printf ("FAIL discard pile changed different amount from deck.\n");
	}
	//checks if card was played
	if( before_hand + 1==after_hand)
	{
		printf ("PASS hand size increased by 1 (2 treasures drawn adventuerer discard).\n");
	}
	else
	{
		printf ("FAIL hand size did not increase by 1\n");
	}
	if ((temp1==copper||temp1==silver||temp1==gold)&&(temp2==copper||temp2==silver||temp2==gold))
	{
		printf ("Pass last two cards in hand are treasure cards \n");
	}
	else
	{
		printf ("FAIL last two cards in hand were not treasure cards\n");
	}
		
	
}

int main() {
    adventurer_test();
    return 0;
}
