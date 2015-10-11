smithyEffect()
Changed the loop iterator so that the cardDraw() is only called twice 
instead of three times.

adventurerEffect()
Removed a line of code that updated the hand position for the next drawn
card.  This will make the hand position variable point to the card just
below the one just drawn.


villageEffect()
No bugs.


mineEffect()
Changed the state->handCount to state->deckCount when the card effect would
look for the card to be trashed.  If this card is not found, then it won't 
be trashed.


stewardEffect()
Removed trash flag from option 3 of the card effect. This will no longer allow 
the two chosen cards to be trashed.