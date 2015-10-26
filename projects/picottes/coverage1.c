Unit test 1 covered scoreFor(). Looking at the gcov every branch and statement is covered 
equally which makes sense because the test sequentially adds values to the deck, discard 
and hand arrays. The boundary was set a zero cards because there would be a fatal flaw somewhere
in the program a negative array position.

Unit test 2 covered isGameOver(). The gcov also showed complete branch and statement coverage.
The boundary cases of 0 or a positive value for province cards and 0-4 empty decks was used
to test the explicit failure cases of the function. The results were consistent with the
expectations.

Unit test 3 covered shuffle(). The gcov also showed complete coverage of both branch and statement.
The test should be reworked to cover more cases, for instance most obviously 0 cards.

Unit test 4 covered handCard(). The gcov also showed complete coverage. Again though the boundary
cases had flaws. The test case again did not cover 0 cards.

Card test 1 covered smithy(). The gcov again showed complete coverage. The boundary covered incrementing
the card numbers an arbitrary number of times and tested against the expected number of cards
in the players hand. Because of the flaw introduced the card count was off and the test failed.

Card test 2 covered the village card. Again the gcov showed complete coverage. The boundary
was tested by incrementing the number of cards in a hand and comparing the outcome with
the defined expectated results. The test cases failed immediately and a cursory look showed
that the count was decrementing and not incrementing.

Card test 3 covered the great hall card and gcov showed complete coverage. The boundary was
tested like the the village card test, but the outcome was congruent with the expected 
outcome and all tests passed.

Card test 4 covered the adventure card. Gcov showed that there was coverage issues with numerous
branches and statements. This was related to the boundary test shortcomings in the test involving
not testing 0 or 1 cards in hand and not testing for hands where treasure cards are not drawn.
As a result entire branches and statements were missed. Also, those branches were the ones
that contained the bugs so the tests reported as passed. Obviously, these tests would need
to redone because they missed a basic code mutation.










statement branch boundary