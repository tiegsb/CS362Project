NOTE: Cardtest3.c, Cardtest4.c ()the last two tests in my makefile (smithyFunction() and adventurerFunction()) have bugs and fail on the asserts and thus kill the program (we were not asked to fix the implementations so they remain buggy)).  You’ll need to comment out test 7 (smithyFunction()) in order to have test 8 (adventurerFunction()) execute and then consequently fail evidencing a bug.

Smithy(): When smithy() was invoked 
•	I had coins added to my player when none were drawn from my deck.  
•	I had one more card drawn than the expected three.
•	The smithy card was not discarded from my hand when finished.

Adventurer():When smithy() was invoked
•	No matter number of cards left in my hand it was reshuffled every single time.
•	Many times there were no cards drawn from my deck to be added to my hand if treasure cards
•	Many times there would be cards inexplicably missing from the my deck
•	Many times there would be cards that I did not start with and that I did not draw that would be in my deck.


PLEASE NOTE:
The last two tests in my makefile (smithyFunction() and adventurerFunction()) have bugs and fail on the asserts and thus kill the program.  You’ll need to comment out test 7 (smithyFunction()) in order to have test 8 (adventurerFunction()) execute and then consequently fail evidencing a bug.