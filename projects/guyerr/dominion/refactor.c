Adventure Card:
In order to incorporate a bug into the adventure card execution statement I decided to eliminate the statement where the deck is reshuffled if there are not enough cards in the deck. This seems like an interesting bug to me because I know errors of ommision can be difficult to track down and it will only occur in special cases - the adventure card tries to pull a card from the deck but the deck is empty.
Smithy Card:
I added in an if statement that checks to see if hand position is greater than 2. If it is then handPos is decreased by one, if not then handPos remains the same.
Great Hall Card:
An if statement was added such that the number of drawn cards will depend on the hand position of the card played. If the hand position is even then the player will draw two cards. If the hand position is odd then the player will only draw one.
Village Card:
The regulat game is setup so that the village card allows the player to draw one card and lets the user use two actions. I have added in that any time this card is played, the number of coins for the player will be set to four.
Outpost Card:
The discardCard function has been removed.