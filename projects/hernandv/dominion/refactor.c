Victor Hernandez
CS_362_F15
Assignment 2 - Part 3 - Refactor and Bugs

Adventurer -
The Adventurer card effect was moved from the switch statement into void adventurerCard()
A bug that was introduced into the Adventurer card was at if(state->deckCount[currentPlayer] <1) which was changed to if(state->deckCount[currentPlayer] <=1). This would have the effect of shuffling the discard pile even if the players deck was not empty.

Smithy -
The Smithy card effect was moved from the switch statement into void smithyCard()
A bug that was introduced into the Smithy card was at discardCard(handPos, currentPlayer, state, 0) which was changed to discardCard(handPos, currentPlayer, state, 1) so that the trashFlag was set. This would have the effect of trashing the Smithy card and removing it from the players deck anytime it was played rather than placing it in the discard pile.

Village - 
The Village card effect was moved from the switch statement into void villageCard()
A bug that was introduced into the Village card was at state->numActions = state->numActions + 2; which was changed to state->numActions = state->numActions + 3;. This bug adds 3 actions to the Village card effect instead of 2, another bug that was introduced was at discardCard(handPos, currentPlayer, state, 0); which was changed to discardCard(handPos, currentPlayer, state, 1);. This bug sets the trashFlag, which would trash the Village card rather than put it into the players discard pile.

Great Hall - 
The Great Hall card effect was moved from the switch statement into void great_hallCard()
A bug that was introduced into the Great Hall card was at drawCard(currentPlayer, state); in which the statement was repeated twice in a row. The effect of this bug is that the card would draw two cards instead of only one as described by the card.

Outpost - 
The Outpost card was refactored into void outpostCard() and no bugs were introduced.