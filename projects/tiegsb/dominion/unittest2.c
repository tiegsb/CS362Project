/*
Brian Tiegs
CS 362 - Assignment 3
Test function isGameOver()
Tests if game is over when there are 0 province cards
Tests if game continues when there is 1 province card
Tests if game is over when there are 3 empty card piles excluding province
Tests if game is not over when there are 2 empty card piles excluding province
*/

#include "interface.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>


int main(){
	int i, j, k;
	struct gameState state;
	char cardName1[MAX_STRING_LENGTH], cardName2[MAX_STRING_LENGTH], cardName3[MAX_STRING_LENGTH];
	int passCount = 0;
	int failCount = 0;
	int testCount = 0;

	printf("Starting tests for \"isGameOver\"...\n\n");

	//set state
	memset(&state, 0, sizeof(struct gameState));

	//loop through each type of card and set supplyCount to 1
	for(i=0; i<27; i++){
		state.supplyCount[i]=1;
	}

	//game should continue since all cards have a supply of 1
	if(isGameOver(&state) == 0){
		printf("PASS - isGameOver returns 0 when all cards have a supply of 1\n");
		passCount++;
	}
	else{
		printf("FAIL - isGameOver does not return 0 when all cards have a supply of 1\n");
		failCount++;
	}
	testCount++;

	//game should end when province card equals 0
	state.supplyCount[province]=0;
	if(isGameOver(&state) == 1){
		printf("PASS - isGameOver returns 1 when province card supply count reaches 0\n");
		passCount++;
	}
	else{
		printf("FAIL - isGameOver does not return 1 when province card supply reaches 0\n");
		failCount++;
	}
	testCount++;

	//reset supply count
	for(i=0; i<27; i++){
		state.supplyCount[i]=1;
	}

	//check when 3 cards are empty the game ends
	//tests all possible combinations of 3 empty card piles
	for(i=0; i<25; i++){
		state.supplyCount[i]=0;
		cardNumToName(i, cardName1);
		for(j=i+1; j<26; j++){
			state.supplyCount[j]=0;
			cardNumToName(j, cardName2);
			for(k=j+1; k<27; k++){
				state.supplyCount[k]=0;
				cardNumToName(k, cardName3);

				//ignore test if province supply is 0
				if((state.supplyCount[province] != 0)){
					if(isGameOver(&state) == 1){
						printf("PASS - isGameOver returns 1 when 3 card piles are empty - Cards with 0 supply count: %s, %s and %s\n", cardName1, cardName2, cardName3);
						passCount++;
					}
					else{
						printf("FAIL - isGameOver does not return 1 when 3 card piles are empty - Cards with 0 supply count: %s, %s and %s\n", cardName1, cardName2, cardName3);
						failCount++;
					}
					testCount++;
				}

				//reset supply count
				state.supplyCount[k]=1;
			}
			state.supplyCount[j]=1;
		}
		state.supplyCount[i]=1;
	}

	//check if game continues when 2 cards are empty
	//tests all possible combinations of 2 empty card piles
	for(i=0; i<26; i++){
		state.supplyCount[i]=0;
		cardNumToName(i, cardName1);
		for(j=i+1; j<27; j++){
			state.supplyCount[j]=0;
			cardNumToName(j, cardName2);

			//ignore test if province supply is 0
			if((state.supplyCount[province] != 0)){
				if(isGameOver(&state) == 0){
					printf("PASS - isGameOver returns 0 when 2 card piles are empty - Cards with 0 supply count: %s and %s\n", cardName1, cardName2);
					passCount++;
				}
				else{
					printf("FAIL - isGameOver does not return 0 when 2 card piles are empty - Cards with 0 supply count: %s and %s\n", cardName1, cardName2);
					failCount++;
				}
				testCount++;
			}

			//reset supply count
			state.supplyCount[j]=1;
		}
		state.supplyCount[i]=1;
	}

	//print summary
	printf("\nTesting complete for \"isGameOver\"\n\n");
	printf("Summary:\n");
	printf("Tests run: %d\nTests passed: %d\nTests failed: %d\n\n", testCount, passCount, failCount);

	return 0;
}
