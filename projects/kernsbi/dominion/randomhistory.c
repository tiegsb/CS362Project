Billy Kerns
Assignment 4

randomtestadventurer:
	Development:
		Developing the test suite for randomtestadventurer consisted of creating an array of type card which holds all the possible
		cards for the game.  Then a for loop is entered that runs x amount of times to make sure they the code is test with many
		different random inputs.  Inside this for loop I start to build the gameState for each player, one player per loop.  This
		is done by using the built in random function to set the different parts of gameState to valid random inputs.  For example
		to set the player''s max handCount I set G.handCount[player] to (rand() % (MAX_HAND)) which sets it to a random number 
		between 0 and MAX_HAND which is defined in dominion.h.  After things like player handCount, discardCount, and deckCount
		are set for the current player the program enters into another series of for loops.  These loops run from 0 to handCount,
		discardCount, and deckCount.  At each iteration the player''s hand, deck, or discard gets a new random card.  For example
		the loop to add to the player''s hand looks like this:
		for(r = 0; r < G.handCount[u]; r++){
			int randomInt = (rand() % (26));
			G.hand[u][r] = randomCard[randomInt];
		}
		where u is the current player.  As we can see randomInt is set to a number between 0 and 26.  Then G.hand[u][r] equals
		the randomCard array at this randomInt giving the hand a random card.  The same is done for the player''s discard and
		deck.  Then G.whoseTurn is set to a random number between 1 and the amount of player minus 1 to make sure whoseTurn
		is a valid player.  Now that the gameState is ready it is passed to a function to check the results of playing the card.

		The checkAdventureRandom() function takes the gameState, whoseTurn, cardDrawn(not used), z(used in adventure card), and n
		(a counter for what iteration we are on).  Once inside checkAdventureRandom() a copy of the orriginal gameState is created.
		AdventureCard() is then called which is a function to run the adventurer card that was created for a previous assignment.
		Now a for loops go through the orriginal gameState''s hand(pre) and the gameState''s hand(post) after running the adventurer 
		card to count the amount of treasure in each state''s hand.  After this I run a few tests on the unaffected players to make
		sure they remain unaffected.  These tests consist of making sure their handCount, discardCount, deckCount in both pre and post
		are the same since the adventurer card should not change these.  After these tests there is an if statement to see if amount
		of treasure in post''s hand is equal to the amount of treasure in pre's hand.  This could be false for a few reasons which
		the suite goes on to test.  The first thing inside the if statement is to get a count of all the treasure cards in pre deck.
		It also get a count of treasure cards in pre discard since these could be shuffled back into the deck.  If two or more treasure
		cards are found then we have error because if there are two or more treasure cards they should have been added to the current
		player''s hand.  If only one treasure is found then only one treasure can be added to the hand.  If this is the case the code
		test to make sure the player''s pre handCount is equal to the player''s post handCount as we should gain a treasure card but
		lose the adventurer card.  Finally if the amount of treasure found is 0 I check to make sure that the player''s pre and post
		hand treasure are the same as treasure cannot be added if it is not found.  If this if block is never entered it means that
		two treasures were found and added to the current player''s post hand.  Now since we know adventurer card gave the player 
		two treasures we test some peripheral things.  The first of which is checking to see if discard is added to the deck when 
		the deck is 0.  This is accomplished by an if statement that checks if pre''s deckCount is 0 when passed to the 
		checkAdventureRandom() function.  If it is and the player''s post deckCount is also 0 we know the discard was never added
		to deck.  The exception being when less than two treasure cards are found since the adventurer card will run all the way
		through the deck again looking for treasure cards.  The last thing that is checked is to make sure the player''s handCount
		is incremented the correct amount.  Since this check is outside of the if block checking to see if pre treasure + 2 equals
		post treasure two treasure cards should have been added to the hand while one adventurer card is removed.  This means that
		post handCount should equal pre handCount + 1.  If any error is encountered and NOISY = 1 an error message is printed that
		includes what test number failed, what was expected, what the actual result is, and on what iteration it failed.  Also an 
		error counter is incremented regardless of NOISY.  At the end of the function this error counter is returned.  If NOISY is
		not set to 1 and this error counter is greater than 0 a message is printed letting the user know an error was encountered
		and to set NOISY to 1 for more information.

	Improvement in coverage:
		The random tester improved the coverage of dominion.c to 22.53% from 19.24% for an improvement of 3.29%  A big chunk of this
		improvement comes from the random tester allowing for a deck count of 0 which makes a call to shuffle.  While the my first
		version of the test was mostly random I hardcoded it to make sure deck count was never 0.  Along with a call to shuffle
		improving the code coverage, when drawCard was called with a deck count of 0 it triggers some additional code in drawCard
		that was not going off in the orriginal tester.

	Correctness:
		By using random inputs to set the amount of cards that can be in a player''s deck, discard, and hand then setting them to 
		random cards we should have a sizeable set of vaild inputs.  Using these inputs helps to ensure that most valid inputs are 
		tested for correctness.  If we know what''s coming into the program are vaild values we can then focus on making sure what
		comes out of the program is correct as well.  Checking that the ouput is correct is done by first counting the amount 
		of treasures that were in the orriginal hand and comparing that to the amount of treasures in the hand after playing the 
		adventurer card.  This should cover the majority of cases but there could be cases where there are not two treasure cards
		to add to the deck.  The test suite accounts for this by checking to see if treasures post hand is not equal to treasures 
		pre hand + 2.  It this evaluates to true then we check for the cases that could have happened such as two or more treasure 
		cards were available(error), only one treasure card available, and 0 cards available.  First the available amount of 
		treasure cards in deck and discard are counted so we know what our results should be.  If two or more ard found then they 
		should have been added to post hand so this throws an error.  If only one treasure card is found then the player''s post 
		hand should be equal to player''s pre hand since once treasure card is added but the hand loses the adventurer card.  So 
		this is what is checked for.  The other case is when there are zero available treasure counts.  When this happens a check 
		is made to make sure that the amount of treasure in post hand is equal to the amount of treasure pre hand.  After all of 
		these checks a few more are made including if the discard was added to deck when it should be, if the adventurer card is 
		discarded, and other player''s gameStates.  Checking the correctness for discardCount is pretty simple since it is just a 
		check to see if the player''s discardCount is incremented.  Checking for correctness when checking other player''s 
		gameStates are correct is simple since none of them should be changed.  The code cycles through each player''s gameState 
		and checks things like handCount, discardCount, and deckCount to make sure they were not changed. Cycling through each 
		player''s discard, deck, and hand would give us better certainty they are not changed but I think that is a bit much as 
		this point.  I feel that using random inputs a few thousand times covers enough inputs that we can confidently say the 
		majority of vaild inputs are checked.  


