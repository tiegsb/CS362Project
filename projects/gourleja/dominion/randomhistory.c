/*
 * Jason Gourley
 * gourleja@oregonstate.edu
 * CS362-400
 * Assignment 4 - randomhistory.c
 * Description : Development writeup for random test cases
 */


/*

-------------------------------------------------------------------------------
Development

    Approaching the random testing for this assignment I looked at the original unit
    tests and found what areas I could impact the unit tests by introducing the random
    values in the cases.  These areas I wanted to focus on were where the previous
    tests had not tested combinations beyond the basic initial setup.  In order to
    recognize any differences in coverage and error detection I chose to use the
    minion card for the randomtestcard.c unit tests.

    The basic data that I found to be most important was in the generation of a
    new game state.  I looked at the parameters necessary to create a new game state
    and what valid ranges of input were allowed.  Then I created a new method for
    both card tests, randomGame(), where I could set random games up with valid player
    count, random set of action cards while ensuring the card under test was available
    in the set, and then a random seed as well.  In previous testing the same game
    seed was used for each unit test and the cards available in the game where always
    the same pulling from a hard coded array.

    With the generation of random game states I decided that for each loop on an
    individual test I would create a completely new game state object to avoid any
    unexpected errors of how the random game state might handle in each iteration
    of an individual test.


-------------------------------------------------------------------------------
Coverage

    The overall coverage for these specific methods under test is very similar to
    the prior tests in regard to statement coverage.  I updated the makefile to
    produce the correct coverage information from the assignment 3 unit tests for
    comparison as well.  The most noticeable item looking at the coverage reports
    is how many times each line of the application was actually executed and how
    much better the branch coverage was.

    With running so many random tests on each card the branch coverage was given
    a chance to improve as the lines executed were subjected to a broad set of
    random states.  Simply running the unit tests from the prior assignment it
    seemed that some of the failures were always consistent.  However running the
    random tests I found that there was more of a fluctuation in failure rates
    than I had anticipated occurring based on the prior testing.

    One additional area I was able to see an improvement was in the helper
    functions that each card was making calls to.  These additional calls and
    the reliability was helpful to build faith in the correctness of these
    methods as well as the methods specifically under test at the time.

-------------------------------------------------------------------------------
Correctness of Specifications

    As far as the correctness of the specification is concerned the unit tests
    for the adventure card failed at a rate of near 66%.  With this failure
    rate it is evident that the code for this particular card definitely does
    not meet the specifications.  Some of the specifications are being met,
    but the failure rate indicates some major errors in the logic to match the
    card’s specifications.

    The random tests for the minion card have a consistent success rate of 100%
    for the unit tests.  Based on this success rate in testing the code against
    the constraints of the specification it is true that the minion card matches
    the specifications.  There may be some additional tests that can created to
    test for the range of inputs and any multi-way combinations that throws any
    unexpected errors or puts the game state into an unexpected state.

*/
