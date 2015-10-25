// tests Smithy card

#include<stdio.h>
#include "dominion.h"

int main(int argc, char *argv[])
{
    int retVal = smithyEffect();
    assert(retVal == 0) printf("Smithy card is working!\n");
    return 0;
}
