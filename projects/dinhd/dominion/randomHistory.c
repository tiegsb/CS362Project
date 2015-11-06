Dustin Dinh
CS 362 Assignment 4

***********************************  Adventurer  ***********************************
Lines executed:25.51% of 639
Branches executed:26.57% of 463
Taken at least once:18.36% of 463
Calls executed:19.23% of 104

Initially I wanted to randomize these variables:

1) the deck with a constant deck size of 30.

However, I realized that after running gcov that I was not covering all my branches 
in the adventurer function, in particular the function that checks to see the deck is
out of cards. As a result, I introduced these random elements:

2) deck size

3) card that hand plays from.

I did not randomize the cards in hand because this test is testing the actual code inside
of adventurer, and not testing to see if calling adventurer when it doesnt exist will
result in an error.  

In my first cardtest, I did not cover conditional statements. The first was the conditional
IF conditional to check when the deck ran low on cards. The second was based on not
drawing a treasure card. I corrected both by randomizing both the deck size and the deck
composition for every iteration of my test.

This would not have been possible for my non-random unit test unless I had implemented a lot
more code. 

I used a more rigorous method to check the correctness of function by writing a more robust
Oracle than before. The new oracle calculated the amount of money in hand, the discard pile,
and the hand size. In addition, I used the print statements found in interface.c to print
before and after information in order to manually check all values on a few test cases.
As a result, I discovered new bugs with the adventurer code that was not
discovered in previous code reviews and tests. 

Additional Bugs Found: The adventurer card does not discard itself. It remains in hand.
In addition, its supposed to go into the played pile but it does not.

If there are no treasure cards in the deck to be drawn, the the adventurer card will
be stuck in a while loop. 


***********************************  Smithy  ***********************************
Lines executed:20.97% of 639
Branches executed:23.11% of 463
Taken at least once:14.47% of 463
Calls executed:15.38% of 104

Smithy was covered very well in the previous test. As a result, I wanted to dig 
deeper into the actual variables that Smithy touched. In addition to counting
the cards that were drawn, I made an Oracle that peeked into the deck to keep
track of the cards that would be drawn when smithy was played.

As a result, I discovered new bugs with Smithy that ws not discovered in previous code
reviews and tests.

Additional Bugs Found: 
1) When smithy calls Discard, it does not actually discard cards into
the discard pile. It only adds cards to the played pile. 

Issues: because the deck size is random and can possibly have less than 3 cards, my test would 
fail because it relied the deck having at least 3 cards. If a deck had less than 3 cards,
the function would look at indexes less than 0, which would fill the expected cards array with
garbage data. As a result, I had to go back and introduce a conditional to prevent this
when there was less than 3 cards on line 103. 