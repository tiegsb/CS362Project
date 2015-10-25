There is a bug with isGameOver(). It goes through all the possible supply cards EXCEPT the last 
two, sea hag and treasure_map. So even if one of these cards has zero supply and there are 2 other
cards with zero supply, the game does not end. 

There is a bug with scoreFor(). When calculating the score for discard and deck, the values are
wrong because the for loop that iterates over the deck only goes through the deck based on the number
of cards in the discard pile, not the actual deck. 

There is a bug with mineCard. The function that checks to see if the cost is affordable has the wrong operator
It should be  if ( (getCost(state->hand[currentPlayer][choice1]) + 3) < getCost(choice2) )
not  if ( (getCost(state->hand[currentPlayer][choice1]) + 3) > getCost(choice2) ).

There is a bug with mineCard. It does not check to see if the card being bought is a treasure card. 
It only checks to see if the card exists. 

There is a bug with mineCard that was introduced by me, the input parameters for choice1 and choice2 were swapped. 

There is a bug with minion