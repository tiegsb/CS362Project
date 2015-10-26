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
10,000 trials.


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

CARD TEST 1
===========
In this card test, we are testing the functionality of the smithy card.  As it turns out, the bug
I attempted to introduce in Assignment 2 didn't actually bug the program in the way I thought it
would.  In any case, the glaring issue that was caught by cardtest1 was the problems associated with
the discardCard function.  As it would turn out, discardCard function does not actually place
discarded cards into the discard pile.  Rather, the cards are instead listed as played.  This would
not be a problem if it weren't for the fact that the cards are never sent to the discard pile.
It would seem that played cards are not handled correctly.

CARD TEST 2
===========
This card test covers the adventurer card.  I had forgotten the really annoying bug I had implemented
in the last assignment which caused lots of trouble in this particular test.  I had to find and revert
the bug in order to insure the unit test was correct.  Another revealled bug is that playing the
adventurer does not know how to handle when there are less than 2 treasure cards available.  While
this is probably a rare occurance, it would not be unheard of.  The behavior is undefined.

Another issue with the adventurer card is that it doesn't follow the pattern of self-discarding as
some of the other cards seem to do.  I'm not sure what the programmer's intentions were in terms of
how to discard (and where to discard) a played card.

CARD TEST 3
===========
N/A - I was unable to complete CARD TEST 3 in time.



CARD TEST 4
===========
N/A - I was unable to complete CARD TEST 4 in time.
