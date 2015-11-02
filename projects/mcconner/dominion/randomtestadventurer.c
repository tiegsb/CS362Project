/* Rachael McConnell
 * CS362 Fall 2015
 * Random Test Adventurer
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>

int testAdventurerCard(struct gameState *after, int drawnTreasure, int temphand[], int currentPlayer, int numPlayers) {
  int z = 0, i=0, k=0;
  int treasureCards = 0;
  int newCard;
  int inHandBefore = 0;
  int inHandAfter = 0;
  struct gameState before;
  memcpy(&before, after, sizeof(struct gameState));
  int cardDrawn = 0;
  int failedTests = 0;

  for(i=0;i<before.handCount[currentPlayer];i++){
    if(before.hand[currentPlayer][i] == adventurer)
      inHandBefore = 1;
  }


  //call adventurerCard
  adventurerCard(drawnTreasure, currentPlayer, after, cardDrawn, temphand, z);

  
  for(i=0;i<after->handCount[currentPlayer];i++){
    if(after->hand[currentPlayer][i] == adventurer)
      inHandAfter = 1;
  }

  int pos = after->handCount[currentPlayer] - 2;
  newCard = after->hand[currentPlayer][pos];
  if(newCard == copper || newCard == silver || newCard == gold)
    treasureCards++;
  
  pos = after->handCount[currentPlayer] - 1;
  newCard = after->hand[currentPlayer][pos];
  if(newCard == copper || newCard == silver || newCard == gold)
    treasureCards++;

    //check the currentPlayer's cards
    printf("Current Player:\n");
    printf("Before: deck=%d, hand=%d, discard=%d\n", before.deckCount[currentPlayer], before.handCount[currentPlayer], before.discardCount[currentPlayer]);
    printf("After:  deck=%d, hand=%d, discard=%d\n", after->deckCount[currentPlayer], after->handCount[currentPlayer], after->discardCount[currentPlayer]);

    if(before.deckCount[currentPlayer]-2 >= after->deckCount[currentPlayer]){
      printf("PASS: deckCount decreased by at least 2 cards\n");
    }else{
      printf("FAIL: deckCount did not decrease by at least 2 cards.\n");
      failedTests++;
    }
    if(before.handCount[currentPlayer]+2 == after->handCount[currentPlayer]){
      printf("PASS: handCount increased by 2\n");
    }else{
      printf("FAIL: handCount did not increase by 2.\n");
      failedTests++;
    }
    if(before.discardCount[currentPlayer]+2 <= after->discardCount[currentPlayer]){
      printf("PASS: discardCount... .\n");
    }else{
      failedTests++;
      printf("FAIL: discardCount ... .\n");
    }
    if(treasureCards == 2){
      printf("PASS: treasureCards count incremented by 2.\n");
    }else{
      printf("FAIL: treasureCards count did not increment by 2.\n"); 
      failedTests++;
    }
    if(inHandBefore > inHandAfter){
      printf("PASS: adventurerCard has been discarded from hand.\n");
    }else{
      printf("FAIL: adventurerCard was not discarded from hand.\n");
      failedTests++;
    }



  //ensure that the other players' # of cards in hand, deck, and discard did not change 
  for(k=0;k<numPlayers;k++){
    if(k != currentPlayer){
    printf("For player %d:\n", k);
    printf("Before: deck=%d, hand=%d, discard=%d\n", before.deckCount[k], before.handCount[k], before.discardCount[k]);
    printf("After:  deck=%d, hand=%d, discard=%d\n", after->deckCount[k], after->handCount[k], after->discardCount[k]);

    if(before.deckCount[k] == after->deckCount[k] && before.handCount[k] == after->handCount[k] && before.discardCount[k] == after->discardCount[k]){
      printf("PASS: Deck, hand & discard piles remain the same\n");
    }else{
      printf("FAIL: At least one of the card piles changed.\n");
      failedTests++;
    }  
    }
  }
  printf("Failed Tests: %d\n", failedTests);

  if(failedTests == 0)
    return 0;
  else
    return 1;

}

int main(){
	int numTests = 100;	
	int i;
	int kingdom[10]= { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	int numPlayers;
	int randomSeed;
	struct gameState GS;
	int drawnTreasure = 0;
	int currentPlayer;
	int temphand[MAX_HAND];
	int j;
	int deckCount;
	int handCount;
        int testReturn = 0;
	int randomCards[12]= { council_room, gardens, remodel, smithy, village, baron, great_hall, copper, silver, gold, estate, duchy };
	randomSeed = time(NULL);
	srand(randomSeed);

	//RUN TESTS	
	printf("Running %d tests...\n", numTests);
	for(i=0;i<numTests;i++){
		printf("\nTest #%d\n", i+1);
		
		//set number of players
		numPlayers = rand() % 2 + 2;
		GS.numPlayers = numPlayers;
		GS.playedCardCount = 0;
		currentPlayer=rand() % numPlayers;
		
		initializeGame(numPlayers, kingdom, randomSeed, &GS);

		for(j=0;j<numPlayers;j++){
			deckCount = (rand()% 70)+30;  /*deckCount can be between 30-100 */
			handCount = 5;  /*handCount starts at 5 */
			GS.deckCount[j] = deckCount - handCount;
			GS.handCount[j] = handCount;	
		}

		//assign cards to hand and deck
		int card;
		int k, a;
		for(j=0;j<numPlayers;j++){
			for(k=0;k<GS.deckCount[j];k++){
				card = randomCards[rand() % 14];
				GS.deck[j][k] = card;
			}
			for(a=0;a<GS.handCount[j];a++){
				if(a == 0 && currentPlayer == j){
					GS.hand[j][a] = adventurer;
				}else{
					card = randomCards[rand() % 14];
					GS.hand[j][a] = card;
				}	
			}
		}
		
		testReturn = testAdventurerCard(&GS, drawnTreasure, temphand, currentPlayer, numPlayers);
		memset(&GS, 23, sizeof(struct gameState));
		
	}

  if(testReturn == 0)
    printf("\nAll tests passed!\n");
  else
    printf("\nSome tests failed.\n");

  return 0;
}
