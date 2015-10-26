#include "dominion.h"

/*
 * 
 * Council.. should draw 4 cards and 1 for everyone else
 * 
 */



int main(){
     struct gameState *state=newGame();
     int *kc = kingdomCards(adventurer,council_room,feast,gardens,mine,remodel,smithy,village,baron,great_hall);
     int results = initializeGame(4, kc,1,state);
     
     
     printf("Playing council room\n");
     councilEffect(0,state);
     printf("Hand count 9? %d %s\n",state->handCount[0],(state->handCount[0]==9)?"YES":"NO");
     printf("Other hand counts increased by 1? %s\n",(state->handCount[1]==1 && state->handCount[2]==1)?"YES":"NO");
     return 0;
}
