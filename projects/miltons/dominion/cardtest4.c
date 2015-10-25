// tests Mine card

#include<stdio.h>
#include "dominion.h"

int main(int argc, char *argv[])
{
    int retVal = mineEffect();
    assert(retVal == 0) printf("Mine card is working!\n");

    return 0;
}
