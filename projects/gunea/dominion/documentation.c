/******DOCUMENTATION.c******

Smithy card:
When the playCard() method is called, the program calls cardEffect() to determine
which effect the card has. cardEffect() uses a switch control structure to assign
functionality based on which card was played. If the card was a Smithy, the function
draw three cards by calling the drawCard() function three times using a for-loop.
cardEffect() discards the top card by calling discardCard(), and then returns
control to playCard().

Adventurer:
The adventurer case follows a similar control structure to Smithy. playCard() calls
cardEffect(), which uses a switch. The adventurer case has a while loop that executes
as long as the number of drawn treasures is less than two (using a treasure counter
variable). If the deck is empty, it shuffles, discards, and adds the hand to the deck.
It then sets the card drawn to be the first card of the hand. If the drawn card is a 
treasure, it increments the treasure counter. Else, it sets the drawn card into a
temporary hand array, and decrements the hand count variable (removing the drawn
card from the hand). The first while loop then ends or iterates. The second
while loop then begins, discarding cards in play; this iterates as long as
the temp hand still has cards in it. The loop then ends and returns control
of the program to playCard().
*/
