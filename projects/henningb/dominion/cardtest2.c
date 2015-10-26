/*
 * Tests adventurer card.
 *
 */
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int checkResults(int player, struct gameState * pre, struct gameState * post, int silent);  //Standard checks to run on all cases

int main (){

    int i, r, player;
    int failures = 0;   //Number of checks failed

    int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};


    /*

    Cases to test:
    2 treasure cards in deck, 0 treasure cards in discard (doesn't require a shuffle)
    (repeat the above test 3 times where treasure cards are copper, silver, and gold to verify it counts all of them as treasure)
    1 treasure card in deck, 1 treasure card in discard (Requires shuffle)
    0 treasure cards in deck, 2 treasure cards in discard (Also requires shuffle)
    */



    struct gameState post;

    player = 1;
/**
    CASE 1: No shuffling required
**/
    printf("Testing adventurer card\n");
    printf("Case 1: 2 treasure cards (copper) in deck, 0 in discard, 0 in hand. Adventurer at pos 4.\n");
    printf("No other adventurer or treasure cards in deck, hand, or discard pile\n");

    //Initialize game
    r = initializeGame(2, k, 1, &post);
    post.whoseTurn = player;

    //Set player 1's hand to one adventurer and 4 baron, to make testing easier
    post.handCount[player] = 5;
    post.hand[player][0] = baron;
    post.hand[player][1] = baron;
    post.hand[player][2] = baron;
    post.hand[player][3] = baron;
    post.hand[player][4] = adventurer;

    //Fill player's deck with baron cards
    post.deckCount[player] = 5;
    for(i = 0; i < post.deckCount[player]; i++){
        post.deck[player][i] = baron;
    }

    //Add two copper cards to deck
    post.deck[player][1] = copper;
    post.deck[player][4] = copper;


    //Set discard pile to baron cards
    post.discardCount[player] = 5;
    for(i = 0; i < post.discardCount[player]; i++){
        post.discard[player][i] = baron;
    }

    //Make a copy of game state
    struct gameState pre;
    memcpy(&pre, &post, sizeof(struct gameState));

    //play adventurer card
    //Since we are not testing playCard or cardEffect, just call adventurer card function
    adventurerCardEffect(player, &post);

    //Run checks
    failures += checkResults(player, &pre, &post, 0);

/**
    CASE 2: Shuffling required
**/
    printf("\nCase 2: 1 treasure cards (gold) in deck, 1 (silver) in discard, 0 in hand. Adventurer at pos 4.\n");
    printf("No other adventurer or treasure cards in deck, hand, or discard pile\n");

    //Initialize game
    r = initializeGame(2, k, 1, &post);
    post.whoseTurn = player;

    //Set player 1's hand to one adventurer and 4 baron, to make testing easier
    post.handCount[player] = 5;
    post.hand[player][0] = baron;
    post.hand[player][1] = baron;
    post.hand[player][2] = baron;
    post.hand[player][3] = baron;
    post.hand[player][4] = adventurer;

    //Fill player's deck with baron cards
    post.deckCount[player] = 5;
    for(i = 0; i < post.deckCount[player]; i++){
        post.deck[player][i] = baron;
    }

    //Add two copper cards to deck
    post.deck[player][4] = gold;


    //Set discard pile to baron cards
    post.discardCount[player] = 5;
    for(i = 0; i < post.discardCount[player]; i++){
        post.discard[player][i] = baron;
    }
    post.discard[player][2] = silver;

    //Make a copy of game state
    memcpy(&pre, &post, sizeof(struct gameState));

    //play adventurer card
    //Since we are not testing playCard or cardEffect, just call adventurer card function
    adventurerCardEffect(player, &post);

    //Run checks
    failures += checkResults(player, &pre, &post, 0);


   if(failures == 0){
        printf("\nAll tests passed\n");
   }
   else{
        printf("\n%d failures occurred\n", failures);
   }

    return 0;
}

