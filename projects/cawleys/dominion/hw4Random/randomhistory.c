


randomtestadventurer
File 'dominion.c'
	Lines executed:10.85% of 562
	Branches executed:7.19% of 417
	Taken at least once:7.19% of 417
	Calls executed:5.32% of 94
	Creating 'dominion.c.gcov'

randomtestcard
File 'dominion.c'
	Lines executed:8.36% of 562
	Branches executed:4.80% of 417
	Taken at least once:4.32% of 417
	Calls executed:4.26% of 94
	Creating 'dominion.c.gcov'


with unit testing
File 'dominion.c'
	Lines executed:13.88% of 562
	Branches executed:11.03% of 417
	Taken at least once:9.83% of 417
	Calls executed:6.38% of 94
	Creating 'dominion.c.gcov'

adventurer_effect had 100% branch coverage

		function adventurer_effect called 200 returned 100% blocks executed 100%
		      200: 1293:int adventurer_effect(struct gameState *state, int currentPlayer)
		        -: 1294:{
		      200: 1295:  int drawntreasure=0;
		        -: 1296:  int cardDrawn;
		        -: 1297:  int temphand[MAX_HAND];
		      200: 1298:  int z = 0;
		        -: 1299:
		     2254: 1300:  while(drawntreasure<3){
		branch  0 taken 90%
		branch  1 taken 10% (fallthrough)
		     1854: 1301:    if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
		branch  0 taken 7% (fallthrough)
		branch  1 taken 93%
		      130: 1302:      shuffle(currentPlayer, state);
		call    0 returned 100%
		        -: 1303:    }
		     1854: 1304:    drawCard(currentPlayer, state);
		call    0 returned 100%
		     1854: 1305:    cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
		     1854: 1306:    if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
		branch  0 taken 85% (fallthrough)
		branch  1 taken 15%
		branch  2 taken 80% (fallthrough)
		branch  3 taken 20%
		branch  4 taken 1% (fallthrough)
		branch  5 taken 99%
		      600: 1307:      drawntreasure++;
		        -: 1308:    else{
		     1254: 1309:      temphand[z]=cardDrawn;
		     1254: 1310:      state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
		     1254: 1311:      z++;
		-: 1312:    }
		        -: 1313:  }
		        -: 1314:
		     1654: 1315:  while(z-1>=0){
		branch  0 taken 86%
		branch  1 taken 14% (fallthrough)
		     1254: 1316:    state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
		     1254: 1317:    z=z-1;
		        -: 1318:  }
		      200: 1319:  return 0;
		        -: 1320:
		        -: 1321:}
		        -: 1322:
		        -: 1323:


smithy_effect had 100% branch coverage

	function smithy_effect called 15 returned 100% blocks executed 100%
	       15: 1324:int smithy_effect(struct gameState *state, int currentPlayer, int handPos)
	        -: 1325:{
	       15: 1326:  int i = 0;
	        -: 1327:  //+3 Cards
	       60: 1328:  for (i = 0; i < 3; i++)
	branch  0 taken 75%
	branch  1 taken 25% (fallthrough)
	        -: 1329:    {
	       45: 1330:      drawCard(currentPlayer, state);
	call    0 returned 100%
	        -: 1331:    }
	        -: 1332:
	        -: 1333:  //discard card from hand
	        -: 1334:  //discardCard(handPos, currentPlayer, state, 0);
	       15: 1335:  return 0;
	        -: 1336:}
	        -: 1337:


The over all coverage for dominion.c of these tests was less than that of the unit testing. This makes sense though as only one 
funciton is being called here, where as with the unit testing there were 8 functions called. Within each function there was 100%.

The errors in both functions were consistant:

For smithy_effect()
	PASS: Smithy() had the correct cards in the deck at the end 15 or 15 times
	FAIL: Smithy() had the correct number of cards in the hand 0 of 15 times
	FAIL: Smithy() had the correct number of cards in the Played Cards at the end 0 times
	FAIL: Smithy() had the correct number of Smithies in the played Cards 0 of 15 times

The error for smithy is that the smithy is not discarded at the end of the hand, this is consistant with the test results. To check the accuracy of 
the tests I fixed the error in smithy and the tests all worked perfectly

For adventurer_effect()
	The Adventurer() tests were run 200 times
	FAIL: Adventurer() did not have 2 extra coins at the end 186 out of 200 times
	FAIL: Adventurer() the adventurer card was not not added to played cards 200 of 200 times
	FAIL: Adventurer() the non coin cards were not properly discarded 14 of 200 times
	FAIL: Adventurer() did not end with the correct number of cards in the hand 200 of 200 times

Testing the adventurer_effect was a bit harder, I had trouble getting the tests to return the correct values, even when I took the bug that I introduced out. 
I have gone over the origional adventurer code and I can't see where the adventurer card is being discarded, I think this is what is causing the majority of
my testing issues. When taking the bug out (adding 3 coins instead of 2) most of the tests worked, but I could not get the discard tests to work. I had the 
test print out the number of cards in the hand each time, and it was always 1 more than it should have been.