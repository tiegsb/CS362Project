Ben Henning
CS 362
Assignment 4
randomhistory.c

/**************************************************
RANDOMTESTADVENTURER
***************************************************/

For creating random test cases, I noted that the adventurer card should affect the player's
deck, hand, discard pile, played card pile, and the associated counts. Thus, I programmed the
test to create random values for those functions, as well as the number of players, current
player, and adventurer card hand position.  In order to keep the randomized input
realistic (and not crash the program), I implemented the following rules on the random
variables:
The total cards in the player's deck, hand, and discard could not exceed max_hand.
The total cards mentioned above must be at least 3 (Minimum: one adventurer in hand, two treasure in deck or discard pile).
There must be at least one card in the hand.
At least one hand card has to be adventurer.
There must be at least 2 treasure cards contained between the deck and discard pile.
There should be no adventurer cards in the deck or discard piles, as it could mess up the discard checks.

The following 6 checks were performed after calling the card function:
1. The player's hand should gain two treasure cards.
2. The player's hand should have a net gain of 1 card (2 drawn treasures - 1 discarded adventurer).
3. PlayedCardCount in gameState should be increased by 1.
4. Player's hand should contain 1 less adventurer.
5. Top of playedCards pile should be adventurer.
6. Aside from what was mentioned in the description above, nothing else in gameState should be changed.

Test 1 almost always failed. Most of the time, several more treasure cards were added to the hand than
expected.  A few cases were noticed where less than 2 treasure cards were drawn.
Test 2 appeared to always fail. The player's hand always had a net gain of several cards rather than just one.
Tests 3, 4, and 5 always failed. This strongly indicates that the adventurer card is not being discarded after use.
Test 6 almost always passed, but there were a small number of cases where it failed, indicating that something
else in game state is being changed. This occurred in 24 out of 20000 tests, or 0.24% of cases. Perhaps this could
be some side effect of the bug I introduced into adventurerCardEffect wherein hand count is incremented whenever a
non-treasure card is drawn. In all cases where this check failed, the player's net card gain increased the hand
over the max_hand value, so it is possibly interfering with other parts of the gameState struct. This effect was not
detected in the last assignment's non-random testing.

The coverage results are below.

gcov results for dominion.c from assignment 3's targeted tests:
File 'dominion.c'
Lines executed:15.83% of 581
Branches executed:15.83% of 417
Taken at least once:13.43% of 417
Calls executed:7.37% of 95

gcov results for dominion.c from randomtestadventurer:
File 'dominion.c'
Lines executed:22.55% of 581
Branches executed:20.14% of 417
Taken at least once:18.47% of 417
Calls executed:10.53% of 95

gcov results for randomtestadventurer.c:
Lines executed:99.18% of 122
Branches executed:100.00% of 70
Taken at least once:94.29% of 70
Calls executed:96.77% of 31

Coverage of randomtestadventurer.c was very good, with all measures being above 94% and
branch coverage being 100%. This indicates the tests were running as they should.
The random tests significantly increased all measures of coverage of dominion.c over the
non-random tests from the previous assignment.  The coverage of the adventurer card function
itself within dominion.c was very good, with all lines covered and all branches taken.

/**************************************************
RANDOMTESTCARD - Smithy Card
***************************************************/
When creating the random test generator, I noted that the smithy card should affect the player's
deck, hand, discard pile, played card pile, and the associated counts. I therefore programmed the
test to create random values for those functions, as well as the number of players, current
player, and smithy card hand position.  In order to keep the randomized input
realistic and useful, I implemented the following rules:
The total cards in the player's deck, hand, and discard could not exceed max_hand.
The total cards mentioned above must be at least 4 (Minimum: one smithy in hand, three cards to draw).
There must be at least one card in the hand.
At least one hand card has to be smithy.
There must be at least 3 cards contained between the deck and discard pile.
There should be no smithy cards in the deck or discard piles, as it could mess up the discard checks.

The following 5 checks were performed after calling the smithy card's function:
1. Player's hand should have a net gain of 2 cards. (3 cards drawn, smithy discarded).
2. The player should have 1 less smithy card in hand.
3. PlayedCardCount should be incremented by 1.
4. The top of playedCards should be a smithy.
5. Aside from what was mentioned in the description, no other parts of gameState should be changed.

All tests passed every time with the exception of test 1, which failed every time.  In every test
case, the player's hand had a net gain of 3 cards instead of 2.  This could indicate that either
an extra card was being drawn or that the smithy was not being discarded.  However, the fact that
tests 2, 3, and 4 never failed is evidence that the smithy was being properly discarded and that
an extra card was being drawn by the smithy.

Coverage Results:

dominion.c results from targeted tests from assignment 3:
File 'dominion.c'
Lines executed:18.24% of 581
Branches executed:17.75% of 417
Taken at least once:14.15% of 417
Calls executed:9.47% of 95

dominion.c results from new random tests:
Lines executed:22.20% of 581
Branches executed:19.18% of 417
Taken at least once:16.55% of 417
Calls executed:10.53% of 95

randomtestcard.c
Lines executed:89.53% of 86
Branches executed:100.00% of 34
Taken at least once:82.35% of 34
Calls executed:81.48% of 27

Every type of coverage of dominion.c was improved somewhat with the random tests, although not by as
much as in the case of the adventurer tests.  This is probably because the smithy card effect is
somewhat simpler than the adventurer card effect and therefore a little easier to target with non-
random tests than was the adventurer.  Random testing still improved coverage, however.  All lines
and branches within the smithy card function were covered.

Coverage of randomtestcard.c was very good. While the coverage measurements were not as highs as in
randomtestadventurer, the unexecuted lines and branches were failure notifications for pass/fail tests
that the smithy always passed. Therefore, the test was still running everything it was supposed to.
