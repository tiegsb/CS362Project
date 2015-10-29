Robert Ward
10/24/2015

Bugs found in tests:

unittest1.c: getCost
    no bugs found
    
unittest2.c: numHandCards
    no bugs found

unittest3.c: endTurn
    no bugs found
    
unittest4.c: handCard
    no bugs found

cardtest1.c: Smithy card
    There are two bugs that I found in the smithy card function.
    1. the state->playedCardCount value is not updated properly. This is a bug that I introduced to the program for assignment 2. Every card is trashed instead of being discarded
    2. If there are not 3 cards total in the deck and discard piles then no cards can be drawn
    
cardtest2.c: adventure card
    
