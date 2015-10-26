Name: 	Jeff Moss
Date:	10/24/15
Title: 	Documentation of the coverage of the unit tests that were developed for dominion.
File:	coverage1.c
Class:	CS362 Fall 2015


OVERALL COVERAGE:
Lines executed:17.71% of 576
Branches executed:13.91% of 417
Taken at least once:11.99% of 417
Calls executed:10.53% of 95

Out of all of dominion.c, only 17.71% of the lines were executed and only 13.19% of the branches were executed. This tells me that I have very low coverage of the whole dominion program and that for dominion to be tested very thoroughly, I would need to create a lot more unit tests. One thing to note is that I did NOT use built in functions beyond the functions that I was testing. I did this for a number of reasons. First, I would not be able to tell if the problem was in the function I was testing or the predecessor function before it. Second, the code coverage would not be accurate as while it would execute those previous functions, we weren't directly testing them. Lastly, calling a function (such as cardEffect) that makes a number of changes as well as launching the functions that we are testing causes more complexity.

Looking over all the lines in the gcov file, there's a lot of spots in the code where branches were not taken and code was not executed. To discuss all of the code that was not executed would be a very lengthy endeavor, thus I believe a brief discussion that 17.71% statement coverage and 13.91% branch is not sufficient coverage. Of course, there are the obvious items that can improve this coverage, such as testing all of the card effect switch statements as well as testing out functionality across the whole game. But these tests were outside the scope of our assignment and this would obviously be a significant amount of work. Perhaps to get more robust coverage, random testing would be a good option, where the code could be run for millions of times. This would allow for functions to be called more often due to the random assignment of action cards.

IN THE SECTION BELOW, I'LL DISCUSS COVERAGE FOR EACH OF THE UNIT TESTS

unittest1.c - shuffle function

Statement:
100% of the statements in the shuffle function were executed.

Branch:
All branches of the shuffle function were taken.
The if statement for the deckCount was taken most of the time.

Boundary:
The shuffle function was executed 6 times.
The shuffle function was also tested very thoroughly my checking the positions of the cards before and after the shuffle function was called. There could be more boundary testing involved if necessary (at max numbers for example).

Total Cumulative Dominion Coverage:
Lines executed:3.65% of 576
Branches executed:2.88% of 417
Taken at least once:2.64% of 417
Calls executed:2.11% of 95

The shuffle function appeared to be well tested from the metrics above.

unittest2.c - fullDeckCount function

Statement:
100% of the statements in the fulldeckCount function were executed.

Branch:
All branches of the fullDeckCount function were executed.
There were a mix of percentages of which branches were taken but all were taken.

Boundary: 
The fullDeckCount function was executed 6 times. 
Boundary testing was adequate. Tests were tried when with no player hand or discards, with player hands, with discards and all together.

Total cumulative dominion coverage:
Lines executed:5.21% of 576
Branches executed:5.76% of 417
Taken at least once:5.52% of 417
Calls executed:2.11% of 95

Overall, the fullDeckCount function appeared to be well tested form the metrics above.

unittest3.c - isGameOver() function

Statement:
100% of the statements in the isGameOver function were executed.

Branch: 
All branches were executed, with a mix of percentages of which ones were taken.

Boundary:
The isGameOver function was executed 4 times.
Boundary testing included testing conditions where the game state should end. This included testing when exactly three supply piles were out, as well as when more than three supply piles were out. This also included the situation when province supply was empty as well as when the game should not end (just after initialization).

Total cumulative dominion coverage:
Lines executed:6.94% of 576
Branches executed:7.67% of 417
Taken at least once:7.43% of 417
Calls executed:2.11% of 95

Overall, the isGameOver function appeared to be well tested from the metrics above.

unittest4.c - gainCard function

Statement: 
100% of the statements in the gainCard function were executed. 

Branch: 
All branches were executed, with a close to equal weight of each of the branches. Some branches were only executed once.
Further testing could be accomplished to boost those branches that were not executed more than once.

Boundary:
The gain card function was executed a total of four times.
Boundary testing included testing conditions where no supply was available, adding a card to a players deck, and testing for the number of cards in both the supply and deck. Gain card was not texted at the max hand, which could be done in the future for much more detailed testing.

Total cumulative dominion coverage:
Lines executed:9.55% of 576
Branches executed:9.11% of 417
Taken at least once:8.87% of 417
Calls executed:3.16% of 95

Overall, the gaincard function appeared to be well tested. Further boundary testing could be completed to test conditions of when a players hand is completely maxed out (which is extremely unlikely).

cardtest1.c - useSmithy function

Statement:
100% of the statements in the useSmithy function were executed.

Branch:
All branches in the smithy function were executed. One branch was predominant, occuring 80% of the time.

Boundary:
The useSmithy fuction was executed once.
Many boundary conditions were tested for the smithy function. This included making sure that only 3 cards were drawn and that the smithy card was discarded. This also included making sure that cards could be drawn.

Total cumulative dominion coverage:
Lines executed:13.89% of 576
Branches executed:11.51% of 417
Taken at least once:10.31% of 417
Calls executed:5.26% of 95

Overall, the smithy function appeared to be well tested.

cardtest2.c - useAdventurer function

Statement:
100% of the statements in this function were executed.

Branch:
The adventurer function was executed 1 time.
All but one branch were excuted in this function. The branch that was not executed was the branch that tested if the deckcount was empty and if it was, execute a shuffle. This was not executed as there is no logic in this function that would require this test. The shuffle function would muddy the waters.

Total cumulative dominion coverage:
Lines executed:15.80% of 576
Branches executed:13.91% of 417
Taken at least once:11.75% of 417
Calls executed:6.32% of 95

Overall, the adventurer function appeared to be well except for the branch where the shuffle function was executed. The branch could be tested in the future, but this may not help the quality of coverage, as at that point you are testing whether or not the shuffle function works correctly.

cardtest3.c - useVillage function

Statement:
100% of the statements in this function were executed.

Branch:
There were no branches to execute in this function.

Boundary:
This function was executed one time.
Boundarys such as handcounts, discard counts, number of actions and number of buys were tested inthis function. The one boundary that was very hard to test (may require more iterations) was the post increment of the currentplayer in the discardcard function within this function. This could be tested more thoroughly in the future.

Total cumulative dominion coverage:
Lines executed:16.67% of 576
Branches executed:13.91% of 417
Taken at least once:11.75% of 417
Calls executed:8.42% of 95

Overall, the useVillage function appeared to be well tested. Further testing could be beneficial to figure out what is happening with the post increment for the discard function.

cardtest4.c - useGreat_hall function

Statement:
100% of the statements in this function were executed.

Branch:
There were no branches to execute in this function.

Boundary:
This function was executed one time.
A number of boundary conditions were tested, including the hand counts, discard counts, number of actions, ensuring that cards were only pulled from a certain deck, and testing that number of buys were not affected. As always, further boundary testing could be helpful over a number of iterations to see what behavior the post decrement would cause (perhaps many great halls in a row).

Total cumulative dominion coverage:
Lines executed:17.71% of 576
Branches executed:13.91% of 417
Taken at least once:11.99% of 417
Calls executed:10.53% of 95

Overall, the useGreat_hall function appeared to be well tested. Further testing could be beneficial to figure out what is happening with the post decrement for the number of actions. 
