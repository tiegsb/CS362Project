All changes made to dominion.c
Note: All functions remain in dominion.c


*****
Functions created:

•	adventurerFunction()
•	smithyFunction()
•	villageFunction()
•	great_hallFunction()
•	stewardFunction()


*****
Function Implementations:

void adventurerFunction(int drawntreasure, struct gameState *state, int currentPlayer, int cardDrawn, int temphand[], int z) {
	while (drawntreasure<2) {
		if (state->deckCount[currentPlayer] <1) {//if the deck is empty we need to shuffle discard and add to deck
			shuffle(currentPlayer, state);
		}
		drawCard(currentPlayer, state);
		cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer] - 1];//top card of hand is most recently drawn card.
		if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
			drawntreasure++;
		else {
			temphand[z] = cardDrawn;
			state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
			z++;
		}
	}
	while (z - 1 >= 0) {
		state->discard[currentPlayer][state->discardCount[currentPlayer]++] = temphand[z - 1]; // discard all cards in play that have been drawn
		z = z - 1;
	}
}

void smithyFunction(int currentPlayer, struct gameState *state, int handPos) {
	int i;
	for (i = 0; i < 3; i++)
	{
		drawCard(currentPlayer, state);
	}

	//discard card from hand
	discardCard(handPos, currentPlayer, state, 0);
}

void villageFunction(int currentPlayer, struct gameState *state, int handPos) {
	//+1 Card
	drawCard(currentPlayer, state);

	//+2 Actions
	state->numActions = state->numActions + 2;

	//discard played card from hand
	discardCard(handPos, currentPlayer, state, 0);
}

void great_hallFunction(int currentPlayer, struct gameState *state, int handPos) {
	//+1 Card
	drawCard(currentPlayer, state);

	//+1 Actions
	state->numActions++;

	//discard card from hand
	discardCard(handPos, currentPlayer, state, 0);
}

void stewardFunction(int currentPlayer, struct gameState *state, int handPos, int choice1, int choice2, int choice3) {
	if (choice1 == 1)
	{
		//+2 cards
		drawCard(currentPlayer, state);
		drawCard(currentPlayer, state);
	}
	else if (choice1 == 2)
	{
		//+2 coins
		state->coins = state->coins + 2;
	}
	else
	{
		//trash 2 cards in hand
		discardCard(choice2, currentPlayer, state, 1);
		discardCard(choice3, currentPlayer, state, 1);
	}

	//discard card from hand
	discardCard(handPos, currentPlayer, state, 0);
}


*****
Switch statement within cardEffect() (only applicable code shown):
…
    case adventurer:
		adventurerFunction(drawntreasure, state, currentPlayer, cardDrawn, temphand, z);
      return 0;
…
    case smithy:
		smithyFunction(currentPlayer, state, handPos);
      return 0;
		
    case village:
		villageFunction(currentPlayer, state, handPos);
      return 0;
…
    case great_hall:
		great_hallFunction(currentPlayer, state, handPos);
      return 0;
…
    case steward:
		stewardFunction(currentPlayer, state, handPos, choice1, choice2, choice3);
      return 0;
…


*****
Introduced bugs:

adventurerFunction();
•	Line 3: while statement will be entered only when drawntreasure is less than 2 and the number of actions is less than 2
•	Lines 4 and 6: have beenswapped 
•	Line 11: should read ‘temphand[z] = cardDrawn;’ not ‘temphand[currentPlayer] = cardDrawn;’

void adventurerFunction(int drawntreasure, struct gameState *state, int currentPlayer, int cardDrawn, int temphand[], int z) {
	while (drawntreasure<2 && state->numActions<2) {
		if (state->deckCount[currentPlayer] <1) {//if the deck is empty we need to shuffle discard and add to deck
			drawCard(currentPlayer, state);
		}
		shuffle(currentPlayer, state);
		cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer] - 1];//top card of hand is most recently drawn card.
		if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
			drawntreasure++;
		else {
			temphand[currentPlayer] = cardDrawn;
			state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
			z++;
		}
	}
	while (z - 1 >= 0) {
		state->discard[currentPlayer][state->discardCount[currentPlayer]++] = temphand[z - 1]; // discard all cards in play that have been drawn
		z = z - 1;
	}
}


smithyFunction()
•	Line 4: is now ‘<=’when it should be ‘<’ 
•	Line 6: If statement will only be executed if the number of cards in the player’s hand is greater than the number of coins the player has
•	The call to discardCard() has been removed as well.

void smithyFunction(int currentPlayer, struct gameState *state, int handPos) {
	//+3 Cards
	int i;
	for (i = 0; i <= 3; i++)
	{
		if (state->hand[currentPlayer][state->handCount[currentPlayer]] > state->coins)
			drawCard(currentPlayer, state);
	}
}
	discardCard(handPos, currentPlayer, state, 0);


villageFunction()
•	Line 3: If statement added where the deckCount must be less than the handcount
•	Line 7: should read ‘state->numActions = state->numActions + 2;’ not ‘state->numActions = state->numActions + state->numBuys;’

void villageFunction(int currentPlayer, struct gameState *state, int handPos) {
	//+1 Card
	if (state->deckCount < state->handCount)
		drawCard(currentPlayer, state);

	//+2 Actions
	state->numActions = state->numActions + state->numBuys;
	
	//discard played card from hand
	discardCard(handPos, currentPlayer, state, 0);
}


great_hallFunction()
•	Line 3: While statement added where handpost is set to 0 and must be less than the handCount
•	Line 12: ‘state->numBuys’ has replaced ‘handPos’

void great_hallFunction(int currentPlayer, struct gameState *state, int handPos) {
	//+1 Card
	while (handPos = handPos - handPos, handPos < state->handCount) {
		drawCard(currentPlayer, state);
		handPos++;
	}

	//+1 Actions
	state->numActions++;

	//discard card from hand
	discardCard(state->numBuys, currentPlayer, state, 0);
}


stewardFunction()
•	Line 8: choice1 is now choice 2Line 11: ‘state->coins = state->coins + 2;’ is now ‘state->coins = state->numPlayers + 2;’
•	Lines 16 and 17: choice2 and choice3 are now choice1 and choice2
•	discardCard was removed

void stewardFunction(int currentPlayer, struct gameState *state, int handPos, int choice1, int choice2, int choice3) {
	if (choice1 == 1)
	{
		//+2 cards
		drawCard(currentPlayer, state);
		drawCard(currentPlayer, state);
	}
	else if (choice2 == 2)
	{
		//+2 coins
		state->coins = state->numPlayers + 2;
	}
	else
	{
		//trash 2 cards in hand
		discardCard(choice1, currentPlayer, state, 1);
		discardCard(choice2, currentPlayer, state, 1);
	}
}