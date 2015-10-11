/******REFACTOR.c******

Smithy:
Introduced a bug where the trashflag is set when
discardCard() is called. This way the card is 
not already marked as trashed, and is therefore
not added to the played cards pile. Also created
new variable i within scope of smithyFunction().

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
























*/