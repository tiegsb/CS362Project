Name: 	Jeff Moss
Date:	09/29/15
Title: 	Documentation of items that were refactored as a part of assignment 2 and the bugs that were introduced in that refactor.
File:	refactor.c
Class:	CS362 Fall 2015

Refactored code:

#1 Smithy card:
The smithy code was refactored into a new method called useSmithy(). This method passes the parameters handPos, currentPlayer and the struct for gameState. The implementation is contained in the dominion.c file while the declaration is located in the dominion.h file.

Bug introduced into Smithy card: 
A logic error was introduced into the Smithy card. The Smithy card is supposed to allow for three additional cards to be played (i < 3). The bug that was introduced was the addition of an = which should result in four additional cards to be played (i <= 3). This is a common logic error that programmers make.

#2 Adventurer card:
The adventurer card was refactored into a new method called useAdventurer(). This method passes the parameters currentPlayer and the game state. The implementation is contained in the dominion.c file while the declaration is located in the dominion.h file.

Bug introduced into the Adventurer card:
After all cars are drawn, the cards that are in the temp hand are to be discarded into the discar pile. Decrementor z=z-1 allows for the discard to decrement appropriately. This decrement was changed to z=z-2, which should cause an error in the number of cards discarded. 

#3 Steward card:
The steward card was refactored into a new method called useSteward(). This method passes the parameters handPos, currentPlayer, state, and choice1, choice2 and choice3. The implementation is contained in the dominion.c file while the declaration is in the dominion.h file. 

Bug introduced in the Steward card:
The steward card has an if, else if and else chain. The chain is supposed to determine if choice1 is equal to 1 or 2 or hit the else statement. Instead, I made the first if statement so that it is a conditional equality against 2. (if choice1 ==2). This behavior should cause the second if statement to not work properly because the first if statement will execute.

#4 Village card:
The Village card was refactored into a new method called useVillage(). This method passes the parameters handPos, currentPlayer and state. The implementation is contained in the dominion.c file and the declaration is located in the dominion.h file.

Bug introduced into the Village card:
When the discard function is called, it is called on currentPlayer++ and not the currentPlayer. This should introduce an off by one error.

#5 Great_hall card:
The great hall card was refactored into a new method called useGreat_hall(). This method passes the parameters handPos, currentPlayer and state. The implementation is contained in the dominion.c file and the declaration is located in the dominion.h file.

Bug introduced into the great_hall card:
The great hall card is supposed to provide an additional draw and an additional action. Rather than incrementing the action for the great hall card, this has been changed to be decremented. This could cause undefined behavior if no actions are left or could cause the skip of an action.  
