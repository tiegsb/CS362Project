// Tony Huynh	CS 362	Fall 2015	bug1.c
/* Documentation:

In my tests, I tried to keep most of them simple and basic.  On a couple of unit tests,
I wanted to try some random testing, so I used the rand function to see if it's possible I break
some code that was already implemented.  All the unit tests seemed to check out just fine.

On the card tests, it was expected that the adventurer and smithy has flaws, since we were supposed to 
alter the code during assignment 2.  I also tested another card that I refactored myself and was able to 
find flaws in it.  I saved the final cardtest file for a card function that was untouched. That test checked
out fine.
One thing I noticed was how the adventurer/smithy cards were coded compared to some of the other ones.  It
might be that I did the tests wrong, but I noticed that the way I had to check for the number of cards from
the adventurer and smithy cards was different for some of the other tests. 
For example, let's look at the smithy card. At first, I took the current number of cards in the player's hand.
After playing smithy (allows player to draw 3 cards), I added three number of cards to the player's
current hand number.  This logic is flawed- if I played smithy, I lose a card, then I gain three cards.  The 
net gain would be two cards.  I realized this as I was making a test for village, the non-required card to test.
Applying this logic to smithy/adventurer seemed to cause some tests to pass when it shouldn't have.  I made
my tests to ensure the adventurer/smithy failed, and document that issue here.

Overall, I was able to catch flaws to three of my refactored cards and was not able to catch a flaw in
one of the un-refactored card.  All unit tests checked out just fine.

*/