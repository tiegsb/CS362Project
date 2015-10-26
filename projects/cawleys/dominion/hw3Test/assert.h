#ifndef _ASSERT_H
#define _ASSERT_H

#include <stdbool.h>
#include "dominion.h"

//created a gamestate for tests
void initState(struct gameState* state);

// Doesn't test anything, just records the fact that the test passed or failed.
//Retunrs 0 if the pass value is true, 1 if it is false. Also prints out the pass or fail message to standard out
int assert(bool pass, const char* what, const char* message);

#endif