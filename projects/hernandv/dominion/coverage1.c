Victor Hernandez
CS_362_F15
Assignment 3 - Part 4 - coverage1.c

/////////////////////////////////////////////////////////////////////////////////////////
Statement Coverage: Ninety five percent of the lines or 57 of 60 lines in the unit test were executed, lines that did not execute are below. Statement coverage in dominion.c were not nearly as good coming in at a little above 15%, indicating that a more robust test might be needed. 

Branch Coverage: All of the branches executed in the unit test for updatecoins(), indicating that all branched were covered. Branch coverage in dominion.c was again less than desirable as it came in a little above 15%.

Boundary Coverage: I tried to cover the boundary with low, middle and high coin counts, however this strategy needs adjustment as I think it is in part why the coverage in dominion.c is less than desirable.

File 'unittest1.c'
Lines executed:95.00% of 60
Branches executed:100.00% of 6
Taken at least once:50.00% of 6
Calls executed:85.71% of 21

File 'dominion.c'
Lines executed:15.83% of 581
Branches executed:15.83% of 417
Taken at least once:13.43% of 417
Calls executed:7.29% of 96

    #####:   69:		printf("Test #1 FAILED\n\n");
    #####:  115:		printf("Test #2 FAILED\n\n");
    #####:  164:		printf("Test #3 FAILED\n\n");

/////////////////////////////////////////////////////////////////////////////////////////
Statement Coverage: Statement coverage in the unit test was again high at 92.3%, indicating that the test was specific and executable for the most part. However in relation to dominion.c statement coverage was low at 16.3%, indicating that the test might be too specific.

Branch Coverage: Branch coverage was 100% for the unit test, indicating that all the edges were covered. Branch coverage in relation to dominion.c was again low at 16.3%, which might be in part to the number of occurences where isgameover() is called.

Boundary Coverage: Boundary coverage needs improvement as I only tested for two specific cases which are in part why the statement and branch coverage in the unit test were high but also why it might be to focused in relation to dominion.c

File 'unittest2.c'
Lines executed:92.31% of 26
Branches executed:100.00% of 4
Taken at least once:50.00% of 4
Calls executed:87.50% of 16
unittest2.c:creating 'unittest2.c.gcov'

File 'dominion.c'
Lines executed:16.35% of 581
Branches executed:16.31% of 417
Taken at least once:13.67% of 417
Calls executed:7.29% of 96

    #####:   52:		printf( "Test #1 FAILED\n\n");
    #####:   69:		printf( "Test #2 FAILED\n\n");

/////////////////////////////////////////////////////////////////////////////////////////
Statement Coverage: The unit test for shuffle had high statement coverge, coming at a 94.5%. Statement coverage in relation to dominion.c was again low at 16.5% but thiss may have to do with the way shuffle is utilized througout.

Branch Coverage: Branch coverage for the unit test was 100%, again this is in part to the focused nature of the unit test, as it test for very specific events. Branch coverage in relation to dominion.c was not very good as it was 16.3%, which might be in part to the occurences of shuffle.

Boundary Coverage: Boundary coverage was fairly straight forward as the cards were chere checked to see if they were shuffled or not. Not sure what other scenarios to test for.

File 'unittest3.c'
Lines executed:94.59% of 37
Branches executed:100.00% of 16
Taken at least once:68.75% of 16
Calls executed:81.25% of 16

File 'dominion.c'
Lines executed:16.52% of 581
Branches executed:16.31% of 417
Taken at least once:13.91% of 417
Calls executed:7.29% of 96

    #####:   72:			deck2Shuffle++;	//Should not increment since Player 2's deck should not have shuffled
    #####:   85:		printf( "Test FAILED\n\n");

/////////////////////////////////////////////////////////////////////////////////////////
Statement Coverage: The unit test for drawcard() had the lowest statement coverage at 88.1%. But in contrast it also had one of the higher statement coverages in relation to dominion.c at 18.5%, which I believe might be in part to the number of calls to drawcard() 

Branch Coverage: Branch coverage for the unit test was 100% again which may indicate some unneccessary statements within the unit test, as the the statement coverage was low. Branch coverage was also higher for this unit test than others at 17.2%, which may also relate to calls to the function.

