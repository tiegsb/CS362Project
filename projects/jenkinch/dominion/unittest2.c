/* -----------------------------------------------------------------------
 * unittest2.c
 * Test of fullDeckCount() in dominion.c
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int testFullDeckCount() {
    int seed = 1000;
    int numPlayer = 2;
    int r;
    int k[10] = {sea_hag, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    
    int p0Hand[MAX_HAND] = {copper, copper, silver, estate, mine};
    int p0Discard[MAX_DECK] = {copper, council_room, feast, gardens, mine
                       , remodel, smithy, village, copper, province};
    int p0Deck[MAX_DECK] = {copper, copper, gold, curse, curse
                    , remodel, smithy, village, baron, great_hall};
    int p0HandCount = 5;
    int p0DiscardCount = 10;
    int p0DeckCount = 10;
                    
    int p0HandV2[MAX_HAND] = {estate, mine};
    int p0DiscardV2[MAX_DECK] = {copper, council_room, feast, gardens, mine
                       , remodel, smithy, village, copper, province, copper, copper, silver};
    int p0DeckV2[MAX_DECK] = {copper, copper, gold, curse, curse
                    , remodel, smithy, village, baron, great_hall};
    int p0HandCountV2 = 2;
    int p0DiscardCountV2 = 13;
    int p0DeckCountV2 = 10;
                    
    int p0HandV3[MAX_HAND] = {copper, copper, gold, curse, curse};
    int p0DiscardV3[MAX_DECK] = {copper, council_room, feast, gardens, mine
                       , remodel, smithy, village, copper, province, copper, copper, silver 
                       , estate, mine};
    int p0DeckV3[MAX_DECK] = {remodel, smithy, village, baron, great_hall};
    int p0HandCountV3 = 5;
    int p0DiscardCountV3 = 15;
    int p0DeckCountV3 = 5;
    
    int p1Hand[MAX_HAND] = {sea_hag, copper, gold};
    int p1Discard[MAX_DECK] = {};
    int p1Deck[MAX_DECK] = {sea_hag, council_room, feast, gardens, mine
                    , remodel, smithy, village, baron, great_hall};
    int p1HandCount = 3;
    int p1DiscardCount = 0;
    int p1DeckCount = 10;
    
    int emptyHand[MAX_HAND] = {};
    int emptyDiscard[MAX_DECK] = {};
    int emptyDeck[MAX_DECK] = {};
    int emptyHandCount = 0;
    int emptyDiscardCount = 0;
    int emptyDeckCount = 0;

    printf ("TESTING fullDeckCount():\n");
    
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
    memcpy(G.deck[1], p1Deck, sizeof(int)*MAX_DECK);
    G.handCount[1] = p1HandCount;
    G.discardCount[1] = p1DiscardCount;
    G.deckCount[1] = p1DeckCount;
    
    //Test that fullDeckCount of copper for player 0 returns 6
    if (fullDeckCount(0, copper, &G) == 6)
        printf("fullDeckCount(): PASS player 0, initial hand/discard/deck mix, copper \n");
    else
        printf("fullDeckCount(): FAIL player 0, initial hand/discard/deck mix, copper \n");
    
    //Test that fullDeckCount of copper for player 1 returns 1
    if (fullDeckCount(1, copper, &G) == 1)
        printf("fullDeckCount(): PASS player 1, initial hand/discard/deck mix, copper \n");
    else
        printf("fullDeckCount(): FAIL player 1, initial hand/discard/deck mix, copper \n");
    
    //Test that fullDeckCount of curse for player 0 returns 2
    //Makes sure uninitialized 0s in arrays aren't being counted
    if (fullDeckCount(0, curse, &G) == 2)
        printf("fullDeckCount(): PASS player 0, initial hand/discard/deck mix, curse \n");
    else
        printf("fullDeckCount(): FAIL player 0, initial hand/discard/deck mix, curse \n");
    
    //Test that fullDeckCount of sea_hag for player 1 returns 2
    //Makes sure sea_hag isn't an issue like it was in isGameOver tests
    if (fullDeckCount(1, sea_hag, &G) == 2)
        printf("fullDeckCount(): PASS player 1, initial hand/discard/deck mix, sea_hag \n");
    else
        printf("fullDeckCount(): FAIL player 1, initial hand/discard/deck mix, sea_hag \n");
    
    //Simulate player 0 playing coin cards from hand   
    memcpy(G.hand[0], p0HandV2, sizeof(int)*MAX_HAND);
    memcpy(G.discard[0], p0DiscardV2, sizeof(int)*MAX_DECK);
    memcpy(G.deck[0], p0DeckV2, sizeof(int)*MAX_DECK);
    G.handCount[0] = p0HandCountV2;
    G.discardCount[0] = p0DiscardCountV2;
    G.deckCount[0] = p0DeckCountV2;

    //Test that fullDeckCount of copper for player 0 remains 6
    if (fullDeckCount(0, copper, &G) == 6)
        printf("fullDeckCount(): PASS player 0, player 0 played hand mix, copper \n");
    else
        printf("fullDeckCount(): FAIL player 0, player 0 played hand mix, copper \n");
    
    //Test that fullDeckCount of copper for player 1 remains 1
    if (fullDeckCount(1, copper, &G) == 1)
        printf("fullDeckCount(): PASS player 1, player 0 played hand mix, copper \n");
    else
        printf("fullDeckCount(): FAIL player 1, player 0 played hand mix, copper \n");
    
    //Simulate player 0 drawing new hand   
    memcpy(G.hand[0], p0HandV3, sizeof(int)*MAX_HAND);
    memcpy(G.discard[0], p0DiscardV3, sizeof(int)*MAX_DECK);
    memcpy(G.deck[0], p0DeckV3, sizeof(int)*MAX_DECK);
    G.handCount[0] = p0HandCountV3;
    G.discardCount[0] = p0DiscardCountV3;
    G.deckCount[0] = p0DeckCountV3;

    //Test that fullDeckCount of copper for player 0 remains 6
    if (fullDeckCount(0, copper, &G) == 6)
        printf("fullDeckCount(): PASS player 0, player 0 draw hand mix, copper \n");
    else
        printf("fullDeckCount(): FAIL player 0, player 0 draw hand mix, copper \n");
    
    //Test that fullDeckCount of copper for player 1 remains 1
    if (fullDeckCount(1, copper, &G) == 1)
        printf("fullDeckCount(): PASS player 1, player 0 draw hand mix, copper \n");
    else
        printf("fullDeckCount(): FAIL player 1, player 0 draw hand mix, copper \n");
    
    //Test when player 0 deck, hand, and discard are empty  
    memcpy(G.hand[0], emptyHand, sizeof(int)*MAX_HAND);
    memcpy(G.discard[0], emptyDiscard, sizeof(int)*MAX_DECK);
    memcpy(G.deck[0], emptyDeck, sizeof(int)*MAX_DECK);
    G.handCount[0] = emptyHandCount;
    G.discardCount[0] = emptyDiscardCount;
    G.deckCount[0] = emptyDeckCount;

    //Test that fullDeckCount of copper for player 0 is 0
    if (fullDeckCount(0, copper, &G) == 0)
        printf("fullDeckCount(): PASS player 0, player 0 everything empty, copper \n");
    else
        printf("fullDeckCount(): FAIL player 0, player 0 everything empty, copper \n");
    
    return 0;
}

int main(int argc, char *argv[])
{
    testFullDeckCount();
    return 0;
}