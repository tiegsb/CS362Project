#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


void testEmptyPile(struct  gameState* G){
    
    int player=G->whoseTurn;
    G->supplyCount[5]=0;
    int result = gainCard(5, G, 1, player);
       printf("Test 1) Testing that an empty pile returns error message.\n");
    printf("preconditions: pile 5 at supplyCount set to 0\n");
    printf("post conditions: function should return -1\n"); 
    printf("results: \n");
    printf("- Expected: -1  Actual: %d\n", result);
    printf("\n\n");

}
void testIllegalCard(struct  gameState* G){
     int player=G->whoseTurn;
    int result = gainCard(-3, G, 1, player);
    printf("Test 2a) Testing that a negative value illegal card returns error message.\n");
    printf("preconditions: function called with card -3 \n");
    printf("post conditions: function should return -1\n"); 
    printf("results: \n");
    printf("- Expected: -1  Actual: %d\n", result);
    printf("\n");
    result = gainCard(1000, G, 1, player);
    printf("Test 2b) Testing that a positive valued illegal card returns error message.\n");
    printf("preconditions: function called with card 1000 \n");
    printf("post conditions: function should return -1\n"); 
    printf("results: \n");
    printf("- Expected: -1  Actual: %d\n", result);
    printf("\n\n");
    
}


void testCardAddedToDeck(struct  gameState* G){
        
    int player=G->whoseTurn;
    int result = gainCard(7, G, 1, player);
    printf("Test 3) Testing that gained card is added to deck\n");
    printf("preconditions: call function with flag set to 1 \n");
    printf("post conditions: new card is in player's deck\n"); 
    printf("results: \n");
    printf("Top of Player's Deck\n");
    int deckCount= G->deckCount[player];
    printf("- Expected: 7  Actual: %d\n", G->deck[player][deckCount-1]);
    printf("\n\n");
}

void testCardAddedToHand(struct  gameState* G){
    int player=G->whoseTurn;
    int result = gainCard(7, G, 2, player);
    printf("Test 4) Testing that gained card is added to deck\n");
    printf("preconditions: call function with flag set to 2 \n");
    printf("post conditions: new card is in player's deck\n"); 
    printf("results: \n");
    printf("Top of Player's Hand\n");
    int handCount= G->handCount[player];
    printf("- Expected: 7  Actual: %d\n", G->hand[player][handCount-1]);
    printf("\n\n");
}

void testCardAddedToDiscard(struct  gameState* G){
     int player=G->whoseTurn;
    int result = gainCard(7, G, -1, player);
    printf("Test 5) Testing that gained card is added to discard\n");
    printf("preconditions: call function with flag set to -1 \n");
    printf("post conditions: new card is in player's discard pile\n"); 
    printf("results: \n");
    printf("Top of Player's Discard Pile\n");
    int discardCount= G->discardCount[player];
    printf("- Expected: 7  Actual: %d\n", G->discard[player][discardCount-1]);
    printf("\n\n");
}
void testRemovedFromSupply(struct  gameState* G){
     int player=G->whoseTurn;

    printf("Test 6) Testing that gained card is removed from supply pile\n");
    printf("preconditions: call function with card 7 \n");
    printf("post conditions: card 7's supply pile is one less\n"); 
    printf("results: \n");
    printf("(Supply Count before function call: %d)\n",G->supplyCount[7]);
    int result = gainCard(7, G, -1, player);
    printf("Supply Count post function call");
    printf("- Expected: 9  Actual: %d\n", G->supplyCount[7]);
    printf("\n\n");
}

void testHandScore(struct gameState *G){
   int player=G->whoseTurn;
    int i=0;
    G->hand[player][0]=0;
    G->hand[player][1]=1;
    G->hand[player][2]=2;
    G->hand[player][3]=3;    
    G->hand[player][4]=16;   
    G->hand[player][5]=10;   
    
    G->handCount[player]=6;
    G->discardCount[player]=0;
    G->deckCount[player]=0;
    // printHand(player,G);
    int result=scoreFor(player,G);
    
    printf("Test 1) Testing hand score\npreconditions: hand set to curse, estate, duchy, province, great_hall,gardens\npost conditions: none\n");
    printf("results: \n");
    printf("- Expected: 10    Actual:  %d \n", result);
    printDiscard(player,G);
    printDeck(player,G);
    printHand(player,G);
}

