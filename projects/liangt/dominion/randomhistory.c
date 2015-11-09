/*

Adventurer:

My adventurer test began with four tests:
- Check net hand count is 1 more than original
- Check that last two cards in hand are treasure cards
- Check adventurer card is on top of discard pile
- Check net total of deck + discard is 1 less than original

However, this does not check for the bug that I introduced, which was not to
count silver cards as treasure cards. To check for that, my code then tallies
how many of each treasure card the function drew and displays the results in the report
for the reader to interpret. In this case, it correctly displayed zero silver
cards drawn with about 10000 each of copper and gold. This was expected given
10000 calls of the adventurer function.

Also, originally I only outputted the total subtests passed. Then I included how many
of each subtest passed.

Village:

Originally I had just two subtests for this function, the realized the
last two tests for adventurer could be easily adapted to this function as well.
I was really surprised the actions test passed, though that is perhaps some other
part of the game engine has a bug or hasn't been run yet.

*/