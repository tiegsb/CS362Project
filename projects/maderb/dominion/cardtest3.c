#include <stdio.h>
#include <stdlib.h>

#include "dominion.h"

//Unit test for salvagerEffect() card/function

int main(int argc, char* argv[]){
	
	int bonus;
	struct gameState currGame;

	printf("UNIT TEST FOR salvagererEffect() FUNCTION:\n");

	currGame.playedCards[0]=0;
	currGame.playedCardCount=0;

	currGame.deckCount[0]=0;
	currGame.discardCount[0]=0;
	currGame.handCount[0]=4;

	currGame.coins=0;
	currGame.numBuys=0;
	currGame.whoseTurn=0;

	currGame.hand[0][0]=salvager;
	currGame.hand[0][1]=village;
	currGame.hand[0][2]=salvager;
	currGame.hand[0][3]=silver;

	salvagerEffect(0,1,0,0,&currGame,0,&bonus);

	if(currGame.coins==3)
		printf("PASS: Succesfully gained coins from salvaged card.\n");
	else
		printf("FAIL: Unsuccesful gained coins from salvaged card. \n");

	if(currGame.handCount[0]==2){
		printf("PASS: Succesfully removed salvager and village card from hand.\n");
	}
	else{
		printf("FAIL: ");
		if(currGame.hand[0][0]==village && currGame.handCount[0]==3)
			printf("Targeted card not removed from hand.\n");
		else if(currGame.hand[0][0]==salvager && currGame.handCount[0]==3)
			printf("salvager not removed from hand.\n");
		else if(currGame.handCount[0]<2)
			printf("Too many cards removed from hand.\n");
		else if(currGame.handCount[0]==4)
			printf("No cards discarded.\n");
		else
			printf("Error during discard of salvager or targeted card.\n");
	}
	salvagerEffect(0,0,0,0,&currGame,0,&bonus);
	if(currGame.coins==3)
		printf("PASS: No coins added when no card is targeted.\n");
	else
		printf("FAIL: Coins added when no card is targeted.\n");
	
	printf("\n");

	return 0;
}
