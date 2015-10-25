Author: Allan Chan
ONID: chanal
Class: CS362
Filename: coverage1.c
Description: Contains code coverage from unittests 1-4 and cardtests 1-4
-------------------------------------------------------------------------

Code Coverage Findings
---------------------
For my test suite, all but one has 100% branch coverage. This is probably because of the if-else statements
used in my unit tests where one condition has to be met. This also indicates that for the tests with 100% branch coverage,
has 100% statement coverage. This indicates that the tests executed the statements that I wanted the test suite to do
(7/8 unit tests).

My line executions are fairly high with the range between 84% to 94%. This is because there can be found unexecuted 
lines in my test as indicated below with '#####'. These unexecuted lines are print statements for PASS or FAIL, 
so one of the conditions are printed.

A lot of code were not executed in dominion.c. Only 31.21% of lines were executed, 31.65% of branches executed,
taken at least once 23.02% and calls executed 21.05%. To reach better coverage, it would be necessary to test
for the most called on functions.  



unittest1 - updateCoins()
--------------------------
	Coverage details of unittest1
		Lines executed: 94% of 98
		Branches executed: 100.00% of 10
		Taken at least once: 50.00% of 10
		Calls executed: 84.85% of 33
	This unit test covered 15.86% of 580 lines in dominion.c
	
	There were some '####' unexecuted lines in my test. 
    #####:   82:		printf("Test #1 FAILED\n\n");
    #####:  128:		printf("Test #2 FAILED\n\n");
    #####:  176:		printf("Test #3 FAILED\n\n");
    #####:  224:		printf("Test #4 FAILED\n\n");
    #####:  270:		printf("Test #5 FAILED\n\n");



unittest2 - isGameOver()
-------------------------
	Coverage details of unittest2
		Lines executed: 90.91% of 44
		Branches executed: 100.00% of 8
		Taken at least once: 50.00% of 8
		Calls executed: 85.71% of 28
	This unit test covered 17.59% of 580 lines in dominion.c

	There were some '####' unexecuted lines in my test. 
    #####:   66:		printf( "Test #1 FAILED\n\n");
    #####:   84:		printf( "Test #2 FAILED\n\n");
    #####:  104:		printf( "Test #3 FAILED\n\n");
    #####:  126:		printf( "Test #4 FAILED\n\n");




unittest3 - shuffle()
----------------------
	Coverage details of unittest3
		Lines executed: 94.59% of 37
		Branches executed: 100.00% of 16
		Taken at least once: 68.75% of 16
		Calls executed: 81.25% of 16
	This unit test covered 17.76% of 580 lines in dominion.c

	There were some '####' unexecuted lines in my test. 
    	#####:   86:			deck2Shuffle++;	//Should not increment since Player 2's deck should not have shuffled
   		#####:   99:		printf( "Test FAILED\n\n");



unittest4 - drawCard()
-----------------------
	Coverage details of unittest4
		Lines executed: 84.71% of 85
		Branches executed: 93.33% of 30
		Taken at least once: 46.67% of 30
		Calls executed: 65.79% of 38
	This unit test covered 17.76% of 580 lines in dominion.c

	There were some '####' unexecuted lines in my test. 
	    #####:   73:		printf( "Test FAILED, card NOT added to player's hand after draw\n");
	    #####:   80:		printf( "Test FAILED, deck NOT decremented after draw\n");
	    #####:   87:		printf( "Test FAILED, card drawn from empty deck\n\n");
	    #####:  123:		printf( "Test FAILED, discard pile NOT shuffled with deck\n");
	    #####:  130:		printf( "Test FAILED, card NOT added to player's hand after draw\n");
	    #####:  137:		printf( "Test FAILED, discard pile was NOT empty\n");
	    #####:  144:		printf( "Test FAILED, deck NOT decremented after draw\n");
	    #####:  151:		printf( "Test FAILED, card drawn from empty deck\n\n");
	    #####:  187:		printf( "Test FAILED, discard pile NOT shuffled with deck\n");
	    #####:  192:		printf( "Test PASSED, card added to player's hand after draw\n");
	    #####:  201:		printf( "Test FAILED, discard pile was NOT empty\n");
	    #####:  206:		printf( "Test PASSED, deck decremented after draw\n");
	    #####:  213:		printf( "Test PASSED, deck was NOT empty\n\n");



