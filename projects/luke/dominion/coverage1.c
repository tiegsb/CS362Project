Kenny Lu
October 23, 2015
CS 362
Assignment 3
coverage1.c

This file will analyze the code coverages (statement, branch, boundary, etc.) for the unit
tests that I performed in dominion.c.
----------------------------------
Overall Coverage of dominion.c: 
Lines executed: 30.00% of 650
Branches executed: 32.13% of 417
Taken at least once: 22.06% of 417

After running all of these tests, only 30.00% of the code is covered because there are 
a lot of functions that were not touched.  In terms of coverage within individual functions
that my unit tests tested, I feel like I did a good job because in most cases, all lines and
branches were covered.  One concern would be that there are some test cases that I missed yielding
code in a tested function to not be covered. One example of this is in the shuffle function
where I didn't test for the case where deckCount is 0.
-----------------------------------
unittest1 - updateCoins():

In dominion.c: 
Lines executed:17.08% of 650
Branches executed:15.83% of 417
Taken at least once:13.43% of 417

Statement Coverage: Testing for code coverage of dominion.c using this unit test, all of 
the statements were covered as there were no hashtags next to any of the statements in the
updateCoins() function of the dominion gcov file.  

Branch Coverage:
According to the branch version of the dominion gcov file: function updateCoins called 20
returned 100% blocks executed 100%.

The above statement indicates that all of the branches are covered in this function. In the
for loop, there is an if statement that determines if  acoin is a copper, silver or gold coin
and for each test hand (there are 5) of my unit test, I made it so that most of the cards in 
all of hands were not treasure cards.  This was represented in my coverage because the branch 
where the card = a coin is usually the least common route taken.  This copper branch yielded only
39% of all traffic, the silver yielded 39%, and the gold yielded 19%.  These numbers tell us 
that the majority of the cards never matched these if conditions and prefered traveling to the
else statement instead.

Boundary Coverage: In the unit test, there were 5 tests included which added more coins and bonuses
as the tests progressed, increasing the frequency of coins being found while the handCount of 
each sequential deck increased as well.  This fact increases the complexity of the testing 
and increases the margin for error as the test progresses.  This makes the testing of the updateCoins()
function tighter and tigher as more subtests progress.
------------------------------------------------------
unittest2 - gainCard():

In dominion.c (not cumulative from other tests):
Lines executed:18.92% of 650
Branches executed:17.27% of 417
Taken at least once:14.39% of 417

Statement Coverage: All of the statements in the function gainCard() were covered at least once
giving 100% statement coverage of the function.  This makes sense because the unit test tests 
all possibilties throwing all of the flags to elicit each test case.

Branch Coverage:
According to the branch version of the dominion gcov file: function gainCard called 4 returned 
100% blocks executed 100%.

This indicates again that all of the branches in our function were covered by the unit test that
I created. Further analysis shows that the first if statement is only entered 25% of the time.
This makes sence because it's a rare case when supplyCOunt is less than one.  The second if statement
has a 33% enter rate which is flag 1, flag 2 has a 50/50 chance of entering vs skipping that edge.
These numbers make sense because my test elicits flag one once and flag 2 once.  There is also
another flag that traces to an else edge case so there are 3 calls in total.  The 33% represents
one call for flag one.  The 50/50 case occurs for the else if and else because 2 is called once
leaving the else to be called catching any other number once as well (comprises of the other entrance).

Boundary Coverage: We knew that gainCard() would not be possible and would return -1 if 
supplyCount became less than 1 so I set the supplyCount to 0 to check for what happens.
Indeed, a -1 was returned.  I could've improved on this boundary coverage by using a range of
numbers towards zero which will give us more insight in terms of testing goes.
-------------------------------------------------------------------------------
unittest3 - shuffle():

In dominion.c (not cumulative from other tests):
Lines executed:16.46% of 650
Branches executed:15.83% of 417
Taken at least once:12.95% of 417

Statement Coverage: There is one statement that is not covered when the unit test for shuffle
is run.  This makes sense because it's a very rare case where the player's deck count is less
than 1.  Because this is never tested, in the unit test, the statement is left untouched.

