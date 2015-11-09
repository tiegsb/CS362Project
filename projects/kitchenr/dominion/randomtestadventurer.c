#include "dominion.h"
#include "dominion.c"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <signal.h>





#define SEED 1
#define TOTAL_MAX_SIZE 10

/************************************************************************


	Adventurer random tester
	By Ryan Kitchen
	
	Tests cardEffect based on the following parameters;
	Deck size
	Discard size
	Deck coins
	Discard coins
	Output coins

	Reports segfaults and infinite loops

*************************************************************************/




void generateRandomDeckAndDiscard(int player, struct gameState *state,int maxtotalsize){
	int decksize=rand()%maxtotalsize;
	int discardsize=maxtotalsize-decksize;
	for(int i=0;i<decksize;i++) state->deck[player][i]=curse+rand()%treasure_map;
	for(int i=0;i<discardsize;i++) state->discard[player][i]=curse+rand()%treasure_map;
	state->deckCount[player]=decksize;
	state->discardCount[player]=discardsize;
}

int countDeckCoins(int player, struct gameState *state){
	int count=0;
	for(int i=0;i<state->deckCount[player];i++){
		int card=state->deck[player][i];
		if(card >= copper && card <=gold) count++;
	}
	return count;
}

int countDiscardCoins(int player, struct gameState *state){
	int count=0;
	for(int i=0;i<state->discardCount[player];i++){
		int card=state->discard[player][i];
		if(card >= copper && card <=gold) count++;
	}
	return count;
}

int countDrawnCoins(int player, struct gameState *state){
	int count=0;
	for(int i=5;i<state->handCount[player];i++){
		int card=state->hand[player][i];
		if(card >= copper && card <=gold) count++;
	}
	return count;
}



static void sigHandler(int signo){
	if(signo == SIGSEGV) printf("INVALID: Segfault\n");
	if(signo == SIGALRM) printf("INVALID: Timed out- infinite loop\n");
	exit(0);
}




int main(){
	

	srand(clock());
	signal(SIGINT,sigHandler);
	signal(SIGALRM,sigHandler);

	struct gameState *state=newGame();
	initializeGame(2,kingdomCards(adventurer,council_room,feast,gardens,mine,remodel,smithy,village,baron,great_hall),SEED,state);
	generateRandomDeckAndDiscard(0,state,TOTAL_MAX_SIZE);

	int deckcoins=countDeckCoins(0,state);
	int discardcoins=countDiscardCoins(0,state);
	int deckcount=state->deckCount[0];
	

	printf("Hand size:%d Deck size:%2d Deck coins:%2d Discard size:%2d Discard coins:%2d Output Coins:",state->handCount[0],state->deckCount[0],deckcoins,state->discardCount[0],discardcoins);
	alarm(2);
	adventurerEffect(0,state);
	int outputcoins=countDrawnCoins(0,state);
	printf("%d results:",countDrawnCoins(0,state));
	if(deckcount>1){
		if(deckcoins >=2 && outputcoins==2) printf("valid\n");
		else if(deckcoins <2 && outputcoins==deckcoins) printf("valid\n");
		else printf("INVALID: output coins != input coins\n");
		return 0;
	}
	if(deckcoins+discardcoins>=2){
		if(outputcoins == 2) printf("valid\n");
		if(outputcoins > 2) printf("INVALID: too many coins\n");
		if(outputcoins < 2) printf("INVALID: too few coins\n");
		return 0;
	}
	if(outputcoins == deckcoins+discardcoins) printf("valid\n");
	else printf("INVALID: output coins != input coins\n");
	return 0;
}	
		


	


