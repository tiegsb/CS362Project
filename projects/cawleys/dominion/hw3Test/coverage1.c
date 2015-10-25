

When running the entire program I had the following coverage:

	File 'dominion.c'
	Lines executed:13.88% of 562
	Branches executed:11.03% of 417
	Taken at least once:9.83% of 417
	Calls executed:6.38% of 94
	Creating 'dominion.c.gcov'

When looking at each function that I modifed the coverage rusults are very good however:

unittest1 (compare)
	
	function compare called 3 returned 100% blocks executed 100%
        3:   13:int compare(const void* a, const void* b) {
        3:   14:  if (*(int*)a > *(int*)b)
	branch  0 taken 33% (fallthrough)
	branch  1 taken 67%
        1:   15:    return 1;
        2:   16:  if (*(int*)a < *(int*)b)
	branch  0 taken 50% (fallthrough)
	branch  1 taken 50%
        1:   17:    return -1;
        1:   18:  return 0;
        -:   19:}
        -:   20:



unitest2 (whoseTurn)

	function whoseTurn called 3 returned 100% blocks executed 100%
        3:  351:int whoseTurn(struct gameState *state) {
        3:  352:  return state->whoseTurn;
        -:  353:}
        -:  354:


unittest3 (updateCoins)

	function updateCoins called 7 returned 100% blocks executed 100%
        7: 1260:int updateCoins(int player, struct gameState *state, int bonus)
        -: 1261:{
        -: 1262:  int i;
        -: 1263:
        -: 1264:  //reset coin count
        7: 1265:  state->coins = 0;
        -: 1266:
        -: 1267:  //add coins for each Treasure card in player's hand
       22: 1268:  for (i = 0; i < state->handCount[player]; i++)


unittest4 (fullDeckCount)

	function fullDeckCount called 7 returned 100% blocks executed 100%
        7:  329:int fullDeckCount(int player, int card, struct gameState *state) {
        -:  330:  int i;
        7:  331:  int count = 0;
        -:  332:
       42:  333:  for (i = 0; i < state->deckCount[player]; i++)
	branch  0 taken 83%
	branch  1 taken 17% (fallthrough)
        -:  334:    {
       35:  335:      if (state->deck[player][i] == card) count++;
	branch  0 taken 14% (fallthrough)
	branch  1 taken 86%
        -:  336:    }
        -:  337:
       42:  338:  for (i = 0; i < state->handCount[player]; i++)
	branch  0 taken 83%
	branch  1 taken 17% (fallthrough)
        -:  339:    {
       35:  340:      if (state->hand[player][i] == card) count++;
	branch  0 taken 14% (fallthrough)
	branch  1 taken 86%
        -:  341:    }
        -:  342:
       42:  343:  for (i = 0; i < state->discardCount[player]; i++)
	branch  0 taken 83%
	branch  1 taken 17% (fallthrough)
        -:  344:    {
       35:  345:      if (state->discard[player][i] == card) count++;
       branch  0 taken 14% (fallthrough)
	branch  1 taken 86%
        -:  346:    }
        -:  347:
        7:  348:  return count;
        -:  349:}
        -:  350:



cardtest1 (smithy)

	function smithy_effect called 1 returned 100% blocks executed 100%
        1: 1324:int smithy_effect(struct gameState *state, int currentPlayer, int handPos)
        -: 1325:{
        1: 1326:  int i = 0;
        -: 1327:  //+3 Cards
        4: 1328:  for (i = 0; i < 3; i++)
	branch  0 taken 75%
	branch  1 taken 25% (fallthrough)
        -: 1329:    {
        3: 1330:      drawCard(currentPlayer, state);
	call    0 returned 100%
        -: 1331:    }
        -: 1332:
        -: 1333:  //discard card from hand
        -: 1334:  //discardCard(handPos, currentPlayer, state, 0);
        1: 1335:  return 0;
        -: 1336:}
        -: 1337:

cardtest2 (adventurer)

	function adventurer_effect called 1 returned 100% blocks executed 93%
        1: 1293:int adventurer_effect(struct gameState *state, int currentPlayer)
        -: 1294:{
        1: 1295:  int drawntreasure=0;
        -: 1296:  int cardDrawn;
        -: 1297:  int temphand[MAX_HAND];
        1: 1298:  int z = 0;
        -: 1299:
        7: 1300:  while(drawntreasure<3){
	branch  0 taken 83%
	branch  1 taken 17% (fallthrough)
        5: 1301:    if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
	branch  0 taken 0% (fallthrough)
	branch  1 taken 100%
    #####: 1302:      shuffle(currentPlayer, state);
	call    0 never executed
        -: 1303:    }
        5: 1304:    drawCard(currentPlayer, state);
	call    0 returned 100%
        5: 1305:    cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
        5: 1306:    if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
	branch  0 taken 80% (fallthrough)
	branch  1 taken 20%
	branch  2 taken 75% (fallthrough)
	branch  3 taken 25%
	branch  4 taken 33% (fallthrough)
	branch  5 taken 67%
        3: 1307:      drawntreasure++;
        -: 1308:    else{
        2: 1309:      temphand[z]=cardDrawn;
        2: 1310:      state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
        2: 1311:      z++;
        -: 1312:    }
        -: 1313:  }
        -: 1314:
        4: 1315:  while(z-1>=0){
	branch  0 taken 67%
	branch  1 taken 33% (fallthrough)
        2: 1316:    state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
        2: 1317:    z=z-1;
        -: 1318:  }
        1: 1319:  return 0;
        -: 1320:
        -: 1321:}
        -: 1322:
        -: 1323:



cardtest3 (village)

	function village_effect called 1 returned 100% blocks executed 100%
        1: 1338:int village_effect(struct gameState *state, int currentPlayer, int handPos)
        -: 1339:{
        -: 1340:  //+1 Card
        1: 1341:  drawCard(currentPlayer, state);
	call    0 returned 100%
        -: 1342:
        -: 1343:  //+2 Actions
        1: 1344:  state->numActions = state->numActions + 4;
        -: 1345:
        -: 1346:  //discard played card from hand
        1: 1347:  discardCard(handPos, currentPlayer, state, 0);
	call    0 returned 100%
        1: 1348:  return 0;
        -: 1349:}
        -: 1350:


cardtest4 (great hall)
	
	function great_hall_effect called 1 returned 100% blocks executed 100%
        1: 1351:int great_hall_effect(struct gameState *state, int currentPlayer, int handPos)
        -: 1352:{
        -: 1353:  //+1 Card
        1: 1354:  drawCard(currentPlayer, state);
	call    0 returned 100%
        -: 1355:
        -: 1356:  //+1 Actions
        1: 1357:  state->numActions--;
        -: 1358:
        -: 1359:  //discard card from hand
        1: 1360:  discardCard(handPos, currentPlayer, state, 0);
	call    0 returned 100%
        1: 1361:  return 0;
        -: 1362:}
        -: 1363:
