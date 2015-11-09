/*
 * Tests adventurer card.
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
    int totalCards;             //Total number of cards in current player's hand, deck, and discard (3 to max_hand)
    int handCount;              //Randomized player hand count
    int deckCount;              //Randomized player deck count
    int discardCount;           //Randomized player discard count
    int handTreasureCount;      //Keep track of treasure cards in hand
    int deckTreasureCount;      //Keep track of treasure cards in deck
    int discardTreasureCount;   //Keep track of treasure cards in discard
    int handAdventurerCount;    //Keep track of adventurer cards in hand
    int adventurerPos;          //Randomized position of adventurer card in hand
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
    int checksFailed = 0;       //Total number of individual checks failed (i.e., errors detected)
    int numTests = 20000;       //Number of random tests to run


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

        printf("\nTEST CASE %d:\nPlayers: %d, Current Player: %d, HandCount: %d, DeckCount: %d, DiscardCount: %d\n",
               i+1, vars->numPlayers, vars->curPlayer, vars->handCount, vars->deckCount, vars->discardCount);
        printf("Hand Treasure Count: %d, Deck Treasure Count: %d, Discard Treasure Count: %d\n",
               vars->handTreasureCount, vars->deckTreasureCount, vars->discardTreasureCount);
        printf("Hand Adventurer Count: %d, GameSeed Value: %d\n",
               vars->handAdventurerCount, vars->gameSeed);

        //Call adventurerCardEffect
        adventurerCardEffect(vars->curPlayer, post);

        //Call function to test pre and post state. Returns 0 if no errors, 1 if errors.
        r = checkResults(pre, post, vars);

        //Print success or number of failures
        if(r == 0){
            printf("Test case %d passed all checks.\n", i);
        }
        else{
            printf("%d of 6 checks failed.\n", r);
            casesFailed++;  //Increment number of test cases with errors
            checksFailed += r;  //Keep running total of failed checks
        }

    }//END RANDOM TEST LOOP


   //Print number of tests and number of failed tests
   printf("\nTest cases run: %d\n", numTests);
   printf("Test cases with errors: %d\n", casesFailed);
   printf("Total checks failed: %d of %d\n", checksFailed, numTests * 6);

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
    //Also need to make sure there are at least 2 treasure cards in discard+deck, and at least 1 adventurer in hand

    //Set total number of cards in hand+deck+discard
    vars->totalCards = floor(Random() * (MAX_DECK - 2)) + 3;        //Needs to be at least 3 (adventurer and 2 treasure)

    //Since max_hand == max_deck, just use totalCards - 2 as ceiling for hand (need at least 2 left for treasure)
    vars->handCount = floor(Random() * (vars->totalCards - 2));
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
    //Place an adventurer card in a random hand pos
    vars->adventurerPos = floor(Random() * vars->handCount);
    post->hand[vars->curPlayer][vars->adventurerPos] = adventurer;
    //Count the number of adventurer and treasure cards in hand
    vars->handAdventurerCount = 0;
    vars->handTreasureCount = 0;
    for(j = 0; j < vars->handCount; j++){
        if(post->hand[vars->curPlayer][j] == adventurer){
            vars->handAdventurerCount++;
        }
        else if(post->hand[vars->curPlayer][j] == copper || post->hand[vars->curPlayer][j] == silver
                || post->hand[vars->curPlayer][j] == gold){
            vars->handTreasureCount++;
        }
    }

    //Debug (make sure random numbers are being generated properly)
    //printf("Total\tHand\tDeck\tDiscard\tTotal\n");
    //printf("%d\t%d\t%d\t%d\t%d\n", vars->totalCards, vars->handCount, vars->deckCount, vars->discardCount, (vars->handCount+vars->deckCount+vars->discardCount));

    //Debug
    //printf("Adventurer cards in hand: %d\n", vars->handAdventurerCount);

    //Fill deck with random cards (count treasure)
    //Do not allow adventurers, it could throw off discard check
    vars->deckTreasureCount = 0;
    for(j = 0; j < vars->deckCount; j++){
        do{
            post->deck[vars->curPlayer][j] = floor(Random() * 26);
        }while(post->deck[vars->curPlayer][j] == adventurer);
        if(post->deck[vars->curPlayer][j] == copper || post->deck[vars->curPlayer][j] == silver ||
            post->deck[vars->curPlayer][j] == gold){
            vars->deckTreasureCount++;
        }
    }

    //Fill discard with random cards(count treasure)
    //Do not allow adventurers, it could throw off discard check
    vars->discardTreasureCount = 0;
    for(j = 0; j < vars->discardCount; j++){
        do{
            post->discard[vars->curPlayer][j] = floor(Random() * 26);
        }while(post->discard[vars->curPlayer][j] == adventurer);
        if(post->discard[vars->curPlayer][j] == copper || post->discard[vars->curPlayer][j] == silver ||
            post->discard[vars->curPlayer][j] == gold){
            vars->discardTreasureCount++;
        }
    }
    //printf("Deck treasure = %d\n", vars->deckTreasureCount);
    //printf("Discard treasure = %d\n", vars->discardTreasureCount);

    //If there are not 2 treasure cards in deck+discard, add them
    if((vars->discardTreasureCount + vars->deckTreasureCount) < 2){
        //Determine size of deck+discard
        int count = vars->deckCount + vars->discardCount;
        //Pick two different random positions throughout the combined deck and discard pile
        int pos1 = floor(Random() * count);
        int pos2;
        do{
            pos2 = floor(Random() * count);
        }while(pos2 == pos1);
        //Now place treasure cards in the two random positions
        if(pos1 < vars->deckCount){
            post->deck[vars->curPlayer][pos1] = copper;
            vars->deckTreasureCount++;
        }
        else{
            post->discard[vars->curPlayer][(pos1 - vars->deckCount)] = copper;
            vars->discardTreasureCount++;
        }
        if(pos2 < vars->deckCount){
            post->deck[vars->curPlayer][pos2] = copper;
            vars->deckTreasureCount++;
        }
        else{
            post->discard[vars->curPlayer][(pos2 - vars->deckCount)] = copper;
            vars->handTreasureCount++;
        }

        //Debug
        //printf("Pos1 = %d\t pos2 = %d\n", pos1, pos2);

        //Debug -- count treasure in both and print total
        /*int treasure = 0;
        for(j = 0; j < vars->deckCount; j++){
            if(post->deck[vars->curPlayer][j] == copper){
                treasure++;
            }
        }
        for(j = 0; j < vars->discardCount; j++){
            if(post->discard[vars->curPlayer][j] == copper){
                treasure++;
            }
        }*/
        //printf("There is now %d copper in both deck and discard\n", treasure);

    }
    return;
}

