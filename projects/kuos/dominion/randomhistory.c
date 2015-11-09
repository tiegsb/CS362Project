/******************************************************************************
randomhistory.c
Sharon Kuo (kuos@oreognstate.edu)
CS362-400: Assignment 4

File 'dominion.c'
Lines executed:21.65% of 559
Branches executed:23.74% of 417
Taken at least once:15.83% of 417
Calls executed:11.58% of 95
dominion.c:creating 'dominion.c.gcov'

File 'randomtestcard.c'
Lines executed:83.33% of 84
Branches executed:100.00% of 38
Taken at least once:81.58% of 38
Calls executed:81.08% of 37
randomtestcard.c:creating 'randomtestcard.c.gcov'

File 'dominion.c'
Lines executed:25.04% of 559
Branches executed:25.66% of 417
Taken at least once:19.18% of 417
Calls executed:12.63% of 95
dominion.c:creating 'dominion.c.gcov'

File 'randomtestadventurer.c'
Lines executed:90.59% of 85
Branches executed:100.00% of 38
Taken at least once:89.47% of 38
Calls executed:89.19% of 37
randomtestadventurer.c:creating 'randomtestadventurer.c.gcov'

For the development of my random testers, I took the base code from Assignment
3 for the smithy and adventurer card tests and modified them to run multiple
times with randomized player counts, deck counts, hand counts, discard pile
counts, and randomized cards. The tests were run 20000 times to cover many of
the possible combinations of hand counts, deck counts, discard counts, player
counts, and permutations of the cards in each hand, deck, and discard pile.

In addition, for both cards, I first randomized the hand, deck, and discard
piles for each player with kingdom cards, then iterated through each hand,
deck, or discard pile and randomly changed some cards to a random treasure
card.

The coverage for the random tester files themselves appears to have improved
slightly from the individual unit tests from the previous assignment. This is
because the introduction of more code to generate the random test states was
covered at every iteration of the test. Additionally, more branches were taken
at least once, probably because of the changes to the game state that would
have resulted from the randomization of game parameters, which would allow for
different results from the testing from the single game instantiation in the
original unit test. The original branches for the smithy card test and
adventurer card test were 50% taken at least once, but this increased to 82%
and 89%, respectively.

The coverage for the dominion file itself was increased slightly for both
random tests. This is probably because the changes in parameters for the game
state would have contributed to taking different paths when executing the
initialization of the game state. Additionally, other functions may have been
called with different parameters each time because of the randomization of the
game state parameters, which could have resulted in greater coverage of the
dominion code.

The specification was checked by saving card counts for players before calling
the card function, then checking these saved counts against expected values
after the result of the card function being called. The specification was
tested on individual runs of the random card testers with values printed out,
then afterwards, to eliminate excessive print statements, removed.

******************************************************************************/