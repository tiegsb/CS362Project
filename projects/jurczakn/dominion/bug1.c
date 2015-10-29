
scoreFor(): The function fails on every attempt where the deck is larger than the discard pile.  It fails most of the time when the deck is smaller than the discard pile.  It only runs consistently when the deck and discard are even.  Looking at the code, this is due to the fact that the deck is being read up to the number of cards in discard, not the number that is actually in the deck, so if the deck is larger, cards are not being read, but if the deck is smaller, extra values, most likely the deck count array, and then cards from the discard, are being counted.

getWinners(): All test for getWinners ran successful.  Function uses scoreFor() function, which was already found to be buggy, so test also uses scoreFor() function.  The getWinners() function itself has not been found in this test to contain bugs.

isGameOver(): When emptying three cards that are not in use in the partucular game, the function still interprets the game as being over.  This means the function is still checking these non-used action cards when looking for empty piles.  The function should be changed to only look at cards that are in use.

fullDeckCount(): All tests ran successfully.  There were no bugs found by this test.