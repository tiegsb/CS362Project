/*Wilson Chan
 *Development and Coverage of Random Testers
 *CS362 - Assignment 4
 */
 
I develop the random tester for the adventurer card and the smithy card by trying to randomize as much as the games variables as I could. The number of players is random. The player activating the card is also chosen at random. The hand, deck, and discard pile is randomly generated from a set of kingdom cards. The size of the hand, deck, and discard is also randomly generated up to the max value allowed. Deck and hand size are currently set to 500 cards in the dominion.h file. Although its highly unlikely that players will have such large decks and hands, random testing can cover these edge cases easily. Asserts and printf was very useful in checking the correctness of my tests. I used some of the games core functions such as playCard() to activate the tested card. The advantage was that many of these functions will return a true of false value as to whether the function ran correctly. I would use the asserts and printf to verify the return value. I removed most of the printf so that the output file will read better. Otherwise, it would be cluttered with 50000 test runs.

randomtestadventurer:
The bugs I introduced in assignment 2 made several of the hand, deck, or discard count test fail. Also, I believe that there is a bug the discard() funciton causing it to not operate correctly 100% of the time. The bugs may allow for an additional treasuer card to be drawn or call an unnessary shuffles.

randomtestadventurer coverage:
	Lines executed:80.00% of 205
	Branches executed:92.45% of 106
	Taken at least once:83.02% of 106
	Calls executed:100.00% of 33

randomtestcard:
The bugs I introduced in assignment 2 for the smithy card caused issues when the smithy card may sometimes not be discarded. Also, the card may something be discarded into the trash instread of the discard pile. The results of the test shows how the discard count and deck count is something failing the test.

randomtestcard Coverage:
	Lines executed:67.36% of 193
	Branches executed:86.36% of 88
	Taken at least once:67.05% of 88
	Calls executed:100.00% of 30

Over all the test coverage statistics look fine. The branches executed are from 86% to 92%. The number of lines executed ranged from 67% to 80%. 