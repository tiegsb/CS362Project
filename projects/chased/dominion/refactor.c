Dustin Chase
 CS 362 
 Assignment 2
 Refactoring card effect method and introducing bugs. 
 
 This documents the bugs introduced into the following card effects: 
 
 adventurer
 Removed condition "cardDrawn == gold" from second if statement. This way the drawnTreasure
 counter will only increment on copper or silver cards. 
 
 smithy
 Changed cards drawn from 3 to 2 in for loop. This way the loop will hault when the player has 
 drawn 2 cards instead of the correct 3 cards. 
 
 council room
 Changed numBuys from +1 to +2. So the number of buys will increase by 2 when it should only increase by 1. 
 
 feast
 Changed updateCoins call last parameter from correct 5 to incorrect 4. 
 
 