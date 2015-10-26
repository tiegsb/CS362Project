
/*

TEST COVERAGE

Unfortunately, I started this assignment much too late. As a result,
I only had time to implement the most basic of tests for all but the
updateCoins() function, which is tested by unittest2.c. The other seven
tests only check for successful return values, and while this type of
testing offers some value, it is obviously inferior to testing the game
state against a wide range of values. Implementing the updateCoins() test
based on the provided template code did provide beneficial hands-on experience
with setting up proper testing for the Dominion codebase, and I will carry
this lesson forward with an eye toward future assignments. I will certainly
begin assignments earlier in the future. I just hope that my lackluster
performance on this assignment won't totally destroy my class grade.

TEST NAME       COVERAGE
cardtest1.c      6.27%
cardtest2.c      5.75%
cardtest3.c      6.62%
cardtest4.c      0.70% (FAIL)
unittest1.c      1.92%
unittest2.c     16.03%
unittest3.c      3.83%
unittest4.c      0.87% (FAIL)

Clearly, as these coverage numbers demonstrate, testing the game state against
a range of values dramatically increases the coverage. As we can see, all the
tests have a relatively low amount of coverage, except for unittest2.c, which
is tested for one or two players, differing numbers and types of treasure cards, and
varying bonus amounts. The coverage for cardtest4.c and unittest4.c is
extremely low since those two tests return early due to run-time errors.
The implication is that the tests that only call a function with a single
set of argument values and check the return value tend to offer little in the
way of coverage. We can increase our code coverage significantly by including
loops that repetitively call the function over a range of values. Examining
the purpose and functionality of a given function will help to determine the
expected values for the relevant parts of the game state. It also allows for
better design of the test driver in order to achieve greater statement,
branch, and boundary coverage.

*/