void testDeckScore(struct gameState *G){
   int player=G->whoseTurn;
    int i=0;
    G->deck[player][0]=0;
    G->deck[player][1]=1;
    G->deck[player][2]=2;
    G->deck[player][3]=3;    
    G->deck[player][4]=16;   
    G->deck[player][5]=10;   
    
    G->deckCount[player]=6;
    G->discardCount[player]=0;
    G->handCount[player]=0;
 //    printDeck(player,G);
    int result=scoreFor(player,G);
    printf("Test 3) Testing deck score\npreconditions: deck set to curse, estate, duchy, province, great_hall,gardens\n\thand and discard empty\npost conditions: none\n");
    printf("results: \n");   
   printf("- Expected: 10     Actual:  %d \n", result);
    printDiscard(player,G);
    printDeck(player,G);
    printHand(player,G);
    
}
void testDiscardScore(struct gameState *G){
   int player=G->whoseTurn;
    int i=0;
    G->discard[player][0]=0;
    G->discard[player][1]=1;
    G->discard[player][2]=2;
    G->discard[player][3]=3;    
    G->discard[player][4]=16;   
    G->discard[player][5]=10;   
    
    G->discardCount[player]=6;
    G->deckCount[player]=0;
    G->handCount[player]=0;
    // printDeck(player,G);
    int result=scoreFor(player,G);
    printf("Test 2) Testing discard score\npreconditions: deck set to curse, estate, duchy, province, great_hall,gardens\n\t\thand and deck empty\npost conditions: none\n");
    printf("results: \n");
    printf("- Expected: 10     Actual:  %d \n", result); 
    printDiscard(player,G);
    printDeck(player,G);
    printHand(player,G);
    
}

/*                      functions unit test 3               */
/** tests discard hand logic in endTurn **/
void testDiscardHand(struct gameState*G){  
    int numPlayers = 2;
    int n,m;
    int zero_count, one_count;
    int turn=0;
    printf("Test 1) Testing that the correct number of cards are discarded for each player\nand that the cards are found in the player's discard pile");
    printf("preconditions: 2 players, 6 turns, 5 cards in each hand, no cards purchased\n");
    printf("post conditions:  players hands are added to the discard pile until deck is empty,\n\t\tthe discard pile is empty if the deck is full minus the\n\t\t current player's hand.\n"); 
    
    for(n = 0; n < 3; n++){
        
        // for each player
        for(m=0; m < numPlayers; m++){
            printf("\nTURN %d\n", turn);
           int player=G->whoseTurn;
            if(turn == 0){
                zero_count=5;       //p0
                one_count=0;
            }
            if(turn == 1) 
            {
                zero_count=5;       //p1
                one_count=5;
            }
            if(turn == 2){
                zero_count=10;     //p0
                one_count=5;
            }
            if(turn == 3){
                zero_count= 0;      //p1 -p0 had to draw a new hand so discard pile was reused
                one_count=10;
            }
            if(turn == 4){
                zero_count=5;       //p0
                one_count=0;
            }
            if(turn == 5){
                zero_count=5;       //p1
                one_count=5;
            }
            printf("results:\n");
/*             printf("(Pre function call)\n");
            printHand(player,G);
            endTurn(G);
            printf("(Post function call)\nTop 5 cards of \n");
            int discardCount=G->discardCount[player];
            int h;
            printf("Player %d's discard pile: \n",m);
            printf("#  Card \n");
            for(h=discardCount; h > (discardCount-5); h-- ){
                printf("%d  ",h);            
                if(G->discard[player][h] == 1){
                    printf("Estate\n");
                }else{
                    printf("Copper\n");
                }

            }
            printf("\n"); */
            if(m==0){
                printf("Player 0's discard count...\n" );
                printf("- Expected: %d Actual: %d\n", zero_count,G->discardCount[m]);               
                printf("Player 1's discard count...\n");
                printf("- Expected: %d Actual: %d\n", one_count,G->discardCount[1]);

            }else{
                           
                printf("Player 1's discardCount\n");
                printf("- Expected: %d Actual: %d\n", one_count,G->discardCount[m]);            
                printf("Player 0's discardCount \n");
                printf("- Expected: %d Actual: %d\n", zero_count,G->discardCount[0]);
          
            }
            
            turn++;
        }      
    }
      printf("\n\n");
}

