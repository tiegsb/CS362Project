/*****************************************************
Solomon Huynh
CS362 Assignment 3
Coverage1.c
******************************************************/
/*****************************************************
unittest1 - isGameOver
dominion.c.gcov
Lines executed: 1.71% of 586
Accumlicated lines executed: 1.71% of 586

Statement coverage: 100%
Branch coverage: 100%
Boundary value coverage: The use of random testing covered
all of the for loop with i from 0 to 26. Using this loop
1000 times definitely covered all possible values of of i
as well as a little over.

Notes: The use of random testing to cover all possible codes
to see if the game would end is a great way to catch errors.
In fact, doing random loops from 0 to 26 did catch an error
because the function for loop for i goes only from 0 to 24
where there is a possibility of 26 cards. That means that
if the 25 or 26 cards were empty, the supply count would not
notice that it's empty and would not count towards one of
the three stacks to end the game.
___________________________________________________________
     1000:  509:int isGameOver(struct gameState *state) {
        -:  510:  int i;
        -:  511:  int j;
        -:  512:
        -:  513:  //if stack of Province cards is empty, the game ends
     1000:  514:  if (state->supplyCount[province] == 0)
        -:  515:    {
      303:  516:      return 1;
        -:  517:    }
        -:  518:
        -:  519:  //if three supply pile are at 0, the game ends
      697:  520:  j = 0;
    18122:  521:  for (i = 0; i < 25; i++){
    17425:  522:      if (state->supplyCount[i] == 0){
      271:  523:        j++;
        -:  524:      }
        -:  525:  }
      697:  526:  if ( j >= 3){
       34:  527:      return 1;
        -:  528:  }
        -:  529:
      663:  530:  return 0;
___________________________________________________________
******************************************************/
/*****************************************************
unittest2 - updateCoins
dominion.c.gcov
Lines executed: 1.87% of 586
Accumlicated lines executed: 3.58% of 586

Statement coverage: 100%
Branch coverage: 100%
Boundary value coverage: Adding code to check all different
combination of coins to check if the coins updated correctly
worked out. This covered all possible combination of
treasure cards and thus covered the boundary.

Notes: I used a random generator of treasure cards in the hand
to see if the treasure cards added the coins correctly. Because
of how small the code actually is, performing coverage on
everything worked well. I also randomly generated the bonus
to add it and use my function to compare if the number of
coins match.
___________________________________________________________
      117: 1347:int updateCoins(int player, struct gameState *state, int bonus)
        -: 1348:{
        -: 1349:  int i;
        -: 1350:
        -: 1351:  //reset coin count
      117: 1352:  state->coins = 0;
        -: 1353:
        -: 1354:  //add coins for each Treasure card in player's hand
      702: 1355:  for (i = 0; i < state->handCount[player]; i++)
        -: 1356:    {
      585: 1357:      if (state->hand[player][i] == copper)
        -: 1358:	{
       85: 1359:	  state->coins += 1;
        -: 1360:	}
      500: 1361:      else if (state->hand[player][i] == silver)
        -: 1362:	{
       20: 1363:	  state->coins += 2;
        -: 1364:	}
      480: 1365:      else if (state->hand[player][i] == gold)
        -: 1366:	{
       14: 1367:	  state->coins += 3;
        -: 1368:	}
        -: 1369:    }
        -: 1370:
        -: 1371:  //add bonus
      117: 1372:  state->coins += bonus;
        -: 1373:
      117: 1374:  return 0;
        -: 1375:}
___________________________________________________________
******************************************************/
/*****************************************************
unittest3 - buyCard
dominion.c.gcov
Lines executed: 3.07% of 586
Accumlicated lines executed: 27.13% of 586

Statement coverage: 81.8% (technically 100%)
Branch coverage: 55.6% (technically 100%)
Boundary value coverage: I only covered enough boundary to pass
the test on this one up to 10 usually. If the number of buys
fails if it is under 0, I did from 0 to 10 to check on it. The
same applies to supply count and calculating the coins.

Notes: I technically the coverage is 100 percent because DEBUG
is turned off which only displays messages. There was no need
to run print statements and would take up more space on the
unittestresults.out document. I randomly generated for the
number of buys, the supply count, and the coins and tested
each of them separately. This covered all the if statements
excluding the DEBUG statements and passed the test.
___________________________________________________________
      172:  391:int buyCard(int supplyPos, struct gameState *state) {
        -:  392:  int who;
      172:  393:  if (DEBUG){
        -:  394:    printf("Entering buyCard...\n");
        -:  395:  }
        -:  396:
        -:  397:  // I don't know what to do about the phase thing.
        -:  398:
      172:  399:  who = state->whoseTurn;
        -:  400:
      172:  401:  if (state->numBuys < 1){
        1:  402:    if (DEBUG)
        -:  403:      printf("You do not have any buys left\n");
        1:  404:    return -1;
      171:  405:  } else if (supplyCount(supplyPos, state) <1){
       27:  406:    if (DEBUG)
        -:  407:      printf("There are not any of that type of card left\n");
       27:  408:    return -1;
      144:  409:  } else if (state->coins < getCost(supplyPos)){
        6:  410:    if (DEBUG)
        -:  411:      printf("You do not have enough money to buy that. You have %d coins.\n", state->coins);
        6:  412:    return -1;
        -:  413:  } else {
      138:  414:    state->phase=1;
        -:  415:    //state->supplyCount[supplyPos]--;
      138:  416:    gainCard(supplyPos, state, 0, who); //card goes in discard, this might be wrong.. (2 means goes into hand, 0 goes into discard)
        -:  417:
      138:  418:    state->coins = (state->coins) - (getCost(supplyPos));
      138:  419:    state->numBuys--;
      138:  420:    if (DEBUG)
        -:  421:      printf("You bought card number %d for %d coins. You now have %d buys and %d coins.\n", supplyPos, getCost(supplyPos), state->numBuys, state->coins);
        -:  422:  }
        -:  423:
        -:  424:  //state->discard[who][state->discardCount[who]] = supplyPos;
        -:  425:  //state->discardCount[who]++;
        -:  426:
      138:  427:  return 0;
___________________________________________________________
******************************************************/
/*****************************************************
unittest4 - getCost
dominion.c.gcov
Lines executed: 4.94% of 586
Accumlicated lines executed: 27.13% of 586

Statement coverage: 96.7%
Branch coverage: 96.7%
Boundary value coverage: Covered all possible cards but not
when it is a card that does not exist. Boundary testing
should of been done better to many values above 27 cards.

Notes: While I covered most of everything. I noticed that
I overlooked the default switch statement if it does not
contain the card number. While all the test worked perfectly,
it never tested the boundary above 27 cards which I will
definitely cover the next time I do something like this. It
was most likely overlooked due to the setup of the program
using names instead of numbers using "enum".
___________________________________________________________
     2296:  699:int getCost(int cardNumber)
        -:  700:{
     2296:  701:  switch( cardNumber )
        -:  702:    {
        -:  703:    case curse:
       75:  704:      return 0;
        -:  705:    case estate:
       73:  706:      return 2;
        -:  707:    case duchy:
       88:  708:      return 5;
        -:  709:    case province:
       90:  710:      return 8;
        -:  711:    case copper:
       73:  712:      return 0;
        -:  713:    case silver:
       86:  714:      return 3;
        -:  715:    case gold:
      115:  716:      return 6;
        -:  717:    case adventurer:
       93:  718:      return 6;
        -:  719:    case council_room:
       85:  720:      return 5;
        -:  721:    case feast:
      105:  722:      return 4;
        -:  723:    case gardens:
       83:  724:      return 4;
        -:  725:    case mine:
       72:  726:      return 5;
        -:  727:    case remodel:
       68:  728:      return 4;
        -:  729:    case smithy:
       85:  730:      return 4;
        -:  731:    case village:
       83:  732:      return 3;
        -:  733:    case baron:
       80:  734:      return 4;
        -:  735:    case great_hall:
       97:  736:      return 3;
        -:  737:    case minion:
       77:  738:      return 5;
        -:  739:    case steward:
       73:  740:      return 3;
        -:  741:    case tribute:
       74:  742:      return 5;
        -:  743:    case ambassador:
       80:  744:      return 3;
        -:  745:    case cutpurse:
       96:  746:      return 4;
        -:  747:    case embargo:
       99:  748:      return 2;
        -:  749:    case outpost:
       85:  750:      return 5;
        -:  751:    case salvager:
       86:  752:      return 4;
        -:  753:    case sea_hag:
       96:  754:      return 4;
        -:  755:    case treasure_map:
       79:  756:      return 4;
        -:  757:    }
        -:  758:
    #####:  759:  return -1;
        -:  760:}
___________________________________________________________
******************************************************/
/*****************************************************
cardtest1.c - smithyCard
dominion.c.gcov
Lines executed: 1.02% of 586
Accumlicated lines executed: 31.40% of 586

Statement coverage: 100%
Branch coverage: 100%
Boundary value coverage: Could of done a better job covering
if the card was discarded in different hand positioned. I did
tests to start from the 0th position just or holding 1 card
to test if the card was discarded afterwards and if the cards
were drawn.

Notes: Testing was done by creating a game state with only the
card tested in hand and 0 on everything else needed. I would
run the program and then check if the cards in hand increase
by three and if the card used was discarded. During testing,
I detected that the cards drawn was only 2 so that was a bug
reported.
___________________________________________________________
        4:  231:void smithyCard(struct gameState *state, int handPos){
        -:  232:    //Declare all variables needed
        -:  233:    int i;
        4:  234:    int currentPlayer = whoseTurn(state);
        -:  235:
        -:  236:    //+3 Cards
       12:  237:    for (i = 0; i < 2; i++)
        -:  238:	{
        8:  239:	  drawCard(currentPlayer, state);
        -:  240:	}
        -:  241:
        -:  242:    //discard card from hand
        4:  243:    discardCard(handPos, currentPlayer, state, 0);
        4:  244:    return;
        -:  245:}
___________________________________________________________
******************************************************/
/*****************************************************
cardtest2.c - adventurerCard
dominion.c.gcov
Lines executed: 3.07% of 586
Accumlicated lines executed: 34.47% of 586

Statement coverage: 94.7%
Branch coverage: 94.7%
Boundary value coverage: Created random decks in each
testing phase to provide coverage of all cards provided.

Notes: Improvements can be done with providing different
deck sizes to provide higher coverage with the shuffling
function. The deck was not small enough to shuffle so there
could of been more testing done there. Testing the cards
after using the adventurer card and seeing the types of
treasure cards caught two bugs: the adventurer card was
never discarded and the two treasures drawn was never
silver cards which needs to be fixed.
___________________________________________________________
       10:  202:void adventurerCard(struct gameState *state){
        -:  203:    //Declare all variables needed
       10:  204:    int currentPlayer = whoseTurn(state);
       10:  205:    int drawntreasure = 0;
       10:  206:    int cardDrawn = 0;
        -:  207:    int temphand[MAX_HAND];// moved above the if statement
       10:  208:    int z = 0;// this is the counter for the temp hand
        -:  209:
       82:  210:    while(drawntreasure<2){
       62:  211:        if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
    #####:  212:          shuffle(currentPlayer, state);
        -:  213:        }
       62:  214:        drawCard(currentPlayer, state);
       62:  215:        cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
       82:  216:        if (cardDrawn == copper || cardDrawn == gold)
       20:  217:          drawntreasure++;
        -:  218:        else{
       42:  219:          temphand[z]=cardDrawn;
       42:  220:          state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
       42:  221:          z++;
        -:  222:        }
        -:  223:    }
       62:  224:    while(z-1>=0){
       42:  225:        state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
       42:  226:        z=z-1;
        -:  227:    }
       10:  228:    return;
___________________________________________________________
******************************************************/
/*****************************************************
cardtest3.c - councilRoomCard
dominion.c.gcov
Lines executed: 1.71% of 586
Accumlicated lines executed: 36.18% of 586

Statement coverage: 100%
Branch coverage: 100%
Boundary value coverage: Could of done a better job covering
if the card was discarded in different hand positioned. I did
tests to start from the 0th position just or holding 1 card
to test if the card was discarded afterwards and if the cards
were drawn. I did cover all players to check if they each drew
a card which was good.

Notes: Testing was done by creating a game state with only the
card tested in hand and 0 on everything else needed. I would
run the program and then check if the cards in hand increase
by three and if the card used was discarded. I detected that
the cards drawn was 3 instead of 4 so that was a good check
on bugs. I also confirmed that all players drew a card which
covered everything needed.
___________________________________________________________
        4:  291:void councilRoomCard(struct gameState *state, int handPos){
        -:  292:    int i;
        4:  293:    int currentPlayer = whoseTurn(state);
        -:  294:
        -:  295:    //+4 Cards
       16:  296:    for (i = 1; i < 4; i++)
        -:  297:	{
       12:  298:	  drawCard(currentPlayer, state);
        -:  299:	}
        -:  300:
        -:  301:    //+1 Buy
        4:  302:    state->numBuys++;
        -:  303:
        -:  304:    //Each other player draws a card
       20:  305:    for (i = 0; i < state->numPlayers; i++)
        -:  306:	{
       16:  307:	  if ( i != currentPlayer )
        -:  308:	    {
       12:  309:	      drawCard(i, state);
        -:  310:	    }
        -:  311:	}
        -:  312:
        -:  313:    //put played card in played card pile
        4:  314:    discardCard(handPos, currentPlayer, state, 0);
        -:  315:
        4:  316:    return;
___________________________________________________________
******************************************************/
/*****************************************************
cardtest4.c - villageCard
dominion.c.gcov
Lines executed: 1.02% of 586
Accumlicated lines executed: 37.20% of 586

Statement coverage: 100%
Branch coverage: 100%
Boundary value coverage: Covered everything needed except
the usual improvements on using the cards on different
hand positions.

Notes: Testing was done by running the function to detect changes
in the card drawn, action, and number of cards in the hand. Doing the
test, the card was properly discarded and one card was drawn. The big
issue was 2 actions was suppose to increase and it ended up being
three instead.
___________________________________________________________
        4:  247:void villageCard(struct gameState *state, int handPos){
        4:  248:    int currentPlayer = whoseTurn(state);
        -:  249:
        -:  250:    //+1 Card
        4:  251:    drawCard(currentPlayer, state);
        -:  252:
        -:  253:    //+2 Actions
        4:  254:    state->numActions = state->numActions + 3;
        -:  255:
        -:  256:    //discard played card from hand
        4:  257:    discardCard(handPos, currentPlayer, state, 0);
        4:  258:    return;
        -:  259:}
___________________________________________________________
******************************************************/
