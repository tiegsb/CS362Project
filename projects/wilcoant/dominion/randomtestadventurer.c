/* 
Anthony Wilcox
CS362 
Fall 2015
Assignment 4 
-----------------------------------------------------------------------
 * random card test for adventurer -----------------------------------------------------------------------
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
#include <time.h>
#include <stdlib.h>

#define MAX_RUN 1000 //number of times to run while loop 

int main() {
    int i, j, m; //loop counters 
    int handpos = 0; 
    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0, bonus = 0; //dummy choices to pass to cardeffect, not used for this card 
    
    int seed = 1000;
    int numPlayer = 2;   //add for loop condition to iterate up to 4
    int allcards[20] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall, minion, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map};
    int tempcard; //temp cards to shuffle 
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G, testG;
    int drawncard;
    int tcoins = 0, bhandcoins = 0, ahandcoins = 0; //num coin cards to pass to play_adventurer
    //int maxHandCount = 5;  //number of cards in each player's hand
    int val = 0, bhandval = 0, ahandval = 0; //val of coins in deck, hand in G, and hand in testG after fn call
    time_t t;  //rand seed
    srand((unsigned) time(&t)); //seed rand with time_t
   
    /*shuffle array of possible room names*/
    int adv_count = 0; //counter for adventurer cards first 10 indices 
    int n = MAX_RUN; //while loop control
    int r; //index tracker for adventurer 
    while( n > 0)
    {    
        j = 0; //reset j
        r = 0;  //reset r    
        for(i = 0; i < 20; i++)
        {//shuffle array of possible cards 
            j = (rand() % 19) + 1; //so that it can't equal 0 and have i and j be equal 
            tempcard = allcards[i];
            allcards[i] = allcards[j]; //copy rand inexed into i index 
            allcards[j] = tempcard; //tempcard now into j index 
            if(i <= 9 && allcards[i] == adventurer)
            {//find out if adventurer got put into the fist ten indices of the deck at random 
                adv_count++; 
                r = i; //get index where it was stored 
            }
        }
        for(i = 0; i < 10; i++)
        {//put first ten shuffled cards in k
            k[i] = allcards[i]; 
        }
        
        if(adv_count == 0)
        {//if adventurer wasn't one of the first 10 cards after shuffle, put it there 
            r = (rand() % 9) + 1; //get a random index in the card array 
            k[r] = adventurer; //put adventurer in k
        }
        
        /*get random number of players to seed game with*/
        numPlayer = (rand() % 3) + 2; //force to be 2, 3 or 4
        
        /*init game with random deck and players*/
        initializeGame(numPlayer, k, seed, &G); //init game 
        
        /*now that game is initialized, force input random treasure cards
        at random spots in the deck prior to memcopy for state 
        preservation*/
        int num_randcards = (rand() % 6);//putting between 0 and 5 treasure cards in each player's deck 
        int randindex; //index to put cards in 
        int randval; //type of random card to be put in deck 

        printf ("----------------------TESTING adventurer()--------------\n");
        printf ("Additional random cards placed in deck: %d\n", num_randcards);
        printf ("Random number of players: %d\n", numPlayer);
        printf ("Adventurer in k at index: %d\n", r); 
        //testchange
        for(i = 0; i < numPlayer; i++)
        {
            printf ("------Player %d:\n", i + 1);
            for(j = 0; j < num_randcards; j++)
            {//go through each players deck and put random treasure cards in 
                randval = rand() % 3; //0, 1 or 2 (copper, silver, gold)
                randindex = rand() % (G.deckCount[i] + 1); //this players deckcount, and index 0 to max 
                printf ("placed at index: %d\n", randindex);
                if(randval == 0)
                {
                    G.deck[i][randindex] = copper; //put copper in that players deck at that location 
                    printf ("Value: 1\n");
                }
                if(randval == 1)
                {
                    G.deck[i][randindex] = silver; //put copper in that players deck at that location 
                    printf("Value: 2\n");
                }
                if( randval == 2)
                {
                    G.deck[i][randindex] = gold; //put copper in that players deck at that location 
                    printf ("Value: 3\n");
                }
            }
        }
        
        
        /*display random variables here*/
        printf ("TESTING adventurer()\n");
        
        //copy state of game to test state to preserve original game state 
        memcpy(&testG, &G, sizeof(struct gameState));
        for(j = 0; j < numPlayer; j++){
            printf ("----------Player %d:\n", j +1);
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
                    printf("TEST 1: Deck count after card played:\n");
                    
                    printf("deck count = %d, expected = %d\n\n", testG.deckCount[j], i); //i is where you are in the deck 
                    
                    //check that the discard pile was properly changed 
                    printf("TEST 2: Discard count after card played:\n");
                    printf("discard count = %d, expected = %d\n\n", testG.discardCount[j], G.discardCount[j] + (i - tcoins) );
                    
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
                    printf("TEST 3: Number of treasure coins after play:\n");
                    printf("treasure cards = %d, expected = %d\n\n", ahandcoins, tcoins + bhandcoins);
                    printf("TEST 4: Value of cards in hand:\n");
                    printf("value of cards = %d, expected = %d\n\n", ahandval, val + bhandval);  
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
    n--; //loop control    
    }   //exit while 
    return 0;
}
