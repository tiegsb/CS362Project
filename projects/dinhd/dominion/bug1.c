There is a bug with isGameOver(). It goes through all the possible supply cards EXCEPT the last 
two, sea hag and treasure_map. So even if one of these cards has zero supply and there are 2 other
cards with zero supply, the game does not end. 

There is a bug with scoreFor(). When calculating the score for discard and deck, the values are
wrong because the for loop that iterates over the deck only goes through the deck based on the number
of cards in the discard pile, not the actual deck. 