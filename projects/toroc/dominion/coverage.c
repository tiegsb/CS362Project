/*
*	CS362 - Assignment 3 - coverage.c
*	Author: Carol D. Toro
*	Date: 10/24/2015
*/


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
	While branch coverage for this method was 100%, the coverage was very 
	disproportional. For the branch on line 1193, I took branch 0 just 1% of the time,
	same with the branch on line 1198, which was also taken 1% of the time. 
	These were covered specifically when the last card in a hand array was 
	played or when there was only one card in the hand. 


unittest4.c : 	playCard() method

	Coverage of dominion.c file:
			File 'dominion.c'
			Lines executed:37.86% of 597
			Branches executed:39.58% of 427
			Taken at least once:26.00% of 427
			Calls executed:26.04% of 96
			dominion.c:creating 'dominion.c.gcov'

	As expected, coverage of dominion.c kept improving as I ran more tests
	that would execute different parts of the file. For this method that
	I tested, I was unable to achieve 100% block coverage. Only 93% of blocks
	executed. To further improve the coverage, I could call the function
	with enums that are lower than treasure_map.

	function playCard called 32 returned 100% blocks executed 93%

		 30:  262:  if ( card < adventurer || card > treasure_map )
			branch  0 taken 97% (fallthrough)
			branch  1 taken 3%
			branch  2 taken 0% (fallthrough) 

	Furthermore, I could have improved coverage for branch 1 on line 268
	by calling cardEffect with an enum that would result in less than 0.

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

	Funcion coverage of the smithyCard implementation was 100%.
	I was also able to trigger the bug I inserted.

	function smithyCard called 9 returned 100% blocks executed 100%


cardtest2.c: adventurerCard()

	Coverage of dominion.c file:
			File 'dominion.c'
			Lines executed:41.21% of 597
			Branches executed:42.86% of 427
			Taken at least once:29.04% of 427
			Calls executed:28.13% of 96
			dominion.c:creating 'dominion.c.gcov'

	It was disappointing when I quickly realized that the bug I had
	inserted into this card would never fire as I made it a branch that
	can never get triggered as an else if since it will always get triggerered
	by the first if. Hence, 88% of blocks executed since it is impossible
	to penetrate the ele if statement where my bug resides.

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

	Branch coverage in general was not too disproportional: 

	35: 1392:      for ( i = 0; i < 4; i++)
		branch  0 taken 80%
		branch  1 taken 20% (fallthrough)

	7: 1400:	if  (cardDrawn == gold)
		branch  0 taken 29% (fallthrough)
		branch  1 taken 71%

	21: 1408:      for (i = 0; i < state->numPlayers; i++)
		branch  0 taken 67%
		branch  1 taken 33% (fallthrough)

	14: 1410:	  if ( i != currentPlayer )
		branch  0 taken 50% (fallthrough)
		branch  1 taken 50%



cardtest4.c : GreatHallCard()

	Coverage of dominion.c file:
			File 'dominion.c'
			Lines executed:45.06% of 597
			Branches executed:45.20% of 427
			Taken at least once:31.85% of 427
			Calls executed:35.42% of 96
			dominion.c:creating 'dominion.c.gcov'

	While function great_hallCard called 7 returned 100% blocks executed 100%,
	this only increased overall domininion.c line coverage by 2%.
	Branch coverage for line 1376 was a bit disproportional as
	I only took branch 0 14% of the time. 


	7: 1376:	  if (state->deckCount[currentPlayer]<2)
		branch  0 taken 14% (fallthrough)
		branch  1 taken 86%


cardtest5.c : VillageCard()

	Coverage of dominion.c file:
			File 'dominion.c'
			Lines executed:46.57% of 597
			Branches executed:45.67% of 427
			Taken at least once:32.55% of 427
			Calls executed:39.58% of 96
			dominion.c:creating 'dominion.c.gcov'

		function villageCard called 7 returned 100% blocks executed 100%

	
	In order to improve overall file coverage for dominion.c I will need to attempt
	to call all internal functions by perhaps simulating a game between players. 
	Of course, I will need to make sure that all types of cards get played so that
	line coverage is considerable improved in the cardEffect function.