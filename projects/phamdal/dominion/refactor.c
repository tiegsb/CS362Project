Changes made to cardeffect(): 
- Adventurer code moved to separate function: adventurer_card() in dominion.c. Function header 	added to dominion.h 
- Smithy code move to separate function: smithy_card() in dominion.c. Function header added to
	dominion.h
- Great Hall code moved to separate function: great_hall_card() in dominion.c. Function header
	added to dominion.h
- Cut Purse code moved to separate function: cutpurse_card() in dominion.c. Function header added
	to dominion.h
- Council Room code moved to separate function: council_room_card() in dominion.c. Function header
	added to dominion.h

Changes made to Adventurer code: 
Introduced a different comparision operator, 
original line :	while(drawntreasure < 2)
changed line:	while(drawntreasure <=2)

Changes made to Smithy code: 
Marked as a trash card instead of a played card: 
original line: 	discardCard(handPos, currentPlayer, state, 0);
changed line: 	discardCard(handPos, currentPlayer, state, 1);

Changes made to Great Hall code: 
Decrement instead of increment: 
original line:	state->numActions++;
changed line:	state->numActions--;

Marked as a trash card instead of a played card: 
original line: 	discardCard(handPos, currentPlayer, state, 0);
changed line: 	discardCard(handPos, currentPlayer, state, 1);

Changes made to Cut Purse code: 
Switch varibles in 2D array
original line:	if (state->hand[i][j] == copper)
changed line:	if (state->hand[j][i] == copper)

Changes made to Council Room code: 
Changed a conditional:
original line:	if ( i != currentPlayer )
changed line:	if ( i == currentPlayer )

Changed return statement: 
original line:	return 0; 
changed line:	return 1; 





