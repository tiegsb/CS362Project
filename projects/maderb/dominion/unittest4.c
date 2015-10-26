#include <stdio.h>
#include <stdlib.h>

#include "dominion.h"

int main(int argc, char* argv[]){
	struct gameState currGame;
	int i=0;

	currGame.handCount[0]=0;			//NO CARDS IN HAND AT START OF TEST.

	currGame.deckCount[0]=5;		//STOCK DECK FOR DRAW. ORDER FROM TOP: CURSE, DUCHY, ESTATE, PROVINCE, VILLAGE.
	currGame.deck[0][0]=village;
	currGame.deck[0][1]=province;
	currGame.deck[0][2]=estate;
	currGame.deck[0][3]=duchy;
	currGame.deck[0][4]=curse;
	
	currGame.discardCount[0]=3;		//STOCK DISCARD PILE FOR RESHUFFLE.
	currGame.discard[0][0]=copper;
	currGame.discard[0][1]=silver;
	currGame.discard[0][2]=gold;

	printf("UNIT TESTS FOR drawCard() FUNCTION:\n");

	drawCard(0,&currGame);
	if(currGame.hand[0][0]==curse)
		printf("PASS: Correct card in hand. (curse).\n");
	else
		printf("FAIL: Incorrect card in hand. Expected curse.\n");

	drawCard(0,&currGame);
	if(currGame.hand[0][1]==duchy)
		printf("PASS: Correct card in hand. (duchy).\n");
	else
		printf("FAIL: Incorrect card in hand. Expected duchy.\n");

	for(i;i<4;i++){
		drawCard(0,&currGame);
	}

	if(currGame.hand[0][5]==copper || currGame.hand[0][5]==silver || currGame.hand[0][5]==gold)
		printf("PASS: Correct drawn card after deck exhausted (copper|silver|gold).\n");
	else
		printf("FAIL: Incorrect drawn card after deck exhausted !(copper|silver|gold).\n");

	if(currGame.deckCount[0]==2)
		printf("PASS: Correct deckCount. (2)\n");
	else
		printf("FAIL: Incorrect deckCount. (%i)\n",currGame.deckCount[0]);

	if(currGame.handCount[0]==6)
		printf("PASS: Correct handCount. (6)\n");
	else
		printf("FAIL: Incorrect handCount. (%i)\n",currGame.handCount[0]);

	if(currGame.discardCount[0]==0)
		printf("PASS: Correct discardCount. (0)\n");
	else
		printf("FAIL: Incorrect dicardCount. (%i)\n",currGame.discardCount[0]);

	printf("\n");

	return 0;
}
