Write up and check in the development of your random testers, including improvements in coverage 
and effort to check the correctness of your specification, as randomhistory.c. Be detailed and thorough!

Ashley Greenacre

This is the write up for assignment4, about randomtestcard.c and randomtestadventurer.c.

For randomtestcard.c, I wrote a random test for testing the smithy_card() function.  For this test
I used the Mersenne twister pseudo-random number generator to generate the random values to then
mod and add to, to create random values in the acceptable range.  I tried to use the rngs.c and rngs.h
as the random number generator and was unable to get it to produce a random number.  It would only produce
one value.  For both random testers I cycle through my tests 1000 times.  I test the handCount, discardCount 
and deckCount values.  I compare the calculated expected value to the actual value from the function.  Then 
report if the test fails or not.  I also check the other players values to make sure that the function doesn't 
mess with that and change it.  This test resulted in the same expected results as my unit test for it.

randomtester

Lines executed:18.23% of 576
Branches executed:17.75% of 417
Taken at least once:14.39% of 417
Calls executed:9.38% of 96

unittest

Lines executed:18.06% of 576
Branches executed:17.75% of 417
Taken at least once:14.15% of 417
Calls executed:9.38% of 96 

For randomtestadventurer.c, I wrote a random test for testing the adventurer_card() function.  For this test
I also used the Mersenne twister pseudo-random number generator to generate the random values to then
mod and add to, to create random values in the acceptable range.  I test the coin count, handCount, discardCount,
deckCount.  I randomly generate the card in the players deck and hand.  Then compare the calculated expected
values to the actual values returned by the function.  Then report if that comparison passed or not.  I again
also check the other players values to make sure that the adventurer_card() function doesn't change the cards of
the other player.  From this random test I found another bug in the bounding cases of the discardCount and deckCount
when there are no treasure cards, this resulted in some negative values sometimes.

randomtester

Lines executed:20.66% of 576
Branches executed:19.66% of 417
Taken at least once:17.27% of 417
Calls executed:10.42% of 96

unittest

Lines executed:20.66% of 576
Branches executed:19.66% of 417
Taken at least once:17.27% of 417
Calls executed:10.42% of 96

If you look at my coverage results, you will see that they are very, very close, between the unit tests and the random
tests.  Which makes sense, that the functions and calls these programs are using from domintion.c are the same.  
The only difference in my testing scheme is how the variables are getting set and checked.