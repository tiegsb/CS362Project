CS_362_Software Engineering
Assignment #2
thalijw

File name: refactor.c
Cards chosen: Adventurer, Smithy, Steward, council_room and remodel

Adventurer Code Changes:
In this code I made the while loop condition checks for three treasure cards instead of two, its a common mistake when doing
a while loop to mistake the condition, so now the Adventurer card will add three treasure cards to players hand


Smithy Code Changes:
I set the trashflage in the discardCard() to be 1 instead of 0, this way when the card played and discardCard() runs, it first
will check if the trashflage<1 to see if it was not trashed and added to the played pile, after the bug the if statement will fail
and the card will not be added to the played pile.


Steward Code Changes:
In this card the user can choose from three options, add two cards to hand, add 2 coins to player's coins or trash two cards
from the hand, I changed the add two coins option to take out two coins from the player.


council_room Code Changes:
In this card all the players will draw a card and add it to their hand cards, and the player who plays the card will have + buy 
a new card.
I changed the code to make the player who played the card is the only one who is drawing the cards by changing the if statement 
condition from ( i != currentPlayer ) to ( i = currentPlayer ).

Remodel Code Changes:
In this card the player will trash one card from his hand and gain another card that costs two more coins that the card he trashes.
I changed the code to select a new card that is less in value from the card that is trashed by changing the condition to execute
the if statement to check the card's values with getCost() function, Now the code will check if the card will be trashed +2 is "<"
the now cost of the new card, then it will change the cards.


