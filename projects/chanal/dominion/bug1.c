Author: Allan Chan
ONID: chanal
Class: CS362
Filename: bug1.c
Description: Bugs identified from unittests 1-4 and cardtests 1-4
--------------------------------------------------------------------
Bugs identified:


unittest4.c - drawCard()
------------------------
Just for testing boundaries, the test that failed for drawCard() was when
the player had an empty deck and an empty discard pile. This situation
would not arrise through normal play, but if it were then it failed
in three areas. The first was that after calling drawCard(), the discard
pile was shuffled with the deck. Both decks were zero, so this could not
happen as I was comparing the post deck count with the prediscard count.
Another area that it failed was the deck was not decremented after drawCard().
Again, this was not possible due to a deck should not have negative value of cards.
The last area that failed was that one of my conditions was testing if the post deck
count was greater than zero, but it was zero instead.


cardtest1.c - smithyCard()
---------------------------
In assignment 2, a bug was introduced into the smithcard effects after refactoring
the code in dominion.c. The bug introduced was: 
	for(i = 0; i < 3; i++) //original
	for(i = 0; i <= 3; i++) //introduced bug
for the drawCard() iterations. This would yield different results than expected.
This bug was detected in cardtest1.c in one of the failed test.
	"Playing Smithy card and testing..."
	"Test FAILED, player 0's hand DID NOT receive +3 cards"
As a result, the player did not receive the correct number of cards for playing smithy.
This unit test tested the properties of the smithy card effects for one player and
can be improved upon in later revisions of the unit test. No other bugs were found
besides the bug I introduced for assignment 2.


cardtest2.c - adventurerCard()
-------------------------------
In assignment 2, a bug was introduced into the adventurerCard effects after refactoring
the code in dominion.c. The bug introduced was:
	while(drawntreasure<2) //original 
	while(drawntreasure<=2)	//introduced bug
for drawing treasure. This would yield a different result than expected.
The bug was detected in cardtest2.c in one of the failed tests.
	"Test FAILED, 3 (NOT 2) treasure cards are added to player 1's hand"
The actual result was what I expected due to the bug I introduced. However,
another potential bug may have been found in one of the tests. Printing the
player's hand after calling adventurerCard() showed that Adventurer was still
in the player's hand. 
	"Test FAILED, card is still present in player 1's hand"
As a result, the card should have been discarded in the played pile, but it is shown in the
player's hand. 


cardtest3.c - councilRoomCard()
--------------------------------
In assignment2, two bugs were introduced into the councilRoomCard effects after refactoring 
the code in dominion.c. The first bug introduced was:
	for(i = 0; i < 4; i++) //original
	for(i = 0; i <= 4; i++) //introduced bug
for the drawCard() iterations. This would yield a different result than expected.
This bug was detected in cardtest3.c in one of the tests.
	"Testing for correct number of cards drawn..."
	"Test FAILED, Player 0 drew incorrect amount of cards"
As a result of this test, the number of cards drawn is incorrect.

The second bug introduced into councilRoomCard() was:
	state->numBuys++	//original
	state->numActions++	//introduced bug
This bug was detected in one of the tests.
	"Testing for correct number of numBuys..."
	"Test FAILED, Player 0 has incorrect number of numBuys"
As a result, numBuys was not incremented, rather it was numActions that was incremented instead as expected.


cardtest4.c - salvagerCard()
-----------------------------
In assignment2, a bug was introduced into the salvagerCard effects after refactoring
the code in dominion.c. The bug introduced was:
	state->numBuys++	//original
	state->numActions++	//introduced bug
The bug was detected in one of tests with no choice effect.
	"Testing for correct number of numBuys..."
	"Test FAILED, Player 0 has incorrect number of numBuys"
The bug was detected in one of the tests with a choice card effect for Salvager as well.
	"Testing for correct number of numBuys..."
	"Test FAILED, Player 0 has incorrect number of numBuys"
As a result of both of the tests of playing Salvager with no choice and a choice effect,
the numBuys was not incremented, rather it was the numActions as expected. 
A potential bug may be getting the coins after playing salvager. In some executions
of creating unittestresults.out yielded the correct number of coins while sometimes yielding
an incorrect number. The coin status varies and it may be a bug, but my unit test catches
the error when it is not the expected coin amount.