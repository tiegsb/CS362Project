James Carlin
Documentation.c


Smithy

	Each time the smithy card is called, the player draws 3 cards from their deck. In order to do this, the drawcall function is looped 3 times. It consumes 1 action point.

Adventurer

	The adventurer card allows a player to draw cards until the player receives 2 coins. The adventurer function has a while loop that draws cards and checks to see their value. If there is a treasure card, it adds it to the hand. If there is a non-treasure card, it is not added to the hand and is instead added to a temp hand, which is held in an array. That array that holds the cards not being placed in the hand are then discarded. The loop stops once two treasure cards are attained.


discardCard
	Discard card has two options. It looks at a card marked for discard by the player and that card will be placed into "played cards" or discarded. 


updateCoins

	The update coins function takes a look at the player's hand and increments a player's treasure value based on what is found in the hand. It loops through the hand to do this. It can also look at a variable called bonus which changes how treasure is added. 