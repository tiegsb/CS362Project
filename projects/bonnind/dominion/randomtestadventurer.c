/* Daniel Bonnin
 * CS362 Fall 2015
 * bonnind@oregonstate.edu
 * randomtestadventurer.c
 *
 * This file contains a random tester unit test of adventurerCard() as part of 
 * the requirements for assignment 4.
 *
 * This tester randomly generates: 
 * deckCount:   0 - MAX_DECK
 * handCount:   0 - MAX_HAND
 * cardType :   0 - treasure_map
 * numPlayers:  0 - MAX_PLAYERS
 * curPlayer:   0 - numPlayers
 *
 * The oracle then creates a comparison post-condition by adding to discard or 
 * hand cards from deck that are non-Treasure or Treasure, respectively, until 
 * 2 Treasure cards are revealed, or the deck has been cycled:
 *
 * memcmp() is used to test actual/comparison states for equality. 
 *
 * Cases with descrepancies are printed to randomtestadventurer.out.
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"

#define NUM_REPS 10000
#define MAX_ACTIONS 50

int printDetails(struct gameState *state, int curPlayer) {
    int i, j;
    printf("numPlayers: %i\n", state->numPlayers);
    printf("curPlayer: %i\n", curPlayer);
    printf("numActions: %i\n", state->numActions);

    for (i = 0; i < state->numPlayers; i++) {
        printf("Player %i:\ndeck: {", i); 
        for (j = 0; j < state->deckCount[i]; j++) {
            printf("%i, ", state->deck[i][j]);
        }
        printf("}\nhand: {");
        for (j = 0; j < state->handCount[i]; j++) {
            printf("%i, ", state->hand[i][j]);
        }
        printf("}\n");
        
    }
    return 0;
}

int oracleAdventurerCard(struct gameState *state, int player) {
    int i, treasureCount = 0, curCard;

    /* Traverse deck from right to left */
    for (i = (state->deckCount[player] - 1); i >= 0; i--) {
        curCard = state->deck[player][i];

        /* treasure card found */
        if (curCard == copper || curCard == silver || curCard == gold) {
            state->hand[player][state->handCount[player]] = curCard;
            state->handCount[player]++;
            treasureCount++;
        }
        else {
            state->discard[player][state->discardCount[player]] = curCard;
            state->discardCount[player]++;
        }
        state->deckCount[player]--;

        if (treasureCount == 2)
            break;
    }
    return 0;
}
int oracleVerified(struct gameState *state1, struct gameState *state2, int player) {
    int i, j;
    int cardtypeCounts1[treasure_map + 1];
    int cardtypeCounts2[treasure_map + 1];

    /* numActions differ */
    if (state1->numActions != state2->numActions) {
        printf("***Bug***\nnumActions not equal\n");
        return 0;
    }

    /* numPlayers differ */
    if (state1->numPlayers != state2->numPlayers) {
        printf("***Bug***\nnumPlayers not equal\n");
        return 0;
    }

    for (j = 0; j < state1->numPlayers; j++) {
        /* deckCounts differ */
        if (state1->deckCount[j] != state2->deckCount[j]) {
            printf("***Bug***\ndeckCount not equal\n");
            return 0;
        }
        /* handCounts differ */
        if (state1->handCount[j] != state2->handCount[j]){
            printf("***Bug***\nhandCount not equal\n");
            return 0;
        }
        /* discardCounts differ */
        if (state1->discardCount[j] != state2->discardCount[j]) {
            printf("***Bug***\ndiscardCount not equal\n");
            return 0;
        }

        memset(&cardtypeCounts1,0,sizeof(cardtypeCounts1));
        memset(&cardtypeCounts2,0,sizeof(cardtypeCounts2));

        /* quantities of cardtype in deck differ */
        for (i = 0; i < state1->deckCount[j]; i++) {
            cardtypeCounts1[state1->deck[j][i]]++;
            cardtypeCounts2[state2->deck[j][i]]++;
        }
        for (i = 0; i < treasure_map + 1; i++) {
            if (cardtypeCounts1[i] != cardtypeCounts2[i]) {
                printf("***Bug***\ncounts of cardTypes in deck not equal\n");
                return 0;
            }
        }

        memset(&cardtypeCounts1,0,sizeof(cardtypeCounts1));
        memset(&cardtypeCounts2,0,sizeof(cardtypeCounts2));
        
        /* quantities of cardtype in hand differ */
        for (i = 0; i < state1->handCount[j]; i++) {
            cardtypeCounts1[state1->hand[j][i]]++;
            cardtypeCounts2[state2->hand[j][i]]++;
        }
        for (i = 0; i < treasure_map + 1; i++) {
            if (cardtypeCounts1[i] != cardtypeCounts2[i]) {
                printf("***Bug***\ncounts of cardTypes in hand not equal\n");
                return 0;
            }
        }

        memset(&cardtypeCounts1,0,sizeof(cardtypeCounts1));
        memset(&cardtypeCounts2,0,sizeof(cardtypeCounts2));

        /* quantities of cardtype in discard differ */
        for (i = 0; i < state1->discardCount[j]; i++) {
            cardtypeCounts1[state1->discard[j][i]]++;
            cardtypeCounts2[state2->discard[j][i]]++;
        }
        for (i = 0; i < treasure_map + 1; i++) {
            if (cardtypeCounts1[i] != cardtypeCounts2[i]) {
                printf("counts of cardTypes in discard not equal\n");
                return 0;
            }
        }
    }
    /* passed */
    return 1;
}

