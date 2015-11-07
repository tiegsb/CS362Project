/***********
Author:  Brian Stamm
Title:  documentation.c
Assignment:  2
Date:  10.11.15
Notes:  This file explains two cards (Smithy and Adventurer) and two methods (discardCard and updateCoins).
Any line numbers referenced in this file refers to the original dominion.c file.
************/

/************************************************************

In explaining the cards and functions, there is a basic assumption that reader has a general knowledge of
the Dominion card game.  The basics of the game is there are at least 2 players each who start with 10 cards
in their hand.  The goal of the game is to have the most Victory points by the end of the game.  Each player
has a turn which has two main components - action and buy.  Action cards are played first, and you end your turn
with a buy.  Each turn, the player has one action and one buy opportunity.  Cards the player plays can change
those values.

Smithy card:  The smithy card is an "Action" card which costs 4 treasure points to buy (defined in interface.h).  
When played during the "Action" portion of a player's turn, it lets the player draw 3 more cards from their deck 
and use those cards.  It does use one player's "Action" turn.
	The code to this card is contained in the switch statement in the cardEffect() method located at line 836.  The
code is a simple for loop that iterates 3 times, drawing a card from the player's dech using the method drawCard().
After getting those three new cards, the original Smithy card is discarded using the discardCard() method.

Adventurer card:  The adventurer card is also an "Action" card which costs 6 treasure points to buy (defined in 
interface.h).  When a player uses this card during the "Action" portion, it allows them to draw from their deck 
until they have gotten 2 Treasure cards.  Once they get those 2 cards, those are placed in the player's hand while 
the rest are put back in their deck.  This card does use one of the player's "Action" turn.
	The code to this card is contained in the switch statement in the cardEffect() method located at line 674.  The
code follows the explanation.  It has a counter (drawntreasure) which starts at 0.  While it is less than 2, it goes 
through the player's deck until a treasure card is drawn.  Once it is, the card is added to the hand and the counter 
is incremented.  But if it is not, the card is stored in a temporary hand using another counter (z).  Once that while
loop is completed, the function then goes to another while loop designed to add back all the cards in the temporary hand
back into the player's deck.

discardCard():  This method is defined in dominion_helper.h, where it has 4 parameters in this order:  int handPos, 
int currentPlayer, struct gameState, and int trashFlag.  It is called in line 710, 791, 798, 816, 823, 839, 850, 
912, 920, 932, 951, 981, 982, 986, 1089, 1098, 1117, 1136, 1155, 1163, 1175, 1179, 1206, and line 1207 in cardEffect 
method.  The actual method is defined starting on line 1226.  It first checks if the trashFlag is greater than one.  
If it is not, then it adds the card to the playedCard array and sets played card to -1.  Then the function moves into
another if-else if-else statement.  If there is no other card to play or the last card to play, it reduces the hand by
one card.  If there are more cards, it moves to the next card in the player's hand and decreases the hand count by one.  

updateCoins():  This method is defined in dominion_helper.h, where it has the 3 parameters in this order:  int player, 
struct gameState, and int bonus.  It is called in dominion.c on line 196 for the initilization of the game, line 267
in the playCard() method, line 385 in the endTurn() method, and in line 724 and 1108 in the cardEffect method.  The 
method is actually defined in line 1301.  In the method, it initially sets the player's coin value to zero.  Then,
using a "for" loop, it goes through the player's hand checking if the cards are a coper, silver, or gold card.  If
they are, it adds the corresponding value to the player's coin total.  After the "for" loop, it adds any bonus the
player might have.  At the end, the method returns the int 0.

****************************************************************/