/** tests state variables that are reset by endTurn
**/
void testResetsValues(struct gameState* G){
   
  printf("Test 2) Testing that state varialbes are reset when endTurn is called.\n");
  printf("preconditions: variables outpostPlayed, phase, numActions, numBuys, playedCardCount and hand count\n\t\thave been set to abirtray values.\n");
  printf("post conditions: all variables are reset to initial values.\n");
  G->outpostPlayed = 5; // should be 0
  G->phase=1;             // should be 0
  G->numActions=5;   // should be 1
  G->numBuys = 2;  //should be 1
  G->playedCardCount = 4; // should be 0
  G->handCount[G->whoseTurn] = 9; // should be 0, then 5 post draw

  endTurn(G);
  printf("results:\n");
   printf("Outpost Played\n- Expected: 0 Actual: %d\n", G->outpostPlayed);
   assert(G->outpostPlayed == 0);
   printf("Phase\n- Expected: 0 Actual: %d\n", G->phase);
   printf("numActions\n- Expected: 1 Actual: %d\n", G->numActions);
   printf("numBuys\n- Expected: 1 Actual: %d\n", G->numBuys);
   printf("playedCardCount\n- Expected: 0 Actual: %d\n", G->playedCardCount);
   printf("handCount for current player %d\n- Expected: 5 Actual: %d\n", G->whoseTurn,G->handCount[G->whoseTurn]);
     printf("\n\n");
}
/* Tests that the function correctly switches between players*/
void testCurrentPlayer(struct gameState *G){
    
    G->whoseTurn=0;
   int i,m;
    printf("Test 3) Testing that Current Player is updated\n");
    printf("preconditions: 4 turns are executed\n");
    printf("post conditions: endTurn switches current player each time it is called\n");
    printf("results:\n");
    for( i= 0; i < 4; i++){
        printf("Ending Turn %d\n",i);
        endTurn(G);
        // test current player
            if(i % 2 != 0) {
                    m=0;
            }else{
                    m=1;
             }
    printf("- Expected Player: %d Actual Player: %d\n", m, G->whoseTurn);
 
  }
  printf("\n\n");
}
void testPlayedCards(struct gameState* G){
     int player=G->whoseTurn;
    int i,m;
    printf("Test 4) Testing that played cards return to discard pile\n");
    printf("preconditions: add a smithy card to played pile\n");
    printf("post conditions: smithy card should be moved to discard pile \n\n");
    printf("results:\n");
    
    G->playedCards[0]=13;
    G->playedCardCount++;
    endTurn(G);
    int found_smity=-1;
    for(m=0; m < G->discardCount[0];m++){
        
        if(G->discard[0][m] == 13){
            found_smity=0;
        }
        
    }
  
    printf("(if smithy was found in discard pile, expect 0) \n");
    printf("- Expected: 0 Actual: %d\n", found_smity);
 
 
  printf("\n\n"); 
}
/*************************  functions unit test 4 *************************/

void testZeroProvinces(struct gameState* G){

    printf("Test 1a) Tests if game ends when there are no provinces in the pile.\n");
    printf("preconditions: zero Province cards in pile\n");
    printf("preconditions: game should end (so return true 0)\n");    
    int result;
    G->supplyCount[province]=0;
    result=isGameOver(G);
    printf("results: \n-Expected: 1 Actual: %d\n\n", result );
    printf("Test 1b) Tests if game ends when there is one province in the pile.\n");    
     printf("preconditions: oneProvince cards in pile\n");
    printf("preconditions: game should not end (so return false 1)\n");    
    G->supplyCount[province]=1;
    result=isGameOver(G);
    printf("results:\n-Expected: 0 Actual: %d\n\n", result );
    
}

