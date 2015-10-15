Robert Ward
10-11-2015
Assignment 2

Implemented cards and bugs added
playAdventure: I left out the -1 in 
    cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer] -1 ]; // code with error
    cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer] ];    // my code

playSmithy: in the discardCard function I used 2 instead of 0 for the last option.
    discardCard(handPos, currentPlayer, state, discard); // discard = 2 not 0

playVillage: set numActions to equal 2 instead of adding 2
    state->numActions = 2;

playGreat_hall: no intentional changes to great hall card

playCouncil_room: the loop for other players starts counting at 1 instead of 0
    for (i=1; i < state->numPlayers; i++);

