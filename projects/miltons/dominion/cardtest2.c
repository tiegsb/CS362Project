// tests Adventurer card

#include<stdio.h>
#include "dominion.h"

int main(int argc, char *argv[])
{
    int retVal = adventurerEffect();
    assert(retVal == 0) printf("Adventurer card is working!\n");
    return 0;
}
