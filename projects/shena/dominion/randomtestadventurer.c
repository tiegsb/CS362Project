#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define MAX_TESTS 1000

int main(){

	int k[10] = {adventurer, gardens, embargo, village, minion, steward, cutpurse, sea_hag, tribute, smithy};

	int players, player, copperDeck, copperHand, tempCopper, handCount, deckCount, coins, seed;

	int failed = 0;
	struct gameState state;
	
	srand( time(NULL) );

	printf( "\n\nrandomtestadventurer" );
	printf( "\n====================\n\n" );
	
	int i;
	for( i = 0; i < MAX_TESTS; i++ ) {
		
		int errors = 0;
		seed = ( ( rand() % 10000 ) + 1 );
		
		printf( "\n\nTest # %d\n", i + 1 );
		players = ( rand() % MAX_PLAYERS - 1 ) + 1;
		if( players == 0 ){
			player = rand() % 1;
        }else{
			player = rand() % players;
        }
		
		initializeGame( players, k, seed, &state );
		state.deckCount[player] = rand() % MAX_DECK;
		if( state.deckCount[player] == 0 ){    
			state.discardCount[player] = rand() % 1;
		}else{
			state.discardCount[player] = rand() % state.deckCount[player];
		}
		
		if( state.deckCount[player] < MAX_HAND ){
			state.handCount[player] = state.deckCount[player];
		}else{ 
			state.handCount[player] = rand() % MAX_HAND;
		}

		handCount = state.handCount[player];
		deckCount = state.deckCount[player];
		
		coins = state.coins;
		printf( "handCount: %d\n", state.handCount[player] );
		printf( "deckCount: %d\n", state.deckCount[player] );
		state.hand[player][0] = adventurer;
		copperDeck = fullDeckCount( player, copper, &state );
		
		int j;
		copperHand = 0; 
		for( j = 0; j < handCount; j++ ){
            if( handCard( j, &state ) == copper ){
				copperHand ++;
            }
		} 
		tempCopper = copperDeck - copperHand; 
		printf( "copperDeck is %d, copperHand is %d, tempCopper is %d\n", copperDeck, copperHand, tempCopper );
		playCard( 0, 1, -1, -1, &state );
		if( tempCopper >= 2 ){
			if( handCount != state.handCount[player] + 2 ){
				printf( "Adventurer failed to increase number of cards by 2\n" );
				errors++;
            }
		}
		
		if( tempCopper == 1 ) {
			if( handCount != state.handCount[player] + 1 ){
				printf( "Adventurer failed to increase cards by 1.\n" );
				errors++;
			}
		}
		
		if( tempCopper == 0 ){
			if( handCount != state.handCount[player] ){
				printf( "Adventurer added incorrectly added extra cards.\n" );
				errors++;
			}
		}
		
		if( errors != 0 ){
			failed++;
		}
	}

	printf( "\n%d tests failed of %d\n", failed, MAX_TESTS );

	printf( "Testing Complete\n\n" );

	return 0;
	
}