void testThreeZeroSupplyCount(struct gameState* G){
    
    printf("Test 2) Test if game ends when three piles are empty.\n");
    printf("preconditions: THREE card piles (curse, silver, duchy) are set to zero\n");
    printf("post-conditions: Game should end.\n");
    int result;
    G->supplyCount[curse]= 0;
    G->supplyCount[silver]= 0;
    G->supplyCount[duchy]=0;

    result=isGameOver(G);
    
    printf("results:\n-Expected: 1 Actual: %d\n\n", result );

    
}

void testAllKingdomCards(struct gameState* G){
    int result;
    printf("Test 3)\n THREE kingdom card piles are set to zero\n");
    printf("preconditions: THREE kingdom card piles (village, minion, cutpurse) are set to zero\n");
    printf("post-conditions: Game should end.\n");

    G->supplyCount[14]= 0; // village
    G->supplyCount[17]= 0; // Minion
    G->supplyCount[21]= 0; // cutpurse
    
    result=isGameOver(G);
    
    printf("results:\n-Expected: 1 Actual: %d\n\n", result );

    
}
  /*                FUNCTIONS  CARD TEST 1                   */
  
void testDrawThreeCards(struct gameState* G){

      int player;  
      player=G->whoseTurn;

       G->hand[player][0]=13;

      play_smithy(player,G,0);
     
   
       printf("Test 1a) Testing if player's hand has three additonal cards after playing smithy card.\n\npreconditions: Card count is 5, card in position 0 is Smithy\npost conditions: Card count is 7, three cards are drawn, Smithy is discarded\n");
       printf("results:\n- Expected: 7 Actual: %d\n\n", G->handCount[player]);
       printf("Test 1b)Testing if player's deck has the right number of cards after playing smithy card.\n\npreconditions: Deck count is 5\npost conditions: Deck should have 2 cards (-3 after Smithy called)\n");
       printf("results:\n- Expected: 2 Actual: %d\n\n", G->deckCount[player]);
       endTurn(G);
  }
  void testSmithyIsDiscarded(struct gameState* G){

      int player;  
      player=G->whoseTurn;
      G->hand[player][0]=13;
      G->supplyCount[13]--;
      play_smithy(player,G,0);
      printf("Test 2a) Tests that the smithy card is discarded after use\npreconditions: Card count is 5, card in position 0 is Smithy\npost conditions: Card count is 7, three cards are drawn, Smithy is discarded\n");
      printf("results:\n- Expected: 1 Actual: %d\n\n", G->discardCount[player]);
      printHand(player,G);
        printf("(Check smithy is in played cards pile)\n");
        printf("- Expected: 13 Actual: %d\n\n", G->playedCards[0]);
      printPlayed(player, G);
      endTurn(G);
  }
/*                               FUNCTIONS CARD TEST 1                              */
void testDeckShuffle(struct gameState* G){
    
    int deckCount;
    int player= G->whoseTurn;
    int empty_deck[MAX_DECK];
    int i;
   
    for (i = 0; i < MAX_DECK; i++)
    { 
        empty_deck[i]="";
    }
    int j;
    
        G->discardCount[player]=G->deckCount[player];
    for(j=0;j<G->discardCount[player]; j++){
       
        G->discard[player][j]= j;
    }



    printf("Test 1) Testing when deck is empty, discard pile is shuffled, then added to deck\npreconditions: deck is empty, discard is full of unique cards (to check shuffle)\npostconditions: deck has cards\n");
    deckCount=G->deckCount[player]; //deck count stored
    G->deckCount[player]=0;                 // deck count in state set to zero
    G->hand[player][0]=7;                       // adventurer card put in player's hand at pos zero
    memcpy(G->deck[player], empty_deck, sizeof(int) * deckCount);   // player's deck is emptied
    printf("\n(before function call, to compare with deck cards post function call)\n");   
   printDiscard(player,G);                     

    printf("\n(deckCount before calling play_adventurer: %d)\n",G->deckCount[player]);
    printf("results: \n");
    play_adventurer(player,G,0);           //takes player, game ptr, and hand position of adventurer card
    printf("(deck count after calling play_adventurer)\n - Expected: at least 1 Actual: %d\n\n", G->deckCount[player]);
    
    printf("(Visual check to see that new cards in deck are shuffled)\n");
    printDeck(player,G);
    
    
         
}

