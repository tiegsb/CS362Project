Jibrahn Khoury
CS 362

Changes to adventurer, smithy, village, steward, and outpost

Adventurer changes:

	I put the shuffle function call into an if condition and checked for a negative
	return value, and return 1 if that is the case.


Smithy changes:

discardCard(handPos, currentPlayer, state, 0);
changed to
discardCard(handPos, currentPlayer+1, state, 0);

for (i = 0; i < 3; i++)
changed to
for (i = 1; i < 3; i++)

Village changes:

state->numActions = state->numActions + 2;
changed to
state->numActions = state->playedCardCount++ + 2;



Steward changes:

drawCard(currentPlayer, state);
changed to
drawCard(currentPlayer+1, state);

state->coins = state->coins + 2;
changed to
state->coins = state->coins + 1;

Outpost changes:

state->outpostPlayed++;
changed to
state->outpostPlayed;

discardCard(handPos, currentPlayer, state, 0);
changed to
discardCard(handPos--, currentPlayer, state, 0);