CS 362 - ASSIGNMENT 3               KELVIN WATSON 
coverage1.c                    		ONID: watsokel      
                                    OSU ID: 932540242 
                                    https://github.com/amchristi/cs362f15/tree/master/projects/watsokel 
----------------------------------------------- -----------------------
COVERAGE:


unittest1 - fullDeckCount()
---------------------------
The following is the unittestresults.out output for unittest1:
	File 'dominion.c'
	Lines executed:17.25% of 574
	Branches executed:18.89% of 413
	Taken at least once:15.74% of 413
	Calls executed:7.37% of 95

*** Statement coverage: All lines were executed as there were no lines 
	with the #### notation, as noted below: 
	function fullDeckCount called 432 returned 100% blocks executed 100% 

*** Branch Coverage: According to the dominion.c.gcov file, all of the 
	branches executed to some degree. Most of the time, the if statements 
	within the for loops executed the fallthrough branch, which means that 
	they were executed and the card type did match in order for the count to 
	be incremented. To ensure that all branches were covered, I allowed for 
	the number of cards to be counted (estates and coppers) to vary from 0 
	through the full hand, deck and discard piles. 
	
*** Boundary Coverage: To ensure that all branches and lines were covered, 
	I allowed for  the number of cards to be counted (estates and coppers) to 
	vary from 0 through the full hand, deck and discard piles.


unittest2 - discardCard()
-------------------------	 
The following is the unittestresults.out output for unittest2. Note that 
this data includes the execution of unittest1 and unittest2 together 
(cumulative data): 
	File 'dominion.c'
	Lines executed:19.34% of 574
	Branches executed:20.34% of 413
	Taken at least once:16.71% of 413
	Calls executed:7.37% of 95

*** Statement coverage: 88% of the lines were executed as indicated below: 
		function discardCard called 56 returned 100% blocks executed 88%

*** Branch Coverage: According to the dominion.c.gcov file, all of the 
	branches executed. For the first if block (line 1258) which checks if 
	the trashFlag is less than 1, branch 0 is executed 76% of the time. This 
	makes sense since the unit test passes the a 0 for the trashFlag 
	argument. The remaining 24% is likely from other tests (unittest3 
	through cardtest4). The second if block (line 1269) falls through branch 
	0 only 11% of the time. This is intentional as unittest2 tests 
	discarding of the last card at the end of the first inner for loop's 
	iterations of handPos in main of unittest2.c. Similarly, branch 0 of the 
	if block on line 1274 is taken only 12% of the time since the hand count 
	is 1 only at the beginning of the second inner for loop's iterations of 
	handCount in main of unittest2.c. Not surprisingly, most of the 
	executions are within the else block on line 1279 as unittest2 spends 
	most of its time testing hand positions and hand counts between 0 and 
	the maximum hand counts and positions. 
	I have attempted to create, using for loops, a situation where the else 
	if condition would evaluate to true, but for reasons I am unable to 
	determine, the statement inside this else if block does not execute.
	It seems as though the game state is always captured within the else block.	
		else if ( state->handCount[currentPlayer] == 1 ){
			state->handCount[currentPlayer]--;
		}
		
*** Boundary coverage:  unittest2 tests hand positions from 0 through the 
	current value of hand count, which spans the values 0 through 5. This 
	allows testing of discardCard() when there are no cards in the hand
	to discard.
	
unittest3 - isGameOver()
------------------------	  
The following is the unittestresults.out output for unittest2. Note that 
this data is cumulative, including the executions of unittest1, 
unittest2 and unittest3: 
	File 'dominion.c'
	Lines executed:20.91% of 574
	Branches executed:22.28% of 413
	Taken at least once:18.64% of 413
	Calls executed:7.37% of 95
	dominion.c:creating 'dominion.c.gcov'

*** Statement coverage: All lines were executed as there were no lines 
	with the #### notation, as noted below. function isGameOver called 22 
	returned 100% blocks executed 100% 

