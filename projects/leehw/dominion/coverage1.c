/******************************
Susan Lee
CS 362_400_Fall15
Assignment3 – coverage1.c
*******************************/

Total coverage
File 'dominion.c'
Lines executed : 33.68% of 570
Branches executed : 30.22% of 417
Taken at least once : 27.58% of 417
Calls executed : 17.89% of 95
Creating 'dominion.c.gcov'

Total coverage could definitely be improved.  I chose a variety of functions 
to demonstrate different things.The getCost() function may seem trivial, but
it is essential to test and ensure the accuracy of smaller functions so that
you can build on them with  more complex ones.  I definitely could increase 
the boundaries I'm testing to get more comprehensive coverage of various 
inputs.  I could also vary the actual content/structure of each individual 
player so that  different scenarios are tested.  This test suite was more
purposeful to ensure that controlled cases are behaving as expected.  In
another iteration of test suites, I would implement some random testing to
get more varied players and to test for normal test cases.

/*************************
unittest1 - getCost()
**************************/
File 'dominion.c'
Lines executed : 5.26% of 570
Branches executed : 6.71% of 417
Taken at least once : 6.71% of 417
Calls executed : 0.00% of 95
Creating 'dominion.c.gcov'

This level of coverage allowed every scenario to be touched and ensured
that the function is returning the desired values every time.Even though
there isn't much going on in the function, ensuring that these smaller peices
are working as expected allows us to be confident in our use of it in other
more complex functions.

Statement Coverage: 
Called 29 times, returned 100% blocks executed 100%

Branch Coverage:
Every branch was covered, and each one was executed the same percentage.  
This is due to the fact that my testing called each card once, and used
to boundary cases.

Boundary Coverage:
My code tested each value in the code, and tested two values that were
out of bounds (a large number and a negative number).


/*************************
unittest2 - shuffle
**************************/
File 'dominion.c'
Lines executed : 21.05% of 570
Branches executed : 22.54% of 417
Taken at least once : 19.90% of 417
Calls executed : 7.37% of 95
Creating 'dominion.c.gcov'

This level of coverage allowed each edge case to be considered, and some
cases where invalid input is used.  It also tested some normal inputs.

Statement Coverage :
Called 88 times, returned 100% blocks executed 100%

Branch Coverage :
Every branch was accessed, due to my testing of edge cases.I think I'll
include more common cases in my testing to ensure the function works well
as intended(for usual cases).

Boundary Coverage :
My code tested for when there is 0 cards in the deck to shuffle, the edge case
of just 1 card, and the out-of-bounds case of -1.  I also tested for the boundary
case of the deck holding the maximum allowed (as defined in the game).  

/*************************
unittest3 - updateCoins
**************************/
File 'dominion.c'
Lines executed : 21.40% of 570
Branches executed : 22.54% of 417
Taken at least once : 20.38% of 417
Calls executed : 7.37% of 95
Creating 'dominion.c.gcov'

This level of coverage allowed each edge case to be considered, and some
cases where invalid input is used.  It also tested some normal inputs.
I'd like to test for a mixed bag of coins including bonus, as well as 
exclusive coins with bonuses.  

Statement Coverage :
Called 37 times, returned 100 % blocks executed 100 %

Branch Coverage :
Every branch was accessed, due to my testing of every coin type in game.
It tested for all gold, all silver, all copper, and for a mixed bag.

Boundary Coverage :
My code tested for when there were no coins associated with the player, tested for coins
that were more than the max allowed by the program, and tested for max number of coins 
for the hand including a bonus. 


/*************************
unittest4 - drawCard
**************************/
File 'dominion.c'
Lines executed : 23.68% of 570
Branches executed : 23.50% of 417
Taken at least once : 21.34% of 417
Calls executed : 8.42% of 95
Creating 'dominion.c.gcov'

This level of coverage allowed each edge case to be considered, and some
cases where invalid input is used. It also tested some normal inputs.
I'd like to test for more scenarios involving the status of the discard pile.
I'd also like to test some more cases involving the boundaries of the hand count.
I think including these cases that aren't directly noticeable will help reveal
any strange behavior or patterns that may not be immediately apparent. 

Statement Coverage :
Called 179 times, returned 100 % blocks executed 100 %

