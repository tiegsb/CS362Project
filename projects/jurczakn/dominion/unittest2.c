/* -----------------------------------------------------------------------
 * Demonstration of how to write unit tests for dominion-base
 * Include the following lines in your makefile:
 *
 * testUpdateCoins: testUpdateCoins.c dominion.o rngs.o
 *      gcc -o testUpdateCoins -g  testUpdateCoins.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int getValue(int card, int num, int total){

	if (card == 0){
		return num * -1;
	}
	else if (card == 1){
		return num * 1;
	}
	else if (card == 2){
		return num * 3;
	}
	else if (card == 3){
		return num * 6;
	}
	else if (card == 4){
		return num * 1;
	}
	else if (card == 5){
		return total / 10;
	}
	return -1000;
}

int main() {
    int i;
    time_t t;
    int seed = 1000;
    int numPlayer = 4;
    int tests = 100;
    int p, r, handCount, deckCount, discardCount, vh1, vh2, vh3, vh4,  vd1, vd2, vd3, vd4, vds1, vds2, vds3, vds4, score1, score2, score3, score4, winner, testWinner, highScore;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    int maxDeckCount = 20;
    int maxDiscardCount = 20;
    // arrays of all victory cards
    /*int curses[MAX_DECK];
    int estates[MAX_DECK];
    int duchys[MAX_DECK];
    int provinces[MAX_DECK];
    int great_halls[MAX_DECK];
    int gardenss[MAX_DECK];*/
    int victoryCards[6][MAX_DECK];
    int players[numPlayer];
    for (i = 0; i < MAX_DECK; i++)
    {
        victoryCards[0][i] = curse;
        victoryCards[1][i] = estate;
        victoryCards[2][i] = duchy;
	victoryCards[3][i] = province;
	victoryCards[4][i] = great_hall;
	victoryCards[5][i] = gardens;
    }
    srand((unsigned) time(&t));

    printf ("TESTING getWinners():\n");
    for (i = 0; i < tests; i++){
	handCount = rand() %maxHandCount;
	deckCount = rand() %maxDeckCount;
	discardCount = rand() %maxDiscardCount;
	vh1 = rand() %6;
	vh2 = rand() %6;
	vh3 = rand() %6;
	vh4 = rand() %6;
	vd1 = rand() %6;
	vd2 = rand() %6;
	vd3 = rand() %6;
	vd4 = rand() %6;
	vds1 = rand() %6;
	vds2 = rand() %6;
	vds3 = rand() %6;
	vds4 = rand() %6;
	memset(&G, 23, sizeof(struct gameState));   //clear gameState
	r = initializeGame(numPlayer, k, seed, &G);
	for (p = 0; p < numPlayer; p++){
		G.deckCount[p] = deckCount;
		G.handCount[p] = handCount;
		G.discardCount[p] = discardCount;
	}
	memcpy(G.hand[0], victoryCards[vh1], sizeof(int) * handCount);
	memcpy(G.deck[0], victoryCards[vd1], sizeof(int) * deckCount);
	memcpy(G.discard[0], victoryCards[vds1], sizeof(int) * discardCount);
	memcpy(G.hand[1], victoryCards[vh2], sizeof(int) * handCount);
	memcpy(G.deck[1], victoryCards[vd2], sizeof(int) * deckCount);
	memcpy(G.discard[1], victoryCards[vds2], sizeof(int) * discardCount);
	memcpy(G.hand[2], victoryCards[vh3], sizeof(int) * handCount);
	memcpy(G.deck[2], victoryCards[vd3], sizeof(int) * deckCount);
	memcpy(G.discard[2], victoryCards[vds3], sizeof(int) * discardCount);
	memcpy(G.hand[3], victoryCards[vh4], sizeof(int) * handCount);
	memcpy(G.deck[3], victoryCards[vd4], sizeof(int) * deckCount);
	memcpy(G.discard[3], victoryCards[vds4], sizeof(int) * discardCount);
	score1 = scoreFor(0, &G);
	score2 = scoreFor(1, &G);
	score3 = scoreFor(2, &G);
	score4 = scoreFor(3, &G);
	highScore = 0;
	if (score1 >= highScore){
		highScore = score1;
		winner = 0;
	}
	if (score2 >= highScore){
		highScore = score2;
		winner = 1;
	}
	if (score3 >= highScore){
		highScore = score3;
		winner = 2;
	}
	if (score4 >= highScore){
		highScore = score4;
		winner = 3;
	}
	getWinners(players, &G);
	for (p = 0; p < numPlayer; p++){
		if (players[p] == 1){
			testWinner = p;
		}
	}

	printf("Test #%d:\n", i);
	printf("Player 0: %d\n", score1);
	printf("Player 1: %d\n", score2);
	printf("Player 2: %d\n", score3);
	printf("Player 3: %d\n", score4);
	printf("Winner: %d, Expected: %d\n", testWinner, winner);
	if (testWinner == winner){
		printf("Success\n");
	}
	else{
		printf("Failure<==============");
	}
    }

    /*for (vh = 0; vh < 6; vh++){
        for (handCount = 1; handCount <= maxHandCount; handCount++)
        {
	    for (vd = 0; vd < 6; vd++){
            for (deckCount = 0; deckCount <= maxDeckCount; deckCount++)
            {
		for (vds = 0; vds < 6; vds++){
		for (discardCount = 0; discardCount <= maxDiscardCount; discardCount++){
		cards = handCount + deckCount + discardCount;
#if (NOISY_TEST == 1)
                printf("Test player %d with %d victory card(s).\n", p, cards);
		printf("%d of card number %d in hand\n", handCount, vh);
		printf("%d of card number %d in deck\n", deckCount, vd);
		printf("%d of card number %d in discard\n", discardCount, vds);
#endif
		cards = handCount + deckCount + discardCount;
		score = 0;				    // clear score
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
                G.handCount[p] = handCount;                 // set the number of cards on hand
		G.deckCount[p] = deckCount;		    // set the number of cards in deck
		G.discardCount[p] = discardCount;	    // set the number in discard
                memcpy(G.hand[p], victoryCards[vh], sizeof(int) * handCount);
		memcpy(G.deck[p], victoryCards[vd], sizeof(int) * deckCount);
		memcpy(G.discard[p], victoryCards[vds], sizeof(int) * discardCount);
		score = getValue(vh, handCount, cards) + getValue(vd, deckCount, cards) + getValue(vds, discardCount, cards);
		testScore = scoreFor (p, &G);
#if (NOISY_TEST == 1)
		printf("Score calculated: %d, Expected: %d\n", testScore, score);
		if (score == testScore){
			printf("SUCCESS\n");
		}
		else {
			printf("FAILURE<=============================\n");
		}
#endif
		
		}
		}
            }
	    }
	}
     }
*/
#if (NOISY_TEST == 1)
    printf("All tests ended in getWinners()\n");
#endif

    return 0;
}
