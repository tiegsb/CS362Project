
Below is the output from my testing program:

	PASS: compare() should return 0 when a and b are equal
	PASS: compare() should return 1 when a is greater than b
	PASS: compare() should return -1 when a is less than b
	PASS: whoseTurn() should return 0 if state->whoseTurn is 0
	PASS: whoseTurn() should return 1 if state->whoseTurn is 1
	PASS: whoseTurn() should return -1 if state->whoseTurn is -1
	PASS: updateCoins() should return 0 if the player's hand has no coins and no bonus
	PASS: updateCoins() should return 0 if the player's hand has no coins and 3 other cards
	PASS: updateCoins() should return 9 if the player's had has 3 gold
	PASS: updateCoins() should return 9 if the player's had has 3 gold
	PASS: updateCoins() should return 6 if the player's had has 3 silver
	PASS: updateCoins() should return 3 if the player's had has 3 copper
	PASS: updateCoins() should return 9 if the player's had has 3 bonus
	PASS: fullDeckCount() should return 4 coppers
	PASS: fullDeckCount() should return  3 estates 
	PASS: fullDeckCount() should return 2 feasts
	PASS: fullDeckCount() should return 1 baron
	PASS: fullDeckCount() should return 2 silver
	PASS: fullDeckCount() should return 1 gold
	PASS: fullDeckCount() should return 1 steward
	FAIL: smithy_effect() This hand started with 6, should now have 8
	       There are now 9 cards in the hand
	PASS: The cards for Smithy were taken from the correct pile
	PASS: Smithy did not add cards to the other players hand
	FAIL: Smithy was not discarded
	FAIL: Adventurer() This hand started with 6, should now have 7
	       9 cards in hand
	FAIL: Adventurer added 3 new coin cards to the hand
	    There were 1 coins before adventurer and 4 coins after
	PASS: adventurer() did not add any coin cards to player 2
	PASS: Adventurer() player 0 had 6 cards in thier deck before and 9 after
	PASS: village() Player 0 has the same number of cards before and after in their hand
	PASS: village() Player 1 has the same number of cards before and after in their hand
	PASS: village() 1 card was taken from player 0's deck
	PASS: village() 0 cards were taken from player 1's deck
	FAIL: village() player 0 should have 2 actions, but has 5
	PASS: great_hall() Player 0 has the same number of cards before and after in their hand
	PASS: great_hall() Player 1 has the same number of cards before and after in their hand
	PASS: great_hall() 1 card was taken from player 0's deck
	PASS: great_hall() 0 cards were taken from player 1's deck
	FAIL: great_hall() player 0 should have 1 actions, but has 0

	6 tests failed

6 of my tests failed:

1) When Smithy is called the player ends up with too many cards in their hand
	FAIL: smithy_effect() This hand started with 6, should now have 8
	       There are now 9 cards in the hand
2) Smithy does not discard (this is why there are too many cards in the hand)	       
	FAIL: Smithy was not discarded
3) When adventurer is played the player ends up with too many cards in their hand
	FAIL: Adventurer() This hand started with 6, should now have 7
	       9 cards in hand
4) When adventurer is played the player ends up with too many coins	       
	FAIL: Adventurer added 3 new coin cards to the hand
	    There were 1 coins before adventurer and 4 coins after
5) When village is played the player ends up with 3 too many actions	    
	FAIL: village() player 0 should have 2 actions, but has 5
6) When great hall is played the player ends up with too few actions
	FAIL: great_hall() player 0 should have 1 actions, but has 0 


These test resuls are consistant with the bus that I introduced in homework 2.