int main(int argc, char *argv[]) {
    int i, j, k, seed, deckCount, handCount, cardType, numPlayers, curPlayer;
    int handPos = 0;
    struct gameState comparisonState; //control
    struct gameState testState;  // adventurerCard() test
    /* generate random values */
    seed = time(NULL);
    srand(seed);

    for (k = 0; k < NUM_REPS; k++) {
        numPlayers = (rand() % MAX_PLAYERS) + 1; //never 0 players
        curPlayer = rand() % numPlayers;
        comparisonState.playedCardCount = 0;   
        /* initialize comparison state */
        comparisonState.numPlayers = numPlayers;
        comparisonState.numActions = rand() % MAX_ACTIONS;
        
        /* initialize deck and hand for each player */
        for (i = 0; i < numPlayers; i++) {
            deckCount = (rand() % MAX_DECK) + 1;
            handCount = (rand() % deckCount) + 1;
            deckCount -= handCount;
            if (i == curPlayer)
                handPos = rand() % handCount; //index of adventurer card
            comparisonState.discardCount[i] = 0;
            comparisonState.deckCount[i] = deckCount;
            comparisonState.handCount[i] = handCount;
            
            /* set deck to random cards */
            for (j = 0; j < comparisonState.deckCount[i]; j++) {
                cardType = rand() % (treasure_map + 1);
                comparisonState.deck[i][j] = cardType;
            }
            /* set hand to random cards */
            for (j = 0; j < comparisonState.handCount[i]; j++) {
                if (i == curPlayer && j == handPos)
                    cardType = adventurer; /* Place adventurer card in hand */
                else
                    cardType = rand() % (treasure_map + 1);
                comparisonState.hand[i][j] = cardType;
            }
        }

        /* make deep copy of comparison state */
        memcpy(&testState, &comparisonState, sizeof(struct gameState));

        /* comparison and test states must be identical */
        assert(memcmp(&testState, &comparisonState, sizeof(struct gameState)) == 0);

        oracleAdventurerCard(&comparisonState, curPlayer);
        adventurerCard(&testState, curPlayer);

        if (!oracleVerified(&testState, &comparisonState, curPlayer)) {
            printf("Seed: %i, Iteration: %i, numPlayers: %i, curPlayer: %i\n", 
            seed, k + 1, numPlayers, curPlayer);
            printf("\nOracle-generated state:\n");
            printDetails(&comparisonState, curPlayer);
            printf("\nTested state:\n");
            printDetails(&testState, curPlayer);
            printf("\n");
            return 0;
        }
    }

    printf("%i Iterations passed\n", NUM_REPS);
    return 0;
}