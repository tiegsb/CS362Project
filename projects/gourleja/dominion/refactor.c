Jason Gourley
gourleja@oregonstate.edu
CS362-400
Assignment 2/3 - refactor.c

-------------------------------------------------------------------------------
Refactored Code
-------------------------------------------------------------------------------

Smithy Card
    Moved card code from switch statement to method cardSmithy()
    Signature:
        void cardSmithy(int handPos, int player, struct gameState *state);
    Bugs Introduced:
        Changed for loop condition to "i <= 3" from "i < 3"

    Bugs Caught:
        The test case for this card did catch that there was an incorrect addition occuring.



Adventurer Card
    Moved card code from switch statement to method cardAdventurer()
    Signature:
        void cardAdventurer(int temphand[], int z, int cardDrawn, int drawntreasure, int handPos, int player, struct gameState *state);
    Bugs Introduced:
        Changed shuffle condition from "state->deckCount[currentPlayer] < 1" to "state->deckCount[currentPlayer] <= 1"
        Changed variable z from post-increment to pre-increment in the else block

    Bugs Caught:
        The test case for this card did catch that there was an issue with the increment of the z variable which required an inspection of running the file with ddd for debugging.

    Bugs Not Caught:
        For the bug where the shuffle of the deck was happening with a single card left instead of at none I couldn't figure out how to run a test case for this.  With the call for the shuffle I couldn't find a way to force the positions of cards to test using a black box method.  I think in order to actually catch this I would need to be manipulating the code in the method rather than just running an exterior test case.  In this type of circumstance knowing the bug existed I was unable to find a way to actually catch it.

Baron Card
    Moved card code from switch statement to method cardBaron()
    Signature:
        void cardBaron(int choice1, int handPos, int player, struct gameState *state);
    Bugs Introduced:
        Removed the decrement line for estate supply count: "state->supplyCount[estate]--;//Decrement Estates"


Salvager Card
    Moved card code from switch statement to method cardSalvager()
    Signature:
        void cardSalvager(int choice1, int handPos, int currentPlayer, struct gameState *state);
    Bugs Introduced:
        Changed "state->numBuys++;" to "state->numActions++"


Council Room Card
    Moved card code from switch statement to method cardCouncilRoom()
    Signature:
        void cardCouncilRoom(int handPos, int currentPlayer, struct gameState *state);
    Bugs Introduced:
        None
