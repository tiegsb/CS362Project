//############################################################
// Filename: randomhistory.c
//############################################################

// ---------- Effort to check correntness of specification ---
	In order to make sure I had full control of the game state,
I wrote code to initialize every aspect of the game state that
was relevant to the method I was testing. This involved initializing
the both players hand, deck, discard piles, and supply counts. I 
was sure that I covered all the branches in my cardtests, so I used
made sure to check everything in my random tests that I checked in 
the cardtests.
	Here is a summary of what I checked for the adventurer code:
	// - Check hand count for current player 
	// - Check deck count for current player 
	// - Check treasure count for current player 
	// - Check that the cards added to the discard pile are not treasures
	// - Check hand count for other player 
	// - Check deck count for other player 
	// - Check discard pile for count for other player
	// - Check the coin supply did not change

	Here is a summary of what I checked for the smithy code:
	// - Check hand count for current player
	// - Check deck count for current player
	// - Check treasure count for current player
	// - Check that the cards added to the discard pile are not treasures
	// - Check that played cards count increased by 1
	// - Check hand count for other player
	// - Check deck count for other player
	// - Check discard pile for count for other player
	// - Check the coin supply did not change

	I also used asserts and printf messages to validate my tests. 
The printf statements make it clear what I am validating. I tell
the user, which test fails (if any) and I also tell the user if 
there was a test that failed within a test iteration. A test 
iteration is when one randomized loop runs and all the tests
validate that loops results.
	Looking at the random tests for the adventurer card, you can
see that no tests fail. Remember I introduced a bug within the 
adventurer card? I know about the bug, but it is very difficult
to test using unit or random testing. The bug in the code is 
adventurer card tries to draw 4 treasures instead of 2, but
when the adventurer card draws a treasure, it is with 2 treasures.
This means the end result is that the adventurer card draws the 
correct amount of treasures, even though the code is wrong. It
seems like this type of bug can only be caught in code reviews.
	Looking at the random tests for the smithy card, you can see
that one test fails. The smithy card is drawing more cards than
it should be. This was the bug that I introduced.

// ---------- Improvement in Test Coverage -------------------
Total Coverage of all tests without random tests: 35.49% 
Total Coverage of all tests with random tests: 35.49%
 - It seems like the coverage did not change. My original
   cardtests looked like they were thorough enough without
   the randomized values. All the branches seemed like they
   were already covered.