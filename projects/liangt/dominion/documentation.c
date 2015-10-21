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
It then discards the Smithy card from the hand and puts it in to the played pile
It returns 0 because the player cannot do anything wrong.

Adventurer card:
----------------

Logic starts at line 674.
drawntreasure is specific to the adventurer card and describes how many
treasure cards are drawn by adventurer. While it's less than 2, it does the following:
- shuffles deck if deck is empty. This is unnecessary because drawCard already does that.
- draws card
- if it's a treasure card, great, increment drawntreasure
- if not, put the card in the temporary hand and remove it from the active hand
Once its drawn enough treasure cards, it puts all the cards in the temp hard
into the discard pile

A bug exists where if there is only 0 or 1 treasure card left in the deck - 
then it will get stuck shuffling the (nonexistent) deck forever.

Returns 0 since the player can't mess up.

discardCard():
--------------

Line 1231.
The default behavior is to trash the card.
But if it's not going to be trashed, it's placed in the played pile.
The card in the player's hand is "nullified" by setting it to -1, which is a
non-type.
If it's the last card or the only card in the hand, the handCount is decremented
If not, the last card is put in its place.
This is in contrast with the online game which preserves order.
The last card gets nullified.
It returns 0 for no reason.

updateCoins():
--------------

Line 1306.
The online game lets you withhold playing any treasure cards.
Here it automatically assumes you'll play all of them,
presumably after playing an action card with a +$ effect.
In other words, all it does is sum up the value of the treasure cards
in your hand and adds any bonuses from +$ cards, setting that as the total coin amount.
Again this is a gross simplification from the online game's behavior.
It returns 0 for no reason.
*/