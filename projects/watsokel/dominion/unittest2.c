/* -----------------------------------------------------------------------
*
* -----------------------------------------------------------------------
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int checkDiscardCard(int handPos, int player, struct gameState* state,int handCount, int discardedCard){
  int r = discardCard(handPos,player,state,0);
  assert(r==0);
  //check handCount
#if (NOISY_TEST==1)
  printf("handCount=%d, expected=%d\n", state->handCount[player], (handCount-1));
#endif
  assert(state->handCount[player] == (handCount-1));
  //check discard pile for the card discarded
#if (NOISY_TEST==1)
  printf("discardCount=%d, expected=%d\n", state->discardCount[player], 1);
#endif
#if (NOISY_TEST==1)
  printf("discardedCard=%d, expected=%d\n",state->discard[player][(state->discardCount[player])-1], discardedCard);
#endif
  assert(state->discard[player][(state->discardCount[player])-1] == discardedCard);
  
  return 0;
}


int main() {
  int i,p,r;
  int seed = 1000;
  int numPlayers = 2;
  int k[10] = {adventurer, sea_hag, council_room, feast, gardens, mine
    , remodel, smithy, baron, salvager};
  struct gameState G;
  int handPos;
  int maxHandCount = 5;
  int estates[MAX_HAND];
  int golds[MAX_HAND];

  for (i = 0; i < MAX_HAND; i++){
    estates[i] = estate;
  }
  
  for (i = 0; i < MAX_HAND; i++){
    golds[i] = gold;
  }
  
  printf ("TESTING discardCard():\n");
	
	for (p = 0; p < numPlayers; p++){
		for(handPos = 0; handPos < maxHandCount; handPos++){
			memset(&G, 23, sizeof(struct gameState));   // clear game state
			r=initializeGame(numPlayers, k, seed, &G);  // initialize new game
			memcpy(G.hand[p], estates, sizeof(int) * maxHandCount); //set all cards in hand to estate
			G.hand[p][handPos]=gold; //set one card to be gold
			checkDiscardCard(handPos,p,&G,maxHandCount,gold);//remove the single gold card		
		}
	}
  /*  for (handCount = 1; handCount <= maxHandCount; handCount++){
      for(deckCount = 1; deckCount <= maxDeckCount; deckCount++){
        for(discardCount=1; discardCount <=maxDiscardCount; discardCount++){
          memset(&G, 23, sizeof(struct gameState));   // clear game state
          r=initializeGame(numPlayers, k, seed, &G);  // initialize new game
          G.handCount[p] = handCount;
          G.deckCount[p] = deckCount;
          G.discardCount[p] = discardCount;
          memcpy(G.hand[p], estates, sizeof(int) * handCount); //set all cards to estate
          memcpy(G.deck[p], estates, sizeof(int) * deckCount); //set all cards to estate
          memcpy(G.discard[p], estates, sizeof(int) * discardCount); //set all cards to estate
          estatesInHand = handCount;
          estatesInDeck = deckCount;
          estatesInDiscard = discardCount; 
          fullDeck = fullDeckCount(p, estate, &G);
#if (NOISY_TEST==1)
          printf("Estate: fullDeckCount=%d, expected=%d\n",fullDeck, estatesInHand+estatesInDeck+estatesInDiscard);
#endif
          assert(fullDeck == (estatesInHand+estatesInDeck+estatesInDiscard));
          memcpy(G.hand[p], coppers, sizeof(int) * handCount); //set all cards to copper
          memcpy(G.deck[p], coppers, sizeof(int) * deckCount); //set all cards to copper
          memcpy(G.discard[p], coppers, sizeof(int) * discardCount); //set all cards to copper
          coppersInHand = handCount;
          coppersInDeck = deckCount;
          coppersInDiscard = discardCount; 
          r = discardCard(p, copper, &G);
#if (NOISY_TEST==1)
          printf("Copper: fullDeckCount=%d, expected=%d\n",fullDeck, estatesInHand+estatesInDeck+estatesInDiscard);
#endif
          assert(fullDeck == (coppersInHand+coppersInDeck+coppersInDiscard));
        }
      }
    }    
  }      */
  
  printf("All tests passed!\n");

  return 0;
}