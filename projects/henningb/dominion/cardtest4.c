/*
 * Tests village card.
 *
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
    int index;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};


    /*
        Things to test:
        player's hand count unchanged (draw a card, discard village)
        player's deck decreased by 1
        player's hand contains 1 card from deck (copper)
        actions increased by 2
        playedCardCount increased by 1
        top of playedCards is now village
        player's hand no longer contains village
        nothing else in state is changed
    */

    struct gameState post;

    player = 1;

    printf("Testing village card\n\n");
    printf("Test case:Player 1 has village in pos 4.\n");
    printf("No other village cards in game.\n");

    //Initialize game
    r = initializeGame(2, k, 1, &post);

    //Fill player's hand with 5 barons
    post.handCount[player] = 5;
    for(i = 0; i < 5; i++){
        post.hand[player][i] = baron;
    }

    //Give player 1 village at pos 4
    post.hand[player][4] = village;

    //Fill player's deck with 5 copper cards
    post.deckCount[player] = 5;
    for(i = 0; i < 5; i++){
        post.deck[player][i] = copper;
    }

    //Make a copy of game state
    struct gameState pre;
    memcpy(&pre, &post, sizeof(struct gameState));

    //play village card
    //Since we are not testing playCard or cardEffect, just call village card function
    villageCardEffect(4, player, &post);

    //Test player's hand count unchanged (gained a card, discarded village)
    printf("Testing that P%d's hand count is unchanged ... ", player);
    comparison = post.handCount[player] - pre.handCount[player];
    if(comparison == 0){
        printf("PASS\n");
    }
    else{
        printf("Increased by %d. FAIL\n", comparison);
        failures++;
    }

    //Test that player's deck decreased by 1
    printf("Testing that P%d's deck decreased by 1 ... ", player);
    comparison = post.deckCount[player] - pre.deckCount[player];
    if(comparison == 1){
        printf("PASS\n");
    }
    else{
        printf("Decreased by %d, FAIL\n", comparison);
        failures++;
    }

    //player's hand contains 1 cards from deck (copper)
    printf("Testing that top position in P%d's hand contains card from deck ... ", player);
    if(post.deck[player][post.deckCount[player] - 1] == copper){
        printf("PASS\n");
    }
    else{
        printf("FAIL\n");
        failures++;
    }

    //actions increased by 2
    printf("Testing that numActions has increased by 2 ... ");
    comparison = post.numActions - pre.numActions;
    if(comparison == 2){
        printf("PASS\n");
    }
    else{
        printf("Increased by %d. FAIL\n", comparison);
        failures++;
    }

    //TEST THAT VILLAGE WAS DISCARDED
    //Current player's hand no longer contains village
    int villageFound = 0;
    printf("Testing that P%d's hand no longer contains village ... ", player);
    for(i = 0; i < post.handCount[player]; i++){
        if(post.hand[player][i] == village){
            villageFound++;
            index = i;
        }
    }
    if(villageFound == 0){
        printf("PASS\n");
    }
    else{
        printf("Village found at hand pos %d. FAIL\n", index);
        failures++;
    }

    //playedCount increased by 1
    printf("Testing that playedCardCount is increased by 1 ... ");
    comparison = post.playedCardCount - pre.playedCardCount;
    if(comparison == 1){
        printf("PASS\n");
    }
    else{
        printf("PlayedCount increased by %d. FAIL\n", comparison);
        failures++;
    }

    //playedCards has village at top
    printf("Testing that playedCards has village at the top ... ");
    if(post.playedCards[post.playedCardCount - 1] == village){
        printf("PASS\n");
    }
    else{
        printf("FAIL\n");
        failures++;
    }

    //Test that nothing else in state has changed
    pre.handCount[player] = post.handCount[player];
    memcpy(&pre.hand[player], &post.hand[player], sizeof(int) * MAX_HAND);
    pre.deckCount[player] = post.deckCount[player];
    memcpy(&pre.deck[player], &post.deck[player], sizeof(int) * MAX_DECK);
    memcpy(&pre.playedCards, &post.playedCards, sizeof(int) * MAX_DECK);
    pre.playedCardCount = post.playedCardCount;
    pre.numActions = post.numActions;

    comparison = memcmp(&pre, &post, sizeof(struct gameState));
    printf("Testing that nothing else in game state has changed ... ");
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
