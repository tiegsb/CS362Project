/*
Brian Tiegs
CS 362 - Assignment 3
Test function scoreFor()
Tests for correct calculation of player's score by altering player, handCount, deckCount, discardCount and card type
Tests for any unnecessary alterations to game state
*/

#include "interface.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>


int main(){

	int player;
	int i, j, k;
	struct gameState state;
	int calcScore;
	int actualScore;
	int cardValue;
	int deckTotal;
	char cardName[MAX_STRING_LENGTH];
	int passCount = 0;
	int failCount = 0;
	int testCount = 0;

	printf("Starting tests for \"scoreFor\"...\n\n");

	//loop through each player
	for(player=0; player<MAX_PLAYERS; player++)
	{
		//loop through each card type
		for(i=0; i<27; i++) {

			cardNumToName(i, cardName);

			memset(&state, 0, sizeof(struct gameState));

			//set players hand, deck and discard deck to be entirely composed of a single card type designated by i
			//allows for easy score calculation
			for(j=0; j<MAX_PLAYERS; j++){
				for(k=0; k<MAX_HAND; k++){
					state.hand[j][k] = i;
				}
				for(k=0; k<MAX_DECK; k++){
					state.deck[j][k] = i;
					state.discard[j][k] = i;
				}
			}

			//loop through different values of handCount, discardCount and deckCount
			//checks all combinations of min values, max values, and middle values
			for(state.handCount[player]=0; state.handCount[player]<=MAX_HAND; state.handCount[player]+=250)
			{
				for(state.discardCount[player]=0; state.discardCount[player]<=MAX_DECK; state.discardCount[player]+=250)
				{
					for(state.deckCount[player]=0; state.deckCount[player]<=MAX_DECK; state.deckCount[player]+=250)
					{
						//calculate total
						calcScore = scoreFor(player, &state);

						//calculate deck total
						deckTotal = state.handCount[player] + state.discardCount[player] + state.deckCount[player];

						//get value of each card
						switch(i){
							case curse:
								cardValue = -1;
								break;
							case estate:
								cardValue = 1;
								break;
							case duchy:
								cardValue = 3;
								break;
							case province:
								cardValue = 6;
								break;
							case great_hall:
								cardValue = 1;
								break;
							case gardens:
								cardValue = deckTotal/10;
								break;
							default:
								cardValue = 0;
								break;
						}

						//calculate actual total
						actualScore = deckTotal * cardValue;

						//check if calculated score is correct
						if(calcScore == actualScore){
							printf("PASS - Score calculated correctly - Expected Result: score: %d - Actual Result: score: %d player: %d handCount: %d discardCount: %d deckCount: %d card: %s\n", calcScore, actualScore, player, state.handCount[player], state.discardCount[player], state.deckCount[player], cardName);
							passCount++;
						}
						else{
							printf("FAIL - Score not calculated correctly - Expected Result: score: %d - Actual Result: score: %d player: %d handCount: %d discardCount: %d deckCount: %d card: %s\n", calcScore, actualScore, player, state.handCount[player], state.discardCount[player], state.deckCount[player], cardName);
							failCount++;
						}
						testCount++;
					}
				}
			}
		}
	}

	//check to make sure state was not altered
	if ((state.numPlayers + state.outpostPlayed + state.outpostTurn + state.whoseTurn + state.phase + state.numActions + state.coins + state.numBuys + state.playedCardCount) == 0){
		printf("PASS - Game state was not altered\n");
		passCount++;
	}
	else{
		printf("FAIL - Game state was altered\n");
		failCount++;
	}
	testCount++;

	//print summary
	printf("\nTesting complete for \"forScore\"\n\n");
	printf("Summary:\n");
	printf("Tests run: %d\nTests passed: %d\nTests failed: %d\n\n", testCount, passCount, failCount);

	return 0;
}
