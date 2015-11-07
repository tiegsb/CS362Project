CS 362 - ASSIGNMENT 4               KELVIN WATSON 
randomhistory.c                    	ONID: watsokel      
                                    OSU ID: 932540242 
                                    https://github.com/amchristi/cs362f15/tree/master/projects/watsokel 
-----------------------------------------------------------------------

randomtestcard.c:
-----------------

COVERAGE:
	  
	*** Statement Coverage ***
	
	All of the embargo case statements within cardEffect() were executed. 
	In particular, notice that 53% of the time, the supply card was not in 
	play, and 47% of the time, the supply card in question was not in play. 
	This even distribution is not surprising since there are 26 cards, and 
	only 10 of the kingdom cards are in play, and 7 of those cards (curse, 
	estate, duchy, province, copper, silver and gold) are always in the 
	game. In my random test, I randomized choice1 to be any card between the 
	enumerated type card (0 through 26) to allow both valid and invalid 
	cards to be used in the test. This was done in order to shift the
	probability space to ensure that the important inputs were covered by
	the random test. This adjustment of the random inputs was necessary to 
	produce card values for the decks, hands and discard piles in order for 
	the tests to run properly (otherwise, the test would cause  
	segmentation faults).
	
	*** Branch Coverage ***	

	As mentioned above, 53% of the time, the supply card was not in play, 
	so the function returned -1 approximately half the time. The remaining 
	half of the time, the function returns 0. This means that both cases of 
	embargo (error and success) were exercised by the random tests. 

	
EFFORT TO CHECK CORRECTNESS:

	In order to test correctness, I created an oracle to compare the 
	results of the call to the embargo case within cardEffect(). 

	The oracle replicates the action of the call to the cardEffect() 
	function's embargo case, then compares this value to the actual game 
	state ("post" variable)'s value. For instance, if choice1 is a supply 
	card that is in play, then the actual embargo token count in the game 
	should have increased by one. The oracle replicates this scenario by 
	incrementing it's embargoTokens count for a particular supply card by 1, 
	and the oracle's value is compared against the actual game state's 
	value. On the other hand, if the supply card in choice1 is not in play, 
	then the return value of the function is also compared against the 
	expected value in the oracle (which should be -1). Also, the actual coin 
	count is also compared against the oracle's expected value. In the 
	embargo case within cardEffect(), the player's coin count is increased 
	by 2. Thus, the oracle's coin count is increased by 2 and compared 
	against the game state's actual value. 

	*** Checking for unexpected transactions *** 
	
	I also checked for unwanted transactions by comparing the opponent's 
	hand count, discard count, and deck counts to ensure that they were not 
	disturbed during the player's call to embargo case within cardEffect(). 

	
randomtestcardAdventurer.c:
---------------------------
/* Please note that I had to write a new buggy version of adventurerEffect() method 
because my original buggy version from assignment 2 introduced an infinite loop. 
Professor Christi has advised us (see Piazza post @100) to remove infinite loops 
in buggy versions of the cardEffect() cases. */

COVERAGE IMPROVEMENTS:

	The differences in statement coverage between the unit tests of the 
	adventurerEffect() method and the random tests of the 
	adventurerEffect2() method are quite dramatic. 

	*** Statement Coverage ***
	
	The random tests included 2000 iterations (calls to 
	the adventurerEffect2() method) using random input, which is in sharp 
	contrast to the 6 calls that were in the unit tests. In the random 
	tests, the while condition on line 670 was evaluated 39259 times, 
	whereas in the unit tests in the previous assignment, it was only 
	evaluated 44 times. 

	*** Branch Coverage ***
	
	All branches were executed in the random tests, some more than others. 
	Surprisingly, there was more of an even distribution of branch coverage 
	percentages in the unit tests than in the random tests, despite the 
	large number of executed tests. However, since the deck count was 
	initialized to a random number between 0 and 500, this means that most 
	of the time, the deck was not empty so it is not surprising and branch 0 
	at line 702 was taken less than 1% of the time (145 times of a total of 
	35259 times). The 1% also implies that most of the time, two treasure 
	cards are drawn before the deck has a chance to become empty to require 
	shuffling. Although this edge case was evaluated a small percentage of 
	the time, it never the less executed 145 times. 
	
	On line 716, notice that 94% of the time, z-1>0 evaluated to true, which 
	means that many cards were drawn before treasure cards were encountered, 
	resulting in a larger temphand. This greatly increases the coverage of 
	the lines within the while loop, resulting in 29275 executions of the 
	line: 
	state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temp 
	hand[z-1];. 
	
	*** Logic Coverage ***
	
	The branch at line 707 was fully covered. It seems most of the time, 
	even though cards were generated at random, there was at least one copper, 
	silver, and gold treasure card. In an actual game, there should always
	be enough treasure cards. Otherwise, the result would be an infinite 
	loop. This indicates that the degree of randomness generated by the random
	tests is appropriate for the purposes of testing this game.
	
	if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
	branch  0 taken 96% (cardDrawn == copper)
	branch  1 taken 4%	(cardDrawn != copper)
	branch  2 taken 96% (cardDrawn == silver)
	branch  3 taken 4%	(cardDrawn != silver)
	branch  4 taken 4% 	(cardDrawn == gold)
	branch  5 taken 96%	(cardDrawn != gold)
	Let C be the boolean value of the expression cardDraw==copper, 
	let S be the boolean value of the expression cardDrawn==silver,
	and let G be the boolean value of the expression cardDrawn==gold.
	If S==false, and G==false,and C==true evaluates true, then the entire 
	condition evaluates to true. If S==false G==false, and C==false,
	then the entire condition evaluates to false. This shows that C 
	(cardDrawn==copper) independently affects the outcome. Using similar
	logic for the other two boolean values shows that both S 
	(cardDrawn==silver)	and G (cardDrawn==gold) independently affect the
	outcome. Each branch was executed to some degree, so each combination
	of boolean values occurred at least once.
	
EFFORT TO CHECK CORRECTNESS:

	In an effort to check correctness, I created an oracle from the game state 
	to replicate the actions of the adventurerEffect2() function.
	
	The oracle is first copied from the game state into a struct named "oracle". 
	Prior to the call to adventurerEffect2() using the struct gameState *post 
	parameter, the treasure count in the player and opponent's hand were counted.	
	(The opponent's cards were also checked in order to detect unexpected 
	transactions - details below)
	
	Note that it is not possible to compare the handcount of the oracle and 
	the actual game state after the call to adventurerEffect2() due to the 
	inability to know how many cards would be drawn before two treasure 
	cards are ever encountered. The same reasoning applies to the discard 
	pile. As it is impossible to determine how many cards would need to be 
	drawn from the deck to obtain two treasure cards, it is also not 
	possible to determine the number of times the deck would become empty 
	and require shuffling and re-supply from the discard pile. 

	The treasure card count was checked against the oracle after the call 
	to adventurerEffect2(). Based on the comparison, the method 
	adventurerEffect2() does correctly increase the player's treasure card 
	count in the hand increasing by two. The actual hand count from the call 
	to adventurerEffect2() using the "post" parameter was compared against 
	the oracle, and it was determined that the function correctly increases 
	the hand count by 2 cards (i.e. the two treasure cards). 

	Checking for unexpected transactions: 
	
	I also checked for unwanted transactions by comparing the opponent's 
	treasure card count, hand count discard count, and deck counts to ensure 
	that they were not disturbed during the player's call to 
	adventurerEffect2(). 