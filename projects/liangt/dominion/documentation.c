/**************************************

Author:			Tony Liang
Class:			CS 362 Fall 2015
Assignment:	2
Date: 			10/11/15
Filename:		documentation.c

Overview:
	Documentation of:
		- Smithy card
		- Adventurer card
		- discardCard() method
		- updateCoins() method

**************************************/

/*

Smithy Card:
------------

In dominion.c:
The cost of the Smithy card is defined on line 618 within the getCost() function.
Its behavior is defined starting at line 836.
The first thing it does is draw three cards for the current player by
calling the drawCard() function three times using the same currentPlayer and
state input with the assumption that the state may change each time.

*/