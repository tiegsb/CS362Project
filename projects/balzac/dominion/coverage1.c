/****************************** FINDINGS **********************************************************
All of my tests scored a statement coverage of 80.70% or higher with the highest being 96.74%.
This indicates that almost every statement in the tests executed.

However I had 4 tests that had 100% branch coverage which indicates those tests had 100% statement
coverage because covering all the branches means only the statements that were necessary executed.
This shows that these tests, tested everything I set it to test.

The taken at least once coverage indicates that a branch has been executed at least one time.
Even though I have 100% branch coverage I don't have 100% taken at least once coverage because
my branches are mostly if else statements (true or false) and I didn't want to make a bunch of 
tests to make false positive and false negative to bring the coverage up to 100% because it would
only confuse the results and does not improve the test suite. Therefore this indicates to me
that my tests may be testing for the same thing multiple times.

I don't have 100% call coverage because not all of the printf statements executed. If I set
values to get failure responses and other data manipulation I could bring this up to 100%.
However doing this would just make my test results more complicated and confusing.

From reviewing the .gcov files associated with the tests I have found that all of my tests
except for cardtest2; the statements not being executed are print statements indicating a 
PASS or FAIL response. In cardtest2 parts of a for loop are not being executed which I will need
to revise during the next testing phase.

Code not executed in dominion:
There is an awful lot of code that is not executed in dominion.c. Only 19.44% statement coverage and
only 18.23% branch coverage; this is not a good sign. Only three of the things I tested for actually
run in the game. drawCard(), discardCard(), and steward_card(), everything else does not run. This
indicates that the game is ending prematurely because the game is not checking if the game should end
by either using all the province cards or if three card piles are empty, which was tested for in
unittest3 with the isGameOver().

In the future it would be a good idea to add test cases for playCard(), buyCard(), and endTurn()
because these functions are clearly stating to be used from the output when a person plays the game.

However due to the fact none of these functions are being called in dominion.c I think it would be
more wise to begin checking other files specifically the playdom.c file to see what lines are being
executed in there. In playdom.c it calls for the playCard function inside a while loop which may
be the reason the code is not being executed in dominion.c.

In fact it would be a good idea to test numHandCards() in dominion.c too, because that determines if
the while loop inside playdom.c executes to call the playCard(). Also test whoseTurn() in dominion.c
because this precedes the while loop in playdom.c with an if statement that evaluates whoseTurn().

/***************************** END OF FINDINGS ***************************************************/

/***************************** UNITTEST1 discardCard() COVERAGE REPORT ****************************

	coverage details of unittest1
		Lines executed: 89.29% of 84
		Branches executed: 92.86% of 28
		Taken at least once: 57.14% of 28
		Calls executed: 77.14% of 35

	This test unit covered 17.71% of 576 lines in dominion.c
	
	inputting command: grep '####' unittest1.c.gcov
	
    #####:   29:                inhand = 1; // card is in player's hand
    #####:   39:        printf ("\nFAIL - card has NOT been discarded from player's hand\n\n");
    #####:  101:        printf ("FAIL - card NOT added to played pile when trash flag set to 0.\n");
    #####:  107:        printf ("PASS - card added to discard pile.\n");
    #####:  121:        printf ("FAIL - Last card did NOT replace discarded card's position.\n");
    #####:  147:        printf ("FAIL - card added to played pile when trash flag set to 1.\n");
    #####:  153:        printf ("PASS - card added to discard pile.\n");
    #####:  167:        printf ("FAIL - Last card's position in hand discarded replaced with another card.\n");
    #####:  193:        printf ("\nFAIL - Player's hand is NOT empty.");
	
**************************** END UNITTEST1 COVERAGE REPORT ***************************************/

/*************************** UNITTEST2 drawCard() COVERAGE REPORT *********************************

	coverage details of unittest2
		Lines executed: 86.60% of 97
		Branches executed: 86.67% of 30
		Taken at least once: 43.33% of 30
		Calls executed: 64.86% of 37

	This test unit covered 18.40% of 576 lines in dominion.c
	
	inputting command: grep '####' unittest2.c.gcov
	
	#####:   68:                printf ("FAIL - card NOT added to player's hand.\n");
    #####:   78:                printf ("FAIL - card NOT removed from deck pile.\n");
    #####:   83:                printf ("FAIL - deck count is less than 0.\n");
    #####:  116:                printf ("FAIL - discard pile NOT added to deck pile.\n");
    #####:  126:                printf ("FAIL - discard pile NOT empty.\n");
    #####:  136:                printf ("FAIL - card NOT added to player's hand.\n");
    #####:  146:                printf ("FAIL - card NOT removed from deck pile.\n");
    #####:  151:                printf ("FAIL - deck count is less than 0.\n");
    #####:  183:                printf ("FAIL - discard pile NOT added to deck pile.\n");
    #####:  193:                printf ("FAIL - discard pile NOT empty.\n");
    #####:  203:                printf ("FAIL - card NOT added to player's hand.\n");
    #####:  213:                printf ("FAIL - card NOT removed from deck pile.\n");
    #####:  223:                printf ("PASS - deck count is NOT less than 0.\n");

**************************** END UNITTEST2 COVERAGE REPORT **************************************/

