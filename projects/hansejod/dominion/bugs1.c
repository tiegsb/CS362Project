Jody Hansen
Assignment 3

unittest1:
This unit test tests the relatively simple compare() function in the dominion.c file (Line 8).
The program returns one of three values 1, -1, and 0 depending on if the values pass are greater
than, smaller than, or equal. There were no bugs discovered.

unittest2:
The program tests the isGameOver() function. The function returns a 1 if the game is to conclude.
It does so when the province cards are set to 0 and does not end when they are any other value.
The game also finishes when any three of the supply card counts are at 0. At first the function
did not appear to have any bugs, but I based my unit testing by looking at the code. I realized
later that there are a total of 27 supply, but the function only evaluates 26. This causes an
error periodically when the last card is set to 0 and the program does not correctly include that
card in its counts.

unittest3:
My tests of shuffle() function did not uncover any bugs. The program returned -1 when the cardDeck
count was 0 and shuffled the deck when it was 1 or more.

unittest4:
The unit test of buyCard() behaved as expected when the number of buys, the supply count of the
card, or the coins was at 0. As in it returned a -1. However, a bug was exposed when the
gainCard() is called. The hand count is not increased by one as expected. The third argument
of the function call should be a 2 instead of a 0.

cardtest1:
I changed the loop counter from a post-fix to pre-fix. However, the Smithy() function appears to
behave as expected. The player discards one card and gains three more.

cardtest2:
The Adventurer() function has several bugs. The function arguments, particularly temphand are
passed incorrectly, which does come up as a warning. As a side effect, it does not properly
discard cards and the temphand array is not added to during several rounds of testing.

cardtest3:
The unit test for the councilRoom() found two bugs. The numBuys is not increased due to a bug
I introduced. Oddly, the function appeared to have its own bug since the total count is not
increased by three. My suspicion is that the bug is in the drawCard function within the
councilRoom program.

cardtest4:
The unit test discovered two bugs in the seaHag() function. The program does not appear to set the
top card of the other player to a curse card. The other bug is that the program improperly tries
to reference the top card by using the following statement, state->deck[i][state->deckCount[i]--,
each time the program does this it decreases the deckCount by one. As a result the deckCount is
decreased by three each time the program is called.