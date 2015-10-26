/*
 * Tests smithy card.
 * Smithy should draw 3 cards from player's deck
 * into player's hand, then discard itself.
 * For testing purposes, player's hand is all copper with 1 smithy.
 * Deck is all silver. Played cards are all gold.
 */
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main (){

    int i, r, player;
    int failures = 0;   //Number of checks failed
    int comparison;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};


    struct gameState post;

    player = 1;

    printf("Testing smithy card\n Hand is all copper with one smithy at pos 4\n");
    printf("Deck initialized to all silver. Played cards initialized to all gold.\n\n");

    //Initialize game
    r = initializeGame(2, k, 1, &post);

    //Set player 1's hand to one smithy and 4 copper, to make testing easier
    post.handCount[player] = 5;
    post.hand[player][0] = copper;
    post.hand[player][1] = copper;
    post.hand[player][2] = copper;
    post.hand[player][3] = copper;
    post.hand[player][4] = smithy;

    //Fill player's deck with silver cards to make it easy to keep track of
    for(i = 0; i < post.deckCount[player]; i++){
        post.deck[player][i] = silver;
    }

    //Set played card pile to all gold cards
    for(i = 0; i < post.playedCardCount; i++){
        post.playedCards[i] = gold;
    }

    //Make a copy of game state
    struct gameState pre;
    memcpy(&pre, &post, sizeof(struct gameState));

    //play smithy card
    //Since we are not testing playCard or cardEffect, just call smithy card function
    smithyCardEffect(4, player, &post);

    //Played card pile should be incremented
    printf("Testing that played card pile was increased by 1. ");
    comparison = post.playedCardCount - pre.playedCardCount;
    if(comparison == 1){
        printf("Increased by 1. PASS\n");
    }
    else{
        printf("Increased by %d. FAIL\n", comparison);
        failures++;
    }

    //Test that top of played cards is smithy
    printf("Testing that top of played card pile is smithy. ");
    if(post.playedCards[post.playedCardCount - 1] == smithy){
        printf("PASS\n");
    }
    else{
        printf("FAIL\n");
        failures++;
    }

    //Test that player's hand received 3 cards (net gain of 2 with discarded smithy)
    printf("Testing that player hand has net gain of 2 cards ... ");
    comparison = post.handCount[player] - pre.handCount[player];
    if(comparison == 2){
        printf("PASS\n");
    }
    else{
        printf("Net gain of %d. FAIL\n", comparison);
        failures++;
    }

    //Test that any new cards in player's hand came from deck (silver)
    printf("Testing that all new cards came from deck (should all be silver) ... ");
    r = 0;
    for(i = 0; i < comparison; i++){
        int index = post.handCount[player] - (i+1);
        if(post.hand[player][index] != silver){
            r = -1;
        }
    }
    if(r == 0){
        printf("PASS\n");
    }
    else{
        printf("FAIL\n");
        failures++;
    }

    //Test that deck count properly decremented
    printf("Testing that players deck count was decreased by 3 ... ");
    comparison = pre.deckCount[player] - post.deckCount[player];
    if(comparison == 3){
        printf("PASS\n");
    }
    else{
        printf("decreased by %d. FAIL\n", comparison);
        failures++;
    }

    //Test that smithy not present in hand (verify that it discarded properly)
    printf("Verifying smithy no longer in player hand ... ");
    r = 0;
    int index;
    for(i = 0; i < post.handCount[player]; i++){
        if(post.hand[player][i] == smithy){
            r = -1;
            index = i;
        }
    }
    if(r == 0){
        printf("PASS\n");
    }
    else{
        printf("Smithy at pos %d. FAIL\n", index);
        failures++;
    }


    //Nothing else in game state should be unchanged
    printf("Testing that rest of game state is unchanged ... ");
    //Update game state pre to match the tested parts above
    pre.playedCardCount = post.playedCardCount;
    memcpy(&pre.playedCards, &post.playedCards, sizeof(int) * MAX_DECK);
    pre.handCount[player] = post.handCount[player];
    memcpy(&pre.hand[player], &post.hand[player], sizeof(int) * MAX_HAND);
    post.deckCount[player] = pre.deckCount[player];
    memcpy(&post.deck[player], &pre.deck[player], sizeof(int) * MAX_DECK);

    comparison = memcmp(&pre, &post, sizeof(struct gameState));
    if(comparison == 0){
        printf("PASS\n");
    }
    else{
        printf("FAIL\n");
        failures++;
    }


   if(failures == 0){
        printf("\nAll tests passed\n");
   }
   else{
        printf("\n%d failures occurred\n", failures);
   }

    return 0;
}