Branch Coverage:  
According to the branch version of the dominion gcov file: function shuffle called 6 returned 
100% blocks executed 93%.

The 93% accounts for the statement explained above that is never run.  This is because the unit test
never tests for a case where the deckCount is less than one (no cards to shuffle).  We can see this
because the if statement is entered 0% of the time going around it 100% of the time from the
gcov file.
----------------------------------------------------------------------------------
unittest4 - isGameOver():

In dominion.c (not cumulative from other tests):
Lines executed:18.31% of 650
Branches executed:17.75% of 417
Taken at least once:14.87% of 417

Statement Coverage: There is 100% statement coverage in this function from our unit tests performed
This is indicated by no hashtags. 

Branch Coverage:  
According to the branch version of the dominion gcov file: isGameOver called 24 returned 
100% blocks executed 100%

All of the branches are hit at least one time from this unit test.  The values of the branches
are all very extreme as the number of the highest branch out of branch 0 and 1 is always 90% or
above.  This makes sense because isGameOver is an extreme case function where the function is
hit many times but most of the time returns that the game isn't over.

Boundary Coverage:  To test where the province deck isn't empty, we used a while loop to hone
in to the case where the deck would eventually become empty. In addition, to check for empty supply
decks, we started from one deck being down, testing isGameOver(), repeating to two decks down, then 
finally three decks down and the game being over.
-------------------------------------------------------
cardtest1 - smithyCard():

In dominion.c (not cumulative from other tests):
Lines executed:20.77% of 650
Branches executed:19.66% of 417
Taken at least once:16.07% of 417

Statement Coverage: There is 100% statement coverage in this function from our unit tests performed
This is indicated by no hashtags. 

Branch Coverage:
According to the branch version of the dominion gcov file: function smithyCard called 1 returned 
100% blocks executed 100%

There is only one for loop in this function that is taken 67% of the time because it loops twice and
the third time it attempts to loop, the excape conditions are met and the 3rd time we escape 
the for loop yielding 33% outside of the loop.
-----------------------------------------------
cardtest2 - adventurerCard():

In dominion.c (not cumulative from other tests):
Lines executed:24.62% of 650
Branches executed:23.50% of 417
Taken at least once:19.42% of 417

Statement Coverage: There is 100% statement coverage in this function from our unit tests performed
This is indicated by no hashtags. 

Branch Coverage: 
According to the branch version of the dominion gcov file: 
function adventurerCard called 1 returned 100% blocks executed 100%

All of the branches in the function are covered by the unit test.  The first branch is the while loop.
Because most cases, drawntreasure will be below 2, this while loop is taken 86% of the time.
The first if statement checks if deckCount<1 which is only 17% of the case. 
---------------------------------------------------------------------------
cardtest3 - villageCard():

In dominion.c (not cumulative from other tests):
Lines executed:25.38% of 650
Branches executed:23.50% of 417
Taken at least once:19.42% of 417

Statement Coverage: There is 100% statement coverage in this function from our unit tests performed
This is indicated by no hashtags. 

Branch Coverage:
According to the branch version of the dominion gcov file: 
function villageCard called 1 returned 100% blocks executed 100%

There are no branches that need to be tested inside this function.

Boundary Conditions: We are only testing to see if the state before the function call is 
congruent to the state after the function call given the certain conditions of the function 
call.  This is done by matching old and new numbers (after the function call).
-----------------------------------------------------------------------------
cardtest4 - stewardCard():

In dominion.c (not cumulative from other tests):
Lines executed:19.54% of 650
Branches executed:17.27% of 417
Taken at least once:14.15% of 417

Statement Coverage: There is 100% statement coverage in this function from our unit tests performed
This is indicated by no hashtags. 

Branch Coverage:
According to the branch version of the dominion gcov file: 
function stewardCard called 3 returned 100% blocks executed 100%.

All of the branches are hit at least once in this function because our unit test. The first
branch is an if statement that enters the first choice 33% of the time. Because we are testing
for 3 flag cases, this is congruent because the 33% would be the first flag yielding +2 cards.
The first else if statement is entered 50% of the time because it is hit once as well leading the
last flag to be caught in the else statement (yielding a 50% branch 0 and 50% branch 1).

