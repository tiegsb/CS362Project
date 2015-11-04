Random Testing Analysis

I used a similar approach for both of my random testers, which performed tests on both the Adventurer 
Card and the Smithy Card. My initial unit tests already  functioned by using multiple embedded loops 
that analyzed variations of different game state values such as current player index and hand count. 
I then removed all inner loops but kept the outer loop which then was changed to a variable titled 
"iterations" which would loop through all tests as many times as the "iterations"  variable was set to. 
At the beginning of each loop I then set my random values  which would be used for all tests within the 
loop iteraion. The only values I would set were the max values for modding the random values generated. 
So at the begginning of each loop iteration the following game variables were randomized: game state init 
seed, handcount, current player, and hand position (of the card being tested). From here the test would 
loop through all my 5-7 tests with the randomized varaibles 1000 times (which was the value I set
"iterations" to be). My testing also makes a complete effort in verifying the game state does not change
in any unexpected ways (such as cards being drawn from other players hands, etc) by using a custom function
that checks everys game state vraiable that should not be changing when calling the card function being 
currently tested. I performed both a black box and white box logical analysis to create my test plan. I 
first outlined what the card funcitons should be doing and how the gamestate should be changing (black box) 
and writing down all tests needed to check verify the latter. Next I would then analyze the code line by line
and ad more tests to verify the code is be performing as inteneded as well as getting a sense of how and what
variables are passed into and out of the function (white box). I then combined my black and white box testing
analysis and plans to create the overall testing outline for my tests which I then wrote code for. 



Random Test 1 - Adventurer

Bugs Found:
	- Adventurer Card not discarded from hand
	- Adventurer Card not added to Played Pile
	- Hand Count not incremented by one
	- Cause: Non-treasure cards are not discarded from temp hand

Coverage:

	“Random Test - Adventurer Card: randomtestadventurer.c gcov:”
	File 'randomtestadventurer.c'
	Lines executed:85.51% of 138
	Branches executed:98.41% of 126
	Taken at least once:69.84% of 126
	Calls executed:73.17% of 41
	randomtestadventurer.c:creating 'randomtestadventurer.c.gcov'

	“Random Test - Adventurer Card: dominion.c gcov:”
	File 'dominion.c'
	Lines executed:23.01% of 578
	Branches executed:25.18% of 417
	Taken at least once:17.51% of 417
	Calls executed:12.77% of 94
	dominion.c:creating 'dominion.c.gcov'

Coverage Analysis:
	- Again at first inspection, this unit test was not where I expected it to be in regards 
		to its own line coverage: 85.51%. I thought I had written a random test function in which 
		every line was called. Upon further inspection of the gcov file the lower than expected 
		line was due to my game state comparison function which compared game states from before
		and after calling the function being tested. This comparison function has nearly 20
		return statements which indicate a bug due to the pre and post game state not matching
		when in fact they should. Since this unit test did not uncover any bugs, these return
		statements were never called, and therefore decreasing my line coverage. 
	- This unit test was near perfect in regards to its own branch coverage: 98.41%
	- This unit test covered a small amount of dominion.c in regards to line coverage 
		but since this was just a test of one function it is was expected: 23.01%
	- This unit test covered a small amount of dominion.c in regards to branch coverage 
		but since this was just a test of one function it is was expected: 25.18%
	- Multiple bugs were found in this function so my tests did in fact cover at least one important 
		case that did end up having issues. 
	- From my initial non-random card unit test
		- Test line coverage increased from 84.96% to 85.51%
		- Test branch coverage decreased from 98.44% to 98.41%
		- dominion.c coverage remained the same, however this was expcted since this test only covered
			one card function using a small amount of the overall dominion.c code. Expanding tests to 
			include cards and function not already tested, or combining unit/random tests into one 
			program will be the only way to increase overall coverage at this point



Random Test 2 - Smithy
Bugs Found:
	- More than three cards (4) drawn from deck
	- More than three cards (4) added to hand

Coverage:

	“Random Test - Smithy Card: randomtestcard.c gcov:”
	File 'randomtestcard.c'
	Lines executed:80.95% of 126
	Branches executed:97.96% of 98
	Taken at least once:67.35% of 98
	Calls executed:70.00% of 40
	randomtestcard.c:creating 'randomtestcard.c.gcov'

	“Random Test - Smithy Card: dominion.c gcov:”
	File 'dominion.c'
	Lines executed:23.53% of 578
	Branches executed:24.22% of 417
	Taken at least once:16.31% of 417
	Calls executed:12.77% of 94
	dominion.c:creating 'dominion.c.gcov'

Coverage Analysis:
	- Again at first inspection, this unit test was not where I expected it to be in regards 
		to its own line coverage: 80.95%. I thought I had written a random test function in which 
		every line was called. Upon further inspection of the gcov file the lower than expected 
		line was due to my game state comparison function which compared game states from before
		and after calling the function being tested. This comparison function has nearly 20
		return statements which indicate a bug due to the pre and post game state not matching
		when in fact they should. Since this unit test did not uncover any bugs, these return
		statements were never called, and therefore decreasing my line coverage. 
	- This unit test was near perfect in regards to its own branch coverage: 97.96%
	- This unit test covered a small amount of dominion.c in regards to line coverage 
		but since this was just a test of one function it is was expected: 23.53%
	- This unit test covered a small amount of dominion.c in regards to branch coverage 
		but since this was just a test of one function it is was expected: 24.22%
	- Multiple bugs were found in this function so my tests did in fact cover at least one important 
		case that did end up having issues. 
	- From my initial non-random card unit test
		- Test line coverage increased from 80.33% to 80.95%
		- Test branch coverage increased from 97.92% to 97.96%
		- dominion.c coverage remained the same, however this was expcted since this test only covered
			one card function using a small amount of the overall dominion.c code. Expanding tests to 
			include cards and function not already tested, or combining unit/random tests into one 
			program will be the only way to increase overall coverage at this point
