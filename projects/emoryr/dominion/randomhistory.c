/*
Adventurer_Play info:

Coverage information is the same. I had 100% statement and branch coverage in the last assignment and still do.

 Loop needed at the beginning of the adventurer_play function to make sure there are at least 2 treasure cards in the deck + discard.
 This is not garunteed as there could be treasure cards already in your hand, so the three coppers you start with might not be enough.
 If there are not enough treasures in the deck + discard. The loop will keep going forever.

Insert this code to fix the problem
 int cnt = 0;
    for (int i = 0; i < state->deckCount[currentPlayer]; i++) {
      int card = state->deck[currentPlayer][i];
        if (card == gold || card == silver || card == copper) {
            cnt++;
        }
    }
    
    for (int i = 0; i < state->discardCount[currentPlayer]; i++) {
      int card = state->discard[currentPlayer][i];
        if (card == gold || card == silver || card == copper) {
            cnt++;
        }
    }
    if (cnt < 2) {
        return -1;
    }

Had to change function by adding code above to stop seg fault.

The adventurer card is not discarded at the end of this function, even though it should be. This makes the handCount off by one. There are 2 cards added
to the hand instead of 1.

Insert this code at the end of the function to fix the problem
//discardCard(handPos, currentPlayer, state, 0);
//Bug (line needed to fix adventurer_play)

*Bug 5 in bug report
The gold cards are not counted as treasures, this is an expected bug and was inserted by me. The assert statement checking if there are any treasures in the
discard fails for this reason.

This random tester brought up the case in which there are not enough treasure cards in the deck + discard. This was not previously tested.
I also understood the specification better after using this tester, enough to know that the adventurer card should have been discarded. This
was anther functionality not tested by my original tester.

 */

/*
smithy test function:

Coverage information is the same. I had 100% statement and branch coverage in the last assignment and still do.

There is a bug in the conditional loop of the smithy function. This was reported in the previous bug report.

There also need to be conditional statements protecting the drawCard function. If the deck is empty, you need to shuffle.
Also, if the deck + discard < 2 for some reason, the function will not be able to draw 3 cards and the number of cards in the player's hand will
be incorrect.

Add these lines to fix this bug:

if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
            shuffle(currentPlayer, state);
        }
        if ((state->deckCount[currentPlayer] + state->discardCount[currentPlayer]) < 4) {
          return -1;
        }

These conditional statements did not come up without random testing. Random testing helps get your system into a state that might not occur very frequently and
fix any bugs that might come up. This is extremely helpful in building software that will not fail.

*/