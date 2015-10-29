#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>


struct gameState makeRandomGameState(){

	struct gameState G;
	time_t t;
	unsigned r;
	int i, j, players, pass;
	int k[10];
	srand((unsigned) time(&t));
	players = rand() % 3;
	players += 2;
	r = rand();
	for (i = 0; i < 10; i++){
		k[i] = rand() % 20;
		pass = -1;
		while (pass < 0){
			pass = 1;
			for (j = 0; j < i; j++){
				if (k[i] == k[j]){
					k[i] = rand() % 20;
					pass = -1;
				}
			}
		}
	for (i = 0; i < 10; i++){
		switch (k[i]){
			case 0:
				k[i] = adventurer;
				break;			
			case 1:
				k[i] = council_room;
				break;			
			case 2:
				k[i] = feast;
				break;			
			case 3:
				k[i] = gardens;
				break;			
			case 4:
				k[i] = mine;
				break;			
			case 5:
				k[i] = remodel;
				break;			
			case 6:
				k[i] = smithy;
				break;			
			case 7:
				k[i] = village;
				break;			
			case 8:
				k[i] = baron;
				break;			
			case 9:
				k[i] = great_hall;
				break;			
			case 10:
				k[i] = minion;
				break;			
			case 11:
				k[i] = steward;
				break;			
			case 12:
				k[i] = tribute;
				break;			
			case 13:
				k[i] = ambassador;
				break;			
			case 14:
				k[i] = cutpurse;
				break;			
			case 15:
				k[i] = embargo;
				break;			
			case 16:
				k[i] = outpost;
				break;			
			case 17:
				k[i] = salvager;
				break;			
			case 18:
				k[i] = sea_hag;
				break;			
			case 19:
				k[i] = treasure_map;
				break;
		}
	}
	initializeGame(2, k, r, &G);
	return G;
}