/*
Brian Tiegs
CS 362 - Assignment 3
Test function getWinners()
Tests for correct winner when number of players is changed
Tests for correct winner when whoseTurn is changed
Tests for correct winner for each player
Tests for correct winners when there is a tie between 2 players and both have even amount of turns
*/

#include "interface.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>

int testPlayersArray(int players[MAX_PLAYERS], int a, int b, int c, int d){
	if(players[0] == a && players[1] == b && players[2] == c && players[3] == d)
		return 1;
	return 0;
}

int main(){
	int a, b, c, d, i, j, k;
	struct gameState state;
	int players[MAX_PLAYERS];
	int passCount = 0;
	int failCount = 0;
	int testCount = 0;

	printf("Starting tests for \"getWinners\"...\n\n");

	memset(&state, 0, sizeof(struct gameState));

	c=d=0;
	//all players have same cards, winners should go to players who have more turns
	for(state.numPlayers=2; state.numPlayers<=MAX_PLAYERS; state.numPlayers++){
		if(state.numPlayers == 3){c=1;}
		if(state.numPlayers == 4){d=1;}
		getWinners(players, &state);
		if(testPlayersArray(players, 0, 1, c, d)){
			printf("PASS - getWinners returns correct players array with %d players and even score - array returned: %d %d %d %d\n", state.numPlayers, players[0], players[1], players[2], players[3]);
			passCount++;
		}
		else{
			printf("FAIL - getWinners returns incorrect players array with %d players and even score - array returned: %d %d %d %d\n", state.numPlayers, players[0], players[1], players[2], players[3]);
			failCount++;
		}
		testCount++;
	}

	c=d=0;
	//all have same cards, all players have same amount of turns, all players should be winners
	for(state.numPlayers=2; state.numPlayers<=MAX_PLAYERS; state.numPlayers++){
		//set whoseturn to last player
		state.whoseTurn=state.numPlayers-1;

		if(state.numPlayers == 3){c=1;}
		if(state.numPlayers == 4){d=1;}
		getWinners(players, &state);
		if(testPlayersArray(players, 1, 1, c, d)){
			printf("PASS - getWinners returns correct players array with %d players, even score and even amount of turns - Expected Result: players[ ]: 1 1 %d %d - Actual Result: players[ ]: %d %d %d %d\n", state.numPlayers, c, d, players[0], players[1], players[2], players[3]);
			passCount++;
		}
		else{
			printf("FAIL - getWinners does not return correct players array with %d players, even score and even amount of turns - Expected Result: players[ ]: 1 1 %d %d - Actual Result: players[ ]: %d %d %d %d\n", state.numPlayers, c, d, players[0], players[1], players[2], players[3]);
			failCount++;
		}
		testCount++;
	}

	//test if correct array is returned when each player wins
	for(i=0; i<MAX_PLAYERS; i++){
		//give player winning hand
		for(j=0; j<MAX_HAND; j++){
			state.hand[i][j] = province;
		}
		state.handCount[i] = MAX_HAND;
		state.numPlayers = MAX_PLAYERS;

		getWinners(players, &state);

		a=b=c=d=0;
		if(i == 0){a=1;}
		if(i == 1){b=1;}
		if(i == 2){c=1;}
		if(i == 3){d=1;}

		if(testPlayersArray(players, a, b, c, d)){
			printf("PASS - getWinners returns correct players array when player %d wins - Expected Result: players[ ]: %d %d %d %d - Actual Result: players[ ]: %d %d %d %d\n", i+1, a, b, c, d, players[0], players[1], players[2], players[3]);
			passCount++;
		}
		else{
			printf("FAIL - getWinners does not return correct players array when player %d wins - Expected Result: players[ ]: %d %d %d %d - Actual Result: players[ ]: %d %d %d %d\n", i+1, a, b, c, d, players[0], players[1], players[2], players[3]);
			failCount++;
		}
		testCount++;

		//reset state
		memset(&state, 0, sizeof(struct gameState));
	}

	//test if correct array is returned when 2 players tie
	for(i=0; i<MAX_PLAYERS-1; i++){
		for(j=i+1; j<MAX_PLAYERS; j++){
			//give both players winning hand
			for(k=0; k<MAX_HAND; k++){
				state.hand[i][k] = province;
				state.hand[j][k] = province;
			}
			state.handCount[i] = MAX_HAND;
			state.handCount[j] = MAX_HAND;
			state.numPlayers = MAX_PLAYERS;
			//give players even amount of turns
			state.whoseTurn = MAX_PLAYERS-1;

			getWinners(players, &state);

			a=b=c=d=0;
			if(i == 0 || j == 0){a=1;}
			if(i == 1 || j == 1){b=1;}
			if(i == 2 || j == 2){c=1;}
			if(i == 3 || j == 3){d=1;}

			if(testPlayersArray(players, a, b, c, d)){
				printf("PASS - getWinners returns correct players array when player %d and player %d tie - Expected Result: players[ ]: %d %d %d %d - Actual Result: players[ ]: %d %d %d %d\n", i+1, j+1, a, b, c, d, players[0], players[1], players[2], players[3]);
				passCount++;
			}
			else{
				printf("FAIL - getWinners does not return correct players array when player %d and player %d tie - Expected Result: players[ ]: %d %d %d %d - Actual Result: players[ ]: %d %d %d %d\n", i+1, j+1, a, b, c, d, players[0], players[1], players[2], players[3]);
				failCount++;
			}
			testCount++;

			//reset state
			memset(&state, 0, sizeof(struct gameState));
		}
	}

	//print summary
	printf("\nTesting complete for \"getWinners\"\n\n");
	printf("Summary:\n");
	printf("Tests run: %d\nTests passed: %d\nTests failed: %d\n\n", testCount, passCount, failCount);

	return 0;
}
