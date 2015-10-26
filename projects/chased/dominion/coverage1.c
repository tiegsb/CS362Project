/*
File: coverage1.c
Author: Dustin Chase
Email: chased@oregonstate.edu
Date: 10/25/15
Description: Discussion of coverage results for unit test of dominion.c
*/

/*Results for testing smithy card:*/
/*Excerpt from dominion.c.gcov:  	 
	 3000:  229:void playSmithy(struct gameState *state, int handPos) {
        -:  230:	
        -:  231:	int i; //loop counter
     3000:  232:	int currentPlayer = whoseTurn(state);
     9000:  233:	for (i = 0; i < 2; i++)
        -:  234:	{
     6000:  235:	  drawCard(currentPlayer, state);
        -:  236:	}
        -:  237:			
        -:  238:    //discard card from hand
     3000:  239:    discardCard(handPos, currentPlayer, state, 0);
*****************************************************************************/
Statement: 100%
Branch: 100%
Boundary:100%
Discussion: Every line and branch in the smithy function was executed. The testing revealed that 
there was a major bug in this function. The full coverage of this function and subsequent review
of the game state after this code was run were enough to find the issue with this function. 
/*Results for testing remodel card*/
/*Excerpt from dominion.c.gcov*/ 
    3000:  320:void playRemodel(struct gameState *state, int choice1, int choice2, int handPos) {
     3000:  321:	int currentPlayer = whoseTurn(state);
     3000:  322:	int j = state->hand[currentPlayer][choice1];  //store card we will trash
        -:  323:    int i; //loop counter
     3000:  324:    gainCard(choice2, state, 0, currentPlayer);
        -:  325:
        -:  326:      //discard card from hand
     3000:  327:    discardCard(handPos, currentPlayer, state, 0);
        -:  328:
        -:  329:      //discard trashed card
     3589:  330:     for (i = 0; i < state->handCount[currentPlayer]; i++)
        -:  331:	{
     1344:  332:	  if (state->hand[currentPlayer][i] == j)
        -:  333:	    {
      755:  334:	      discardCard(i, currentPlayer, state, 0);			
      755:  335:	      break;
        -:  336:	    }
        -:  337:	}
     3000:  338:}
*****************************************************************************/
Statement: 100%
Branch: 100%
Boundary:100%
Discussion: Every line and branch in the remodel function was executed. The boundary cases were checked carefully
to make sure these would execute as required in each case. There was a need to iterate through the function many times
to look at the different situations that could come up, but there was sufficient variation in the cases so we could feel
the function performs as needed.   
/*Results for testing council room card*/ 
/*Excerpt from dominion.c.gcov*/
        4:  243:void playCouncilRoom(struct gameState *state, int handPos) {
        -:  244:	int i; //loop counter
        4:  245:	int currentPlayer = whoseTurn(state);
       20:  246:	for (i = 0; i < 4; i++)
        -:  247:	{
       16:  248:	  drawCard(currentPlayer, state);
        -:  249:	}
        -:  250:			
        4:  251:      state->numBuys += 2;
        -:  252:			
        -:  253:      //Each other player draws a card
       20:  254:      for (i = 0; i < state->numPlayers; i++)
        -:  255:	{
       16:  256:	  if ( i != currentPlayer )
        -:  257:	    {
       12:  258:	      drawCard(i, state);
        -:  259:	    }
        -:  260:	}
        -:  261:			
        -:  262:      //put played card in played card pile
        4:  263:      discardCard(handPos, currentPlayer, state, 0);
        4:  264:}
*****************************************************************************/
Statement: 100%
Branch: 100%
Boundary:100%
Discussion: The council room function was thoroughly executed and every statement and branch was executed. 
This testing revealed a big which was documented. There was good code coverage but looking at the final game state
was what revealed the problem in this function.  
/*Results from testing adventurer card*/
/*Excerpt from dominion.c.gcov*/ 
       10:  202:void playAdventurer(struct gameState *state) {
       10:  203:	int drawntreasure = 0;
       10:  204:	int cardDrawn = 0; 
       10:  205:	int z = 0; //counter for temp hand
        -:  206:	int temphand[MAX_HAND];
       10:  207:	int currentPlayer = whoseTurn(state);
      288:  208:	  while(drawntreasure < 2){
      268:  209:	if (state->deckCount[currentPlayer] < 1){//if the deck is empty we need to shuffle discard and add to deck
    #####:  210:	  shuffle(currentPlayer, state);
        -:  211:	}
      268:  212:	drawCard(currentPlayer, state);
      268:  213:	cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
      288:  214:	if (cardDrawn == copper || cardDrawn == silver)
       20:  215:	  drawntreasure++;
        -:  216:	else{
      248:  217:	  temphand[z]=cardDrawn;
      248:  218:	  state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
      248:  219:	  z++;
        -:  220:	}
        -:  221:      }
      268:  222:      while(z-1>=0){
      248:  223:	state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
      248:  224:	z=z-1;
        -:  225:      }
        -:  226:	
       10:  227:}
