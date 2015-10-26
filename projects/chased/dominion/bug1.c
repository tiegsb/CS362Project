/*
 * Title: bug1.c
 * Author: Dustin Chase
 * Email: chased@oregonstate.edu
 * Date: 10/25/2015
 * Description: Explanation of bugs found during unit testing
 *             
 */
 
 unittest1: Testing update coins. No bug found. 
 unittest2: Testing get cost. No bug found. 
 unittest3: Testing buy card. No bug found. 
 unittest4: Testing game over. Bug in this function. The function was not correctly returning the end of the game when there were 3 or more 
			cards with zero left. In the test cases, I noticed it was always missing the high numbered cards in the "zero card" count. This led
			me to examine the loop inside the function which checks the supply of each card. The loop ends too early and does not check the higher 
			numbered cards. 
			
cardtest1.c: Testing smithy card. Bug in this function. My tests showed that the cards in the player's hand were always short. In other words, not enough cards
			 were being drawn. This error occurred every time I ran the test so it showed me that the loop inside the function was not running enough times. 
cardtest2.c: Testing remodel card. No bug found. 
cardtest3.c: Testing council room card. Found that the player buys were not being updated as they should (testing shows "player buy errors"). Examined the code and found that
			 player buys was being incremented by 2 instead of 1. 
			 
cardtest4.c: Testing the adventurer card. Found that the adventurer card is not being discarded when it is played and confirmed that there is no discard action in the adventurer
			 card function. Also registered that the function never picks up any of the gold cards that are in the deck. We can see that in the test results which show 0 
			 gold cards being picked up in the function. 