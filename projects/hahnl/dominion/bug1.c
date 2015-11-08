/*
Author: Larissa Hahn
bug1.c

adventurerCard() does not correctly draw or discard cards. Test fails.
villageCard() does not correctly draw the right amount or discard the right
amount of cards. Test fails.
greatHallCard() does not correctly draw the right amount or discard the right
amount of cards. Test fails.
Other tests successful.
The bugs currently found are the same as in refactor.c:

BUGS INTRODUCED: Below are notes on the bugs I introduced in my
refactoring.

//// Smithy Card - void smithyCard ()
In the for loop, the i counter starts at 1 instead of 0,
and goes till less than or equal to 4 instead of less than 3.

//// Adventurer Card - void adventurerCard ()
The first if statement to check if the deck is empty checks if the
state is less than 0 instead of the original less than 1.
drawntreasure gets decremented instead of incremented.
state->handCount[currentPlayer] gets incremented instead of decremented.

//// Great Hall Card - void greatHallCard ()
Comment and action now reflect -1 instead of +1. Wondering if changing
the comment will throw someone off when debugging.

//// Village Card - void villageCard ()
Incremented action instead of +2, altered comment.

//// Council Room Card - void councilRoomCard ()
+2 instead of increment for buys.
Second for loop now states <= instead of <
If statement is == currentPlayer instead of !=
/*