*****************************************************************************/
Statement: 90%
Branch: 90%
Boundary:90%
Discussion: This function did not acheive full code coverage as the other tests did. The case with the empty deck was not tested. 
This is considered a boundary case and it should have been considered in the testing. Although 2 major bugs were found in this function, 
reviewing this boundary case would have improved the testing and I would look for a way to do this in the future. 
/*Results from testing updateCoins()*/
/*Excerpt from dominion.c.gcov*/
 9017: 1329:int updateCoins(int player, struct gameState *state, int bonus)
        -: 1330:{
        -: 1331:  int i;
        -: 1332:	
        -: 1333:  //reset coin count
     9017: 1334:  state->coins = 0;
        -: 1335:
        -: 1336:  //add coins for each Treasure card in player's hand
    54102: 1337:  for (i = 0; i < state->handCount[player]; i++)
        -: 1338:    {
    45085: 1339:      if (state->hand[player][i] == copper)
        -: 1340:	{
    24240: 1341:	  state->coins += 1;
        -: 1342:	}
    20845: 1343:      else if (state->hand[player][i] == silver)
        -: 1344:	{
      179: 1345:	  state->coins += 2;
        -: 1346:	}
    20666: 1347:      else if (state->hand[player][i] == gold)
        -: 1348:	{
      197: 1349:	  state->coins += 3;
        -: 1350:	}	
        -: 1351:    }	
        -: 1352:
        -: 1353:  //add bonus
     9017: 1354:  state->coins += bonus;
        -: 1355:
     9017: 1356:  return 0;
        -: 1357:}
*****************************************************************************/
Statement: 100%
Branch: 100%
Boundary:100%
Discussion: This function did acheive full statement, branch and boundary case coverage. With sufficient exercising of 
the code in different situations, it could be shown that this function does not have any bugs. 
/*Results from testing getCost() */
/*Excerpt from dominion.c.gcov*/
 3007:  722:int getCost(int cardNumber)
        -:  723:{
     3007:  724:  switch( cardNumber ) 
        -:  725:    {
        -:  726:    case curse:
      131:  727:      return 0;
        -:  728:    case estate:
      110:  729:      return 2;
        -:  730:    case duchy:
      112:  731:      return 5;
        -:  732:    case province:
      107:  733:      return 8;
        -:  734:    case copper:
      112:  735:      return 0;
        -:  736:    case silver:
      113:  737:      return 3;
        -:  738:    case gold:
      125:  739:      return 6;
        -:  740:    case adventurer:
      115:  741:      return 6;
        -:  742:    case council_room:
       98:  743:      return 5;
        -:  744:    case feast:
      111:  745:      return 4;
        -:  746:    case gardens:
      113:  747:      return 4;
        -:  748:    case mine:
      115:  749:      return 5;
        -:  750:    case remodel:
      113:  751:      return 4;
        -:  752:    case smithy:
      116:  753:      return 4;
        -:  754:    case village:
      122:  755:      return 3;
        -:  756:    case baron:
       97:  757:      return 4;
        -:  758:    case great_hall:
      118:  759:      return 3;
        -:  760:    case minion:
       88:  761:      return 5;
        -:  762:    case steward:
      102:  763:      return 3;
        -:  764:    case tribute:
      119:  765:      return 5;
        -:  766:    case ambassador:
      105:  767:      return 3;
        -:  768:    case cutpurse:
       97:  769:      return 4;
        -:  770:    case embargo: 
      108:  771:      return 2;
        -:  772:    case outpost:
      130:  773:      return 5;
        -:  774:    case salvager:
      107:  775:      return 4;
        -:  776:    case sea_hag:
      106:  777:      return 4;
        -:  778:    case treasure_map:
      117:  779:      return 4;
        -:  780:    }
        -:  781:	
    #####:  782:  return -1;
        -:  783:}
