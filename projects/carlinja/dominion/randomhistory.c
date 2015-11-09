James Carlin
Assignment 4

RandomTestCard.c

My randomtestcard.c test had a total of 51.03 percent coverage. I decided to test deck counts for this test, as the card is supposed to have change the total hand count.
I decided to input random numbers, with a value of at least five, and iterate that 50 times. I chose 50 based on the professor asking for something that takes less than a minute to run
I did a test with 1000 and got similar results, but chose to turn the project in with 50 iterations.

All of my tests failed, which is intentional. The bug I introduced to the function during the second assignment changed the way the hand count was decided within the function. 
I chose to test this card to ensure that my bug did the correct thing and failed each time.

When I changed the values I was looking for, I was able to get the test to pass.

In my mind, this means that my test actually works, as it's finding a bug, although it is one that I introduced.

THe random tester gets 100 percent branch coverage, as well as statement coverage.


Randomtestadventurer.

Similar to my first test, this one has 50 percent coverage. I decided to look at hand counts for this one.

My tests fail everytime for this card as well. After looking over my coverage and my test, I realized this function has a bug written into provided by the professor.

The function does not discarding the card of the player. After the adventurer card is played, it SHOULD be discarded. This function does not discard the adventurer card.

What is happening is the discard function is not adding discarded cards to the correct array, it is adding to playedCards instead of discarded array.

