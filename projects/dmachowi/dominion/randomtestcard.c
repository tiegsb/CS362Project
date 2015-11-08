/*************************************************************************************************
 * Author:                 Drew Machowicz
 * Date Created:           November 2, 2015
 * Last Modification Date: November 8, 2015
 * File Name:              randomtestcard.c
 * Overview:
 *   Random testing for smithy card, checks pre and post game states for correctnes,
 *   this test fails as it should because I introduced bugs to it in a previous assignment.
 ************************************************************************************************/
#include "dominion.h"
#include "interface.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>

void checkSmithy(int handPos, struct gameState *post, int p) {
	int i;
	int player = p;
	post->whoseTurn = p;
	struct gameState pre;
	memcpy(&pre, post, sizeof(struct gameState));
	int error = 0;
	//printf("this is pre hand %d \n", pre.handCount[player]);
	//printf("this is post hand %d \n", post->handCount[player]);

	playSmithy(&pre, handPos);
	//pre hand should have plus 2 from previous hand because it discared a smithy and gained two cards
	pre.handCount[player] = pre.handCount[player] + 2;
	if (pre.handCount[player] != post->handCount[player]) {
		//printf("hand count is wrong! \n");
		error++;
	}

	//top of discard for player in pre and post should be smithy
	//put smithy code here to run through pre card discard stuff
	for(i = 0; i < 3; i++) {
		drawCard(p, &pre);
	}

	int preCard = pre.discard[player][pre.discardCount[player]];
	int postCard = post->discard[player][post->discardCount[player]];
	if (preCard != postCard){
		error++;	
		//printf("top cards in discaard mismatch\n");
	}

	int preDeck = pre.deckCount[player];
	int postDeck = post->deckCount[player];
	if (preDeck != postDeck){
		error++;	
		//printf("top cards in discaard mismatch\n");
	}
	//if you dont see this in the .out file then there were errros
	if(!error)
		printf("No Errors!\n");
}


int main() {
printf("Testing Smithy Card..\n");
    int i,n,p  = 0;
    //kingdom cards uses for tets
    //int k[10] = {adventurer, ambassador, embargo, smithy, village, feast, mine, gardens, baron, council_room};
    int handPos = 0;
    struct gameState G;
    //itnialzieGame supplies all the supplyCounts of cards

    //taken from lecture video
    SelectStream(2);
  	PutSeed(3);
	for(i =0; i<40000; i++) {
		//initialize game state when random junk
  		//initializeGame((rand() %(2)+2), k, rand(), &G);
		for (n = 0; n < sizeof(struct gameState); n++) {
    		((char*)&G)[n] = floor(Random() * 256);
    	}
    	//need a feasible number of players
    	p = floor(Random() * 3);
    	//need a feasible deck count, up to max deck size
    	G.deckCount[p] = floor(Random() * MAX_DECK);
    	//need a feasible discard count, up to max deck size
    	//printf("this is deckcount %d\n", G.deckCount[p]);
    	G.discardCount[p] = floor(Random() * MAX_DECK);
    	//need a feasible hand count, up to max hand size
    	//printf("discardCount is %d\n", G.discardCount[p]);
    	G.handCount[p] = floor(Random() * MAX_HAND);
    	//need a feasible played card count, up to max deck size
    	G.playedCardCount = floor(Random() * MAX_DECK);
    	//random hand position between 0 and hand count
    	//printf("this is handcount %d\n", G.handCount[p] );
    	handPos = floor(Random() * G.handCount[p]);
   		checkSmithy(handPos, &G, p);
	}
    printf("finished testing\n");
    return 0;
}

