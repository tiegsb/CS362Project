// Ashok Nayar
// cs362 - Fall 2015
// refactor.c

/*****************
* Name: smithyEffect
* Description: Three cards are randomly dealt into the player's hand. The smithy card itself is then discarded
* Input: The index of the player in the game, the index of the smithy card, and a pointer to the struct of the game's state
* Output: The player's hand is modified and 0 is returned.
* Bug introduced: None
******************/

/*****************
* Name:  adventurerEffect
* Description: Cards are continuously drawn until two coin cards are found. The coin cards are placed into the player's
*              hand while the other cards are discarded. 
* Input: The index of the player in the game and a pointer to the struct of the game's state
* Output: The hand is modified adn 0 is returned.
* Bug introduced: Originally, any coin card would be placed into the player's hand. The bug introduced only allows silver and gold
                  cards to be placed into the player's deck. Copper cards are discarded due to this bug.
******************/

/*****************
* Name:  villageEffect
* Description: Let's the player draw one card and allows for an additional two actions
* Input: The index of the player in the game and a pointer to the struct of the game's state
* Output: Player's hand is increased by one and their action count by 2. Returns 0.
* Bug introduced: The function now multiplies the actions by 2 instead of adding them.
******************/

/*****************
* Name:  councilEffect
* Description: Allows the player to draw four cards, increases their buy count by 1, and let's all the other players draw a single card.
* Input: The index of the player in the game and a pointer to the struct of the game's state
* Output: The player's hand is modified with four extra cards and their buy count by 1. Other players' hands are modified with one extra card.
* Bug introduced: Instead of all the other player's drawing a card, the function now gives the current player a card and the others get nothing.
******************/

/*****************
* Name:  feastEffect
* Description: Allows the player to buy a card costing up to 5 coins (assuming there are cards of that type remaining)
.* Input: The index of the player in the game and a pointer to the struct of the game's state, integer of player's card choice
* Output: The player's hand is modified to add the chosen card. Function returns 0.
* Bug introduced: Originally, 5 coins are added so the player can purchase a card costing up to 5. The bug introduced does not add any coins.
******************/