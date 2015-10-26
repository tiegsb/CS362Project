Ben Henning
CS 362
Assignment 3
bug1.c

Bugs found:

shuffle():
All tests passed. No bugs found.

isGameOver():
All tests passed. No bugs found.

updateCoins():
All tests passed. No bugs found.

buyCard():
This function failed the final test because the function made changes to phase.
If I account for this difference, the final test passes.  I am unsure if the buyCard
function is supposed to make changes to phase or not, so I am not sure if this is a bug.

Smithy:
According to the tests,the player's hand gains 1 more card than it should and the player's deck loses
1 more card than it should. This indicates 4 cards are being drawn instead of 3.


Adventurer:
1. The player's hand has net gains of several cards where it should have 1. This indicates
that handCount is being incremented when it should not be.  In the code, it appears that
handCount is incremented every time a non-treasure card is drawn when it should be decremented.

2. PlayedCardCount is unchanged when it should be increased by 1.  The top card in playedCards is not
the adventurer.  The adventurer is also still detected in player's hand.  This indicates the adventurer
card is not being discarded after being played.  In dominion.c, the adventurer card function does
not call discard on the played card.


Sea Hag:
1. All the current player's opponents experience no changes to their discard piles.  The top card in
all of the opponents' decks is not a curse card.  This indicates the sea_hag is not giving the other
players a curse card or making them discard the top card from their deck and therefore not effecting
the other players.  In the code for the card, the if statement is telling it to affect the current player
and skip the other players when it should be doing the opposite.

2. The current player's discard pile increased by 1 when it should be unaffected. This is because the card
is working its effect on the current player instead of the others due to the if statement mentioned in 1.

3. Current player's deck count is decreased by 3 when it should be unaffected.  After examining the code,
it seems that not only is the function affecting the current player instead of the other players, but that
it is also decreasing deckCount where it should not be.  Specifically, on lines 95 and 98,
state->deckCount[i] is followed by -- where it should be followed by -1.

4. The code passes the test where the current player is not supposed to have a curse in the deck.
However, when the bug in deckCount is accounted for, the test fails.  This is because of the bug mentioned
in 2.

5. PlayedCardCount is unchanged, the sea hag is not on top of the playedCards pile, and the sea hag
is still found in the player's hand.  This is because the sea hag function is missing a function call
to discard the current card.

Village:
All tests passed. No bugs found.
