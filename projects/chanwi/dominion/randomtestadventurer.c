/*Wilson Chan
 *Random Testing on Adventurer Card
 *CS362 - Assignment 4
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "interface.h"

#define NUM_TESTRUNS 50000

int main(){
	int i;
	int numPlayers;
	int chosenPlayer;
	int adventurerPos;
	int randomSeed;
	int bonus = 0;
	
	int errCount = 0;
	int errTurn = 0;
	int errAction = 0;
	int errCoins = 0;
	int errHand = 0;
	int errDeck = 0;
	int errDiscard = 0;
	int errHandCount = 0;
	int errDeckCount = 0;
	int errDiscardCount = 0;
	
	int passCount = 0;
	int passTurn = 0;
	int passAction = 0;
	int passCoins = 0;
	int passHand = 0;
	int passDeck = 0;
	int passDiscard = 0;
	int passHandCount = 0;
	int passDeckCount = 0;
	int passDiscardCount = 0;

	int king[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int ktv[17] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, curse, estate, duchy, province, copper, silver, gold};
	
	for (i = 0; i < NUM_TESTRUNS; i++){
		int j;
		int k;
		int treasureDeck = 0;
		int treasureDiscard = 0;
		int ktvIndex = 0;
		adventurerPos = -1;
		
		struct gameState preTest;
		struct gameState G;
		
		//seed for rand()
		srand(time(NULL));

		//Generate a random number of players between 2 and the maximum
		numPlayers = rand() % (MAX_PLAYERS -1) + 2;

		//Pick a random player
		chosenPlayer = rand() % (numPlayers -1) +2;
	
		//Generate a random seed value from 1 to 1000
		randomSeed = rand() % 1000 + 1;
		
		initializeGame(numPlayers, king, randomSeed, &G);

		//randomize hand, deck, discard count for all players
		for (j = 0; j < numPlayers; j++){
			G.handCount[j] = rand() % (MAX_HAND - HANDSIZE + 1) + HANDSIZE;
			G.deckCount[j] = rand() % (MAX_DECK + 1);
			G.discardCount[j] = rand() % (MAX_DECK + 1);
		}

		//randomize hand for all players
		for (j = 0; j < numPlayers; j++){
			for (k = 0; k < G.handCount[j]; k++){
				ktvIndex = rand() % 17;
				G.hand[j][k] = ktv[ktvIndex];
			}
		}
	
		//randomize deck for all players
		for (j = 0; j < numPlayers; j++){
			for (k = 0; k < G.deckCount[j]; k++){
				ktvIndex = rand() % 17;
				G.deck[j][k] = ktv[ktvIndex];
			}
		}
		
		//randomize discard for all players
		for (j = 0; j < numPlayers; j++){
			for (k = 0; k < G.discardCount[j]; k++){
				ktvIndex = rand() % 17;
				G.discard[j][k] = ktv[ktvIndex];
			}
		}
		
		//Check for adventurer card in hand of chosen player
		for (j = 0; j < G.handCount[chosenPlayer]; j++){
			if (G.hand[chosenPlayer][j] == adventurer){
				adventurerPos = j;
				break;
			}
		}
	
		//if no adventurer card found in hand, put one in hand
		if (adventurerPos == -1){
			G.hand[chosenPlayer][0] = adventurer;
			adventurerPos = 0;
		}
	
		//check number of treasure cards in deck
		for (j = 0; j < G.handCount[chosenPlayer]; j++){
			if (G.hand[chosenPlayer][j] == copper || G.hand[chosenPlayer][j] == silver || G.hand[chosenPlayer][j] == gold){
				treasureDeck++;
			}
		}
		
		//check number of treasure cards in discard		
		for (j = 0; j < G.discardCount[chosenPlayer]; j++){
			if (G.discard[chosenPlayer][j] == copper || G.hand[chosenPlayer][j] == silver || G.hand[chosenPlayer][j] == gold){
				treasureDiscard++;
			}
		}
		
		//Setup beginning of turn for chosen player
		G.whoseTurn = chosenPlayer;
		G.numActions = 1;
		G.coins = updateCoins(G.whoseTurn, &G, bonus);
	
		//Save gameState prior to playing adventurer card
		memcpy(&preTest, &G, sizeof(struct gameState));

		//Play adventurer card
		playCard(adventurerPos, -1, -1, -1, &G);

	//Results of playing adventurer card by Chosen player
		//Check Whose Turn
		if (preTest.whoseTurn == G.whoseTurn){
			passCount++;
			passTurn++;
		} else {
			errCount++;
			errTurn++;
		}
		
		//Check Number of Actions of chosen Player
		if (preTest.numActions - 1 == G.numActions){
			passCount++;
			passAction++;
		} else {
			errCount++;
			errAction++;
		}

		//Check Coin Total of Chosen Player
		if ((treasureDeck + treasureDiscard) == 0){
			if (preTest.coins == G.coins){
				passCount++;
				passCoins++;
			} else {
				errCount++;
				errCoins++;
			}
		} else if ((treasureDeck + treasureDiscard) > 0){
			if (preTest.coins != G.coins){
				passCount++;
				passCoins++;
			} else {
				errCount++;
				errCoins++;
			}
		} else {
			errCount++;
			errCoins++;
		}
		
		//Check Hand, Deck, Discard count for all players
		for (j = 0; j < numPlayers; j++){
			if (j == chosenPlayer){
				//Because of the possibility of the shuffle occurring, deckCount and discardCount is totalled together for chosen player
				//No treasure card added to hand
				if ((treasureDeck + treasureDiscard) == 0){
					if (G.handCount[j] == preTest.handCount[j] - 1){
						passCount++;
						passHandCount++;
					} else {
						errCount++;
						errHandCount++;
					}
					//One adventurer card added to discard pile
					if (G.deckCount[j] + G.discardCount[j] == preTest.deckCount[j] + preTest.discardCount[j] + 1){
						passCount++;
						passDeckCount++;
						passDiscardCount++;
					} else {
						errCount++;
						errDeckCount++;
						errDiscardCount++;
					}
				//One treasure card added to hand, adventurer removed from hand					
				} else if ((treasureDeck + treasureDiscard) == 1){
					if (G.handCount[j] == preTest.handCount[j]){
						passCount++;
						passHandCount++;
					} else {
						errCount++;
						errHandCount++;
					}
					//One adventurer card added to discard pile and one treasure card removed from deck					
					if (G.deckCount[j] + G.discardCount[j] == preTest.deckCount[j] + preTest.discardCount[j]){
						passCount++;
						passDeckCount++;
						passDiscardCount++;
					} else {
						errCount++;
						errDeckCount++;
						errDiscardCount++;
					}
				//Two treasure card added to hand, adventurer card removed from hand					
				} else {
					if (G.handCount[j] == preTest.handCount[j] + 1){
						passCount++;
						passHandCount++;
					} else {
						errCount++;
						errHandCount++;
					}
					//One adventurer card added to discard pile and two treasure cards removed from deck						
					if (G.deckCount[j] + G.discardCount[j] == preTest.deckCount[j] + preTest.discardCount[j] - 1){
						passCount++;
						passDeckCount++;
						passDiscardCount++;
					} else {
						errCount++;
						errDeckCount++;
						errDiscardCount++;
					}	
				}
			} else {
				//Hand count for all other players
				if (G.handCount[j] == preTest.handCount[j]){
					passCount++;
					passHandCount++;
				} else {
					errCount++;
					errHandCount++;
				}
				//Deck count for all other players				
				if (G.deckCount[j] == preTest.deckCount[j]){
					passCount++;
					passDeckCount++;				
				} else {
					errCount++;
					errDeckCount++;
				}
				//Discard count for all other players
				if (G.discardCount[j] == preTest.discardCount[j]){
					passCount++;
					passDiscardCount++;
				} else {
					errCount++;
					errDiscardCount++;
				}
			}
		}
		
		//Check hand contents of other players
		for (j = 0; j < numPlayers; j++){
			if (j == chosenPlayer){
				//ignore
			} else {
				int err_flg = 0;
				
				for (k = 0; k < G.handCount[j]; k++){
					if (G.hand[j][k] != preTest.hand[j][k]){
						errCount++;
						errHand++;
						err_flg = 1;
						break;
					}
				}
				if (err_flg == 0){
					passCount++;
					passHand++;
				}
			}
		}

		//Check deck contents of other players
		for (j = 0; j < numPlayers; j++){
			if (j == chosenPlayer){
				//ignore
			} else {
				int err_flg = 0;
				
				for (k = 0; k < G.deckCount[j]; k++){
					if (G.deck[j][k] != preTest.deck[j][k]){
						errCount++;
						errDeck++;
						err_flg = 1;
						break;
					}
				}
				if (err_flg == 0){
					passCount++;
					passDeck++;
				}
			}
		}
		
		//Check discard contents of other players
		for (j = 0; j < numPlayers; j++){
			if (j == chosenPlayer){
				//ignore
			} else {
				int err_flg = 0;
				
				for (k = 0; k < G.discardCount[j]; k++){
					if (G.discard[j][k] != preTest.discard[j][k]){
						errCount++;
						errDiscard++;
						err_flg = 1;
						break;
					}
				}
				if (err_flg == 0){
					passCount++;
					passDiscard++;
				}
			}
		}

		//Clear gameState
		memset(&G, 0, sizeof(struct gameState));
		memset(&preTest, 0, sizeof(struct gameState));
	}

	printf("--------------------------------------\n");
	printf("Test Summary\n");
	printf("--------------------------------------\n");
	printf("Number of Test Runs: %d\n", NUM_TESTRUNS);
	printf("Number of Tests: %d\n", (passCount + errCount));
	printf("Number of Passed Tests: %d\n", passCount);
	printf("Number of Failed Tests: %d\n", errCount);
	printf("--------------------------------------\n");
	printf("Test Details\n");
	printf("--------------------------------------\n");
	printf("Whose Turn - Passed: %d  Failed: %d\n", passTurn, errTurn);
	printf("Number of Actions - Passed: %d  Failed: %d\n", passAction, errAction);
	printf("Coin Total - Passed: %d  Failed: %d\n", passCoins, errCoins);
	printf("Hand Count - Passed: %d  Failed: %d\n", passHandCount, errHandCount);
	printf("Deck Count - Passed: %d  Failed: %d\n", passDeckCount, errDeckCount);
	printf("Discard Count - Passed: %d  Failed: %d\n", passDiscardCount, errDiscardCount);
	printf("Hand Content - Passed: %d  Failed: %d\n", passHand, errHand);
	printf("Deck Content - Passed: %d  Failed: %d\n", passDeck, errDeck);
	printf("Discard Content - Passed: %d  Failed: %d\n", passDiscard, errDiscard);

	return 0;
}