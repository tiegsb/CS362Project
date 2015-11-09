/*
Name: Rhett Guyer
Class: CS 362
Date: 11/8/15

Goal: Overview of random testers and coverage. Also include improvements of test code.
*/

Development of randomtestadventure.c:

	For the random test for the adventurer card I used a for loop to run through a number of tests that I set with an integer variavble called numOfRandTests. This for loop would execute until the specified number of tests were run. Inside that loop I created another loop that would randomly determine the number of cards that the hand will have and then randomly allocate cards to this hand. If the hand did not contain an adventurer card then it would set a flag to tell the program to not run the test and go back to the top of the for loop to set another random hand. Once a random hand was set the data was passed to a testing function called testAdven which takes the array of cards, player, number of cards in the hand, place in the hand where the adventurer card is, a random number between 0 to 2, the count of adventurer cards in the hand, and the total number of passed and failed tests as parameters.

	Inside the test function we change the cards in the deck if the parameter consisting of a random number between 0 and 2 is a 1. This allows us to test that the function correctly discards and non treasur cards. If the rand parameter is 2 then we set the deck size to 0.

	Once the card is executed we compare before and after results to see if the function did what we need it to do. For this card we tested that the deck is re-shuffled if the deck is empty, that the hand is increased by 2 cards, that the adventurer card is removed from the hand, that the correct number of treasurer cards are added, and that the cards in the deck that are not treasurer cards are skipped. We also check that the deck is reduced by at least 2 and that the cards in the hand after the card is played are all valid.

Coverage of randomtestadventure.c:

	The coverage over the whole dominion.c file is only about 20% but this is expected since the goal of this test is to test the only the adventurer card. When looking at the dominion.c.gcov file I can see that each statement is executed multiple times and the coverage looks good for that card.

Effort to check correctness of randomtestadventurer.c

	I noted a few flaws in the design of the static test that I tried to address in this random test. For one thing I only ever included 5 cards in the static version so I expanded this test to include up to 11 cards. Also I added in validation that all the cards in the hand after the card is executed are valid by checking that they are in the range of 0 to 26. Another correctness check I added that actually found some errors was the addition of a test to check that when the deck comes in as 0 it should shuffle the discard pile and place them in the deck. It turns out that the adventurer card does not deal with this correctly.



Development of randomtestcard.c:

	For randomtestcard.c I decided to test the Smithy card. For this test I created the hand in a similar manner to the randomtestadventurer.c file. The hands created were passed in to the test function with the following parameters: cards in the hand, player, hand count, position of the smithy card in the hand, passed and failed tests.

	In the testing section of the program I tested that 3 cards are added to the hand and that the Smithy card was removed. I also tested that the deck of cards decrease by 3 after the execution of the card. I thought about testing a situation where the deck is empty but the function used the drawCard function to handle an empty deck so I decided that it fell out of the scope for this test.

Coverage of randomtestcard.c:

	After reviewing the coverage from the test of the Smithy card it appears that the coverage was pretty good. While the total coverage of dominion.c was only about 20%, similar to the percentage coverage for randomtestadventurer.c, the coverage for the smithy card was great. Each inportant line of the function was called at least 6 times. Since the random test only executed 20 times, having the minimum number executions per line at 6 is pretty good.

Effort to check correctness of randomtestcard.c:

	To increase the correctness of this test I added in a check that makes sure the deck is decreased by 3 after the execution of the catd. As mentioned above, I thought about adding in a case where the deck is set to 0 but since the card uses the drawCard function it seems like that is out of scope for testing just the card.

