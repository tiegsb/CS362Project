//Keenan Bishop
//CS362 Assignment 2
//Documentation
//
//
//Objectives
// 1. Explain smithy and adventure cards
// 2. Explain discardCard() and updateCoins()
//
/*

Smithy Card
Smithy Card lets the player draw 3 cards when used.
It calls drawCard 3 times, then discardCard.
It returns a 0 on success.

Adventurer Card
This card lets you draw cards from your deck until you have collected 2 treasure cards
It uses a while loop that checks against a temporary int called drawntreasure.
First, it checks for an empty deck, and shuffles if necessary
Then, it calls drawcard, and checks if the drawncard is a treasure card, and increments drawntreasure as necessary.
Otherwise, it puts the drawn card into a temporary hand,
Afterwards, it cleans up by cleaning up the temphand variable.
It returns a 0 on success.


discardCard()
int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)
(defined in dominion.c)
This function discards a card from the current player's hand.
First, it checks if hte card is "trashed".  If it isn't, it adds the card to the "playedCards" section of the game state
Next, it sets the value of the card to -1
Next, it removes the card from the player's hand.
It first checks whether the card is the last one in the player's hand.
In all cases, it decrements the handcount of the current player, but if its not the last card in the player's hand, then it updates the current hand position.
It returns a 0 on success.

updateCoins()
int updateCoins(int player, struct gameState *state, int bonus)
(defined in dominion.c)
This function updates the coin count for the specified player.
First, it resets the coin count to zero.
Next it enters a for loop from 0 to the number of cards the player has.
It adds appropriate values (1, 2, 3) for the copper, silver, and gold coins, respectively, for the cards the player owns.
Before returning, it also adds the bonus, which is specified when it is called.
It returns a 0 on success.

































*/
