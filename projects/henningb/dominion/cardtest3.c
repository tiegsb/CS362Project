/*
 * Tests sea hag card.
 *
 */
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int main (){

    int i, r, j, player;
    int failures = 0;   //Number of checks failed
    int comparison;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};


    /*

    Things to test:
    Other players' top card of deck (a copper) is now top card of discard deck
    Other players' discard deck count incremented
    Other players' decks' top card is curse card
    Other players' deck count is same size (1 discarded, curse gained)
    Current player's top card of deck not moved to discard deck (i.e. not == copper)
    Current player's discard count not incremented
    Current player's deck top card is not curse

    Current player's hand count decreased by 1
    Current player's hand no longer contains sea hag
    Current player's playedCount increased by 1
    Current player's playedCards has sea hag at top

    */



    struct gameState post;

    player = 1;

    printf("Testing sea hag card\n");
    printf("Test case: 4 Players. Player 1 has sea hag in pos 4.\n");
    printf("No other sea hag cards in game.\n");

    //Initialize 4 player game
    r = initializeGame(4, k, 1, &post);

    //Fill all 4 players' hands with 5 barons
    for(i = 0; i < 5; i++){
        post.handCount[i] = 5;
        for(j = 0; j < 5; j++){
            post.hand[i][j] = baron;
        }
    }

    //Give player 1 a sea hag at pos 4
    post.hand[player][4] = sea_hag;


    //Fill all decks with 5 copper cards
    for(i = 0; i < 5; i++){
        post.deckCount[i] = 5;
        for(j = 0; j < 5; j++){
            post.deck[i][j] = copper;
        }
    }

    //Set all discard piles to 5 silver cards
    for(i = 0; i < 5; i++){
        post.discardCount[i] = 5;
        for(j = 0; j < 5; j++){
            post.discard[i][j] = silver;
        }
    }

    //Make a copy of game state
    struct gameState pre;
    memcpy(&pre, &post, sizeof(struct gameState));

    //play sea_hag card
    //Since we are not testing playCard or cardEffect, just call sea_hag card function
    printf("P%d played sea_hag\n", player);
    seaHagCardEffect(player, &post);

    //Test other players' top card of deck (a copper) is now top card of discard deck
    for(i = 0; i < 4; i++){
        if(i != player){    //Skip player that played sea_hag
            printf("Testing top of P%d's discard pile. Expecting copper ... ", i);
            if(post.discard[i][post.discardCount[i] - 1] == copper){
                printf("PASS\n");
            }
            else{
                printf("FAIL\n");
                failures++;
            }
        }
    }

    //Other players' discard deck count incremented
    for(i = 0; i < 4; i++){
        if(i != player){    //Skip player that played sea_hag
            printf("Testing that P%d's discard count was incremented by 1 ... ", i);
            comparison = post.discardCount[i] - pre.discardCount[i];
            if(comparison == 1){
                printf("PASS\n");
            }
            else{
                printf("Increased by %d. FAIL\n", comparison);
                failures++;
            }
        }
    }

    //Other players' decks' top card is curse card
    for(i = 0; i < 4; i++){
        if(i != player){    //Skip player that played sea_hag
            printf("Testing that top of P%d's deck is curse card ... ", i);
            if(post.deck[i][post.deckCount[i] - 1] == curse){
                printf("PASS\n");
            }
            else{
                printf("FAIL\n");
                failures++;
            }
        }
    }

    //All players' deck count should be unchanged
    for(i = 0; i < 4; i++){
        printf("Testing that P%d's deck count is unchanged ... ", i);
        comparison = post.deckCount[i] - pre.deckCount[i];
        if(comparison == 0){
            printf("PASS\n");
        }
        else{
            printf("Deck count increased by %d. FAIL\n", comparison);
            failures++;
        }
    }


    //Current player's top card of deck not moved to discard deck (i.e. not == copper)
    printf("Testing that top card of P%d's discard pile is not from deck ... ", player);
    if(post.discard[player][post.discardCount[player] - 1] != copper){
        printf("PASS\n");
    }
    else{
        printf("FAIL\n");
        failures++;
    }

    //Current player's discard count not incremented
    printf("Testing that P%d's discard count has not changed ... ", player);
    comparison = post.discardCount[player] - pre.discardCount[player];
    if(comparison == 0){
        printf("PASS\n");
    }
    else{
        printf("Increased by %d. FAIL\n", comparison);
        failures++;
    }

    //Current player's deck top card is not curse
    printf("Testing that P%d's deck does not contain curse ... ", player);
    int curseFound = 0;
    int index;
    for(i = 0; i < post.deckCount[i]; i++){
        if(post.deck[player][i] == curse){
            curseFound = 1;
            index = i;
        }
    }

    if(curseFound == 0){
        printf("PASS\n");
    }
    else{
        printf("Curse card found at index %d. FAIL\n", index);
        failures++;
    }

    //Current player's hand count decreased by 1
    printf("Testing that P%d's hand count decreased by 1 ... ", player);
    comparison = pre.handCount[player] - post.handCount[player];
    if(comparison == 1){
        printf("PASS\n");
    }
    else{
        printf("Decreased by %d. FAIL\n", comparison);
        failures++;
    }

    //Current player's hand no longer contains sea hag
    int hagFound = 0;
    printf("Testing that P%d's hand no longer contains sea_hag ... ", player);
    for(i = 0; i < post.handCount[player]; i++){
        if(post.hand[player][i] == sea_hag){
            hagFound++;
            index = i;
        }
    }
    if(hagFound == 0){
        printf("PASS\n");
    }
    else{
        printf("sea_hag found at hand pos %d. FAIL\n", index);
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


    //Current playedCards has sea hag at top
    printf("Testing that playedCards has sea_hag at the top ... ");
    if(post.playedCards[post.playedCardCount - 1] == sea_hag){
        printf("PASS\n");
    }
    else{
        printf("FAIL\n");
        failures++;
    }

    //Test that nothing else in state has changed
    memcpy(&pre.handCount, &post.handCount, sizeof(int) * MAX_PLAYERS);
    memcpy(&pre.hand, &post.hand, sizeof(int) * MAX_PLAYERS * MAX_HAND);
    memcpy(&pre.deckCount, &post.deckCount, sizeof(int) * MAX_PLAYERS);
    memcpy(&pre.deck, &post.deck, sizeof(int) * MAX_PLAYERS * MAX_DECK);
    memcpy(&pre.discardCount, &post.discardCount, sizeof(int) * MAX_PLAYERS);
    memcpy(&pre.discard, &post.discard, sizeof(int) * MAX_PLAYERS * MAX_DECK);
    memcpy(&pre.playedCards, &post.playedCards, sizeof(int) * MAX_DECK);
    pre.playedCardCount = post.playedCardCount;

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
