Name: 	Jeff Moss
Date:	10/24/15
Title: 	Documentation of the bugs that were found through the execution of unit tests.
File:	bug1.c
Class:	CS362 Fall 2015

unittest1.c - Shuffle function
All unit tests passed for the shuffle function. In order to pass all of the unit tests for the
shuffle function, at least one number must change position within the list of 5 numbers. This
was tested for five iterations. The order of where the shuffle occurs is the same each time as
the seed value is always the same.

Bugs found:
All unit tests passed, but it should be noted that in the dominion code, the shuffle funtion always takes in the same seed value. This should be tested further beyond unit testing.

unittest2.c - fullDeckCount function
All unit tests passed for the fullDeckCount function. 

Bugs found: None

unittest3.c - isGameOver function
All unit tests passed for the isGameOver function.

Bugs found: None

unittest4.c - gainCard function
All unit tests passed for the gainCard function.

Bugs found: None

cardtest1.c - useSmithy function (refactored smithy)
The useSmithy function failed the handcount unit test and the discardcount unit test.

Bugs found: 
1) Hand count was not incremented and decremented correctly. Three cards should have been drawn with the smithy card discarded. This was a bug that was introduced in the refactoring. (<= 3 should have been <3).
2) Discardcount was not incremented correctly. The expected value was 1, but 0 returned. This was consistent with a number of other cards, thus I suspect the issue is in the discard function.

cardtest2.c - useAdventurer function (refactored adventurer)
The useAdventurer function failed the discard count unit test. It expected 6 discards but 0 was returned.

Bugs found: 
1) Discard count failed to increment correctly. This is probably due to an incorrect discard function as well as a bug that was introduced in the discard part of the adventurer function.

cardtest3.c - useVillage function (refactored village)
The useVillage function failed the discard count unit test. It expected one discard but 0 were returned.

Bugs found:
1) Discard count failed to increment correctly. This is probably due to an incorrect discard function.
2) An incrementor bug was introduced in the discard portion of the village card.

cardtest4.c - useGreat_hall function (refactored great_hall)
The useGreat_hall function failed the discard count unit test as well as the actions unit test.

Bugs found:
1) Discard count failed to increment correclty. This is probably due to an incorrect discard function. 1 discard was expected, but 0 were returned.
2) The number of actions were not incremented correctly. Rather than incrementing an action the actions were decremented. This should be tested further beyond the unit tests.

