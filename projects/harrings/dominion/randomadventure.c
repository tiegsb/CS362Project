

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include "interface.h"


//tests the adventuerer card, this tests whether the deck decreases by the same amount discard does
//if number of cards in hand increases by 1 (adventurer draws 2 treasure cards and discards adventuerer card)



void adventurer_random()
{
	//basic game cards
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	int rando =rand()%512; //seed for random number
    
    int p_id = 0; //player id, 2 player game so ids are 0 and 1	   
	int playercount = 4; 
	int handCount = 5;
 
	int i;
	int total1=0;
	int good1=0;
	int bad1=0;
	int good2=0;
	int bad2=0;
	int total2=0;
	int good3=0;
	int bad3=0;
	int total3=0;
	int temp=0;
	int temp2;
	int card1;
	int card2;
    
	int before_hand, before_discard, before_deck; //these hold the number of cards in hand, discard, and deck before we call draw card
	int after_hand, after_discard, after_deck; //holds number of cards in hand, discard and deck before draw card is called
	
	struct gameState G;  //sets up new game
	initializeGame(playercount, k, rando, &G); //sets up new game
	printf ("Testing Adventurer card random.\n");
	for (i=0;i<20000; i++)
	{
			playercount=(rand()%3)+2;
			p_id=rand()%playercount;
			memset(&G, 23, sizeof(struct gameState)); //clear game state
			initializeGame(playercount, k, rando, &G); //sets up new game
			temp=rand()%5;
			temp2=(rand()%3); //generates random starting deck assignment
			if (temp2==1)
			{
				G.deckCount[p_id] = 0; //deck to 0 discard to 5
				G.discardCount[p_id] = 5;
			}
			else if (temp2==2)
			{
				G.deckCount[p_id] = 5; //deck to 0 discard to 5
				G.discardCount[p_id] = 0;
			}
			
			
			
			before_deck = G.deckCount[p_id];// initializes number of cards in deck
			before_hand = G.handCount[p_id]; // initializes number of cards in hand 
			before_discard = G.discardCount[p_id];//intializes number of cards in discard before dc
			
			adventurerfunction (&G, p_id, 2);
			after_deck = G.deckCount[p_id];//gets number of cards in deck 
			after_hand = G.handCount[p_id];//gets number of cards in players hand 
			after_discard = G.discardCount[p_id];//gets number of cards in discard pile
			card1 = G.hand[p_id][G.handCount[p_id]-1];
			card2 = G.hand[p_id][G.handCount[p_id]-2];
			
			//printf ("Testing Adventurer card.\n");
			//test 1
			if (before_deck-after_deck!=after_discard-before_discard)
			{
				//printf ("PASS discard pile increased by same amount deck decreased.\n");
				good1 ++;
				total1++;
			}	
			else
			{
				//printf ("FAIL discard pile changed different amount from deck.\n");
				bad1++;
				total1++;
			}
			//checks if card was played
			//test 2
			if( before_hand + 1==after_hand)
			{
				//printf ("PASS hand size increased by 1 (2 treasures drawn adventuerer discard).\n");
				good2++;
				total2++;
			}
			else
			{
				//printf ("FAIL hand size did not increase by 1\n");
				bad2++;
				total2++;
			}
			//test 3
			if ((card1==copper||card1==silver||card1==gold)&&(card2==copper||card2==silver||card2==gold))
			{
				//printf ("Pass last two cards in hand are treasure cards \n");
				good3++;
				total3++;
			}
			else
			{
				//printf ("FAIL last two cards in hand were not treasure cards\n");
				bad3++;
				total3++;
			}
		
	}
	printf ( "End of test Test 1 results %d tests were run with %d successes and %d failures \n", total1, good1, bad1);
	printf ( "End of test Test 2 results %d tests were run with %d successes and %d failures \n", total2, good2, bad2);	
	printf ( "End of test Test 3 results %d tests were run with %d successes and %d failures \n", total3, good3, bad3);
}

int main() {
	int rando=512;
	 srand(rando);
    adventurer_random();
    return 0;
}