cardtest1 - smithyCard()
-------------------------
	Coverage details of cardtest1
		Lines executed: 92.68% of 41
		Branches executed: 100.00% of 14
		Taken at least once: 71.43% of 14
		Calls executed: 83.33% of 18
	This unit test covered 23.45% of 580 lines in dominion.c

	There were some '####' unexecuted lines in my test. 
	    #####:   76:		printf("\nTest FAILED, card is not present in player %d's hand\n\n", p);
	    #####:   86:		printf("Test PASSED, player %d's hand received +3 cards\n\n", p);
	    #####:  104:		printf("Test FAILED, Smithy card is NOT discarded from player %d's hand after use\n\n", p);



cardtest2 - adventurerCard()
-----------------------------
	Coverage details of cardtest2
		Lines executed: 93.75% of 48
		Branches executed: 100.00% of 22
		Taken at least once: 77.27% of 22
		Calls executed: 83.33% of 18
	This unit test covered 25.00% of 580 lines in dominion.c

	There were some '####' unexecuted lines in my test. 
	    #####:   81:		printf("Test FAILED, card is not present in player %d's hand\n\n", p);
	    #####:  105:		printf("Test PASSED, card is NOT present in player %d's hand\n", p);
	    #####:  116:		printf("Test PASSED, two treasure cards are added to player %d's hand\n\n", p);



cardtest3 - councilRoomCard()
-----------------------------
	Coverage details of cardtest2
		Lines executed: 86.36% of 44
		Branches executed: 100.00% of 18
		Taken at least once: 66.67% of 18
		Calls executed: 80.77% of 26
	This unit test covered 28.10% of 580 lines in dominion.c

	There were some '####' unexecuted lines in my test. 
	    #####:   60:		printf("\nTest FAILED, card is NOT present in player %d's hand\n\n", p);
	    #####:   73:			cardStatus = 1;	//Card is present in hand
	    #####:   81:		printf("\nTest FAILED, card is present in player %d's hand\n\n", p);
	    #####:   87:		printf("Test PASSED, Player %d drew +4 cards\n\n", p);
	    #####:   95:		printf("Test PASSED, Player %d has +1 numBuys\n\n", p);
	    #####:  105:		printf("Test FAILED, Council Room is NOT in played pile\n\n");



cardtest4 - salvagerCard()
--------------------------
	Coverage details of cardtest2
		Lines executed: 87.50% of 96
		Branches executed: 100.00% of 36
		Taken at least once: 66.67% of 36
		Calls executed: 80.00% of 60
	This unit test covered 31.21% of 580 lines in dominion.c

	There were some '####' unexecuted lines in my test. 
	    #####:   69:		printf("Test FAILED, card is NOT present in player %d's hand\n\n", p);
	    #####:   82:			cardStatus = 1;	//Card is present in hand
	    #####:   90:		printf("Test FAILED, card is present in player %d's hand\n\n", p);
	    #####:   96:		printf("Test PASSED, Player %d has +1 numBuys\n\n", p);
	    #####:  107:		printf("Test FAILED, %d cards left in player %d's hand\n\n",  numHandCards(GS), p);
	    #####:  113:		printf("Test PASSED, current coins is %d\n", GS->coins);
	    #####:  153:		printf("Test FAILED, card is NOT present in player %d's hand\n\n", p);
	    #####:  166:			cardStatus = 1;	//Card is present in hand
	    #####:  174:		printf("\nTest FAILED, card is present in player %d's hand\n\n", p);
	    #####:  180:		printf("Test PASSED, Player %d has +1 numBuys\n\n", p);
	    #####:  191:		printf("Test FAILED, %d cards left in player %d's hand\n\n",  numHandCards(state), p);
	    #####:  197:		printf("Test PASSED, current coins is %d\n\n", state->coins);



