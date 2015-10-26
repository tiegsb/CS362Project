#include <stdio.h>
#include <stdlib.h>

#include "dominion.h"

//Unit test for getWinners()
int main(int argc, char* argv[]){
	struct gameState currGame;
	int players[MAX_PLAYERS];


	printf("UNIT TEST FOR getWinners() function:\n");

	currGame.numPlayers=3;
	
	currGame.deckCount[0]=1;				//PLAYER 1 SCORE SET TO 1.
	currGame.deck[0][0]=estate;
	currGame.discardCount[0]=0;
	currGame.handCount[0]=0;
	currGame.whoseTurn=0;

	getWinners(players,&currGame);
	if(players[0]==1){					//PLAYER 1 WINS WHEN NO OTHER SCORES AVAILABLE.
		printf("PASS: Player 1 wins.\n");
	}else{
		printf("FAIL: Player 1 does not win.\n");
	}

	currGame.deckCount[1]=1;				//PLAYER 2 SCORE SET TO 3.
	currGame.deck[1][0]=duchy;
	currGame.discardCount[1]=0;
	currGame.handCount[1]=0;
	currGame.whoseTurn=0;
	
	getWinners(players,&currGame);
	if(players[0]==0 && players[1]==1){			//PLAYER 2 WINS WHEN PLAYER 1 SCORE: 1 AND PLAYER 2 SCORE: 3.
		printf("PASS: Player 2 wins\n");
	}else{
		printf("FAIL: Player 2 does not win.\n");
	}
	
	currGame.deck[1][0]=estate;
	getWinners(players,&currGame);
	if(players[0]==0){
		printf("PASS: Player 1 loses in tie where game ends on Player 1's turn.\n");
	}else{
		printf("FAIL: Player 1 wins on tie where game ends on Player 1's turn.\n");	
	}
	
	currGame.whoseTurn=1;
	getWinners(players,&currGame);
	if(players[0]==1 && players[1]==1)
		printf("PASS: Tie when Player 2's turn and both players have same score in deck.\n");
	else
		printf("FAIL: Players do not tie with same score when Player 2's turn on completion.\n");

	currGame.numPlayers=3;						//Player 3 == 6
	currGame.deckCount[2]=1;
	currGame.discardCount[2]=0;
	currGame.handCount[2]=0;
	currGame.deck[2][0]=province;
	getWinners(players,&currGame);
	if(players[2]==1)
		printf("PASS: Player 3 wins with highest score.\n");
	else
		printf("FAIL: Player 3 loses with highest score.\n");

	currGame.numPlayers=4;
	currGame.deckCount[3]=2;
	currGame.discardCount[3]=0;
	currGame.handCount[3]=0;
	currGame.deck[3][0]=province;
	currGame.deck[3][1]=estate;
	getWinners(players,&currGame);
	if(players[3]==1)
		printf("PASS: Player 4 wins with highest score.\n");
	else
		printf("FAIL: Player 4 loses with highest score.\n");

	currGame.deck[3][0]=village;
	currGame.deck[2][0]=estate;
	currGame.whoseTurn=4;
	getWinners(players,&currGame);
	if(players[0]==1 && players[1]==1 && players[2]==1 && players[3]==1)
		printf("PASS: 4 way tie when scores equal and Player 4's turn.\n");
	else
		printf("FAIL: No 4 way tie when all scores equal and Player 4's turn.\n");

	printf("\n");

	return 0;
}

