Refectored the following switch cases into functions:

int smithyCard(int currentPlayer, struct gameState *state, int handPos);

int adventurerCard(int currentPlayer, struct gameState *state, int handPos);

int mineCard(int currentPlayer, struct gameState *state, int handPos, int choice1, int choice2);

int minionCard(int currentPlayer, struct gameState *state, int handPos, int choice1, int choice2);

int villageCard(int villageCard(int currentPlayer, struct gameState *state, int handPos);

############################################################################################################

  Bugs introduced:

mineCard: reversed the input parameters between choice1 and choice2
    from this: int mineCard(int currentPlayer, struct gameState *state, int handPos, int choice1, int choice2)

    to this: int mineCard(int currentPlayer, struct gameState *state, int handPos, int choice2, int choice1)

smithyCard: included the discardCard function in the drawCard for loop so instead of discarding only one card
    3 cards get discarded.

minionCard: on line 780, the discardCard parameters are changed so that instead of the opposing player discarding
    their hands, they trash their hands.

    from this: discardCard(handPos, i, state, 0);

    to this: discardCard(handPos, i, state, 1);
    
adventurerCard: line 684 off by one error: 1 more card gets discarded but doesnt get removed from hand so another card gets created.

    from this: while(z-1>=0)

    to this: while(z>=0){