void testDrawTreasure(struct gameState* G){
    int player=G->whoseTurn;
    printf("Test 2)Testing that two treasure cards are drawn\npreconditions: none \npostconditions: 2 treasure cards drawn\n");
    printf("\nresults:\n(Number of Cards in Hand after discard adventurer -1, add treasures +2)\n- Expected: 6 Actual: %d\n\n", G->handCount[player]);
    //state->hand[currentPlayer][state->handCount[currentPlayer]-1]
}
/*                  FUNCTIONS CARD TEST 3                           */
void testEffectsOtherPlayers(struct gameState* game){
    
    int player=game->whoseTurn;
    printf("Test 1) Test all players other than 0 are effected by cut purse\n");
    printf("preconditions: 4 players, all cards set to copper for all players\n\t all deck cards set to silver\n");
    printf("postconditions: other players should have one less copper than they started with\n\n");
    int i,j;
    //set hand cards to copper
    for(i=0; i < 5; i++){        
        game->hand[0][i]=4;
        game->hand[1][i]=4;
        game->hand[2][i]=4;
        game->hand[3][i]=4;
    }
    //set deck cards to silver
     for(j=0; j < 10; j++){     
        
       game->deck[0][j]=5;
        game->deck[1][j]=5;
        game->deck[2][j]=5;
        game->deck[3][j]=5;
 
    }
    //set p0's card at pos 0 to cutpurse
    game->hand[0][0]=21;
    int x;
    for(x=0; x<4 ; x++){
        game->handCount[x]=5;
        game->deckCount[x]=5;
    }

    int result=play_cutpurse(0,game,0);

    int copper_count=0;
    int k;
    for( k=0 ; k < 4;k++){
        
        if(game->playedCards[k]==4){
            copper_count++;
        }
        
    }
    printf("results: \n(number of coppers in played cards pile)\n");
    printf("- Expected: 3 Actual: %d\n",copper_count); 

    printf("\n\n");
}
/*                                  FUNCTIONS CARD TEST 4                                     */
  void testZeroTreasureMap(struct gameState *G){
     
     int player=G->whoseTurn;
     
    int result=play_treasure_map(player,G,0);
        printf("Test 4) Test if function returns -1 if there are no treasure maps in hand.\n");
        printf("preconditions: hand at 0 is treasure map card.\n");
        printf("post conditions: Function should return with -1.\n");
        printf("Expected: -1, Actual: %d\n\n", result);  
     
 }
 
 void testOneTreasureMap(struct gameState *G){
     
     int player=G->whoseTurn;
     G->hand[player][0]= 26;
     
    int result=play_treasure_map(player,G,0);
        printf("Test 3) Test if function returns -1 if only one treasure map in hand.\n");
        printf("preconditions: hand at 0 is treasure map card.\n");
        printf("post conditions: Function should return with -1.\n");
        printf("Expected: -1, Actual: %d\n\n", result);  
     
 }
 
 void testBothTreasuresDiscarded(struct gameState *G){
     
     int m;
     for(m=0; m < 4; m++){
     //   printf("TURN %d\n", m);
       int player = G->whoseTurn; 
       printf("PLAYER %d\n", player);
        printf("Test 2) Testing discard count.\n");
        printf("preconditions: hand at 1, and at 3 are set to treasure cards.\n");
        printf("post conditions: Discard count should be > 0.\n");
        int firstCard=G->hand[player][1];
        int secondCard=G->hand[player][3];
        
        // putting removed cards back
        int d;
        for(d=0; d < treasure_map+1; d++){
            if(G->supplyCount[d] == firstCard || G->supplyCount[d] == secondCard){
                G->supplyCount[d]++;             
            }
        }
        //adding two treasure cards from supply
        G->supplyCount[26]=G->supplyCount[26]-2;
        G->hand[player][1]= 26;
        G->hand[player][3]= 26;
        
        
        int result=play_treasure_map(player,G,1);
        int discardCount=G->discardCount[player]; 
        printf("Discard Count... Expected: at least 2, Actual: %d\n\n", discardCount);
           
        if(discardCount > 0){
            printf("Test 2a) Testing both treasure cards are discarded.\n");
            printf("preconditions: State from test 2 is preserved.\n");
            printf("post conditions: Top two cards of discard pile are Treasure Map cards.\n\n");
            
            printf("Top of discard pile...\n");
            int c;
            int map_count=0;
        
           for(c=discardCount; c > 0; c--){
                 printf("Card at Position %d: %d\n",c-1, G->discard[player][(c-1)]);
                 if(G->discard[player][c-1] == 26){
                     map_count++;
                 }
             }
             printf("\n");
             printf("Number of Treasure Maps, Expected: 2   Actual: %d\n", map_count);
      }else{
          printf("Discard count too low to execute Test 2a...");
      }
        endTurn(G);
        printf("\n\n");
     }
 }
 void testGainFourGold(struct gameState* G){
   
        int m;
        for(m=0; m<4; m++){
            printf("PLAYER %d\n",m);
            int player = G->whoseTurn; 
        printf("Test 1) Testing player gains 4 Golds when two treasure cards are present their hand.\n");
        printf("preconditions: hand at 0, and at 4 are set to treasure cards.\n");
        printf("post conditions: User gains 4 Golds.\n");
            G->hand[player][0]= 26;
            G->hand[player][4]= 26;

            int result=play_treasure_map(player,G,0);
            printf("-Return Value...Expected: 1 Actual: %d\n\n", result);

            if(result == 1){
                printf("Test 1a) Testing 4 Golds are sent to top of deck.\n");
                printf("preconditions: hand at 0, and at 4 are set to treasure cards. No golds in deck.\n");
                printf("post conditions: Top of player deck should contain 4 gold cards.\n");

                int k;
                printf("Player %d Deck\n",m);
                
                for(k=G->deckCount[player] ; k > 0; k--){ 
                    if(k > G->deckCount[player]-4){
                        printf("%d  Expected: 6 (Gold) Actual: %d\n", k,G->deck[player][k]);
                    }else{
                        printf("%d  Actual: %d\n", k,G->deck[player][k]);
                    }
                } 
                printf("\n\n");
            endTurn(G);
            }
        
    }
     
 }
 /************************************* MAIN ********************************************/
