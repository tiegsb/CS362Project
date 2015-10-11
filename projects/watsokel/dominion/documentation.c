CS 362 - ASSIGNMENT 2               KELVIN WATSON 
documentation.c                     ONID: watsokel      
                                    OSU ID: 932540242 
                                    github.com/watsokel 
----------------------------------------------- -----------------------
DOCUMENTATION 

SMITHY CARD  
-----------
As shown in dominion.h, the smithy card is an enumerator of the 
enumerated type CARD, and has the integer value 13. 

From dominion.c, the getCost() function shows that the smithy card costs 
4 coins. A player buys a smithy card using the buyCard() function. 
Provided that the player has buys remaining, there is a smithy card 
available in the supply, and has enough coins to purchase the smithy 
card, the gainCard() function is called, and the player gains the smithy 
card, and it is added to the player's discard pile. Subsequently, the 
player's number of coins is reduced by 4, and the number of buys is 
decreased by one. 

A smithy card can be played by calling the playCard() method. Provided 
that the method does not return -1 i.e. the game state is in the correct 
phase, the player has enough actions, and the smithy card is an action, 
thecardEffect() method is called. In the cardEffect() method, three 
additional cards are drawn for the current player, and the smithy card 
is placed in the discard pile via the discardCard() method. Finally, the 
player's number of actions is decremented and the player's coins is 
updated via the updatedCoins() method (see below for description). 


ADVENTURER CARD 
---------------
As shown in dominion.h, the adventurer is an enumerator of the 
enumerated type CARD, and has the integer value 7. 

From dominion.c, the getCost() function shows that the adventurer card 
costs 6 coins. When a player buys a adventurer using the buyCard() 
function, the player gains the adventurer as long as the player has buys 
remaining, there is an adventurer card available in the supply, and has 
enough coins to purchase the adventurer card. The gainCard() method is 
called, and the adventurer card is added to the player's discard pile. 
The player's number of coins is reduced by 6, and the number of buys is 
decreased by one. 

When the player plays the adventurer card via the playCard() method, the 
cardEffect() method is invoked with the adventurer card (provided that 
the game state is in the correct phase, the player has enough actions, 
and the adventurer card is an action, i.e. the playCard() does not 
return -1 before cardEffect() is called. Within cardEffect(), the 
adventurer card is selected in the switch statement. Cards are drawn 
from the player's deck until two treasure cards are drawn. The two 
treasure cards are placed in the hand, and any non-treasure cards are 
then placed into the disard pile. 


discardCard() method
--------------------
The discardCard() method takes as arguments the position of the card to 
be discarded, the current player, the game state, and the trash flag. 
When the trash flag is passed into discardCard() with a value of 0, the 
card is being played (added to the played pile) and not trashed. The 
played card's position in the hand 2D array is then assigned a value of 
-1. If the card being played is in the last position of the hand or if 
it is the only card remaining in the hand, then the hand count is 
decremented. If the card being played is in any other position in the 
hand with more than 1 card, then the played card is replaced with the 
last card in the hand, the last card in the hand is set to -1, and the 
player's hand count is decremented. Note that when the trash flag is 
passed to discardCard() with a value of 1, this means that the card is 
trashed. 


updateCoins() method
--------------------
The updateCoins() method takes as arguments the player number, the game 
state, and a bonus. It adds up all of the Treasure cards (copper, silver 
and gold) in the player's hand, as well as a bonus if provided, and 
updates the game state's coins variable with the result of the sum. 


SOURCES
-------
http://wiki.dominionstrategy.com/index.php/Clean-up#Clean-up_phase
http://dominion.diehrstraits.com/?set=Base
http://dominioncg.wikia.com/wiki/Kingdom_Cards
CS362 - Dominion-BaseArchitecture.pdf
CS362 - Dominion Documentation.pdf