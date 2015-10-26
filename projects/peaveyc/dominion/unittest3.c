//Unit test for discardCard function
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "dominion.c"
#include "rngs.c"

/*int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)
{
	
  //if card is not trashed, added to Played pile 
  if (trashFlag < 1)
    {
      //add card to played pile
      state->playedCards[state->playedCardCount] = state->hand[currentPlayer][handPos]; 
      state->playedCardCount++;
    }
	
  //set played card to -1
  state->hand[currentPlayer][handPos] = -1;
	
  //remove card from player's hand
  if ( handPos == (state->handCount[currentPlayer] - 1) ) 	//last card in hand array is played
    {
      //reduce number of cards in hand
      state->handCount[currentPlayer]--;
    }
  else if ( state->handCount[currentPlayer] == 1 ) //only one card in hand
    {
      //reduce number of cards in hand
      state->handCount[currentPlayer]--;
    }
  else 	
    {
      //replace discarded card with last card in hand
      state->hand[currentPlayer][handPos] = state->hand[currentPlayer][ (state->handCount[currentPlayer] - 1)];
      //set last card to -1
      state->hand[currentPlayer][state->handCount[currentPlayer] - 1] = -1;
      //reduce number of cards in hand
      state->handCount[currentPlayer]--;
    }
	
  return 0;
}*/

void testDiscardCard(){
    printf("Testing discardCard()\n");
    struct gameState* game = malloc(sizeof(struct gameState));
    int i;
    game->deckCount[1] = 0;
    game->handCount[1] = 1;
    game->numPlayers = 1;
    game->whoseTurn = 1;
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
    game->hand[1][1] = copper;
    game->handCount[1] = 1;
    //game = gameStateCreate(2, 2, 0, 1, 0, 1, hand, handCount, deck, deckCount, discard, discardCount, playedCards, playedCardCount);
    discardCard(1, 1, game, 0);
    if(game->playedCardCount != 1)
        printf("Card did not move to discard pile\n");

    if(game->handCount[1] != 0)
        printf("Card was not removed from hand\n");

      game->playedCardCount = 0;
    discardCard(1, 1, game, 1);
    if(game->playedCardCount != 0)
        printf("Card moved to discard pile instead of trash\n");

    game->handCount[1] = 3;
    game->hand[1][1] = copper;
    game->hand[1][2] = silver;
    game->playedCardCount = 0;
    discardCard(1, 1, game, 1);
    if(game->hand[1][1] != silver)
        printf("%d should be silver\n", game->hand[1][1]);

    game->handCount[1] = 3;
    game->hand[1][1] = copper;
    game->hand[1][2] = silver;
    game->playedCardCount = 0;
    discardCard(2, 1, game, 1);
    if(game->hand[1][1] != copper)
        printf("%d should be copper\n", game->hand[1][1]);
}

int main(){
    testDiscardCard();
    return 0;
}