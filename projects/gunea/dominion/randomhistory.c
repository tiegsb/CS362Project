/******RANDOMHISTORY.c******

Cards tested: Adventurer, Great Hall

Development:
Development for these testers hinged on initializing the 
game with randomly developed variables. The "game state" struct
was initialized with a random seed every time. Additionally,
many of the function calls were performed with random values
passed as parameters. However, to ensure that the test cases
were not trivial, I put bounds on the random generation so that
rand() would only generate random values that would make sense
within the functionality of the game. For example, the 
Great Hall function takes an integer as the hand position
to be discarded. I used rand() to generate a valid integer 
for this function. 

Similarly, with the Adventurer card, I used random number
generators to come up with the cards for each player's hand.
I then ran both tests 100 times in main(). 


Coverage:

File 'randomtestcard.c'
Lines executed:96.08% of 51
randomtestcard.c:creating 'randomtestcard.c.gcov'

File 'randomtestadventurer.c'
Lines executed:91.38% of 58
randomtestadventurer.c:creating 'randomtestadventurer.c.gcov'

File 'dominion.c'
Lines executed:32.99% of 579
dominion.c:creating 'dominion.c.gcov'

There were no real improvements in coverage from the unit test,
but the line coverage increased by around 1-5%, partly due to 
the random generation of values.

Correctness:
I checked the correctness of the test by using print statements:
-In Adventurer, the test would fail if the card was not added to
the hand, the treasures were not drawn correctly, or the Adventurer
card was not discarded at the end of the function call.

-Similarly, in Great Hall, the test would fail if the number of actions
was not incremented, a card was not added to the hand, or the card
was not discarded after the function call. Testing yielded the 
expected bugs based on refactored functionality


*/

//end of randomhistory.c