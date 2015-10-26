* Coverage for unittest1.c (handCard())
Lines executed:16.67% of 660

For this unit test, the percentage of coverage was actually quite generous. The function itself is only two lines of code
and is executed every time the function is called. The additional code coverage comes from the intialization function. Since
there are only two lines of code, there is no branch coverage required and the testing does full statement coverage.

* Coverage for unittest2.c (supplyCount())
Lines executed:16.36% of 660
The function tested by this unit test also only contains a small bit of code. This function simply returns the supply count
of a given card, so it has full statement coverage. There is no logic and branching involved, so statement coverage is the 
only relevant type of coverage.

* Coverage for unittest3.c (numHandCards())
Lines executed:16.52% of 660
This function only contains a single line of code so there is full statement coverage. 

* Coverage for unittest3.c (fullDeckCount())
Lines executed:17.88% of 660
This function is a bit more complex than the other function and it achieves full statement coverage. Although it has several if
statements, there are no complementing else statements so code does not branch out. However, all the for loops run multiple times, 
which shows that we have good coverage in this area.

* Coverage for cardtest1.c (smithy card)
Lines executed:18.64% of 660
For the Smithy card function itself, we have good statment coverage. However, the smithy function calls two other funcions: drawCard 
and discardCard. Let us first look at the drawCard function. The drawCard function does not have very good branch coverage as only
one if statement is run by our tests. In order to obtain better branch coverage (and, as a result, better statement coverage), we
would need to test the smithy function call with a completely empty deck. As it currently stands, more than half the code of the 
drawCard function is not touched by our testing. The discardCard has pretty good branch and statement coverage, but two branches are
not touched by our current testing. In order for these to be tested, we would need to test with a deck that only has one card or 
discard a card that is in the last position of the hand. Both of these test would be simple to implement by testing the discard or draw
card functions by themselves or through the smithy function.

* Coverage for cardtest2.c (adventurer card)
Lines executed:18.48% of 660
The adventurer card has good coverage, both statement and branching, but there is one small branch that does not run. This piece of code
runs when the deck is empty and our tests do not currently account for a completely empty deck. However, the piece of code that is not 
covered involves calling the shuffle() function. If we expanded our test suite to include running this function, then we'd also have to 
check to make sure that the shuffle function runs correctly. Rather than expanding our test suite to run an additional test for the 
adventurer function, it would probably be better to unit test the shuffle function directly as currently we are assuming that the 
shuffle function already runs correctly. If it doesn't run as intended, then expanding our adventurer test suite would be pointless.

* Coverage for cardtest3.c (village card)
Lines executed:18.48% of 660
The village card is similar to the smithy card in that it calls both the drawCard and discardCard functions. As was the case with the smithy
card functions, the drawCard function does not run the code associated with and empty deck nor does the discardCard function run the sections
with a single card or a card that is in the last position of the hand. The village testing could be expanded and obtain total branch and
statement coverage of drawCard and discardCard by including these testing situations.

* Coverage for cardtest4.c (council card)
Lines executed:19.55% of 660
The council card has good statement coverage as all statements in the function are executed. This function, however, suffers the same issue
as the other functions as both the discardCard and drawCard lack tests for empty decks and hands with a single card in it. 

* Conclusions
Testing has shown that we need to create more tests that include different sizes of decks and card position. Because both the discardCard and
drawCard functions are tied in with all our card functions, I probably would not expand my test suite for the individual cards, but rather
I would create an entirely new set of tests to test out the drawCard and discardCard functions directly. Since these two functions are 
vital to the entire game, I would test them by themselves and confirm that they are working as expected. It, of course, wouldn't hurt to
expand our card testing suite to include these tests as an added measure.







