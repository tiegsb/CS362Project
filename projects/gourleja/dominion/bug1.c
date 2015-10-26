/*
 * Jason Gourley
 * gourleja@oregonstate.edu
 * CS362-400
 * Assignment 3 - bug1.c
 * Description : Bug results from unit tests
 */

/*

    Bugs Found in Testing:

    1. Description: Coins not correctly incremented when playing an action card that increases the number of coins the player has.  
        This was found running the unit tests on the playCard method.  The problem does not necessarilly exist in this method, but in the combination of methods called from within and how the bonus coins are handled.  The value of coins is correctly updated in the first call correctly, but in the second call the state is rebuilt and the coins are reset to the prebonus amount.

    2. Description: Smithy card is adding an additional card into the players hand.
        The playing of the Smithy card should add an additional 3 cards to the players hand, however the implementation of cardSmithy method is actually adding an additional card to the players hand.

    3. Description: Adventurer card played with no treasure cards in the deck or discard pile still adds cards to the hand.  This seems to occur because of how the adventurer card is structured using a temporary hand and copy the cards back to the state object player hand.  The number of times the cards are evaluated in the copy function is also incorrect.

    3. Description: Minion card played without an option choice set will fall through without any error handling, allowing for the card to be played without either option being exercised.

*/
