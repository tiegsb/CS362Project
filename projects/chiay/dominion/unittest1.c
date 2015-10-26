/*******************************************************************
 Author: CHIA, YiXuan
 Title:  unittest1.c
 Desc:   Testing updateCoins() function in dominion.c using unit test
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
   int bonus = 0;
   
   int hand_count = 0;
   int max_hand_count = 9;

   int test_hand1[MAX_HAND];
   int test_hand2[MAX_HAND];
   int test_hand3[MAX_HAND];
   int test_hand4[MAX_HAND];
   
   //Assign test_hand with treasure cards
   for (j = 0; j < 3; j++)
   {
      test_hand1[j] = copper;
      test_hand2[j] = copper;
      test_hand3[j] = copper;
   }
 
   for (h = 3; h < 6; h++)
   {
      test_hand1[h] = silver;
      test_hand2[h] = silver;
      test_hand3[h] = silver;
   }

   for (n = 6; n < 9; n++)
   {
      test_hand1[n] = gold;
      test_hand2[n] = gold;
      test_hand3[n] = gold;
   }
   

   test_hand4[0] = silver;
   test_hand4[1] = gold;
   test_hand4[2] = gold;
   test_hand4[3] = gold;
   test_hand4[4] = copper;
   test_hand4[5] = copper;
   test_hand4[6] = silver;
   test_hand4[7] = silver;
   test_hand4[8] = silver;
   
   int testresult[4] = {0, 0, 0, 0};
   int expected[4] = {0, 0, 0, 0};

#if (TEST_MODE == 1)
   printf("START TESTING updateCoins():\n");
#endif

   /* Test 1*/
   /*Clear game state*/
   memset(&test_state, 23, sizeof(struct gameState));

   /*Initialize game*/ 
   initializeGame(num_player, k, seed, &test_state);

   /*Fill hand with cards*/
   memcpy(test_state.hand[0], test_hand1, sizeof(int) * max_hand_count);

   test_state.handCount[0] = max_hand_count;

   /*Calculate values of treasure cards*/
   updateCoins(0, &test_state, bonus);

   testresult[0] = test_state.coins;

   expected[0] = 18;
   /*End Test 1*/
   
   /*Test 2*/
   bonus = 3;

   hand_count = 12;

   /*Clear game state*/
   memset(&test_state, 23, sizeof(struct gameState));

   /*Initialize game*/ 
   initializeGame(num_player, k, seed, &test_state);

   /*Fill hand with cards*/
   memcpy(test_state.hand[0], test_hand2, sizeof(int) * hand_count);

   test_state.handCount[0] = hand_count;

   /*Calculate values of treasure cards*/
   updateCoins(0, &test_state, bonus);

   testresult[1] = test_state.coins;
   
   expected[1] = 21;
   /*End Test 2*/

   
   /*Test 3*/
   bonus = 2;

   hand_count = 10;

   /*Clear game state*/
   memset(&test_state, 23, sizeof(struct gameState));

   /*Initialize game*/ 
   initializeGame(num_player, k, seed, &test_state);

   /*Fill hand with cards*/
   memcpy(test_state.hand[0], test_hand3, sizeof(int) * hand_count);

   test_state.handCount[0] = hand_count;

   /*Calculate values of treasure cards*/
   updateCoins(0, &test_state, bonus);

   testresult[2] = test_state.coins;
   
   expected[2] = 20;
   /*End Test 3*/

   /*Test 4*/
   bonus = 6;

   hand_count = 15;

   /*Clear game state*/
   memset(&test_state, 23, sizeof(struct gameState));

   /*Initialize game*/ 
   initializeGame(num_player, k, seed, &test_state);

   /*Fill hand with cards*/
   memcpy(test_state.hand[0], test_hand4, sizeof(int) * hand_count);

   test_state.handCount[0] = hand_count;

   /*Calculate values of treasure cards*/
   updateCoins(0, &test_state, bonus);

   testresult[3] = test_state.coins;

   expected[3] = 25;
   /*End Test 4*/

#if (TEST_MODE == 1)
   for (i = 0; i < 4; i++)
   {
      printf ("TEST #%d:\n", i + 1);

      printf("Coins: %d \t Expected: %d\t\t", testresult[i], expected[i]);
   
      if (expected[i] == testresult[i])
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
