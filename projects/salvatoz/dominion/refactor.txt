- Created new module cards (cards.c and cards.h) that implements a new way of storing card costs and effects.
- Extracted definitions for adventurer, smithy, council room, feast, mine, and treasure map into static functions in cards.c.
- Extracted common/confusing behavior from card effect handlers into special helper functions.
<<<<<<< HEAD
- Updated getCost and cardEffect to check the cardsData struct.
=======
- Updated getCost and cardEffect to check the cardsData struct.

Bugs:
    - cards.c:lastDrawn
        state->hand[currentPlayer][state->handCount[currentPlayer] - 1] 
            --> *(*(state->hand + currentPlayer) + *(state->handCount + currentPlayer - 1))

        Replaced intelligible array indexing with confusing pointer arithmetic to hide off-by-one errors
    - cards.c:treasureMapHandler
        secondTreasureMapIndex = -1 --> secondTreasureMapIndex = NULL
        if (secondTreasureMapIndex > -1) --> if (secondTreasureMapIndex > NULL)
        
        Uses NULL (i.e. 0) to check if a treasure map has been found, so if the second treasure map
        is at 0 then it won't be found
    - cards.h:NUM_CARDS
        (treasure_map + 1) --> treasure_map
        
        The correct way to do this is to increment treasure_map by one, because the CARDS enum is
        zero indexed.
    - cards.c:adventurerHandler:83
        both `while (--z >= 0)` and `z = z - 1` decrement z, causing it to decrease twice as quickly as it should.
    - cards.c:smithyHandler:100
        the for loop starts at 3, but only continues while i < 0, so it doesn't give the player any cards
    - cards.c:feastHandler:158
        state->hand[currentPlayer][i] = -1 --> state->hand[currentPlayer][i] = NULL
    - cards.c:feastHandler:203
        temphand[i] = -1 happens before state->hand[currentPlayer][i] = temphand[i], so the hand
        will be erased
>>>>>>> @{-1}