int main(){
  struct gameState G;
          /*                       UNIT TEST 1               */
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
           sea_hag, tribute, smithy};
  
  printf ("\t\t\t\t\tStarting Unit Test 1 on gainCard...\n\n");
  initializeGame(2, k, 1000, &G);
  testEmptyPile(&G);
  memset(&G, 23, sizeof(struct gameState));   
  int r = initializeGame(2, k,1000 , &G);
  testIllegalCard(&G);
  memset(&G, 23, sizeof(struct gameState));   
  r = initializeGame(2, k,1000 , &G);
 testCardAddedToDeck(&G);
   memset(&G, 23, sizeof(struct gameState));   
  r = initializeGame(2, k,1000 , &G);
 testCardAddedToHand(&G);
  memset(&G, 23, sizeof(struct gameState));   
  r = initializeGame(2, k,1000 , &G);
 testCardAddedToDiscard(&G);
   memset(&G, 23, sizeof(struct gameState));   
  r = initializeGame(2, k,1000 , &G);
 testRemovedFromSupply(&G);

   printf ("\t\t\t\t\tFINISHED Unit Tests on gainCard...\n\n");
   
   
   /*                       UNIT TEST 2                 */
    int j[10] = {adventurer, gardens, great_hall, village, minion, mine, cutpurse, 
           sea_hag, tribute, smithy};
  
  printf ("\t\t\t\t\tStarting Unit Test 2 for Function scoreFor...\n\n");
  initializeGame(2, j, 1000, &G);
  testHandScore(&G);
  memset(&G, 23, sizeof(struct gameState));   
   initializeGame(2, j,1000 , &G);
    testDiscardScore(&G);
  memset(&G, 23, sizeof(struct gameState));   
  initializeGame(2, j,1000 , &G);
    testDeckScore(&G);
      printf ("\t\t\t\t\tFINISHED tests for function scoreFor...\n\n");
      
  /*                       UNIT TEST 3                 */
    int l[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
           sea_hag, tribute, smithy};
  
  printf ("\t\t\t\t\tStarting Unit Test 3 for function endTurn...\n\n");
  initializeGame(2, l, 1000, &G);

  testDiscardHand(&G);
  testResetsValues(&G);
  testCurrentPlayer(&G);
 memset(&G, 23, sizeof(struct gameState));   
 initializeGame(2, l,1000 , &G);
 testPlayedCards(&G);
 printf ("\t\t\t\t\tFINISHED tests for function endTurn...\n\n");
        /*                       UNIT TEST 4                 */
  int m[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
           sea_hag, tribute, smithy};
  
  printf ("\t\t\t\t\tStarting Unit Test 4 for isGameOver()...\n\n");
  initializeGame(2, m, 1000, &G);
  testZeroProvinces(&G);
  memset(&G, 23, sizeof(struct gameState));   
  r = initializeGame(2, m,1000 , &G);
  testThreeZeroSupplyCount(&G);
  memset(&G, 23, sizeof(struct gameState));   
  r = initializeGame(2, m,1000 , &G);
  testAllKingdomCards(&G);
  printf ("\t\t\t\t\tFINISHED tests for isGameOver function...\n\n");
  
  /*                            CARD TEST 1                         */
    int ct1k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
    sea_hag, tribute, smithy};
   printf ("\t\t\t\t\tStarting Card Test 1for function play_smithy...\n\n");
   initializeGame(2, ct1k, 1000, &G);
   testDrawThreeCards(&G);
   testSmithyIsDiscarded(&G);
   printf ("\t\t\t\t\tFINISHED Unit Tests for function play_smithy...\n\n");
     /*                            CARD TEST 2                         */
   int ct2k[10] = {adventurer, gardens, embargo, village, minion, mine,cutpurse,sea_hag, tribute, smithy};
  printf ("\t\t\t\t\tStarting Unit tests for play_adventurer.\n\n");
  initializeGame(2, ct2k, 1000, &G);
  testDeckShuffle(&G);
  memset(&G, 23, sizeof(struct gameState));   
  initializeGame(2, ct2k,1000 , &G);
  testDrawTreasure(&G);  
  printf ("\t\t\t\t\tFINISHED Unit tests for play_adventurer...\n\n");
  /*                            CARD TEST 3                                 */
 int ct3k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse, 
           sea_hag, tribute, smithy };
  printf ("\t\t\t\t\tStarting Unit Tests for cutpurse.\n\n");
  initializeGame(4, ct3k, 1000, &G);
   testEffectsOtherPlayers(&G);
   memset(&G, 23, sizeof(struct gameState));   // clear the game state (from template.c)
   initializeGame(2, ct3k,1000 , &G);              // initialize a new game (from template.c)
   memset(&G, 23, sizeof(struct gameState));   // clear the game state (from template.c)
   initializeGame(2, ct3k,1000 , &G);              // initialize a new game (from template.c)
   printf ("\t\t\t\t\tFINISHED Card Unit Test 3 for cutpurse...\n\n");
  /*                        CARD TEST 4                            */
    int ct4k[10] = { adventurer, treasure_map, embargo, village, minion, mine, cutpurse, 
           sea_hag, tribute, smithy }; 
  printf ("\t\t\t\t\tStarting Unit Tests for card treasure map...\n\n");
  initializeGame(4, ct4k, 1000, &G);
   testGainFourGold(&G);
   memset(&G, 23, sizeof(struct gameState));   // clear the game state (from template.c)
   initializeGame(2, ct4k,1000 , &G);              // initialize a new game (from template.c)
    testBothTreasuresDiscarded(&G);
   memset(&G, 23, sizeof(struct gameState));   // clear the game state (from template.c)
   initializeGame(4, ct4k,1000 , &G);              // initialize a new game (from template.c)
   testOneTreasureMap(&G);
   memset(&G, 23, sizeof(struct gameState));   // clear the game state (from template.c)
   initializeGame(4, ct4k,1000 , &G);              // initialize a new game (from template.c) 
 testZeroTreasureMap(&G);
    printf ("\t\t\t\t\tFINISHED Card Test 4 for treasure map...\n\n");
 printf("\t\t\t\t\tGcov Results");
   return 0;
}



