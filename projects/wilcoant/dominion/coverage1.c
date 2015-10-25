/********************************************************************
**
Anthony Wilcox
CS362
Fall 2015
For the purposes of this document, "Lines executed" refers to the entire
dominion.c file, percentages given of statements and branch are for the
FUNCTION ITSELF.  The code segments underneath the "Lines Executed" 
percentage for each test are excerpts from dominion.c.gcov as they 
pertain to the individual unit tests.  Analysis is underneath each 
code segment.
***********************************************************************
Unittest1: getCost
coverage dominion.c: 
Lines executed 5.13% of 585
***********************************************************************
 28:  583:int getCost(int cardNumber)
        -:  584:{
       28:  585:  switch( cardNumber ) 
        -:  586:    {
        -:  587:    case curse:
        1:  588:      return 0;
        -:  589:    case estate:
        1:  590:      return 2;
        -:  591:    case duchy:
        1:  592:      return 5;
        -:  593:    case province:
        1:  594:      return 8;
        -:  595:    case copper:
        1:  596:      return 0;
        -:  597:    case silver:
        1:  598:      return 3;
        -:  599:    case gold:
        1:  600:      return 6;
        -:  601:    case adventurer:
        1:  602:      return 6;
        -:  603:    case council_room:
        1:  604:      return 5;
        -:  605:    case feast:
        1:  606:      return 4;
        -:  607:    case gardens:
        1:  608:      return 4;
        -:  609:    case mine:
        1:  610:      return 5;
        -:  611:    case remodel:
        1:  612:      return 4;
        -:  613:    case smithy:
        1:  614:      return 4;
        -:  615:    case village:
        1:  616:      return 3;
        -:  617:    case baron:
        1:  618:      return 4;
        -:  619:    case great_hall:
        1:  620:      return 3;
        -:  621:    case minion:
        1:  622:      return 5;
        -:  623:    case steward:
        1:  624:      return 3;
        -:  625:    case tribute:
        1:  626:      return 5;
        -:  627:    case ambassador:
        1:  628:      return 3;
        -:  629:    case cutpurse:
        1:  630:      return 4;
        -:  631:    case embargo: 
        1:  632:      return 2;
        -:  633:    case outpost:
        1:  634:      return 5;
        -:  635:    case salvager:
        1:  636:      return 4;
        -:  637:    case sea_hag:
        1:  638:      return 4;
        -:  639:    case treasure_map:
        1:  640:      return 4;
        -:  641:    }
        -:  642:	
        1:  643:  return -1;
        -:  644:}

***********************************************************************
statement: 100%
branch:100%
boundary: boundary cases execute once meaning a return value of -1 does 
occur for a card passed to the function that isn't in the hand.  
Implications: 
Proper values return from the function and all values were 
checked.  In this case good coverage appears to be a good metric that 
aligns with positive test results.  Methodology supports this since integer
values were used rather than the enumerated strings as they will be passed
inside the game as integers.  All enumerated values were checked as integers
vs their corresponding value in the treasure_map array.

***********************************************************************


Unittest2: drawCard
coverage dominion.c:
Lines executed 21.71% of 585
***********************************************************************
1972:  525:int drawCard(int player, struct gameState *state)
        -:  526:{	int count;
        -:  527:  int deckCounter;
     1972:  528:  if (state->deckCount[player] <= 0){//Deck is empty
        -:  529:    
        -:  530:    //Step 1 Shuffle the discard pile back into a deck
        -:  531:    int i;
        -:  532:    //Move discard to deck
    #####:  533:    for (i = 0; i < state->discardCount[player];i++){
    #####:  534:      state->deck[player][i] = state->discard[player][i];
    #####:  535:      state->discard[player][i] = -1;
        -:  536:    }
        -:  537:
    #####:  538:    state->deckCount[player] = state->discardCount[player];
    #####:  539:    state->discardCount[player] = 0;//Reset discard
        -:  540:
        -:  541:    //Shufffle the deck
    #####:  542:    shuffle(player, state);//Shuffle the deck up and make it so that we can draw
        -:  543:   
    #####:  544:    if (DEBUG){//Debug statements
        -:  545:      printf("Deck count now: %d\n", state->deckCount[player]);
        -:  546:    }
        -:  547:    
    #####:  548:    state->discardCount[player] = 0;
        -:  549:
        -:  550:    //Step 2 Draw Card
    #####:  551:    count = state->handCount[player];//Get current player's hand count
        -:  552:    
    #####:  553:    if (DEBUG){//Debug statements
        -:  554:      printf("Current hand count: %d\n", count);
        -:  555:    }
        -:  556:    
    #####:  557:    deckCounter = state->deckCount[player];//Create a holder for the deck count
        -:  558:
    #####:  559:    if (deckCounter == 0)
    #####:  560:      return -1;
        -:  561:
    #####:  562:    state->hand[player][count] = state->deck[player][deckCounter - 1];//Add card to hand
    #####:  563:    state->deckCount[player]--;
    #####:  564:    state->handCount[player]++;//Increment hand count
        -:  565:  }
        -:  566:
        -:  567:  else{
     1972:  568:    int count = state->handCount[player];//Get current hand count for player
        -:  569:    int deckCounter;
     1972:  570:    if (DEBUG){//Debug statements
        -:  571:      printf("Current hand count: %d\n", count);
        -:  572:    }
        -:  573:
     1972:  574:    deckCounter = state->deckCount[player];//Create holder for the deck count
     1972:  575:    state->hand[player][count] = state->deck[player][deckCounter - 1];//Add card to the hand
     1972:  576:    state->deckCount[player]--;
     1972:  577:    state->handCount[player]++;//Increment hand count
        -:  578:  }
        -:  579:
     1972:  580:  return 0;
        -:  581:}

***********************************************************************
statement: 50%
branch: 50%
boundary: 50%
Implications: 
Coverage here isn't as misleading as it may seem.  The function
gets called over 1900 times and runs without error as to its pre and post 
conditions for deck counts, player draw counts et... The 50% comes from 
the condition that the deck is empty.  This occurs infrequently but normal
game iteration through 1900 + iterations didn't make this happen.  This may
be due to a flaw in discardCard.  Of note, however, is that attempting to 
force manual entry into that branch causes a core abort.  In other words, 
I rewrote the test to manually pass an empty deck into the function and the 
program core dumps.  For this reason I left this code commented out and branch
coverage at 50% since the branches covered account for at least 80% of actual
game play.  Integration testing needs to account for proper passing of an 
empty deck into drawCard in case other variables in conjunction with the empty
deck caused the crash.  discardCard may be the culprit.  In the end, in this case,
code coverage was a great indicator that the test case needed to be revised.
***********************************************************************


Unittest3: scoreFor
coverage dominion.c:
Lines executed 27.35% of 585
***********************************************************************
  27:  417:int scoreFor (int player, struct gameState *state) {
        -:  418:
        -:  419:  int i;
       27:  420:  int score = 0;
        -:  421:  //score from hand
      729:  422:  for (i = 0; i < state->handCount[player]; i++)
        -:  423:    {
      702:  424:      if (state->hand[player][i] == curse) { score = score - 1; };
      702:  425:      if (state->hand[player][i] == estate) { score = score + 1; };
      702:  426:      if (state->hand[player][i] == duchy) { score = score + 3; };
      702:  427:      if (state->hand[player][i] == province) { score = score + 6; };
      702:  428:      if (state->hand[player][i] == great_hall) { score = score + 1; };
      702:  429:      if (state->hand[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, state) / 10 ); };
        -:  430:    }
        -:  431:
        -:  432:  //score from discard
      729:  433:  for (i = 0; i < state->discardCount[player]; i++)
        -:  434:    {
      702:  435:      if (state->discard[player][i] == curse) { score = score - 1; };
      702:  436:      if (state->discard[player][i] == estate) { score = score + 1; };
      702:  437:      if (state->discard[player][i] == duchy) { score = score + 3; };
      702:  438:      if (state->discard[player][i] == province) { score = score + 6; };
      702:  439:      if (state->discard[player][i] == great_hall) { score = score + 1; };
      702:  440:      if (state->discard[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, state) / 10 ); };
        -:  441:    }
        -:  442:
        -:  443:  //score from deck
      729:  444:  for (i = 0; i < state->discardCount[player]; i++)
        -:  445:    {
      702:  446:      if (state->deck[player][i] == curse) { score = score - 1; };
      702:  447:      if (state->deck[player][i] == estate) { score = score + 1; };
      702:  448:      if (state->deck[player][i] == duchy) { score = score + 3; };
      702:  449:      if (state->deck[player][i] == province) { score = score + 6; };
      702:  450:      if (state->deck[player][i] == great_hall) { score = score + 1; };
      702:  451:      if (state->deck[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, state) / 10 ); };
        -:  452:    }
        -:  453:
       27:  454:  return score;

***********************************************************************
statement: 100%
branch: 100%
boundary: 100%
Implications: Testing did not reveal bugs and gcov line examination shows 
execution of all branches and conditions.  Variables were used to calculate
and compare correct scoring tabulation.  The lack of bug detection along with 
statement and branch coverage along with sufficient border coverage to exercise
all paths indicates that coverage is a good metric of solid testing in this
case. 
***********************************************************************


Unittest4: isGameOver
coverage dominion.c:
Lines executed 27.86% of 585
***********************************************************************
 -:  389:
        2:  390:int isGameOver(struct gameState *state) {
        -:  391:  int i;
        -:  392:  int j;
        -:  393:	
        -:  394:  //if stack of Province cards is empty, the game ends
        2:  395:  if (state->supplyCount[province] == 0)
        -:  396:    {
        1:  397:      return 1;
        -:  398:    }
        -:  399:
        -:  400:  //if three supply pile are at 0, the game ends
        1:  401:  j = 0;
       26:  402:  for (i = 0; i < 25; i++)
        -:  403:    {
       25:  404:      if (state->supplyCount[i] == 0)
        -:  405:	{
       24:  406:	  j++;
        -:  407:	}
        -:  408:    }
        1:  409:  if ( j >= 3)
        -:  410:    {
        1:  411:      return 1;
        -:  412:    }

***********************************************************************
statement: Originally 50% revised to get 100%
branch: Originally 50% revised to get 100%
boundary: 100%
Implications:  
This test was run to pass empty piles of all cards that weren't 
province and then explicitly and separately and empty stack of province cards.
Original examination of gcov data indicated that empty province piles were being
properly evaluated and covered, however any other empty pile wasn't executed.
The test was updated to make this branch execute.  The satisfactory completion
of the tests without location of new bugs indicates that the covereage in this 
case being 100% graph coverage for the function is a good metric.  Lack of bug 
discovery and low raw numbers of execution over all iterations indicates a possible
need for more elaborate and out of boundary testing.
***********************************************************************


cardtest1: smithy
coverage dominion.c:
Lines executed 30.6% of 585
***********************************************************************
54:  674:int play_smithy(int currentPlayer, struct gameState *state, int handPos)
        -:  675:{
        -:  676:    int i;
        -:  677:   //+3 Cards
      216:  678:      for (i = 0; i < 3; i++)
        -:  679:	{
      162:  680:	  drawCard(currentPlayer, state);
        -:  681:	}
        -:  682:			
        -:  683:      //discard card from hand
       54:  684:      discardCard(handPos, currentPlayer, state, 0);
       54:  685:      return 0;

***********************************************************************
statement: 100%
branch: 100%
boundary: 100%
Implications: Code coverage over the play smithy card function was 100% in that
all lines and branches were executed.  This test did reveal bugs so in this case,
the code coverage doesn't tell me much more than that the current test case
revealed bugs and is testing the play_smithy function.  Revision of the
play_smithy function and further testing along with integration testing and second
order effects of the smithy card following revision based on the bugs that
were located seems to be necessary in this case since we have known bugs.  
***********************************************************************

cardtest2: adventurer
coverage dominion.c:
Lines executed 33.68% of 585
***********************************************************************
54:  645:int play_adventurer(struct gameState *state, int currentPlayer, int *temphand)
        -:  646:{
       54:  647:    int drawntreasure = 0; //counter for treasure cards 
        -:  648:    int cardDrawn; //temp card drawn var 
       54:  649:    int z = 0; //counter for temp hand 
       54:  650:    int y = 0; //test counter var 
        -:  651:    //int k[10] = {&z, &drawntreasure, &y}; //counters for testing
        -:  652:     
      264:  653:    while(drawntreasure<2){
      156:  654:	if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
    #####:  655:	  shuffle(currentPlayer, state);
        -:  656:	}
      156:  657:	drawCard(currentPlayer, state);
      156:  658:    y++; //test counter var 
      156:  659:	cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
      264:  660:	if (cardDrawn == copper || (cardDrawn == silver && cardDrawn == gold))
      108:  661:	  drawntreasure++;
        -:  662:	else{
       48:  663:	  temphand[z]=cardDrawn;
       48:  664:	  state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
       48:  665:	  z++;
        -:  666:	}
        -:  667:      }
      156:  668:      while(z-1>=0){
       48:  669:	state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
       48:  670:	z=z-1;
        -:  671:      }
       54:  672:      return (z + drawntreasure) - y; //return 0 if not testing 
***********************************************************************
statement: 100%
branch: 90%
boundary: 90%
Implications: The implications for coverage here are the same as was for the 50% 
in drawCard.  The line not being executed is the function call to shuffle which 
only occurs when the deck is empty.  Game play has shown me that this should occur
but the adventurer card is not the culprit for the deck never being empty.  It is properly evaluating the if condition and moving on.  This second function besides 
drawCard that has had hundreds of iterations run through it with different gamestate
possibilities and still never ends up with an empty deck indicates to me that 
there must be an issue in discardCard or some other gameState function that
adjudicates that state of the game in between turns.  
Aside form this issue, the remainder of the code coverage did reveal bugs so it 
has been a good metric for me in both regards.  The combination of drawCard and adventurer never arriving at an empty deck on their own indicate another unfound bug
which I found by attempting to increase code coverage to force an empty deck.
***********************************************************************
cardtest3: council_room 
coverage dominion.c:
Lines executed 35.90% of 585
***********************************************************************
  45:  717:int play_council(struct gameState *state, int currentPlayer, int handPos)
        -:  718:{
        -:  719:    int i; 
       45:  720:    int x = 0; //testing vars 
       45:  721:    int y = 0; //testing vars 
        -:  722:  //+4 Cards
      225:  723:      for (i = 0; i < 4; i++)
        -:  724:	{
      180:  725:      x++; //testing 
      180:  726:	  drawCard(currentPlayer, state);
        -:  727:	}
        -:  728:			
        -:  729:      //+1 Buy
        -:  730:      //state->numBuys++;
        -:  731:			
        -:  732:      //Each other player draws a card
      190:  733:      for (i = 0; i < state->numPlayers; i++)
        -:  734:	{ 
      145:  735:	  if ( i != currentPlayer )
        -:  736:	    {
      100:  737:	      drawCard(i, state);
      100:  738:          y++; //testing 
        -:  739:	    }
        -:  740:	}
        -:  741:			
        -:  742:      //put played card in played card pile
       45:  743:      discardCard(handPos, currentPlayer, state, 0);
        -:  744:	 //x + y gives value 4 + number of of other players if functioning properly	
       45:  745:      return x + y; //return 0 if not testing     
        -:  746:}

***********************************************************************
statement:100%
branch: 100%
boundary: 100%
Implications: 
The code coverage in this case having executed all statements and branches
has revealed a bug that has been documented.  In this case since we were 
successful in revealing a bug it appears that good coverage has indicated
good testing.  Resolution of the bug and further testing followed by integration
testing will reveal whether or not this implication is correct in that we
have found one known bug, there may be more that further testing may reveal 
once regression analysis begins following resolution of the bug. 
***********************************************************************

Unittest4: village
coverage dominion.c:
Lines executed 36.92% of 585
***********************************************************************
 45:  747:int play_village(int currentPlayer, int handPos, struct gameState *state)
        -:  748:{
        -:  749:     
        -:  750:    //+1 Card
       45:  751:      drawCard(currentPlayer, state);
        -:  752:	
        -:  753:      //+2 Actions
       45:  754:      state->numActions = state->numActions + 2;
        -:  755:			
        -:  756:      //discard played card from hand
       45:  757:      discardCard(handPos, currentPlayer, state, 0);
       45:  758:      return 0;  //return 0 if not testing 
        -:  759:}

***********************************************************************
statement:100%
branch: 100%
boundary: 100%
Implications:
Code coverage in this case may not be a great indication of testing efficacy.
No bugs were detected, but bugs in adventurer and drawCard indicate that 
dicardCard, which gets called 45 times in this test, may have a bug.  Unit testing
of play_village itself is behaving properly in the pre and post conditions 
that are expected, but discardCard may require regression and therefore regression
testing may reveal problems.  On its surface and in code examination, it appears 
that play_village itself is ok and if there are existing undetected bugs, they
are inside of helper function calls discardCard or drawCard where we have a known
bug when the deck reaches 0.
******************************************************************************/