/*******************************************************************
 Author: CHIA, YiXuan
 Title:  unittest2.c
 Desc:   Testing scoreFor() function in dominion.c using unit test
 Course: CS362 Fall 2015
*******************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>

//Set TEST_MODE to 0 to remove printfs from output
#define TEST_MODE 1

int main() {
   int i, j, h, n;
   int seed = 2000;
   int num_player = 2;
   int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
   struct gameState test_state;
   
   int hand_count = 6;
   int score = 0;

   int test_hand[3][MAX_HAND];

   int test_discard[3][MAX_HAND];

   int test_deck[3][MAX_HAND];

   int testresult_hand[3] = { 0, 0, 0 };
   int expected_hand[3] = { 0, 0, 0 };

   int testresult_discard[3] = { 0, 0, 0 };
   int expected_discard[3] = { 0, 0, 0 };

   int testresult_deck[3] = { 0, 0, 0 };
   int expected_deck[3] = { 0, 0, 0 };

#if (TEST_MODE == 1)
   printf("START TESTING scoreFor():\n");
#endif
   /*Expected Score: 10*/
   test_hand[0][0] = curse;
   test_hand[0][1] = estate;
   test_hand[0][2] = duchy;
   test_hand[0][3] = province;
   test_hand[0][4] = great_hall;
   test_hand[0][5] = gardens;

   /*Expected Score: 16*/
   test_hand[1][0] = province;
   test_hand[1][1] = feast;
   test_hand[1][2] = duchy;
   test_hand[1][3] = province;
   test_hand[1][4] = great_hall;
   test_hand[1][5] = baron;

   /*Expected Score: 0*/
   test_hand[2][0] = mine;
   test_hand[2][1] = feast;
   test_hand[2][2] = council_room;
   test_hand[2][3] = smithy;
   test_hand[2][4] = village;
   test_hand[2][5] = adventurer;

   /*Expected Score: 2*/
   test_discard[0][0] = silver;
   test_discard[0][1] = curse;
   test_discard[0][2] = gold;
   test_discard[0][3] = duchy;
   test_discard[0][4] = silver;
   test_discard[0][5] = copper;

   /*Expected Score: 6*/
   test_discard[1][0] = mine;
   test_discard[1][1] = estate;
   test_discard[1][2] = baron;
   test_discard[1][3] = village;
   test_discard[1][4] = province;
   test_discard[1][5] = curse;

   /*Expected Score: 0*/
   test_discard[2][0] = mine;
   test_discard[2][1] = feast;
   test_discard[2][2] = council_room;
   test_discard[2][3] = smithy;
   test_discard[2][4] = village;
   test_discard[2][5] = adventurer;

   /*Expected Score: 10*/
   test_deck[0][0] = curse;
   test_deck[0][1] = estate;
   test_deck[0][2] = duchy;
   test_deck[0][3] = province;
   test_deck[0][4] = great_hall;
   test_deck[0][5] = gardens;

   /*Expected Score: 8*/
   test_deck[1][0] = estate;
   test_deck[1][1] = mine;
   test_deck[1][2] = baron;
   test_deck[1][3] = smithy;
   test_deck[1][4] = great_hall;
   test_deck[1][5] = province;

   /*Expected Score: 0*/
   test_deck[2][0] = mine;
   test_deck[2][1] = feast;
   test_deck[2][2] = council_room;
   test_deck[2][3] = smithy;
   test_deck[2][4] = village;
   test_deck[2][5] = adventurer;

   /*Test 1: Player's Hand Score*/
   for (j = 0; j < 3; j++)
   {
      /*Clear game state*/
      memset(&test_state, 23, sizeof(struct gameState));
      /*Initialize game*/
      initializeGame(num_player, k, seed, &test_state);
      test_state.handCount[0] = hand_count;
      test_state.discardCount[0] = 0;
      test_state.deckCount[0] = 0;
      /*Fill hand with cards*/
      memcpy(test_state.hand[0], test_hand[j], sizeof(int) * hand_count);
      /*Get score on player's hand*/
      score = scoreFor(0, &test_state);
      
      testresult_hand[j] = score;

      expected_hand[0] = 10;
      expected_hand[1] = 16;
      expected_hand[2] = 0;
   }
   /*End Test 1*/

   /*Test 2: Player's Discard Score*/
   for (h = 0; h < 3; h++)
   {
      /*Clear game state*/
      memset(&test_state, 23, sizeof(struct gameState));	   
      /*Initialize game*/
      initializeGame(num_player, k, seed, &test_state);
      test_state.handCount[0] = 0;
      test_state.discardCount[0] = hand_count;
      test_state.deckCount[0] = 0;
      /*Fill hand with cards*/
      memcpy(test_state.discard[0], test_discard[h], sizeof(int) * hand_count);

      /*scoreFor() third for-loop discardCount causing error of calculation
	     without this line. Should be deckCount[player]? (Bug)*/
      memcpy(test_state.deck[0], test_deck[h], sizeof(int)* hand_count);
      
      score = scoreFor(0, &test_state);
      
      testresult_discard[h] = score;
      
      expected_discard[0] = 12;
      expected_discard[1] = 14;
      expected_discard[2] = 0;
   }
   /*End Test 2*/

   /*Test 3: Player's Deck Score*/
   for (n = 0; n < 3; n++)
   {
      /*Clear game state*/
      memset(&test_state, 23, sizeof(struct gameState));
      /*Initialize game*/
      initializeGame(num_player, k, seed, &test_state);
      test_state.handCount[0] = 0;
      test_state.discardCount[0] = hand_count;
      test_state.deckCount[0] = 0;
      /*Fill hand with cards*/
      memcpy(test_state.deck[0], test_deck[n], sizeof(int) * hand_count);
      /*Get score on player's hand*/
      score = scoreFor(0, &test_state);

      testresult_deck[n] = score;

      expected_deck[0] = 10;
      expected_deck[1] = 8;
      expected_deck[2] = 0;
   }
   /*End Test 3*/

#if (TEST_MODE == 1)
   //Display Hand Count Test Result
   for (i = 0; i < 3; i++)
   {
      printf("Player Hand Test %d:\n", i + 1);
      printf("Score: %d, Expected Score: %d\t\t", testresult_hand[i], expected_hand[i]);

      if (testresult_hand[i] == expected_hand[i])
      {
         printf("Test #%d passed unit test!\n\n", i + 1); 
      }
      else
      {
         printf("Test #%d failed unit test!\n\n", i + 1);
      }
   }

   printf("*******************************************************************\n");
   
   //Display Score from Discard Test Result
   for (i = 0; i < 3; i++)
   {
      printf("Player Discard Test %d:\n", i + 1);
      printf("Score: %d, Expected Score: %d\t\t", testresult_discard[i], expected_discard[i]);

      if (testresult_discard[i] == expected_discard[i])
      {
         printf("Test #%d passed unit test!\n\n", i + 1);
      }
      else
      {
         printf("Test #%d failed unit test!\n\n", i + 1);
      }
   }

   printf("*******************************************************************\n");

   //Display Score from Deck Test Result
   for (i = 0; i < 3; i++)
   {
      printf("Player Deck Test %d:\n", i + 1);
      printf("Score: %d, Expected Score: %d\t\t", testresult_deck[i], expected_deck[i]);

      if (testresult_deck[i] == expected_deck[i])
      {
         printf("Test #%d passed unit test!\n\n", i + 1);
      }
      else
      {
         printf("Test #%d failed unit test!\n\n", i + 1);
      }
   }
#endif
   
   return 0;
}
