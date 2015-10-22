/* Unit tests for the scoreFor()
	Testing for...
      - Score from hand is calculated correctly
	  - Score from discard pile is calculated correctly
	  - Score from deck pile is calculated correctly
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include "interface.h"

/*scoreFor() unit tests*/
void testscoreFor()
{
	int seed = 1000; /*Used for initializeGame parameter for setting up random # generator*/
    int numPlayer = 2; /*number of players in game. Maximum # of players is 4*/
    int p = 0; /*holds the value of the player, example player 0, player 1.*/
	int handCount = 5; /*Number of cards player starts with*/
	
	/*Kingdom cards used in this game*/
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
			   
    struct gameState G; /*start a new game*/
	char name[20]; /*Holds card name when converting card number to string*/
	int score = 0; /*Holds return value from scoreFor()*/
	
	/*****************Cards for game where only Players hand contributes to score***********/
	/*create a custom hand to give to player */
    int custom_hand[handCount];
	custom_hand[0] = curse;
    custom_hand[1] = silver;
	custom_hand[2] = village;
	custom_hand[3] = gold;
	custom_hand[4] = duchy;
	
	/*create a custom discard pile to give to player */
	int custom_discard[handCount];
	custom_discard[0] = village;
    custom_discard[1] = smithy;
	custom_discard[2] = silver;
	custom_discard[3] = copper;
	custom_discard[4] = gold;
	
	/*create a custom deck pile to give to player */
    int custom_deck[handCount];
	custom_deck[0] = smithy;
    custom_deck[1] = feast;
	custom_deck[2] = village;
	custom_deck[3] = gold;
	custom_deck[4] = copper;
	
	/**************Cards for game where only discard pile contributes to score*****************/
	/*create a custom hand to give to player */
    int custom_hand2[handCount];
	custom_hand2[0] = smithy;
    custom_hand2[1] = silver;
	custom_hand2[2] = village;
	custom_hand2[3] = gold;
	custom_hand2[4] = mine;
	
	/*create a custom discard pile to give to player */
	int custom_discard2[handCount];
	custom_discard2[0] = village;
    custom_discard2[1] = smithy;
	custom_discard2[2] = estate;
	custom_discard2[3] = duchy;
	custom_discard2[4] = curse;
	
	/*use custom_deck*/
	
	/*******************Cards for game where only deck pile contributes to score***********/
	/*use custom_hand2*/
	/*use custom_discard*/
	
	/*create a custom deck pile to give to player */
    int custom_deck2[handCount];
	custom_deck2[0] = curse;
    custom_deck2[1] = curse;
	custom_deck2[2] = village;
	custom_deck2[3] = great_hall;
	custom_deck2[4] = province;
	
	
    printf ("\nTESTING scoreFor():\n");
	
	/*Get score from player's hand*/
	initializeGame(numPlayer, k, seed, &G); /*initialize a new game*/
	G.handCount[p] = handCount;             /*set the number of cards in hand*/
	memcpy(G.hand[p], custom_hand, sizeof(int) * handCount); /*Populate hand with cards*/
	memcpy(G.discard[p], custom_discard, sizeof(int) * handCount); /*Populate hand with cards*/
	memcpy(G.deck[p], custom_deck, sizeof(int) * handCount); /*Populate hand with cards*/

	printf ("\nPlayer Hand\n");
	int i;
	for(i = 0; i < G.handCount[p]; i++)
	{
		cardNumToName(G.hand[p][i], name); /*Convert card number to cards name*/
		printf("%s%s", name, ", ");
	}

	score = scoreFor(p, &G);
	
	printf("\nScore for Player's Hand is %d\n", score);
	
	if(score == 2)
	{
		printf ("PASS - Score correctly calculated for cards in Player's Hand\n");
	}
	else
	{
		printf ("FAIL - Score NOT correctly calculated for cards in Player's Hand\n");
	}
	
	/*Get score from player's discard pile*/
	memset(&G, 23, sizeof(struct gameState)); /*clear the game state*/
	initializeGame(numPlayer, k, seed, &G); /*initialize a new game*/
	G.handCount[p] = handCount;             /*set the number of cards in hand*/
	memcpy(G.hand[p], custom_hand2, sizeof(int) * handCount); /*Populate hand with cards*/
	memcpy(G.discard[p], custom_discard2, sizeof(int) * handCount); /*Populate hand with cards*/
	memcpy(G.deck[p], custom_deck, sizeof(int) * handCount); /*Populate hand with cards*/
	
	printf ("\nDiscard Pile\n");
	for(i = 0; i < G.handCount[p]; i++)
	{
		cardNumToName(G.discard[p][i], name); /*Convert card number to cards name*/
		printf("%s%s", name, ", ");
	}
	
	score = scoreFor(p, &G);
	
	printf("\nScore for Player's Discard pile is %d\n", score);
	
	if(score == 3)
	{
		printf ("PASS - Score correctly calculated for cards in Player's discard pile\n");
	}
	else
	{
		printf ("FAIL - Score NOT correctly calculated for cards in Player's discard pile\n");
	}
	
	/*Get score from player's deck pile*/
	memset(&G, 23, sizeof(struct gameState)); /*clear the game state*/
	initializeGame(numPlayer, k, seed, &G); /*initialize a new game*/
	G.handCount[p] = handCount;             /*set the number of cards in hand*/
	memcpy(G.hand[p], custom_hand2, sizeof(int) * handCount); /*Populate hand with cards*/
	memcpy(G.discard[p], custom_discard, sizeof(int) * handCount); /*Populate hand with cards*/
	memcpy(G.deck[p], custom_deck2, sizeof(int) * handCount); /*Populate hand with cards*/
	
	printf ("\nDeck Pile\n");
	for(i = 0; i < G.deckCount[p]; i++)
	{
		cardNumToName(G.deck[p][i], name); /*Convert card number to cards name*/
		printf("%s%s", name, ", ");
	}
	
	score = scoreFor(p, &G);
	
	printf("\nScore Player's Deck pile is %d\n", score);
	
	if(score == 5)
	{
		printf ("PASS - Score correctly calculated for cards in Player's deck pile\n");
	}
	else
	{
		printf ("FAIL - Score NOT correctly calculated for cards in Player's deck pile\n");
	}
}

int main() {
   testscoreFor();
    return 0;
}
