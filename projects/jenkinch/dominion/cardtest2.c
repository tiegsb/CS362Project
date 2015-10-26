/* -----------------------------------------------------------------------
 * cardtest2.c
 * Test of cardEffect(adventurer) in dominion.c
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int testCardEffect(int card) {
    int seed = 1000;
    int numPlayer = 2;
    int r;
    int k[10] = {sea_hag, council_room, feast, gardens, mine
               , remodel, smithy, village, adventurer, great_hall};
    struct gameState G;
    
    int p0Hand[MAX_HAND] = {sea_hag, copper, copper, copper, adventurer};
    int p0Discard[MAX_DECK] = {copper, council_room, feast, gardens, mine
                       , remodel, smithy, village, copper, province};
    int p0Deck[MAX_DECK] = {curse, curse
                    , remodel, smithy, village, duchy, great_hall, copper, gold};
    int p0HandCount = 5;
    int p0DiscardCount = 10;
    int p0DeckCount = 9;
    
    int p1Hand[MAX_HAND] = {sea_hag, adventurer, gold};
    int p1Discard[MAX_DECK] = {sea_hag, copper, gold};
    int p1Deck[MAX_DECK] = {sea_hag, council_room, feast, gardens, mine
                    , remodel, smithy, village, adventurer, great_hall};
    int p1HandCount = 3;
    int p1DiscardCount = 3;
    int p1DeckCount = 10;
    
    int emptyDeck[MAX_DECK] = {};

    printf ("TESTING cardEffect(adventurer):\n");
    
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
    
    G.whoseTurn = 0;
    
    //Test for successful function call
    if(cardEffect(adventurer, 0, 0, 0, &G, 4, 0) == 0)
        printf("cardEffect(adventurer): PASS player 0, function returned successfully \n");
    else
        printf("cardEffect(adventurer): FAIL player 0, function returned successfully \n");
    
    //Test for updated handCount - player 0
    if(G.handCount[0] == p0HandCount - 1 + 2)
        printf("cardEffect(adventurer): PASS player 0, handCount correct after discard/draw \n");
    else
        printf("cardEffect(adventurer): FAIL player 0, handCount correct after discard/draw \n");
    
    //Test for updated discardCount - player 0
    if(G.discardCount[0] == p0DiscardCount + 1 + 7)
        printf("cardEffect(adventurer): PASS player 0, discardCount correct after discard \n");
    else
        printf("cardEffect(adventurer): FAIL player 0, discardCount correct after discard \n");
    
    //Test for updated deckCount - player 0
    if(G.deckCount[0] == p0DeckCount - 9)
        printf("cardEffect(adventurer): PASS player 0, deckCount correct after draw \n");
    else
        printf("cardEffect(adventurer): FAIL player 0, deckCount correct after draw \n");
    
    //Test for unaffected handCount - player 1
    if(G.handCount[1] == p1HandCount)
        printf("cardEffect(adventurer): PASS player 1, handCount unaffected after p0 discard/draw \n");
    else
        printf("cardEffect(adventurer): FAIL player 1, handCount unaffected after p0 discard/draw \n");
    
    //Test for unaffected discardCount - player 1
    if(G.discardCount[1] == p1DiscardCount)
        printf("cardEffect(adventurer): PASS player 1, discardCount unaffected after p0 discard \n");
    else
        printf("cardEffect(adventurer): FAIL player 1, discardCount unaffected after p0 discard \n");
    
    //Test for unaffected deckCount - player 1
    if(G.deckCount[1] == p1DeckCount)
        printf("cardEffect(adventurer): PASS player 1, deckCount unaffected after p0 draw \n");
    else
        printf("cardEffect(adventurer): FAIL player 1, deckCount unaffected after p0 draw \n");
    
    //Reset and initialize game and set players' decks, hands, and discard piles    
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
    memcpy(G.deck[1], emptyDeck, sizeof(int)*MAX_DECK);
    G.handCount[1] = p1HandCount;
    G.discardCount[1] = p1DiscardCount;
    G.deckCount[1] = 0;
    
    G.whoseTurn = 1;
    
    //Test on empty deck
    //Test for successful function call
    if(cardEffect(adventurer, 0, 0, 0, &G, 1, 0) == 0)
        printf("cardEffect(adventurer): PASS player 1 empty deck, function returned successfully \n");
    else
        printf("cardEffect(adventurer): FAIL player 1 empty deck, function returned successfully \n");
    
    //Test for updated handCount - player 1
    if(G.handCount[1] == p0HandCount - 1 + 2)
        printf("cardEffect(adventurer): PASS player 1 empty deck, handCount correct after discard/draw \n");
    else
        printf("cardEffect(adventurer): FAIL player 1 empty deck, handCount correct after discard/draw \n");
    
    //Test for updated discardCount and deckCount - player 1
    if(G.discardCount[1] + G.deckCount[1] == 1 + 1)
        printf("cardEffect(adventurer): PASS player 1 empty deck, discardCount + deckCount = 2 \n");
    else
        printf("cardEffect(adventurer): FAIL player 1 empty deck, discardCount + deckCount = 2 \n");
    
    //Test for unaffected handCount - player 0
    if(G.handCount[0] == p0HandCount)
        printf("cardEffect(adventurer): PASS player 0, handCount unaffected after p1 discard/draw \n");
    else
        printf("cardEffect(adventurer): FAIL player 0, handCount unaffected after p1 discard/draw \n");
    
    //Test for unaffected discardCount - player 0
    if(G.discardCount[0] == p0DiscardCount)
        printf("cardEffect(adventurer): PASS player 0, discardCount unaffected after p1 discard \n");
    else
        printf("cardEffect(adventurer): FAIL player 0, discardCount unaffected after p1 discard \n");
    
    //Test for unaffected deckCount - player 0
    if(G.deckCount[0] == p0DeckCount)
        printf("cardEffect(adventurer): PASS player 0, deckCount unaffected after p1 draw \n");
    else
        printf("cardEffect(adventurer): FAIL player 0, deckCount unaffected after p1 draw \n");
    
    return 0;
}

int main(int argc, char *argv[])
{
    testCardEffect(adventurer);
    return 0;
}