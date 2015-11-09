randomtestadventure.c:

1) Loop for number of tests
2) Random number of cards in hand
3) Randomly allocations of cards in hand
4) Hand stopped if no adventurere card and returned to top
5) Test were then run on the the hand including randomizing the various cards
6) Pass/Fail tallied

Coverage of randomtestadventure.c:
Lines executed:90.12% of 81
Branches executed:100.00% of 50
Taken at least once:86.00% of 50
Calls executed:88.46% of 26

Correctness check of randomtestadventurer:
The number of cards was expanded to 11 from the orginal test. A check was also added to make certain they were between 0-26.
The adventurer card is having problems when the size is 0.
	
randomtestcard.c:
The Smithy card was used for this test. Much of the structure was the same as for the randomtestadventurer
test function with the following parameters: cards in the hand, player, hand count, position of the smithy card in the hand, passed and failed tests.

Coverage of randomtestcard.c:
Lines executed:89.80% of 49
Branches executed:100.00% of 16
Taken at least once:75.00% of 16
Calls executed:83.33% of 18

Correctness check of randomtestcard.c:
A check that makes sure the deck is decreased by 3 after the execution of the card. 
