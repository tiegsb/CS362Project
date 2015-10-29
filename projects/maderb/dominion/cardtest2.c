#include <stdio.h>
#include <stdlib.h>

#include "dominion.h"

//Unit test for adventurerEffect() card/function

int main(int argc, char* argv[]){
	int i=0;
	int bonus;
	struct gameState currGame;
	int treasureTracker=0;

	printf("UNIT TEST FOR adventurerEffect() FUNCTION:\n");

	currGame.playedCards[0]=0;
	currGame.playedCardCount=0;

	currGame.deckCount[0]=10;
	currGame.discardCount[0]=0;
	currGame.handCount[0]=1;

	currGame.whoseTurn=0;
	currGame.hand[0][0]=adventurer;

	for(i;i<10;i++){
		currGame.deck[0][i]=gold;
	}

	adventurerEffect(0,0,0,0,&currGame,0,&bonus);

	if(currGame.hand[0][0]==gold)
		printf("PASS: Succesfully discarded adventurer card and removal of treasure card.\n");
	else
		printf("FAIL: Unsuccesful draw of treasure card / removal of adventurer card. \n");

	if(currGame.handCount[0]==2) 
		printf("PASS: Succesfully stop drawing at 2 treasure cards.\n");
	else
		printf("FAIL: Unsuccesful stop at 2 treasure cards. (%i)\n",currGame.handCount[0]);

	
	if(currGame.discardCount[0]==1 && currGame.discard[0][0]==adventurer)
		printf("PASS: Successful addition of adventurer to discard pile on use.\n");
	else
		printf("FAIL: Card not added to discard pile successfully. (discard count: %i, card: %i)\n",currGame.discardCount[0],currGame.discard[0][0]);

	currGame.deck[0][2]=village;
	currGame.deck[0][3]=village;


	for(i=0;i<2;i++){
		currGame.hand[0][i]=adventurer;
		currGame.handCount[0]++;
		adventurerEffect(0,0,0,0,&currGame,0,&bonus);
	}

	for(i=0;i<currGame.handCount[0];i++){
		if(currGame.hand[0][i]==!(gold|silver|copper))
			treasureTracker=1;
	}
	if(treasureTracker==1)
		printf("FAIL: All cards in hand not treasure cards.\n");
	else
		printf("PASS: All cards in hand are treasure cards.\n");

	return 0;
}
