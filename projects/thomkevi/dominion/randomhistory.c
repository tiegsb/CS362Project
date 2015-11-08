Write up and check in the development of your random testers, including improvements in 
coverage and effort to check the correctness of your specification, as randomhistory.c

Run the following to build the random tests, execute the programs, run gcov and write
randomtestadventurer.out and randomtestcard.out:
   make randomtestadventurer.out
   make randomtestcard.out

randomtestadventurer.c

  Code Coverage Results
  Lines executed:19.93% of 582
  
  This compares to the previous cardtest for the adventurer card which had coverage
  results of Lines executed:19.07% of 582.
  
  A slight improvement has been realized with the implementation of random testing.
  
  A review of the dominion.c.gcov file showed good coverage with the exception of the 
  shuffle function.  Tests to ensure this branch is covered will be noted for 
  future improvement in testing.
  
       2000: 1258:int playAdventurer(struct gameState *state, int currentPlayer)
          -: 1259:{
          -: 1260:
          -: 1261:  int temphand[MAX_HAND];// moved above the if statement
       2000: 1262:  int drawntreasure=0;
          -: 1263:  int cardDrawn;
       2000: 1264:  int z = 0;// this is the counter for the temp hand
          -: 1265:
      10000: 1266:  while(drawntreasure<2){
       6000: 1267:    if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
      #####: 1268:      shuffle(currentPlayer, state);
          -: 1269:    }
       6000: 1270:    drawCard(currentPlayer, state);
       6000: 1271:    cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
      10000: 1272:    if (cardDrawn == copper || cardDrawn == silver && cardDrawn == gold)
       4000: 1273:      drawntreasure++;
          -: 1274:    else{
       2000: 1275:      temphand[z]=cardDrawn;
       2000: 1276:      state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
       2000: 1277:      z++;
          -: 1278:    }
          -: 1279:  }
       6000: 1280:  while(z-1>=0){
       2000: 1281:    state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
       2000: 1282:    z=z-1;
          -: 1283:  }
          -: 1284:  
       2000: 1285:  return 0;
          -: 1286:}
 
  
  The random testing approach ran a series of 1000 games for 2 players with each player
  playing a card.  This gives a total of 2000 random tests.
  
  The tests evaluated the outcome of playing the adventurer card against the game
  specifications.  Test Cases:
  - Test that players handcount increments by 2 cards
  - Test that the 2 new cards are a copper, silver or gold card
  - Test return code from function
  
randomtestcard.c - Random Testing for playCouncilRoom

  Code Coverage Results
  Lines executed:20.62% of 582
  
  This compares to the previous cardtest for the council room card which had coverage
  Lines executed:20.62% of 582
  
  A review of the dominion.c.gcov file showed full coverage for the playCouncilRoom function
  
       2000: 1288:int playCouncilRoom(struct gameState *state, int currentPlayer, int handPos)
          -: 1289:{
          -: 1290:
          -: 1291:  int i;
          -: 1292:
          -: 1293:  //+4 Cards
      10000: 1294:  for (i = 0; i < 4; i++)
          -: 1295:  {
       8000: 1296:    drawCard(currentPlayer, state);
          -: 1297:  }
          -: 1298:
          -: 1299:  //+1 Buy
       2000: 1300:  state->numBuys++;
          -: 1301:
          -: 1302:  //Each other player draws a card
       6000: 1303:  for (i = 0; i < state->numPlayers; i++)
          -: 1304:  {
       4000: 1305:      if (i != currentPlayer)
          -: 1306:      {
       2000: 1307:        drawCard(i, state);
          -: 1308:      }
          -: 1309:  }
          -: 1310:
          -: 1311:  //put played card in played card pile
       2000: 1312:  discardCard(handPos, currentPlayer, state, 0);
          -: 1313:	
       2000: 1314:  return 0;
          -: 1315:}

  Like the randomadventurer test, the random testing approach here ran a series of 1000 games for 2 players with each player
  playing a card.  This gives a total of 2000 random tests.
  
  The tests evaluated the outcome of playing the council room card against the game
  specifications.  Test Cases:
  - Test that players buy count increments by 1
  - Test that players played card count increments by 1
  - Test that the other players cards in hand increments by 1
  - Test that players hand count increases by 3 (+4 cards minus discard council)
  - Test return code from function