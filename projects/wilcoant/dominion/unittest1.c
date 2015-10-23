/* -----------------------------------------------------------------------
 * unit test for get cost, check values passed through 
 for loop as integers returning correct return values for cost 
 and negative one for non enumerated values.
 -----------------------------------------------------------------------
 */
//used provided testUpdateCoins.c shell provided in OSU Fall CS362
//modified some initialation variables to test boundaries more completely
 
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 0

int main() {
    printf ("TESTING getCost:\n");
    int i;
    for(i = 0; i < treasure_map + 2; i++)
    {//assert proper return value based on enueration in switch when 
    //passed as integer as it will ultimately be
        if(i == 0)//curse
        {
            assert(getCost(i) == 0);
        }
        if(i == 1)//estate
        {
            assert(getCost(i) == 2);
        }
        if(i == 2)//duchy
        {
            assert(getCost(i) == 5);
        }
        if(i == 3)//province
        {
            assert(getCost(i) == 8);
        }
        if(i == 4)//copper
        {
            assert(getCost(i) == 0);
        }
        if(i == 5)//silver
        {
            assert(getCost(i) == 3);
        }
        if(i == 6)//gold 
        {
            assert(getCost(i) == 6);
        }
        if(i == 7)//adventurer
        {
            assert(getCost(i) == 6);
        }
        if(i == 8)//council_room
        {
            assert(getCost(i) == 5);
        }
        if(i == 9)//feast
        {
            assert(getCost(i) == 4);
        }
        if(i == 10)//gardens
        {
            assert(getCost(i) == 4);
        }
        if(i == 11)//mine
        {
            assert(getCost(i) == 5);
        }
        if(i == 12)//remodel
        {
            assert(getCost(i) == 4);
        }
        if(i == 13)//smithy
        {
            assert(getCost(i) == 4);
        }
        if(i == 14)//village
        {
            assert(getCost(i) == 3);
        }
        if(i == 15)//baron
        {
            assert(getCost(i) == 4);
        }
        if(i == 16)//great_hall
        {
            assert(getCost(i) == 3);
        }
        if(i == 17)//minion
        {
            assert(getCost(i) == 5);
        }
        if(i == 18)//steward
        {
            assert(getCost(i) == 3);
        }
        if(i == 19)//tribute
        {
            assert(getCost(i) == 5);
        }
        if(i == 20)//ambassador
        {
            assert(getCost(i) == 3);
        }
        if(i == 21)//cutpurse
        {
            assert(getCost(i) == 4);
        }
        if(i == 22)//embargo
        {
            assert(getCost(i) == 2);
        }
        if(i == 23)//outpost
        {
            assert(getCost(i) == 5);
        }
        if(i == 24)//salvager
        {
            assert(getCost(i) == 4);
        }
        if(i == 25)//sea_hag
        {
            assert(getCost(i) == 4);
        }
        if(i == 26)//treasure_map
        {
            assert(getCost(i) == 4);
        }
        if(i > 26)
        { //returns negative one for all non enumerated card values
            assert(getCost(i) == -1);
        }
    }
    
    


    printf("All tests passed! Expected results were assertions\nfor each card value value\n\n\n");

    return 0;
}
