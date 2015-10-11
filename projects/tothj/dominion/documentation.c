/*John R. Toth
*CS362 Assignment 2
*tothj@oregonstate.edu
*document.c
*/

/*
Per instructions, this document illustrates my understanding of the Smithy, & Adventurer cards, 
as well as the discardCard() and updateCoins() methods. 

Smithy Card
The Smithy card is an action card, allowing a player to draw 3 cards when played. Once the Smithy 
card is played, the function drawCard() is called 3 times. Afterwards, the discardCard() function is 
called, thus closing out the Smithy card functionality.

Adventurer Card
The Adventurer card, an action card, allows the holder to reveal cards in their deck, until they reveal 
2 treasure cards. Once the user has pulled the second of their two treasure cards, they are allowed to 
then discard the other revealed cards. When the Adventurer card is played, the game checks to see if the 
current player has less than 1 card left in their deck. If so, the shuffle() function is called. Next, 
the drawCard() function is called. When drawCard() is called, the system pulls the player’s top card and 
deducts 1 from handCount, in order to maintain current count of cards in the players hand. If the user’s 
cardDrawn is a copper, silver or gold card, then drawnTreasure is incremented, else the cardDrawn simply 
removes the top card, placing the drawn card into temphand, and increments “z”, the players temphand. A 
while loop is then used to determine if temphand – 1 is greater than or equal to 0. While true, this loop 
will discard all cards from the temporary hand.

discardCard Method
The discardCard function simply removes a card from a player’s hand. When called, the discarded card is either 
added to the player’s “Played” pile, or trashed. Once the card is removed from the player’s hand, one of three 
if/else statements determine the number of cards remaining in the player’s hand. Once the number of remaining 
cards has been determined, the player’s handCount is decremented and the function is exited. 

updateCoins Method
The updateCoins function loops through a player’s hand, determining how many coins that player has. The type of 
coins the player has, whether copper, silver or gold, are each accounted for and the player’s coin holdings are 
incremented by their appropriate values. Lastly, there is an “add bonus” function that tracks coins gain from 
actions, adding any bonus owed directly to the player’s coin value. 
*/