randomtestcard:
	Development:
		The first part of developing a random test suite for the village card is almost exactly the same as developing one for the
		adventurer card.  The main difference being that when setting up the gameState for the village card we need to initialize
		the gameState''s played card count and number of actions.  Other than that setting up the gameState was done the same way 
		it was in randomtestadventurer.c.

		The checkVillageRandom() function takes the gameState, currentPlayer, handPos, and n(a counter).  Once checkVillageRandom
		is called a copy of the gameState is maded called post.  Next the function cardEffect() is called with the village card
		and post so it's changes can be compared to the pre gameState.  After this we perform a series of tests comparing the pre
		gameState to the post gameState.  The first of these tests is a check to see if pre and post hand count are equal.  This
		checks for equality due to post gaining a card from the deck but losing the village card that was played resulting in a 
		total of zero cards gained.  The next check is a check that the gameStates number of actions is incremented by two.  This
		one almost cause trouble because it would make since for the card to decrement number of actions after it is played but 
		this is done later, outside of the card switch statement.  The next check is just a simple to check to see if the player''s
		discard count was incremented.  The last check involving the current player makes sure that the card drawn came from the
		top of the player''s deck.  After this the suite tests a few things concerning other players.  This includes check each
		player''s hand count, discard count, and deck count.  These tests just make sure they are the same in the post state as 
		they were in the pre state as the village card does not affect other players.

	Improvement in coverage:
		dominion.c coverage improved from 34.32% to 34.49%.  This relativly low increase is to be expected as the implementation
		of the village card is only a few line of few thousand line file.  Within the the village implementation are calls to 
		two functions however these have already been covered by previous code.  

	Correctness:
		Like randomtestadventurer all the inputs that go into building the gameState are random inputs.  After running the test
		suite a few thousand times a large portion of valid inputs and edge cases will have been tested.  Testing to make sure
		these results were the rights ones is relativly straightforward since all the card does is add a card to the player''s 
		hand and adds two to the number of actions in the gameState.  Since we have a copy of the pre gameState it is simply a
		matter of manually adding to the pre gameState and checking for equality.