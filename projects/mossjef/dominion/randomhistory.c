
Name: 	Jeff Moss
Date:	11/1/15
Title: 	Documentation of the two random testers that were built for the adventurer card
	and the great_hall card.
File:	randomhistory.c.c
Class:	CS362 Fall 2015

randomtestadventurer:
Description:
For the development of the randomtestadventurer random tester, I took an approach that was similar in concept to my unit tests but needed to think a little more broad. My first approach was to create a pre-game state that was identical to the post game state on initialization. Then, I would make adjustments to the pre-game state and assert that pre and post matched. In theory this sounded great until I found that there were things I wouldn't be able to test. 

For example, there is no way for me to determine exactly which cards drawcard will draw when the adventurer draws cards until two treasure cards are drawn. This made it difficult (if not impossible) to determine exactly how many cards were drawn and how many were discarded. I was able to test for the condition that whichever cards are pulled from the deck and added to the hand should match the change in the discard pile. 

While I was unable to assert that the pre-state was exactly the same as post-state, I was able to assert almost all attributes of the gamestate struct manually. 

Bugs found:
The random test found that the played card count was not incrementing correctly. It is pretty self explanatory that the played card count should be incremented by one after the adventurer card is played. 

Further, I found a strange error that only occured once. I am wondering if it is a setup error or an actual bug found in the code. This error was the fact that the change deck count + handcount did not match the change in discard count. I was unable to trace the cause of the error but I'm guessing it has to do with the discard card function error that I found through unit testing.

Coverage:
Coverage for the adventurer random tester was much higher than the unit testers. In fact, the random tester executed 18.40 percent of the total lines in the code while the whole test suite of all unit tests barely hit the 18% mark. Further, branch executions, taken at least one executions were similar on percentage as the line executed mark.

93% of the useAdventurer function was executed. It appears that the branch where the cards are shuffled if the deck is out. This was not part of the random tester execution, but would make a good endpoint test.

Random test:
File 'dominion.c'
Lines executed:18.40% of 576
Branches executed:18.71% of 417
Taken at least once:15.11% of 417
Calls executed:8.42% of 95
dominion.c:creating 'dominion.c.gcov'

randomtestcard.c:
Description:
The random tester that I built for randomtestcard.c was to test the great_hall card. I used a very similar framework as the random tester that I wrote for the adventurer card. In this case, I was able to determine exactly how many cards were added and discarded. To test the whole struct gamestate, this was a fairly straightforward test.

Bugs found:
The random tester found three bugs in this function. One bug was that the discard count was not being incremented correctly. Another bug was that the handcount was not being decremented correctly. Lastly, numactions was not being incremented as a result of this function (which is the purpose of this function).

Coverage:
The random tester executed 18.58% of the lines of dominion.c. Comparing this to the full test suite of unit tests, the random tester executed much more code. The full suite of unit tests almost hit 18% for comparison. Branches executed, lines executed and taken at least once were all similar in the double digits.

100% of the great_hall function was executed. This is great code coverage and did not require any endpoint tests. This makes sense, as this function has more clear start and finish points, which make it much more convenient to test on a random tester. 

Random test:
File 'dominion.c'
Lines executed:18.58% of 576
Branches executed:17.27% of 417
Taken at least once:13.91% of 417
Calls executed:9.47% of 95
dominion.c:creating 'dominion.c.gcov'