*** Branch Coverage: According to the dominion.c.gcov file, each branch 
	was executed to some degree. The first if block on line 394 shows that 
	91% of the time, branch 1 is taken. This means that branch 0 is only 
	taken 9% of the time. In unittest3, the game is only over when the 
	province cards have been depleted. It is decremented one by one until it 
	reaches a count of 0. It is for this reason that most of the time branch 
	1 is taken. In the succeeding for loop on line 402, 98% of the time, the 
	supply count is not 0, so this explains the 98% branch coverage for line 
	404. Finally on line 411, the situation where 3 supply counts is tested, 
	resulting in this branch being taken as well. 

*** Boundary Coverage: unittest3 tests the boundary case where the 
	province card count has been depleted to -1. While the isGameOver() 
	source code does not have specific logic to handle this boundary case, 
	its default is still to return 0 when none of the if blocks evaluate to 
	true. 



	
unittest4 - gainCard()
----------------------
The following is the unittestresults.out output for unittest2. This data 
shows cumulative coverage from unittest1, unittest2, unittest3 and 
unittest4 inclusive: 
	File 'dominion.c'
	Lines executed:23.69% of 574
	Branches executed:23.73% of 413
	Taken at least once:20.34% of 413
	Calls executed:8.42% of 95
	
*** Statement coverage: All lines were executed as there were no lines 
	with the #### notation, as noted below. function gainCard called 162 
	returned 100% blocks executed 100% Out of 162 executions, 102 resulted 
	in a return value of 0, and 60 resulted in a return value of -1 (card 
	not used). 

*** Branch Coverage: According to the dominion.c.gcov file, 
	all branches were covered. The first if block on line 1297 shows that 
	33% of the time, the supply did not contain the card to be gained. In 
	unittest4, the different gainCard() flags were also tested from 0 to 2. 
	According to the number of statement executions within the if, else if 
	and else block evaluating the toFlags, each block had exactly 34 
	executions. 

*** Boundary cases: Flags 0 through 2 were passed to 
	gainCard() and tested in unittest4. This explains why all of the 
	branches for the if statements that check the toFlag were taken. 
	unittest4 also tests the full range of supply cards from curse to 
	treasure_map cards. 


	
cardtest1 - smithyEffect()
--------------------------
The following is the unittestresults.out output for unittest2. This data 
shows cumulative coverage from unittest1, unittest2, unittest3, 
unittest4 and cardtest1 inclusive: 
	File 'dominion.c'
	Lines executed:24.56% of 574
	Branches executed:24.21% of 413
	Taken at least once:21.07% of 413
	Calls executed:10.53% of 95

*** Statement coverage: All lines were executed as there were no lines 
	with the #### notation, as noted below: 
		function smithyEffect called 2 returned 100% blocks executed 100% 

*** Branch Coverage: According to the dominion.c.gcov file, all branches 
	were covered. At the for loop in 75% of the time, branch 1 was taken and 
	the drawCard() function was called within the for loop body. *** 
	Boundary cases: In order to play a smithy card, or call the 
	smithyEffect() function, the player should have a smithy card in his/her 
	hand. Thus, each player was given a full hand of smithys to ensure that 
	smithyEffect() can be called. 

	
cardtest2 - adventurerEffect()
------------------------------
The following is the unittestresults.out output for unittest2. This data 
shows cumulative coverage from unittest1, unittest2, unittest3, 
unittest4, cardtest1 and cardtest2 inclusive: 
	File 'dominion.c'
	Lines executed:24.56% of 574
	Branches executed:24.21% of 413
	Taken at least once:21.07% of 413
	Calls executed:10.53% of 95

*** Statement coverage: All lines were executed as there were no lines 
	with the #### notation, as noted below. 
		function adventurerEffect called 6 returned 100% blocks executed 100%

