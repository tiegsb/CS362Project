// Tony Huynh	CS 362	Fall 2015	randomhistory.c
/* Documentation:

In my random testers, the only thing that I have that is random is the iteration.  For both my randomtestcard.c (testing Village card) and randomtestadventurer.c, I keep a random iteration from 1-3, although it could probably go up a bit higher.  The iteration can't go too high, because the way I coded this, the number of iterations is based on the number of cards available in the game.

randomVillage (randomtestcard.c): In this test, I added the random factor I described above.  Aside from checking just for the number of cards in hand and checking the number of actions awarded (from last assignment), I added in a check for the number of cards in the deck.  With the check I inserted, it sometimes provides a message that a test has failed.  I was excited to find this message, but thought about it a bit more.  I then realized that the error message was false- we have a limited number of cards our initial deck, so if we draw at least 3 cards, we'll get an output that says we have less than 0 cards in our deck.  Realizing this, I was at first disappointed.  My disappointment is slightly alleviated when I realized what this tells me- we at least know that the game's actual function can take into account an empty deck, so when we try to draw more from it, it doesn't become negative- it remains zero.
As it is right now, I have not found any bugs in my script with the method of random testing- I have some doubts if I am doing this right.  I hope to get feedback on this soon.

randomAdventurer (randomtestadventurer.c): In this test, I did the same thing I did in randomVillage, and that was to input a random number of adventurer cards drawn into the user's hand.  In this updated test, I am now checking to see if the last two cards in the hand are treasure cards.  I can confirm that this test is reliable- when I add a non-treasure card into the hand AFTER the other testing of this test unit, I get the test fail message of checking the treasure cards.  Like the previous random test for the village card, I could not find any new errors through this new method of testing.  

---------- 
HW 3 test stats
cardtest3.c: (village)
Lines executed:24.35% of 616
Branches executed:26.46% of 427
Taken at least once:15.93% of 427
Calls executed:18.81% of 101

cardtest2.c: (adventurer)
Lines executed:23.05% of 616
Branches executed:26.93% of 427
Taken at least once:16.39% of 427
Calls executed:16.83% of 101

(11/5/2015)
Random test stats
card: (village)
Lines executed:24.35% of 616
Branches executed:26.46% of 427
Taken at least once:15.93% of 427
Calls executed:18.81% of 101

adventurer:
Lines executed:23.21% of 616
Branches executed:26.93% of 427
Taken at least once:16.63% of 427
Calls executed:16.83% of 101
----------

Looking at the code above, my new village test doesn't cover anything new compared to the old test. 
For my adventurer test, we can see slight improvements. There is a small percentage increase for the percentage of lines executed and the "taken at least once" section.  While the increase is seemingly small, I believe this is at least an improvement of my coverage.

After reading a few other comments on Piazza, I will try to test other conditions of the game, conditions that may seem trivial.  This should help me increase the lines covered in both the tests.

*/