/*
 * Tests the shuffle function
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int checkShuffle(int player, struct gameState * post, int testDeckCount);
int compare(const int* a, const int* b);

int main () {

    int r;
    int failures = 0;   //Number of checks failed

    int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

    //Initialize game
    struct gameState G;
    r = initializeGame(2, k, 1, &G);

    printf ("Testing shuffle.\n");

    //Test shuffle on decks containing 0 cards, 1 card, and many cards
    //Check shuffle function on deck with MAX_DECK cards
    printf("\nCase 1: Testing shuffle on deck of count 0\n");
    r = checkShuffle(1, &G, 0);
    failures += r;

    //Check shuffle function on deck with MAX_DECK cards
    printf("\nCase 2: Testing shuffle on deck of count 1\n");
    r = checkShuffle(1, &G, 1);
    failures += r;

    //Check shuffle function on deck with MAX_DECK cards
    printf("\nCase 3: Testing shuffle on deck of count %d\n", MAX_DECK);
    r = checkShuffle(1, &G, MAX_DECK);
    failures += r;

    if(failures == 0){
        printf("\nAll checks passed\n");
    }
    else{
        printf("\n%d checks failed\n", failures);
    }

    return 0;
}

int checkShuffle(int player, struct gameState * post, int testDeckCount){


    int failures = 0; //Number of checks failed
    int comparison;

    //Set deckcount to testCount
    post->deckCount[player] = testDeckCount;

    //Create a pre-function copy of struct for comparison
    struct gameState pre;
    memcpy(&pre, post, sizeof(struct gameState));


    //Run the shuffle function
    int r = shuffle(player, post);

    //Check shuffle return values
    if(testDeckCount > 0){
        if(r == 0){
            printf("Testing shuffle return value. Expecting 0. Returned 0 ... PASS\n");
        }
        else{
            printf("Testing shuffle return value. Expecting 0. Returned %d ... FAIL\n", r);
            failures++;
        }
    }
    else{   //Shuffle should return -1 with a deck size of < 1
        if(r == -1){
            printf("Testing shuffle return value. Expecting -1. Returned -1 ... PASS\n");
        }
        else{
            printf("Testing shuffle return value. Expecting -1. Returned %d ... FAIL\n", r);
            failures++;
        }
    }

    //Check deck order and game state

    //Case 1: Deck with less than 1 card
    if(testDeckCount < 1){
        //Game state should be unchanged
        printf("Testing that game state has not changed ... ");
        comparison = memcmp(&pre, post, sizeof(struct gameState));
        if(comparison == 0){
            printf("PASS\n");
        }
        else{
            printf("FAIL\n");
            failures++;
        }
    }

    //Case 2: Deck with 1 card
    if(testDeckCount == 1){

        //Player's deck should not be rearranged
        comparison = memcmp(&pre.deck[player], post->deck[player], sizeof(int) * testDeckCount);
        printf("Testing that order of player %d's deck has not changed ... ", player);
        if(comparison == 0){
            printf("PASS\n");
        }
        else{
            printf("FAIL\n");
            failures++;
        }

        //Nothing in game state should be changed
        printf("Testing that game state has not changed ... ");
        comparison = memcmp(&pre, post, sizeof(struct gameState));
        if(comparison == 0){
            printf("PASS\n");
        }
        else{
            printf("FAIL\n");
            failures++;
        }
    }

    //Case 3: Deck with more than 1 card
    if(testDeckCount > 1){
        /* Test whether the order of player's deck has changed
         * Unchanged deck does not necessarily mean failure, as lower
         * count decks might be shuffled into the same order sometimes*/
        printf("Testing if deck is in different order ... ");
        comparison = memcmp(&pre.deck[player], post->deck[player], sizeof(int) * testDeckCount);

        if(comparison == 0){
            printf("FALSE\n");
        }
        else{
            printf("TRUE\n");
        }

        //Test that the decks in pre and post contain the same cards, just in different order
        //Sort both decks and memcmp
        qsort ((void*)(pre.deck[player]), pre.deckCount[player], sizeof(int), compare);
        qsort ((void*)(post->deck[player]), post->deckCount[player], sizeof(int), compare);
        comparison = memcmp(&pre.deck[player], post->deck[player], sizeof(int) * testDeckCount);
        printf("Sorting decks and testing that they contain the same cards ... ");
        if(comparison == 0){
            printf("PASS\n");
        }
        else{
            printf("FAIL\n");
            failures++;
        }

        //Test that the rest of the game state is unchanged
        memcpy(pre.deck[player], post->deck[player], sizeof(int) * testDeckCount);
        comparison = memcmp(&pre, post, sizeof(struct gameState));
        printf("Testing that rest of game state is unchanged ... ");
        if(comparison == 0){
            printf("PASS\n");
        }
        else{
            printf("FAIL\n");
            failures++;
        }

    }


    //If no failures, return 0. Otherwise, return number of failures
    return failures;
}