*** Branch Coverage: According to the dominion.c.gcov file, all branches 
	were covered. The if statement on line 673 "if (cardDrawn == silver || 
	cardDrawn == gold)" was executed a total of 44 times. 

 
	*** BUG introduced to adventurerEffect() method *** 
		When evaluating the card
		that was drawn, a drawn copper card no longer increments drawntreasure.
		Namely, the line: 
		if (cardDrawn==copper || cardDrawn==silver || cardDrawn==gold) //original
			has been changed to: 
		if (cardDrawn == silver || cardDrawn == gold) //bug introduced

	Of note, 25% of those executions took branch 1 (silver), and 17% took 
	branch 2 (gold). This ratio makes sense - since due to a bug introduced 
	in Assignment 2, I needed to insert silver into the discard pile when 
	treasure card 4 (copper) was being tested in order to prevent an 
	infinite loop from occuring. Line 668 shows a shuffle of the deck if the 
	deckCount is below 1. In cardtest2, the deckCount was set to values 
	within the range 0 through 5. This forces the adventurerEffect() 
	function to call the shuffle method, thus, improving both branch and 
	statement coverage. 
  
*** Boundary coverage: Due to a bug introduced in Assignment 2, whenever 
	the treasure card is a copper card, the adventurerEffect() should be 
	caught in an infinite loop as it would be unable to find any coppers due 
	to initialization of the discard and deck with coppers. This is why the 
	copper tests have been commented out on line 62 of the cardtest2.c code, 
	and a discard pile of silvers were added to the copper test. 


cardtest3 - sea_hag case in cardEffect()
----------------------------------------
The following is the unittestresults.out output for unittest2. This data 
shows cumulative coverage from unittest1, unittest2, unittest3, 
unittest4, cardtest1, cardtest2 and cardtest3 inclusive: 
	File 'dominion.c'
	Lines executed:32.75% of 574
	Branches executed:34.14% of 413
	Taken at least once:26.15% of 413
	Calls executed:14.74% of 95
	
*** Statement coverage: All lines were in the sea_hag case were 
	executed. There were no lines with the #### notation, as noted below. 
	Because the sea_hag case is part of the cardEffect() method, the 
	coverage below shows the 10 blocks returned 100% blocks. 
		function cardEffect called 10 returned 100% blocks executed 9% 
	Because the sea_hag case is part of the cardEffect() method, the coverage 
	below shows 9% for the entire cardEffect() method. The .gcov file shows that 
	all of the lines of the sea_hag case were executed. 

*** Branch Coverage: According to the dominion.c.gcov file, all branches were 
	covered. The branch at the second fallthrough shows 50% branch coverage 
	for each of the two branches on line 1212. This makes sense as there are 
	only two players, and only one player (i.e. the opponent) takes that branch. 


*** Boundary coverage: The only boundary case not tested here is 
	if the deck was empty. However, this would not be possible in a real 
	game as the deck is always replenished (by drawCard) before each turn. 


cardtest4 - steward case in cardEffect
--------------------------------------
The following is the unittestresults.out output for unittest2. This data 
shows cumulative coverage from unittest1, unittest2, unittest3, 
unittest4, cardtest1, cardtest2, cardtest3 and cardtest4 inclusive: 
	File 'dominion.c'
	Lines executed:34.49% of 574
	Branches executed:35.11% of 413
	Taken at least once:27.60% of 413
	Calls executed:20.00% of 95

*** Statement coverage: All lines in the steward case of cardEffect() 
	were executed. There were no lines with the #### notation. 
		function cardEffect called 10 returned 100% blocks executed 9%
	The steward case is part of the cardEffect() method, the coverage below 
	shows 9% for the entire cardEffect() method. The .gcov file shows that 
	all of the lines of the steward case were executed. 

***	Branch Coverage: 2 of 8 executions branched to choice1==1, 2 of 8 
	executions branched to choice1==2, and the remainder branched to 
	choice1==0 or 4, resulting in all branches being covered.

*** Boundary coverage: The following choice1 values were tested: 
	choice1==0, choice1==1, choice1==2, choice1==3, and choice1==4. 
	Values 0 and 4 are outside of the bounds of choice1, and are captured 
	by the else block starting on line 1018.