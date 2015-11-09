/******************************
Susan Lee
CS 362_400_Fall15
Assignment3 – coverage1.c
*******************************/

/******************************
ADVENTURER FAILURE SUMMARY: 
********************************/
The random test cases were similar to the ones ran in my unit tests.  My previous tests indicated
a lack of diversity in my inputs, therefore, the random testing greatly increased the variety I 
was looking for.  The results showed a significant increase in coverage demonstrating that the 
variances provided by random testing for the deck, discard, and hand piles were quite useful.  In 
my previous testing, I did not think to test for cases where there was only 1 treasure card present
in the player's deck or discard pile.  The random inputs actually illuminated a case where this was
so, and presented a bug in the logic of the code.  It should allow for an exit condition upon 
discovery that there are no more treasure cards to be found after cycling through both the player's
deck and shuffling of their discard pile.

I began testing with smaller iterations for test cases, which allowed me to step through a number of
cases and verify the results were as expected.  Also, to create a more robust random test case, I 
inserted a boundary condition for when the player's deck contains no treasure cards.  I also noticed
that there were at times, unreasonable inputs for the coins value, and was able to pare down the 
randomness of coins.  This allows for more reasonable random input, and more substantive test data.

Hand count failures: 4537/5931
Deck count failures: 4394/5931
Discard count failures: 5931/5931
Treasure card failures: 0/7468
Other Players' hand count failures: 0/8726
Coin count failures: 0/5931
Adventurer count failures: 1621/5931

File 'dominion.c'
Lines executed:45.09% of 570
Branches executed:53.00% of 417
Taken at least once:35.01% of 417
Calls executed:29.47% of 95
Creating 'dominion.c.gcov'

Overall, I find the value of random testing in that it increases the robustness of your test suite.
It tests for a variety of inputs, that would be difficult to cover or even generate and
illuminated cases that were not considered before. By increasing the number of test cases, we are 
able to better understand how the function would operate in the real world with users.  However, I 
also found that it is important to balance the randomness with some known input and boundaries to 
ensure that those cases will be considered in the test suite. As I grew my test suite, it became
harder to keep track of the results expected as the types of inputs varied.  I would like to in 
the future, work on optimizing this random test some more, so that the results would be more 
uniform and obvious as to where the bugs are.  

/******************************
COUNCIL ROOM FAILURE SUMMARY:
********************************/
The random test cases were similar to the ones ran in my unit tests.  As seen above, most of the 
issues with my test coverage in the unit tests were due to a lack of diversity in inputs.  For 
this random tester, I was able to set a number of members of the game state to create a variety
of inputs.  I randomized the deck, discard, and hand piles for the players, as well as the hand
position for the council room card.  This gave me a great level of coverage for testing the discard
of the council room card because it could end up at any number of positions in the player's hand.
During my test development, I came across a number of game state members that required a more reasonable
input(playedCardCount, numBuys, coins) in order to generate more substantive results.  In fact,
not changing the playedCardCount resulted in a seg fault error when the discardCard function was
called.  

As with the case above, I began testing with smaller iterations for test cases so that I could step
through the results of a couple to ensure the tests were working as intended.  The results of 
coverage increased by a good amount from my previous unit test.  This indicates that the robust 
data provided by the random tests enabled more of the program to be covered.  The test results
themselves were as expected, and pretty uniformly indicated the problem areas of the code.  The 
results themselves, however, required a different level of interpretation than the previous unit
tests.  This is due to the less controlled environment for testing, which gave unknown inputs and 
therefore required a shift in the frame of analysis.  

For instance, I would expect there to be no council card count failures.  Based on my first unit 
test, I was able to control that no new council cards would be added to the player's hand.  However, 
with random inputs, I cannot (and wouldn't want to) impose a restriction on the player's deck, or 
discard pile that would be required to ensure that they would not receive a new council card in 
their hand.  Therefore, I must check for the council count based on the assumption that the last 
4 cards in their hand are the only new cards added.  However, I had found that there is a bug in 
the code and allows the current player to receive a fifth card(and all other players to not receive 
their +1 card), which thereby throws off my new council card count.  This explains why there is a 
discrepancy in what I expect the result to be, in that I am not considering the fifth card added 
to their hand when counting any new council cards.  However, this isn't the worst thing in the world, 
because it did bring to light that there was a bug in the code, and by going back to where I placed 
my assumption, I was able to discover the source.  

Hand count failures : 92 / 92
Deck count failures : 92 / 92
Discard count failures : 92 / 92
Buy count failures : 0 / 92
Other Players' hand count failures: 112/112
Other Players' deck count failures: 112/112
Coin count failures : 0 / 92
Council count failures : 11 / 92

File 'dominion.c'
Lines executed : 46.67% of 570
Branches executed : 54.44% of 417
Taken at least once : 36.21% of 417
Calls executed : 32.63% of 95
Creating 'dominion.c.gcov'