I ran gcov on each unittest and cardtest to find it's coverage in dominion.c.  Then I grepped for '####' to find the lines where there was no coverage.
I copied it's output to a spreadsheet so that I could compare each coverage results from my test and find the similarites between the lines in dominion.c
that aren't being covered at all.  The functions, playCard, buyCard, numHandCards, whoseTurn, EndTurn, getWinners, cardEffect are some of the cards that
are not covered, so in the future I should add to my test suite, tests that verify these functions are working corectly or not.

unittest1.c: isGameOver()
Lines executed:17.19% of 576
Branches executed:17.75% of 417
Taken at least once:14.63% of 417
Calls executed:7.29% of 96

This unit test only executed about 17% of the lines in dominion.c and 18% of the branches in dominion.c.
Most of the coverage results are about this score.  I think due to the fact I was only testing one function
per unit test, they were very close to the amount of code it covered.

unittest2.c: scoreFor()
Lines executed:19.79% of 576
Branches executed:25.90% of 417
Taken at least once:19.66% of 417
Calls executed:7.29% of 96

This unit test executed about 20% of the lines in dominion.c and only 25% of the branches in dominion.c.
Which was about average compared to the other tests.

unittest3.c: cardCost()
Lines executed:5.03% of 576
Branches executed:6.71% of 417
Taken at least once:6.47% of 417
Calls executed:0.00% of 96

This unit test only executed about 5% of the lines in dominion.c and 7% of the branches in dominion.c.
This is a very small number of lines executed in the code, but that makes sense, since this function is just a litte 
part of the code.

The implication of this test, is that it probably took longer to write a test than it was worth, in 
number of lines covered in dominion.c.

unittest4.c: updateCoins()
Lines executed:15.97% of 576
Branches executed:15.83% of 417
Taken at least once:13.43% of 417
Calls executed:7.29% of 96

This unit test only executed about 16% of the lines in dominion.c and 16% of the branches in dominion.c.
This was a little less than average.

cardtest1.c: smithy_card()
Lines executed:18.06% of 576
Branches executed:17.75% of 417
Taken at least once:14.15% of 417
Calls executed:9.38% of 96

This unit test only executed about 18% of the lines in dominion.c and 18% of the branches in dominion.c.


cardtest2.c: adventurer_card()
Lines executed:20.66% of 576
Branches executed:19.66% of 417
Taken at least once:17.27% of 417
Calls executed:10.42% of 96

This unit test executed about 21% of the lines in dominion.c and 17% of the branches in dominion.c.
This test was a little bit more than average, because this code contained more code than the other
functions.  

cardtest3.c: village_card()
Lines executed:18.58% of 576
Branches executed:17.27% of 417
Taken at least once:13.67% of 417
Calls executed:10.42% of 96

This unit test executed about 19% of the lines in dominion.c and only 17% of the branches in dominion.c.
Most functions had about 17-19% coverage.

cardtest4.c: steward_card()
Lines executed:19.27% of 576
Branches executed:18.23% of 417
Taken at least once:14.87% of 417
Calls executed:12.50% of 96

This unit test only executed about 19% of the lines in dominion.c and 18% of the branches in dominion.c.
This test had like 13% calls executed, which is the most compared to all of my unittests.  Which is
not what I would have expected, but it makes sense.
