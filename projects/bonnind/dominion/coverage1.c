Daniel Bonnin
CS362 Fall 2015
bonnind@oregonstate.edu
coverage1.c

This file contains information about the testing coverage achieved as a result
of assignment 3. 

buyCard():
Statement coverage: 100%
Branch coverage:    100%
Other coverage:     Unit test compares gameState with a control to check for
                    unexpected transformations.
gainCard():
Statement coverage: 100%
Branch coverage:    100%
Other coverage:     Also tests for postcondition to check that correct card is
                    correct deck array. 

isGameOver():
Statement coverage: 8/9
Branch coverage:    2/3
Other coverage:     100% coverages should have been achieved, but for a bug.
                    The boundary case of 3 absent cards should have executed the
                    missing branch/line. 

fullDeckCount():
Statement coverage: 100%
Branch coverage:    100%
Boundary coverage:  Full, empty, single, and (full -1) deck states are tested.
                    Positive and negative tests.

adventureCard():
Statement coverage: 100%
Branch coverage:    100%
Other coverage:     Manual testing is required to achieve 100% statement/branch
                    coverage due to 2 bugs which interact with each other:
                    The bug that assigns treasure to any card causes the bug
                    that tries to shuffle an empty deck to not infinitely loop.  

                    Empty deck, hand,  full deck, and not enough treasure 
                    cases are tested.  Also compares gameState with a control 
                    to check for unexpected transformations.

smithyCard():
Statement coverage: 100%
Branch coverage:    100%
Other coverage:     Unit test compares gameState with a control to check for
                    unexpected transformations.

villageCard():
Statement coverage: 100%
Branch coverage:    100%
Other coverage:     Unit test compares gameState with a control to check for
                    unexpected transformations.

greatHallCard():
Statement coverage: 100%
Branch coverage:    100%
Other coverage:     Unit test compares gameState with a control to check for
                    unexpected transformations. 
