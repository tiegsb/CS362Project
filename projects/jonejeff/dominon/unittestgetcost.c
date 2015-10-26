
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int main ()  {

    int i, n, r, p, deckCount, discardCount, handCount;

    int card;
    int testPass = 0;
    int testFail = 0;
    int currentPlayer;
    int result;
    int result2;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
		 remodel, smithy, village, baron, great_hall};

    struct gameState G , g;

    printf ("RANDOM TESTS.\n");

    SelectStream(2);
    PutSeed(3);


    printf("Begining getCost Fuction Test\n");

    for (n = 0; n < 200000; n++) { // Testing Loop
	card = n%45;
	result = getCost(card);
	if(result == -1 && card >= 26)  {
	    testPass++;
	}
	else if(result == -1 && card < 26)  {
	    testFail++;
	  }
	else if (result >= 0){
	    switch( card )
	      {
	      case curse:
		result2 = 0;
		break;
	      case estate:
		result2 = 2;
		break;
	      case duchy:
		result2 = 5;
		break;
	      case province:
		result2 = 8;
		break;
	      case copper:
		result2 = 0;
		break;
	      case silver:
		result2 = 3;
		break;
	      case gold:
		result2 = 6;
		break;
	      case adventurer:
		result2 = 6;
		break;
	      case council_room:
		result2 = 5;
		break;
	      case feast:
		result2 = 4;
		break;
	      case gardens:
		result2 = 4;
		break;
	      case mine:
		result2 = 5;
		break;
	      case remodel:
		result2 = 4;
		break;
	      case smithy:
		result2 = 4;
		break;
	      case village:
		result2 = 3;
		break;
	      case baron:
		result2 = 4;
		break;
	      case great_hall:
		result2 = 3;
		break;
	      case minion:
		result2 = 5;
		break;
	      case steward:
		result2 = 3;
		break;
	      case tribute:
		result2 = 5;
		break;
	      case ambassador:
		result2 = 3;
		break;
	      case cutpurse:
		result2 = 4;
		break;
	      case embargo:
		result2 = 2;
		break;
	      case outpost:
		result2 = 5;
		break;
	      case salvager:
		result2 = 4;
		break;
	      case sea_hag:
		result2 = 4;
		break;
	      case treasure_map:
		result2 = 4;
		break;
	      default:
		result2 = -1;
	      }
	      if(result2 == result)
		  testPass++;
	      else {
		  testFail++;
		  printf("card:%d resultf:%d result2%d\n",card,result,result2);
	      }
	}
    }
    printf("Tests Passed:%d Tests Failed %d\n",testPass,testFail);
    printf("Testing End\n");


  return 0;
}