*****************************************************************************/
Statement: 90%
Branch: 90%
Boundary:50%
Discussion: This function was well tested with every case run many times. The one problem with the test suite was that
there was nothing to test the boundary case when the input doesn't match any of the card types. This may not have been 
critical in this case since we could feel confident that this code would execute correctly. However, testing the game with 
these "strange" inputs is still necessary and this could be improved in future test cases. 
/*Results from testing buyCard()*/
/*Excerpt from dominion.c.gcov*/
  5:  411:int buyCard(int supplyPos, struct gameState *state) {
        -:  412:  int who;
        5:  413:  if (DEBUG){
        -:  414:    printf("Entering buyCard...\n");
        -:  415:  }
        -:  416:
        -:  417:  // I don't know what to do about the phase thing.
        -:  418:
        5:  419:  who = state->whoseTurn;
        -:  420:
        5:  421:  if (state->numBuys < 1){
        1:  422:    if (DEBUG)
        -:  423:      printf("You do not have any buys left\n");
        1:  424:    return -1;
        4:  425:  } else if (supplyCount(supplyPos, state) <1){
        1:  426:    if (DEBUG)
        -:  427:      printf("There are not any of that type of card left\n");
        1:  428:    return -1;
        3:  429:  } else if (state->coins < getCost(supplyPos)){
    #####:  430:    if (DEBUG) 
        -:  431:      printf("You do not have enough money to buy that. You have %d coins.\n", state->coins);
    #####:  432:    return -1;
        -:  433:  } else {
        3:  434:    state->phase=1;
        -:  435:    //state->supplyCount[supplyPos]--;
        3:  436:    gainCard(supplyPos, state, 0, who); //card goes in discard, this might be wrong.. (2 means goes into hand, 0 goes into discard)
        -:  437:  
        3:  438:    state->coins = (state->coins) - (getCost(supplyPos));
        3:  439:    state->numBuys--;
        3:  440:    if (DEBUG)
        -:  441:      printf("You bought card number %d for %d coins. You now have %d buys and %d coins.\n", supplyPos, getCost(supplyPos), state->numBuys, state->coins);
        -:  442:  }
        -:  443:
        -:  444:  //state->discard[who][state->discardCount[who]] = supplyPos;
        -:  445:  //state->discardCount[who]++;
        -:  446:    
        3:  447:  return 0;
        -:  448:}
*****************************************************************************/
Statement: 90%
Branch: 90%
Boundary:50%
Discussion: This function was pretty thoroughly tested but did leave out the boundary case where the player
would not have enough money to buy the particular card. This is another boundary case that would definitely 
need to be tested to really have good coverage of all cases. There were no bugs found with this function but, possibly 
there might have been if this function had been more completely tested. 
/*Results from testing isGameOver*/
/*Excerpt from dominion.c.gcov*/ 
2000:  529:int isGameOver(struct gameState *state) {
        -:  530:  int i;
        -:  531:  int j;
        -:  532:	
        -:  533:  //if stack of Province cards is empty, the game ends
     2000:  534:  if (state->supplyCount[province] == 0)
        -:  535:    {
      190:  536:      return 1;
        -:  537:    }
        -:  538:
        -:  539:  //if three supply pile are at 0, the game ends
     1810:  540:  j = 0;
    47060:  541:  for (i = 0; i < 25; i++)
        -:  542:    {
    45250:  543:      if (state->supplyCount[i] == 0)
        -:  544:	{
     4347:  545:	  j++;
        -:  546:	}
        -:  547:    }
     1810:  548:  if ( j >= 3)
        -:  549:    {
      782:  550:      return 1;
        -:  551:    }
        -:  552:
     1028:  553:  return 0;
*****************************************************************************/
Statement: 100%
Branch: 100%
Boundary:100%
Discussion: It turned out this function had a fairly subtle bug. For most of the test cases, 
it appeared to be working correctly. There were relatively few "odd" cases where something went wrong. 
Digging into the problem more, I found it only occurred with higher-numbered cards. I found that out by
looking at the frequency that the cards occurred whenever errors occurred. This was a good lesson since 
it would have been easy to miss this bug if I were just relying on branch and statement coverage. 
