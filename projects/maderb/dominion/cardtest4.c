#include <stdio.h>
#include <stdlib.h>

#include "dominion.h"

//Unit test for smithyEffect() card/function

int main(int argc, char* argv[]){
	int i=0;
	int bonus;
	struct gameState currGame;

	printf("UNIT TEST FOR smithyEffect() FUNCTION:\n");

	currGame.playedCards[0]=0;
	currGame.playedCardCount=0;

	currGame.deckCount[0]=12;
	currGame.discardCount[0]=0;
	currGame.handCount[0]=1;

	currGame.whoseTurn=0;

	for(i=0;i<4;i+=3){
		currGame.deck[0][i]=copper;
		currGame.deck[0][i+1]=silver;
		currGame.deck[0][i+2]=gold;
	}
	currGame.hand[0][0]=smithy;

	smithyEffect(0,0,0,0,&currGame,0,&bonus);

	if(currGame.handCount[0]==3 && currGame.hand[0][0]!=smithy)
		printf("PASS: Succesfully drew 3 cards and played/discarded smithy card.\n");
	else{
		printf("FAIL: ");
		if(currGame.hand[0][0]==smithy){	
			printf("Did not discard smithy.\n");
			if(currGame.handCount[0]>6)
				printf("Drew too many cards.\n");
					if(currGame.hand[0][1]!=copper||currGame.hand[0][2]!=silver||currGame.hand[0][2]!=gold)
						printf("Incorrect card discarded.\n");

		}
		else if(currGame.handCount[0] > 5)
			printf("Drew too many cards.\n"); 
		else
			printf("Error in draw/discard.\n");
	}	
	
	printf("\n");

	return 0;
}
