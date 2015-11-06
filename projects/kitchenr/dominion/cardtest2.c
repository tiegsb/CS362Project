#include "dominion.h"



/*
 * 
 *  Unit testing for Adventurer
 * 
 * 
 */



int main(){
   struct gameState *state=newGame();
   
   state->deck[0][0] = curse;
   state->deck[0][1] = curse;
   state->deck[0][2] = curse;
   state->deck[0][3] = smithy;
   state->deck[0][4] = gold;
   state->deck[0][5] = curse;
   state->deck[0][6] = curse;
   state->deck[0][7] = silver;
   state->deck[0][8] = curse;
   state->deck[0][9] = curse;
   state->deckCount[0]=10;

   state->discardCount[0]=0;
   state->handCount[0] = 0;

   printf("Handcount = 0, discard pile is empty\n");
   adventurerEffect(0,state);
   printf("Handcount is 2? %s\n",(state->handCount[0]==2)?"YES":"NO");
   printf("Hand cards are gold and silver? %s\n",(state->hand[0][0]==silver && state->hand[0][1]==gold)?"YES":"NO");
   printf("%d %d %d\n",state->hand[0][0],state->hand[0][1],state->hand[0][2]);
   printf("Discard pile has 4 cards? %d %s\n",state->discardCount[0],(state->discardCount[0]==4)?"YES":"NO");
   
   
   printf("Trying adventurer on a deck with no money:\n");
   adventurerEffect(0,state);
   printf("Handcount = 2? %s\n",(state->handCount[0]==2)?"YES":"NO");
   printf("Deck empty? %s\n",(state->deckCount[0]==0)?"YES":"NO");
   

   return 0;
   
}
   