/*
*	CS362 - Assignment 3 - coverage.c
*	Author: Carol D. Toro
*	Date: 10/24/2015
*/


Coverage.c

unittest1.c: updateCoins() method

	Coverage of dominion.c file:
			File 'dominion.c'
			Lines executed:15.41% of 597
			Branches executed:15.46% of 427
			Taken at least once:13.11% of 427
			Calls executed:7.29% of 96
			dominion.c:creating 'dominion.c.gcov'

	While this unit test appears to have really low coverage of the dominion.c file,
	when looking at the function coverage it did very well. When it was called
	100% blocks returned, and 100% executed. 

unittest2.c: isGameOver() method

	Coverage of dominion.c file:
			File 'dominion.c'
			Lines executed:23.12% of 597
			Branches executed:27.17% of 427
			Taken at least once:18.50% of 427
			Calls executed:12.50% of 96
			dominion.c:creating 'dominion.c.gcov'

	While this unit test had better coverage of the dominion file, it is still 
	relatively low when only 23% of lines were covered. In regards to function
	coverage, it was called 14 times, returned 100% blocks executed 100%. 

unittest3.c : discardCard() method

	Coverage of dominion.c file:
			File 'dominion.c'
			Lines executed:25.29% of 597
			Branches executed:28.57% of 427
			Taken at least once:19.91% of 427
			Calls executed:12.50% of 96
			dominion.c:creating 'dominion.c.gcov'

	function discardCard called 638 returned 100% blocks executed 100%

			      638: 1193:  if ( handPos == (state->handCount[currentPlayer] - 1) ) 	//last card in hand array is played
		branch  0 taken 1% (fallthrough)
		branch  1 taken 99%

		      636: 1198:  else if ( state->handCount[currentPlayer] == 1 ) //only one card in hand
		branch  0 taken 1% (fallthrough)
		branch  1 taken 99%



unittest4.c : 	playCard() method


	Coverage of dominion.c file:
			File 'dominion.c'
			Lines executed:37.86% of 597
			Branches executed:39.58% of 427
			Taken at least once:26.00% of 427
			Calls executed:26.04% of 96
			dominion.c:creating 'dominion.c.gcov'


	function playCard called 32 returned 100% blocks executed 93%

			 30:  262:  if ( card < adventurer || card > treasure_map )
			branch  0 taken 97% (fallthrough)
			branch  1 taken 3%
			branch  2 taken 0% (fallthrough) 

	to improve the coverage i could have called the function with a province

			 29:  268:  if ( cardEffect(card, choice1, choice2, choice3, state, handPos, &coin_bonus) < 0 )
			call    0 returned 100%
			branch  1 taken 0% (fallthrough)
			branch  2 taken 100%
			        -:  269:    {
			    #####:  270:      return -1;
			        -:  271:    }


cardtest1.c 	: smithyCard()

	Coverage of dominion.c file:
			File 'dominion.c'
			Lines executed:38.02% of 597
			Branches executed:39.58% of 427
			Taken at least once:26.23% of 427
			Calls executed:26.04% of 96
			dominion.c:creating 'dominion.c.gcov'

	function smithyCard called 9 returned 100% blocks executed 100%




cardtest2.c: adventurerCard()

	Coverage of dominion.c file:
			File 'dominion.c'
			Lines executed:41.21% of 597
			Branches executed:42.86% of 427
			Taken at least once:29.04% of 427
			Calls executed:28.13% of 96
			dominion.c:creating 'dominion.c.gcov'

	function adventurerCard called 6 returned 100% blocks executed 88%


cardtest3.c: councilRoomCard()
	
	Coverage of dominion.c file:
			File 'dominion.c'
			Lines executed:43.55% of 597
			Branches executed:44.73% of 427
			Taken at least once:31.15% of 427
			Calls executed:32.29% of 96
			dominion.c:creating 'dominion.c.gcov'

	function council_roomCard called 7 returned 100% blocks executed 100%


cardtest4.c : GreatHallCard()

	Coverage of dominion.c file:
			File 'dominion.c'
			Lines executed:45.06% of 597
			Branches executed:45.20% of 427
			Taken at least once:31.85% of 427
			Calls executed:35.42% of 96
			dominion.c:creating 'dominion.c.gcov'

		function great_hallCard called 7 returned 100% blocks executed 100%