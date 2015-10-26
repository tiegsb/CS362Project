//Woo Choi
//cardtest3.c
//Steward Test

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

/*Testing steward
    case steward:
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
      return 0;


*/

int main(){

	int i;
    int seed = 1000;
    int numPlayer = 2;
    int r;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, steward, village, baron, great_hall};
    struct gameState G;
	int currentPlayer = whoseTurn(&G);
	int currentCardNum;	// number of cards before the steward card is played.
	//Begin steward testing
	printf("******************\n");
	printf("cardtest3.c\n");
	printf("steward Card Test:\n");
	printf("  choice1 == 1: \n");
    // initialize game state
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

	// gain steward for currentPlayer
	gainCard(steward, &G, 2, currentPlayer);	
	currentCardNum = G.handCount[0];
	
	// go through hand to look for the steward card
	// numbHandCards: How many cards current player has in hand 
	for (i = 0; i < numHandCards(&G); i++) {
		// handCard: enum value of indexed card in player's hand
		if(handCard(i, &G) == steward){
			// Play card with index handPos from current player's hand
			// set choice1 to 1
			playCard(i,1,-1,-1,&G);	
			// + 1 because discardCard was not used (so steward wasn't accounted for)
			printf("    Expected card count: %d\n    Actual card count: %d\n",currentCardNum+1,G.handCount[0]);		
		}
	}
	
	//Test for choice1 == 2
	printf("  choice1 == 2: \n");
	printf("    Tests for +2 coins, coins after should be +2 before\n");
    // initialize game state
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

	// gain steward for currentPlayer and add to hand
	gainCard(steward, &G, 2, currentPlayer);	
	currentCardNum = G.handCount[0];
	printf("    coins before steward is : %d\n", G.coins); 	
	// go through hand to look for the steward card
	// numbHandCards: How many cards current player has in hand 
	for (i = 0; i < numHandCards(&G); i++) {
		// handCard: enum value of indexed card in player's hand
		if(handCard(i, &G) == steward){
			// Play card with index handPos from current player's hand
			// set choice1 to 2
			playCard(i,2,-1,-1,&G);	
			// + 1 because discardCard was not used (so steward wasn't accounted for)
			printf("    coins after steward is : %d\n", G.coins); 
		}
	}
	
	//Test for choice1 == 3
	printf("  choice1 == 3: \n");
	printf("    tests for 2 discarded cards\n");
    // initialize game state
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

	// gain steward for currentPlayer
	gainCard(steward, &G, 2, currentPlayer);	
	currentCardNum = G.handCount[0];
	// go through hand to look for the steward card
	// numbHandCards: How many cards current player has in hand 
	for (i = 0; i < numHandCards(&G); i++) {
		// handCard: enum value of indexed card in player's hand
		if(handCard(i, &G) == steward){
			// Play card with index handPos from current player's hand
			// set choice1 to 2
			playCard(i,3,-1,-1,&G);	
			// + 1 because discardCard was not used (so steward wasn't accounted for)
			printf("    Expected card count: %d\n    Actual card count: %d\n",currentCardNum-3,G.handCount[0]);	
		}
	}		
	printf("steward Card Test is now over\n\n");
	return 0;
}