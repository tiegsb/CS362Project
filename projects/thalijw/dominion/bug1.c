CS_362_Software Engineering
Assignment #3
thalijw

I created four unittest files to test the following function:

1) updateCoins()
	I tested the fucntion and did not find any bugs associated with it, the function correctly
	adds the right number of coins to the player total coins. the test unit test against adding
	all copper and all silver and all gold.

2) fullDeckCount()
	I added one card of value (1) to each deck pile, discarded pile and player's hand, the result
	of the test function returned 3 in total, the test case passed with no Errors.

3) scoreFor()
	The fucntion tested the count of all the players' cards in hand, deck and discard pile, I added
	2 estate, 2 duchy and one province to the player's hand (total 14 points) and added 10 estates for 
	each deck and discard piles. The function returned the correct total of score = 34. no bugs found!

4) gainCard()
	In this function, I initialized the handCount, deckCount and discardCount to be equal to 5, and
	tested the those values after each call for gainCard() with the appropriate flag. The function
	passed all the test with no bugs found!


And I created four cardtest files to test the following cards:


1) Smithy Card
	The function passed with the correct number of gained cards (+3), but playing the card was supposed
	to add the played card to the played pile and increament the playCount variable for the game state,
	here was my introduced bug for Assignment#2 , the test failed and playing the card just discarded 
	the played card with out increamenting the playedCount variable.( abug found ).

2) Adventurer Card
	The test checks for the correct added number of cards ( supposed to be +2), my test failed to pass 
	because of the bug i interduced in Assignment#2 where the function adds 3 cards inseatd of two, the 
	unit test exposed this but!, also tested if the cards added were actually a treasure cards and this 
	test passed. the last test was checking if the card was added to the played pile and this test passed
	as well.

3) Steward Card
	The test passed in Choice 1 by adding the correct number of cards to the player hand.
	the test failed in choice 2 for adding two coins, since this was a bug I introduced in Assignment#2
	as well, where I subtracted two coins instead of adding them, the test successfully found this bug.
	And the test passed in Choice 3 for trashing two cards from the player hand.

4) Cutpurse Card
	This test unit passed all the test caeses, where I tested playing the card added two coins to the first
	player total coins, the card removed one copper card from the second player hand and discarded the played 
	cards from the first player hand.




