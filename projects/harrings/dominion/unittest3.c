

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include "interface.h"
#include <time.h>

//tests update coins function using a random number generator, to create
//randon hands of cards with random bonus and confirms that correct value
//is generated



void updatecoin_test()
{
	//basic game cards
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	int rando = 512; //seed for random numbers I have heard base 2 is best
    int sum;
    int pid = 0; //player id, 2 player game so ids are 0 and 1	   
	int playercount = 2; 
	int handCount = 5;
	int temp;
    int i=0;
	int j=0;
	int good=0;
	int bad=0;
	int total=0;
	int test_h[handCount];
	int bonus=0;
	
	struct gameState G;  //sets up new game
	
    printf ("\nUnit test of update coins\n");
	for (j=0; j<=100; j++) //since its a random test it loops through 100 times
	{
		 for (pid = 0; pid < playercount; pid++) //cycles through number of cards and players and bonus
		{
			
				for (bonus = 0; bonus <= 10; bonus++)
				{
					 
					sum=bonus;
					initializeGame(playercount, k, rando, &G); //sets up new game
					G.handCount[pid] = handCount; 
					for (i=0; i<handCount;i++)
					{
						temp=rand()%3;
						if (temp==0)
						{
							test_h[i]= copper;
							sum=sum+1;
						}
						else if (temp==1)
						{
							test_h[i]= silver;
							sum=sum+2;
						}
						else
						{
							test_h[i]=gold;
							sum=sum+3;
						}
					}	
					memcpy(G.hand[pid], test_h, sizeof(int) * handCount); //creates hand with cards above
					updateCoins(pid, &G, bonus);
					if (G.coins==sum) //checks to make sure expected coins matches actual coins
					{
						if (j==0) //only prints sucess on first run through to avoid clutter
						{
							printf ("Passed test expected %d coins and got %d coins\n", sum, G.coins);
						}
						good++;
						total++;
					}
					else
					{
						
						printf ( "Failed test expected %d coins and got %d coins \n", sum, G.coins);
						printf ( "failed test details player number %d bonus of %d and handcount of %d \n", pid, bonus, handCount );
						bad++;
						total++;
					}
				}
			
		}
	}
	printf ( "End of test %d tests were run with %d successes and %d failures \n", total, good, bad);
	
}

int main() {
	int rando=512;
	 srand(rando);
    updatecoin_test();
    return 0;
}
