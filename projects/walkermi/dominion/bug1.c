Unit Test Bug Findings:




Unit Test 1 - updateCoins():
	- No bugs found


Unit Test 2 - fullDeckCount():
	- No bugs found


Unit Test 3 - discardCard():
	- No bugs found


Unit Test 4 - gainCard():
	- No bugs found


Card Test 1 - Adventurer:
	- Adventurer Card not discarded from hand
	- Adventurer Card not added to Played Pile
	- Hand Count not incremented by one
		- Cause: Non-treasure cards are not discarded from temp hand


Card Test 2 - Smithy:
	- More than three cards (4) drawn from deck
	- More than three cards (4) added to hand


Card Test 3 - Great Hall:
	- Adventurer Card not discarded from hand
	- Adventurer Card not added to Played Pile

Card Test 4 - Village:
	- Less than 2 actions (1) added to current players action count