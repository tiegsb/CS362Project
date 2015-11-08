Victor Hernandez
CS_362_F15
Assignment 4 - Part 3 - randomhistory.c

randomtestadventurer.c -
This random test used the main function to call the test function. The test function uses a while loop
to cycle through 15000 iterations.  Each iteration a random player was picked, and then for that random player,
a random deckCount, handCount, and discardCount was set. The adventurerCard function is then called for the current player and gamestate. After that, the coin count, hand count, and discard count is checked. For coin count, the adventurer
should add 2 treasure cards which is checked by counting the number of drawntreasure, if 2 cards area added the test passes if not an error counter is incremented. Handcount is checked in much the same way, as 2 cards should now be in the players hand, which is checked by comparing the hand count before and after the Adventurer card is played. Finally the palyers hand is checked to see if the Adventurer card is discarded, this is done by checking the looping over the players hand after the adventurerCard() function has been called checking to see if the Adventurer card is still present and incrementing a second error variable if it is still in the and. Finally the two error counters are checked, and messages are printed to the screen indicating how many times the tests created errors.

File 'dominion.c'
Lines executed:25.30% of 581
Branches executed:22.06% of 417
Taken at least once:19.42% of 417
Calls executed:12.50% of 96

Statement coverage for the random test was not particularly high at 25.30%, but it was noticeably better coverage wise than the unit test for the Adventurer card. Branch coverage was again not very high but also higher in coverage than the unit test for the Adventurer card. The larger number of tests and in particular the randomness of some of the inputs are what I imagine lead to the increased statement and branch coverage.

randomtestcard.c -
This random test used the main function to call the test function. The test function uses a while loop
to cycle through 15000 iterations.  Each iteration a random player was picked, and then for that random player,
a random deckCount, handCount, and discardCount was set. The smithyCard function is then called for the current player and gamestate. After that hand count and discard count is checked for errors. The bug that was introduced to the Smithy card is quite apparent at the discard count is the same before and after the smithCard() function is called. This is because the trash flag was set instead of allowing the card to be discarded so the discard count never goes up when the card is played. The hand count is also checked again by checking the hand count before the Smithy card and after. This test passes almost totally as it should,as it has not been adjusted or had bugs introduced. Both tests also use an error counter that increments on failed tests, these results are then displayed to the screen once the loop is finished.

File 'dominion.c'
Lines executed:20.83% of 581
Branches executed:19.18% of 417
Taken at least once:15.59% of 417
Calls executed:10.42% of 96

Statement coverage for the random test was not particularly high at 25.30%, but it was noticeably better coverage wise than the unit test for the Smithy card. Branch coverage was again not very high but also higher in coverage than the unit test for the Smithy card. The larger number of tests and in particular the randomness of some of the inputs are what I imagine lead to the increased statement and branch coverage.