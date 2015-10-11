Drew Machowicz
October 6, 2015
Assignment 2 - Documentation

Smithy Card - Playing this card allows the player to draw three additional cards and addes them to the players hand.
However, this card does not provide any additional actions, which means if any action cards are drawn, then they
cannot be played (unless you have extra actions from a previous card). Then the cards are added to the hand by the
drawCard function and the player proceeds with his turn.

Adventurer Card - Playing this card means that cards will be draw continuously until you receive two treasure cards.
That means that the adventurer case is called, which contains a while loop that runs while the treasure cards are fewer
than 2. It shuffles the deck if need be and then draws a card. After that it checks if that card is in fact a treasure
card. If it is a treasure card, then the tresure card counter is increased. If it is not a treasure card then it gets
added to a temporary hand. The loop runs until the player has two treausre cards. At the end of the case all cards
that have been drawn are discarded.

discardCard() - This function first checks to make sure the card was not trashed, if it is not trashed then it is added 
to the played pile and the played card counter is increased. After that it sets the position of the current hand to -1.
After that, it checks if the the card being played is the last card in the hand array or if it is the only card in the hand and
reduces the current player hand count by 1. If it is not either of these cases then it replaces the discarded card with the
last card in the hand, sets the last card to -1 and reduces the number of cards in the hand.

updateCoins() - This function first has a loop that goes through each card to check if it is a treasure card. If it is At
treasure card then it updates the coin total appropriately. Finally, if there are bonus coins from other cards they are added.∑