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
  int deckTreasureCards = 0;
  int handTreasureCards = 0;
  int failedTestsOthers = 0;

  for(i=0;i<before.handCount[currentPlayer];i++){
    if(before.hand[currentPlayer][i] == adventurer)
      inHandBefore = 1;
  }
  
  for(i=0; i<before.deckCount[currentPlayer];i++){
    int card1 = before.deck[currentPlayer][i];
    int card2 = before.hand[currentPlayer][i];
    if(card1 == copper || card1 == silver || card1 == gold)
      deckTreasureCards++;
    if(card2 == copper || card2 == silver || card2 == gold)
      handTreasureCards++;
  }
  
  //call adventurerCard
  adventurerCard(drawnTreasure, currentPlayer, after, cardDrawn, temphand, z);

  //set variable if adventurerCard remains in the currentPlayers hand
  for(i=0;i<after->handCount[currentPlayer];i++){
    if(after->hand[currentPlayer][i] == adventurer)
      inHandAfter = 1;
  }

  // check the last two cards in the currentPlayer's hand to make sure they are 
  // treasure cards
  int pos = after->handCount[currentPlayer] - 2;
  newCard = after->hand[currentPlayer][pos];
  //printf("newCard = %d\n", newCard);
  if(newCard == copper || newCard == silver || newCard == gold)
    treasureCards++;
  
  pos = after->handCount[currentPlayer] - 1;
  newCard = after->hand[currentPlayer][pos];
  //printf("newCard = %d\n", newCard);
  if(newCard == copper || newCard == silver || newCard == gold)
    treasureCards++;

    //check the currentPlayer's cards- deck, hand, discard
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

    int difference = before.deckCount[currentPlayer] - after->deckCount[currentPlayer] - 2;
 

    if(before.discardCount[currentPlayer]+difference == after->discardCount[currentPlayer]){
      printf("PASS: discardCount expected %d, actual %d\n", difference, after->discardCount[currentPlayer]);
    }else{
      failedTests++;
      printf("FAIL: discardCount expected %d, actual %d\n", difference, after->discardCount[currentPlayer]);
    }
    //check if treasureCards have increased by 2 in the current players hand
    if(deckTreasureCards >= 2 && treasureCards == 2){
      printf("PASS: treasureCards count incremented by 2.\n");
    }else if(deckTreasureCards < 2 && treasureCards < 2){
      printf("PASS: less than 2 treasureCards in deck.\n");
    }else{
      printf("FAIL: treasureCards count did not increment by 2.\n"); 
      failedTests++;
    }
    //check if adventurerCard has been discarded
    if(inHandBefore > inHandAfter){
      printf("PASS: adventurerCard has been discarded from hand.\n");
    }else{
      printf("FAIL: adventurerCard was not discarded from hand.\n");
      failedTests++;
    }
    if(before.playedCardCount + 1 == after->playedCardCount){
      printf("PASS: playedCardCount increased by 1.\n");
    }else{
      printf("FAIL: playedCardCount did not increase by 1.\n");
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
      failedTestsOthers++;
    }  
    }
  }
  //count check on other players cards as one test
  if(failedTestsOthers > 0)
    failedTests++;

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
	int drawnTreasure = 0;
	int currentPlayer;
	int temphand[MAX_HAND];
	int j;
	int deckCount;
	int handCount;
        int testReturn = 0;
	int randomCardsHand[9]= { council_room, gardens, remodel, smithy, village, baron, great_hall, estate, duchy };
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
			deckCount = (rand()% 100);  /* deckCount can be between 0 - 100 */
			handCount = (rand()% 50)+1;  /* hardCount ranges from 1 - 50*/
			GS.deckCount[j] = deckCount;
			GS.handCount[j] = handCount;	
		}

		//assign cards to hand and deck
		int card;
		int k, a;
		for(j=0;j<numPlayers;j++){
			for(k=0;k<GS.deckCount[j];k++){
				card = randomCards[rand() % 11];
				GS.deck[j][k] = card;
			}
			for(a=0;a<GS.handCount[j];a++){
				if(a == 0 && currentPlayer == j){
					GS.hand[j][a] = adventurer;
				}else{
					card = randomCardsHand[rand() % 8];
					GS.hand[j][a] = card;
				}	
			}
		}
		// Call test function
		testReturn += testAdventurerCard(&GS, drawnTreasure, temphand, currentPlayer, numPlayers);
		memset(&GS, 23, sizeof(struct gameState));
		
	}

  // Return number of tests that passed. Number of tests run is the variable numTests * 7
  if(testReturn == 0)
    printf("\nAll %d tests passed!\n", numTests);
  else
    printf("\nSome tests failed: %d tests failed out of %d\n", testReturn, numTests*7);

  return 0;
}
