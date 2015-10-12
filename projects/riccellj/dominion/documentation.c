riccellj
CS362f15
assn2
Documentation

Smithy Card

This action card, when played, lets the current player draw three cards. This card costs four cards to purchase by the player. The card is played by putting the drawCard function into an iterator looping thourgh three times. Once this is done, the card is then sent to the discard pile via discardCard()

Adventurer Card
This action card when played, lets the current player scroll through their deck until two treasure cards have been produced. The two treasure cards are then inserted into the current hand and the rest of the cards are sent to the discard pile. 

Discard()
This function assists the action cards. When called, trashes a card from a players hand. the trashFlagparameter indicates whether or not the card should be trashed. This integer, greater than one, will be trashed. If doesn't meet criteria, card will be added to played pile, handcount in decremented. if card wasn't the last one, lst card is swapped with the discarded card and handcount in decremented.

updatecoins()
when called, the player cards are iterated through and will have coins added to their bonus, the amount of points is determined by three types of coin. gold, silver, copper. gold updates bonus by three silver by two and copper by one
