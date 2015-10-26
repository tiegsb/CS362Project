/*************************************************
* Name: Solomon Huynh
* Class: CS362 Software Engineering 2
* Term: Fall 2015
* File: bugs1.c
* Description: Summary of all bugs founds and descriptions of it.
**************************************************/

/*************************************************
Bugs found:

File: unittest1.c
Function: isGameOver
Bugs:
1) Recap that rules for game over are either to have no
province cards in the supply or three card supplies being
depleted. When testing the function, it was noticed that
it was checking if 25 cards are have no supplies left
rather than the 27 cards that are available in the game.
This is an obvious bug because the last two cards being
depleted would not be checked at all.
_________________________________________________________________
File: unittest2.c
Function: updateCoins
Bugs: No bugs found
_________________________________________________________________
File: unittest3.c
Function: buyCard
Bugs: No bugs founds
_________________________________________________________________
File: unittest4.c
Function: getCost
Bugs: No bugs found
_________________________________________________________________
File: cardtest1.c
Function: smithyCard
Bugs:
1) The number of cards drawn is 2 instead of 3. This
was confirmed after the smithy card was used and checked
the number of cards in hand, which is only 2.
2) Not really a bug, but the function name discardCard()
confuses users because we assume that the card would go
into the discard pile when it just goes into the played
pile. Had to change testing file to adjust to check for
played cards rather than discarded card.
_________________________________________________________________
File: cardtest2.c
Function: adventurerCard
Bugs:
1) The adventurerCard function does not discard the
card used so after the card is played, it remains to
be in the player's hand along with the two treasure
cards drawn.
2) The hand count and played cards does not update
after playing adventurer card and is affected due
to the bug reported above.
3) Doing a count of the treasured picked, after the
card was used, silver was not ever picked up.
After looking at the code, the function only picks
up copper and gold cards.
_________________________________________________________________
File: cardtest3.c
Function: councilRoomCard
Bugs:
1) The number of cards drawn were 3 instead of 4. The
number of buys and other players drawing 1 card are
correct.
_________________________________________________________________
File: cardtest4.c
Function: villageCard
Bugs:
1) The number of actions increased should be 2 but it
increased to three instead. The rest of the tests
of drawing one card and discarding a card passed.

**************************************************/
