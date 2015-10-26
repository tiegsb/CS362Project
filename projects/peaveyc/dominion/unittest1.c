//unit test for UpdateCoins function
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "dominion.c"
#include "rngs.c"

/*int updateCoins(int player, struct gameState *state, int bonus)
{
    int i;
	
    //reset coin count
    state->coins = 0;

    //add coins for each Treasure card in player's hand
    for (i = 0; i < state->handCount[player]; i++){
        if (state->hand[player][i] == copper){
	        state->coins += 1;
	    }
        else if (state->hand[player][i] == silver){
            state->coins += 2;
	    }
        else if (state->hand[player][i] == gold){
            state->coins += 3;
	    }	
    }	

    //add bonus
    state->coins += bonus;

    return 0;
}*/

void testUpdateCoins(){
    printf("Testing UpdateCoins()\n");
    struct gameState* game = malloc(sizeof(struct gameState));
    int i;
    game->deckCount[1] = 0;
    game->deckCount[2] = 0;
    //hand 1
    game->hand[1][1] = copper;
    game->hand[1][3] = copper;
    game->hand[1][2] = silver;
    game->handCount[1] = 3;
    //hand 2
    game->hand[2][1] = copper;
    game->hand[2][2] = silver;
    game->hand[2][3] = gold;
    game->hand[2][4] = copper;
    game->handCount[2] = 4;
    //assignment to gamestate
    game->numPlayers = 2;
    game->whoseTurn = 2;
    for(i=0; i<treasure_map + 1; i++){
        game->supplyCount[i] = 12;
        game->embargoTokens[i] = 0;
    }
    game->outpostPlayed = 0;
    game->outpostTurn = -1;
    game->phase = 0;
    game->numActions = 1;
    game->coins = 0;
    game->numBuys = 1;
    //game = gameStateCreate(2, 2, 0, 1, 0, 1, hand, handCount, deck, deckCount, discard, discardCount, playedCards, playedCardCount);
    updateCoins(2, game, 0);
    if(game->coins != 6)
        printf("Coins should = 6. Coins actually = %i\n", game->coins);
}
int main(){
    testUpdateCoins();
    return 0;
}