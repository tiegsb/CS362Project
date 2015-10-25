Billy Kerns
CS 362
Documentation

smithy:
	The smithy card adds three cards to the hand of the player who played the smithy card.  Once this is completed the card is
	discarded from the player''s hand and goes into their played card pile.  This is done with a for loop that runs three times,
	calling drawCard() on each iteration, and then calling the discardCard() function after exiting the loop.

adventurer:
	The adventurer card allows the player who plays the card to go through their deck until two treasure cards are found.  These
	treasure cards are put into the player's hand while the revealed cards are placed in the played	card pile.  This is accomplished
	by running a while loop that runs while the variable drawntreasure is less than two.  In the while loop it checks to make sure
	the player has more than one card in their deck, if not the played card pile is shuffled and added to the player's deck.  Then a 
	card is drawn with the drawcard() function.  The variable cardDrawn is set to the top card of the player's hand.  The cardDrawn
	variable is checked to see if it is a treasure card.  If it is then the drawntreasure variable is incremented.  Else the cardDrawn
	is added to temp hand at z and the top card is removed.  z is incremented and the while loop goes back to the top.  After the while
	loop is exited another while loop is started that gets rid of the non treasure cards that were drawn.

discardCard():
	The discardCard() function will discard a card when called.  This is done by first entering an if statement that checks if trashFlag
	has been set.  If it has not been set then the card is added to the played pile and playedCardCount is incremented.  Then the played
	card is set to -1.  Another if block is entered which first checks if the card is the last card in the array.  If it is, the player's 
	hand count is decremented.  Else if the player only has one card in their hand the player's hand count is decremented.  If neither of 
	these conditions are met then the discarded card is replaced with last card, the last card is set to -1, and handCount is decremented.

updateCoins():
	The updateCoins() function uses a for loop and few if statements to update the amount of coins a player has in their hand.  This is 
	accomplished by first setting coins equal to 0 then entering the for loop.  Once in the for loop if statements check to if the card
	is a copper, silver, or gold and if it is the appropriate amount of coins are added to the state.  After this has been done a user's 
	bonus is added to the total amount of coins.
