/* -----------------------------------------------------------------------
* Programmed by: Kelvin Watson
* Filename: cardtest1.c
* Created: 15 Oct 2015
* Last modified: 15 Oct 2015
* Description: Unit tests for dominion.c 's smithyEffect() function
* -----------------------------------------------------------------------
*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1


int main() {
    int i,r;
    int seed = 1000;
    int numPlayer = 2;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    // arrays of all coppers, silvers, and golds
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];
    for (i = 0; i < MAX_HAND; i++)
    {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }
    int errFlag=0;
    int gameOver;
    
    printf ("TESTING smithyEffect():\n");

  
  if(errFlag != 0){
    printf("Some tests failed.\n");  
  }else{
    printf("All tests passed!\n");
  }
  return 0;
}