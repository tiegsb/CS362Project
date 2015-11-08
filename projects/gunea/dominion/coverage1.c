/******COVERAGE1.c******

Running gcov on the dominion.c file revealed
that the current tests only tested about 33% of the 
code. I suspect that this is partly because of the 
way the tests were structured - that is, they
tested the individual functions by calling them
in isolation rather than in the exact way they 
would be called in the game, though the tests
did attempt to replicate game conditions.

Much of the code was bypassed as certain cards
were never played or certain functions were never called.
In particular, most of the cardEffect() function
was left uncovered, and the code for the non-refactored
cards was not tested at all. Since the cardEffect() 
function forms the essence of the game, a proper testing 
suite should aim to test all the cards in the function
with multiple input types as discussed in lecture.

gcov results:

File 'unittest1.c'
Lines executed:88.24% of 51
unittest1.c:creating 'unittest1.c.gcov'

File 'unittest2.c'
Lines executed:93.16% of 117
unittest2.c:creating 'unittest2.c.gcov'

File 'unittest3.c'
Lines executed:91.09% of 101
unittest3.c:creating 'unittest3.c.gcov'

File 'unittest4.c'
Lines executed:89.92% of 129
unittest4.c:creating 'unittest4.c.gcov'

File 'cardtest1.c'
Lines executed:90.00% of 30
cardtest1.c:creating 'cardtest1.c.gcov'

Lines executed:100.00% of 29
cardtest2.c:creating 'cardtest2.c.gcov'

File 'cardtest3.c'
Lines executed:100.00% of 30
cardtest3.c:creating 'cardtest3.c.gcov'

File 'cardtest4.c'
Lines executed:100.00% of 20
cardtest4.c:creating 'cardtest4.c.gcov'

File 'dominion.c'
Lines executed:32.99% of 579
dominion.c:creating 'dominion.c.gcov'

*/

//end of coverage1.c