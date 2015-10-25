/*
 * Jason Gourley
 * gourleja@oregonstate.edu
 * CS362-400
 * Assignment 3 - bug1.c
 * Description : Bug results from unit tests
 */

/*

    Bugs Found:

    1. Description: Coins not correctly incremented when playing an action card that increases the number of coins the player has.  
        This was found running the unit tests on the playCard method.  The problem does not necessarilly exist in this method, but in the combination of methods called from within and how the bonus coins are handled.  The value of coins is correctly updated in ...

    2. Description: Smithy card is adding an additional card into the players hand.
        The playing of the Smithy card should add an additional 3 cards to the players hand, however the implementation of cardSmithy method is actually adding an additional card to the players hand.

*/
