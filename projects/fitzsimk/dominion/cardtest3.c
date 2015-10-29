#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

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

    int y;

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
/*                      MAIN                    */

int main () {
  struct gameState G;
  int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse, 
           sea_hag, tribute, smithy };
 
  printf ("Starting UnitTests for cutpurse.\n\n");
  initializeGame(4, k, 1000, &G);


   testEffectsOtherPlayers(&G);
  
   memset(&G, 23, sizeof(struct gameState));   // clear the game state (from template.c)
   int r = initializeGame(2, k,1000 , &G);              // initialize a new game (from template.c)

   memset(&G, 23, sizeof(struct gameState));   // clear the game state (from template.c)
   r = initializeGame(2, k,1000 , &G);              // initialize a new game (from template.c)

      printf ("FINISHED UnitTests for cutpurse...\n\n");


  

  return 0;
}