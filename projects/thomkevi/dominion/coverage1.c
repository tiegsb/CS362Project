Coverage results from the unittest and cardtests are as follows:

  unittest1.c:
  TESTING discardCard():
  Lines executed:17.70% of 582
  dominion.c:creating 'dominion.c.gcov'

  unittest2.c:
  TESTING gainCard():
  Lines executed:18.04% of 582
  dominion.c:creating 'dominion.c.gcov'

  unittest3.c:
  TESTING getCost():
  Lines executed:4.98% of 582
  dominion.c:creating 'dominion.c.gcov'

  unittest4.c:
  TESTING whoseTurn():
  Lines executed:20.45% of 582
  dominion.c:creating 'dominion.c.gcov'

  cardtest1.c:
  TESTING playVillage():
  Lines executed:19.93% of 582
  dominion.c:creating 'dominion.c.gcov'

  cardtest2.c:
  TESTING playCouncilRoom():
  Lines executed:20.62% of 582
  dominion.c:creating 'dominion.c.gcov'

  cardtest3.c:
  TESTING playSmithy():
  Lines executed:19.93% of 582
  dominion.c:creating 'dominion.c.gcov'

  cardtest4.c:
  TESTING playAdventurer():
  Lines executed:19.07% of 582
  dominion.c:creating 'dominion.c.gcov'

The coverage tests above provide data for the coverage of each individual unit test.
In order to provide coverage metrics for the full set of unittests and cardtests,
the dominion.c.gocv data was captured for each individual unit test file execution and
aggregated in excel.  The results show near 50% coverage of the code which is better than
the above data shows but still leaves much room for improvement.

By the numbers:
  1345 Lines of Code
  798 Lines that are not significant (e.g. comments)
  376 Lines of executable code that are not covered by any of the unit tests above.
  171 Lines of executable code that is covered
  31.2% coverage
  
Analysis shows the following functions are not covered by current unit tests:
  newGame()
  kingdomCards()
  playCard()
  numHandCards()
  handCard()
  fullDeckCount()
  isGameOver()
  scoreFor()
  getWinners()
  cardEffect()
  playRemodel()
  
Analysis shows one function that has a unit tests but does not have full coverage:
  playAdventurer() - Don't reach empty deck or draw down card other than copper.
                     Additional game play in the unit test would be required to meet the
                     empty deck criteria.  Or staging the data such that the empty deck
                     criteria is hit in a controlled manner.
                     
Testing style
 unit tests - unittest1.c,unittest2.c, unittest3.c, and unittest4.c
              These tests were designed to hit all conditions and go down every possible
              branch.
              
 card tests - cardtest1.c, cardtest2.c,cardtest3.c, and cardtest4.c
              These tests were designed to play a card and validate the proper outcome
              as in the correct number of cards are in the hand, been discarded, and
              number of buys and actions updated appropriately for the card type.
              There is an opportunity to further strengthen the test sets for these cards
              especially for the adventurer card which doesnt have full coverage based
              on gcov analysis.
  
  
  

  
  
  
  
  
  