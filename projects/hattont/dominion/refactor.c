Ty Hatton
CS362 F15

Documentation of the bugs introduced into the dominion.c file.  5 cards have been refactored and all have a bug introduced.  

adventurerCard-
shuffles deck when one card is left

old code:
while(drawntreasure<2){
	//if the deck is empty we need to shuffle discard and add to deck
	if (state->deckCount[currentPlayer] <1)
      	shuffle(currentPlayer, state);

new code:
 while(drawntreasure < 2) {
    //if the deck is empty we need to shuffle discard and add to deck
    if (state->deckCount[currentPlayer] <= 1){
      shuffle(currentPlayer, state);


council_roomCard-
Skips the first player

old code:
      for (i = 0; i < state->numPlayers; i++)
new code:
      for (i = 1; i < state->numPlayers; i++)


smithyCard-
Draws two cards instead of 3
old code:
  for (i = 0; i < 3; i)
new code:
  for (i = 1; i < 3; i)


villageCard-
increases actions by 3 instead of 2

old code:
  state->numActions = state->numActions + 2;
new code:
  state->numActions = state->numActions + 3;


cutpurseCard-
 skips the first player

old code:
      for (i = 0; i < state->numPlayers; i++)	
new code:
       for (i = 1; i < state->numPlayers; i++)



