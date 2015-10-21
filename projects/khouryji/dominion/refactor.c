Jibrahn Khoury
CS 362

Changes to adventurer, smithy, village, steward, and outpost

Adventurer changes:

tempHand's array size is set to 4 instead of MAX_HAND.
While loop condition set to drawntreasure<20 instead of <2.
shuffle(currentPlayer,state) changed to shuffle(currentPlayer++,state)
[state->handCount[currentPlayer]-1] changed to [state->handCount[currentPlayer+1]-1]
in line: cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1]; 

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

discardCard(handPos,
changed to
discardCard(handPos--,

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