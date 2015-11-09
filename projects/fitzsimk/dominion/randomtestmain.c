#include "randomtestadventure.h"
#include "randomtestcard.h"
int main(){
     int seed = time(NULL);
    srand(seed);
    test_adventurer(seed);
    test_mine(seed);
    
}