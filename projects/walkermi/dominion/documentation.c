
Card - Adventurer:

The Adventurer card is an element within an enumeration data set called "Card." 
The enumeration declaration can be found in dominion.h. The adventurer card's 
integer value within this enumeration set is 7. The Adventurer card's effects 
are defined in dominion.c in the method cardEffect() as part of a switch statement 
(lines 669 - 688). The method cardEffect()'s parameters are as follows: an integer 
"card," an integer "choice1," an integer "choice2," an integer "choice3," a pointer 
to a "gameState" struct "state," and integer "handPos," and a pointer to an integer 
"bonus." The Adventurer card's effect is that of drawing cards until two treasure 
cards are drawn (whcih are put into the current player's hand) and discarding all 
other cards drawn. Before the switch statement is reached in cardEffect() an integer 
variable "drawntreaseure" is set to a the value of 0. When the Adventurer sectinon 
of the switch statement is reached a while loop is entered and continues to iterate 
until two treasure cards are drawn (or in other words until the "drawntreasure" >= 2). 
Within this first while loop the current player's deck is evaluated to check if it 
is empty, if it is indeed empty, the shuffle() methoed is called to shuffle the 
discarded cards back into the deck. A card is then drawn by calling the drawCard() 
method and this card is set to an integer variable "cardDrawn" (the "cardDrawn" 
variable is set to the last card in the current player's hand since this will 
always be the current player's most recently drawn card). If "cardDrawn" is 
equal to the enum value of "coppper," "silver," or "gold," "drawntreasure" is 
incremented. Otherwise the newly dran card is added to a integer array "temphand" 
which acts as a temporary hand to store the drawn cards that are not treasure cards. 
After the card is added to the temp hand the current player's hand count is 
decremented to remove the most recently drawn card and "temphand's" index variable 
"z" is incremented. Once the first while loop temrinates, a second while loop is 
enetered which discards all the cards which were added to "temphand" (if any). 
The method then returns 0.



Card - Smithy:

The Smithy card is am element within an enumeration data set called "Card." 
The enumeration declaration can be found in dominion.h. The adventurer card's 
integer value within this enumeration set is 13. The Smithy card's effects are 
defined in dominion.c in the method cardEffect() as part of a switch statement 
(lines 831 - 851). The method cardEffect()'s parameters are as follows: an integer 
"card," an integer "choice1," an integer "choice2," an integer "choice3," a 
pointer to a "gameState" struct "state," and integer "handPos," and a pointer to 
an integer "bonus." The Smithy card's effect is that of drawing three cards, 
which is performed by entering a loop that iterates thress times, each calling the 
drawCard() method. The effect finishes by discarding the Smithy card from the 
current player's hand. The method then returns 0.



Method - discardCard():

The discardCard() method is defined within dominion.c (line 1226 - 1262). Its 
parameters consist of the following: an integer called "HandPos," an integer 
called "currentPlayer," a pointer to a "gameState" struct called "state," and 
an integer called "trashFlag." The method first checks if the "trashflag" is 
set (by checking if "trashflag > 0"). If the "trashFlag" is not set, the card 
(which in this case is the "state" 2D array member variable "hand" at the index 
of "currentPlayer" and "handPos") is added to the played card pile (which is 
the "state" member variable "playedCards[]" at the index of the "state" 
member variable "playedCardCount"). Whether or not the "trashFlag" is set the 
played card is set to the value of -1. Next the card is removed from the player's 
hand. If the card played was either the last card in the hand array or the card 
played was the only card left in the player's hand, "handCount" (with the index 
of "currentPlayer") is decremented. Else, the discarded card is replaced by the 
last card in the current player's hand array, the last card is set to the value of -1 
to mark it as played, and finally the current player's hand count is decremented.



Method - updateCoins():

The updateCoins() method is defined within dominion.c (line 1301 - 1329). Its 
parameters consist of the following: an integer called "player," a pointer to a 
"gameState" struct called "state," and an integer called "bonus." The method 
first resets the "state" member varaible "coins" to zero. Next, the method loops 
once for every card in the current player's hand which is defined by the "state" 
member variable "handCount[]" using an index of the integer value of "player" 
(handCount[player]). Every iteration of the loop evaluates each card in the player's 
hand (which is defined as the "state" member variable "hand[player][i]" with i being 
the current loop iteration starting at zero) and if equal to the "Card" enumerator 
values (as defined in dominion.h) of "copper," "silver," or "gold" adds 1 coin, 
2 coins, or 3 coins to the "state" member variable "coins." Finally the value of the 
"bonus" argument is added to the state" member variable "coins." The method returns 
zero at this point.