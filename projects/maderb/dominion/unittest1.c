#include<stdio.h>
#include<stdlib.h>

#include "dominion.h"

//unit test for isGameOver()

int main(int argc, char* argv[]){
	struct gameState currState;
	int i=0;

	printf("\nUNIT TEST FOR isGameOver() FUNCTION\n");

	for(i=0;i<25;i++){
		currState.supplyCount[i]=1;
	}
	
	if(isGameOver(&currState)==0){
		printf("PASS: Successful game continuence on all piles stocked.\n");
	}else{
		printf("FAIL: Game continuence not successful on all piles stocked.\n");	
	}

	currState.supplyCount[province]=0;
	if(isGameOver(&currState)==1){
        	printf("PASS: Successful game over output. Province == 0\n");
	}else{
        	printf("FAIL: Failed to return game over due to Province == 0\n");
	}

	currState.supplyCount[province]=1;
	currState.supplyCount[1]=0;
	if(isGameOver(&currState)==0){
		printf("PASS: No game over on 1 supplyCount == 0\n");
	}else{
		printf("FAIL: Game over with only 1 supplyCount == 0\n");
	}

	currState.supplyCount[2]=0;
	if(isGameOver(&currState)==0){
		printf("PASS: No game over on 2 supplyCount == 0\n");	
	}else{
		printf("FAIL: Game over with only 2 supplyCounts == 0\n");
	}
	
	currState.supplyCount[3]=0;
	if(isGameOver(&currState)==1){
		printf("PASS: Game over with 3 stacks empty.\n");
	}else{
		printf("FAIL: No game over with 3 supplyCounts == 0\n");
	}
	
	printf("\n");
	
}
