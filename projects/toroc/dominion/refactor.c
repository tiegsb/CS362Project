/*
Carol D. Toro
CS 362
Assignment 2
Toroc@oregonstate.edu
#932676028


Assignment 2: Function Prototypes for 5 cards:
Smithy, Adventurer, Village, Great Hall, Council Room

int smithyCard(struct gameState* state, int currentPlayer, int handPos);
int adventurerCard(struct gameState* state, int currentPlayer);
int villageCard(struct gameState* state, int currentPlayer, int handPos);
int great_hallCard(struct gameState* state, int currentPlayer, int handPos);
int council_roomCard(struct gameState* state, int currentPlayer, int handPos);

Smithy Card: The smithy card continues to draw 3 cards, but if third card
drawn is a gold treasure card, the smithy will grant an additional action.

Adventurer Card: The bug I had introduced into the implementation of the
Adventurer never gets triggered as it was introduced as an else if statement
following the if when a treasure card is found. I have now replace the old
bug with the following new bug:
If the treasure count is 2 and the drawn treasure is gold, the user's buy is decremented.
OLD BUG: Anytime a silver treasure card is drawn, it gets added into 
the temp hand instead of the player's hand. The drawn treasure is also 
decremented so that it still appears that the Adventure card is drawing up
two treasure cards.

Village Card: Whenever a player has more than 2 cards in their deck count,
the village card will get discarded. This ensures that a majority of the time
the village card functions correctly. On the occasion that a player has less
than 2 cards in their deck count, they will draw an additional card.

Great Hall Card: Whenever a player has less than 2 cards in their deck count,
the great hall card will grant an additional buy. A majority of the time the
great hall card will behave as expected.

Council Room Card: The card will continue to grant the player four cards, but
whenever the fourth card is a gold treasure card, the user will gain an additional
action on top of the additional buy they receive from the card.

*/