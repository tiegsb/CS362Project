After running each of the 4 unit tests, no bugs were found. These tests covered the 
functions updateCoins(), gainCard(), getCost() and discardCard.

The four card tests however prooved to be more fruitful. cardtest1 tested the smithyF
function. I had forgotten the bug I introduced in these functions, and made myself not look
at the refactored.c file. My unit test did end up finding the bug, which sent the card to the 
trash pile rather than the discard pile.
cardtest2.c and cardtest3.c found no bugs.
cardtest4.c was much more difficult to test, and revealed a bug I had not intorduced. When attempting to buy
a card that was out of supply, or that was too expensive, the function gets locked into an infinte loop.

