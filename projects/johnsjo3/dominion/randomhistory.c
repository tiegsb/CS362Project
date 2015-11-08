RANDOM TEST CARD - SMITHY
===========
I designed this test based on past experience from Assignment 3.  In fact, this is the exact same
code since in Assignment 3 I had implemented random tests.  The design of the test was such that
the game state is 100% randomized, then important features to smithy are given reasonable values,
then important test cases are injected upon occasion (such as testing for when the deck is empty or
when the discard is empty or both!).

In this card test, we are testing the functionality of the smithy card.  As it turns out, the bug
I attempted to introduce in Assignment 2 didn't actually bug the program in the way I thought it
would.  In any case, the glaring issue that was caught by randomtestcard was the problems associated with
the discardCard function.  As it would turn out, discardCard function does not actually place
discarded cards into the discard pile.  Rather, the cards are instead listed as played.  This would
not be a problem if it weren't for the fact that the cards are never sent to the discard pile.
It would seem that played cards are not handled correctly.

Card Test 1 tested smithy function.  There really isn't too much here in terms of branches. According to gcov the
function ran 100% the first time.  The issues I ran into were problems related to the called function
discardCard().  While I have determined that discard does not work as intended, the coverage for it
was not 100%.  I would need to set up a seperate unit test, or provide extra test parameters that
would allow me to access every branch.

RANDOM TEST ADVENTURER
======================

In designing this unit test, I relied on my past experiences from random test design in Assignment 3.
I completely randomized all the bytes in the game structure.  From there I set some parameters based on
what was reasonable to expect to be passed into the function such as proper card types and non-negative
deck counts.  I compared the states before and after to get accurate information about what had happened
before and after the function ran.  We expected two more treasure in the hand and two less treasures
in the deck/discard.  The test looks for this event to have taken place.

To hit situations of perhaps more interest, I built in a percent chance where the hand/deck/or discard
might be empty.  Because of crashes in assignment 3, I already knew I couldn't have less than 2 treasures
in the entire deck/discard.  This is still the largest issue I've come across in the function.

Of interest, the random tester hit every line of code in the adventurer function as well as the contained
functions according to gcov.
 