int checkResults(int player, struct gameState * pre, struct gameState * post, int silent){
    /*Checks to run each time:
    Hand should have net gain of 1 card
    Hand should have 2 additional treasure cards
    Played cards should be incremented
    Played cards should contain adventurer
    Sum of discardCount and deckCount should be decreased by 2
    Nothing else in state should change*/
    int comparison;
    int failures = 0;
    int i;
    int r;
    int treasureCardsPre = 0;;
    int treasureCardsPost = 0;

    //Make sure hand has net gain of 1 card
    if(silent == 0)
        printf("Testing that player's hand has net gain of 1 card ... ");
    comparison = post->handCount[player] - pre->handCount[player];
    if(comparison == 1){
        if(silent == 0)
            printf("PASS\n");
    }
    else{
        if(silent == 0)
            printf("Net gain of %d. FAIL\n", comparison);
        failures++;
    }

    //Test that hand has two additional treasure cards
    if(silent == 0)
        printf("Testing that player's hand gained 2 treasure cards ... ");
    for(i = 0; i < pre->handCount[player]; i++){
        if(pre->hand[player][i] == copper || pre->hand[player][i] == silver || pre->hand[player][i] == gold){
            treasureCardsPre++;
        }
    }
    for(i = 0; i < post->handCount[player]; i++){
        if(post->hand[player][i] == copper || post->hand[player][i] == silver || post->hand[player][i] == gold){
            treasureCardsPost++;
        }
    }
    comparison = treasureCardsPost - treasureCardsPre;
    if(comparison == 2){
        if(silent == 0)
            printf("PASS\n");
    }
    else{
        if(silent == 0)
            printf("%d treasure cards gained. FAIL\n", comparison);
        failures++;
    }

    //TEST THAT ADVENTURER WAS DISCARDED
    //Test that playedCards in incremented
    if(silent == 0)
        printf("Testing that playedCardCount is incremented by 1 ... ");
    comparison = post->playedCardCount - pre->playedCardCount;
    if(comparison == 1){
        if(silent == 0)
            printf("PASS\n");
    }
    else{
        if(silent == 0)
            printf("Increased by %d. FAIL\n", comparison);
        failures++;
    }

    //Test that top of playedCards contains adventurer
    if(silent == 0)
        printf("Testing that top of playedCards is adventurer ... ");
    if(post->playedCards[post->playedCardCount - 1] == adventurer){
        if(silent == 0)
            printf("PASS\n");
    }
    else{
        if(silent == 0)
            printf("FAIL\n");
            failures++;
    }

    //Test that no adventurer is in hand
    if(silent == 0)
        printf("Testing that hand no longer contains adventurer ... ");
    r = 0;
    for(i = 0; i < post->handCount[player]; i++){
        if(post->hand[player][i] == adventurer){
            r = -1;
        }
    }
    if(r == 0){
        if(silent == 0)
            printf("PASS\n");
    }
    else{
        if(silent == 0)
            printf("FAIL\n");
        failures++;
    }


    //Test that sum of discardCount and deckCount is decreased by 2
    if(silent == 0)
        printf("Testing that sum of discardCount and deckCount decreased by 2 ... ");
    comparison = (pre->discardCount[player] + pre->deckCount[player]) - (post->discardCount[player] + post->deckCount[player]);
    if(comparison == 2){
        if(silent == 0)
            printf("PASS\n");
    }
    else{
        if(silent == 0)
            printf("FAIL\n");
        failures++;
    }

    //Test that no other changes to state occurred
    pre->handCount[player] = post->handCount[player];
    memcpy(pre->hand[player], post->hand[player], sizeof(int) * MAX_HAND);
    pre->playedCardCount = post->playedCardCount;
    memcpy(pre->playedCards, post->playedCards, sizeof(int) * MAX_DECK);
    pre->discardCount[player] = post->discardCount[player];
    memcpy(pre->discard[player], post->discard[player], sizeof(int) * MAX_DECK);
    pre->deckCount[player] = post->deckCount[player];
    memcpy(pre->deck[player], post->deck[player], sizeof(int) * MAX_DECK);
    printf("Testing that nothing else in game state was changed ... ");
    comparison = memcmp(pre, post, sizeof(struct gameState));
    if(comparison == 0){
        printf("PASS\n");
    }
    else{
        printf("FAIL\n");
        failures++;
    }



    return failures;
}
