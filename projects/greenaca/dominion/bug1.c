unittest1.c: isGameOver()
This function should loop through treasure_map+1 cards which is 27 cards, not 25 cards.

unittest2.c: scoreFor()
There is a bug in the section that gets the score from the discard pile.  There is an off by one scoring issue.

This function when checking the deckCount, loops until the # of elements in the discardCount, not deckCount.

unittest3.c: cardCost()
I found no bugs in this function

unittest4.c: updateCoins()
I found no bugs  in this function

cardtest1.c: smithy_card()
The function has a bug where discardCard() doesn't actually increment discardCount. 
The implemented bug in this function is that it should discard the smithy card rather than trash it.

cardtest2.c: adventurer_card()
I found a lot of different bugs in this function:
First, the function should break after looking through the deck, shuffling in the discard pile, and looking through the deck again, then stop.  Right now the code keeps going.
Second, this function does not discard the adventurer_card at the end of the function.
Third, this function doesn’t check the return value of drawCard, so it ends up checking the last card to be drawn that is currently in the players hand, rather than breaking.  
This is how the function will keep "drawing" a treasure card even when there is no longer one in the deck, it finds one in the players hand.

cardtest3.c: village_card()
This function draws two cards instead of one.  Also discardCard doesn't increment discard.

cardtest4.c: steward_card()
This function trashes one card and discards two cards, instead of trashing two cards and discarding one card.
Although as I mentioned, discardCard doesn't increment discardCount.