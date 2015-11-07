#include <stdio.h>
#include <stdlib.h>

#include "dominion.h"

//Unit test for adventurerEffect() card/function

int main(int argc, char* argv[]){
	int bonus;
	struct gameState currGame;

	printf("UNIT TEST FOR outpostEffect() FUNCTION:\n");

	currGame.playedCards[0]=0;
	currGame.playedCardCount=0;

	currGame.deckCount[0]=0;
	currGame.discardCount[0]=0;
	currGame.handCount[0]=1;

	currGame.whoseTurn=0;
	currGame.hand[0][0]=outpost;

	outpostEffect(currGame.hand[0][0],0,0,0,&currGame,0,&bonus);
	if(currGame.handCount[0]==0)
		printf("PASS: Successfully remove card from user's hand.\n");
	else
		printf("FAIL: Card not removed from user's hand or improper decrement of handCount.\n");

	
	if(currGame.discardCount[0]==1 && currGame.discard[0][0]==outpost)
		printf("PASS: Successful addition of outpost to discard pile on use.\n");
	else
		printf("FAIL: Card not added to discard pile successfully. (discard count: %i, card: %i\n",currGame.discardCount[0],currGame.discard[0][0]);

	if(currGame.outpostPlayed==1)
		printf("PASS: outpostPlayed variable succesfully adjusted.\n");
	else
		printf("FAIL: outpostPlayed variable not adjusted. %i\n",currGame.outpostPlayed);
	
	if(currGame.playedCardCount==1 && currGame.playedCards[0]==outpost)
		printf("PASS: Successfully registered as played card.\n");
	else
		printf("FAIL: Played card not registering.\n");

	return 0;
}
