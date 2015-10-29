//
// *****************************************************************************
// 
// Author:    Erik Ratcliffe
// Date:      October 25, 2015
// Project:   Assignment 3 - Unit Tests
// Filename:  unittest_helpers.h
// Class:     CS 362 (Fall 2015)
//
// *****************************************************************************
//

#ifndef UNITTESTS_H
#define UNITTESTS_H

int whatChanged(struct gameState *origState, struct gameState *state);
struct gameState * copyState(struct gameState *state);

#endif