Boundary Coverage: Boundary coverage could be improved as the number of tests checked for in the unit test were

File 'unittest4.c'
Lines executed:88.10% of 42
Branches executed:100.00% of 12
Taken at least once:50.00% of 12
Calls executed:70.59% of 17

File 'dominion.c'
Lines executed:18.59% of 581
Branches executed:17.27% of 417
Taken at least once:14.87% of 417
Calls executed:8.33% of 96

    #####:   70:		printf( "Test FAILED, discard pile NOT shuffled with deck\n");
    #####:   75:		printf( "Test PASSED, card added to player's hand after draw\n");
    #####:   84:		printf( "Test FAILED, discard pile was NOT empty\n");
    #####:   89:		printf( "Test PASSED, deck decremented after draw\n");
    #####:   96:		printf( "Test PASSED, deck was NOT empty\n\n");

/////////////////////////////////////////////////////////////////////////////////////////
Statement Coverage: The card test for Smithy had high statement coverge, coming at a 87.7%. Statement coverage in relation to dominion.c was again low at 22.5% but overall one of the higher statement coverages in relation to dominion.c

Branch Coverage: Branch coverage for the card test was 100%, again this is in part to the focused nature of the card test, as it test for very specific events namely the addition of three cards. Branch coverage in relation to dominion.c was not very good as it was 19.6%, which might be due to the use of Smithy throughout.

Boundary Coverage: Boundary coverage could be improved with the addition of more test cases as I only tested for one specific event, the number of cards in hand after Smithy was played.

File 'cardtest1.c'
Lines executed:87.76% of 49
Branches executed:100.00% of 22
Taken at least once:68.18% of 22
Calls executed:82.14% of 28

File 'dominion.c'
Lines executed:22.55% of 581
Branches executed:19.66% of 417
Taken at least once:17.03% of 417
Calls executed:10.42% of 96

    #####:   46:		printf("\nTest FAILED, card is NOT present in player %d's hand\n\n", p);
    #####:   59:			cardStatus = 1;	//Card is present in hand
    #####:   67:		printf("\nTest FAILED, card is present in player %d's hand\n\n", p);
    #####:   75:		printf("Test FAILED, Player %d drew incorrect amount of cards\n\n", p);
    #####:   81:		printf("Test PASSED, Smithy is in played pile\n\n");
    #####:   99:		printf("Test FAILED, Smithy card is NOT discarded from player %d's hand after use\n\n", p);


/////////////////////////////////////////////////////////////////////////////////////////
Statement Coverage: The card test for Adventurer had high statement coverge, coming at a 93.0%. Statement coverage in relation to dominion.c was again low at 24.9% but overall one of the higher statement coverages in relation to dominion.c

Branch Coverage: Branch coverage for the card test was 100%, again this is in part to the focused nature of the card test, as it test for very specific events namely the addition of two treasure cards. Branch coverage in relation to dominion.c was not very good as it was 22.5%, which might be due to the use of Adventurer throughout.

Boundary Coverage: Boundary coverage could be improved with the addition of more test cases as I only tested for one specific event, namely the number of treasure cards added.

File 'cardtest2.c'
Lines executed:93.02% of 43
Branches executed:100.00% of 22
Taken at least once:77.27% of 22
Calls executed:85.00% of 20

File 'dominion.c'
Lines executed:24.96% of 581
Branches executed:22.54% of 417
Taken at least once:19.18% of 417
Calls executed:11.46% of 96

    #####:   51:		printf("\nTest FAILED, card is NOT present in player %d's hand\n\n", p);
    #####:   70:		printf("\nTest PASSED, card is NOT present in player %d's hand\n\n", p);
    #####:   88:		printf("Test FAILED, %d (NOT 2) treasure cards are added to player %d's hand\n\n", drawntreasure, p);

/////////////////////////////////////////////////////////////////////////////////////////
Statement Coverage: The card test for Village had high statement coverge, coming at a 86.3%. Statement coverage in relation to dominion.c was again low at 25.8% but overall one of the higher statement coverages in relation to dominion.c in due part to the nature of the cards use.

Branch Coverage: Branch coverage for the card test was 100%, again this is in part to the focused nature of the card test, as it test for very specific events namely the num of actions and cards drawn. Branch coverage in relation to dominion.c was not very good as it was 22.5%.

