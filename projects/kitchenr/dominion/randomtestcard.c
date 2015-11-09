#include "dominion.h"
#include "dominion.c"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>




/*********************************************************************************
 * 
 * 
 * 
 * 			Random testing for the Mine card
 * 			Ryan Kitchen
 * 
 * 
 * 			Tests mine on random input and choice cards
 * 
 * 			Verifies that the input card is a valid coin
 * 			Verifies output card is a valid coin
 * 			Verifies there are availiable cards to buy
 * 			Verifies that the cost is less than card cost + 3
 * 			Verifies that the card in hand is replaced by output
 * 
 * 
 ********************************************************************************/




int main(){
    srand(clock());
    struct gameState *state=newGame();
    for(int i=0;i<4;i++) state->hand[0][i]=curse+rand()%treasure_map;
    state->discard[0][0]=-1;
    
    state->supplyCount[copper]=rand()%4;
    state->supplyCount[silver]=rand()%4;
    state->supplyCount[gold]=rand()%4;
    
    for(int i=gold+1;i<treasure_map;i++)state->supplyCount[i]=1;	
    
    /// always going to pick card 0;
    
    int inputcard = state->hand[0][0];
    int outputcard = curse+rand()%treasure_map;
    printf("Input card: %2d Chosen Output: %2d ",inputcard,outputcard);
    int inputshouldfail=0;
    int outputshouldfail=0;
    if(state->supplyCount[outputcard]<1){
      printf("Output supply depleted! ");
      outputshouldfail=1;
    }
    if(inputcard<copper || inputcard>gold) inputshouldfail=1;
    if(outputcard<copper || outputcard>gold || (outputcard == gold && inputcard==copper)) outputshouldfail=1;
    printf("Input should %s, Output should %s ", (inputshouldfail)?"fail":"pass", (outputshouldfail)?"fail":"pass");
    int results=cardEffect(mine,0,outputcard,-1,state,4,0);
    printf("Results:%s",(results)?"fail":"pass");
    if(results != 0){
      if(!(inputshouldfail || outputshouldfail)) printf(" INVALID: should have passed!\n");
      else printf(" VALID: failed\n");
      return 0;
    }
    if(inputshouldfail || outputshouldfail){
      printf(" INVALID: should have failed!\n");
      return 0;
    }
    if(state->hand[0][0]!=outputcard){
      printf(" INVALID: card not changed\n");
      return 0;
    }
    if(state->discard[0][0]==inputcard){
      printf(" INVALID: input was discarded instead of trashed\n");
      return 0;
    }
    if(state->handCount[0]==5){
      printf(" INVALID: card is still in hand\n");
      return 0;
    }
    printf(" VALID\n");
    return 0;
}