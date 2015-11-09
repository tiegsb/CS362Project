/*************************************************************************************************
 * Author:                 Drew Machowicz
 * Date Created:           November 3, 2015
 * Last Modification Date: November 8, 2015
 * File Name:              randomtestadventurer.c
 * Overview:
 *   random tests for adventurer card
 ************************************************************************************************/
#include "dominion.h"
#include "interface.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int checkAdventurer(struct gameState *post, int p){
	// printf("in the oracle\n");
	int i, cardDrawn;
	int treasureCardsBefore, treasureCardsAfter = 0;
	post->whoseTurn = p;
	int player = p;
	int errCounter = 0;
    

	struct gameState pre;
    //printf("this is deckcount %d\n", post->deckCount[player]);
    //printf("discardCount is %d\n", post->discardCount[player]);
    //printf("this is handcount %d\n", post->handCount[player]);
	memcpy(&pre, post, sizeof(struct gameState));
  	//printf("this is deckcount %d\n", pre.deckCount[player]);
    //printf("discardCount is %d\n", pre.discardCount[player]);
    //printf("this is handcount %d\n", pre.handCount[player]);
	//printf("counting the hands\n");
	playAdventurer(post);




   	//what should be done to pre
    //handcount +2
    pre.handCount[player] = pre.handCount[player] + 2;
    //discard + deck - 2
    int beforeCards = pre.discardCount[player] + pre.deckCount[player];
    int afterCards = beforeCards - 2;


	//check treasure count before
	for(i = 0; i < pre.handCount[player]; i++) {
		cardDrawn = pre.hand[player][i];
		if((cardDrawn == copper) || (cardDrawn == silver) || cardDrawn == gold){
			treasureCardsBefore++;
		}
	}
	// printf("calling playAdventurer\n");
	//check discard after, should be at least two more, total deck the same?
	
	// printf("calling treasure check after\n");
	//check treasure count after, should be plus 2
	for(i = 0; i <= post->handCount[player]; i++) {
		cardDrawn = post->hand[player][i];
		if((cardDrawn == copper) || (cardDrawn == silver) || cardDrawn == gold){
			treasureCardsAfter++;
		}
	}

	//add two to treasureCardsBefore because thats pre's treasure count
	treasureCardsBefore = treasureCardsBefore + 2;

	// printf("calling check treasure before and after\n");
	//prints message if treasure count is off
	if (treasureCardsBefore != treasureCardsAfter) {
		//printf("Fail! Wrong number of treasure cards!\n");
		errCounter++;
	}
	
	//hand count should be plus a
	int preHandCount = pre.handCount[player]++; //plus 1 for the treasure cards
	if (post->handCount[player] != preHandCount) {
		//printf("Fail! Hand count is wrong!\n");
		errCounter++;
	}

	//deckcount + discard count + hand count is the same before and after, compare pre and post
	int deckb = pre.deckCount[player];
	int discb = pre.discardCount[player];
	int handb = pre.handCount[player];
	int cardsBefore = deckb + discb + handb;

	int decka = post->deckCount[player];
	int disca = post->discardCount[player];
	int handa = post->handCount[player];
	int cardsAfter = decka + disca + handa;

	if(cardsAfter != cardsBefore){
		errCounter++;
	// 	printf("Fail! Full card count is different! Should be the same before and after\n");
	}


	if (memcmp(&pre, post, sizeof(struct gameState)) != 0) {
		//printf("Failed assertion!\n");
		errCounter++;
	}

	if(!errCounter) 
		printf("All passed! No Problems!\n");
}
int main() {
	printf("Testing playAdventurer Card..\n");
    int i,n  = 0;
    //kingdom cards uses for tets
    int k[10] = {adventurer, ambassador, embargo, smithy, village, feast, mine, gardens, baron, council_room};

    struct gameState G;
    //itnialzieGame supplies all the supplyCounts of cards


    SelectStream(2);
  	PutSeed(3);

	for(i =0; i<40000; i++) {
  		//initializeGame((rand() %(2)+2), k, rand(), &G);
		for (n = 0; n < sizeof(struct gameState); n++) {
    		((char*)&G)[n] = floor(Random() * 256);
    	}
    	int p = floor(Random() * 2);
    	//give some treasures to the deck

    	G.deckCount[p] = floor(Random() * MAX_DECK);
    	//printf("this is deckcount %d\n", G.deckCount[p]);
    	G.discardCount[p] = floor(Random() * MAX_DECK);
    	//printf("discardCount is %d\n", G.discardCount[p]);
    	G.handCount[p] = floor(Random() * MAX_HAND);
    	G.playedCardCount = floor(Random() * MAX_DECK);
    	//printf("this is handcount %d\n", G.handCount[p] );
    	G.numPlayers = p;
    	//G.whoseTurn = 1;
   		checkAdventurer(&G, p);
	}
    printf("finished testing\n");
	return 0;
}
