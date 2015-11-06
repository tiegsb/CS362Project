

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include "interface.h"


//tests the council_room card which causes 4 cards to be drawn with 
//council being discard so hand +3 while all other players draw 1 card and buys
//increased by 1



void council_test_random()
{
	//basic game cards
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	int rando = 512; //seed for random numbers I have heard base 2 is best
    
    int p_id = 0; //player id, 2 player game so ids are 0 and 1	   
	int playercount = 4; 
	int handCount = 5;
    int test_h[handCount];
	int other_hand_before[playercount];
	int other_hand_after[playercount];
	
	int i=0;
	int j;
	int l;
	int total1=0;
	int good1=0;
	int bad1=0;
	int good2=0;
	int bad2=0;
	int total2=0;
	int good3=0;
	int bad3=0;
	int total3=0;
	int randhand;
    
	int before_hand, before_buys; //these hold the number of cards in hand and number of actions
	int after_hand, after_buys; //holds number of cards in hand and number of actions
	
	struct gameState G;  //sets up new game
	initializeGame(playercount, k, rando, &G); //sets up new game
	
	
	for (l=0;l<20000;l++)
	{
		
		playercount=(rand()%3)+2;
		p_id=rand()%playercount;
		memset(&G, 23, sizeof(struct gameState)); //clear game state
		initializeGame(playercount, k, rando, &G); //sets up new game
		before_hand = G.handCount[p_id]; // initializes number of cards in hand 
		before_buys = G.numBuys;
		for (j=0;j<playercount;j++)
		{
			other_hand_before[j]=0; //resets values
			other_hand_after[j]=0;
			if (j!=p_id)
			{
			other_hand_before[j]=G.handCount[j];
			}
		}
		
		councilfunction (&G, p_id, i, 2);
		after_buys = G.numBuys;
		after_hand = G.handCount[p_id]; // gets number of cards in hand
		for (j=0;j<playercount;j++)
		{
			if (j!=p_id)
			{
			other_hand_after[j]=G.handCount[j];
			}
		}
		//printf ("Testing Council card.\n");
		
		if (before_buys+1==after_buys)
		{
			//printf ("PASS buys increased by 1.\n");
			good1 ++;
			total1++;
		}	
		else
		{
			//printf ("FAIL buys did not increase by 1.\n");
			bad1++;
			total1++;
		}
		//checks if card was played
		if( before_hand+3==after_hand)
		{
			//printf ("PASS hand size increased by 3.\n");
			good2++;
			total2++;
		}
		else
		{
			//printf ("FAIL hand size did not increase by 3 \n");
			bad2++;
				total2++;
		}
		//checks that other players hands increased by 1
		for (j=0;j<playercount;j++)
		{
			if (j!=p_id)
			{
				if( other_hand_before[j]+1==other_hand_after[j])
				{
					//printf ("PASS other players hand size increased by 1.\n");
					good3++;
					total3++;
				}
				else
				{
					//printf ("FAIL other players hand size did not increase by 1 \n");
					bad3++;
					total3++;
				}
			}
		}
	}
		printf ( "End of test of Buys results %d tests were run with %d successes and %d failures \n", total1, good1, bad1);
	printf ( "End of test for PLayers handsize results %d tests were run with %d successes and %d failures \n", total2, good2, bad2);	
	printf ( "End of test Other players hand size results %d tests were run with %d successes and %d failures \n", total3, good3, bad3);
		
	
}

int main() {
    council_test_random();
    return 0;
}
