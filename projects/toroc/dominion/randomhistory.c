/*
*	CS362 - Assignment 4 - randomhistory.c
*	Author: Carol D. Toro
*	Date: 10/30/2015
*/


/*

randomtestadventurer.c 
		As I stated in Assignment 3, the bug I had introduced into Adventurer was never 
		triggered as it was part of an else if statement. For this week's test, I opted 
		for getting rid of the bug and introducing a bug where if the second drawn treasure 
		turned to be a gold treasure, the user would lose their buy.
		
		For this test the number of iterations were chosen at random along with player 
		as well as the cards the player had in their hand, and deck. Before playing 
		the adventure card, the shuffle method was called at random. 
		
		In terms of the implementation of the test, I had to hard code the answer to 
		state->whoseTurn to the current random test player. Had I not done this, 
		the program would have drawn cards from the other player's deck
		when calling DrawCard() method. 
		
		Furthermore, while running my tests on Visual Studio, I noticed that whenever the z 
		for tempHand in dominion went over the max of 500, a first-chance exception occurred 
		since the program could not read the location over the boundary. After much investigation, 
		I found this would happen when ever the player only had 1 treasure total in both deck 
		and discard. This would cause the temp hand z would go over the max deck limit trying to 
		find the 2nd treasure. On these instances, instead of ensuring that the player's hand got 
		2 additional treasures, I made sure to test that the player was receiving 
		that 1 treasure coin count and coin value.

Test Results: 
			 Starting Random Test #1 on Adventurer 
			 
				 This random test ensures player receives appropriate treasure cards, 
				 player receives correct value of treasure cards, 
				 handCount increases for player, cards are drawm from player's deck, 
				 cards are discarded to the player's discard deck, 
				 player's expected action doesn't change, 
				 and player's expected buy doesn't change. 

			Random Test #1 completed for adventurerCard() implementation. 
			Test Results for 21028 rounds: 
			 # of times player only had 1 or 0 treasure in deck was 685 
			 Errors with coin count after Adventurer was 0 
			 Errors with coin value after Adventurer was 0 
			 Errors with hand count after Adventurer was 0 
			 Errors with player's deck after Adventurer was 0 
			 Errors with player's discard deck was 3 
			 Errors with Action count after Adventurer was 0 
			 Errors with Buy value after Adventurer was 6988 

	coverage of dominion.c:
			Lines executed:26.26% of 594
			Branches executed:28.21% of 429
			Taken at least once:20.51% of 429
			Calls executed:16.67% of 96
			dominion.c:creating 'dominion.c.gcov'

		Dominion coverage for the random test did not improve since I was running
		similar tests to the unit tests. Function coverage however, did improve once
		I removed the old bug that was impossible to trigger, function coverage is now
		at 100%. Branch coverage on the function also improved as I was able to taken
		each branch at least once.
			
	

randomtestcard.c:
		The random tests for the steward function focused on checking for the following
		different types of errors: coins gained when choice1 is 1, cards gained when 
		choice1 is 2, discarding of cards at choice 2 and 3, proper discarding of
		the seward card, as well as appropriate count of actions and buys.
		
		Like the adventure random test, I had to hard code the answer to state->whoseTurn 
		to the current random test player. These random tests revealed a bug in the 
		implementation of the seward card. The seward card is supposed to add 2 coins
		when choice 1 is 1, and while it does that, a call to UpdateCoins actually
		resets the coin value to original as the coins added in by the Seward do not
		go into the method as bonus. This test failed 100% of the time when ever
		the Seward was supposed to add 2 coins to the player's coin value.


	Test Results:
			Starting Random Test #2 on Steward 
		 
			 This random test looks for the following errors: 
			 errors with coin gained after Steward, 
			 errors with cards discarded after Steward, 
			 errors with Steward discard, 
			 errors with hand count after Steward, 
			 errors with action count, 
			 and errors with buy count after Steward. 
		 
			Random Test #1 completed for steward card implementation. 
			Test Results for 15161 rounds: 
			 Errors with card gain  after Steward was 0 
			 Errors with coin gain after Steward was 2961 
			 Errors with cards discarded after Steward was 0 
			 Errors with Steward discard was 0 
			 Errors with hand count after Steward was 0 
			 Errors with actions after Steward was 0 
			 Errors with buys after Steward was 0 

	Coverage of dominion.c:
			Lines executed:23.23% of 594
			Branches executed:25.87% of 429
			Taken at least once:17.25% of 429
			Calls executed:17.71% of 96
			dominion.c:creating 'dominion.c.gcov'
			
			
		Since I was testing a card implementation I hadn't tested before, I did not 
		expect for the line coverage in dominion to improve significantly. Overall,
		if I were to run all unit tests along with random tests, I can probably expect
		to see line coverage improve by a few percentage points since the seward case
		is about 20 lines of code in dominion.c. Branch coverage could have been better
		had I focused on making choice1 equal to either 1 or 2 more than going to the else
		branch that discards 2 cards in hand.
			
   