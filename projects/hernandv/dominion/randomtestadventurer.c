#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.c"
#include "rngs.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>

#define MAX_TEST_ITER 15000
#define numPlayers 4

int testAdventurer() {

 	int gameSeed = rand();
    int p;
    int numPlayer;
    int i = 0;
    int iterCount = 0;
    int error1 = 0, error2 = 0;
    int k[10] = {adventurer, council_room, feast, gardens, mine,
                remodel, smithy, village, baron, great_hall};

	struct gameState* G = newGame();

    printf("-------RANDOM TESTING ADVENTURER CARD-------\n");

	while (iterCount != MAX_TEST_ITER) {
					
		int drawntreasure = 0;
		int cardDrawn = 0;
		int z = 0;
		int temphand[MAX_HAND];
        int randNum = rand()% 3; 
               
        numPlayer = rand()% 4;
        p = rand()% 4;

		initializeGame(numPlayer, k, gameSeed, G);
				
        if(randNum == 0){
            G->deckCount[p] = 0;
        } else if(randNum == 1) {
            G->deckCount[p] = -1;
        } else{
            G->deckCount[p] = floor(Random() * MAX_DECK);
        }

        G->discardCount[p] = floor(Random() * MAX_DECK);   
        G->playedCardCount = floor(Random() * MAX_DECK);		
		
        for(i = 0; i < G->deckCount[p]; i++){
            G->deck[p][i] = floor(Random() * 5);
        }
        
        for(i = 0; i < G->discardCount[p]; i++){
            G->discard[p][i] = floor(Random() * 5);
        }		
		
		G->hand[p][4] = adventurer;
		
		/*Checking handcount and cards in hand before playing adventurer*/
		printf("Hand count before Adventurer is %d...", G->handCount[p]);
		int i = 0, cardStatus;
		char c[25];
		for(i = 0; i < G->handCount[p]; i++){
			cardNumToName(G->hand[p][i], c);	//Converts card number to string
			if(strcmp(c, "Adventurer") == 0){
				cardStatus = 1;	//Card is present in hand
				}
			}
		//Play adventurer card
		adventurerCard(drawntreasure, G, p, cardDrawn, temphand, z);	

		cardStatus = 0; //Reset to zero

		/*Checking handcount and cards in hand after playing adventurer*/
		printf("Hand count after adventurer is %d...", G->handCount[p]);
		for(i = 0; i < G->handCount[p]; i++){
			cardNumToName(G->hand[p][i], c);	//Converts card number to string
			if(strcmp(c, "Adventurer") == 0){
			cardStatus = 1;	//Card is present in hand
			}
		}
		
		/*Check if adventurer card is in hand*/
		if(cardStatus == 0){
			printf("\nTest PASSED, card is NOT present in player %d's hand\n\n", p);
		} else {
			printf("\nTest FAILED, card is present in player %d's hand\n\n", p);
			error1++;
		}
	

		/*Check if two treasure cards are drawn and added to hand*/
		printf("Testing for correct number of treasure cards added...\n");
		for(i = 0; i < G->handCount[p]; i++){
			if(G->hand[p][i] == copper || G->hand[p][i] == silver || G->hand[p][i] == gold){
				drawntreasure++;
			}
		}	

		if(drawntreasure == 2){
			printf("Test PASSED, two treasure cards are added to player %d's hand\n\n", p);
		} else {
			printf("Test FAILED, %d (NOT 2) treasure cards are added to player %d's hand\n\n", drawntreasure, p);
			error2++;
		}
			iterCount++;
		}

    if(error1 != 0){
        printf("\nTotal error count for Adventurer card in hand and not discarded: %d of %d tests", error1, iterCount);
    }
    if(error2 != 0){
        printf("\nTotal error count for incorrect drawntreasure in hand: %d of %d tests\n\n", error2, iterCount);
    }
    printf("\n");
	printf("Random tests for Adventurer Card complete!\n");

    return 0;
}

int main(int argc, char *argv[]) {
	srand(time(NULL));
	testAdventurer();
	return 0;
}