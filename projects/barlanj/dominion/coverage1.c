/* Filename: coverage1.c
 * Author: Joseph Barlan (barlanj)
 * Description: This file contains coverage information using gcov on the
 *  unittest and cardtest files.
 *
 *
 */


/*
    ====================================================================================
    1.0 - unittest
    ====================================================================================
    1.01 - isGameOver() / unittest1.c
    ------------------------------------------------------------------------------------
    [10/25/2015]
    File 'dominion.c'
    Lines executed: 16.72% of 598
    Branches executed: 17.66% of 419
    Taken at least once: 14.80% of 419
    Calls Executed: 7.37% of 95

    Statement Coverage: 90% of 80
    All statements of the test ran except for the else-failed statements. I didn't find any
    failing test cases which is why these are showing us uncovered in the gcov analysis.

    Branch Coverage:
    Lines executed: 90.00% of 80
    Branches executed: 100% of 26
    Taken at least once: 80.77% of 26
    Calls executed: 90.00% of 40

    Implications:
    From the results of the gcov analysis, it looks this particular test did pretty well.
    I managed to cover a lot of cases where it could trigger a gameover and also managed
    to trigger bugs that we expected to end the game. To improve this test case, I would
    increase the amount of randomization in the test cases to add more use cases in an
    attempt to trigger all if-else statements.


    1.02 - updateCoins() / unittest2.c
    ------------------------------------------------------------------------------------
    [10/25/2015]
    File 'dominion.c'
    Lines executed: 17.06% of 598
    Branches executed: 17.66% of 419
    Taken at least once: 15.27% of 419
    Calls Executed: 7.37% of 95

    Statement Coverage: 98.77% of 81
    All statement of the test rand except for the else-failed statement. No bug was found
    so this line never executed.

    Branch Coverage:
    Lines executed: 98.77% of 81
    Branches executed: 100% of 4
    Taken at least once: 75.00% of 4
    Calls executed: 96.88% of 32

    Implications:
    This test case did extremely well in both statement and branch coverage. I would add
    a randomized loop and increase the number of test cases to further improve this test.

    1.03 - shuffle() / unittest3.c
    ------------------------------------------------------------------------------------
    [10/25/2015]
    File 'dominion.c'
    Lines executed: 17.22% of 598
    Branches executed: 17.66% of 419
    Taken at least once: 15.51% of 419
    Calls Executed: 7.37% of 95

    Statement Coverage: 97.73 of 44
    All statement of the test rand except for the else-failed statement. No bug was found
    so this line never executed.

    Branch Coverage:
    Lines executed: 97.73% of 44
    Branches executed: 100% of 12
    Taken at least once: 91.67% of 12
    Calls executed: 94.44% of 18

    Implications:
    Like test2, this one did similarly well. The function being tested is fairly simple to
    check in that we just check pre and post hand and make sure the card positions
    aren't the same. This made it straightforward to create test cases where we could trigger
    whether it worked or not. To improve this test I would add a randomized loop with increasing
    test cases of varied handcounts.

    1.04 - fullDeckCount() / unittest4.c
    ------------------------------------------------------------------------------------
    [10/25/2015]
    File 'dominion.c'
    Lines executed: 19.73% of 598
    Branches executed: 21.00% of 419
    Taken at least once: 18.62% of 419
    Calls Executed: 7.37% of 95

    Statement Coverage: 95.24 of 42
    All statement of the test rand except for the else-failed statement. No bug was found
    so this line never executed.

    Branch Coverage:
    Lines executed: 95.24% of 42
    Branches executed: 100% of 12
    Taken at least once: 83.33% of 12
    Calls executed: 94.44% of 18

    Implications:
    This also did well amongst the test implemented. I implemented the test cases
    using a loop that randomized values. I would increase the number of times
    the loop runs (from 30 currently) to thousands to see if it could hit any bugs by
    brute force.

    ====================================================================================
    2.0 - cardtest
    ====================================================================================

    All the cardtest cases had 100% branch coverage but inconsistent in the statement
    coverage. Adventurer, Council Room and Village particularly are lower than 90%
    statement coverage - this may be due to the fact that there are a lot of
    if-else statements in these test cases that didn't run. To improve these scores,
    I would add a randomized loop see if we can't trigger any corner cases that we
    may have missed using expected and fixed values.


    2.01 - smity / cardtest1.c
    ------------------------------------------------------------------------------------
    [10/25/2015]
    File 'dominion.c'
    Lines executed: 26.42% of 598
    Branches executed: 30.79% of 419
    Taken at least once: 21.48% of 419
    Calls Executed: 15.79% of 95

    Statement Coverage: 93.33% of 42
    All statement of the test rand except for the else-failed statement. No bug was found
    so this line never executed.

    Branch Coverage:
    Lines executed: 93.33% of 45
    Branches executed: 100% of 6
    Taken at least once: 50.00% of 6
    Calls executed: 82.35% of 17


    2.02 - adventurer / cardtest2.c
    ------------------------------------------------------------------------------------
    [10/25/2015]
    File 'dominion.c'
    Lines executed: 28.93% of 598
    Branches executed: 133.65% of 419
    Taken at least once: 24.11% of 419
    Calls Executed: 17.89% of 95

    Statement Coverage: 89.55% of 67
    A few if-failed statements didn't execute as these did not trigger a bug.

    Branch Coverage:
    Lines executed: 89.55% of 67
    Branches executed: 100% of 22
    Taken at least once: 63.64% of 22
    Calls executed: 80.77% of 26

    2.03 - council_room / cardtest3.c
    ------------------------------------------------------------------------------------
    [10/25/2015]
    File 'dominion.c'
    Lines executed: 30.77% of 598
    Branches executed: 35.08% of 419
    Taken at least once: 25.78% of 419
    Calls Executed: 22.11% of 95

    Statement Coverage: 87.50% of 80
    A few if-failed statements didn't execute as these did not trigger a bug.

    Branch Coverage:
    Lines executed: 87.50% of 80
    Branches executed: 100% of 22
    Taken at least once: 54.55% of 22
    Calls executed: 83.33% of 30

    2.04 - village / cardtest4.c
    ------------------------------------------------------------------------------------
    [10/25/2015]
    File 'dominion.c'
    Lines executed: 31.44% of 598
    Branches executed: 35.08% of 419
    Taken at least once: 26.01% of 419
    Calls Executed: 24.21% of 95

    Statement Coverage: 80.88% of 68
    A few if-failed statements didn't execute as these did not trigger a bug.

    Branch Coverage:
    Lines executed: 80.88% of 68
    Branches executed: 100% of 20
    Taken at least once: 55.00% of 20
    Calls executed: 75.00% of 24

 */

