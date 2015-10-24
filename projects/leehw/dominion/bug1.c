/******************************
Susan Lee
CS 362_400_Fall15
Assignment3 – bug1.c
*******************************/

Unit Tests for functions: getCost, shuffle, updateCoins, drawCard
The Unit tests for thes functions revealed no bugs.

UNIT TESTS FOR CARDS
/**************
Smithy Card
***************/
The unit tests for this function were run on a variety of inputs, where the Smithy
card was placed at the front of the player's hand, at the end of the player's hand,
and somewhere in the middle of the player's hand.  The deck was set to a deck count
of 10 across all 4 players, but with various cards in each deck.

All of the players exhibited the same failures, indicating that the bug in the code
is pretty significant.  All players had 1 more card in their hand than expected, and
1 less card in their deck than expected.  This indicates that the player is drawing
1 more card from their deck than expected.  This was further confirmed by failure of 
the expected last card added to the player's hand.  The test took into consideration 
that the last card added to the hand will replace the smithy's hand position 
(as a part of the discardCard function).

The tests indicate that the count of Smithy cards in the player's hand did indeed 
decrease by 1 as expected(assuming that no new smithy cards were added to the player's
hand in its draw).  However, the discard count did not increase by 1, which indicates
that the Smithy card was indeed removed from the player's hand, but not placed in the 
player's discard pile to be recycled for later use.

Testing outside factors:
The hand counts for the other players were not affected, confirming that the call to
function did not unwantingly alter the hands of the other players.
The coins count was also not altered.

**NOTE**
I removed the previously introduced bug of passing the gamestate struct by reference.
I was getting seg fault errors, and it was inhibiting my ability to properly test the
cases that I had written for the test suite.  I justify this by stating that in a real
test environment, I would have noticed the bug in the code and fixed it so that I could
test for other bugs.  

/**************
Adventurer Card
****************/
The unit tests for this function were also run on a variety of inputs for the number
of treasure cards in the hand.  I tested for when there are 0 treasure cards in the deck, 
when the deck is filled with only treasure cards, when the deck is filled with only 
2 treasure cards, and a normal case of when filled with more than 2, but less than the max.
The deck count was set to 10 across all players.  The hand count was set to various inputs
with various values populating the deck.

All of the players, except the player who had 0 treasure cards in their deck
exhibited the same failures.  The player with 0 treasure cards had the expected hand count
(as no additions or deletions from the hand was expected), however, the deck count came to -2.
The expected deck count was calculated by the total pre-change deck count minus the number
of iterations through the treasure loop.  This leads me to believe that the treasure loop 
is not exiting when expected, and should either include some sort of exit condition for when 
no treasure cards are found in the deck, or when the deck has been exhausted.  

For the non-boundary conditions, the hand count was 1 more than expected, the deck count was as
expected, and the discard count was 0 across the board.  After further investigation into the
hand count, it appears the the adventurer function does not call a discard function to remove
the adventurer card from the player's hand.  This explains why the hand count is incorrect,
but the deck count is as expected.  This is further proved by the adventurer count being 1 more
than expected pre and post function call.  

I expect all the cards that were picked from the deck and not treasure cards to be placed back in 
the discard pile, however none of them were.Since the discard count is 0 across the board, this 
leads me to believe that there is a bug in the code that moves the cycled non-treasure cards to 
the discard pile.  

Testing outside factors :
The hand counts for the other players were not affected, confirming that the call to
function did not unwantingly alter the hands of the other players.
The coins count was also not altered.

***NOTE****
I added some code to the refactored Adventurer function to change the return value of the function.
The return value now returns information that is useful in my test suite/debugging.  Again, I 
justify this by the fluid nature of the testing environment, and the need to alter or reconsider
things as you are testing so that you may have a more robust testing session.


/**************
Council Card
****************/
The unit tests for this function were run on a variety of inputs, where the Council
card was placed at the front of the player's hand, at the end of the player's hand,
and somewhere in the middle of the player's hand.  The deck was set to a deck count
of 10 across all 4 players, but with various cards in each deck.

All of the players failed the same tests.  The hand count was 1 more than expected,
and the deck count was 1 less than expected.  This indicates that the player drew 
1 more card than allowed from their deck. This is further confirmed by the fact 
that the last card added to the player's hand is not as expected.  This again takes
into consideration that the council card is replaced by the last card added to the 
player's hand.

The number of buys was as expected across the board.  

As exhibited in other tests above, the count of council cards in the player's hand
is decremented as expected(assuming no new council cards in the player's hand), however
the discard count is not incremented.  This leads me to believe that the bug is in 
the discardcard function and not these card functions.

Testing outside factors:
We expect every other player to draw a card from their deck into their hand, however
the tests show that the handcount is 1 less than expected, the deckcount is 1 more than 
expected, and the "added" card at the end of the player's hand is not as expected.  
This indicates that the other players are not getting the extra deck draw as expected, 
and clues us into where we can find the bug for the current player receiving an additional
draw while the other players do not.  

Again, testing random coins count, shows that this is not affected by the card function.


/**************
Village Card
****************/
The unit tests for this function were run on a variety of inputs, where the Village
card was placed at the front of the player's hand, at the end of the player's hand,
and somewhere in the middle of the player's hand.  The deck was set to a deck count
of 10 across all 4 players, but with various cards in each deck.

All of the players failed the same tests. The hand count, deckcount, and expected 
added card were all as expected.  However, the number of actions was 1 less than 
expected.  Since all players started with the same number of actions, and upon further
investigation in the code, it appears that instead of incrementing the number the actions, 
the code is simply hard coding it to a value of 2.  

The post/pre hands indicate the appropriate number of village cards, however the discard
count was not incremented.As we've seen in the above functions, there is clearly an 
issue with the discardCard function.  

Testing outside factors:
As expected, there were no changes to the other players' hand or deck counts.  I also 
tested to ensure that the coins count was not changed, and it indeed was not, indicating 
things outside the scope of the function were not altered.  
