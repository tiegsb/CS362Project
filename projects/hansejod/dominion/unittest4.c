#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include<stdlib.h>
#include<time.h>


int main()
{
    int seed = 1000;
    int numPlayer = 2;
    int k[10] = {adventurer, council_room, feast, gardens, mine
        , remodel, smithy, village, baron, great_hall};
    int result, result1, result2;
    
    struct gameState game;
    
    initializeGame(numPlayer, k, seed, &game);
    
    printf("\n");
    printf("*------------------------- Unit Test #4 -------------------------*\n\n");
    printf("Testing if buyCard properly terminates if one of the conditions is not \n");
    printf("met and if all are satisfied, handCount increases by 1. \n");
    
    /*Going through and systematically change only one of the 3 variables, numBuys, supplyCount
     and coins. */
    printf("Checking if hand count increase by one when other conditionals are satisfied.\n");
    game.numBuys = 1;
    printf("numBuys: %d\n",game.numBuys);
    
    game.supplyCount[3] = 1;
    printf("supplyCount: %d\n",supplyCount(3, &game));
    
    game.coins = 8;
    printf("Coins: %d\n",game.coins);
    
    result = getCost(3);
    printf("cost: %d\n",result);
    result1 = game.handCount[0];
    printf("handCount: %d\n", result1);
    
    printf("Calling buyCard function!\n");
    buyCard(3, &game);
    
    printf("numBuys: %d\n",game.numBuys);
    printf("supplyCount: %d\n",supplyCount(3, &game));
    printf("coins: %d\n",game.coins);
    result2 = game.handCount[0];
    printf("handCount: %d\n", result2);
    if( result1 != result2 - 1){
        printf("Bug found! handCount is not increased by 1. \n");
    }
    printf("\n");

    printf("Checking if function terminates if numBuys is 0.\n");
    game.numBuys = 0;
    printf("numBuys: %d\n",game.numBuys);
    
    game.supplyCount[3] = 1;
    printf("supplyCount: %d\n",supplyCount(3, &game));
    
    game.coins = 8;
    printf("Coins: %d\n",game.coins);
    
    result = getCost(3);
    printf("Cost: %d\n",result);
 
    printf("Calling buyCard function!\n");
    result1 = buyCard(3, &game);
    
    printf("numBuys: %d\n",game.numBuys);
    printf("supplyCount: %d\n",supplyCount(3, &game));
    printf("coins: %d\n",game.coins);
    assert(result1 != 0);
    printf("\n");
    
    printf("Checking if function terminates if there are no cards left of that type.\n");
    game.numBuys = 1;
    printf("numBuys: %d\n",game.numBuys);
    
    game.supplyCount[3] = 0;
    printf("supplyCount: %d\n",supplyCount(3, &game));
    
    game.coins = 8;
    printf("Coins: %d\n",game.coins);
    
    result = getCost(3);
    printf("Cost: %d\n",result);
    
    printf("Calling buyCard function!\n");
    result1 = buyCard(3, &game);
    
    printf("numBuys: %d\n",game.numBuys);
    printf("supplyCount: %d\n",supplyCount(3, &game));
    printf("coins: %d\n",game.coins);
    assert(result1 != 0);
    printf("\n");
    
    printf("Checking if function terminates if player does not have enough coins.\n");
    game.numBuys = 1;
    printf("numBuys: %d\n",game.numBuys);
    
    game.supplyCount[3] = 1;
    printf("supplyCount: %d\n",supplyCount(3, &game));
    
    game.coins = 0;
    printf("Coins: %d\n",game.coins);
    
    result = getCost(3);
    printf("Cost: %d\n",result);
    
    printf("Calling buyCard function!\n");
    result1 = buyCard(3, &game);
    
    printf("numBuys: %d\n",game.numBuys);
    printf("supplyCount: %d\n",supplyCount(3, &game));
    printf("coins: %d\n",game.coins);
    assert(result1 != 0);
    printf("\n");
  
    printf("All unit #4 tests passed! \n");
    return 0;
}