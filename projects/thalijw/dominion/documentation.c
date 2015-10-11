CS_362_Software Engineering
Assignment #2
thalijw

documentation about Smithy and Adventurer Cards:

Smithy:

The Action of this card is +3 adding three new cards to the current player hand and discarding the smithy card in the end of the action.
In the cardEffect()/case smithy code, it starts with a for loop that runs 3 times, at each time it calls the function drawCard() 
passing it the current player and the state of the game, it draws three cards and adds it to the current player hand, then it calls
the function discardCard() to discard the Smithy card from the player hand, passing it the hand position, the player, state of the game
and index 0.

Adventurer:

This card makes the player to reveal cards from his deck unitl he reveals two treasure cards, then add these treasure cards to his hand,
and discard the other revealed cards to the discarded pile, the code will keep track of those treasure card count in the drawntreasure variable.
In the cardEffect()/case adventurer code, it starts with a while loop that runs while the number of treasure cards revealed < 2, it first checkes
the player deck, if its empty, then it calls shuffle() to shuffle the players discarded cards and add them to the player card pile, then it calls
drawCard() to draw a card from the card play pile, then it adds that card to the top of the player's hand using the cardDrawn variable.
The next step is checking if the card drawn is a treasure card(copper, silver or gold), if it is then we increment the drawntreasure variable by 1,
if it is not a treasure card, then we added it to a temphand list and keep track of how many cards added using "z" index, then we remove it from
the top of the player's hand.
After we found our two treasure cards and exit the above loop we enter another loop that removes the drawn cards that was not a treasure cards.


discardCard():

This function will discard a card and added to the player's played pile (discarded pile), it takes a hand position, the current player, the game state
and the trashFlag (a flag to check if the card has been added to the played pile).
First the function will check the trashFlag, if the card is not trashed, then it will add it to the player's discarded pile, and incremented the number
of the cards in this pile, then we set the played card's value to -1 (set it as played) and then remove that card from the player's hand by executing an
if statement that first checks if it was the last card in hand, then it reduces the number of cards in hand by one, or if there is one card left in hand,
then it also reduces the number of cards in hand by one, or in case there is more that one card in hand, it will replace the discarded card with the last one
in hand, and set it's value to -1 (played) then decreased the count of the hand cards by 1.

updateCoins():

This function will update the number of coins the playes have each turn. it will first sets the coins count in the game state to Zero to start with empty variable.
Then it will enter a for loop that goes through the player's hand cards and checkes whether it is a "Copper", then it adds 1 to the coin's count, or if it is a "Silver",
then it adds 2 coins to the count or if it is a "Gold", then it adds 3 coins to the count. at the end it will add to the count any bonus coins the player has ( this number
is passed as an argument to the function).
