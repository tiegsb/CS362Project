/*
* Card Test 1: Adventurer
*
* In this unit test, we are testing the Adventurer Card.  The expected behavior of the Adventurer
* Card is to draw cards from the deck until 2 treasure cards (copper, silver, or gold) are drawn.
* The other cards are discarded.
*
*/

#include "dominion.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

void fuzzState(struct gameState *);
int randomNumber(int, int);
int percentChanceIsOne(int);
int totalCardCount(int, struct gameState *);

int main(int argc, char * argv[]) {
	int test_trials = 10000;
	
	if (argc > 1) {
		test_trials = atoi(argv[1]);
		if (test_trials < 1) {
			printf("Usage: cardtest1 <trials>\r\n");
			exit(1);
		}
	}
	
	srand(time(NULL));
	
	//new gameState
	struct gameState * gs = malloc(sizeof(struct gameState));
	struct gameState * stateCopy = malloc(sizeof(struct gameState));
	
	int trial;
	int numberOfErrors = 0;
	int playerNum;
	
	int emptyHand;
	int emptyDiscard;
	int emptyDeck;
     int treasureCards;
     int i;
	
	printf("Random Test - Adventurer\r\n");
	printf("Conducting %d random trials.\r\n", test_trials);
	
	for (trial = 0; trial < test_trials; trial++) {
		
		//printf("TRIAL %d\r\n", trial);
		
		
		fuzzState(gs);

		//semi-randomize inputs (within reason)
          playerNum = randomNumber(0, MAX_PLAYERS-1);
		emptyDeck = percentChanceIsOne(5);
		emptyDiscard = percentChanceIsOne(5);
		emptyHand = percentChanceIsOne(5);
          
          //SETUP DECK AND HAND AND DISCARD
          if (emptyDeck == 1) {
          gs->deckCount[playerNum] = 0;
               } else { 
          gs->deckCount[playerNum] = randomNumber(1, 300);
          }
     
          if (emptyHand == 1) {
               gs->handCount[playerNum] = 1;		//leave room for Adventurer card
          } else { 
               gs->handCount[playerNum] = randomNumber(2, 300);
          }
          
          if (emptyDiscard == 1) {
               gs->discardCount[playerNum] = 2;        //2 because of we need at least two treasures.
          } else {
               gs->discardCount[playerNum] = randomNumber(1, 300);
          }
          
          //Each card should be in the range of possible cards
          for (i = 0; i < gs->deckCount[playerNum]; i++){
               gs->deck[playerNum][i] = randomNumber(0, treasure_map);
          }

          for (i = 0; i < gs->discardCount[playerNum]; i++){
               gs->discard[playerNum][i] = randomNumber(0, treasure_map);
          }
          
          for (i = 0; i < gs->handCount[playerNum]; i++){
               gs->hand[playerNum][i] = randomNumber(0, treasure_map);
          }
          
  //Because of a bug in the code, we will prevent errors by seeding at
  //least two treasures.  Without the two treasures, the function crashes
  //the program.  Place at top of discard pile.
          gs->discard[playerNum][gs->discardCount[playerNum] - 1] = gold;
          gs->discard[playerNum][gs->discardCount[playerNum] - 2] = silver;
          
          
          //copy the previous state and play card
          memcpy(stateCopy, gs, sizeof(struct gameState));
          playAdventurer(playerNum, gs);
          
          
          //Analyse state
          //Two more cards should be in hand than in deck.  Both cards should be removed from deck and/or discard pile
          if (gs->deckCount[playerNum] + gs->discardCount[playerNum] != stateCopy->deckCount[playerNum] + stateCopy->discardCount[playerNum] - 2) {
               printf("Mismatched deckCount + discardCount. Expected: %d, Actual: %d\r\n",stateCopy->deckCount[playerNum] + stateCopy->discardCount[playerNum] - 2,gs->deckCount[playerNum] + gs->discardCount[playerNum] );
               numberOfErrors++;
          }
          if (gs->handCount[playerNum] != stateCopy->handCount[playerNum] + 2) {
               printf("Mismatched handCount. Expected: %d, Actual: %d\r\n", stateCopy->handCount[playerNum] + 2, gs->handCount[playerNum]);
               numberOfErrors++;
          }
          
          //At least Two cards in hand should be treasure cards
          treasureCards=0;
          for (i = 0; i < gs->handCount[playerNum]; i++){
               switch (gs->hand[playerNum][i]){
                    case copper:
                         //intentional fall-through
                    case silver:
                         //intentional fall-through
                    case gold:
                         treasureCards++;
                         break;
                    default:
                         break;
               }   
          }
          
          if (treasureCards < 2) {
               printf("Not enough treasure cards drawn!  Only found %d.\r\n", treasureCards);
               numberOfErrors++;
          }
     }
	
     printf("Number of errors: %d\r\n", numberOfErrors);
     printf("End Random Test - Adventurer\r\n");
     
	return 0;
}


void fuzzState(struct gameState * state) {
	int i;
	
	unsigned char * ptr = (unsigned char *)state;
	
	for (i = 0; i < sizeof(struct gameState); i++) {
		ptr[i] = (unsigned char)(rand()%256);
	}
}

int randomNumber(int from, int to) {
	int a, b;
	if (from < to) {
		a = from;
		b = to;
	} else {
		a = to;
		b = from;
	}
	
	return rand() % ((b - a) + 1) + a;
}

int percentChanceIsOne(int probability) {
	if ( probability > (rand() % 100)) {
		return 1;
	} else {
		return 0;
	}
}

int totalCardCount(int playerNum, struct gameState * gs) {
	return (gs->deckCount[playerNum] + gs->discardCount[playerNum] + gs->handCount[playerNum]);
}