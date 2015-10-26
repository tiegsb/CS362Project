//Keenan Bishop
//bug1.c for Assignment 3
//
//
//



//Unit tests

/*

1. updateCoins()
	This works fine. All tests pass.

2. isGameOver()
	All tests pass in this one as well.  It tests the two end conditions of 3 piles depleted or 0 provinces




3. scoreFor()
	This test failed when testing 3 gardens and ~20 treasures.  It reports a negative number.




4. getCost()
	This test works fine, it tests every statement in getCost and doesn't error at all.

Card tests

1. Smithy
	Since I introduced a bug to gain 2 cards instead of 3, this fails the test for 3 cards gained and 3 cards missing from deck.
	For some reason, the discard count is wrong too.

2. Adventurer
	The bug of silvers not counting towards drawntreasure is caught.  This means it will grab silvers from the deck but it won't acknowledge it.


3. great hall
	All tests pass except for correct number of cards discarded.  This was the bug I introduced (doesn't discard), so this is expected.

4. village
	Segfault somewhere in the discardCard() function, temporarily not testing
	However, the bug of +3 actions instead of +2 is caught correctly.
*/

