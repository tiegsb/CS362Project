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


*/