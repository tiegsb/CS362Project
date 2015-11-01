Daniel Bonnin
CS362 Fall 2015
bonnind@oregonstate.edu
randomhistory.c

This file contains a report related to the implementation of randomtestcard.c
and randomtestadventurer.c. It details the improvements in coverage resulting
from these files, and contains insights gained relating to the specifications
of the functions under test. 

Relating to both files:

Randomized inputs (with constraints): 
1) number of cards in deck (0 to max)
2) number of cards in hand (1 to max)
3) number of players (1 to max)
4) number of actions (0 to 50 (arbitrarily high edge case))
4) tested card index (index less than number of cards in hand)
5) current player index(less than number of players)
6) card type for each card in hand and deck (within range of card types)

Both random testers initialize a random state, use memcpy() to duplicate the
state, then compare the output of the function under test with that of an 
oracle function. The comparison is handled by oracleVerified().

oracleVerified comparisons:
1) numActions
2) numPlayers
3) deckCount
4) handCount
5) discardCount
6) quantities of different card types in each of deck, hand, and discard

Initially, my plan was to use memcmp() to compare the outputs
of the SUT with the oracle function. However, I discovered a discrepancy with 
the specification and interactions of drawCard(), shuffle(), and discardCard(),
which I did not want to test in these unit tests. The ordering of cards in the
deck, hand, and discard arrays is not important, however, since the deck should
be random. 

Both testers currently detect a bug on every iteration and, therefore, are not 
able to express their complete functionality. However, when the bugs are fixed, 
coverage is significantly improved over the previous tests on these cards. The
bugs that are stopping these tests on the first iteration are already documented
in bugs1.c.

Both random testers get 100% statement and branch coverage. 

randomtestcard.c:

When the previously documented bug is corrected, this test runs all 10,000 
iterations without uncovering a discrepancy between oracleVillageCard() and  
villageCard().

randomtestadventurer.c:

When the previously documented bug is corrected, this test finds a handCount 
discrepancy intermittently (at various iterations, but usually less than
iteration 100). This only occurs when the current player's deck is empty. Also, 
the program segmentation faults intermittently as well. Analysis with GDB
localized the bug to the following line:

cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];

This bug is also already present in bug1.c, and needs to be addressed before 
randomtestadventurer is able to complete more iterations.

Specification learning:

I discovered that adventurerCard() is not discarding the played card like the 
other card functions. When the adventurer card is played, it should be discarded
as well. 

This led me to look at the discardCard() function, which does not add cards to 
the discard array, but rather to playedCards. I cannot find what happens to the
playedCards array at the end of each turn except that playedCardsCount is reset 
in the endTurn() function. This may be a bug.