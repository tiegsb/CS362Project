Results for all unit and card tests
unittest1.c
Testing UpdateCoins()
File 'dominion.c'
Lines executed:1.88% of 586
Branches executed:1.92% of 417
Taken at least once:1.92% of 417
Calls executed:0.00% of 101
dominion.c:creating 'dominion.c.gcov'

File 'unittest1.c'
Lines executed:96.88% of 32
Branches executed:100.00% of 4
Taken at least once:75.00% of 4
Calls executed:75.00% of 4
unittest1.c:creating 'unittest1.c.gcov'

unittest2.c
Testing GainCard()
File 'dominion.c'
Lines executed:2.56% of 586
Branches executed:1.44% of 417
Taken at least once:1.44% of 417
Calls executed:0.99% of 101
dominion.c:creating 'dominion.c.gcov'

File 'unittest2.c'
Lines executed:87.88% of 33
Branches executed:100.00% of 10
Taken at least once:60.00% of 10
Calls executed:60.00% of 10
unittest2.c:creating 'unittest2.c.gcov'

unittest3.c
Testing discardCard()
File 'dominion.c'
Lines executed:2.22% of 586
Branches executed:1.44% of 417
Taken at least once:1.44% of 417
Calls executed:0.00% of 101
dominion.c:creating 'dominion.c.gcov'

File 'unittest3.c'
Lines executed:89.13% of 46
Branches executed:100.00% of 12
Taken at least once:58.33% of 12
Calls executed:54.55% of 11
unittest3.c:creating 'unittest3.c.gcov'

unittest4.c
Testing getCost()
File 'dominion.c'
Lines executed:4.61% of 586
Branches executed:6.71% of 417
Taken at least once:6.00% of 417
Calls executed:0.00% of 101
dominion.c:creating 'dominion.c.gcov'

File 'unittest4.c'
Lines executed:90.00% of 10
Branches executed:100.00% of 4
Taken at least once:75.00% of 4
Calls executed:75.00% of 4
unittest4.c:creating 'unittest4.c.gcov'

cardtest1.c
Testing Smithy()
Card was trashed not discarded
File 'dominion.c'
Lines executed:4.44% of 586
Branches executed:2.40% of 417
Taken at least once:1.44% of 417
Calls executed:2.97% of 101
dominion.c:creating 'dominion.c.gcov'

File 'cardtest1.c'
Lines executed:96.67% of 30
Branches executed:100.00% of 8
Taken at least once:75.00% of 8
Calls executed:80.00% of 5
cardtest1.c:creating 'cardtest1.c.gcov'

cardtest2.c
Testing adventurer()
File 'dominion.c'
Lines executed:11.09% of 586
Branches executed:7.19% of 417
Taken at least once:6.24% of 417
Calls executed:5.94% of 101
dominion.c:creating 'dominion.c.gcov'

File 'cardtest2.c'
Lines executed:91.67% of 48
Branches executed:100.00% of 20
Taken at least once:80.00% of 20
Calls executed:66.67% of 12
cardtest2.c:creating 'cardtest2.c.gcov'

cardtest3.c
Testing council_RoomF
File 'dominion.c'
Lines executed:4.95% of 586
Branches executed:3.36% of 417
Taken at least once:2.16% of 417
Calls executed:2.97% of 101
dominion.c:creating 'dominion.c.gcov'

File 'cardtest3.c'
Lines executed:93.75% of 32
Branches executed:100.00% of 8
Taken at least once:75.00% of 8
Calls executed:66.67% of 6
cardtest3.c:creating 'cardtest3.c.gcov'

cardtest4.c
Testing FeastF()
No end of loop for testing gain card with no supply, and card too expensive
File 'dominion.c'
Lines executed:6.48% of 586
Branches executed:11.03% of 417
Taken at least once:3.12% of 417
Calls executed:5.94% of 101
dominion.c:creating 'dominion.c.gcov'

File 'cardtest4.c'
Lines executed:96.77% of 31
Branches executed:100.00% of 6
Taken at least once:83.33% of 6
Calls executed:85.71% of 7
cardtest4.c:creating 'cardtest4.c.gcov'

I created my unit tests with the intention of trying to acheive maximum branch coverage. By reviewing the dominion.c.gcov
file after each run of a unittest or cardtest, I was able to see the individual branch coverage of each test.
Most of the tests, while acheiving a high percentage of branch coverage, never caught bugs placed in the functions.
I beleive this is a result of not testing corner cases as well as I could have, as well as not creating detailed enough
tests. I created tests that checked for the most obvious errors, i.e., the correct number of cards were drawn
for the player that played the smithy card. In retrospect I should have been making tests that checked all other 
variables for every player, instead of just the immediate variables. This would allow for much, much better
testing. Near the end of writing unit tests I developed a quickSetup function, that allowed me to build a generic
gameState, and then change specific aspects of it to fit the test. This ended up being an incredible time saver
and I would probably make that my first priority when it comes to new unit testing. Other changes I would probably make
are numbered tests, and a printout for when tests pass, as well as when they do not pass. The final thing I would try to 
implement in the next test suite would be a cumulative test, which would make total coverage much more possible
than implementing each unit test separately.