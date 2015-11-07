#include "dominion.h"



/*
 * 
 *  Unit testing for Smithy
 * 
 * 
 */



int main(){
   struct gameState *state=newGame();
   int *kc = kingdomCards(adventurer,council_room,feast,gardens,mine,remodel,smithy,village,baron,great_hall);
   initializeGame(2,kc,1,state);
   
   printf("Drew hand. Handcount is 5, Deckcount is 5\n");
   printf("Playing smithy\n");
   
   smithyEffect(0,state);
   
   printf("Handcount is now 8? %d %s\n",state->handCount[0],(state->handCount[0]==8)?"YES":"NO");
   printf("Deck count is now 2? %d %s\n",state->deckCount[0],(state->deckCount[0]==2)?"YES":"NO");
   printf("Playing smithy again\n");
   smithyEffect(0,state);
   
   printf("Handcount is now 10? %d %s\n",state->handCount[0],(state->handCount[0]==10)?"YES":"NO");
   printf("Deck count is now 0? %d %s\n",state->deckCount[0],(state->deckCount[0]==0)?"YES":"NO");
   
   return 0;
   
}
   