Branch Coverage :
Every branch was accessed, due to my testing for various scenarios of deck status.

Boundary Coverage :
My code tested for edge cases where there were 0 cards, negative cards, or max cards
in the deck.  It also tested for the case where there are 0 cards in the hand.  

/*************************
cardtest1 - smithy
**************************/
File 'dominion.c'
Lines executed : 27.72% of 570
Branches executed : 25.90% of 417
Taken at least once : 23.50% of 417
Calls executed : 10.53% of 95
Creating 'dominion.c.gcov'

This level of coverage allowed for variety in behavior of the internally called
upon functions.  Since the discardCard function requires a handpos to remove 
the smithy card, and rearranges the player's hand  accordingly, I felt it was
necessary to test the cases where the smithy card was in different locations in 
the hand.I'd like to extend my coverage by testing the edge cases for other 
considerations like max hand count, 0 card counts, negative inputs etc.  

Statement Coverage :
Called 4 times, returned 100 % blocks executed 100 %

Branch Coverage :
Every branch was accessed, which indicates no unexpected failures in the code.

Boundary Coverage :
My code tested for cases where the smithy card was at the beginning of the hand
and the end of the hand.  Since the handpos of the card is being passed into the
smithy function, it seemed pertinent to test those edge cases corresponding to 
index position.

/*************************
cardtest2 - adventurer
**************************/
File 'dominion.c'
Lines executed : 31.05% of 570
Branches executed : 28.78% of 417
Taken at least once : 26.14% of 417
Calls executed : 12.63% of 95
Creating 'dominion.c.gcov

This level of coverage could be improved.  One reason for the poor coverage is 
actually due to a bug in the code and causes one portion to not execute.  So 
while there is a failure in code coverage, the failure actually points towards 
a bug in the code, so the tests were indeed successful regardless of the poor
coverage indicator.I'd like to increase the variety of inputs being tested, 
namely the coins used in the player's decks.  Also some more edge and invalid
inputs would help round out coverage.

Statement Coverage :
Called 4 times, returned 100 % blocks executed 93 %
The statements surrounding the bug in code were not executed.  This is to be
expected as the variable was not properly incrementing, which caused the while
loop dependent on that variable to not execute.  

Branch Coverage :
Two branches were not accessed.  The reason for one branch is discussed in the 
statement coverage above.  The other was not accessed because I did not include
all treasure values in my players' decks.  However, since the statement only 
needs one of them to be true to satisfy the condition, this isn't the worst thing
in the world.

Boundary Coverage :
This card does not actually call the discardCard function, so no need to focus 
edge cases on index values.  I did, however test for when there are 0 treasure
cards in the deck to examine behavior.  I also tested for when there are ONLY 
treasure cards in the deck.

/*************************
cardtest3 - council_room
**************************/
File 'dominion.c'
Lines executed : 32.81% of 570
Branches executed : 30.22% of 417
Taken at least once : 27.58% of 417
Calls executed : 15.79% of 95
Creating 'dominion.c.gcov'

This level of coverage could be improved.  I should include more boundaries for
the number of players in the game, the number of cards in the deck and in the
player's hand, and for the number of starting buys for each player.  

Statement Coverage :
Called 4 times, returned 100 % blocks executed 100 %

Branch Coverage :
All branches were accessed due to the fact that an appropriate number of players
was used for the testing(>1).

Boundary Coverage :
Again, this function calls the discard card function, so I tested the boundaries
of the index values.  

/*************************
cardtest4 - village
**************************/
File 'dominion.c'
Lines executed : 33.68% of 570
Branches executed : 30.22% of 417
Taken at least once : 27.58% of 417
Calls executed : 17.89% of 95
Creating 'dominion.c.gcov'


This level of coverage could be improved.I should include more boundaries for
the number of players in the game, the number of cards in the deck and in the
player's hand, and for the number of starting actions for each player.  

Statement Coverage :
Called 4 times, returned 100 % blocks executed 100 %

Branch Coverage :
There are no conditional statements in this function, therefore no alternative
branches to consider.  The entire peice of code was executed as a result.

Boundary Coverage :
Again, this function calls the discard card function, so I tested the boundaries
of the index values.