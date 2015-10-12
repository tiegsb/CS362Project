#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*BUGGED
 * This version of adventurer does not allow the player to keep gold
 * cards, they are discarded like all other non-treasure cards dtawn.
 * In the second if conditional, the card drawn is checked if it is
 * either a copper or silver. It should also check if the card is gold.
 */

int playAdventurer (struct gameState *state, int currentPlayer, int cardDrawn, int drawntreasure, int temphand[], int z){
	//printf("Made into playAdventurer\n");

	while (drawntreasure<2) {
		if (state->deckCount[currentPlayer] <1) {//if the deck is empty we need to shuffle discard and add to deck
			shuffle(currentPlayer, state);
		}
		drawCard(currentPlayer, state);
		cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card
		if (cardDrawn == copper || cardDrawn ==silver)
			drawntreasure++;
		else{
			temphand[z]=cardDrawn;
			state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
			z++;
		}
	}
	while (z-1>=0){
		state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
		z=z-1;
	}
	return 0;
}

/*BUGGED
 * This version of smithy only has the player draw 2 cards instead of 3.  
 * The for loop initializes i as 1 when it should be initialized as 0.
 */

int playSmithy (struct gameState *state, int currentPlayer, int handPos){
	int i;
	for (i = 1; i < 3; i++){
		drawCard(currentPlayer, state);
	}
	//discard card from hand
	discardCard(handPos, currentPlayer, state, 0);
	return 0;
}

/* BUGGED
 * This version of remodel allows the player to trash a card and gain a card
 * costing THREE more than the card trashed.  It should only by allowed to 
 * add a card costing two more.  In the third line, inside the if statement,
 * the cost of the coin should be added by 2, not 3.
 */

int playRemodel (struct gameState *state, int choice1, int choice2, int currentPlayer, int handPos){
	int i;
	int j = state->hand[currentPlayer][choice1];  //store card we will trash
	if ( (getCost(state->hand[currentPlayer][choice1]) + 3) > getCost(choice2) ){
		return -1;
	}

	gainCard(choice2, state, 0, currentPlayer);
		
	//discard card from hand
	discardCard(handPos, currentPlayer, state, 0);

	//discard trashed card
	for (i = 0; i < state->handCount[currentPlayer]; i++){
		if (state->hand[currentPlayer][i] == j){
			discardCard(i, currentPlayer, state, 1);
			break;
		}
	}
	return 0;
}


/*BUGGED
 * This version of village trashed the village card after it is used.  On the
 * second to last line, the discardCard funtion has the trashFlag set.  It 
 * should be called with a 0 as the last argument instead of a 1.
 */

int playVillage (struct gameState *state, int currentPlayer, int handPos){
	//+1 Card
	drawCard(currentPlayer, state);
	//+2 Actions
	state->numActions = state->numActions +2;
	//discard played card form hand
	discardCard(handPos, currentPlayer, state, 1);
	return 0;
}

//NOT BUGGED

int playMine (struct gameState *state, int choice1, int choice2, int currentPlayer, int handPos){
	int i;
	int j = state->hand[currentPlayer][choice1]; //store card we will trash
	
	if (state->hand[currentPlayer][choice1] < copper || state->hand[currentPlayer][choice1] > gold){
		return -1;
	}
	
	if (choice2 > treasure_map || choice2 < curse){
		return -1;
	}

	if ( (getCost(state->hand[currentPlayer][choice1]) + 3) > getCost(choice2) ){
		return -1;
	}

	gainCard(choice2, state, 2, currentPlayer);

	//discard card from hand
	discardCard(handPos, currentPlayer, state, 0);

	//discard trashed card
	for (i = 0; i < state->handCount[currentPlayer]; i++){
		if (state->hand[currentPlayer][i] == j){
			discardCard(i, currentPlayer, state, 1);
			break;
		}
	}

	return 0;
}
