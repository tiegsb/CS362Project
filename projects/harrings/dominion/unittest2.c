

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include "interface.h"


//tests discard card function, this checks to ensure player hand count decreases by 1
//while also checking that discard count increases by 1. Also tests if other cards in hand properly fill in gap



void discardCard_test()
{
	//basic game cards
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	int rando = 512; //seed for random numbers I have heard base 2 is best
    
    int pid = 0; //player id, 2 player game so ids are 0 and 1	   
	int playercount = 2; 
	int handCount = 5;
    int test_h[handCount];
	test_h[0] = copper;
    test_h[1] = silver;
	test_h[2] = gold;
	test_h[3] = copper;
	test_h[4] = silver;
	int i;
    
	int before_played, before_discard; //these hold the number of cards in hand, discard, and deck before we call draw card
	int after_played, after_discard; //holds number of cards in hand, discard and deck before draw card is called
	
	struct gameState G;  //sets up new game
	
    printf ("\nUnit test 2 Discard card\n");

	initializeGame(playercount, k, rando, &G); //sets up new game
	G.handCount[pid] = handCount;             
	memcpy(G.hand[pid], test_h, sizeof(int) * handCount); //creates hand with cards above
	before_discard = G.discardCount[pid];//sets discarded cards before dc is used
	before_played = G.playedCardCount;//sets played cards before dc is used
	
	printf ("\nDiscarding players 3rd card \n");
	discardCard(2, pid, &G, 0);//discard gold card trash flag 0
	
	after_discard = G.discardCount[pid];//gets number of discarded and played cards after dc is used
	after_played = G.playedCardCount;
	//checks if discard increased by 1
	if( before_discard + 1==after_discard)
	{
		printf ("PASS discard pile increased by 1.\n");
	}
	else
	{
		printf ("FAIL discard pile did not increase by 1.\n");
	}
	//checks if card was played
	if( before_played + 1==after_played)
	{
		printf ("PASS played pile increased by 1.\n");
	}
	else
	{
		printf ("FAIL played pile did not increase by 1\n");
	}
	
	
	//confirms that card in last slot silver here moves to the missing slot
	if(G.hand[pid][2] == silver)
	{
		printf ("PASS card at end of hand filled in discarded cards spot.\n");
	}
	else
	{
		printf ("FAIL card did not replace discarded cards spot.\n");
	}
	
	before_discard = G.discardCount[pid];//sets discarded cards before dc is used
	before_played = G.playedCardCount;//sets played cards before dc is used
	
	printf ("\nDiscarding players 3rd card \n");
	discardCard(3, pid, &G, 1);//discard copper card trash flag 1
	
	after_discard = G.discardCount[pid];//gets number of discarded and played cards after dc is used
	after_played = G.playedCardCount;
	
	
	//checks if discard increased by 1
	if( before_discard + 1==after_discard)
	{
		printf ("PASS discard pile increased by 1.\n");
	}
	else
	{
		printf ("FAIL discard pile did not increase by 1.\n");
	}
	
	//confrims card was not added to played
	if( before_played==after_played)
	{
		printf ("PASS played pile stayed same with trash flag of 1.\n");
	}
	else
	{
		printf ("FAIL played pile changed\n");
	}
	
}

int main() {
    discardCard_test();
    return 0;
}
