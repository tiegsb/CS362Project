#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
    int r;
    int seed = 1000;
    int numPlayer = 2;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    

    r = initializeGame(numPlayer, k, seed, &G);

    printf ("TESTING getCost():\n");


    //Testing with values in the set of cards in this game.
    assert(getCost(adventurer) == 6);
    #if (NOISY_TEST == 1)
    printf ("PASSED. OUTPUT: %d RESULT: %d \n", 6, getCost(adventurer));
#endif
 
    assert(getCost(council_room) == 5);
#if (NOISY_TEST == 1)
    printf ("PASSED. OUTPUT: %d RESULT: %d \n", 5,getCost(council_room));
#endif
    assert(getCost(feast) == 4);
#if (NOISY_TEST == 1)
    printf ("PASSED. OUTPUT: %d RESULT: %d \n", 4, getCost(feast));
#endif
    assert(getCost(gardens) == 4);
#if (NOISY_TEST == 1)
    printf ("PASSED. OUTPUT: %d RESULT: %d \n", 4,getCost(gardens));
#endif
    assert(getCost(mine) == 5);
#if (NOISY_TEST == 1)
    printf ("PASSED. OUTPUT: %d RESULT: %d \n", 5,getCost(mine));
#endif
    assert(getCost(remodel) == 4);
#if (NOISY_TEST == 1)
    printf ("PASSED. OUTPUT: %d RESULT: %d \n", 4,getCost(remodel));
#endif
    assert(getCost(smithy) == 4);
#if (NOISY_TEST == 1)
    printf ("PASSED. OUTPUT: %d RESULT: %d \n", 4,getCost(smithy));
#endif
    assert(getCost(village) == 3);
#if (NOISY_TEST == 1)
    printf ("PASSED. OUTPUT: %d RESULT: %d \n", 3,getCost(village));
#endif

    assert(getCost(baron) == 4);
#if (NOISY_TEST == 1)
    printf ("PASSED. OUTPUT: %d RESULT: %d \n", 4,getCost(baron));
#endif
 
    assert(getCost(great_hall) == 3);
#if (NOISY_TEST == 1)
    printf ("PASSED. OUTPUT: %d RESULT: %d \n",3 ,getCost(great_hall));
#endif
    
    //If this function is passed a card value that is not in the game,
    //it will still return the value of that card.

    assert(getCost(treasure_map) == 4);
#if (NOISY_TEST == 1)
    printf ("PASSED. notInDeck OUTPUT: %d RESULT: %d \n", 4, getCost(treasure_map));
#endif

    //Testing if card enum is just a little bit out of range.

    assert(getCost(27) == -1);
#if (NOISY_TEST == 1)
    printf ("PASSED. notInDeck OUTPUT: %d RESULT: %d \n", 4, getCost(27));
#endif
    //Testing if card enum is extremely out of range.
    assert(getCost(999) == -1);
#if (NOISY_TEST == 1)
    printf ("PASSED. outOfRange OUTPUT: %d RESULT: %d \n", -1, getCost(999));
#endif

    printf("All tests passed!\n");

    return 0;
}