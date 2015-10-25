// tests Council Room card

#include<stdio.h>
#include "dominion.h"

int main(int argc, char *argv[])
{
    int retVal = councilRoomEffect();
    assert(retVal == 0) printf("Council Room card is working!\n");

    return 0;
}
