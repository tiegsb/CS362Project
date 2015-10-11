Smithy Card:
The Smithy card is one of the card options avalible within the switch statement located in the "cardEffect" function. It allows the player to increase their hand by 3 cards and then play a card in their hand through the "discardCard" function.

Adventurer Card:
The card uses a while loop to check to see if two treasure cards have been drawn. Inside the while loop it checks to see if the stack of cards being pulled from is empty and if so shuffles the deck of cards from the drawn stack. Then, it draws a catd from the top of the pile and checks if it is a treasure card. If so the variable in the while loop is incremented by one and the card is added to the players hand. once the while loop evaluates to false, two treasure cards have been drawn, the while loop ends and the cards drawn that were not treasure cards are sent to the pile of cards that have been used.

DiscardCard Function:
The function first checks to see if the card being discarded is going to be trashed. If not the card is added to the set of played cards so that it can be drawn again in the game. Once the used card is trashed or discarded the function reduces the number of cards remaining in the player's hand but does so for three different cases. Case one is that the player just played the last card in their hand. Case two is that the player has one card remaining in their hand. And case three is that the player has more than one card left in their hand.

Update Coind Function:
First the function sets the coins variable to 0. Then a for loop is used to add the number of coins in the handCount variable for the player. Copper coins add 1, silver adds 2 and gold adds 3. There are also some cards that allow for bonus coins to be added so any bonus coins are added once the for loop ends.