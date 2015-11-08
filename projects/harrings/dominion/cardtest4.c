

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include "interface.h"


//tests the council_room card which causes 4 cards to be drawn with 
//council being discard so hand +3 while all other players draw 1 card and buys
//increased by 1



void council_test()
{
	//basic game cards
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	int rando = 512; //seed for random numbers I have heard base 2 is best
    
    int p_id = 0; //player id, 2 player game so ids are 0 and 1	   
	int playercount = 2; 
	int handCount = 5;
    int test_h[handCount];
	
	int i=0;
    
	int before_hand, before_buys, other_hand_before; //these hold the number of cards in hand and number of actions
	int after_hand, after_buys, other_hand_after; //holds number of cards in hand and number of actions
	
	struct gameState G;  //sets up new game
	initializeGame(playercount, k, rando, &G); //sets up new game
	
   
	before_hand = G.handCount[p_id]; // initializes number of cards in hand 
	before_buys = G.numBuys;
	other_hand_before=G.handCount[1];
	
	councilfunction (&G, p_id, i, 2);
	after_buys = G.numBuys;
	after_hand = G.handCount[p_id]; // gets number of cards in hand
	other_hand_after=G.handCount[1];
	printf ("Testing Council card.\n");
	
	if (before_buys+1==after_buys)
	{
		printf ("PASS buys increased by 1.\n");
	}	
	else
	{
		printf ("FAIL buys did not increase by 1.\n");
	}
	//checks if card was played
	if( before_hand+3==after_hand)
	{
		printf ("PASS hand size increased by 3.\n");
	}
	else
	{
		printf ("FAIL hand size did not increase by 3 \n");
	}
	if( other_hand_before+1==other_hand_after)
	{
		printf ("PASS other players hand size increased by 1.\n");
	}
	else
	{
		printf ("FAIL other players hand size did not increase by 1 \n");
	}
	
		
	
}

int main() {
    council_test();
    return 0;
}