Boundary Coverage: Boundary coverage could be improved with the addition of more test cases as I only tested for two specific events once, the number of cards in hand after Village was played and the number of actions.


File 'cardtest3.c'
Lines executed:86.36% of 44
Branches executed:100.00% of 18
Taken at least once:66.67% of 18
Calls executed:80.77% of 26

File 'dominion.c'
Lines executed:25.82% of 581
Branches executed:22.54% of 417
Taken at least once:19.18% of 417
Calls executed:13.54% of 96

    #####:   45:		printf("\nTest FAILED, card is NOT present in player %d's hand\n\n", p);
    #####:   58:			cardStatus = 1;	//Card is present in hand
    #####:   66:		printf("\nTest FAILED, card is present in player %d's hand\n\n", p);
    #####:   74:		printf("Test FAILED, Player %d drew incorrect amount of cards\n\n", p);
    #####:   80:		printf("Test PASSED, Player %d has +2 numActions\n\n", p);
    #####:   88:		printf("Test PASSED, Village is in played pile\n\n");

/////////////////////////////////////////////////////////////////////////////////////////
Statement Coverage: The card test for Great Hall had high statement coverge, coming at a 86.3%. Statement coverage in relation to dominion.c was again low at 27.1% but overall one of the higher statement coverages in relation to dominion.c in due part to the nature of the cards use and similarity to the previous card test.

Branch Coverage: Branch coverage for the card test was 100%, again this is in part to the focused nature of the card test, as it test for very specific events namely the num of actions and cards drawn. Branch coverage in relation to dominion.c was not very good as it was 22.5%. The similarities in statement and branch coverage to cardtest3 stem from the likeness in the cards effects.

Boundary Coverage: Boundary coverage could be improved with the addition of more test cases as I only tested for two specific events once, the number of cards in hand after Village was played and the number of actions.

File 'cardtest4.c'
Lines executed:86.36% of 44
Branches executed:100.00% of 18
Taken at least once:66.67% of 18
Calls executed:80.77% of 26

File 'dominion.c'
Lines executed:27.19% of 581
Branches executed:22.54% of 417
Taken at least once:19.42% of 417
Calls executed:16.67% of 96

    #####:   45:		printf("\nTest FAILED, card is NOT present in player %d's hand\n\n", p);
    #####:   58:			cardStatus = 1;	//Card is present in hand
    #####:   66:		printf("\nTest FAILED, card is present in player %d's hand\n\n", p);
    #####:   72:		printf("Test PASSED, Player %d drew +1 cards\n\n", p);
    #####:   82:		printf("Test FAILED, Player %d has incorrect number of numActions\n\n", p);
    #####:   90:		printf("Test FAILED, Great Hall is NOT in played pile\n\n");
    
/////////////////////////////////////////////////////////////////////////////////////////
Statement Coverage: The low statement coverage in dominion.c may be in part to bugs that exist in the program that have yet to be corrected, causing premature executions of operations.

Branch Coverage: The branch coverage is also likely low due to uncorrected errors in the program that need attention in order to cover more edges.

Boundary Coverage: There may also be boundary issues that are affecting the statement and branch coverage.

