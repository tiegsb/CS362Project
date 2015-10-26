/* Filename: bug1.c
 * Author: Joseph Barlan (barlanj)
 * Description: This file contains bug found using unittest and cardtest
 */


/*
    ====================================================================================
    1.0 - unittest
    ====================================================================================
    1.01 - isGameOver() / unittest1.c
    ------------------------------------------------------------------------------------
    [10/25/2015]
    + Test 6 - 30 have a high chance of finding a bug.
    + Bug: if cards 25-26 enumerated are depleted and all other cards still > 0 count,
           the game does not recognized game over state.

    1.02 - updateCoins() / unittest2.c
    ------------------------------------------------------------------------------------
    [10/25/2015]
    + No Bugs Found in updateCoins

    1.03 - shuffle() / unittest3.c
    ------------------------------------------------------------------------------------
    [10/25/2015]
    + No Bugs Found

    1.04 - fullDeckCount() / unittest4.c
    ------------------------------------------------------------------------------------
    [10/25/2015]
    + No Bugs Found

    ====================================================================================
    2.0 - cardtest
    ====================================================================================
    2.01 - smity / cardtest1.c
    ------------------------------------------------------------------------------------
    [10/25/2015]
    + No obvious bug found concerning effect

    2.02 - adventurer / cardtest2.c
    ------------------------------------------------------------------------------------
    [10/25/2015]
    + BUG: discardCount looking like garbage. Does not match expected
    + BUG: playedCards not incrementing

    2.03 - council_room / cardtest3.c
    ------------------------------------------------------------------------------------
    [10/25/2015]
    + BUG: handCount not updating correctly for the active player / +1 extra card drawn
    + BUG: deckCount not updating correctly for the active player / +1 extra card drawn

    2.04 - village / cardtest4.c
    ------------------------------------------------------------------------------------
    [10/25/2015]
    + No Bugs Found

 */
