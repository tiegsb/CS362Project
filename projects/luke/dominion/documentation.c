/*Kenny Lu
October 7, 2015
CS362
Assignment 2

This file shows my knowledge of the Smithy and Adventurer cards in the Dominion card game 
along with knowledge of the discardCard() and updateCoin() functions.

Smithy Card - A smithy card is an action card that allows a player to draw 3 cards when it's 
played.  When the card is played, the function drawCard() is called 3 times and then the 
discardCard() function is called putting the smithy card away (yielding a successful play).

Adventurer Card - An adventurer card is an action card that allows a player to reveal cards
from their deck unti 2 treasure cards are revealed.  The two treasure cards are put in their
hand and the other revealed cards are discarded.  
	Code Analysis:  When the adventurer card is played, the game will check to see if the player 
	has less than one card in the deck.  If this is the case, the shuffle() function is called.
	The drawCard() function is then called which pulls the player's top card and thus deducting
	1 from handCount to keep the count of the cards in the player's hand.  According to the treasure
	card, the value of the card is added and drawnTreasure is incremented.  If a treasure card is
	not drawn, then the cardDrawn removes the top card and places a card into temphand which increments
	"z".  The final step after 2 treasure cards are drawn is that a while loop will check to to see
	if (temphand - 1) is greater than 0 which indicates that at least a card exists in temphand.
	All of the cards in temphand are then discarded.

discardCard() - The discardCard function removes a card from the player's hand and is either added
to the player's "Played" pile or trashed.  When a card is removed from the player's hand, an if/else
statement determines the number of cards remaining in the player's hand.  When the remaining count has 
been determined, the player's handCount is decreased accordingly and the function is exited.

updateCoins() - The updateCoins function loops through the player's hand and finds out how many
coins that player has.  This amount can depend according to whether the player has a silver, gold, or copper
coin and the coin count is update accordingly to the state.  After this, the user's bonus is added to the total
amount of coins.*/






















