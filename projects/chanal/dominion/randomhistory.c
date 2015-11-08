Author: Allan Chan
ONID: chanal
Class: CS362
Filename: randomhistory.c
Description: Contains code coverage for randomtestadventurer.c and randomtestcard.c
------------------------------------------------------------------------------------


randomtestadventurer (tests adventurer)
----------------------------------------

	Coverage details of randomtestadventurer
		Lines executed: 100.00% of 48
		Branches executed: 100.00% of 26
		Taken at least once: 76.92% of 26
		Calls executed: 100.00% of 19
	Lines executed:	21.21% of 580 in dominion.c

	For the random tester for adventurer, I referred to and used much of my 
	unit test that was developed for the adventurer card portion. The changes
	made was with randomized deck set up, the seed, and player. I made a randomly
	generated deckcount for 0, -1 to MAX_DECK (although roughly 1/3 chance to start a deckcount with one of those values). 
	This was to induce shuffling of the deck since if the deck was <1 the deck is shuffled.
	One thing that was hardcoded into the player's hand was the adventurer card since the tests
	I ran were to determine if it would be played from the player's hand. 
	The number of iterations for testing is randomly determined beginning at least 20000 tests.
	The number of errors is kept track in a loop for whether the adventurer card is discarded from the hand and
	if the correct number of treasure cards are drawn. Those were the two tests that were pass/fail and
	a reported summary is proviuded at the end of the test. Both tests failed everytime since those were the 
	bugs that I introduced into adventurer card that were being testing in the random tester.
	The coverage for the randomtestadventurer was slightly lower in dominion.c (21.21% vs 25.00%), however, 
	the coverage for the the randomtestadventurer is overall higher than my unit test for the adventurer card
	such as the lines executed, and calls executed. The branches executed is the same as before at 100.00%.
	The taken at least once is slightly lower from 77.27% to 76.92% previously in the unit test. 
	Since I had 100% statement coverage, what I wanted to test for ran as expected. 



randomtestcard (tests smithy)
-----------------------------
	Coverage details of randomtestcard
		Lines executed: 89.80% of 49
		Branches executed: 100.00% of 18
		Taken at least once: 77.78% of 18
		Calls executed: 82.61% of 23
	Lines executed: 23.97% of 580 in dominion.c

	For the random tester for smithy, I referred to and used much of my unit test
	that was developed for the smithy card portion. The changes made
	was that I randomized deck set up, the seed, and player. I made a randomly
	generated deckcount for 0, -1 to MAX_DECK (although roughly 1/3 chance to start a deckcount with one of those values). 
	This was to induce shuffling of the deck since if the deck was <1 the deck is shuffled.
	One thing that was hardcoded into the player's hand was the smithy card since the tests I ran
	were to determine if it would be played from the player's hand.
	The number of iterations for testing is randomly determined beginning at least 20000 tests.
	The number of errors is kept track in a loop for whether the smithy card is discarded from the hand
	and if the correct number of cards was drawn. Those were the two tests that were pass/fail and
	a reported summary is provided at the end of the test.i The comparisons were from a pre-hand state
	and the post-hand state of the player.
	Of the two tests, one always passed and the other always failed. This was because of the bug that
	I introduced into the smithy card that was being tested in the random tester. 
	The coverage for the randomtestcard is slightly higher in dominion.c (23.97% vs 23.45%) and
	the coverage for the randomtestcard is very similar to my unit test for the smithy card.
	The taken at least once is greater than my unit test for smithy. The lines executed for randomtestcard
	is less than my unit test because the non-printed lines are from the if-else statements and my error counter as seen below:

	From grep "###" randomtestcard.c.gcov:
	    #####:   84:            printf("TEST PASSED - obtained correct number of cards\n");
	    #####:   92:            printf("TEST FAILED - smithy was not discarded\n");
	    #####:   93:            error2++;
	    #####:  102:        	printf("\nAll %d test1 passed, player obtained correct number of cards\n", randomIt);
	    #####:  110:        	printf("Test2 error count: smithy not discarded from hand %d of %d tests\n\n", error2, randomIt);
