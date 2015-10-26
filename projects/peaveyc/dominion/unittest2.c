//Unit test for gainCard function
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "dominion.c"
#include "rngs.c"

/*int supplyCount(int card, struct gameState *state) {
  return state->supplyCount[card];
}

int gainCard(int supplyPos, struct gameState *state, int toFlag, int player)
{
  //Note: supplyPos is enum of choosen card
	
  //check if supply pile is empty (0) or card is not used in game (-1)
  if ( supplyCount(supplyPos, state) < 1 )
    {
      return -1;
    }
	
  //added card for [whoseTurn] current player:
  // toFlag = 0 : add to discard
  // toFlag = 1 : add to deck
  // toFlag = 2 : add to hand

  if (toFlag == 1)
    {
      state->deck[ player ][ state->deckCount[player] ] = supplyPos;
      state->deckCount[player]++;
    }
  else if (toFlag == 2)
    {
      state->hand[ player ][ state->handCount[player] ] = supplyPos;
      state->handCount[player]++;
    }
  else
    {
      state->discard[player][ state->discardCount[player] ] = supplyPos;
      state->discardCount[player]++;
    }
	
  //decrease number in supply pile
  state->supplyCount[supplyPos]--;
	 
  return 0;
}*/

void testGainCard(){
    printf("Testing GainCard()\n");
    struct gameState* game = malloc(sizeof(struct gameState));
    int i;
    game->deckCount[1] = 0;
    game->handCount[1] = 0;
    game->numPlayers = 2;
    game->whoseTurn = 2;
    for(i=0; i<treasure_map + 1; i++){
        game->supplyCount[i] = 12;
        game->embargoTokens[i] = 0;
    }
    game->discardCount[1] = 0; //setting player 1 discard pile to empty
    game->outpostPlayed = 0;
    game->outpostTurn = -1;
    game->phase = 0;
    game->numActions = 1;
    game->coins = 0;
    game->numBuys = 1;
    //game = gameStateCreate(2, 2, 0, 1, 0, 1, hand, handCount, deck, deckCount, discard, discardCount, playedCards, playedCardCount);
    gainCard(4, game, 0, 1);
    if(game->discardCount[1] != 1)
        printf("Card did not move to discard pile");
    gainCard(4, game, 1, 1);
    if(game->deckCount[1] != 1)
        printf("Card did not move to deck");
    gainCard(4, game, 2, 1);
    if(game->handCount[1] != 1)
        printf("Card did not move to discard pile");
    game->supplyCount[4] = 0;
    if(!gainCard(4, game, 0, 1))
      printf("Drew card from empty supply");
}

int main(){
    testGainCard();
    return 0;
}