#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define MAX_TESTS 1000 

int main() {

	int k[10] = {adventurer, gardens, embargo, village, minion, steward, cutpurse, sea_hag, tribute, smithy};

	int players, player, handCount, deckCount, coins, seed, select, trashSelect1, trashSelect2;
	int failed = 0;
	
	struct gameState state;
	
	srand( time( NULL ) );

	printf( "\n\nrandomtestcard - steward" );
	printf( "\n====================\n\n" );

	int i;
	for( i = 0; i < MAX_TESTS; i++ ){
		
		int errors = 0;
		seed = ( ( rand() % 10000 ) + 1 );
		
		printf( "\n\nTest # %d\n", i + 1);
		players = ( rand() % MAX_PLAYERS - 1 ) + 1 ;
		if ( players == 0 ){
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
		state.hand[player][0] = steward;
		
		select = rand() % 3 + 1; 
		
		if( select == 1 ) {
			playCard( 0, 1, -1, -1, &state );
			
			if( handCount != state.handCount[player] + 2 ){
				printf( "Failed to increase number of cards by 2.\n" );
				errors++;
			}
		}
		if( select == 2 ) {
			playCard(0, 2, -1, -1, &state);
			if( coins != state.coins + 2 ){
				printf( "Failed to increase the number of coins by 2.\n" );
				errors++;
			}
		}
		
		if( select == 3 ) {
			trashSelect1 = -1; 
			trashSelect2 = -1;
			while( trashSelect1 == trashSelect2 ){  
				if( state.handCount[player] == 0 ){
					trashSelect1 = rand() % 1; 
				}else{
					trashSelect1 = rand() % state.handCount[player];  
				}
				if( state.handCount[player] == 0 ){
					trashSelect2 = rand() % 1; 
				}else{
					trashSelect2 = rand() % state.handCount[player];  
				}
				
				if( handCount != state.handCount[player] -2 ){
					printf( "Failed to trash 2 cards.\n" );
					errors++;
					break;
				}
			} 
			playCard( 0, 3, trashSelect1, trashSelect2, &state );
		}
		
		if( errors != 0 ){
			failed++;
		}
    }

	printf( "\n%d tests failed of %d\n", failed, MAX_TESTS );
	
    printf( "Testing Complete\n\n" );
	
    return 0;

}