int checkResults(struct gameState * pre, struct gameState * post, struct randomValues * vars){
    /*
    Checks to run each time:
    -Hand should have 2 more treasure cards
    -Hand should have 1 less adventurer
    -HandCount should be increased by 1 (2 cards drawn, 1 discarded)
    -Top of playedCards should be adventurer
    -No other parts of gamestate should change
    */

    int comparison;
    int failures = 0;
    int i;
    int r;
    int treasureCardsPost = 0;


    //CHECK 1: Test that hand has two additional treasure cards
    //printf("Testing that player's hand gained 2 treasure cards ... ");
    for(i = 0; i < post->handCount[vars->curPlayer]; i++){
        if(post->hand[vars->curPlayer][i] == copper || post->hand[vars->curPlayer][i] == silver || post->hand[vars->curPlayer][i] == gold){
            treasureCardsPost++;
        }
    }
    comparison = treasureCardsPost - vars->handTreasureCount;
    if(comparison != 2){
        printf("FAILED CHECK: Player hand gained %d treasure cards. Expected 2.\n", comparison);
        failures++;
    }

    //TEST DISCARD STUFF AND ARRAY SIZE CHANGES
    //Test that hand has net gain of 1 card (2 drawn, 1 discarded)
    comparison = post->handCount[vars->curPlayer] - pre->handCount[vars->curPlayer];
    if(comparison != 1){
        printf("FAILED CHECK: net gain to player's hand count is %d. Expected 1.\n", comparison);
        failures++;
    }

    //Test that playedCards in incremented
    comparison = post->playedCardCount - pre->playedCardCount;
    if(comparison != 1){
        printf("FAILED CHECK: gameState's playedCardCount increased by %d. Expected 1.\n", comparison);
        failures++;
    }

    //Test that player hand contains one less adventurer
    r = 0;
    for(i = 0; i < post->handCount[vars->curPlayer]; i++){
        if(post->hand[vars->curPlayer][i] == adventurer){
            r++;
        }
    }
    comparison = vars->handAdventurerCount - r;
    if(comparison != 1){
        printf("FAILED CHECK: Number of adventurers in player hand decreased by %d. Expected 1.\n", comparison);
        failures++;
    }

    //Test that top of playedCards contains adventurer
    if(post->playedCards[post->playedCardCount - 1] != adventurer){
        printf("FAILED CHECK: top of playedCard pile is NOT adventurer.\n");
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

