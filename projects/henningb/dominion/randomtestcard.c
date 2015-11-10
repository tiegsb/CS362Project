/*
 * Tests smithy card.
 *
 */
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "rngs.h"

//Store all the variables that will be randomized in one big struct, to make it easier to pass to functions
struct randomValues{
    int numPlayers;             //Randomized number of players in game (2-4)
    int curPlayer;              //Randomized current player
    int totalCards;             //Total number of cards in current player's hand, deck, and discard (4 to max_hand)
    int handCount;              //Randomized player hand count
    int deckCount;              //Randomized player deck count
    int discardCount;           //Randomized player discard count
    int handSmithyCount;        //Keep track of smithy cards in hand (to check discard)
    int smithyPos;               //Randomized position of adventurer card in hand
    int gameSeed;               //Random value for seeding game
};

//Initializes game state, sets random variables and stores them in vars. Modifies gamestate with values from vars
void randomize(struct gameState * post, struct randomValues * vars, int k[]);
//Runs checks on the random set-up
int checkResults(struct gameState * pre, struct gameState * post, struct randomValues * vars);

int main (){
    srand(time(NULL));
    int i, r;
    int casesFailed = 0;        //Number of test cases with failed checks
    int checksFailed = 0;       //Number of individual checks failed
    int numTests = 20000;        //Number of random tests to run


    int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

    //Allocate memory for pre and post function game states, and struct for random variables
    struct gameState * post = malloc(sizeof(struct gameState));
    struct gameState * pre = malloc(sizeof(struct gameState));
    struct randomValues * vars = malloc(sizeof(struct randomValues));

    for(i = 0; i < numTests; i++){

        //Pass the gamestate to function for generating random values
        randomize(post, vars, k);

        //Make copy of gamestate
        memcpy(pre, post, sizeof(struct gameState));

        //Print test variables
        printf("\nTEST CASE %d:\nPlayers: %d, Current Player: %d, HandCount: %d, DeckCount: %d, DiscardCount: %d\n",
               i+1, vars->numPlayers, vars->curPlayer, vars->handCount, vars->deckCount, vars->discardCount);
        printf("Hand Smithy Count: %d, Smithy Hand Pos: %d, GameSeed Value: %d\n",
               vars->handSmithyCount, vars->smithyPos, vars->gameSeed);

        //Call smithyCardEddrect
        smithyCardEffect(vars->smithyPos, vars->curPlayer, post);

        //Call function to test pre and post state. Returns 0 if no errors, 1 if errors.
        r = checkResults(pre, post, vars);

        //Print success or number of failures
        if(r == 0){
            printf("Test case %d passed all checks.\n", i);
        }
        else{
            printf("%d of 5 checks failed.\n", r);
            casesFailed++;  //Increment number of test cases with errors
            checksFailed += r;  //Keep running total of failed checks
        }

    }//END RANDOM TEST LOOP


   //Print number of tests and number of failed tests
   printf("\nTest cases run: %d\n", numTests);
   printf("Test cases with errors: %d\n", casesFailed);
   printf("Total checks failed: %d of %d\n", checksFailed, numTests * 5);

    return 0;
}

