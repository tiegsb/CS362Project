/******************************
Susan Lee
CS 362_400_Fall15
Assignment2 – Documentation.c
*******************************/


/*******************************
Smithy
******************************/
The smithy card enables the player to draw 3 cards from their deck.
It uses a loop to call the drawCard() function 3 times, and the 
function in turn returns a new card for the player to hold in their hand.  
After dispensing 3 new cards from the player’s deck, the discardCard() 
function is called to discard the played Smithy card from the player’s hand, 
to be reentered into the drawing pool.


/*******************************
Adventurer
******************************/
The adventurer card enables the player to go through the cards in 
their deck until they find 2 treasure cards.  It does this by 
looping through the deck until the drawntreasure count equals 2.  
Once inside the loop, it checks to see if there is at least 1 card 
in the deck to draw from, if not, it calls the shuffle() function 
to return shuffled cards from the discarded pile into the deck.  
Then it calls the drawCard() function to place another card in the 
player’s hand.  That card is then set to the cardDrawn variable, 
and inspected to see if it is a treasure card (copper, silver, or gold).  
If it is, the drawntreasure count is incremented, else the card 
is removed from the player’s hand to a temporary hand.

Once the player draws 2 treasure cards, the loop ends, and the 
other non-treasure cards that were revealed are discarded.  
This is done by looping through the temporary hand, and placing 
each card in the player’s discard pile.  

/*******************************
discardCard()
******************************/
This function takes 4 parameters: an integer representing the 
position of the card in the player’s hand, an integer representing 
which player is currently playing, a gameState struct representing 
all essential details of the current game, and an int representing 
whether the card is trashed, or goes back in play.  

The function first checks to see if the card in question should go 
in the played pile.  If the trash flag is not set, the card is 
placed in the playedCards stack and its count is incremented.   
Either way, the card is taken out of the player’s hand by setting 
its position to -1.  

The function then checks to see if the card is either the last 
card in the player’s hand array or if it is the only card, and 
decrements the total count of cards in that player’s hand.  
Else, it first replaces the card with the last card in the 
player’s hand array and then decrements the total hand count for 
the player.  


/*******************************
updateCoins()
******************************/
This function takes an int representing the current player, a 
gameState struct representing the state of the current game, and an
int representing the number of any bonus coins the player earned.

The function first resets the coin count to 0 for the current state
of the game.  It then loops through the player’s hand and adds the 
appropriate number of coins for any cards that are copper, silver, 
or gold.  There is no condition for card states outside of those 
listed, therefore no action is taken on the coin count for cards 
that are not copper, silver, or gold.  Once all the player’s cards 
are cycled through, any bonus coins passed in to the function will 
be added to the total.  