dominion.c Coverage
---------------------
	Coverage details of cardtest2
		Lines executed: 31.21% of 580
		Branches executed: 31.65% of 417
		Taken at least once: 23.02% of 417
		Calls executed: 21.05% of 95

	Unexecuted lines '####' in dominion.c
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
	    #####:  670:	  adventurerCard (drawntreasure, state, currentPlayer, cardDrawn, temphand, z); //function call
	    #####:  671:      return 0;
	    #####:  674:	  councilRoomCard(currentPlayer, state, handPos); //function call
	    #####:  675:      return 0;
	    #####:  680:      for (i = 0; i <= state->handCount[currentPlayer]; i++){
	    #####:  681:	temphand[i] = state->hand[currentPlayer][i];//Backup card
	    #####:  682:	state->hand[currentPlayer][i] = -1;//Set to nothing
	    #####:  687:      updateCoins(currentPlayer, state, 5);
	    #####:  688:      x = 1;//Condition to loop on
	    #####:  689:      while( x == 1) {//Buy one card
	    #####:  690:	if (supplyCount(choice1, state) <= 0){
	    #####:  691:	  if (DEBUG)
	    #####:  694:	  if (DEBUG){
	    #####:  698:	else if (state->coins < getCost(choice1)){
	    #####:  699:	  printf("That card is too expensive!\n");
	    #####:  701:	  if (DEBUG){
	    #####:  707:	  if (DEBUG){
	    #####:  711:	  gainCard(choice1, state, 0, currentPlayer);//Gain the card
	    #####:  712:	  x = 0;//No more buying cards
	    #####:  714:	  if (DEBUG){
	    #####:  722:      for (i = 0; i <= state->handCount[currentPlayer]; i++){
	    #####:  723:	state->hand[currentPlayer][i] = temphand[i];
	    #####:  724:	temphand[i] = -1;
	    #####:  728:      return 0;
	    #####:  731:      return -1;
	    #####:  734:      j = state->hand[currentPlayer][choice1];  //store card we will trash
	    #####:  736:      if (state->hand[currentPlayer][choice1] < copper || state->hand[currentPlayer][choice1] > gold)
	    #####:  738:	  return -1;
	    #####:  741:      if (choice2 > treasure_map || choice2 < curse)
	    #####:  743:	  return -1;
	    #####:  746:      if ( (getCost(state->hand[currentPlayer][choice1]) + 3) > getCost(choice2) )
	    #####:  748:	  return -1;
	    #####:  751:      gainCard(choice2, state, 2, currentPlayer);
	    #####:  754:      discardCard(handPos, currentPlayer, state, 0);
	    #####:  757:      for (i = 0; i < state->handCount[currentPlayer]; i++)
	    #####:  759:	  if (state->hand[currentPlayer][i] == j)
	    #####:  761:	      discardCard(i, currentPlayer, state, 0);			
	    #####:  762:	      break;
	    #####:  766:      return 0;
	    #####:  769:      j = state->hand[currentPlayer][choice1];  //store card we will trash
	    #####:  771:      if ( (getCost(state->hand[currentPlayer][choice1]) + 2) > getCost(choice2) )
	    #####:  773:	  return -1;
	    #####:  776:      gainCard(choice2, state, 0, currentPlayer);
	    #####:  779:      discardCard(handPos, currentPlayer, state, 0);
	    #####:  782:      for (i = 0; i < state->handCount[currentPlayer]; i++)
	    #####:  784:	  if (state->hand[currentPlayer][i] == j)
	    #####:  786:	      discardCard(i, currentPlayer, state, 0);			
	    #####:  787:	      break;
	    #####:  792:      return 0;
	    #####:  795:	  smithyCard(currentPlayer, state, handPos); //function call
	    #####:  796:      return 0;
	    #####:  800:      drawCard(currentPlayer, state);
	    #####:  803:      state->numActions = state->numActions + 2;
	    #####:  806:      discardCard(handPos, currentPlayer, state, 0);
	    #####:  807:      return 0;
	    #####:  810:      state->numBuys++;//Increase buys by 1!
	    #####:  811:      if (choice1 > 0){//Boolean true or going to discard an estate
	    #####:  812:	int p = 0;//Iterator for hand!
	    #####:  813:	int card_not_discarded = 1;//Flag for discard set!
	    #####:  814:	while(card_not_discarded){
	    #####:  815:	  if (state->hand[currentPlayer][p] == estate){//Found an estate card!
	    #####:  816:	    state->coins += 4;//Add 4 coins to the amount of coins
	    #####:  817:	    state->discard[currentPlayer][state->discardCount[currentPlayer]] = state->hand[currentPlayer][p];
	    #####:  818:	    state->discardCount[currentPlayer]++;
	    #####:  819:	    for (;p < state->handCount[currentPlayer]; p++){
	    #####:  820:	      state->hand[currentPlayer][p] = state->hand[currentPlayer][p+1];
	    #####:  822:	    state->hand[currentPlayer][state->handCount[currentPlayer]] = -1;
	    #####:  823:	    state->handCount[currentPlayer]--;
	    #####:  824:	    card_not_discarded = 0;//Exit the loop
	    #####:  826:	  else if (p > state->handCount[currentPlayer]){
	    #####:  827:	    if(DEBUG) {
	    #####:  831:	    if (supplyCount(estate, state) > 0){
	    #####:  832:	      gainCard(estate, state, 0, currentPlayer);
	    #####:  833:	      state->supplyCount[estate]--;//Decrement estates
	    #####:  834:	      if (supplyCount(estate, state) == 0){
	    #####:  835:		isGameOver(state);
	    #####:  838:	    card_not_discarded = 0;//Exit the loop
	    #####:  842:	    p++;//Next card
	    #####:  848:	if (supplyCount(estate, state) > 0){
	    #####:  849:	  gainCard(estate, state, 0, currentPlayer);//Gain an estate
	    #####:  850:	  state->supplyCount[estate]--;//Decrement Estates
	    #####:  851:	  if (supplyCount(estate, state) == 0){
	    #####:  852:	    isGameOver(state);
	    #####:  858:      return 0;
	    #####:  861:	  greatHallCard(currentPlayer, state, handPos); //function call
	    #####:  862:      return 0;
	    #####:  866:      state->numActions++;
	    #####:  869:      discardCard(handPos, currentPlayer, state, 0);
	    #####:  871:      if (choice1)		//+2 coins
	    #####:  873:	  state->coins = state->coins + 2;
	    #####:  876:      else if (choice2)		//discard hand, redraw 4, other players with 5+ cards discard hand and draw 4
	    #####:  879:	  while(numHandCards(state) > 0)
	    #####:  881:	      discardCard(handPos, currentPlayer, state, 0);
	    #####:  885:	  for (i = 0; i < 4; i++)
	    #####:  887:	      drawCard(currentPlayer, state);
	    #####:  891:	  for (i = 0; i < state->numPlayers; i++)
	    #####:  893:	      if (i != currentPlayer)
	    #####:  895:		  if ( state->handCount[i] > 4 )
	    #####:  898:		      while( state->handCount[i] > 0 )
	    #####:  900:			  discardCard(handPos, i, state, 0);
	    #####:  904:		      for (j = 0; j < 4; j++)
	    #####:  906:			  drawCard(i, state);
	    #####:  913:      return 0;
	    #####:  916:      if (choice1 == 1)
	    #####:  919:	  drawCard(currentPlayer, state);
	    #####:  920:	  drawCard(currentPlayer, state);
	    #####:  922:      else if (choice1 == 2)
	    #####:  925:	  state->coins = state->coins + 2;
	    #####:  930:	  discardCard(choice2, currentPlayer, state, 1);
	    #####:  931:	  discardCard(choice3, currentPlayer, state, 1);
	    #####:  935:      discardCard(handPos, currentPlayer, state, 0);
	    #####:  936:      return 0;
	    #####:  939:      if ((state->discardCount[nextPlayer] + state->deckCount[nextPlayer]) <= 1){
	    #####:  940:	if (state->deckCount[nextPlayer] > 0){
	    #####:  941:	  tributeRevealedCards[0] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
	    #####:  942:	  state->deckCount[nextPlayer]--;
	    #####:  944:	else if (state->discardCount[nextPlayer] > 0){
	    #####:  945:	  tributeRevealedCards[0] = state->discard[nextPlayer][state->discardCount[nextPlayer]-1];
	    #####:  946:	  state->discardCount[nextPlayer]--;
	    #####:  950:	  if (DEBUG){
	    #####:  957:	if (state->deckCount[nextPlayer] == 0){
	    #####:  958:	  for (i = 0; i < state->discardCount[nextPlayer]; i++){
	    #####:  959:	    state->deck[nextPlayer][i] = state->discard[nextPlayer][i];//Move to deck
	    #####:  960:	    state->deckCount[nextPlayer]++;
	    #####:  961:	    state->discard[nextPlayer][i] = -1;
	    #####:  962:	    state->discardCount[nextPlayer]--;
	    #####:  965:	  shuffle(nextPlayer,state);//Shuffle the deck
	    #####:  967:	tributeRevealedCards[0] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
	    #####:  968:	state->deck[nextPlayer][state->deckCount[nextPlayer]--] = -1;
	    #####:  969:	state->deckCount[nextPlayer]--;
	    #####:  970:	tributeRevealedCards[1] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
	    #####:  971:	state->deck[nextPlayer][state->deckCount[nextPlayer]--] = -1;
	    #####:  972:	state->deckCount[nextPlayer]--;
	    #####:  975:      if (tributeRevealedCards[0] == tributeRevealedCards[1]){//If we have a duplicate card, just drop one 
	    #####:  976:	state->playedCards[state->playedCardCount] = tributeRevealedCards[1];
	    #####:  977:	state->playedCardCount++;
	    #####:  978:	tributeRevealedCards[1] = -1;
	    #####:  981:      for (i = 0; i <= 2; i ++){
	    #####:  982:	if (tributeRevealedCards[i] == copper || tributeRevealedCards[i] == silver || tributeRevealedCards[i] == gold){//Treasure cards
	    #####:  983:	  state->coins += 2;
	    #####:  986:	else if (tributeRevealedCards[i] == estate || tributeRevealedCards[i] == duchy || tributeRevealedCards[i] == province || tributeRevealedCards[i] == gardens || tributeRevealedCards[i] == great_hall){//Victory Card Found
	    #####:  987:	  drawCard(currentPlayer, state);
	    #####:  988:	  drawCard(currentPlayer, state);
	    #####:  991:	  state->numActions = state->numActions + 2;
	    #####:  995:      return 0;
	    #####:  998:      j = 0;		//used to check if player has enough cards to discard
	    #####: 1000:      if (choice2 > 2 || choice2 < 0)
	    #####: 1002:	  return -1;				
	    #####: 1005:      if (choice1 == handPos)
	    #####: 1007:	  return -1;
	    #####: 1010:      for (i = 0; i < state->handCount[currentPlayer]; i++)
	    #####: 1012:	  if (i != handPos && i == state->hand[currentPlayer][choice1] && i != choice1)
	    #####: 1014:	      j++;
	    #####: 1017:      if (j < choice2)
	    #####: 1019:	  return -1;				
	    #####: 1022:      if (DEBUG) 
	    #####: 1026:      state->supplyCount[state->hand[currentPlayer][choice1]] += choice2;
	    #####: 1029:      for (i = 0; i < state->numPlayers; i++)
	    #####: 1031:	  if (i != currentPlayer)
	    #####: 1033:	      gainCard(state->hand[currentPlayer][choice1], state, 0, i);
	    #####: 1038:      discardCard(handPos, currentPlayer, state, 0);			
	    #####: 1041:      for (j = 0; j < choice2; j++)
	    #####: 1043:	  for (i = 0; i < state->handCount[currentPlayer]; i++)
	    #####: 1045:	      if (state->hand[currentPlayer][i] == state->hand[currentPlayer][choice1])
	    #####: 1047:		  discardCard(i, currentPlayer, state, 1);
	    #####: 1048:		  break;
	    #####: 1053:      return 0;
	    #####: 1057:      updateCoins(currentPlayer, state, 2);
	    #####: 1058:      for (i = 0; i < state->numPlayers; i++)
	    #####: 1060:	  if (i != currentPlayer)
	    #####: 1062:	      for (j = 0; j < state->handCount[i]; j++)
	    #####: 1064:		  if (state->hand[i][j] == copper)
	    #####: 1066:		      discardCard(j, i, state, 0);
	    #####: 1067:		      break;
	    #####: 1069:		  if (j == state->handCount[i])
	    #####: 1071:		      for (k = 0; k < state->handCount[i]; k++)
	    #####: 1073:			  if (DEBUG)
	    #####: 1076:		      break;
	    #####: 1085:      discardCard(handPos, currentPlayer, state, 0);			
	    #####: 1087:      return 0;
	    #####: 1092:      state->coins = state->coins + 2;
	    #####: 1095:      if ( state->supplyCount[choice1] == -1 )
	    #####: 1097:	  return -1;
	    #####: 1101:      state->embargoTokens[choice1]++;
	    #####: 1104:      discardCard(handPos, currentPlayer, state, 1);		
	    #####: 1105:      return 0;
	    #####: 1109:      state->outpostPlayed++;
	    #####: 1112:      discardCard(handPos, currentPlayer, state, 0);
	    #####: 1113:      return 0;
	    #####: 1116:	  salvagerCard(state, choice1, currentPlayer, handPos); //function call
	    #####: 1117:      return 0;
	    #####: 1120:      for (i = 0; i < state->numPlayers; i++){
	    #####: 1121:	if (i != currentPlayer){
	    #####: 1122:	  state->discard[i][state->discardCount[i]] = state->deck[i][state->deckCount[i]--];			    state->deckCount[i]--;
	    #####: 1123:	  state->discardCount[i]++;
	    #####: 1124:	  state->deck[i][state->deckCount[i]--] = curse;//Top card now a curse
	    #####: 1127:      return 0;
	    #####: 1131:      index = -1;
	    #####: 1132:      for (i = 0; i < state->handCount[currentPlayer]; i++)
	    #####: 1134:	  if (state->hand[currentPlayer][i] == treasure_map && i != handPos)
	    #####: 1136:	      index = i;
	    #####: 1137:	      break;
	    #####: 1140:      if (index > -1)
	    #####: 1143:	  discardCard(handPos, currentPlayer, state, 1);
	    #####: 1144:	  discardCard(index, currentPlayer, state, 1);
	    #####: 1147:	  for (i = 0; i < 4; i++)
	    #####: 1149:	      gainCard(gold, state, 1, currentPlayer);
	    #####: 1153:	  return 1;
	    #####: 1157:      return -1;
	    #####: 1160:  return -1;
	    #####: 1186:      state->handCount[currentPlayer]--;
	    #####: 1201:int gainCard(int supplyPos, struct gameState *state, int toFlag, int player)
	    #####: 1206:  if ( supplyCount(supplyPos, state) < 1 )
	    #####: 1208:      return -1;
	    #####: 1216:  if (toFlag == 1)
	    #####: 1218:      state->deck[ player ][ state->deckCount[player] ] = supplyPos;
	    #####: 1219:      state->deckCount[player]++;
	    #####: 1221:  else if (toFlag == 2)
	    #####: 1223:      state->hand[ player ][ state->handCount[player] ] = supplyPos;
	    #####: 1224:      state->handCount[player]++;
	    #####: 1228:      state->discard[player][ state->discardCount[player] ] = supplyPos;
	    #####: 1229:      state->discardCount[player]++;
	    #####: 1233:  state->supplyCount[supplyPos]--;
	    #####: 1235:  return 0;
	    #####: 1272:	  shuffle(currentPlayer, state);
	    #####: 1279:	  temphand[z]=cardDrawn;
	    #####: 1280:	  state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
	    #####: 1281:	  z++;
	    #####: 1285:	state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
	    #####: 1286:	z=z-1;
	    #####: 1350:int greatHallCard(int currentPlayer, struct gameState* state, int handPos){
	    #####: 1352:      drawCard(currentPlayer, state);
	    #####: 1355:      state->numActions++;
	    #####: 1358:      discardCard(handPos, currentPlayer, state, 0);
	    #####: 1359:	  return 0;
