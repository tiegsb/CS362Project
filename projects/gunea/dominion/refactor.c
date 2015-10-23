/******REFACTOR.c******

Smithy:
Introduced a bug where the trashflag is set when
discardCard() is called. This way the card is
already marked as trashed, and is therefore
not added to the played cards pile.

Adventurer:
Introduced bugs into this function when turning
it into a function where many of the variables
required (drawntreasure, currentPlayer,
tempHand, z, and cardDrawn) are not passed by
reference. Means their value will not change 
after the function returns control to cardEffect().

Ambassador:
Introduced a bug where each player gains a copy of
the revealed card, but it goes to their hand rather
than their discard pile (accomplished by calling
gainCard(), but with the toFlag set to 1.

Embargo:
Introduced a bug by putting Embargo into a function
unaltered. Under the condition that the selected pile
is in play:
	//if (state->supplyCount[choice1] == -1)
	//	return -1;
this will cause embargoFunction() to return control
to cardEffect, which will then return 0 by default.
cardEffect() now fails to trigger a condition in
playCard() which would have reduced actions and 
updated coins. This results a change where playing
the Embargo card is always successful

	Clean code:
	If pile is in play, cardEffect() returns -1 to playCard()
	If cardEffect() < 0, playCard() returns -1 to main()
	If playCard returns 0, main() marks it as SUCCESS
	Else, main() says player cannot play that card
	Therefore, if pile is in play, main() says player cannot play Embargo

	Buggy code:
	If pile is in play, embargoFunction() returns -1 to cardEffect()
	cardEffect() always returns 0 to playCard() upon Embargo play
	Consequently, playCard() returns 0 to main()
	main() reads out come of playCard(embargo) as success


Great Hall:
Refactored into function with no bugs.

*/

//end of refactor.c