Author: Allan Chan
ONID: chanal
Class: CS362
Filename: documentation.c
Description: Contains documentation of smithy, adventurer cards, 
			 discardCard() and updateCoins() methods.
--------------------------------------------------------------------

Smithy Card 
-----------
From dominion.h, the smithy card has a value of 12 from the enum Card declaration.
The smithy card is an action card that has the effect of +3 cards and costs 4 coins 
(http://dominioncg.wikia.com/wiki/Smithy). When played, this action card allows the player
to draw three cards and place them in their hand. 
In dominion.c, the getCost function returns 4 for smithy which shows the cost of the card 
in coins. The buyCard function allows the player to purchase a smithy card if they have
enough coins to do so and if the supply of smithy cards is not less than 1. When the card is 
played, drawCard() is called 3 times and then discardCard is called to discard the smithy card.

Adventurer Card
---------------
From dominion.h, the adventurer card has a value of 7 from the enum Card declaration.
The adventurer card is an action card that costs 6 coins and when played has the effect of 
revealing cards from your deck until two Treasure cards are drawn. Those two Treasure cards 
will then be placed in your hand and the other non-Treasure cards revealed are discarded. 
(http://dominioncg.wikia.com/wiki/Adventurer). 
In dominion.c, the getCost function returns 6 for adventurer which shows the cost of the card
in coins. The buyCard function allows the player to purchase an adventurer card if they have
enough coins to do so and if the supply of smithy cards is not less than 1. When the card
is played, drawCard() is called and checks if the drawn card is a Treasure card (copper,
silver or gold) and if it is, the drawntreasure count increases. If a Treasure card
is not drawn, then it is placed in a temphand. Once two Treasure cards are drawn,
all cards in temp hand is discarded. 

discardCard() method
--------------------
The discardCard function takes in handPos, currentPlayer, gameState and trashFlag are parameters.
The handPos parameter is the position of the card in the current player's hand. If the trashFlag
is passed in less than 1, the card is not trashed and is added to the played pile. A played
card is set to -1. If the card played is the last card in the player's hand, the number of
cards in the hand is decremented. If the card played is not the only card in the player's
hand then the discarded card is replaced by the last card in the hand then the last card is 
set to -1. The number of cards in the player's hand count is decremented. 
If the trashFlag passed in is 1 or greater, then the card is trashed and not placed in 
the played pile.


updateCoins() method
--------------------
The updateCoins function takes in the player, the gameState and the bonus for parameters.
The updateCoins functions adds the coins for each Treasure card in a player's hand
inside a for loop where if the the player's hand has a copper it would be +1, silver would
be +2 and gold would be +3 coins for the player's hand. After all the Treasure cards
are summed up, bonus coins, if any, are added to the player's coin amount.  