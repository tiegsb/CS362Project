/* -----------------------------------------------------------------------
 * randomtestcard.c
 * Random test of cardEffect(village) in dominion.c
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
    int k[10] = {sea_hag, council_room, feast, gardens, mine
                , remodel, smithy, village, adventurer, great_hall};
    struct gameState pre, post;
    int handPosOfVillage[MAX_PLAYERS];
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
            
            for(i = 0; i < pre.deckCount[p]; i++){
                pre.deck[p][i] = (int)(Random() * 27);
            }
            
            for(i = 0; i < pre.discardCount[p]; i++){
                pre.discard[p][i] = (int)(Random() * 27);
            }
            
            for(i = 0; i < pre.handCount[p]; i++){
                pre.hand[p][i] = (int)(Random() * 27);
            }
            
            //Set position of village card in hand
            handPosOfVillage[p] = rand() % pre.handCount[p];
            pre.hand[p][handPosOfVillage[p]] = village;
            
            //Increase chance to set deckCount to 0
            if(rand() % 2 == 0)
                pre.deckCount[p] = 0;
        }
        
        //Output status
        printf("Starting currentPlayer deckCount = %d, discardCount = %d, handCount = %d, handPosOfVillage = %d\n", pre.deckCount[currentPlayer], pre.discardCount[currentPlayer], pre.handCount[currentPlayer], handPosOfVillage[currentPlayer]);
    
        //Create copy of game state prior to card effect activation
        memcpy(&post, &pre, sizeof(struct gameState));
        
        //Activate card
        r = cardEffect(card, 0, 0, 0, &post, handPosOfVillage[pre.whoseTurn], 0);
        
        //Draw 1 card
        if(pre.deckCount[pre.whoseTurn] > 0){
            pre.handCount[pre.whoseTurn]++;
            pre.hand[pre.whoseTurn][pre.handCount[pre.whoseTurn]-1] = pre.deck[pre.whoseTurn][pre.deckCount[pre.whoseTurn]-1];
            pre.deckCount[pre.whoseTurn]--;
        }
        else if(pre.discardCount[pre.whoseTurn] > 0){
            memcpy(pre.deck[pre.whoseTurn], pre.discard[pre.whoseTurn], sizeof(int)*pre.discardCount[pre.whoseTurn]);
            pre.handCount[pre.whoseTurn]++;
            pre.deckCount[pre.whoseTurn] = pre.discardCount[pre.whoseTurn];
            pre.hand[pre.whoseTurn][pre.handCount[pre.whoseTurn]-1] = pre.deck[pre.whoseTurn][pre.deckCount[pre.whoseTurn]-1];
            pre.deckCount[pre.whoseTurn]--;
            pre.discardCount[pre.whoseTurn] = 0;
        }
        
        //Add 2 to number of actions
        pre.numActions = pre.numActions + 2;
        
        //Discard village at handPosOfVillage
        pre.discardCount[pre.whoseTurn]++;
        pre.discard[pre.whoseTurn][pre.discardCount[pre.whoseTurn]-1] = pre.hand[pre.whoseTurn][handPosOfVillage[pre.whoseTurn]];
        pre.hand[pre.whoseTurn][handPosOfVillage[pre.whoseTurn]] = pre.hand[pre.whoseTurn][pre.handCount[pre.whoseTurn]-1];
        pre.handCount[pre.whoseTurn]--;
        
        //Output status
        printf("Pre ending currentPlayer deckCount = %d, discardCount = %d, handCount = %d\n", pre.deckCount[currentPlayer], pre.discardCount[currentPlayer], pre.handCount[currentPlayer]);
        
        printf("Post ending currentPlayer deckCount = %d, discardCount = %d, handCount = %d\n", post.deckCount[currentPlayer], post.discardCount[currentPlayer], post.handCount[currentPlayer]);
        
        printf("\nTest Results-----------------------------\n");
        
        //Test for successful function call
        if(r == 0){
            printf("cardEffect(village): PASS, function returned successfully \n");
            passed++;
        }
        else{
            printf("cardEffect(village): FAIL, function returned unsuccessfully \n");
            failed++;
        }
        
        //Test for updated handCount
        if(pre.handCount[currentPlayer] == post.handCount[currentPlayer]){
            printf("cardEffect(village): PASS, handCount correct after discard/draw \n");
            passed++;
        }
        else{
            printf("cardEffect(village): FAIL, handCount incorrect after discard/draw \n");
            failed++;
        }
        
        //Test for updated discardCount
        if(pre.discardCount[currentPlayer] == post.discardCount[currentPlayer]){
            printf("cardEffect(village): PASS, discardCount correct after discard \n");
            passed++;
        }
        else{
            printf("cardEffect(village): FAIL, discardCount incorrect after discard \n");
            failed++;
        }
        
        //Test that latest card on discard is the same (a village)
        if(pre.discard[currentPlayer][pre.discardCount[currentPlayer]-1] == post.discard[currentPlayer][post.discardCount[currentPlayer]-1]){
            printf("cardEffect(village): PASS, latest card on discard pile correct \n");
            passed++;
        }
        else{
            printf("cardEffect(village): FAIL, latest card on discard pile incorrect \n");
            failed++;
        }
        
        //Test for updated deckCount
        if(pre.deckCount[currentPlayer] == post.deckCount[currentPlayer]){
            printf("cardEffect(village): PASS, deckCount correct after draw \n");
            passed++;
        }
        else{
            printf("cardEffect(village): FAIL, deckCount incorrect after draw \n");
            failed++;
        }
        
        //Test for updated numActions
        if(pre.numActions == post.numActions){
            printf("cardEffect(village): PASS, numActions correct after update \n");
            passed++;
        }
        else{
            printf("cardEffect(village): FAIL, numActions incorrect after update \n");
            failed++;
        }
        
        //Test that other player's counts weren't affected
        for(p = 0; p < numPlayer; p++){
            if(p != currentPlayer){
                //Test for unaffected handCount for other players
                if(pre.handCount[p] == post.handCount[p]){
                    printf("cardEffect(village): PASS, player %d handCount unaffected after currentPlayer %d discard/draw \n", p, currentPlayer);
                    passed++;
                }
                else{
                    printf("cardEffect(village): FAIL, player %d handCount affected after currentPlayer %d discard/draw \n", p, currentPlayer);
                    failed++;
                }
                
                //Test for unaffected discardCount for other players
                if(pre.discardCount[p] == post.discardCount[p]){
                    printf("cardEffect(village): PASS, player %d discardCount unaffected after currentPlayer %d discard \n", p, currentPlayer);
                    passed++;
                }
                else{
                    printf("cardEffect(village): FAIL, player %d discardCount affected after currentPlayer %d discard \n", p, currentPlayer);
                    failed++;
                }
                
                //Test for unaffected deckCount for other players
                if(pre.deckCount[p] == post.deckCount[p]){
                    printf("cardEffect(village): PASS, player %d deckCount unaffected after currentPlayer %d draw \n", p, currentPlayer);
                    passed++;
                }
                else{
                    printf("cardEffect(village): FAIL, player %d deckCount affected after currentPlayer %d draw \n", p, currentPlayer);
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
    testCardEffect(village);
    return 0;
}