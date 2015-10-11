Solomon Huynh
CS362 Assignment 2
refactor.c

The cards refactored are adventure, smithy, village, remodel, and council_room.

Functions and implementation of bugs listed below:

adventure = adventureCard()
Removed the "cardDrawn == silver" condition when checking if a treasure has been drawn so the function will only pick up
copper and gold cards only as a treasure.

smithy = smithyCard()
In the for loop to draw 3 cards, the variable i in the for loop is set as 2 instead of 3 so it will draw 2 cards instead
of 3.

village = villageCard()
Set to where the number of actions is given as 3 instead of 2.

remodel = remodelCard()
No bugs introduced in this function

council_room = councilRoomCard()
In the for loop to draw 4 cards, the variable i in the for loop is set to 1 instead of 0 so the loop will actually only
run 3 times instead of 4 which results in only drawing 3 cards.



