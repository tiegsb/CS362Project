randomtestadventurer:
	For random test adventure, the test had complete branch coverage, the funciton was run on every test of 1000, the only suprise was that drawntreasure++; (line 25) was ran 2000, twice for every iteration.  The functional playAdventurer would be expected to run this way, but in its buggy form this should not have happened.  It made me realize that there is another bug, when a coin is drawn, it can be drawn a second time after a reshuffle.
	The test ran 1000 times and failed 1000 times.  I did not expect it to fail every test.  I only expected it to fail when a gold card was present in the deck.  It was also failing many more of the checks than I expected.  What I found was the deck began not matching the expected cards at the position the adventurer card was played.  As it turned out, this was because the adventurer card was not being discarded at the end of the playAdventurer function, and was effecting the position of all the cards being checked.  So that, in addition to the gold card being skipped were found as bugs.  

coverage:  dominion.c - 22.90%
		refactor.c - 29.41%

randomtestcard:
	For random test card, the test ran and had complete branch coverage.  There are no conidtionals in the playSmithy funciton, with the exception of the for loop, so this would make sense to have occured.  The buggy version ran the appropriate number of times, but the inside of the for loop only ran 200 times, twice for evey call to playSmithy, where a functional version would have ran it 3 times for evey call.
	The test itself ran 1000 times and failed 1000 times.  It was seen that every time there were too few cards.  This was expected, and is due to the bug introduced to only have the user draw 2 cards instead of 3, so the user always has 1 fewer card than expected.

coverage:  dominion.c - 21.56%
		refactor.c -  9.80%