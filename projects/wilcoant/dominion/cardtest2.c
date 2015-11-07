/* 
Anthony Wilcox
CS362 
Fall 2015
-----------------------------------------------------------------------
 * card test for adventurer -----------------------------------------------------------------------
 */
//used cardsolution from assignment3 solution CS362 Fall2015 for 
//improvement to base cardtest, then generated random tests from 
//there
//modified some initialation variables to test boundaries more completely
 
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {
    int i, j, m; //loop counters 
    int handpos = 0; 
    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0, bonus = 0; //dummy choices to pass to cardeffect, not used for this card 
    int temphand[MAX_HAND];//var to pass to play_adventurer
    int seed = 1000;
    int numPlayer = 2;   //add for loop condition to iterate up to 4
    int p, r, handCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G, testG;
    
    int player;
    int card, drawncard;
    int tcoins = 0, bhandcoins = 0, ahandcoins = 0; //num coin cards to pass to play_adventurer
    //int maxHandCount = 5;  //number of cards in each player's hand
    int val = 0, bhandval = 0, ahandval = 0; //val of coins in deck, hand in G, and hand in testG after fn call 
    
    initializeGame(numPlayer, k, seed, &G); //init game 
    
    printf ("TESTING adventurer():\n");
    
    //copy state of game to test state to preserve original game state 
    memcpy(&testG, &G, sizeof(struct gameState));
    for(j = 0; j < numPlayer; j++){
        for(i = G.deckCount[j]; i > 0; i--){
            if(G.deck[j][i] == copper || G.deck[j][i] == silver|| G.deck[j][i] == gold)
            {   //add to val for each coin found 
                if(G.deck[j][i]== copper){
                    val = val + 1;
                }
                if(G.deck[j][i]== silver){
                    val = val + 2;
                }
                if(G.deck[j][i]== gold){
                    val = val + 3;
                }
                tcoins++; //find all the treasure cards in the deck  
            }
            else{
                drawncard++; //add to drawn cards that aren't treasure cards
            }
            if(tcoins == 2 || i == 0) //if you found two treasure or got to the bottom of the deck
            {
               
                cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
                //check that the deck count was properly incremented
                //
                printf("deck count = %d, expected = %d\n", testG.deckCount[j], i); //i is where you are in the deck 
                
                //check that the discard pile was properly changed 
                printf("discard count = %d, expected = %d\n", testG.discardCount[j], G.discardCount[j] + (i - tcoins) );
                
                //test that number of coin cards was properly added 
                for(m = 0; m < G.handCount[j]; m++)
                {//count treasure cards in hand pre card play 
                     if(G.hand[j][m] == copper || G.hand[j][m] == silver|| G.hand[j][m] == gold){
                        bhandcoins++; //count treasure cards in player's hand 
                        if(G.hand[j][m]== copper){
                        bhandval = bhandval + 1;
                        }
                        if(G.hand[j][m]== silver){
                            bhandval = bhandval + 2;
                        }
                        if(G.hand[j][m]== gold){
                            bhandval = bhandval + 3;
                        }
                    }
                }
                //test that value of coins added was correct 
                for(m = 0; m < testG.handCount[j]; m++)
                {
                    if(testG.hand[j][m] == copper || testG.hand[j][m] == silver|| testG.hand[j][m] == gold){
                        ahandcoins++; //count treasure cards in player's hand 
                    }
                    
                    if(testG.hand[j][m]== copper){
                        ahandval = ahandval + 1;
                    }
                    if(testG.hand[j][m]== silver){
                        ahandval = ahandval + 2;
                    }
                    if(testG.hand[j][m]== gold){
                        ahandval = ahandval + 3;
                    }
                    
                }
                printf("treasure cards = %d, expected = %d\n", ahandcoins, tcoins);
                printf("value of cards = %d, expected = %d\n", ahandval, val + bhandval);  
                bhandcoins = 0; //reset pregame hand count for other player 
                ahandcoins = 0; //reset handcount 
                ahandval = 0; //reset handval 
                bhandval = 0;
                i = 0; //stop for loop to prevent further coin accumulation
                
                
                
                
            }
            
        }
        val = 0;
        tcoins = 0;
        drawncard = 0; //reset counters to zero after going through each player's deck 
    }
        
  
    

    return 0;
}