/*************************** UNITTEST3 isGameOver() COVERAGE REPORT ******************************

	coverage details of unittest3
		Lines executed: 86.21% of 58
		Branches executed: 100.00% of 16
		Taken at least once: 50.00% of 16
		Calls executed: 75.00% of 32

	This test unit covered 17.36% of 576 lines in dominion.c
	
	inputting command: grep '####' unittest3.c.gcov
	
	#####:   37:                printf ("FAIL - Game is over when 1 Province remaining.\n");
    #####:   53:                printf ("FAIL - Game is NOT over when 0 Province remaining.\n");
    #####:   66:                printf ("FAIL - Game is over when 1 card stack empty.\n");
    #####:   78:                printf ("FAIL - Game is over when 2 card stacks are empty.\n");
    #####:   94:                printf ("FAIL - Game is NOT over when 3 card stacks are empty.\n");
    #####:  107:                printf ("FAIL - Game is over when 1 card stack empty.\n");
    #####:  119:                printf ("FAIL - Game is over when 2 card stacks are empty.\n");
    #####:  131:                printf ("PASS - Game is over when 3 card stacks are empty.\n");

**************************** END UNITTEST3 COVERAGE REPORT **************************************/

/*************************** UNITTEST4 scoreFor() COVERAGE REPORT ********************************

	coverage details of unittest4
		Lines executed: 96.74% of 92
		Branches executed: 100.00% of 12
		Taken at least once: 75.00% of 12
		Calls executed: 88.46% of 26

	This test unit covered 17.71% of 576 lines in dominion.c
	
	inputting command: grep '####' unittest4.c.gcov
	
    #####:  115:        printf ("FAIL - Score NOT correctly calculated for cards in Player's Hand\n");
    #####:  139:        printf ("PASS - Score correctly calculated for cards in Player's discard pile\n");
    #####:  167:        printf ("PASS - Score correctly calculated for cards in Player's deck pile\n");

**************************** END UNITTEST4 COVERAGE REPORT **************************************/

/*************************** CARDTEST1 Smithy Card COVERAGE REPORT *******************************

	coverage details of cardtest1
		Lines executed: 90.91% of 44
		Branches executed: 100.00% of 16
		Taken at least once: 68.75% of 16
		Calls executed: 81.25% of 16
	
	This test unit covered 18.06% of 576 lines in dominion.c
	
	inputting command: grep '####' cardtest1.c.gcov
	
    #####:   66:        printf ("\nFAIL - Smithy card is NOT in player's hand\n");
    #####:   76:        printf ("PASS - Player %d has received 3 cards.\n", p);
    #####:   89:                inhand = 0; //Smithy card is not in player's hand
    #####:   99:        printf ("\nFAIL - Smithy card was NOT discarded hand.\n");
	
*************************** END CARDTEST1 COVERAGE REPORT ***************************************/

/************************** CARDTEST2 Adventurer Card COVERAGE REPORT ****************************

	coverage details of cardtest2
		Lines executed: 80.70% of 57
		Branches executed: 69.23% of 26
		Taken at least once: 42.31 of 26
		Calls executed: 66.67% of 21

	This test unit covered 20.14% of 576 lines in dominion.c
	
	inputting command: grep '####' cardtest2.c.gcov
	
    #####:   73:        printf ("\nFAIL - Adventurer card is NOT in player's hand\n");
    #####:   88:        printf ("PASS - deckCount now %d, deck was shuffled\n", G.deckCount[p]);
    #####:   94:        printf ("PASS - Player %d has received 2 cards.\n", p);
    #####:  104:        cardNumToName(G.hand[p][i], name); //Convert card number to cards name
    #####:  105:        printf("%s%s", name, ", ");
    #####:  106:        if(strcmp(name, "Adventurer") == 0)
    #####:  108:                inhand = 0; //Adventurer card is not in player's hand
    #####:  110:        if(strcmp(name, "Copper") == 0 || strcmp(name, "Silver") == 0 || strcmp(name, "Gold") == 0)
    #####:  112:                drawnTreasure++; //Treasure card drawn.
    #####:  122:        printf ("FAIL - Adventurer card was NOT discarded hand.\n");
    #####:  127:        printf ("PASS - Only two treasure cards were added to hand.\n");

************************** END CARDTEST2 COVERAGE REPORT ****************************************/

/************************* CARDTEST3 Village Card COVERAGE REPORT ********************************

	coverage details of cardtest3
		Lines executed: 88.68% of 53
		Branches executed: 90.00% of 20
		Taken at least once: 60.00% of 20
		Calls executed: 73.68% of 19

	This test unit covered 19.97% of 576 lines in dominion.c
	
	inputting command: grep '####' cardtest3.c.gcov
	
    #####:   70:                printf ("\nFAIL - Village card is NOT in player's hand\n");
    #####:   86:                printf ("FAIL - Player %d has not received a card.\n", p);
    #####:   92:                printf ("PASS - Player %d has gained +2 actions.\n", p);
    #####:  100:                printf ("FAIL - Player %d has NOT gained +2 actions.\n", p);
    #####:  109:                        inhand = 1; //Village card is in player's hand
    #####:  119:                printf ("\nFAIL - Village card has NOT been discarded from player's hand\n");

************************* END CARDTEST3 COVERAGE REPORT *****************************************/

