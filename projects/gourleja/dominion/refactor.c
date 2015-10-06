Jason Gourley
gourleja
CS362-400
Assignment 2 - refactor.c

-------------------------------------------------------------------------------
Refactored Code
-------------------------------------------------------------------------------

Smithy Card
    Moved card code from switch statement to method cardSmithy()
    Bugs Introduced:
        Changed for loop condition to "i <= 3" from "i < 3"


Adventurer Card
    Moved card code from switch statement to method cardAdventurer()
    Bugs Introduced:
        Changed shuffle condition from "state->deckCount[currentPlayer] < 1" to "state->deckCount[currentPlayer] <= 1"
        Changed variable z from post-increment to pre-increment in the else block


Baron Card
    Moved card code from switch statement to method cardBaron()
    Bugs Introduced:
        Removed the decrement line for estate supply count: "state->supplyCount[estate]--;//Decrement Estates"


Salvager Card
    Moved card code from switch statement to method cardSalvager()
    Bugs Introduced:
        Changed "state->numBuys++;" to "state->numActions++"


Council Room Card
    Moved card code from switch statement to method cardCouncilRoom()
    Bugs Introduced:
        None
