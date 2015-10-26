------------
Unit Test 1:
------------
Interestingly enough, when I ran gcov on UnitTest1 for the first time,
I found that I was not covering all code with my random tests.  The discovery
was that I had actually inadvertantly created a poor design for one of my random functions
and it had caused the number of players to always be 2 which ran otherwise as expected.

Once I corrected this mistake, the coverage for all lines (aside from the test conditions for other
function calls) went up.  No bugs were discovered within the initializeGame code.


------------
Unit Test 2:
------------
Now with a little experience, unit test 2 was a bit easier to put together.  This fuzzes a game state,
copies the game state runs the shuffle function in dominion.c, and compares the game state.  We'd
expect to see the games states to be the same, except for the values in deck[player] array which
usually will be in a different order.

No bugs were discovered in running the test.  GCov revealed that 100% of the function was covered in
10,000 trials.  This did not require too much consideration from me doing random testing.  The only
valid inputs I had to insure were the player number and the deck range so that there were no
overflows (other functions take care of this input validation).


------------
Unit Test 3:
------------
Unit 3 is testing isGameOver.  10000 random trials covers all code in the function.  It would
appear there is a bug... the gameOver function loops from cards 0 to 25.  There are 27 cards.
The real issue is that the coders of this particular game should have modified their enum such
that there were a NUM_CARD_TYPES at the end.  That way, when cycling through cards in a loop,
instead of hardcoding values (or using treasure_map+1), they would simply just use the constant.
Now if cards are added (as apparently happened), a coder would not have to search through lines
upon lines of code to fix the issue.

------------
Unit Test 4:
------------
Unit 4 tested scoreFor() function, a function that calculates the total score of a player.
The unit test immediately reported an error in nearly every case.  It would appear that garden
score calculation was poorly implimented.  While garden is supposed to give a point for every 10
cards a player owns in the deck, hand, or discard, by using the function fullDeckCount() in it's
equation, it ends up having problems.

fullDeckCount looks to be something of a poor evolution of a function with poor or outdated
documentation.  The header file states that fullDeckCount returns deck+hand+discard... in which
case scoreFor should work.  However, fullDeckCount clearly only counts the number of a particular
card.  It's possible that the functionality of fullDeckCount had changed from its original meaning.
That is to say, fullDeckCount(player, 0, gs) only counts the number of curse cards in the deck, hand,
and discard pile.

gcov showed that 100% of the function was covered.

------------
Card Test 1:
------------
Card Test 1 tested smithy function.  There really isn't too much here in terms of branches.  The
function ran 100% the first time.  The issues I ran into were problems related to the called function
discardCard().  While I have determined that discard does not work as intended, the coverage for it
was not 100%.  I would need to set up a seperate unit test, or provide extra test parameters that
would allow me to access every branch.

------------
Card Test 2:
------------
Card Test 2 tested the adventurer function.  Here, the only test I designed to NOT be random, but
rather, to follow the branches and test cases for the function.  As such, 100% of the function
runs 100% of the time.  However coverage isn't everything.  It doesn't explain what the function
doesn't account for, such as what if the player has no more treasure cards??  This is a test
case I set up that the function as written could not pass.
