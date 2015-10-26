/*
unittest1:
	No bugs

unittest2:
	No bugs

unittest3:
	The discarded card is not in the player's discard pile:
	unittest3: unittest3.c:45: main: Assertion `G.discard[1][0] == gardens' failed.

unittest4:
	- scoreFor fails to calculate the score from even the starting deck:
	unittest4: unittest4.c:26: main: Assertion `scoreFor(0, &G) == 3' failed.

	- scoreFor fails to have correct values for duchy and province cards:
	unittest4: unittest4.c:45: main: Assertion `scoreFor(0, &G) == 3*5*5' failed.
	unittest4: unittest4.c:67: main: Assertion `scoreFor(0, &G) == 3*5*8' failed.

cardtest1:
	- buggySmithy() fails to have a +2 net change in handCount:
	cardtest1: cardtest1.c:36: main: Assertion `G.handCount[0] == 5+3-1' failed.
	- Also fails to put smithy card in discard pile:
	cardtest1: cardtest1.c:43: main: Assertion `G.discard[0][0] == smithy' failed.

cardtest2:
	- buggyAdventurer() doesn't draw silver cards:
	cardtest2: cardtest2.c:60: main: Assertion `G.hand[0][G.handCount[0]-1] == silver && G.hand[0][G.handCount[0]-2] == silver' failed.
	- The hand was initialized as all estate cards,
	but the third-to-last card is a treasure card. That means more than two
	treasure cards were added to the hand:
	cardtest2: cardtest2.c:84: main: Assertion `G.hand[0][G.handCount[0]-3] != copper && G.hand[0][G.handCount[0]-3] != silver && G.hand[0][G.handCount[0]-3] != gold' failed.


*/