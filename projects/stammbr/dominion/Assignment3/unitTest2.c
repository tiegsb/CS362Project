/*****************
 * Author:  Brian Stamm
 * Title:  unitTest2.c
 * Assignment:  3
 * Date:  10.25.15
 * Notes:  Test updateCoins().
 * ****************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void test(){
  struct gameState g;
  struct gameState *game = &g;

  int i, test, total, player = 0;
  int bonus = 0;

  //Initial test, checking initializing all copper, silver, and gold.
  //Start with Copper.
  game->handCount[player] = 5;
  total = 0;

  for(i = 0; i < 5; i++){
  	game->hand[player][i] = copper;
  	total++;
  } 
  test = 1;

  if(updateCoins(player, game, bonus) == 0){
  	if(game->coins == total){
  		printf("%d- updateCoins():  PASS when all copper, no bonus\n", test);
  	}
  	else{
  		printf("%d- updateCoins():  FAIL when all copper, no bonus\n", test);
  	}
  }
  else{
  	printf("updateCoins():  FAIL test 1.\n");
  }

  //Checking only silver, player incremented, and cards increased.
  test++;
  total = 0;
  game->coins = 0;
  game->handCount[player] == 50;

  for(i = 0; i < 50; i++){
  	game->hand[player][i] = silver;
  	total += 2;
  } 

  if(updateCoins(player, game, bonus) == 0){
  	if(game->coins == total){
  		printf("%d- updateCoins():  PASS when all silver, no bonus\n", test);
  	}
  	else{
  		printf("%d- updateCoins():  FAIL when all silver, no bonus\n", test);
      printf("Total:  %d\tActual Coins:  %d\n", total, game->coins);
  	}
  }
  else{
  	printf("updateCoins():  FAIL test 2.\n");
  }  

  //Checking only gold and cards increased to max.
  test++;
  total = 0;
  game->handCount[player] == 500;

  for(i = 0; i < 500; i++){
  	game->hand[player][i] = gold;
  	total += 3;
  } 

  if(updateCoins(player, game, bonus) == 0){
  	if(game->coins == total){
  		printf("%d- updateCoins():  PASS when all gold, no bonus\n", test);
  	}
  	else{
  		printf("%d- updateCoins():  FAIL when all gold, no bonus\n", test);
      printf("Total:  %d\tActual Coins:  %d\n", total, game->coins);
  	}
  }
  else{
  	printf("updateCoins():  FAIL test 3.\n");
  } 
  
  //New test - mix of gold, silver and copper, no bonus
  test++;
  total = 0;
  for(i = 0; i < 500; i++){
  	if(i < 166){
  		game->hand[player][i] = copper;
  		total++;
  	}
  	else if(i < 333){
  		game->hand[player][i] = silver;
  		total += 2;
  	}
  	else{
  		game->hand[player][i] = gold;
  		total += 3;
  	}
  }

  if(updateCoins(player, game, bonus) == 0){
  	if(game->coins == total){
  		printf("%d- updateCoins():  PASS mix, no bonus\n", test);
  	}
  	else{
  		printf("%d- updateCoins():  FAIL mix, no bonus\n", test);
      printf("Total:  %d\tActual Coins:  %d\n", total, game->coins);
  	}
  }
  else{
  	printf("updateCoins():  FAIL test 4.\n");
  } 

//Checking bonus with initial amount;
  test++;
  for(i = 0; i < 5; i++){
    game->hand[player][i] = copper;
    total++;
  }
  game->handCount[player] = 5; 
  bonus = 5;
  total = 5;
  if(updateCoins(player, game, bonus) == 0){
  	if(game->coins == (total+bonus)){
  		printf("%d- updateCoins():  PASS copper, small bonus\n", test);
  	}
  	else{
  		printf("%d- updateCoins():  FAIL mix, small bonus\n", test);
      printf("Total:  %d\tActual Coins:  %d\n", total, game->coins);
  	}
  }
  else{
  	printf("updateCoins():  FAIL test 5.\n");
  } 

//Checking bonus with negative amount;
  test++;
  bonus = -5;
  total = 5;
  if(updateCoins(player, game, bonus) == 0){
  	if(game->coins == (total+bonus)){
  		printf("%d- updateCoins():  PASS copper, negative bonus\n", test);
  	}
  	else{
  		printf("%d- updateCoins():  FAIL mix, negative bonus\n", test);
      printf("Total:  %d\tActual Coins:  %d\n", total, game->coins);
  	}
  }
  else{
  	printf("updateCoins():  FAIL test 6.\n");
  } 

//Checking bonus with large amount;
  test++;
  bonus = 2000000000;
  total = 5;
  if(updateCoins(player, game, bonus) == 0){
  	if(game->coins == (total+bonus)){
  		printf("%d- updateCoins():  PASS copper, large bonus\n", test);
  	}
  	else{
  		printf("%d- updateCoins():  FAIL mix, large bonus\n", test);
      printf("Total:  %d\tActual Coins:  %d\n", total, game->coins);
  	}
  }
  else{
  	printf("updateCoins():  FAIL test 7.\n");
  } 
//Checking bonus with boundary of positive amount;
  test++;
  bonus = 4294967291;
  total = 5;
  if(updateCoins(player, game, bonus) == 0){
  	if(game->coins == 4294967296){
  		printf("%d- updateCoins():  PASS copper, extreme large bonus\n", test);
  	}
  	else{
  		printf("%d- updateCoins():  FAIL mix, extreme large bonus\n", test);
  		printf("Should have:  4294967296\tWas:%d\n", game->coins);
  	}
  }
  else{
  	printf("updateCoins():  FAIL test 8.\n");
  } 

}

int main(int argc, char **argv){

  printf("This is the tests for the updateCoins() function.\n");

	test();

	return 0;
}

/*  Below is the function being tested.

int updateCoins(int player, struct gameState *state, int bonus)
{
  int i;
	
  //reset coin count
  state->coins = 0;

  //add coins for each Treasure card in player's hand
  for (i = 0; i < state->handCount[player]; i++)
    {
      if (state->hand[player][i] == copper)
        {
          state->coins += 1;
        }
      else if (state->hand[player][i] == silver)
        {
          state->coins += 2;
        }
      else if (state->hand[player][i] == gold)
      {
        state->coins += 3;
      }	
    }	

  //add bonus
  state->coins += bonus;

  return 0;
}
*/