File 'dominion.c'
Lines executed:27.19% of 581
Branches executed:22.54% of 417
Taken at least once:19.42% of 417
Calls executed:16.67% of 96

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
    #####:   63:	      return -1;
    #####:   79:      state->supplyCount[curse] = 20;
    #####:  158:	  return -1;
    #####:  231:int playCard(int handPos, int choice1, int choice2, int choice3, struct gameState *state) 
    #####:  234:  int coin_bonus = 0; 		//tracks coins gain from actions
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
    #####:  401:  j = 0;
    #####:  402:  for (i = 0; i < 25; i++)
    #####:  404:      if (state->supplyCount[i] == 0)
    #####:  406:	  j++;
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
    #####:  469:	  players[i] = -9999;
    #####:  473:	  players[i] = scoreFor (i, state);
    #####:  478:  j = 0;
    #####:  479:  for (i = 0; i < MAX_PLAYERS; i++)
    #####:  481:      if (players[i] > players[j])
    #####:  483:	  j = i;
    #####:  486:  highScore = players[j];
    #####:  489:  currentPlayer = whoseTurn(state);
    #####:  490:  for (i = 0; i < MAX_PLAYERS; i++)
    #####:  492:      if ( players[i] == highScore && i > currentPlayer )
    #####:  494:	  players[i]++;
    #####:  499:  j = 0;
    #####:  500:  for (i = 0; i < MAX_PLAYERS; i++)
    #####:  502:      if ( players[i] > players[j] )
    #####:  504:	  j = i;
    #####:  507:  highScore = players[j];
    #####:  510:  for (i = 0; i < MAX_PLAYERS; i++)
    #####:  512:      if ( players[i] == highScore )
    #####:  514:	  players[i] = 1;
    #####:  518:	  players[i] = 0;
    #####:  522:  return 0;
    #####:  534:      state->deck[player][i] = state->discard[player][i];
    #####:  535:      state->discard[player][i] = -1;
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
    #####:  670:	  adventurerCard (drawntreasure, state, currentPlayer, cardDrawn, temphand, z); 
    #####:  671:      return 0;
    #####:  675:      for (i = 0; i < 4; i++)
    #####:  677:	  drawCard(currentPlayer, state);
    #####:  681:      state->numBuys++;
    #####:  684:      for (i = 0; i < state->numPlayers; i++)
    #####:  686:	  if ( i != currentPlayer )
    #####:  688:	      drawCard(i, state);
    #####:  693:      discardCard(handPos, currentPlayer, state, 0);
    #####:  695:      return 0;
    #####:  700:      for (i = 0; i <= state->handCount[currentPlayer]; i++){
    #####:  701:	temphand[i] = state->hand[currentPlayer][i];//Backup card
    #####:  702:	state->hand[currentPlayer][i] = -1;//Set to nothing
    #####:  707:      updateCoins(currentPlayer, state, 5);
    #####:  708:      x = 1;//Condition to loop on
    #####:  709:      while( x == 1) {//Buy one card
    #####:  710:	if (supplyCount(choice1, state) <= 0){
    #####:  711:	  if (DEBUG)
    #####:  714:	  if (DEBUG){
    #####:  718:	else if (state->coins < getCost(choice1)){
    #####:  719:	  printf("That card is too expensive!\n");
    #####:  721:	  if (DEBUG){
    #####:  727:	  if (DEBUG){
    #####:  731:	  gainCard(choice1, state, 0, currentPlayer);//Gain the card
    #####:  732:	  x = 0;//No more buying cards
    #####:  734:	  if (DEBUG){
    #####:  742:      for (i = 0; i <= state->handCount[currentPlayer]; i++){
    #####:  743:	state->hand[currentPlayer][i] = temphand[i];
    #####:  744:	temphand[i] = -1;
    #####:  748:      return 0;
    #####:  751:      return -1;
    #####:  754:      j = state->hand[currentPlayer][choice1];  //store card we will trash
    #####:  756:      if (state->hand[currentPlayer][choice1] < copper || state->hand[currentPlayer][choice1] > gold)
    #####:  758:	  return -1;
    #####:  761:      if (choice2 > treasure_map || choice2 < curse)
    #####:  763:	  return -1;
    #####:  766:      if ( (getCost(state->hand[currentPlayer][choice1]) + 3) > getCost(choice2) )
    #####:  768:	  return -1;
    #####:  771:      gainCard(choice2, state, 2, currentPlayer);
    #####:  774:      discardCard(handPos, currentPlayer, state, 0);
    #####:  777:      for (i = 0; i < state->handCount[currentPlayer]; i++)
    #####:  779:	  if (state->hand[currentPlayer][i] == j)
    #####:  781:	      discardCard(i, currentPlayer, state, 0);		
    #####:  782:	      break;
    #####:  786:      return 0;
    #####:  789:      j = state->hand[currentPlayer][choice1];  //store card we will trash
    #####:  791:      if ( (getCost(state->hand[currentPlayer][choice1]) + 2) > getCost(choice2) )
    #####:  793:	  return -1;
    #####:  796:      gainCard(choice2, state, 0, currentPlayer);
    #####:  799:      discardCard(handPos, currentPlayer, state, 0);
    #####:  802:      for (i = 0; i < state->handCount[currentPlayer]; i++)
    #####:  804:	  if (state->hand[currentPlayer][i] == j)
    #####:  806:	      discardCard(i, currentPlayer, state, 0);		
    #####:  807:	      break;
    #####:  811:      return 0;
    #####:  814:	  smithyCard(currentPlayer, state, handPos); 
    #####:  815:      return 0;
    #####:  818:      villageCard(currentPlayer, state, handPos);
    #####:  819:      return 0;
    #####:  822:      state->numBuys++;//Increase buys by 1!
    #####:  823:      if (choice1 > 0){//Boolean true or going to discard an estate
    #####:  824:	int p = 0;//Iterator for hand!
    #####:  825:	int card_not_discarded = 1;//Flag for discard set!
    #####:  826:	while(card_not_discarded){
    #####:  827:	  if (state->hand[currentPlayer][p] == estate){//Found an estate card!
    #####:  828:	    state->coins += 4;//Add 4 coins to the amount of coins
    #####:  829:	    state->discard[currentPlayer][state->discardCount[currentPlayer]] = state->hand[currentPlayer][p];
    #####:  830:	    state->discardCount[currentPlayer]++;
    #####:  831:	    for (;p < state->handCount[currentPlayer]; p++){
    #####:  832:	      state->hand[currentPlayer][p] = state->hand[currentPlayer][p+1];
    #####:  834:	    state->hand[currentPlayer][state->handCount[currentPlayer]] = -1;
    #####:  835:	    state->handCount[currentPlayer]--;
    #####:  836:	    card_not_discarded = 0;//Exit the loop
    #####:  838:	  else if (p > state->handCount[currentPlayer]){
    #####:  839:	    if(DEBUG) {
    #####:  843:	    if (supplyCount(estate, state) > 0){
    #####:  844:	      gainCard(estate, state, 0, currentPlayer);
    #####:  845:	      state->supplyCount[estate]--;//Decrement estates
    #####:  846:	      if (supplyCount(estate, state) == 0){
    #####:  847:		isGameOver(state);
    #####:  850:	    card_not_discarded = 0;//Exit the loop
    #####:  854:	    p++;//Next card
    #####:  860:	if (supplyCount(estate, state) > 0){
    #####:  861:	  gainCard(estate, state, 0, currentPlayer);//Gain an estate
    #####:  862:	  state->supplyCount[estate]--;//Decrement Estates
    #####:  863:	  if (supplyCount(estate, state) == 0){
    #####:  864:	    isGameOver(state);
    #####:  870:      return 0;
    #####:  873:      great_hallCard(currentPlayer, state, handPos);
    #####:  874:      return 0;
    #####:  878:      state->numActions++;
    #####:  881:      discardCard(handPos, currentPlayer, state, 0);
    #####:  883:      if (choice1)		//+2 coins
    #####:  885:	  state->coins = state->coins + 2;
    #####:  888:      else if (choice2)		//discard hand, redraw 4, other players with 5+ cards discard hand and draw 4
    #####:  891:	  while(numHandCards(state) > 0)
    #####:  893:	      discardCard(handPos, currentPlayer, state, 0);
    #####:  897:	  for (i = 0; i < 4; i++)
    #####:  899:	      drawCard(currentPlayer, state);
    #####:  903:	  for (i = 0; i < state->numPlayers; i++)
    #####:  905:	      if (i != currentPlayer)
    #####:  907:		  if ( state->handCount[i] > 4 )
    #####:  910:		      while( state->handCount[i] > 0 )
    #####:  912:			  discardCard(handPos, i, state, 0);
    #####:  916:		      for (j = 0; j < 4; j++)
    #####:  918:			  drawCard(i, state);
    #####:  925:      return 0;
    #####:  928:      if (choice1 == 1)
    #####:  931:	  drawCard(currentPlayer, state);
    #####:  932:	  drawCard(currentPlayer, state);
    #####:  934:      else if (choice1 == 2)
    #####:  937:	  state->coins = state->coins + 2;
    #####:  942:	  discardCard(choice2, currentPlayer, state, 1);
    #####:  943:	  discardCard(choice3, currentPlayer, state, 1);
    #####:  947:      discardCard(handPos, currentPlayer, state, 0);
    #####:  948:      return 0;
    #####:  951:      if ((state->discardCount[nextPlayer] + state->deckCount[nextPlayer]) <= 1){
    #####:  952:	if (state->deckCount[nextPlayer] > 0){
    #####:  953:	  tributeRevealedCards[0] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
    #####:  954:	  state->deckCount[nextPlayer]--;
    #####:  956:	else if (state->discardCount[nextPlayer] > 0){
    #####:  957:	  tributeRevealedCards[0] = state->discard[nextPlayer][state->discardCount[nextPlayer]-1];
    #####:  958:	  state->discardCount[nextPlayer]--;
    #####:  962:	  if (DEBUG){
    #####:  969:	if (state->deckCount[nextPlayer] == 0){
    #####:  970:	  for (i = 0; i < state->discardCount[nextPlayer]; i++){
    #####:  971:	    state->deck[nextPlayer][i] = state->discard[nextPlayer][i];//Move to deck
    #####:  972:	    state->deckCount[nextPlayer]++;
    #####:  973:	    state->discard[nextPlayer][i] = -1;
    #####:  974:	    state->discardCount[nextPlayer]--;
    #####:  977:	  shuffle(nextPlayer,state);//Shuffle the deck
    #####:  979:	tributeRevealedCards[0] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
    #####:  980:	state->deck[nextPlayer][state->deckCount[nextPlayer]--] = -1;
    #####:  981:	state->deckCount[nextPlayer]--;
    #####:  982:	tributeRevealedCards[1] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
    #####:  983:	state->deck[nextPlayer][state->deckCount[nextPlayer]--] = -1;
    #####:  984:	state->deckCount[nextPlayer]--;
    #####:  987:      if (tributeRevealedCards[0] == tributeRevealedCards[1]){//If we have a duplicate card, just drop one 
    #####:  988:	state->playedCards[state->playedCardCount] = tributeRevealedCards[1];
    #####:  989:	state->playedCardCount++;
    #####:  990:	tributeRevealedCards[1] = -1;
    #####:  993:      for (i = 0; i <= 2; i ++){
    #####:  994:	if (tributeRevealedCards[i] == copper || tributeRevealedCards[i] == silver || tributeRevealedCards[i] == gold){//Treasure cards
    #####:  995:	  state->coins += 2;
    #####:  998:	else if (tributeRevealedCards[i] == estate || tributeRevealedCards[i] == duchy || tributeRevealedCards[i] == province || tributeRevealedCards[i] == gardens || tributeRevealedCards[i] == great_hall){//Victory Card Found
    #####:  999:	  drawCard(currentPlayer, state);
    #####: 1000:	  drawCard(currentPlayer, state);
    #####: 1003:	  state->numActions = state->numActions + 2;
    #####: 1007:      return 0;
    #####: 1010:      j = 0;		//used to check if player has enough cards to discard
    #####: 1012:      if (choice2 > 2 || choice2 < 0)
    #####: 1014:	  return -1;				
    #####: 1017:      if (choice1 == handPos)
    #####: 1019:	  return -1;
    #####: 1022:      for (i = 0; i < state->handCount[currentPlayer]; i++)
    #####: 1024:	  if (i != handPos && i == state->hand[currentPlayer][choice1] && i != choice1)
    #####: 1026:	      j++;
    #####: 1029:      if (j < choice2)
    #####: 1031:	  return -1;				
    #####: 1034:      if (DEBUG) 
    #####: 1038:      state->supplyCount[state->hand[currentPlayer][choice1]] += choice2;
    #####: 1041:      for (i = 0; i < state->numPlayers; i++)
    #####: 1043:	  if (i != currentPlayer)
    #####: 1045:	      gainCard(state->hand[currentPlayer][choice1], state, 0, i);
    #####: 1050:      discardCard(handPos, currentPlayer, state, 0);		
    #####: 1053:      for (j = 0; j < choice2; j++)
    #####: 1055:	  for (i = 0; i < state->handCount[currentPlayer]; i++)
    #####: 1057:	      if (state->hand[currentPlayer][i] == state->hand[currentPlayer][choice1])
    #####: 1059:		  discardCard(i, currentPlayer, state, 1);
    #####: 1060:		  break;
    #####: 1065:      return 0;
    #####: 1069:      updateCoins(currentPlayer, state, 2);
    #####: 1070:      for (i = 0; i < state->numPlayers; i++)
    #####: 1072:	  if (i != currentPlayer)
    #####: 1074:	      for (j = 0; j < state->handCount[i]; j++)
    #####: 1076:		  if (state->hand[i][j] == copper)
    #####: 1078:		      discardCard(j, i, state, 0);
    #####: 1079:		      break;
    #####: 1081:		  if (j == state->handCount[i])
    #####: 1083:		      for (k = 0; k < state->handCount[i]; k++)
    #####: 1085:			  if (DEBUG)
    #####: 1088:		      break;
    #####: 1097:      discardCard(handPos, currentPlayer, state, 0);		
    #####: 1099:      return 0;
    #####: 1104:      state->coins = state->coins + 2;
    #####: 1107:      if ( state->supplyCount[choice1] == -1 )
    #####: 1109:	  return -1;
    #####: 1113:      state->embargoTokens[choice1]++;
    #####: 1116:      discardCard(handPos, currentPlayer, state, 1);		
    #####: 1117:      return 0;
    #####: 1120:      outpostCard(state, handPos, currentPlayer);
    #####: 1121:      return 0;
    #####: 1125:      state->numBuys++;
    #####: 1127:      if (choice1)
    #####: 1130:	  state->coins = state->coins + getCost( handCard(choice1, state) );
    #####: 1132:	  discardCard(choice1, currentPlayer, state, 1);	
    #####: 1136:      discardCard(handPos, currentPlayer, state, 0);
    #####: 1137:      return 0;
    #####: 1140:      for (i = 0; i < state->numPlayers; i++){
    #####: 1141:	if (i != currentPlayer){
    #####: 1142:	  state->discard[i][state->discardCount[i]] = state->deck[i][state->deckCount[i]--];	    state->deckCount[i]--;
    #####: 1143:	  state->discardCount[i]++;
    #####: 1144:	  state->deck[i][state->deckCount[i]--] = curse;//Top card now a curse
    #####: 1147:      return 0;
    #####: 1151:      index = -1;
    #####: 1152:      for (i = 0; i < state->handCount[currentPlayer]; i++)
    #####: 1154:	  if (state->hand[currentPlayer][i] == treasure_map && i != handPos)
    #####: 1156:	      index = i;
    #####: 1157:	      break;
    #####: 1160:      if (index > -1)
    #####: 1163:	  discardCard(handPos, currentPlayer, state, 1);
    #####: 1164:	  discardCard(index, currentPlayer, state, 1);
    #####: 1167:	  for (i = 0; i < 4; i++)
    #####: 1169:	      gainCard(gold, state, 1, currentPlayer);
    #####: 1173:	  return 1;
    #####: 1177:      return -1;
    #####: 1180:  return -1;
    #####: 1201:      state->handCount[currentPlayer]--;
    #####: 1206:      state->handCount[currentPlayer]--;
    #####: 1221:int gainCard(int supplyPos, struct gameState *state, int toFlag, int player)
    #####: 1226:  if ( supplyCount(supplyPos, state) < 1 )
    #####: 1228:      return -1;
    #####: 1236:  if (toFlag == 1)
    #####: 1238:      state->deck[ player ][ state->deckCount[player] ] = supplyPos;
    #####: 1239:      state->deckCount[player]++;
    #####: 1241:  else if (toFlag == 2)
    #####: 1243:      state->hand[ player ][ state->handCount[player] ] = supplyPos;
    #####: 1244:      state->handCount[player]++;
    #####: 1248:      state->discard[player][ state->discardCount[player] ] = supplyPos;
    #####: 1249:      state->discardCount[player]++;
    #####: 1253:  state->supplyCount[supplyPos]--;
    #####: 1255:  return 0;
    #####: 1292:	  shuffle(currentPlayer, state);
    #####: 1349:int outpostCard(struct gameState* state, int handPos, int currentPlayer) {
    #####: 1351:		state->outpostPlayed++;
    #####: 1354:		discardCard(handPos, currentPlayer, state, 0);
    #####: 1355:	return 0;
