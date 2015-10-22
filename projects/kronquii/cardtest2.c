#include <assert.h>

#include "dominion.h"
int adventurerEffect(int currentPlayer, int handPos, struct gameState *state) {
    int temphand[MAX_HAND];// moved above the if statement
    int z;
    int drawntreasure = 0;
    int cardDrawn;
    while(drawntreasure<2){
        if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
            shuffle(currentPlayer, state);
        }
        drawCard(currentPlayer, state);
        cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
        if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
            drawntreasure++;
        else{
            temphand[z]=cardDrawn;
            state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
            z++;
        }
    }
    while(z-1>=0){
        state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
        z=z-1;
    }
    return 0;
}


void testAdventurerEffect() {
    struct gameState gs = {
        .numPlayers = 3,
        .supplyCount = {0},
        .embargoTokens = {0},
        .outpostPlayed = 0,
        .outpostTurn = 0,
        .whoseTurn = 0,
        .phase = 0,
        .numActions = 0,
        .coins = 0,
        .numBuys = 0,
        .hand = {{0}},
        .handCount = {0},
        .deckCount = {4, 4, 4},
        .deck = {{silver, silver, curse, curse},
                 {curse, curse, curse, curse},
                 {curse, silver, curse, silver},},
        .discard = {{0}},
        .discardCount = {0},
        .playedCards = {0},
        .playedCardCount = 0,
    };


}
