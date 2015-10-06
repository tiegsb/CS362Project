/*John R. Toth
*CS362 Assignment 2
*tothj@oregonstate.edu
*refactor.c
*/

/*
Introducing bugs into 5 cards. 

Smithy:

The Smithy card is an action card, allowing a player to draw 3 cards when played. Once the Smithy 
card is played, the function drawCard() is called 3 times. Afterwards, the discardCard() function is 
called, thus closing out the Smithy card functionality.
For the Smithy card bug, I added the discard function, immediately passing the drawn card to the discard
pile.

Adventurer:

The Adventurer card, an action card, allows the holder to reveal cards in their deck, until they reveal 
2 treasure cards. Once the user has pulled the second of their two treasure cards, they are allowed to 
then discard the other revealed cards.
For the Adventurer bug, I've swapt the second if statement in the implemtnetation so that if a copper, 
silver or gold card is drawn, the current player's handcount is decremented. The proper code has been 
swapt with the else statement below it. The new implementation of the else statement will decrement the 
player's currnet treasure count, with each card drawn.


Council Room:

The council room allows a player to draw four additional cards, increase buys by 1 and each other player
is allowed to draw a card. 
For the council room bug, I changed the initialization of the initial "for" loop to 1, while leaving the upper limit
at 4. I find this to be one of those annoyingly common mistakes that everyone makes. While there are no catastrophic 
changes to gameplay, the player will be shorted 1 card, while at surface level, the code looks correct. 


Mine:

The Mine card allows a user to trash a trasure card and gain a treasure card worth 3 or more, in it's place. 
Keeping with the treasure element of the Mine card, I've embedded an additional treasure into the code. I'm allowing the 
player to gain an additional 4 coins when they attempt to discard the exact card they selected to trash. Although the code
will still not allow the player to keep their card, they will benefit from 4 extra coins. The foriegn code is located on 
the last for loop, of the mineCard implementation.

Minions:

The Minion card allows a player to select either +2 coins or to discard their hand. The other benefit to this card is that
your opponents, if they have 5 cards in their hand, must discard their hand and draw 4 new cards. In the many rounds of 
playing this game, I've only seen the availability of this card, once. 
Given how infrequent this card is actually used on the gameboard, I've chosen to make a small adjustment to the trigger for 
the opponents complete discard of their hand. As mentioned above, the opponent must have at least 5 cards in their hand for this
benefit to trigger. I've changed the code to be enacted if the opponent has 3 or more cards. This slight advantage will
likely ensure a guaranteed opponent reset of the cards in their hand, each time it is played. The bug is within the last if 
statement on the minionCard implementation.
*/

