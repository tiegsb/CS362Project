unittest1: handCard()
* No bugs found

unittest2: supplyCount()
* No bugs found

unittest3: numHandCards()
* No bugs found

unittest4: fullDeckCount()
* No bugs found

cardtest1: Smithy
* No bugs found

cardtest2: Adventurer
The Adventurer function had a bug that revealed two problems. The first bug being that copper cards are not added to the treasure 
count of the function, and thus not added to the player's hand. In theory, this should cause an infinite loop (if there are no silver
or gold cards as in our test), however, the loop fails as the function always pulls a card from the end of the array and works its
way down to the first card. In other words, the index of the array decreases until it approaches 0. However, there is no check to make
sure that the index does not go beyond 0, so it will eventually become a negative number. When the program attempts to access an element
at a negative index, it will either return with an unreliable element or will fail completely. 
 
cardtest3: Village
The Village function testing revealed a bug that affected the number of actions a player was supposed to receieve. Instead of adding 2 to 
the player's actions, the function multiplied the actions by two. Additionally, since I was not resetting the actions during every hand,
the actions would continue to double, going as high as 160 actions. 

cardtest4: Council
The Council testing revealed that instead of all the other player's receiving an extra card, it was the current player that received the card.
This was discovered by checking the hand counts of each player before and after the function was called. 