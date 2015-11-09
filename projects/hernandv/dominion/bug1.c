Victor Hernandez
CS_362_F15
Assignment 3 - Part 3 - bug1.c

cardtest1.c: Smithy Card - 
A bug was introduced in the previous assignment into the Smithy card, where the trash flag was set in discardCard(handPos, currentPlayer, state, 1). This causes the Smithy card to be trashed rather than placed in the played cards pile after it's use, removing it from the player's deck. This bug was identified in cardtest1.c by checking the playedcards pile for the Smithy card, this test PASSED as the card was not found in the playedcard pile.

cardtest2.c: Adventurer Card - 
A bug was introduced in the previous assignment into the Adventurer card, where the discard pile would be shuffled due to a change in if(state->deckCount[currentPlayer] <=1), even though this was not appropriate. I was unable to create test to check for this condition but was able to find a bug where the adventurer card remained in the player's hand and was not being discarded. I was also able to verify that at least one treasure card was added to the player's current hand.

cardtest3.c: Village Card - 
Two bugs were introduced in the previous assignment into the Village card, where 1) the number of actions given to the village card in state->numActions = state->numActions + 3, and 2) where the trash flag was set at discardCard(handPos, currentPlayer, state, 1). Both of these bugs were identified in cardtest3.c with failed tests checking for correct number of actions and checking if the village card was placed into the played card pile.

cardtest4.c: Great Hall Card -
A bug was introduced in the previous assignment into the Great Hall card where the number of additional cards drawn was incorrect due to the addition of drawCard(currentPlayer, state). This bug was identified in cardtest4.c by a failed test checking for the correct number of cards to be drawn

unittest4.c: drawcard() - 
A bug was identified in the drawncard() function where a card was drawn from an empty deck and the player having a non-empty discard pile by a failed test in unitest4.c. This would not normally happen as the discard pile should be shuffled and the player should draw from this newly reorganized deck.
