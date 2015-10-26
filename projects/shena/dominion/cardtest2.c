#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

//=====================
//TEST ADVENTURER CARD
//=====================


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include "interface.h"

/*Adventurer card unit tests*/
void testAdventurerCard()
{
	
	/*Kingdom cards used in this game*/
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
			   
    struct gameState s; /*start a new game*/
	
	/*create a custom hand to give to player */
    int playerHand[5];
	
	playerHand[0] = smithy;
    playerHand[1] = village;
	playerHand[2] = gardens;
	playerHand[3] = adventurer;
	playerHand[4] = mine;
    
    char name[20];
	int checker = 0;
	
	int z = 0;
	int cardDrawn = 0;
	int drawnTreasure = 0; 
	int temphand[MAX_HAND];

    printf ("\nTESTING adventurer_card():\n");
	
	initializeGame(2, k, 21, &s);
	s.handCount[1] = 5;
	memcpy(s.hand[1], playerHand, sizeof(int) * handCount); /*Populate hand with cards*/
	s.deckCount[1] = 0;
	int i;
	for(i = 0; i < s.handCount[p]; i++)
	{
		cardNumToName(s.hand[p][i], name);
		printf("%s%s", name, ", ");
		if(strcmp(name, "Adventurer") == 0)
		{
			checker = 1;
		}
	}
	
	if (checker == 1)
	{
		printf ("\nAdventurer card in hand... Success!\n");
	}
	else
	{
		printf ("\nAdventurer card in hand... Fail.\n");
	}
	
	checker = 0;
	
	adventurer_card(p, cardDrawn, drawnTreasure, z, temphand, &s);
	
	if(s.deckCount[p] == 0)
	{
		printf ("Deck properly maintained?... Fail.\n", s.deckCount[p]);
	}
	else
	{
		printf ("Deck properly maintained?... Success!\n", s.deckCount[p]);
	}
	
	if(s.handCount[p] == 6 || s.handCount[p] == 7)
	{
		printf ("Correct number of cards received?... Success!", p);
	}
	else
	{
		printf ("Correct number of cards received?... Fail.", p);
	}
	
	
	for(i = 0; i < s.handCount[p]; i++)
	{
		cardNumToName(s.hand[p][i], name);
		printf("%s%s", name, ", ");
		if(strcmp(name, "Adventurer") == 0)
		{
			checker = 0;
		}
		if(strcmp(name, "Copper") == 0 || strcmp(name, "Silver") == 0 || strcmp(name, "Gold") == 0)
		{
			drawnTreasure++;
		}
	}

	if (checker == 0)
	{
		printf ("Adventurer Card discarded?... Success!\n");
	}
	else
	{
		printf ("Adventurer Card discarded?... Fail!\n");
	}
	
	if (drawnTreasure == 2)
	{
		printf ("Two treasure cards added to hand?... Success! \n");
	}
	else
	{
		printf ("Two treasure cards added to hand?... Fail.\n");
	}
	return 0;
}