void randomize(struct gameState * post, struct randomValues * vars, int k[]){

    int r, j;
    //Randomize numPlayers, curPlayer, and gameSeed
    vars->numPlayers = floor(Random() * 3) + 2;           //Min: 2, Max: 4
    vars->curPlayer = floor(Random() * vars->numPlayers);       //Min: 0, Max: curPlayer
    vars->gameSeed = rand();

    /*//DEBUG
    printf("NumPlayers\tcurPlayer\tgameSeed\n");
    printf("%d\t\t%d\t\t%d\n", numPlayers, curPlayer, gameSeed);
    */

    //Initialize game
    r = initializeGame(vars->numPlayers, k, vars->gameSeed, post);

    //Set the random variables for current player
    //Need controlled randomization of deckCount, discardCount, handCount, deck, discard, and hand
    //Also need to make sure there are at least 3 discard+deck, and at least 1 smithy in hand

    //Set total number of cards in hand+deck+discard
    vars->totalCards = floor(Random() * (MAX_DECK - 2)) + 4;        //Needs to be at least 4 (Smithy, 3 cards to draw)

    //Since max_hand == max_deck, just use totalCards - 3 as ceiling for hand (need at least 3 left for drawing)
    vars->handCount = floor(Random() * (vars->totalCards - 3));
    if(vars->handCount == 0){
        vars->handCount++;
        vars->totalCards++;
    }
    vars->deckCount = floor(Random() * (vars->totalCards - vars->handCount + 1));
    vars->discardCount = vars->totalCards - (vars->handCount + vars->deckCount);
    post->deckCount[vars->curPlayer] = vars->deckCount;
    post->handCount[vars->curPlayer] = vars->handCount;
    post->discardCount[vars->curPlayer] = vars->discardCount;

    //Fill hand with random cards
    for(j = 0; j < vars->handCount; j++){
        post->hand[vars->curPlayer][j] = floor(Random() * 26);
    }
    //Place a smithy card in a random hand pos
    vars->smithyPos = floor(Random() * vars->handCount);
    post->hand[vars->curPlayer][vars->smithyPos] = smithy;
    //Count the number of smithy cards in hand
    vars->handSmithyCount = 0;
    for(j = 0; j < vars->handCount; j++){
        if(post->hand[vars->curPlayer][j] == smithy){
            vars->handSmithyCount++;
        }
    }

    //Debug (make sure random numbers are being generated properly)
    //printf("Total\tHand\tDeck\tDiscard\tTotal\n");
    //printf("%d\t%d\t%d\t%d\t%d\n", vars->totalCards, vars->handCount, vars->deckCount, vars->discardCount, (vars->handCount+vars->deckCount+vars->discardCount));

    //Debug
    //printf("Smithy cards in hand: %d\n", vars->handSmithyCount);

    //Fill deck with random cards
    //Do not allow smithies in deck or discard because it could throw off discard check
    for(j = 0; j < vars->deckCount; j++){
        do{
            post->deck[vars->curPlayer][j] = floor(Random() * 26);
        }while(post->deck[vars->curPlayer][j] == smithy);
    }

    //Fill discard with random cards
    //Don't allow smithies because it could throw off discard check
    for(j = 0; j < vars->discardCount; j++){
        do{
            post->discard[vars->curPlayer][j] = floor(Random() * 26);
        }while(post->discard[vars->curPlayer][j] == smithy);
    }

    return;
}


int checkResults(struct gameState * pre, struct gameState * post, struct randomValues * vars){
    /*
    Checks to run each time:
    -Hand should have net gain of 2 cards (3 drawn, 1 discarded)
    -Hand should have 1 less smithy card than before
    -PlayedCardsCount should be increased by 1
    -Top of playedCards should be smithy
    -Nothing else in gameState should change
    */

    int comparison;
    int failures = 0;
    int i;
    int smithyCardsPost = 0;    //How many smithy cards are in hand after card played

    //Test that hand has net gain of 2 cards (3 drawn, 1 discarded)
    comparison = post->handCount[vars->curPlayer] - pre->handCount[vars->curPlayer];
    if(comparison != 2){
        printf("FAILED CHECK: net gain to player's hand count is %d. Expected 2.\n", comparison);
        failures++;
    }

    //Test that player hand contains one less smithy
    for(i = 0; i < post->handCount[vars->curPlayer]; i++){
        if(post->hand[vars->curPlayer][i] == smithy){
            smithyCardsPost++;
        }
    }
    comparison = vars->handSmithyCount - smithyCardsPost;
    if(comparison != 1){
        printf("FAILED CHECK: Number of smithies in player hand decreased by %d. Expected 1.\n", comparison);
        failures++;
    }

    //Test that playedCards in incremented
    comparison = post->playedCardCount - pre->playedCardCount;
    if(comparison != 1){
        printf("FAILED CHECK: gameState's playedCardCount increased by %d. Expected 1.\n", comparison);
        failures++;
    }

    //Test that top of playedCards contains smithy
    if(post->playedCards[post->playedCardCount - 1] != smithy){
        printf("FAILED CHECK: top of playedCard pile is NOT smithy.\n");
        failures++;
    }

    //Test that no other changes to state occurred
    pre->handCount[vars->curPlayer] = post->handCount[vars->curPlayer];
    memcpy(pre->hand[vars->curPlayer], post->hand[vars->curPlayer], sizeof(int) * MAX_HAND);
    pre->playedCardCount = post->playedCardCount;
    memcpy(pre->playedCards, post->playedCards, sizeof(int) * MAX_DECK);
    pre->discardCount[vars->curPlayer] = post->discardCount[vars->curPlayer];
    memcpy(pre->discard[vars->curPlayer], post->discard[vars->curPlayer], sizeof(int) * MAX_DECK);
    pre->deckCount[vars->curPlayer] = post->deckCount[vars->curPlayer];
    memcpy(pre->deck[vars->curPlayer], post->deck[vars->curPlayer], sizeof(int) * MAX_DECK);
    comparison = memcmp(pre, post, sizeof(struct gameState));
    if(comparison != 0){
        printf("FAILED CHECK: Other areas of game state altered.\n");
        failures++;
    }


    return failures;
}

