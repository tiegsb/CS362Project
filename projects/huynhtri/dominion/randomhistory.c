/**********************************************************
Solomon Huynh
CS362 Assignment 4
randomhistory.c
**********************************************************/

/**********************************************************
Smithy Card (randomtestcard.out) analysis:

Random test method:
The smithy card was developed using randomization of both the player
and the card positioning. With a max of 4 players, it would loop
2000 times and pick a random player to test the results in. Then
the card position is randomized from 10 positions and when then it
would run the function. Once the function runs, it would then check
for three things: 1) if the smithy card is not in the hand, 2) if
the cards drawn is 3, and 3) if the card is put into the played pile.
The program keeps a running count if there are any errors in the
areas tested.

Bugs caught:
The bugs caught would be the number of cards drawn from when I created
bugs during assignment 2. The test results showed 200 errors on cards
drawn because it only draws 2 cards instead of 3.

Coverage:
This random testing is still the same 100% coverage compared to the
last time it was covered excepted it was ran more often. The last time,
the test coverage was 100% but was ran only 4 times each whereas this
testing covered over 2000 times on each line of code. This proves
to be more effective and given assurance that this program works. Note
that the coverage and branch testing are 100%.

Coverage testing pulled from gcov:
     2000:  231:void smithyCard(struct gameState *state, int handPos){
        -:  232:    //Declare all variables needed
        -:  233:    int i;
     2000:  234:    int currentPlayer = whoseTurn(state);
        -:  235:
        -:  236:    //+3 Cards
     6000:  237:    for (i = 0; i < 2; i++)
        -:  238:	{
     4000:  239:	  drawCard(currentPlayer, state);
        -:  240:	}
        -:  241:
        -:  242:    //discard card from hand
     2000:  243:    discardCard(handPos, currentPlayer, state, 0);
     2000:  244:    return;
        -:  245:}
**********************************************************/

/**********************************************************
Adventurer Card (randomtestadventurer.out) analysis:

Random test method:
This testing method on the adventurer card is done through randomizing
the cards using a specific formula to randomly put all possible cards
into the deck with a little weight on treasure cards to contain more
than 2 treasures. Then the testing function ran the card and checked
the count of the treasure cards drawn.

The testing function also checked if the card was removed from hand
and if it was discarded properly every time.

Bugs caught:
There were a couple of major bugs that were found. The first thing
noted was the number of silver cards that were picked up out of the
number of tests that I did which was 0. Looking back at the code,
it was noted that treasure cards only count for copper and gold so
with no silver card in the statement meant that this is wrong.

Another bug found was that the card was never removed from the hand
and it did not appear in the played pile. Looking at the code, the
discard function was not used in the adventurerCard function so
so it was an obvious bug due to the card not being discarded at all.

Coverage:
The coverage for this test is 94% because shuffle was not being initialized
due to the test being restarted every iteration of the test. I deemed it
to not be needed to test because the testing shuffling should be done
separately. Other than that, the tests covered everything and made sure
to check if the functionally worked properly. Unfortunately, there were
bugs found that would cause major problems in the game so it needs to
be addressed. The code coverage was mostly done and the branch coverage
covered everything except for the shuffle function which is OK at this
point.

Coverage testing pulled from gcov:
       20:  202:void adventurerCard(struct gameState *state){
        -:  203:    //Declare all variables needed
       20:  204:    int currentPlayer = whoseTurn(state);
       20:  205:    int drawntreasure = 0;
       20:  206:    int cardDrawn = 0;
        -:  207:    int temphand[MAX_HAND];// moved above the if statement
       20:  208:    int z = 0;// this is the counter for the temp hand
        -:  209:
      165:  210:    while(drawntreasure<2){
      125:  211:        if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
    #####:  212:          shuffle(currentPlayer, state);
        -:  213:        }
      125:  214:        drawCard(currentPlayer, state);
      125:  215:        cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
      165:  216:        if (cardDrawn == copper || cardDrawn == gold)
       40:  217:          drawntreasure++;
        -:  218:        else{
       85:  219:          temphand[z]=cardDrawn;
       85:  220:          state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
       85:  221:          z++;
        -:  222:        }
        -:  223:    }
      125:  224:    while(z-1>=0){
       85:  225:        state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
       85:  226:        z=z-1;
        -:  227:    }
       20:  228:    return;
        -:  229:}
**********************************************************/
