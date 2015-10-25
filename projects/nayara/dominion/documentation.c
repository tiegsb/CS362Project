// Ashok Nayar
// cs362 - Fall 2015
// documentation.c

/*****************
* Smithy Card
******************/
Overview
Based upon the dominion.c code in its present state, the Smithy card is an action card that
allows the player to draw three cards.

Detail
If a player has a Smithy card and it is their turn to perform an action (and they have at least one action available),
the player plays the card using the playCard() function, which in turn invokes the cardEffect() function. Three cards are
randomly dealt into the player's hand and the Smithy card is placed into the player's discard pile. The playCard function 
decrements the player's actions by 1.

If it's the player's turn to buy and they have at least one available buy, at least 4 coins, and the there are still Smithy
cards available, the player can elect to purchase the card using the buyCard() function. If the previously mentioned requirements
are fullfilled, the player's coin count is decremented by four, the buy count by one, and the gainCard() function is called 
in which the Smithy card is added to the player's discard pile. The total count of available Smithy cards is decremented by 1.

/*****************
* Adventurer Card
******************/
Overview
The Adventurer card is an action card that allows the player to continuously draw cards from their deck until 
they gain two coin cards. The drawn cards that are not coppers are placed into the discard pile and the coin 
cards are placed into the player's current hand.

Detail
If a player has an Adventurer card and it is their turn to perform and action and they have an action available, the player 
plays the card using the playCard() function. This function also invokes the cardEffect() function. In the cardEffect function, 
the Adventurer section enters a while loop that continues as long as the "drawn treasure" is less than 2. The drawn treasure 
variable is incremented when a copper, silver, or gold card is encounted and the coin card is added to the deck. If the drawn card
is not a coin card, it is placed in the discard pile and the variable is not incremented. 

If it's the player's turn to buy and they have at least one available buy, at least 6  coins, and there are still Adventurer 
cards available, the player can elect to purchase the card using the buyCard() function. If the previously mentioned requirements
are fullfilled, the player's coin count is decremented by six, the buy count by one, and the gainCard() function is called 
in which the Adventurer card is added to the player's discard pile. The total count of available Adventurer cards is decremented by 1.

/*****************
* discardCard()
******************/
The discardCard() function takes in four parameters: The position of the card in player's hand, the index of the current
player in the game, the game state (a struct containing players, positions, hands, etc), and a flag indicating whether a card should be
trashed or not. The trashed flag is checked first and if it is set to 0, indicating that it is to be placed in the discard pile, the
card is copied from the given position in the player's hand to the last index of the discarded pile area. The index of the discarded pile array
is then incremented by one. The discarded card in the player's hand is then set to -1. If the card's position in the player's hand was at the 
end of the array, the array is shrunk by 1. If the card was the only card in the player's hand, it is also shrunk by 1. In all other situations,
the last card in the player's hand is copied to the position held by the discarded card and the player's hand/array is shrunk by a value of 1.
The function then returns 0.

/*****************
* updateCoins()
******************/
The updateCoins() function takes in three parameters: The player's position in the game, a struct of the current game state, and an integer of
a bonus amount of coins to be added to the player's coin total. First, the coin count is set to 0. The function then loops through each card
in the player's hand and checks to see if it is a coin card. If it's copper, 1 coin is added. Two are added for silver and three for gold. The
bonus is added at the end and the function returns 0.



