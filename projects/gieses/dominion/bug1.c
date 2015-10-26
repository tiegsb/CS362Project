Bugs found:

Found bug with discardCard(). It is not properly increasing the discard count after it is called.
	
Found bug in unittest2 where the player buys a card. The card goes in the discard pile, and not the hand.