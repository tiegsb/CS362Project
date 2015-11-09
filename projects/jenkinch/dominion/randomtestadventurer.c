/* -----------------------------------------------------------------------
 * randomtestadventurer.c
 * Random test of cardEffect(adventurer) in dominion.c
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>
#include <time.h>

int testCardEffect(int card) {
    int seed = 1000;
    int numPlayer = 2;
    int currentPlayer = 0;
    int r, n, i, p;
    int treasureCount = 0;
    int treasureAdded = 0;
    int toDiscardCount = 0;
    int toDiscard[MAX_DECK];
    int k[10] = {sea_hag, council_room, feast, gardens, mine
                , remodel, smithy, village, adventurer, great_hall};
    struct gameState pre, post;
    int passed = 0;
    int failed = 0;
    
    SelectStream(2);
    PutSeed(6);
    srand(time(NULL));
    
    //Run n tests
    for(n = 0; n < 4; n++){
        printf("Test #%d\n", n);
        printf("\nStatus-----------------------------------\n");
        
        //Establish number of players
        numPlayer = rand() % (MAX_PLAYERS + 1 - 2) + 2;
        printf("numPlayer = %d\n", numPlayer);
        
        //Initialize game state then randomize values
        r = initializeGame(numPlayer, k, seed, &pre);
        pre.numPlayers = numPlayer;
        
        currentPlayer = rand() % numPlayer;
        pre.whoseTurn = currentPlayer;
        printf("currentPlayer = %d\n", currentPlayer);
        
        treasureCount = 0;
        treasureAdded = 0;
        toDiscardCount = 0;
        
        for(i = 0; i < 27; i++){
            pre.supplyCount[i] = rand();
            pre.embargoTokens[i] = rand();
        }
        
        pre.outpostPlayed = rand();
        pre.outpostTurn = rand();
        pre.phase = rand();
        pre.numActions = rand();
        pre.coins = rand();
        pre.numBuys = rand();
          
        //Set relevant gamestate attributes for each player
        for(p = 0; p < numPlayer; p++){
            pre.deckCount[p] = rand() % MAX_DECK;
            pre.discardCount[p] = rand() % MAX_DECK;
            pre.handCount[p] = rand() % MAX_HAND;
            
            //Increase chance to set deckCount to 0
            if(rand() % 2 == 0)
                pre.deckCount[p] = 0;
            
            if(pre.deckCount != 0){
                for(i = 0; i < pre.deckCount[p]; i++){
                    pre.deck[p][i] = (int)(Random() * 27);
                    if(pre.deck[p][i] == copper || pre.deck[p][i] == silver || pre.deck[p][i] == gold)
                        treasureAdded++;
                }
            }
            
            for(i = 0; i < pre.discardCount[p]; i++){
                pre.discard[p][i] = (int)(Random() * 27);
                if(pre.discard[p][i] == copper || pre.discard[p][i] == silver || pre.discard[p][i] == gold)
                    treasureAdded++;
            }
            
            for(i = 0; i < pre.handCount[p]; i++){
                pre.hand[p][i] = (int)(Random() * 27);
            }
            
            //Card expects that deck+discard contains at least two treasures; add 1 or 2 if necessary
            i = 0;
            if(treasureAdded < 2){
                while(treasureAdded < 2){
                    pre.discard[p][i] = copper;
                    treasureAdded++;
                    i++;
                }
            } 
        }
        
        //Output status
        printf("Pre ending currentPlayer deckCount = %d, discardCount = %d, handCount = %d\n", pre.deckCount[currentPlayer], pre.discardCount[currentPlayer], pre.handCount[currentPlayer]);
    
        //Create copy of game state prior to card effect activation
        memcpy(&post, &pre, sizeof(struct gameState));
        
        //Activate card
        r = cardEffect(card, 0, 0, 0, &post, 0, 0);
        
        //Draw through deck until two treasures are pulled
        if(pre.deckCount[pre.whoseTurn] > 0){
            for(i = pre.deckCount[pre.whoseTurn]-1; i >= 0 && treasureCount < 2; i--){
                if(pre.deck[pre.whoseTurn][i] == copper || pre.deck[pre.whoseTurn][i] == silver || pre.deck[pre.whoseTurn][i] == gold){
                    pre.handCount[pre.whoseTurn]++;
                    pre.hand[pre.whoseTurn][pre.handCount[pre.whoseTurn]-1] = pre.deck[pre.whoseTurn][i];
                    pre.deckCount[pre.whoseTurn]--;
                    treasureCount++;
                }
                else{
                    toDiscard[toDiscardCount] = pre.deck[pre.whoseTurn][i];
                    toDiscardCount++;
                    pre.deckCount[pre.whoseTurn]--;
                }
            }
        }
        
        //If two treasures still haven't been pulled and deck is exhausted, grab from shuffled discard
        if(treasureCount < 2){
            if(pre.discardCount[pre.whoseTurn] > 0){
                memcpy(pre.deck[pre.whoseTurn], pre.discard[pre.whoseTurn], sizeof(int)*pre.discardCount[pre.whoseTurn]);
                pre.deckCount[pre.whoseTurn] = pre.discardCount[pre.whoseTurn];
                pre.discardCount[pre.whoseTurn] = 0;
                
                for(i = pre.deckCount[pre.whoseTurn]-1; i >= 0 && treasureCount < 2; i--){
                    if(pre.deck[pre.whoseTurn][i] == copper || pre.deck[pre.whoseTurn][i] == silver || pre.deck[pre.whoseTurn][i] == gold){
                        pre.handCount[pre.whoseTurn]++;
                        pre.hand[pre.whoseTurn][pre.handCount[pre.whoseTurn]-1] = pre.deck[pre.whoseTurn][i];
                        pre.deckCount[pre.whoseTurn]--;
                        treasureCount++;
                    }
                    else{
                        toDiscard[toDiscardCount] = pre.deck[pre.whoseTurn][i];
                        toDiscardCount++;
                        pre.deckCount[pre.whoseTurn]--;
                    }
                }
            }
        }
        
        //Discard revealed non-treasure cards
        memcpy(pre.discard[pre.whoseTurn] + pre.discardCount[pre.whoseTurn], toDiscard, sizeof(int)*toDiscardCount);
        pre.discardCount[pre.whoseTurn] = pre.discardCount[pre.whoseTurn] + toDiscardCount;
        
        //Output status
        printf("Pre ending currentPlayer deckCount = %d, discardCount = %d, handCount = %d\n", pre.deckCount[currentPlayer], pre.discardCount[currentPlayer], pre.handCount[currentPlayer]);
        
        printf("Post ending currentPlayer deckCount = %d, discardCount = %d, handCount = %d\n", post.deckCount[currentPlayer], post.discardCount[currentPlayer], post.handCount[currentPlayer]);
        printf("\nTest Results-----------------------------\n");
        
        //Test for successful function call
        if(r == 0){
            printf("cardEffect(adventurer): PASS, function returned successfully \n");
            passed++;
        }
        else{
            printf("cardEffect(adventurer): FAIL, function returned unsuccessfully \n");
            failed++;
        }
        
        //Test for updated handCount
        if(pre.handCount[currentPlayer] == post.handCount[currentPlayer]){
            printf("cardEffect(adventurer): PASS, handCount correct after discard/draw \n");
            passed++;
        }
        else{
            printf("cardEffect(adventurer): FAIL, handCount incorrect after discard/draw \n");
            failed++;
        }
        
        //Test for updated discardCount and deckCount for currentPlayer
        if(pre.discardCount[currentPlayer] + pre.deckCount[currentPlayer] == post.discardCount[currentPlayer] + post.deckCount[currentPlayer]){
            printf("cardEffect(adventurer): PASS, pre and post discardCount + deckCount sums match \n");
            passed++;
        }
        else{
            printf("cardEffect(adventurer): FAIL, pre and post discardCount + deckCount sums don't match \n");
            failed++;
        }
        
        //Test for valid resulting hand
        for(i = 0; i < pre.handCount[currentPlayer]; i++){
            if(i < pre.handCount[currentPlayer] - 2){
                if(pre.hand[currentPlayer][i] != post.hand[currentPlayer][i]){
                    printf("cardEffect(adventurer): FAIL, incorrect card in handPos %d \n", i);
                    failed++;
                }
                else
                    passed++;
            }
            else{
                if(post.hand[currentPlayer][i] != copper || post.hand[currentPlayer][i] != silver || post.hand[currentPlayer][i] != gold){
                    printf("cardEffect(adventurer): FAIL, incorrect card in handPos %d \n", i);
                    failed++;
                }
                else
                    passed++;
            }
        }
        
        //Test that other player's counts weren't affected
        for(p = 0; p < numPlayer; p++){
            if(p != currentPlayer){
                //Test for unaffected handCount for other players
                if(pre.handCount[p] == post.handCount[p]){
                    printf("cardEffect(adventurer): PASS, player %d handCount unaffected after currentPlayer %d discard/draw \n", p, currentPlayer);
                    passed++;
                }
                else{
                    printf("cardEffect(adventurer): FAIL, player %d handCount affected after currentPlayer %d discard/draw \n", p, currentPlayer);
                    failed++;
                }
                
                //Test for unaffected discardCount for other players
                if(pre.discardCount[p] == post.discardCount[p]){
                    printf("cardEffect(adventurer): PASS, player %d discardCount unaffected after currentPlayer %d discard \n", p, currentPlayer);
                    passed++;
                }
                else{
                    printf("cardEffect(adventurer): FAIL, player %d discardCount affected after currentPlayer %d discard \n", p, currentPlayer);
                    failed++;
                }
                
                //Test for unaffected deckCount for other players
                if(pre.deckCount[p] == post.deckCount[p]){
                    printf("cardEffect(adventurer): PASS, player %d deckCount unaffected after currentPlayer %d draw \n", p, currentPlayer);
                    passed++;
                }
                else{
                    printf("cardEffect(adventurer): FAIL, player %d deckCount affected after currentPlayer %d draw \n", p, currentPlayer);
                    failed++;
                }
            }
        }
        
        printf ("\n\n");
    }
    
    printf("Summary----------------------------------");
    printf("\nTests Run: %d, Test Cases Passed: %d, Test Cases Failed: %d\n\n", n, passed, failed);
    
    return 0;
}

int main(int argc, char *argv[])
{
    testCardEffect(adventurer);
    return 0;
}