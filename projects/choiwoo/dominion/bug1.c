//Woo Choi
//bug1.c
//Description of any bugs I find in a file

cardtest1:
	Tests for smithy card.
	* Bug: Expected card count and actual card count do not match!
	* Actual card count is 1 lower than expected.
	Reason: From refactor.c
		2. Smithy:
			in for loop, initial i's value is now 1 instead of 0
			player will only get +2 cards
	
		Smithy originally will get the player +3 cards.
		Since it's +2, it is expected that actual card count to be
		lower by 1 card compared to expected card count.
		
cardtest2:
	Tests for adventurer card.
	* Bug: Expected card count and actual card count do not match!
	* Actual card count is 1 lower than expected.
	* This test was weak, it didn't test for bunch of stuff
		I was out of time.
	Reason: From refactor.c
		1. Adventurer:
			drawntreasure's initial value changed from 0 to 10.
			the first while loop will not run
		
		adventurer orginally will get +2 treasure cards
		since the loop that gets +2 treasure cards will not run,
		the actual card count will be 1 lower than the expected 
		card count.
		
cardtest3:
	Tests for steward card
	* Bug: Something wrong when choice1 == 1;
		coins do not change
		I believe there isn't anything wrong with the code itself.
		the test code has some problems I believe.
		Has to do with G.coins.
	** Everything else works as intended.
		
cardtest4:
	* Bug: No matter what the action count is, 
		it should be 2.
		From refactor:
		4. village:
			instead of +2 actions, # of actions just becomes 2
				from
					state->numActions = state->numActions = 2;
				to
					state->numActions = 2;
		
		For some reason, my test code won't work as intended.
		I believe it has to do with G.numActions. 
		
unittest1:
	Test for getCost()
	* Bug: none detected

unittest2:
	Test for isGameOver()
	* Bug: none detected
unittest3:
	Test for gainCard()
	* Bug: none detected
unittest4:
	Test for updateCoins()
	* Bug: none detected