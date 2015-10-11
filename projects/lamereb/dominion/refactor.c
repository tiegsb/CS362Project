Brian Lamere
CS362_400
Assignment 2
5 OCT 2015

Refactoring of 5 Cards
1. playAdventurerCard() added, then called as part of switch statement in cardEffect(). 
Bug introduced: Replaced silver with smithy as one of the 3 cards that is kept when drawing cards.

2. playSmithyCard() added, then called as part of switch statement in cardEffect(). 
Bug introduced: trashFlag set in discardCard(), trashing smithy instead of returning it to discard pile.

3. playVillageCard() added, then called as part of switch statement in cardEffect().
Bug introduced: 2 cards are drawn instead of 1.

4. playCouncilRoomCard() added, then called as part of switch statement in cardEffect().
Bug introduced: trashFlag set in discardCard(), trashing council instead of returning it to discard pile.

5.playRemodelCard() added, then called as part of switch statement in cardEffect(); 
