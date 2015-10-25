/**************************************

Author:			Tony Liang
Class:			CS 362 Fall 2015
Assignment:	2
Date: 			10/11/15
Filename:		refactor.c

Overview:
	Documentation of general strategy.
	Documentation of deliberate buggy changes to:
	- Smithy
	- Adventurer
	- Village
	- Mine
	- Council Room

**************************************/

/*

General strategy:
-----------------

New functions are placed above cardEffect() so that the header file
doesn't need to be changed.
Only a small subset of the cardEffect() input parameters are put into
the functions, as necessary.
Only a small subset of the initialization variables are included as well,
as necessary.
Unused variables in cardEffect() are commented out.
Each case needs to return something, so that part of the original case
was left in.

Buggy changes:
--------------

Smithy:
- 4 cards are drawn instead of 3
- Smithy card is trashed instead of being put in the played pile

Adventurer:
- Draws 3 treasure cards, not 2
- Ignores silver cards

Village:
- Draws 2 cards instead of 1
- Gives only 1 action instead of 2

Mine:
- Newly picked card is added to deck instead of hand
- The existing bug where the trashed card isn't actually trashed is LEFT IN

Council Room:
- Current player gets +3 coins for buying instead of zero

*/