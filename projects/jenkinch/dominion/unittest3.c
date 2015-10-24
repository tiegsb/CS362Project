/* -----------------------------------------------------------------------
 * unittest3.c
 * Test of scoreFor() in dominion.c
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int testScoreFor() {
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
                    , remodel, smithy, village, duchy, great_hall};
    int p0HandCount = 5;
    int p0DiscardCount = 10;
    int p0DeckCount = 10;
                    
    int p0HandV2[MAX_HAND] = {estate, mine};
    int p0DiscardV2[MAX_DECK] = {copper, council_room, feast, gardens, mine
                       , remodel, smithy, village, copper, province, copper, copper, silver};
    int p0DeckV2[MAX_DECK] = {copper, copper, gold, curse, curse
                    , remodel, smithy, village, duchy, great_hall};
    int p0HandCountV2 = 2;
    int p0DiscardCountV2 = 13;
    int p0DeckCountV2 = 10;
                    
    int p0HandV3[MAX_HAND] = {copper, copper, gold, curse, curse};
    int p0DiscardV3[MAX_DECK] = {copper, council_room, feast, gardens, mine
                       , remodel, smithy, village, copper, province, copper, copper, silver 
                       , estate, mine};
    int p0DeckV3[MAX_DECK] = {remodel, smithy, village, duchy, great_hall};
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
    
    int justCurse[MAX_HAND] = {curse};
    int justEstate[MAX_HAND] = {estate};
    int justDuchy[MAX_HAND] = {duchy};
    int justProvince[MAX_HAND] = {province};
    int justGreatHall[MAX_HAND] = {great_hall};
    int justGarden[MAX_HAND] = {gardens};
    int singleCardCount = 1;

    printf ("TESTING scoreFor():\n");
    
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
    
    //Test that scoreFor player 0 returns 11
    if (scoreFor(0, &G) == 11)
        printf("scoreFor(): PASS player 0, initial hand/discard/deck mix, expected 11, got %d \n", scoreFor(0, &G));
    else
        printf("scoreFor(): FAIL player 0, initial hand/discard/deck mix, expected 11, got %d \n", scoreFor(0, &G));
    
    //Test that scoreFor player 1 returns 2
    if (scoreFor(1, &G) == 2)
        printf("scoreFor(): PASS player 1, initial hand/discard/deck mix, expected 2, got %d \n", scoreFor(1, &G));
    else
        printf("scoreFor(): FAIL player 1, initial hand/discard/deck mix, expected 2, got %d \n", scoreFor(1, &G));
    
    //Simulate player 0 playing coin cards from hand   
    memcpy(G.hand[0], p0HandV2, sizeof(int)*MAX_HAND);
    memcpy(G.discard[0], p0DiscardV2, sizeof(int)*MAX_DECK);
    memcpy(G.deck[0], p0DeckV2, sizeof(int)*MAX_DECK);
    G.handCount[0] = p0HandCountV2;
    G.discardCount[0] = p0DiscardCountV2;
    G.deckCount[0] = p0DeckCountV2;

    //Test that scoreFor player 0 remains 11
    if (scoreFor(0, &G) == 11)
        printf("scoreFor(): PASS player 0, player 0 played hand mix, expected 11, got %d \n", scoreFor(0, &G));
    else
        printf("scoreFor(): FAIL player 0, player 0 played hand mix, expected 11, got %d \n", scoreFor(0, &G));
    
    //Test that scoreFor player 1 remains 2
    if (scoreFor(1, &G) == 2)
        printf("scoreFor(): PASS player 1, player 0 played hand mix, expected 2, got %d \n", scoreFor(1, &G));
    else
        printf("scoreFor(): FAIL player 1, player 0 played hand mix, expected 2, got %d \n", scoreFor(1, &G));
    
    //Simulate player 0 drawing new hand   
    memcpy(G.hand[0], p0HandV3, sizeof(int)*MAX_HAND);
    memcpy(G.discard[0], p0DiscardV3, sizeof(int)*MAX_DECK);
    memcpy(G.deck[0], p0DeckV3, sizeof(int)*MAX_DECK);
    G.handCount[0] = p0HandCountV3;
    G.discardCount[0] = p0DiscardCountV3;
    G.deckCount[0] = p0DeckCountV3;

    //Test that scoreFor player 0 remains 11
    if (scoreFor(0, &G) == 11)
        printf("scoreFor(): PASS player 0, player 0 draw hand mix, expected 11, got %d \n", scoreFor(0, &G));
    else
        printf("scoreFor(): FAIL player 0, player 0 draw hand mix, expected 11, got %d \n", scoreFor(0, &G));
    
    //Test when player 0 deck, hand, and discard are empty  
    memcpy(G.hand[0], emptyHand, sizeof(int)*MAX_HAND);
    memcpy(G.discard[0], emptyDiscard, sizeof(int)*MAX_DECK);
    memcpy(G.deck[0], emptyDeck, sizeof(int)*MAX_DECK);
    G.handCount[0] = emptyHandCount;
    G.discardCount[0] = emptyDiscardCount;
    G.deckCount[0] = emptyDeckCount;

    //Test that scoreFor player 0 is 0
    if (scoreFor(0, &G) == 0)
        printf("scoreFor(): PASS player 0, player 0 everything empty, expected 0, got %d \n", scoreFor(0, &G));
    else
        printf("scoreFor(): FAIL player 0, player 0 everything empty, expected 0, got %d \n", scoreFor(0, &G));
    
    //Test when player 0 has a single curse in hand  
    memcpy(G.hand[0], justCurse, sizeof(int)*MAX_HAND);
    G.handCount[0] = singleCardCount;

    //Test that scoreFor player 0 is -1
    if (scoreFor(0, &G) == -1)
        printf("scoreFor(): PASS player 0, player 0 just curse in hand, expected -1, got %d \n", scoreFor(0, &G));
    else
        printf("scoreFor(): FAIL player 0, player 0 just curse in hand, expected -1, got %d \n", scoreFor(0, &G));
    
    //Test when player 0 has a single estate in hand  
    memcpy(G.hand[0], justEstate, sizeof(int)*MAX_HAND);

    //Test that scoreFor player 0 is 1
    if (scoreFor(0, &G) == 1)
        printf("scoreFor(): PASS player 0, player 0 just estate in hand, expected 1, got %d \n", scoreFor(0, &G));
    else
        printf("scoreFor(): FAIL player 0, player 0 just estate in hand, expected 1, got %d \n", scoreFor(0, &G));
    
    //Test when player 0 has a single duchy in hand  
    memcpy(G.hand[0], justDuchy, sizeof(int)*MAX_HAND);

    //Test that scoreFor player 0 is 3
    if (scoreFor(0, &G) == 3)
        printf("scoreFor(): PASS player 0, player 0 just duchy in hand, expected 3, got %d \n", scoreFor(0, &G));
    else
        printf("scoreFor(): FAIL player 0, player 0 just duchy in hand, expected 3, got %d \n", scoreFor(0, &G));
    
    //Test when player 0 has a single province in hand  
    memcpy(G.hand[0], justProvince, sizeof(int)*MAX_HAND);

    //Test that scoreFor player 0 is 6
    if (scoreFor(0, &G) == 6)
        printf("scoreFor(): PASS player 0, player 0 just province in hand, expected 6, got %d \n", scoreFor(0, &G));
    else
        printf("scoreFor(): FAIL player 0, player 0 just province in hand, expected 6, got %d \n", scoreFor(0, &G));
    
    //Test when player 0 has a single great_hall in hand  
    memcpy(G.hand[0], justGreatHall, sizeof(int)*MAX_HAND);

    //Test that scoreFor player 0 is 1
    if (scoreFor(0, &G) == 1)
        printf("scoreFor(): PASS player 0, player 0 just great_hall in hand, expected 1, got %d \n", scoreFor(0, &G));
    else
        printf("scoreFor(): FAIL player 0, player 0 just great_hall in hand, expected 1, got %d \n", scoreFor(0, &G));
    
    //Test when player 0 has a single garden in hand  
    memcpy(G.hand[0], justGarden, sizeof(int)*MAX_HAND);

    //Test that scoreFor player 0 is 0
    if (scoreFor(0, &G) == 0)
        printf("scoreFor(): PASS player 0, player 0 just garden in hand, expected 0, got %d \n", scoreFor(0, &G));
    else
        printf("scoreFor(): FAIL player 0, player 0 just garden in hand, expected 0, got %d \n", scoreFor(0, &G));
    
    //Reset player 0 cards and test when player 0 has a single curse in discard
    memcpy(G.hand[0], emptyHand, sizeof(int)*MAX_HAND);
    memcpy(G.discard[0], emptyDiscard, sizeof(int)*MAX_DECK);
    memcpy(G.deck[0], emptyDeck, sizeof(int)*MAX_DECK);
    G.handCount[0] = emptyHandCount;
    G.discardCount[0] = emptyDiscardCount;
    G.deckCount[0] = emptyDeckCount;
    
    memcpy(G.discard[0], justCurse, sizeof(int)*MAX_DECK);
    G.discardCount[0] = singleCardCount;

    //Test that scoreFor player 0 is -1
    if (scoreFor(0, &G) == -1)
        printf("scoreFor(): PASS player 0, player 0 just curse in discard, expected -1, got %d \n", scoreFor(0, &G));
    else
        printf("scoreFor(): FAIL player 0, player 0 just curse in discard, expected -1, got %d \n", scoreFor(0, &G));
    
    //Test when player 0 has a single estate in discard  
    memcpy(G.discard[0], justEstate, sizeof(int)*MAX_DECK);

    //Test that scoreFor player 0 is 1
    if (scoreFor(0, &G) == 1)
        printf("scoreFor(): PASS player 0, player 0 just estate in discard, expected 1, got %d \n", scoreFor(0, &G));
    else
        printf("scoreFor(): FAIL player 0, player 0 just estate in discard, expected 1, got %d \n", scoreFor(0, &G));
    
    //Test when player 0 has a single duchy in discard  
    memcpy(G.discard[0], justDuchy, sizeof(int)*MAX_DECK);

    //Test that scoreFor player 0 is 3
    if (scoreFor(0, &G) == 3)
        printf("scoreFor(): PASS player 0, player 0 just duchy in discard, expected 3, got %d \n", scoreFor(0, &G));
    else
        printf("scoreFor(): FAIL player 0, player 0 just duchy in discard, expected 3, got %d \n", scoreFor(0, &G));
    
    //Test when player 0 has a single province in discard  
    memcpy(G.discard[0], justProvince, sizeof(int)*MAX_DECK);

    //Test that scoreFor player 0 is 6
    if (scoreFor(0, &G) == 6)
        printf("scoreFor(): PASS player 0, player 0 just province in discard, expected 6, got %d \n", scoreFor(0, &G));
    else
        printf("scoreFor(): FAIL player 0, player 0 just province in discard, expected 6, got %d \n", scoreFor(0, &G));
    
    //Test when player 0 has a single great_hall in discard  
    memcpy(G.discard[0], justGreatHall, sizeof(int)*MAX_DECK);

    //Test that scoreFor player 0 is 1
    if (scoreFor(0, &G) == 1)
        printf("scoreFor(): PASS player 0, player 0 just great_hall in discard, expected 1, got %d \n", scoreFor(0, &G));
    else
        printf("scoreFor(): FAIL player 0, player 0 just great_hall in discard, expected 1, got %d \n", scoreFor(0, &G));
    
    //Test when player 0 has a single garden in discard  
    memcpy(G.discard[0], justGarden, sizeof(int)*MAX_DECK);

    //Test that scoreFor player 0 is 0
    if (scoreFor(0, &G) == 0)
        printf("scoreFor(): PASS player 0, player 0 just garden in discard, expected 0, got %d \n", scoreFor(0, &G));
    else
        printf("scoreFor(): FAIL player 0, player 0 just garden in discard, expected 0, got %d \n", scoreFor(0, &G));
    
    //Reset player 0 cards and test when player 0 has a single curse in deck
    memcpy(G.hand[0], emptyHand, sizeof(int)*MAX_HAND);
    memcpy(G.discard[0], emptyDiscard, sizeof(int)*MAX_DECK);
    memcpy(G.deck[0], emptyDeck, sizeof(int)*MAX_DECK);
    G.handCount[0] = emptyHandCount;
    G.discardCount[0] = emptyDiscardCount;
    G.deckCount[0] = emptyDeckCount;
    
    memcpy(G.deck[0], justCurse, sizeof(int)*MAX_DECK);
    G.deckCount[0] = singleCardCount;

    //Test that scoreFor player 0 is -1
    if (scoreFor(0, &G) == -1)
        printf("scoreFor(): PASS player 0, player 0 just curse in deck, expected -1, got %d \n", scoreFor(0, &G));
    else
        printf("scoreFor(): FAIL player 0, player 0 just curse in deck, expected -1, got %d \n", scoreFor(0, &G));
    
    //Test when player 0 has a single estate in deck  
    memcpy(G.deck[0], justEstate, sizeof(int)*MAX_DECK);

    //Test that scoreFor player 0 is 1
    if (scoreFor(0, &G) == 1)
        printf("scoreFor(): PASS player 0, player 0 just estate in deck, expected 1, got %d \n", scoreFor(0, &G));
    else
        printf("scoreFor(): FAIL player 0, player 0 just estate in deck, expected 1, got %d \n", scoreFor(0, &G));
    
    //Test when player 0 has a single duchy in deck  
    memcpy(G.deck[0], justDuchy, sizeof(int)*MAX_DECK);

    //Test that scoreFor player 0 is 3
    if (scoreFor(0, &G) == 3)
        printf("scoreFor(): PASS player 0, player 0 just duchy in deck, expected 3, got %d \n", scoreFor(0, &G));
    else
        printf("scoreFor(): FAIL player 0, player 0 just duchy in deck, expected 3, got %d \n", scoreFor(0, &G));
    
    //Test when player 0 has a single province in deck  
    memcpy(G.deck[0], justProvince, sizeof(int)*MAX_DECK);

    //Test that scoreFor player 0 is 6
    if (scoreFor(0, &G) == 6)
        printf("scoreFor(): PASS player 0, player 0 just province in deck, expected 6, got %d \n", scoreFor(0, &G));
    else
        printf("scoreFor(): FAIL player 0, player 0 just province in deck, expected 6, got %d \n", scoreFor(0, &G));
    
    //Test when player 0 has a single great_hall in deck  
    memcpy(G.deck[0], justGreatHall, sizeof(int)*MAX_DECK);

    //Test that scoreFor player 0 is 1
    if (scoreFor(0, &G) == 1)
        printf("scoreFor(): PASS player 0, player 0 just great_hall in deck, expected 1, got %d \n", scoreFor(0, &G));
    else
        printf("scoreFor(): FAIL player 0, player 0 just great_hall in deck, expected 1, got %d \n", scoreFor(0, &G));
    
    //Test when player 0 has a single garden in deck  
    memcpy(G.deck[0], justGarden, sizeof(int)*MAX_DECK);

    //Test that scoreFor player 0 is 0
    if (scoreFor(0, &G) == 0)
        printf("scoreFor(): PASS player 0, player 0 just garden in deck, expected 0, got %d \n", scoreFor(0, &G));
    else
        printf("scoreFor(): FAIL player 0, player 0 just garden in deck, expected 0, got %d \n", scoreFor(0, &G));
    
    return 0;
}

int main(int argc, char *argv[])
{
    testScoreFor();
    return 0;
}