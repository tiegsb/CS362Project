/* -----------------------------------------------------------------------
 * unittest4.c
 * Test of shuffle() in dominion.c
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int testShuffle() {
    int seed = 1000;
    int numPlayer = 2;
    int r, i;
    int posChangeCount = 0;
    int cardIsDifferent = 0;
    int k[10] = {sea_hag, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    
    int p0Hand[MAX_HAND] = {copper, copper, silver, estate, mine};
    int p0Discard[MAX_DECK] = {copper, council_room, feast, gardens, mine
                       , remodel, smithy, village, copper, province};
    int p0Deck[MAX_DECK] = {copper, copper, gold, curse, curse
                    , remodel, smithy, village, duchy, great_hall};
    int p0HandCount = 5;
    int p0DiscardCount = 10;
    int p0DeckCount = 10;
    
    int p1Hand[MAX_HAND] = {sea_hag, copper, gold};
    int p1Discard[MAX_DECK] = {sea_hag, copper, gold};
    int p1Deck[MAX_DECK] = {sea_hag, council_room, feast, gardens, mine
                    , remodel, smithy, village, baron, great_hall};
    int p1HandCount = 3;
    int p1DiscardCount = 3;
    int p1DeckCount = 10;
    
    int emptyDeck[MAX_DECK] = {};

    printf ("TESTING shuffle():\n");
    
    //Initialize game and set players' decks, hands, and discard piles    
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
    memcpy(G.hand[0], p0Hand, sizeof(int)*MAX_HAND);
    memcpy(G.discard[0], p0Discard, sizeof(int)*MAX_DECK);
    memcpy(G.deck[0], p0Deck, sizeof(int)*MAX_DECK);
    G.handCount[0] = p0HandCount;
    G.discardCount[0] = p0DiscardCount;
    G.deckCount[0] = p0DeckCount;
    
    memcpy(G.hand[1], p1Hand, sizeof(int)*MAX_HAND);
    memcpy(G.discard[1], p1Discard, sizeof(int)*MAX_DECK);
    memcpy(G.deck[1], emptyDeck, sizeof(int)*MAX_DECK);
    G.handCount[1] = p1HandCount;
    G.discardCount[1] = p1DiscardCount;
    G.deckCount[1] = 0;
    
    //Test for unsuccessful function call
    if(shuffle(1, &G) == -1)
        printf("shuffle(): PASS player 1, function returned unsuccessfully on empty deck \n");
    else
        printf("shuffle(): FAIL player 1, function returned unsuccessfully on empty deck \n");
    
    //Reset game and set players' decks, hands, and discard piles    
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
    memcpy(G.hand[0], p0Hand, sizeof(int)*MAX_HAND);
    memcpy(G.discard[0], p0Discard, sizeof(int)*MAX_DECK);
    memcpy(G.deck[0], p0Deck, sizeof(int)*MAX_DECK);
    G.handCount[0] = p0HandCount;
    G.discardCount[0] = p0DiscardCount;
    G.deckCount[0] = p0DeckCount;
    
    memcpy(G.hand[1], p1Hand, sizeof(int)*MAX_HAND);
    memcpy(G.discard[1], p1Discard, sizeof(int)*MAX_DECK);
    memcpy(G.deck[1], p1Deck, sizeof(int)*MAX_DECK);
    G.handCount[1] = p1HandCount;
    G.discardCount[1] = p1DiscardCount;
    G.deckCount[1] = p1DeckCount;
    
    //Test for successful function call
    if(!shuffle(0, &G))
        printf("shuffle(): PASS player 0, function returned successfully on initial hand/discard/deck mix \n");
    else
        printf("shuffle(): FAIL player 0, function returned successfully on initial hand/discard/deck mix \n");
    
    //Test that player 0 deck count is unaffected
    if(G.deckCount[0] == p0DeckCount)
        printf("shuffle(): PASS player 0, deck count stayed the same \n");
    else
        printf("shuffle(): FAIL player 0, deck count stayed the same \n");
    
    //Test that player 0 deck is in different order then before
    for(i = 0; i < p0DeckCount; i++){
        if(G.deck[0][i] != p0Deck[i])
            posChangeCount++;
    }
    if(posChangeCount > 0)
        printf("shuffle(): PASS player 0, %d cards changed position in deck \n", posChangeCount);
    else
        printf("shuffle(): FAIL player 0, %d cards changed position in deck \n", posChangeCount);
    
    //Test for any other unexpected game state changes
    if(G.handCount[0] == p0HandCount)
        printf("shuffle(): PASS player 0, hand count stayed the same \n");
    else
        printf("shuffle(): FAIL player 0, hand count stayed the same \n");
    
    if(G.discardCount[0] == p0DiscardCount)
        printf("shuffle(): PASS player 0, discard count stayed the same \n");
    else
        printf("shuffle(): FAIL player 0, discard count stayed the same \n");
    
    if(G.deckCount[1] == p1DeckCount)
        printf("shuffle(): PASS player 1, deck count stayed the same \n");
    else
        printf("shuffle(): FAIL player 1, deck count stayed the same \n");
    
    if(G.handCount[1] == p1HandCount)
        printf("shuffle(): PASS player 1, hand count stayed the same \n");
    else
        printf("shuffle(): FAIL player 1, hand count stayed the same \n");
    
    if(G.discardCount[1] == p1DiscardCount)
        printf("shuffle(): PASS player 1, discard count stayed the same \n");
    else
        printf("shuffle(): FAIL player 1, discard count stayed the same \n");
    
    for(i = 0; i < p0HandCount; i++){
        if(G.hand[0][i] != p0Hand[i])
            cardIsDifferent = 1;
            break;
    }
    if(cardIsDifferent)
        printf("shuffle(): FAIL player 0, cards in hand remained same after shuffle \n");
    else
        printf("shuffle(): PASS player 0, cards in hand remained same after shuffle \n");
    
    cardIsDifferent = 0;
    
    for(i = 0; i < p0DiscardCount; i++){
        if(G.discard[0][i] != p0Discard[i])
            cardIsDifferent = 1;
            break;
    }
    if(cardIsDifferent)
        printf("shuffle(): FAIL player 0, cards in discard remained same after shuffle \n");
    else
        printf("shuffle(): PASS player 0, cards in discard remained same after shuffle \n");
    
    cardIsDifferent = 0;
    
    for(i = 0; i < p1DeckCount; i++){
        if(G.deck[1][i] != p1Deck[i])
            cardIsDifferent = 1;
            break;
    }
    if(cardIsDifferent)
        printf("shuffle(): FAIL player 1, cards in deck remained same after shuffle \n");
    else
        printf("shuffle(): PASS player 1, cards in deck remained same after shuffle \n");
    
    cardIsDifferent = 0;
    
    for(i = 0; i < p1HandCount; i++){
        if(G.hand[1][i] != p1Hand[i])
            cardIsDifferent = 1;
            break;
    }
    if(cardIsDifferent)
        printf("shuffle(): FAIL player 1, cards in hand remained same after shuffle \n");
    else
        printf("shuffle(): PASS player 1, cards in hand remained same after shuffle \n");
    
    cardIsDifferent = 0;
    
    for(i = 0; i < p1DiscardCount; i++){
        if(G.discard[1][i] != p1Discard[i])
            cardIsDifferent = 1;
            break;
    }
    if(cardIsDifferent)
        printf("shuffle(): FAIL player 1, cards in discard remained same after shuffle \n");
    else
        printf("shuffle(): PASS player 1, cards in discard remained same after shuffle \n");
    
    return 0;
}

int main(int argc, char *argv[])
{
    testShuffle();
    return 0;
}