Documentation of smithy & adventurer card

The smithy card allows the player to draw three cards to add to their hand.  This is a case in the cardEffect() function in dominion.c.  This is done with a for loop that loops three times, and draws a card each time from your deck.  Then it calls the discardCard() function that removes a card from the player's hand.

The adventurer card allows the player to reveal cards from their deck until they reveal two treasure cards. Then they put those treasure cards in their hand and discard the other revealed cards.  This is a case in the cardEffect() function in dominion.c.  This is done with two while loops, that loops until two treasure cards are drawn.  First if the deck is empty, then the deck is shuffled.  Then the card is drawn, and checked to see if it is copper, silver, or gold.  If the card drawn isn't a treasure, it ends up being discarded.

Documentation of discardCard() & updateCoins()

The discardCard() function allows the player to do simply that, discard a card from their hand.  First, it checks if the trashFlag is set, if it is not, then it gets added to the played pile.  Then the card gets removed from the player's hand, and the handCount variable decreases by one.  

The updateCoins() function first resets the players coin count.  Then with a for loop it adds the appropriate number of coins for copper treasure cards, a silver treasure cards and a gold treasure cards.  This for loop ends when all treasure cards in the player's hand are accounted for.  Then if there is a bonus, this function adds it to the player's total coin count in their hand.
