NOTE: Cardtest3.c, Cardtest4.c or the last two tests in my makefile (smithyFunction() and adventurerFunction()) have bugs and fail on the asserts and thus kill the program (we were not asked to fix the implementations so they remain buggy).  You’ll need to comment out test 7 (smithyFunction()) in order to have test 8 (adventurerFunction()) execute and then consequently fail evidencing a bug.

Unittest1.c:
•	Lines executed: 94.12%  
•	The lines executed would be 100% if it were not for custom asserts messages.
•	As the structure did not have branches and was a series of nested for loops each line was hit the same time as all other lines.  All in all it was a very robust test.
•	Boundaries were tested using a maxCardcount of 5000 (a number that would never be reached in real game play) and then iterating over each card in turn and then examining the results. 

Unittest2.c
•	Lines executed:80.65% 
•	The lines executed would be 100% if it were not for custom asserts messages.  There were quite a few of them in this test.
•	The results of this test in respect to branching appear to be a bit more varied than in Unittest1.c but in reality they are not. Again this is mostly nested for loops geared toward robustness and boundary testing.
•	Initial lines that instantiate are hit the minimum of maxHandcount then all other lines are hit equally.
•	This test tests amounts that would never be reached in real implementation of card play.
o	Lots of iterations and lots of big numerical values.

Unittest3.c
•	Lines executed:90.91%
•	The lines executed would be 100% if it were not for custom asserts messages.  There were quite a few of them in this test.
•	Testing gainCard() had more scenarios that needed to be assessed in order to assume full testing.
•	Again we have a nested for loop structure but with different flags being passed to the function.
•	All paths in the function were tested in similar fashion and were easy to manage as the state of the game was reset and initiated at each pass of the loop.

Unittest4.c
•	Lines executed:92.31%
•	The lines executed would be 100% if it were not for custom asserts messages.
•	This was the simplest of the tests as only the return values needed to be examined and nothing more from the state of the game.
•	There was not a lot to do here than to simply throw a lot of load at it.
•	No branching or really any other type of testing to consider for this one.

Cardtest1.c
•	Lines executed:100.00%
•	More of the state had to be looked at and then examined after testing.
•	I introduced random numbers between 0 and 4 to represent a random card in my hand to test against.
•	When falling outside of this range results became unpredictable and unreliable so staying within these boundaries became necessary as I could not handle any exception.

Cardtest2.c
•	Lines executed:100.00% 
•	With outpost there is not very much to test so again it came down to a lot of load
•	I implemented randomness to increase the robustness of this test.  
•	It had great coverage and each line was covered equally. 
•	The test only requited that the number of cards be checked after each invocation of the function under test, so if we wanted to look specifically at cards that are being discarded that would make a better test but then we would be testing the functionality of discardCard() more than outpost(); 

Cardtest3.c
•	Lines executed:100.00% 
•	This function provided a lot of confusion and examination which was fun as you’ll see in bug1.c
•	I feel that the test is pretty good and tests all of the state that needs to be tested as we were told how we might test smithy() by the instructor.
•	The expected changes were tested as well as examining those fields that were not expected to change.
•	This test had a lot of opportunity to branch and look for specific changes but I found it easier and more effective to reset the state of the game for each pass. 
o	When thinking about the expected result it could all be examined simultaneously thus eliminating the need for varied, specific testing.

Cardtest4.c
•	Lines executed:100.00% 
•	This (adventurer()) felt a lot like testing smithy().  There was a lot of state change and a lot to consider in the way of expected changes and examining fields that were not to have changed after function invocation.
•	Knowing that he function is supposed to look for the two closest upcoming treasure cards it was helpful to, at times, set all cards in the hand to treasure cards, and at other times to set none of them to a treasure value to examine outcomes and implement some branch testing.
•	Brute forces was a good one for this after the test was well though through and streamlined to be efficient and at the same time through. 