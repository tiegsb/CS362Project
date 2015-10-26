

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include "interface.h"


//tests the village card which adds 2 actions
//village card also adds 1 draw but discards village so hand size shoudl not change



void village_test()
{
	//basic game cards
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	int rando = 512; //seed for random numbers I have heard base 2 is best
    
    int p_id = 0; //player id, 2 player game so ids are 0 and 1	   
	int playercount = 2; 
	int handCount = 5;
    int test_h[handCount];
	
	int i;
    
	int before_hand, before_actions; //these hold the number of cards in hand and number of actions
	int after_hand, after_actions; //holds number of cards in hand and number of actions
	
	struct gameState G;  //sets up new game
	initializeGame(playercount, k, rando, &G); //sets up new game
	
   
	before_hand = G.handCount[p_id]; // initializes number of cards in hand 
	before_actions = G.numActions;
	
	villagefunction (&G, p_id, 2);
	after_actions = G.numActions;
	after_hand = G.handCount[p_id]; // gets number of cards in hand
	
	printf ("Testing Village card.\n");
	
	if (before_actions+2==after_actions)
	{
		printf ("PASS actions increased by 2.\n");
	}	
	else
	{
		printf ("FAIL actions did not increase by 2.\n");
	}
	//checks if card was played
	if( before_hand==after_hand)
	{
		printf ("PASS hand size stayed same.\n");
	}
	else
	{
		printf ("FAIL hand size changed \n");
	}
	
		
	
}

int main() {
    village_test();
    return 0;
}
