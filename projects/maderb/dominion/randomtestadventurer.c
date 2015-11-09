#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

#include"dominion.h"

int CardGen(int reference);
void checkResult(struct gameState currState,int k,int* adventurersPlayed);
int stringConverter(char* strConverted);

int main(int argc, char** argv){
	srand(time(NULL));

	struct gameState currState;
	int densityAdj;
	int i, j, k, executionNum, selector, adventurerNum;
	int adventurersPlayed[4];

	executionNum = 1000;
	for(k=0; k<executionNum ; k++){
		currState.numPlayers = (rand()%3) + 2; 				//2<=player number <=4
		//stock decks for all players with randomized card number from 2 -> MAX_DECK.
		for(j=0;j<currState.numPlayers;j++){
			currState.discardCount[j] = 0;				//set discard count to 0;
			currState.deckCount[j] = (rand()%(MAX_DECK-1))+2;	//2 <= decksize <= MAX_DECK
			densityAdj = (rand()%3) + 3;				//50% < treasure probability < 100%
			//printf ( "==================PLAYER %i====================\n",(j+1));
			for(i=0;i<currState.deckCount[j];i++){
				selector = rand() % densityAdj;
				currState.deck[j][i] = CardGen(selector);		
				//printf("deck[%i]: %i\n",i,currState.deck[j][i]);
			}
			//stock hands with randomized card number from 1 - MAX_HAND.
			currState.handCount[j] = (rand()%(MAX_HAND-1))+2;	//1 <= handsize <= MAX_HAND
			//printf ( "==================PLAYER %i====================\n",(j+1));
			for(i=0;i<currState.handCount[j];i++){
				currState.hand[j][i] = village;
				//printf("deck[%i]: %i\n",i,currState.deck[j][i]);
			}
			adventurerNum = (rand()%currState.handCount[j])+1;	//introduce between 1 and handCount adventurer cards
			for(i=0;i<adventurerNum;i++){
				currState.hand[j][(rand() % currState.handCount[j])]=adventurer;	//randomly place 'adventurerNum' adventurer cards in hand. Allows overwrite.
			}
		}

		//decks/hands/discard all stocked. Deploy the Adventurers!
		for(j=0;j<currState.numPlayers;j++){
			currState.playedCardCount=0;
			for(i=0;i<currState.handCount[j];i++){
				if(currState.hand[j][i] == adventurer){
					currState.whoseTurn=j;
					adventurerEffect(0,0,0,0,&currState,i,NULL);
				}
			}
			adventurersPlayed[j]=currState.playedCardCount;
		}

		checkResult(currState,(k+1),adventurersPlayed);

	}

	return 0;
}

int CardGen(int reference){
	switch(reference){
		case 0:
			return gold;
		case 1:
			return silver;
		case 2:
			return copper;
	}
	return village;
}

void checkResult(struct gameState currState, int k,int* adventurersPlayed){
	int i,j,playerNum;
	int treasureCount[currState.numPlayers];
	int treasuresRemaining;

	printf("==================================TEST #%i=======================================\n",k);
	
	for(i=0;i<currState.numPlayers;i++){
		treasureCount[i]=0;
		playerNum=i+1;
		//tabulate number of treasure cards per player:
		for(j=0;j<currState.handCount[i];j++){
			switch(currState.hand[i][j]){
				case copper:
					treasureCount[i]++;
					break;
				case silver:
					treasureCount[i]++;
					break;
				case gold:
					treasureCount[i]++;
			}
		}
		treasuresRemaining=0;
		for(j=0;j<currState.deckCount[i];j++){
			switch(currState.deck[i][j]){
				case copper:
					treasuresRemaining=1;
				case silver:
					treasuresRemaining=1;
				case gold:
					treasuresRemaining=1;
			}		
		}
		if((treasureCount[i] < (adventurersPlayed[i]*2))&&(treasuresRemaining==1))	//if discard pile not shuffled in, and 2 cards not drawn for each adventurer 
												//card played, error.
			printf("PLAYER %i: Not enough treasures drawn with treasures remaining in deck. (Adventurers Played: %i, Treasures Drawn: %i, DeckSize: %i)\n",playerNum,adventurersPlayed[i],treasureCount[i],currState.deckCount[i]);
		if(treasureCount[i] > (adventurersPlayed[i]*2))
			printf("PLAYER %i: Too many treasures drawn. (Adventurers Played: %i, Treasures Drawn: %i)\n",playerNum,adventurersPlayed[i],treasureCount[i]);
		if(currState.discardCount[i] < adventurersPlayed[i])
			printf("PLAYER %i: All adventurers not discarded. (Adventurers Played: %i, DiscardedCards: %i)\n",playerNum, adventurersPlayed[i],currState.discardCount[i]);
	}
		
}

int stringConverter(char* strConverted){
	int val=0;
	int i;

	for(i=0;isdigit(strConverted[i]);i++){
		val*=10;
		val += (strConverted[i]-'0');
	}

	return val;
} 
