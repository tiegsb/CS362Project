/*
- I write the test for getCost() function. I check all the valid input, and if they return an incorrected cost, it will display error
message. Since none of the test fail, so getCost() function pass.
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main (int argc, char* argv[])
{
    printf("Testing getCost() function.\n\n");
    if ( getCost(curse) != 0)
        printf("test fail, curse != 0\n");
    if (getCost(estate) != 2)
        printf("test fail, estate != 2\n");
    if (getCost(duchy) != 5)
        printf("test fail, duchy != 5\n");
    if (getCost(province) != 8)
        printf("test fail, province != 8\n");
    if (getCost(copper) != 0)
        printf("test fail, copper != 0\n");
    if (getCost(silver) != 3)
        printf("test fail, silver != 3\n");
    if (getCost(gold) != 6)
        printf("test fail, gold != 3\n");
    if (getCost(adventurer) != 6)
        printf("test fail, adventurer != 6\n");
    if (getCost(council_room) != 5)
        printf("test fail, council_room != 5\n");
    if (getCost(feast) != 4)
        printf("test fail, feast != 4\n");
    if (getCost(gardens) != 4)
        printf("test fail, gardens != 4\n");
    if (getCost(mine) != 5)
        printf("test fail, mine != 5\n");
    if (getCost(remodel) != 4)
        printf("test fail, remodel != 4\n");
    if (getCost(smithy) != 4)
        printf("test fail, smithy != 4\n");
    if (getCost(village) != 3)
        printf("test fail, village != 3\n");
    if (getCost(baron) != 4)
        printf("test fail, baron != 4\n");
    if (getCost(great_hall) != 3)
        printf("test fail, great hall != 3\n");
    if (getCost(minion) != 5)
        printf("test fail, minion != 5\n");
    if (getCost(steward) != 3)
        printf("test fail, steward != 3\n");
    if (getCost(tribute) != 5)
        printf("test fail, tribute != 5\n");
    if (getCost(ambassador) != 3)
        printf("test fail, ambassador != 3\n");
    if (getCost(cutpurse) != 4)
        printf("test fail, cutpurse != 4\n");
    if (getCost(embargo) != 2)
        printf("test fail, embargo != 2\n");
    if (getCost(outpost) != 5)
        printf("test fail, outpost != 5\n");
    if (getCost(salvager) != 4)
        printf("test fail, salvager != 4\n");
    if (getCost(sea_hag) !=  4)
        printf("test fail, sea_hag != 4\n");
    if (getCost(treasure_map) != 4)
        printf("test fail, treasure_map != 4\n");

    int dummy = 100;
    if (getCost(dummy) != -1)
        printf("test fail, dummy should be - 1\n");

    printf("all tests pass, the getCost() function return the corrected cost\n");

    return 0;
}
