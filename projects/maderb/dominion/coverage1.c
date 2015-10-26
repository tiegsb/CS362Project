Coverage:
cardtest4.c : 4.76%
cardtest3.c : 4.42%
cardtest2.c : 9,52%
cardtest1.c : 2.55%
unittest4.c : 7.31%
unittest3.c : 5.27%
unittest2.c : 4.08%
unittest1.c : 1.53%
__________________
Sum of coverage: 39.44%

Although the sum of coverage values comes in at 39.44%, this number is actually very deceptive, as this includes overlapping segments from separate gcov executions (for example: each cardtest*.c file should contain a call to discardCard(), and as a result a portion of that code coverage is added in several times.). There are portions of this test script that use a number of different methods when striving to provide coverage:

unittest1: Testing isGameOver(). This function tests all supply piles and the province cards as well. It is meant to return 1 when either the province cards or >=3 supply piles are exhausted. Excellent branch coverage was able to be achieved
through executing both sides of each logic switch. Executing with no cards in the province pile results in 1 being returned and the game concluding. Executing with <3 supply piles empty results in a 0 being returned and the game continuing.
When 3 supply piles were emptied, the execution shows the final if statement, which returns a 1 signaling the close of the game. In this case, we are able to test that the loop registers randomly assigned empty piles, and by testing each logic
operator, we are able to execute all statements / blocks within this function.

unittest2.c : Testing scoreFor(). This test utilizes statement / block and loop coverage in order to determine whether each of the loops is functioning properly. The test starts by checking each of the 'if' statements within the function
and as a result covers each branch within the hand 'for' statement and each block contained therein as well. Since the code contained within the other two 'for' statements is functionally identical, designing a test suite
to cover each statement/block within all three loops is a triviality, and, in fact, if this program was designed with testability in mind it would be wise to set the internals in their own function, so that the succesful coverage
within one 'for' loop would reflect coverage of all identical code. The suite tests the loops by providing a stocked deck, with no cards in hand or discard, we can guarantee that discrepencies in the results are strictly due to inaccurate calculations within the block contained in the loop. Performing the same isolation strategy for the han
d and discard pile determines whether each of these is succesfully executing the block of code contained within (which includes all statements within the enclosed block). The tests are each designed to 
cycle through through the loop a fixed number of times, and as a result the loop is tested as well.

unittest3.c: Testing getWinners(). This test suite primarily focuses of the branches. Values were plugged into the test code to test both results garnered by each of the if-statements, and as a result all branches within this function could easily be covered.
In this case, full branch coverage means full block/statement coverage as well, because each path leads to a distinct return statement, running through each of these statements results in both excellent path coverage and statement / block
coverage as well.

unittest4.c: Testing drawCard(). By seeding a number of cards into the deck, it was possible to test the results of the drawCard function based on the layout of player1's hand after calling this function. The test suite is able to achieve high block /
statement coverage by once again achieving good branch coverage. The suite runs through both blocks separately by calling the function both with and without cards in the deck. A final call with no cards in deck executes the final branch and returns -1.

cardtest1.c: Testing outpost. The testing on this function was not extensive as there is no branching. A single call is able to return relatively good statement coverage; by testing this function the suite is mainly testing the functions that it is linked
to, and was actually able to easily reveal a bug in the discardCard() function as no card was placed in the discard pile upon execution as it should be.

cardtest2.c: Testing adventurer. Testing on this function was focused on good branch and path coverage. The function is first called in a situation where the top 2 cards of the deck are treasure cards. This should result in 2 cards being drawn and then
the adventurer card being discarded. There was a loop error implemented in my test code, and the loop coverage resulting from this call results in the bug being revealed, as the players hand ends up having one additional card. The same function is then
called with non-treasure cards in the cards to be drawn, which provides coverage of the other branch to the previous problem and results in a diagnosable error in cards drawn if the function is not returning the proper output. This second test also provides
branch/loop coverage of the while loop responsible for getting rid of the temporary hand created within the function.

cardtest3.c: Testing Salvager. Another very simple test with regard to coverage. In order to provide 100% branch coverage 2 tests must be done: The first requires that a target is chosen for salvager when it is called, and results in coins being present after
the function is executed. The second method of calling the function is to call it without a target, and this results in no coins being credited. Testing both directions provides solid logic coverage for the function and covers all blocks/statements contained
therein as well.

cardtest4.c: Testing Smithy. Smithy is similar to outpost in that no branching occurs, and so 100% branch and statement can be achieved within this function on the first execution. There is, however, a bug in the loop call to discardCard, which results in the incorrect
card being pulled from hand.