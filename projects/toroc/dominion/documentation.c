/*
Carol D. Toro
CS 362
Toroc@oregonstate.edu
#932676028



Documentation

Smithy: Smithy is an action card that draws three additional cards into the player's hand. 
When the Smithy card is played the function drawCard() is called three times. The Smithy
card is then discarded from the user's hand with a call to the function discardCard().


Adventurer: Adventurer is an action card that reveals cards from the player's deck until 
two treasure cards are revealed. The treasure cards are added to the player's hand and
then the player may decide to discard the other cards that were revealed. If the user's
deck is empty, the call to the function shuffle() shuffles the discard pile and adds it
back to the deck. If the user's deck is not empty, the drawCard() function is called to
draw the top card of their deck and the top card gets added to the user's hand. If the 
card drawn turns out to be a treasure card, the drawntreasure variable is incremented by 1.
Otherwise, the card drawn gets added to temphand at position z, the card drawn gets removed
from the user's hand, and z is incremented by one. This is continued until the user has
drawn 2 treasure cards. Once the user has drawn the 2 treasure cards, the cards in temphand
are discarded one by one until z is back at 0. 


discardCard(): Helper function


updateCoins():
*/