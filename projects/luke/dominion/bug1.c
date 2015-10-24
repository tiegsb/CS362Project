/*
Kenny Lu
CS 362
Assignment 3
bug1.c

This file will document the bugs that I've found in the dominion.c code after running various
unit tests.

1) The first bug that I found was in cardtest1.c which involves testing the smithy card.  We
expect the new hand to be 2 ore cards than the original hand because 3 cards are drawn but the 
smithy card is also played.  From our result, the old hand has 5 cards and the new hand has 6
cards.  This is a gain of one card and not 2.  As we see in our code in dominion.c, a bug in the
for loop of that function where i starts incrementing from 1 and not 0 causes this.

2) The second bug that I found was in cardtest2.c which involves testing the adventurer card.
The test case that tests that 2 cards (1c ard gained in hand because of this one played) are 
added in the player's hand fails.  From our unit test, we can see that the old hand count is 5
and the new hand count is 8.  This means that 3 cards are being added instead of just one. This
could be from a card not being discarded correctly and the fact that the first while loop
exits at the wrong place yielding more cards added than necessary.

3) The third bug found was in cardtest3.c which involves testing the village card.  We expect 
a +1 card to take place (which balances out to nothing being added because the village card 
is played).  Our unit test shows that the old hand count is 5 and the new hand count is 6 when
they both should be equal numbers.

4) The last bug I found was inc cardtest4.c which involves testing the steward card.  The
wrong cards are removed when the trash 2 cards option is picked.  This could be from the function
removing cards from the wrong position ;).

*/