/************************ CARDTEST4 Steward Card COVERAGE REPORT *********************************

	coverage details of cardtest4
		Lines executed: 89.83% of 59
		Branches executed: 100.00% of 28
		Taken at least once: 71.43% of 28
		Calls executed: 75.00% of 20

	This test unit covered 19.44% of 576 lines in dominion.c
	
	inputting command: grep '####' cardtest4.c.gcov
	
    #####:   75:                printf ("\nFAIL - Steward card is NOT in player's hand\n");
    #####:   89:                        printf ("PASS - Player %d has received 2 cards.\n", p);
    #####:  100:                        printf ("PASS - Player %d has received 2 coins.\n", p);
    #####:  113:                        printf ("PASS - 2 cards discarded.\n");
    #####:  127:                        inhand = 1; //Steward card is in player's hand
    #####:  137:                printf ("\nFAIL - Steward card has NOT been discarded from player's hand\n\n");

************************* END CARDTEST4 COVERAGE REPORT *****************************************/

/************************ DOMINION COVERAGE REPORT ***********************************************

	coverage details of dominion
		Lines executed: 19.44% of 576
		Branches executed: 18.23% of 417
		Taken at least once: 14.87% of 417
		Calls executed: 13.54% of 96


	inputting command: grep '####' dominion.c.gcov
	
    #####:   10:    return 1;
    #####:   16:struct gameState* newGame() {
    #####:   17:  struct gameState* g = malloc(sizeof(struct gameState));
    #####:   18:  return g;
    #####:   21:int* kingdomCards(int k1, int k2, int k3, int k4, int k5, int k6, int k7,
    #####:   23:  int* k = malloc(10 * sizeof(int));
    #####:   24:  k[0] = k1;
    #####:   25:  k[1] = k2;
    #####:   26:  k[2] = k3;
    #####:   27:  k[3] = k4;
    #####:   28:  k[4] = k5;
    #####:   29:  k[5] = k6;
    #####:   30:  k[6] = k7;
    #####:   31:  k[7] = k8;
    #####:   32:  k[8] = k9;
    #####:   33:  k[9] = k10;
    #####:   34:  return k;
    #####:   50:      return -1;
    #####:   63:              return -1;
    #####:   77:  else if (numPlayers == 3)
    #####:   79:      state->supplyCount[curse] = 20;
    #####:   83:      state->supplyCount[curse] = 30;
    #####:   95:      state->supplyCount[estate] = 12;
    #####:   96:      state->supplyCount[duchy] = 12;
    #####:   97:      state->supplyCount[province] = 12;
    #####:  118:                  else{ state->supplyCount[i] = 12; }
    #####:  158:          return -1;
    #####:  210:    return -1;
    #####:  231:int playCard(int handPos, int choice1, int choice2, int choice3, struct gameState *state) 
    #####:  234:  int coin_bonus = 0;           //tracks coins gain from actions
    #####:  237:  if (state->phase != 0)
    #####:  239:      return -1;
    #####:  243:  if ( state->numActions < 1 )
    #####:  245:      return -1;
    #####:  249:  card = handCard(handPos, state);
    #####:  252:  if ( card < adventurer || card > treasure_map )
    #####:  254:      return -1;
    #####:  258:  if ( cardEffect(card, choice1, choice2, choice3, state, handPos, &coin_bonus) < 0 )
    #####:  260:      return -1;
    #####:  264:  state->numActions--;
    #####:  267:  updateCoins(state->whoseTurn, state, coin_bonus);
    #####:  269:  return 0;
    #####:  272:int buyCard(int supplyPos, struct gameState *state) {
    #####:  274:  if (DEBUG){
    #####:  280:  who = state->whoseTurn;
    #####:  282:  if (state->numBuys < 1){
    #####:  283:    if (DEBUG)
    #####:  285:    return -1;
    #####:  286:  } else if (supplyCount(supplyPos, state) <1){
    #####:  287:    if (DEBUG)
    #####:  289:    return -1;
    #####:  290:  } else if (state->coins < getCost(supplyPos)){
    #####:  291:    if (DEBUG) 
    #####:  293:    return -1;
    #####:  295:    state->phase=1;
    #####:  297:    gainCard(supplyPos, state, 0, who); //card goes in discard, this might be wrong.. (2 means goes into hand, 0 goes into discard)
    #####:  299:    state->coins = (state->coins) - (getCost(supplyPos));
    #####:  300:    state->numBuys--;
    #####:  301:    if (DEBUG)
    #####:  308:  return 0;
    #####:  311:int numHandCards(struct gameState *state) {
    #####:  312:  return state->handCount[ whoseTurn(state) ];
    #####:  315:int handCard(int handPos, struct gameState *state) {
    #####:  316:  int currentPlayer = whoseTurn(state);
    #####:  317:  return state->hand[currentPlayer][handPos];
    #####:  320:int supplyCount(int card, struct gameState *state) {
    #####:  321:  return state->supplyCount[card];
    #####:  324:int fullDeckCount(int player, int card, struct gameState *state) {
    #####:  326:  int count = 0;
    #####:  328:  for (i = 0; i < state->deckCount[player]; i++)
    #####:  330:      if (state->deck[player][i] == card) count++;
    #####:  333:  for (i = 0; i < state->handCount[player]; i++)
    #####:  335:      if (state->hand[player][i] == card) count++;
    #####:  338:  for (i = 0; i < state->discardCount[player]; i++)
    #####:  340:      if (state->discard[player][i] == card) count++;
    #####:  343:  return count;
    #####:  346:int whoseTurn(struct gameState *state) {
    #####:  347:  return state->whoseTurn;
    #####:  350:int endTurn(struct gameState *state) {
    #####:  353:  int currentPlayer = whoseTurn(state);
    #####:  356:  for (i = 0; i < state->handCount[currentPlayer]; i++){
    #####:  357:    state->discard[currentPlayer][state->discardCount[currentPlayer]++] = state->hand[currentPlayer][i];//Discard
    #####:  358:    state->hand[currentPlayer][i] = -1;//Set card to -1
    #####:  360:  state->handCount[currentPlayer] = 0;//Reset hand count
    #####:  363:  if (currentPlayer < (state->numPlayers - 1)){ 
    #####:  364:    state->whoseTurn = currentPlayer + 1;//Still safe to increment
    #####:  367:    state->whoseTurn = 0;//Max player has been reached, loop back around to player 1
    #####:  370:  state->outpostPlayed = 0;
    #####:  371:  state->phase = 0;
    #####:  372:  state->numActions = 1;
    #####:  373:  state->coins = 0;
    #####:  374:  state->numBuys = 1;
    #####:  375:  state->playedCardCount = 0;
    #####:  376:  state->handCount[state->whoseTurn] = 0;
    #####:  380:  for (k = 0; k < 5; k++){
    #####:  381:    drawCard(state->whoseTurn, state);//Draw a card
    #####:  385:  updateCoins(state->whoseTurn, state , 0);
    #####:  387:  return 0;
    #####:  390:int isGameOver(struct gameState *state) {
    #####:  395:  if (state->supplyCount[province] == 0)
    #####:  397:      return 1;
    #####:  401:  j = 0;
    #####:  402:  for (i = 0; i < 25; i++)
    #####:  404:      if (state->supplyCount[i] == 0)
    #####:  406:          j++;
    #####:  409:  if ( j >= 3)
    #####:  411:      return 1;
    #####:  414:  return 0;
    #####:  417:int scoreFor (int player, struct gameState *state) {
    #####:  420:  int score = 0;
    #####:  422:  for (i = 0; i < state->handCount[player]; i++)
    #####:  424:      if (state->hand[player][i] == curse) { score = score - 1; };
    #####:  425:      if (state->hand[player][i] == estate) { score = score + 1; };
    #####:  426:      if (state->hand[player][i] == duchy) { score = score + 3; };
    #####:  427:      if (state->hand[player][i] == province) { score = score + 6; };
    #####:  428:      if (state->hand[player][i] == great_hall) { score = score + 1; };
    #####:  429:      if (state->hand[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, state) / 10 ); };
    #####:  433:  for (i = 0; i < state->discardCount[player]; i++)
    #####:  435:      if (state->discard[player][i] == curse) { score = score - 1; };
    #####:  436:      if (state->discard[player][i] == estate) { score = score + 1; };
    #####:  437:      if (state->discard[player][i] == duchy) { score = score + 3; };
    #####:  438:      if (state->discard[player][i] == province) { score = score + 6; };
    #####:  439:      if (state->discard[player][i] == great_hall) { score = score + 1; };
    #####:  440:      if (state->discard[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, state) / 10 ); };
    #####:  444:  for (i = 0; i < state->discardCount[player]; i++)
    #####:  446:      if (state->deck[player][i] == curse) { score = score - 1; };
    #####:  447:      if (state->deck[player][i] == estate) { score = score + 1; };
    #####:  448:      if (state->deck[player][i] == duchy) { score = score + 3; };
    #####:  449:      if (state->deck[player][i] == province) { score = score + 6; };
    #####:  450:      if (state->deck[player][i] == great_hall) { score = score + 1; };
    #####:  451:      if (state->deck[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, state) / 10 ); };
    #####:  454:  return score;
    #####:  457:int getWinners(int players[MAX_PLAYERS], struct gameState *state) {
    #####:  464:  for (i = 0; i < MAX_PLAYERS; i++)
    #####:  467:      if (i >= state->numPlayers)
    #####:  469:          players[i] = -9999;
    #####:  473:          players[i] = scoreFor (i, state);
    #####:  478:  j = 0;
    #####:  479:  for (i = 0; i < MAX_PLAYERS; i++)
    #####:  481:      if (players[i] > players[j])
    #####:  483:          j = i;
    #####:  486:  highScore = players[j];
    #####:  489:  currentPlayer = whoseTurn(state);
    #####:  490:  for (i = 0; i < MAX_PLAYERS; i++)
    #####:  492:      if ( players[i] == highScore && i > currentPlayer )
    #####:  494:          players[i]++;
    #####:  499:  j = 0;
    #####:  500:  for (i = 0; i < MAX_PLAYERS; i++)
    #####:  502:      if ( players[i] > players[j] )
    #####:  504:          j = i;
    #####:  507:  highScore = players[j];
    #####:  510:  for (i = 0; i < MAX_PLAYERS; i++)
    #####:  512:      if ( players[i] == highScore )
    #####:  514:          players[i] = 1;
    #####:  518:          players[i] = 0;
    #####:  522:  return 0;
    #####:  533:    for (i = 0; i < state->discardCount[player];i++){
    #####:  534:      state->deck[player][i] = state->discard[player][i];
    #####:  535:      state->discard[player][i] = -1;
    #####:  538:    state->deckCount[player] = state->discardCount[player];
    #####:  539:    state->discardCount[player] = 0;//Reset discard
    #####:  542:    shuffle(player, state);//Shuffle the deck up and make it so that we can draw
    #####:  544:    if (DEBUG){//Debug statements
    #####:  548:    state->discardCount[player] = 0;
    #####:  551:    count = state->handCount[player];//Get current player's hand count
    #####:  553:    if (DEBUG){//Debug statements
    #####:  557:    deckCounter = state->deckCount[player];//Create a holder for the deck count
    #####:  559:    if (deckCounter == 0)
    #####:  560:      return -1;
    #####:  562:    state->hand[player][count] = state->deck[player][deckCounter - 1];//Add card to hand
    #####:  563:    state->deckCount[player]--;
    #####:  564:    state->handCount[player]++;//Increment hand count
    #####:  583:int getCost(int cardNumber)
    #####:  585:  switch( cardNumber ) 
    #####:  588:      return 0;
    #####:  590:      return 2;
    #####:  592:      return 5;
    #####:  594:      return 8;
    #####:  596:      return 0;
    #####:  598:      return 3;
    #####:  600:      return 6;
    #####:  602:      return 6;
    #####:  604:      return 5;
    #####:  606:      return 4;
    #####:  608:      return 4;
    #####:  610:      return 5;
    #####:  612:      return 4;
    #####:  614:      return 4;
    #####:  616:      return 3;
    #####:  618:      return 4;
    #####:  620:      return 3;
    #####:  622:      return 5;
    #####:  624:      return 3;
    #####:  626:      return 5;
    #####:  628:      return 3;
    #####:  630:      return 4;
    #####:  632:      return 2;
    #####:  634:      return 5;
    #####:  636:      return 4;
    #####:  638:      return 4;
    #####:  640:      return 4;
    #####:  643:  return -1;
    #####:  646:int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
    #####:  653:  int currentPlayer = whoseTurn(state);
    #####:  654:  int nextPlayer = currentPlayer + 1;
    #####:  656:  int tributeRevealedCards[2] = {-1, -1};
    #####:  658:  int drawntreasure=0;
    #####:  660:  int z = 0;// this is the counter for the temp hand
    #####:  661:  if (nextPlayer > (state->numPlayers - 1)){
    #####:  662:    nextPlayer = 0;
    #####:  667:  switch( card ) 
    #####:  670:                adventurer_card(currentPlayer, cardDrawn, drawntreasure, z, temphand, state);
    #####:  674:      for (i = 0; i < 4; i++)
    #####:  676:          drawCard(currentPlayer, state);
    #####:  680:      state->numBuys++;
    #####:  683:      for (i = 0; i < state->numPlayers; i++)
    #####:  685:          if ( i != currentPlayer )
    #####:  687:              drawCard(i, state);
    #####:  692:      discardCard(handPos, currentPlayer, state, 0);
    #####:  694:      return 0;
    #####:  699:      for (i = 0; i <= state->handCount[currentPlayer]; i++){
    #####:  700:        temphand[i] = state->hand[currentPlayer][i];//Backup card
    #####:  701:        state->hand[currentPlayer][i] = -1;//Set to nothing
    #####:  706:      updateCoins(currentPlayer, state, 5);
    #####:  707:      x = 1;//Condition to loop on
    #####:  708:      while( x == 1) {//Buy one card
    #####:  709:        if (supplyCount(choice1, state) <= 0){
    #####:  710:          if (DEBUG)
    #####:  713:          if (DEBUG){
    #####:  717:        else if (state->coins < getCost(choice1)){
    #####:  718:          printf("That card is too expensive!\n");
    #####:  720:          if (DEBUG){
    #####:  726:          if (DEBUG){
    #####:  730:          gainCard(choice1, state, 0, currentPlayer);//Gain the card
    #####:  731:          x = 0;//No more buying cards
    #####:  733:          if (DEBUG){
    #####:  741:      for (i = 0; i <= state->handCount[currentPlayer]; i++){
    #####:  742:        state->hand[currentPlayer][i] = temphand[i];
    #####:  743:        temphand[i] = -1;
    #####:  747:      return 0;
    #####:  750:      return -1;
    #####:  753:      j = state->hand[currentPlayer][choice1];  //store card we will trash
    #####:  755:      if (state->hand[currentPlayer][choice1] < copper || state->hand[currentPlayer][choice1] > gold)
    #####:  757:          return -1;
    #####:  760:      if (choice2 > treasure_map || choice2 < curse)
    #####:  762:          return -1;
    #####:  765:      if ( (getCost(state->hand[currentPlayer][choice1]) + 3) > getCost(choice2) )
    #####:  767:          return -1;
    #####:  770:      gainCard(choice2, state, 2, currentPlayer);
    #####:  773:      discardCard(handPos, currentPlayer, state, 0);
    #####:  776:      for (i = 0; i < state->handCount[currentPlayer]; i++)
    #####:  778:          if (state->hand[currentPlayer][i] == j)
    #####:  780:              discardCard(i, currentPlayer, state, 0);
    #####:  781:              break;
    #####:  785:      return 0;
    #####:  788:      j = state->hand[currentPlayer][choice1];  //store card we will trash
    #####:  790:      if ( (getCost(state->hand[currentPlayer][choice1]) + 2) > getCost(choice2) )
    #####:  792:          return -1;
    #####:  795:      gainCard(choice2, state, 0, currentPlayer);
    #####:  798:      discardCard(handPos, currentPlayer, state, 0);
    #####:  801:      for (i = 0; i < state->handCount[currentPlayer]; i++)
    #####:  803:          if (state->hand[currentPlayer][i] == j)
    #####:  805:              discardCard(i, currentPlayer, state, 0);
    #####:  806:              break;
    #####:  811:      return 0;
    #####:  814:                smithy_card(currentPlayer, handPos, state);
    #####:  818:      drawCard(currentPlayer, state);
    #####:  821:      state->numActions = state->numActions + 2;
    #####:  824:      discardCard(handPos, currentPlayer, state, 0);
    #####:  825:      return 0;
    #####:  828:      state->numBuys++;//Increase buys by 1!
    #####:  829:      if (choice1 > 0){//Boolean true or going to discard an estate
    #####:  830:        int p = 0;//Iterator for hand!
    #####:  831:        int card_not_discarded = 1;//Flag for discard set!
    #####:  832:        while(card_not_discarded){
    #####:  833:          if (state->hand[currentPlayer][p] == estate){//Found an estate card!
    #####:  834:            state->coins += 4;//Add 4 coins to the amount of coins
    #####:  835:            state->discard[currentPlayer][state->discardCount[currentPlayer]] = state->hand[currentPlayer][p];
    #####:  836:            state->discardCount[currentPlayer]++;
    #####:  837:            for (;p < state->handCount[currentPlayer]; p++){
    #####:  838:              state->hand[currentPlayer][p] = state->hand[currentPlayer][p+1];
    #####:  840:            state->hand[currentPlayer][state->handCount[currentPlayer]] = -1;
    #####:  841:            state->handCount[currentPlayer]--;
    #####:  842:            card_not_discarded = 0;//Exit the loop
    #####:  844:          else if (p > state->handCount[currentPlayer]){
    #####:  845:            if(DEBUG) {
    #####:  849:            if (supplyCount(estate, state) > 0){
    #####:  850:              gainCard(estate, state, 0, currentPlayer);
    #####:  851:              state->supplyCount[estate]--;//Decrement estates
    #####:  852:              if (supplyCount(estate, state) == 0){
    #####:  853:                isGameOver(state);
    #####:  856:            card_not_discarded = 0;//Exit the loop
    #####:  860:            p++;//Next card
    #####:  866:        if (supplyCount(estate, state) > 0){
    #####:  867:          gainCard(estate, state, 0, currentPlayer);//Gain an estate
    #####:  868:          state->supplyCount[estate]--;//Decrement Estates
    #####:  869:          if (supplyCount(estate, state) == 0){
    #####:  870:            isGameOver(state);
    #####:  876:      return 0;
    #####:  880:      drawCard(currentPlayer, state);
    #####:  883:      state->numActions++;
    #####:  886:      discardCard(handPos, currentPlayer, state, 0);
    #####:  887:      return 0;
    #####:  891:      state->numActions++;
    #####:  894:      discardCard(handPos, currentPlayer, state, 0);
    #####:  896:      if (choice1)              //+2 coins
    #####:  898:          state->coins = state->coins + 2;
    #####:  901:      else if (choice2)         //discard hand, redraw 4, other players with 5+ cards discard hand and draw 4
    #####:  904:          while(numHandCards(state) > 0)
    #####:  906:              discardCard(handPos, currentPlayer, state, 0);
    #####:  910:          for (i = 0; i < 4; i++)
    #####:  912:              drawCard(currentPlayer, state);
    #####:  916:          for (i = 0; i < state->numPlayers; i++)
    #####:  918:              if (i != currentPlayer)
    #####:  920:                  if ( state->handCount[i] > 4 )
    #####:  923:                      while( state->handCount[i] > 0 )
    #####:  925:                          discardCard(handPos, i, state, 0);
    #####:  929:                      for (j = 0; j < 4; j++)
    #####:  931:                          drawCard(i, state);
    #####:  938:      return 0;
    #####:  941:                steward_card(currentPlayer, handPos, choice1, choice2, choice3, state);
    #####:  944:                tribute_card(currentPlayer, nextPlayer, tributeRevealedCards, state);
    #####:  947:      j = 0;            //used to check if player has enough cards to discard
    #####:  949:      if (choice2 > 2 || choice2 < 0)
    #####:  951:          return -1;
    #####:  954:      if (choice1 == handPos)
    #####:  956:          return -1;
    #####:  959:      for (i = 0; i < state->handCount[currentPlayer]; i++)
    #####:  961:          if (i != handPos && i == state->hand[currentPlayer][choice1] && i != choice1)
    #####:  963:              j++;
    #####:  966:      if (j < choice2)
    #####:  968:          return -1;
    #####:  971:      if (DEBUG) 
    #####:  975:      state->supplyCount[state->hand[currentPlayer][choice1]] += choice2;
    #####:  978:      for (i = 0; i < state->numPlayers; i++)
    #####:  980:          if (i != currentPlayer)
    #####:  982:              gainCard(state->hand[currentPlayer][choice1], state, 0, i);
    #####:  987:      discardCard(handPos, currentPlayer, state, 0);
    #####:  990:      for (j = 0; j < choice2; j++)
    #####:  992:          for (i = 0; i < state->handCount[currentPlayer]; i++)
    #####:  994:              if (state->hand[currentPlayer][i] == state->hand[currentPlayer][choice1])
    #####:  996:                  discardCard(i, currentPlayer, state, 1);
    #####:  997:                  break;
    #####: 1002:      return 0;
    #####: 1006:      updateCoins(currentPlayer, state, 2);
    #####: 1007:      for (i = 0; i < state->numPlayers; i++)
    #####: 1009:          if (i != currentPlayer)
    #####: 1011:              for (j = 0; j < state->handCount[i]; j++)
    #####: 1013:                  if (state->hand[i][j] == copper)
    #####: 1015:                      discardCard(j, i, state, 0);
    #####: 1016:                      break;
    #####: 1018:                  if (j == state->handCount[i])
    #####: 1020:                      for (k = 0; k < state->handCount[i]; k++)
    #####: 1022:                          if (DEBUG)
    #####: 1025:                      break;
    #####: 1034:      discardCard(handPos, currentPlayer, state, 0);
    #####: 1036:      return 0;
    #####: 1041:      state->coins = state->coins + 2;
    #####: 1044:      if ( state->supplyCount[choice1] == -1 )
    #####: 1046:          return -1;
    #####: 1050:      state->embargoTokens[choice1]++;
    #####: 1053:      discardCard(handPos, currentPlayer, state, 1);
    #####: 1054:      return 0;
    #####: 1058:      state->outpostPlayed++;
    #####: 1061:      discardCard(handPos, currentPlayer, state, 0);
    #####: 1062:      return 0;
    #####: 1066:      state->numBuys++;
    #####: 1068:      if (choice1)
    #####: 1071:          state->coins = state->coins + getCost( handCard(choice1, state) );
    #####: 1073:          discardCard(choice1, currentPlayer, state, 1);
    #####: 1077:      discardCard(handPos, currentPlayer, state, 0);
    #####: 1078:      return 0;
    #####: 1081:                sea_hag_card(currentPlayer, state);
    #####: 1085:      index = -1;
    #####: 1086:      for (i = 0; i < state->handCount[currentPlayer]; i++)
    #####: 1088:          if (state->hand[currentPlayer][i] == treasure_map && i != handPos)
    #####: 1090:              index = i;
    #####: 1091:              break;
    #####: 1094:      if (index > -1)
    #####: 1097:          discardCard(handPos, currentPlayer, state, 1);
    #####: 1098:          discardCard(index, currentPlayer, state, 1);
    #####: 1101:          for (i = 0; i < 4; i++)
    #####: 1103:              gainCard(gold, state, 1, currentPlayer);
    #####: 1107:          return 1;
    #####: 1111:      return -1;
    #####: 1114:  return -1;
    #####: 1135:      state->handCount[currentPlayer]--;
    #####: 1140:      state->handCount[currentPlayer]--;
    #####: 1155:int gainCard(int supplyPos, struct gameState *state, int toFlag, int player)
    #####: 1160:  if ( supplyCount(supplyPos, state) < 1 )
    #####: 1162:      return -1;
    #####: 1170:  if (toFlag == 1)
    #####: 1172:      state->deck[ player ][ state->deckCount[player] ] = supplyPos;
    #####: 1173:      state->deckCount[player]++;
    #####: 1175:  else if (toFlag == 2)
    #####: 1177:      state->hand[ player ][ state->handCount[player] ] = supplyPos;
    #####: 1178:      state->handCount[player]++;
    #####: 1182:      state->discard[player][ state->discardCount[player] ] = supplyPos;
    #####: 1183:      state->discardCount[player]++;
    #####: 1187:  state->supplyCount[supplyPos]--;
    #####: 1189:  return 0;
    #####: 1208:          state->coins += 2;
    #####: 1212:          state->coins += 3;
    #####: 1224:int adventurer_card(int currentPlayer, int cardDrawn, int drawntreasure, int z, int temphand[], struct gameState *state)
    #####: 1226:        while(drawntreasure<2){
    #####: 1227:                if (state->deckCount[currentPlayer] <0){//if the deck is empty we need to shuffle discard and add to deck
    #####: 1228:                  shuffle(currentPlayer, state);
    #####: 1230:                drawCard(currentPlayer, state);
    #####: 1231:                cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
    #####: 1232:                if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
    #####: 1233:                  drawntreasure++;
    #####: 1235:                  temphand[z]=cardDrawn;
    #####: 1236:                  state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
    #####: 1237:                  z++;
    #####: 1241:        while(z-1>=0){
    #####: 1242:                state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
    #####: 1243:                z=z-1;
    #####: 1246:        return 0;
    #####: 1249:int smithy_card(int currentPlayer, int handPos, struct gameState *state)
    #####: 1253:        for (i = 1; i < 3; i++)
    #####: 1255:                drawCard(currentPlayer, state);
    #####: 1259:        discardCard(handPos, currentPlayer, state, 1);
    #####: 1261:        return 0;
    #####: 1264:int sea_hag_card(int currentPlayer, struct gameState *state)
    #####: 1267:        for (i = 0; i < state->numPlayers; i++){
    #####: 1268:                if (i != currentPlayer){
    #####: 1269:                  state->discard[i][state->discardCount[i]] = state->deck[i][state->deckCount[i]--];                                                             state->deckCount[i]--;
    #####: 1270:                  state->discardCount[i]++;
    #####: 1271:                  state->deck[i][state->deckCount[i]--] = curse;//Top card now a curse
    #####: 1275:    return 0;
    #####: 1279:int tribute_card(int currentPlayer, int nextPlayer, int tributeRevealedCards[], struct gameState *state)
    #####: 1283:         if ((state->discardCount[nextPlayer] + state->deckCount[nextPlayer]) <= 1){
    #####: 1284:                if (state->deckCount[nextPlayer] > 0){
    #####: 1285:                  tributeRevealedCards[0] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
    #####: 1286:                  state->deckCount[nextPlayer]--;
    #####: 1288:                else if (state->discardCount[nextPlayer] > 0){
    #####: 1289:                  tributeRevealedCards[0] = state->discard[nextPlayer][state->discardCount[nextPlayer]-1];
    #####: 1290:                  state->discardCount[nextPlayer]--;
    #####: 1294:                  if (DEBUG){
    #####: 1301:                if (state->deckCount[nextPlayer] == 0){
    #####: 1302:                  for (i = 0; i < state->discardCount[nextPlayer]; i++){
    #####: 1303:                        state->deck[nextPlayer][i] = state->discard[nextPlayer][i];//Move to deck
    #####: 1304:                        state->deckCount[nextPlayer]++;
    #####: 1305:                        state->discard[nextPlayer][i] = -1;
    #####: 1306:                        state->discardCount[nextPlayer]--;
    #####: 1309:                  shuffle(nextPlayer,state);//Shuffle the deck
    #####: 1311:                tributeRevealedCards[0] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
    #####: 1312:                state->deck[nextPlayer][state->deckCount[nextPlayer]--] = -1;
    #####: 1313:                state->deckCount[nextPlayer]--;
    #####: 1314:                tributeRevealedCards[1] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
    #####: 1315:                state->deck[nextPlayer][state->deckCount[nextPlayer]--] = -1;
    #####: 1316:                state->deckCount[nextPlayer]--;
    #####: 1319:                  if (tributeRevealedCards[0] == tributeRevealedCards[1]){//If we have a duplicate card, just drop one 
    #####: 1320:                state->playedCards[state->playedCardCount] = tributeRevealedCards[1];
    #####: 1321:                state->playedCardCount++;
    #####: 1322:                tributeRevealedCards[1] = -1;
    #####: 1325:                  for (i = 0; i <= 2; i ++){
    #####: 1326:                if (tributeRevealedCards[i] == copper || tributeRevealedCards[i] == duchy || tributeRevealedCards[i] == gold){//Treasure cards
    #####: 1327:                  state->coins += 6;
    #####: 1330:                else if (tributeRevealedCards[i] == estate || tributeRevealedCards[i] == silver || tributeRevealedCards[i] == province || tributeRevealedCards[i] == gardens || tributeRevealedCards[i] == great_hall){//Victory Card Found
    #####: 1331:                  drawCard(currentPlayer, state);
    #####: 1332:                  drawCard(currentPlayer, state);
    #####: 1335:                  state->numActions = state->numActions + 0;
    #####: 1339:                  return 0;
	
**************************** END DOMINION COVERAGE REPORT ****************************************/
	
	
	
	
	
	
	
	
	
	
	
	
	
	





























