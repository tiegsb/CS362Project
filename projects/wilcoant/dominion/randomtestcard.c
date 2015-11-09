/* 
Anthony Wilcox
CS362 
Fall 2015
Assignment 4
-----------------------------------------------------------------------
 * random card test for smithy
 ----------------------------------------------
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
    int i, j, m, p; //loop counters 
    int handpos = 0; 
    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0, bonus = 0; //dummy choices to pass to cardeffect, not used for this card 
    
    int seed = 1000;
    int numPlayer = 2;   //add for loop condition to iterate up to 4
    int allcards[20] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall, minion, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map};
               /*use rand_cards to grab a card form at random index 
               to put onto the top of the deck*/
    int rand_cards[26] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall, minion, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map, copper, silver, gold, estate, duchy, province};
    int tempcard; //temp cards to shuffle 
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G, testG;
    int tcards = 0, bhandcards = 0, ahandcards = 0; //num coin cards to pass to play_adventurer
    //int maxHandCount = 5;  //number of cards in each player's hand
    int val[3]; //array of added cards 
    int bhandval = 0, ahandval = 0; //val of coins in deck, hand in G, and hand in testG after fn call
    time_t t;  //rand seed
    srand((unsigned) time(&t)); //seed rand with time_t
   
    /*shuffle array of possible room names*/
    int smith_count = 0; //counter for adventurer cards first 10 indices 
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
            if(i <= 9 && allcards[i] == smithy)
            {//find out if adventurer got put into the fist ten indices of the deck at random 
                smith_count++; 
                r = i; //get index where it was stored 
            }
        }
        for(i = 0; i < 10; i++)
        {//put first ten shuffled cards in k
            k[i] = allcards[i]; 
        }
        
        if(smith_count == 0)
        {//if adventurer wasn't one of the first 10 cards after shuffle, put it there 
            r = (rand() % 9) + 1; //get a random index in the card array 
            k[r] = smithy; //put adventurer in k
        }
        
        /*get random number of players to seed game with*/
        numPlayer = (rand() % 3) + 2; //force to be 2, 3 or 4
        
        /*init game with random deck and players*/
        initializeGame(numPlayer, k, seed, &G); //init game 
        
        /*now that game is initialized, force input random treasure cards
        at random spots in the deck prior to memcopy for state 
        preservation*/
        int num_randcards = 3;//putting 3 random cards on top of the deck  
        int randval; //type of random card to be put in deck 
        printf ("----------------------TESTING smithy()--------------\n");
        printf ("Additional random cards placed in deck: %d\n", num_randcards);
        printf ("Random number of players: %d\n", numPlayer);
        printf ("Adventurer in k at index: %d\n", r); 
        
        for(i = 0; i < numPlayer; i++)
        {
            printf ("------Player %d:\n", i + 1);
            for(j = 0; j < num_randcards; j++)
            {//go through each players deck and put random cards in 
                randval = rand() % 26; //get random index 
                printf("Random card %d is: %d\n", j + 1, rand_cards[randval]);
                G.deck[i][G.deckCount[i] - (j + 1)] = rand_cards[randval]; 
                /*has to be j+ 1 becausethe deck is 0 indexed so
               deckCount val iteself is one off so j = 0 in this case
               we really need to be 1 in order to put it on the top of
               the deck*/ 
                G.deckCount[i]++; //increase deckcount for each card you put in 
                val[i] += rand_cards[randval]; //add up enum vals of cards put in deck 
            }
            printf("val i is: %d\n", val[i]);
        }
        
        
        /*display random variables here*/
        printf ("TESTING smithy()\n");
        
        //copy state of game to test state to preserve original game state 
        memcpy(&testG, &G, sizeof(struct gameState));
        for(j = 0; j < numPlayer; j++)
        {
             printf ("----------Player %d:\n", j +1); 
             cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);
             //check that the deck count was properly incremented
             //
             printf("TEST 1: Deck count after card played:\n");
             /*three cards should be gone*/
             printf("deck count = %d, expected = %d\n\n", testG.deckCount[j], G.deckCount[j] - 3); 
             
             //test that number of cards in hand was properly updated
             bhandcards = G.handCount[j]; //handcount before draw
             for(m = 0; m < G.handCount[j]; m++)
             {//count treasure cards in hand pre card play 
                 bhandval += G.hand[j][m]; //count total of enum values of cards in player's hand    
             }
             //test that value of coins added was correct 
             ahandcards = testG.handCount[j]; //handcount after draw
             for(m = 0; m < testG.handCount[j]; m++)
             {
                 ahandval += testG.hand[j][m]; //hand val with drawn cards 
             }
             printf("TEST 2: Deck player hand count:\n");
             /*three cards should be gone*/
             printf("hand count = %d, expected = %d\n\n", testG.handCount[j], G.handCount[j] + 3); //should have three more cards  
             printf("TEST 3:  \n");
             for(p = 0; p < numPlayer; p++)
             {/*check other player's hands*/
                 if(p != j)
                 {
                     printf("Other player's hands: \n");
                     printf("Player %d hand count: %d expected: %d\n", p + 1, testG.handCount[p], G.handCount[p]);
                 }
             }//change
             /*get value of sum of enumerated values from hand before
             and after cards are played*/
             printf("\nTEST 4: Card sum(correct cards added to hand):\n");
             printf("Card sum = %d, expected = %d\n\n", ahandval, val[j] + bhandval);//j is index of the cards added in val to that player's deck 
            
             bhandcards = 0; //reset pregame hand count for other player 
             ahandcards = 0; //reset handcount 
             ahandval = 0; //reset handval 
             bhandval = 0;
             i = 0; //stop for loop to prevent further coin accumulation
             tcards = 0;
             val[j] = 0; //reset that index to 0
            
         } 
        
        
    n--; //loop control    
    }   //exit while 
    return 0;
}
