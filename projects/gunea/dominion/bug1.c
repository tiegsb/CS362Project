/******BUG1.c******

The unit tests ran successfully without any bugs.
I tested the updateCoins(), buyCard(), gainCard(),
and isGameOver() functions, and they all ran
successfully without revealing any major bugs.

I found several bugs in the refactored versions of 
the cards I tested: Smithy, Adventurer, and Ambassador.
The Smithy card revealed that playing the card did not 
actually increase the count of the played cards.

The Adventurer card contained similar issues, where the 
played cards were not updated for that game. 

The Ambassador card test revealed a bug where the cards
went to the player's hand instead of a discard pile,
but the player's hand count was never updated.

The Great Hall card did not have any bugs.

*/

//end of bug1.c