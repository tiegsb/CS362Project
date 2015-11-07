#include <stdio.h>
#include <stdlib.h>

#include "dominion.h"

//Test for scoreFor()

int main(int argc, char* argv[]){
	
	struct gameState currGame;
	int i=0;

	printf("UNIT TESTS FOR scoreFor() FUNCTION:\n");

	currGame.handCount[0]=3;
	currGame.discardCount[0]=0;
	currGame.deckCount[0]=0;

	currGame.hand[0][0]=province;
	currGame.hand[0][1]=duchy;
	currGame.hand[0][2]=estate;

	if(scoreFor(0,&currGame)==10){
		printf("PASS: Correct value from hand. (10)\n");
	}else{
		printf("FAIL: Incorrect value from hand. (%i)\n",scoreFor(0,&currGame));
	}

	currGame.handCount[0]=1;
	currGame.hand[0][0]=province;
	if(scoreFor(0,&currGame)==6){
		printf("PASS: Correct value for Province. (6)\n");
	}else{
		printf("FAIL: Incorrect value for Province. (%i)\n",scoreFor(0,&currGame));
	}

	currGame.hand[0][0]=duchy;
	if(scoreFor(0,&currGame)==3){
		printf("PASS: Correct value for Duchy. (3)\n");
	}else{
		printf("FAIL: Incorrect value for Duchy. (%i)\n",scoreFor(0,&currGame));
	}
	
	currGame.hand[0][0]=estate;
	if(scoreFor(0,&currGame)==1){
		printf("PASS: Correct value for Estate. (1)\n");
	}else{
		printf("FAIL: Incorrect value for Estate. (%i)\n",scoreFor(0,&currGame));
	}

	currGame.hand[0][0]=curse;
	if(scoreFor(0,&currGame)==-1){
		printf("PASS: Correct value for Curse. (-1)\n");
	}else{
		printf("FAIL: Incorrect value for Curse. (%i)\n",scoreFor(0,&currGame));
	}

	currGame.hand[0][0]=great_hall;
	if(scoreFor(0,&currGame)==1){
		printf("PASS: Correct value for Great Hall. (1)\n");
	}else{
		printf("FAIL: Incorrect value for Great Hall. (%i)\n",scoreFor(0,&currGame));
	}
	
	currGame.handCount[0]=0;
	currGame.discardCount[0]=2;
	currGame.discard[0][0]=curse;
	currGame.discard[0][1]=curse;

	if(scoreFor(0,&currGame)==-2){
		printf("PASS: Correct value from discard. (-2)\n");
	}else{
		printf("FAIL: Incorrect value from discard. (%i)\n",scoreFor(0,&currGame));
	}

	currGame.discardCount[0]=0;
	currGame.deckCount[0]=4;
	currGame.deck[0][0]=province;
	currGame.deck[0][1]=estate;
	currGame.deck[0][2]=estate;
	currGame.deck[0][3]=duchy;
	if(scoreFor(0,&currGame)==11){
		printf("PASS: Correct value from deck. (11)\n");
	}else{
		printf("FAIL: Incorrect value from deck. (%i)\n",scoreFor(0,&currGame));
	}

	
	currGame.deckCount[0]=21;
	for (i=0; i<20; i++){
		currGame.deck[0][i]=copper;
	}
	currGame.deck[0][20]=gardens;
	if(scoreFor(0,&currGame)==2){
		printf("PASS: Correct value from gardens. (2)\n");
	}else{
		printf("FAIL: Incorrect value from gardens. (%i)\n",scoreFor(0,&currGame));
	}

	printf("\n");

	return 0;
}
