//Woo Choi
//unitest1.c
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

/*
getCost() function test
int getCost(int cardNumber);
*/

int main(){
/*
From dominion_helpers.h
enum: 
curse=0, estate=1, duchy=2, province=3, copper=4, silver=5, 
gold=6, adventurer=7, council_room=8, feast=9, 
gardens=10, mine=11, remodel=12, smithy=13, village=14,
baron=15, great_hall=16, minion=17, steward=18, tribute=19,
ambassador=20, cutpurse= 21, embargo =22, outpost =23, 
salvager=24, sea_hag=25, treasure_map= 26;
*/
	
	int i;
	int x;
	printf("******************\n");
	printf("unittest1.c\n");
	printf("getCost() Test:\n");
	
	// iterate thru numbers to test for correct values
	for (i = 0; i < 27; i++)
	{
		x = getCost(i);
		if ( i == 0){
			if (x != 0)
				printf("assert failed at card number %d!",i);
		}
		if ( i == 1){
			if ( x != 2)
				printf("assert failed at card number %d!",i);
		}
		if ( i == 2){
			if ( x != 5)
				printf("assert failed at card number %d!",i);
		}
		if ( i == 3){
			if ( x != 8)
				printf("assert failed at card number %d!",i);
		}
		if ( i == 4){
			if ( x != 0)
				printf("assert failed at card number %d!",i);
		}
		if ( i == 5){
			if ( x != 3)
				printf("assert failed at card number %d!",i);
		}
		if ( i == 6){
			if ( x != 6)
				printf("assert failed at card number %d!",i);
		}
		if ( i == 7){
			if ( x != 6)
				printf("assert failed at card number %d!",i);
		}
		if ( i == 8){
			if ( x != 5)
				printf("assert failed at card number %d!",i);
		}
		if ( i == 9){
			if ( x != 4)
				printf("assert failed at card number %d!",i);
		}
		if ( i == 10){
			if ( x != 4)
				printf("assert failed at card number %d!",i);
		}
		if ( i == 11){
			if ( x != 5)
				printf("assert failed at card number %d!",i);
		}
		if ( i == 12){
			if ( x != 4)
				printf("assert failed at card number %d!",i);
		}
		if ( i == 13){
			if ( x != 4)
				printf("assert failed at card number %d!",i);
		}
		if ( i == 14){
			if ( x != 3)
				printf("assert failed at card number %d!",i);
		}
		if ( i == 15){
			if ( x != 4)
				printf("assert failed at card number %d!",i);
		}
		if ( i == 16){
			if ( x != 3)
				printf("assert failed at card number %d!",i);
		}
		if ( i == 17){
			if ( x != 5)
				printf("assert failed at card number %d!",i);
		}
		if ( i == 18){
			if ( x != 3)
				printf("assert failed at card number %d!",i);
		}
		if ( i == 19){
			if ( x != 5)
				printf("assert failed at card number %d!",i);
		}
		if ( i == 20){
			if ( x != 3)
				printf("assert failed at card number %d!",i);
		}
		if ( i == 21){
			if ( x != 4)
				printf("assert failed at card number %d!",i);
		}
		if ( i == 22){
			if ( x != 2)
				printf("assert failed at card number %d!",i);
		}
		if ( i == 23){
			if ( x != 5)
				printf("assert failed at card number %d!",i);
		}
		if ( i == 24){
			if ( x != 4)
				printf("assert failed at card number %d!",i);
		}
		if ( i == 25){
			if ( x != 4)
				printf("assert failed at card number %d!",i);
		}
		if ( i == 26){
			if ( x != 4)
				printf("assert failed at card number %d!",i);
		}
	}
	printf("Test for correct return value complete\n");
	printf("Test for incorrect inputs: \n");
	i = 27;
	x = getCost(i); 
	if ( x != -1)
		printf("Range over highest limit is not working properly\n");
	i = -1;
	x = getCost(i);
	if ( x != -1)
		printf("Range under lowest limit is not working properly\n");
	printf("Test for incorrect return value complete\n");
	printf("getCost() test is now finished \n\n");
	
	return 0;
}