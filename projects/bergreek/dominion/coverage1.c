Total coverage of all tests on dominion.c:
Lines executed:30.46% of 650
Branches executed:31.18% of 417
Taken at least once:23.02% of 417

Each function test and card test is described below with their
individual coverage values from within the functions themselves.
Coverage of all tests on dominion.c is found above.

Only 30% of lines were executed and 31% of branches were executed
with these tests. In order to have more code coverage, other 
functions would have to be tested including some of the more 
frequently used ones such as discardCard(). Additionally, each of 
my tests would need to be expanded to test more boundary and 
edge cases.

Each of my test functions below had statement and branch coverage
of 100% except for cardtest3 (adventurer test). This was because
I only selected copper treasure cards to be added to the players
deck and not silver or gold cards, so two branches never executed. 

/*****************************************************************/

unittest1.c - updateCoins()
Lines executed:100.00% of 34
Branches executed:100.00% of 14
Taken at least once:78.57% of 14

/*****************************************************************/

unittest2.c - gainCard()
Lines executed:100.00% of 36
Branches executed:100.00% of 16
Taken at least once:62.50% of 16

/*****************************************************************/

unittest3.c - drawCard()
Lines executed:100.00% of 29
Branches executed:100.00% of 12
Taken at least once:75.00% of 12

/*****************************************************************/

unittest4.c - buyCard()
Lines executed:100.00% of 48
Branches executed:100.00% of 22
Taken at least once:72.73% of 22

/*****************************************************************/

cardtest1.c - smithyEffect()
Lines executed:100.00% of 18
Branches executed:100.00% of 4
Taken at least once:75.00% of 4

/*****************************************************************/

cardtest2.c - villageEffect()
Lines executed:100.00% of 22
Branches executed:100.00% of 8
Taken at least once:62.50% of 8

/*****************************************************************/

cardtest3.c - adventurerEffect()
Lines executed:89.19% of 37
Branches executed:100.00% of 10
Taken at least once:80.00% of 10

        2:   20:		else if (state->hand[player][i] == silver) {
branch  0 taken 0%
branch  1 taken 100%
    #####:   21:			silvers++;
    #####:   22:		}
2:   23:		else if (state->hand[player][i] == gold) {
branch  0 taken 0%
branch  1 taken 100%
    #####:   24:			golds++;
    #####:   25:		}

/*****************************************************************/

cardtest4.c - stewardEffect()
Lines executed:100.00% of 37
Branches executed:100.00% of 10
Taken at least once:60.00% of 10

/*****************************************************************/
