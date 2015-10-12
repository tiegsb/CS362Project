James Carlin
refactor.c


I refactored 5 total cards for the purpose of this assignment. After refactoring, I replaced code within switch statements to use the new functions I created. The five cards I refactored were:
	GreatHall
	Adventurer
	Smithy
	Village
	Cutpurse

This file contains the documentation from those five cards.








int greatHallCard(struct gameState *state, int currentPlayer, int handPos);

	The greatHall card is an action card. It adds 1 victory point and increases the game state's actions to +1. The card then discards this card from the player's hand.

	The bug I introduced to this was adding +2 actions, instead of +1;


int adventurerCard(struct gameState *state, int currentPlayer);

	This card draws cards until two treasure cards are found. After the treasure cards are found, all other cards are discarded. 

	The bug I introduced changes how the the treasure cards are added. Instead of drawntreasure++, I used drawntreasure +2, which will end the loop after one treasure is drawn.


int smithyCard(struct gameState *state, int currentPlayer, int handPos);

	The smithy card adds 3 cards to the current player's hand. It does this via a for loop which loops through until i is = 3. 

	The bug I added adds an changed the for loop from i < 3 to i > 3, which will cause it to loop one additional time. 


int villageCard(struct gameState *state, int currentPlayer, int handPos);

	This card adds +2 action to the game state. This card is discarded after use. 

	The bug I introduced is changed return 0 to return 1.

int cutpurseCard(struct gameState *state, int currentPlayer, int handPos);

	When played, this card adds +2 to the current player's coins. It then makes the other player discard coin.  If there is not enough coin, the player has to reveal their hand. 

	The bug I introduced as added an unused "m" variable to the function. 