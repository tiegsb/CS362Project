/* Rachael McConnell
 * CS362 Fall 2015
 * Random Test Card: Council Room Card
 * Assignment 4 
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

int testCouncilRoomCard(struct gameState *after, int temphand[], int currentPlayer, int numPlayers) {
  int i=0, k=0;
  int inHandBefore = 0;
  int inHandAfter = 0;
  int handPos = 0;
  struct gameState before;
  memcpy(&before, after, sizeof(struct gameState));
  int failedTests = 0;
  int failedTestsOthers = 0;

  for(i=0;i<before.handCount[currentPlayer];i++){
    if(before.hand[currentPlayer][i] == council_room)
      inHandBefore = 1;
  }


  //call council_roomCard
  council_roomCard(currentPlayer, after, handPos);

    
  for(i=0;i<after->handCount[currentPlayer];i++){
    if(after->hand[currentPlayer][i] == council_room)
      inHandAfter = 1;
  }

    //check the currentPlayer's cards
    printf("Current Player:\n");
    printf("Before: deck=%d, hand=%d, discard=%d\n", before.deckCount[currentPlayer], before.handCount[currentPlayer], before.discardCount[currentPlayer]);
    printf("After:  deck=%d, hand=%d, discard=%d\n", after->deckCount[currentPlayer], after->handCount[currentPlayer], after->discardCount[currentPlayer]);

    if(before.deckCount[currentPlayer]-4 >= after->deckCount[currentPlayer]){
      printf("PASS: deckCount decreased by 4 cards\n");
    }else if(before.deckCount[currentPlayer] < 4){
      printf("N/A: deckCount started at less than 4 and therefore could not decrease by 4.\n");
    }else{
      printf("FAIL: deckCount did not decrease by 4 cards.\n");
      failedTests++;
    }
    if(before.handCount[currentPlayer]+3 == after->handCount[currentPlayer]){
      printf("PASS: handCount increased by 3\n");
    }else if(before.deckCount[currentPlayer] < 4){
      printf("N/A: deckCount started at less than 3 so handCount could not increase by 3.");
    }else{
      printf("FAIL: handCount did not increase by 3.\n");
      failedTests++;
    }
    if(before.discardCount[currentPlayer] == after->discardCount[currentPlayer]){
      printf("PASS: discardCount did not change.\n");
    }else{
      failedTests++;
      printf("FAIL: discardCount changed.\n");
    }
    if(inHandBefore > inHandAfter){
      printf("PASS: council_room card has been discarded from hand.\n");
    }else{
      printf("FAIL: council_room card was not discarded from hand.\n");
      failedTests++;
    }
    if(before.numBuys +1 == after->numBuys){
      printf("PASS: number of buys increased by 1. Before %d, After %d\n", before.numBuys, after->numBuys);
    }else{
      printf("FAIL: number of buys did not increase by 1.\n");
      failedTests++;
    }


  if(before.playedCardCount + 1 == after->playedCardCount){
    printf("PASS: playedCardCount increased by 1.\n");
  }else{
    printf("FAIL: playedCardCount before: %d, after %d\n", before.playedCardCount, after->playedCardCount);
    failedTests++;
  }

  //ensure that the other players' # of cards in discard pile did not change 
  // ensure that other players' # of cards in their hand increased by 1, and deck decreased by 1
  for(k=0;k<numPlayers;k++){
    if(k != currentPlayer){

    printf("For player %d:\n", k);
    printf("Before: deck=%d, hand=%d, discard=%d\n", before.deckCount[k], before.handCount[k], before.discardCount[k]);
    printf("After:  deck=%d, hand=%d, discard=%d\n", after->deckCount[k], after->handCount[k], after->discardCount[k]);

    if(before.deckCount[k]-1 == after->deckCount[k] && before.handCount[k]+1 == after->handCount[k] && before.discardCount[k] == after->discardCount[k]){
      printf("PASS: Discard pile remains the same. Cards in hand have increased by 1. Cards in deck decreased by 1.\n");
    }else if(before.deckCount[k] == 0){
      printf("N/A: Deck count started at 0,");
    }else{
      printf("FAIL: At least one of the card piles is WRONG.\n");
      failedTestsOthers++;
    }  
    }
  }

  //count other players tests as one test
  if(failedTestsOthers > 0)
    failedTests++;
  
  //printf("Failed Tests: %d\n", failedTests);

  if(failedTests == 0)
    return 0;
  else
    return failedTests;

}

int main(){
	int numTests = 1000;	
	int i;
	int kingdom[10]= { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	int numPlayers;
	int randomSeed;
	struct gameState GS;
	int currentPlayer;
	int temphand[MAX_HAND];
	int j;
	int deckCount;
	int handCount;
    int testReturn = 0;
	int randomCards[12]= { adventurer, gardens, remodel, smithy, village, baron, great_hall, copper, silver, gold, estate, duchy };
	randomSeed = time(NULL);
	srand(randomSeed);

	//RUN TESTS	
	printf("Running %d tests...\n", numTests);
	for(i=0;i<numTests;i++){
		printf("\nTest #%d\n", i+1);
		
		// Set number of players
		numPlayers = rand() % 2 + 2; /* 2-4 */
		GS.numPlayers = numPlayers;
		GS.playedCardCount = 0;
		// Get current player
		currentPlayer=rand() % numPlayers;
		
		initializeGame(numPlayers, kingdom, randomSeed, &GS);
		// Get deckCount and handCount for each player
		for(j=0;j<numPlayers;j++){
			deckCount = (rand()% 100);  /*deckCount can be between 0-100 */
			handCount = (rand()% 50)+1;  /*handCount is between 1 and 50 */
			GS.deckCount[j] = deckCount;
			GS.handCount[j] = handCount;
			GS.numBuys = 0;
		}

		// Assign cards to hand and deck
		int card;
		int k, a;
		for(j=0;j<numPlayers;j++){
			for(k=0;k<GS.deckCount[j];k++){
				card = randomCards[rand() % 14];
				GS.deck[j][k] = card;
			}
			for(a=0;a<GS.handCount[j];a++){
			//currentPlayer must have council_room card in hand
			if(a == 0 && currentPlayer == j){
					GS.hand[j][a] = council_room;
				}else{
					card = randomCards[rand() % 14];
					GS.hand[j][a] = card;
				}	
			}
		}
		// Call the test function
		testReturn += testCouncilRoomCard(&GS, temphand, currentPlayer, numPlayers);
		memset(&GS, 23, sizeof(struct gameState));
		
	}

  if(testReturn == 0)
    printf("\nAll tests passed!\n\n");
  else
    printf("\nSome tests failed: %d tests failed out of %d.\n\n", testReturn, numTests*7);

  return 0;
}
