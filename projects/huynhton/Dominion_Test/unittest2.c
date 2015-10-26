/* -----------------------------------------------------------------------
 * Author: Tony Huynh           CS 362          unittest2.c
 *
 * This test will test the discardCard function in dominion.c  It will be similar
 * to unittest1.c, or the gainCard function test.  
 * I am going to take a count of the current player's current hand count, then I will
 * make the player discard a card.  When I check their hand again, they should
 * have one less card than when they originally 
 *
 * Demonstration of how to write unit tests for dominion-base
 * Include the following lines in your makefile:
 *
 * testUpdateCoins: testUpdateCoins.c dominion.o rngs.o
 *      gcc -o testUpdateCoins -g  testUpdateCoins.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */



