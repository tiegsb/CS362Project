Author: Allan Chan
ONID: chanal
Class: CS362
Filename: randomhistory.c
Description: Contains code coverage for randomtestadventurer.c and randomtestcard.c
------------------------------------------------------------------------------------


randomtestadventurer (tests adventurer)
----------------------------------------

	Coverage details of randomtestadventurer
		Lines executed: 100.00% of 43
		Branches executed: 100.00% of 22
		Taken at least once: 72.73% of 22
		Calls executed: 100.00% of 18
	Lines executed:	18.10% of 580 in dominion.c

	For the random tester for adventurer, I used referred to and used much of my 
	unit test that was developed for the adventurer card portion. The changes
	made was with randomized deck set up, the seed, and player. One thing that was
	hardcoded into the player's hand was the adventurer card since the tests
	I ran were to determine if it would be played from the player's hand. 
	The number of iterations for testing is randomly determined beginning at least 2000 tests.
	The number of errors is kept track in a loop for whether the adventurer card is discarded from the hand and
	if the correct number of treasure cards are drawn. Those were the two tests that were pass/fail and
	a reported summary is proviuded at the end of the test. Both tests failed everytime since those were the 
	bugs that I introduced into adventurer card.
	The coverage for the randomtestadventurer was slightly lower in dominion.c (18.10% vs 25.00%), however, 
	the coverage for the the randomtestadventurer is overall higher than my unit test for the adventurer card. 


randomtestcard (tests smithy)
-----------------------------
	Coverage details of randomtestcard
		Lines executed: 88.64% of 44
		Branches executed: 100.00% of 14
		Taken at least once: 71.43% of 14
		Calls executed: 81.82% of 22
	Lines executed: 20.69% of 580 in dominion.c

	For the random tester for smithy, I referred to and used much of my unit test
	that was developed for the smithy card portion. The changes made
	was that I randomized deck set up, the seed, and player. One thing that was 
	hardcoded into the player's hand was the smithy card since the tests I ran
	were to determine if it would be played from the player's hand.
	The number of iterations for testing is randomly determined beginning at least 1000 tests.
	The number of errors is kept track in a loop for whether the smithy card is discarded from the hand
	and if the correct number of cards was drawn. Those were the two tests that were pass/fail and
	a reported summary is provided at the end of the test.i The comparisons were from a pre-hand state
	and the post-hand state of the player.
	Of the two tests, one always passed and the other always failed. This was because of the bug that
	I introduced into the smithy card. 
	The coverage for the randomtestcard is slightly lower in dominion.c (20.69% vs 25.00%), however,
	the coverage for the randomtestcard is very similar to my unit test for the smithy card.
