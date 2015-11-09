RandomHistory.c

randomtestadventurer.c
---Removed initial deck / hand tracking outputs designed to ensure deck properly constructed by randomizer.
---initially set probability of treasure being generated to random values between 10% and 100%, but the vast majority of executions were milling the entire
deck into the discard pile and thus it was running to the same conclusion nearly every time. Increased treasure probability to 50% - 100%.
---Achieved thorough coverage of entire card call with 1000 iterations through test.
---Implemented tracking of remaining cards in deck to determine whether all cards in deck had been cycled.
---Implemented tracking of number of adventurers played by a player as opposed to utilizing cards in discard, as this is not as easily thrown off by other
testable errors.
---Added text output of variables to determine status of relevent variables when error was thrown.
---Removed several bugs from dominion.c in order to properly test the accuracy of the debugger; this included incorrect number of treasures drawn, incorrect
incrementing of discardCount/no cards being placed in discard pile, and others. These bugs have been largely replaced as this was not a direction of the assignment.

randomtestcard.c
---Removed initial deck / hand tracking outputs designed to ensure deck properly constructed by randomizer.
---Implemented tracking of remaining cards in deck to ensure that, if incorrect number of cards are drawn this is not due to insufficient cards in deck.
---Implemented tracking of cards played to measure against cards in discard and cards drawn. This determines whether appropriate number of cards are drawn
and whether appropriate number of cards are discarded.
---Implemented hand and discard scanning in order to determine whether correct cards are placed in the discard pile (should be exclusively smithy cards) and
whether appropriate cards are located in hand to ensure that cards are appropriately removed from hand (should hold no smithy cards).
---Added text output of variables to determine status of relevent variables when error was thrown.
---Removed non-essential treasure cards from deck to minimize likelihood of errors resulting from random test software.
---gcov files show perfect coverage of card function.
---Removed several bugs from dominion.c during testing to ensure that the tester was working appropriately including no increment of discard pile, incorrect
card removed from hand on smithy execution, etc. These have been replaced in file as this was only to test the accuracy of the tester.