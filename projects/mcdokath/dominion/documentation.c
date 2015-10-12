Author: Kathryn McDonald
ONID: mcdokath
Class: CS 362
Filename: documentation.c
Description: Documentation of adventurer and smithy cards, discardCard() and updateCoins().
******************************************************************************

****************
Adventurer Card
****************
From dominion.h:
The Adventurer Card is declared with a value of 7 in enum CARD.

From dominion.c:
The Adventurer Card first checks if the deck is empty.  If so, it shuffles the discard pile and adds it back into the deck.  It then draws a card.  If a Treasure Card (Copper, Silver, or Gold) is drawn, it increases the "drawntreasure" variable by one.  Otherwise, it adds the drawn card to the current hand and advances the hand to make space for the next card.  The Adventurer Card continues this process until a Treasure Card has been drawn twice.  At this point, it discards all the cards that have been drawn and returns 0.

From http://dominioncg.wikia.com/wiki/Adventurer:
The Adventurer Card is an Action Card whose effect allows the player to reveal cards from his/her deck until he/she has 2 Treasure Cards.  The player then puts these Treasure Cards in his/her hand and discards the other revealed cards.  This card costs 6 coins to buy and is part of the Dominion Base Set.

****************
Smithy Card
****************
From dominion.h:
The Smithy Card is declared with a value of 13 in enum CARD.

From dominion.c:
The Smithy Card draws 3 cards.

From http://dominioncg.wikia.com/wiki/Smithy:
The Smithy Card is an Action Card whose effect allows the player to draw 3 additional cards.  This card costs 4 coins to buy and is part of the Dominion Base Set.

****************
discardCard()
****************
From dominion_helpers.h:
The discardCard() function takes 4 inputs: int handPos, int currentPlayer, struct gameState *state, and int trashFlag.

From dominion.c:
First, the discardCard() function checks the trashFlag.  If the flag is less than 1, the card is added to the Played pile. If the card is trashed, nothing occurs.  The card is then removed from the hand, and the appropriate variables updated.

****************
updateCoins()
****************
From dominion_helpers.h:
The updateCoins() function takes 3 inputs: int player, struct gameState *state, and int bonus.

From dominion.c:
First, the updateCoins() function resets the coins counter to 0.  Then, the coin value for each Treasure Card is added to the player's hand, with the appropriate values for Copper, Silver, and Gold specified.  Any bonuses are also added at this time.