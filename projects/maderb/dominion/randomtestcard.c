#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

#include"dominion.h"

void checkResult(struct gameState currState,int execNum,int* smithyNum, int* startCards);

int main(int argc, char** argv){
	srand(time(NULL));

	struct gameState currState;
	int i, j, k, executionNum;
	int smithyNum[4],startCards[4];

	executionNum = 1000;
	for(k=0; k<executionNum ; k++){
		currState.numPlayers = (rand()%3) + 2; 				//2<=player number <=4		

		//stock decks for all players with randomized card number from 2 -> MAX_DECK.
		for(j=0;j<currState.numPlayers;j++){
			currState.discardCount[j] = 0;				//set discard count to 1;
			currState.discard[j][0]=gold;					//set one discarded card to treasure. If top card in discard not treasure card, discard shuffled into deck.
			currState.deckCount[j] = (rand()%(MAX_DECK-1))+2;	//2 <= decksize <= MAX_DECK
			//printf ( "==================PLAYER %i====================\n",(j+1));
			for(i=0;i<currState.deckCount[j];i++){
				currState.deck[j][i] = village;		
				//printf("deck[%i]: %i\n",i,currState.deck[j][i]);
			}
		}
		//stock hands with randomized card number from 1 - MAX_HAND.
		for(j=0;j<currState.numPlayers;j++){
			currState.handCount[j] = (rand()%(MAX_HAND-1))+2;
			//printf ( "==================PLAYER %i====================\n",(j+1));
			for(i=0;i<currState.handCount[j];i++){
				currState.hand[j][i] = village;
				//printf("deck[%i]: %i\n",i,currState.deck[j][i]);
			}
			smithyNum[0] = rand() % (currState.handCount[j]+1);	//introduce between 0 and handCount smithy cards
			for(i=0;i<smithyNum[0];i++){
				currState.hand[j][(rand() % currState.handCount[j])]=smithy;	//randomly place 'adventurerNum' adventurer cards in hand. Allows overwrite.
			}
		}
		
		//decks/hands/discards all stocked. Smithies away!
		for(j=0; j < currState.numPlayers; j++){
			currState.whoseTurn=j;
			currState.playedCardCount=0;
			startCards[j] = currState.handCount[j];
			for(i=0;i < currState.handCount[j];i++){
				if(currState.hand[j][i]==smithy)
					smithyEffect(0,0,0,0,&currState,i,0);
			}
			smithyNum[j]=currState.playedCardCount;
		}
		
		checkResult(currState,k+1,smithyNum,startCards);
		
	}

	return 0;
}

void checkResult(struct gameState currState,int execNum,int* smithyNum, int* startCards){
	int i,j;
	printf("=======================TEST %i============================\n",execNum);
	
	for(i=0;i < currState.numPlayers;i++){
		int incorrectDisc=-1;
		if(((2*smithyNum[i]) > (currState.handCount[i] - startCards[i]))&&(currState.deckCount[i]!=0))
			printf("Not enough cards drawn with cards remaining in deck. (Smithies Played: %i, New Cards in Hand: %i, Final Deck Count: %i)\n",smithyNum[i],(currState.handCount[i]-startCards[i]),currState.deckCount[i]);
		if((2*smithyNum[i]) < ((currState.handCount[i]- startCards[i])))
			printf("Too many cards drawn. (Smithies Played: %i, New Cards in Hand: %i, Final Deck Count: %i)\n",smithyNum[i],(currState.handCount[i]-startCards[i]),currState.deckCount[i]);
		if(smithyNum[i] != currState.discardCount[i])
			printf("Improper number of cards discarded. (Discard Count: %i, Smithy Count: %i)\n",currState.discardCount[i],smithyNum[i]);
		for(j=0;j<currState.discardCount[i];j++){
			if(currState.discard[i][j]!=smithy)
				incorrectDisc=j;
		}
		if(incorrectDisc!=-1)
			printf("Improper addition to discard pile at discard position %i. (Only reporting first instance)\n",incorrectDisc);
		incorrectDisc=-1;
		for(j=0;j<currState.handCount[i];j++){
			if(currState.hand[i][j]==smithy){
				incorrectDisc=j;
			}
		}
		if(incorrectDisc!=-1)
			printf("Improper removal of discarded card from hand at hand position %i. (Only reporting first instance)\n",incorrectDisc);
	}
}
