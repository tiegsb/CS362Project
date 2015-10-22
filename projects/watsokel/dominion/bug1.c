CS 362 - ASSIGNMENT 3               KELVIN WATSON 
bug1.c                    			ONID: watsokel      
                                    OSU ID: 932540242 
                                    https://github.com/amchristi/cs362f15/tree/master/projects/watsokel 
----------------------------------------------- -----------------------
BUGS IDENTIFIED:


unittest2.c: discardCard()
--------------------------
After a card is discarded, the the discard count should be increased by 
one. To detect a discarded card, the discard count was initialized to 
zero. However, the state->discardCount remains zero even after a call to 
discard card with a flag of 0. Checking the top of the discard pile 
results in a garbage value, even though the discarded card was a gold 
card. These two bugs are detected in unittest2 and result in a "FAIL" 
result in the unit test checks:
	"FAIL, discardCount=0, expected=1"
	"FAIL, discardedCard=387389207, expected=6"
	
	
cardtest1: smithyEffect()
-------------------------
In assignment 2, I introduced a bug to the smithy card when I 
refactored the smithy case in cardEffect() to the smithyEffect() 
method. 
	*** BUGS introduced to smithyEffect() method in Assignment 2 *** 
	Instead of calling discardCard() with trashFlag value of 0 (which 
	correctly places the smithy card into the discard pile), a bug has been 
	introduced that calls discardCard() passing in the trashFlag with a 
	value of 1 (which erroneously places the smithy card in the deck). 
	Specifically, the line: 
	  discardCard(handPos, currentPlayer, state, 0); //original
	has been changed to: 
	  discardCard(handPos, currentPlayer, state, 1); //bug introduced
In cardtest1, a bug was detected as the following "FAIL" result:
	"FAIL, discardCount=0, expected=1"
Although the unit test detects a failed test with the discarded smithy card, it is 
uncertain whether this is an actual bug in smithyEffect or discardCard solely by 
examining this unit test alone. However, in conjunction with 
the results from the unittest2.c, it is likely that there is a bug in 
discardCard() since neither the flag 0 or 1 passed as arguments to discardCard 
result in the discardCount being incremented.
	
	
cardtest2: adventurerEffect()
-----------------------------
In assignment 2, I introduced a bug to the adventurer card when I 
refactored the adventurer case in cardEffect() to the adventurerEffect() 
method. 
	*** BUG introduced to adventurerEffect() method in Assignment 2 *** 
	When evaluating the card that was drawn, a drawn copper card no 
	longer increments drawntreasure. Namely, the line: 
	  if (cardDrawn==copper || cardDrawn==silver || cardDrawn==gold) //original
	has been changed to: 
	  if (cardDrawn == silver || cardDrawn == gold) //bug introduced
As a result of this bug, the drawntreasure variable will not be 
incremented when a copper is drawn. This bug was detected in this unit 
test, and shows up as the following "FAIL" result: 
	"FAIL, treasureCount=0, expected=2
	NOTE: If treasure is 4 (copper), failed unit test is expected due to 
	bug introduced in assignment 1. Testing for unexpected transactions. 
	Checking supply counts..."

	
cardtest3: cardEffect(sea_hag)
------------------------------
The sea_hag case in cardEffect() contains several bugs:
1. In this line in dominion.c cardEffect's sea_hag case, 
state->discard[i][state->discardCount[i]] =	state->deck[i][state->deckCount[i]--]; 
Notice that it is not the top of the deck that is being assigned to the 
discard pile. It is actually garbage data that is being assigned to the 
top of the discard pile since the deckCount is not actually decremented 
until after the assignment occurs. This is the behavior of the 
post-decrement notation, but is incorrectly used in this case. 
In cardtest3, the discard pile is initially empty. The top of the 
opponent's deck is set to a gold card, while the rest of his/her deck is 
set to estates. This is done to allow its detection when this gold card is 
discarded. After the call to cardEffect(sea_hag), the unit tests in 
cardtest3 detected that the top of the discard pile was indeed garbage 
data, when the expected card was actually a gold card. In cardtest3, this
bug is detected, as indicated in the result below:	
	"FAIL: Card on top of opponent's discard pile after discarding top of 
	deck=387389207,expected=6"

2. The deck count is erroneously decremented 3 times, when the 
overall deck count should not have changed - i.e. the deck count should 
have only been decremented once when top of deck was discarded, then 
incremented when curse card was added to the top of the deck. Instead,
the sea_hag case in cardEffect() shows that the expression 
"state->deckCount[i]--" "appears a total of three times. In cardtest3, this
bug is detected, as indicated in the result below:	
	"FAIL: Deck count after discarding top of deck=7,expected=10"

3. When the curse card is placed at the top of the opponent's deck, it 
is actually being placed in the wrong location. Specifically, this line: 
	state->deck[i][state->deckCount[i]--] = curse;
Since the opponent's deck was decremented incorrectly twice (when it 
should only have been decremented once) by this point, the curse was 
inserted into the wrong location in the deck (beneath the top of the 
deck). As a result, the top of the opponent's deck was actually an 
estate card, which was what the entire deck was originally initialized 
to. In cardtest3, this bug is detected, as indicated in the result below:	
	"FAIL: Deck count after discarding top of deck=7,expected=10"

3. The supply count of curse cards was not decremented when the curse 
card was placed on top of opponents' decks. In this line, 
state->deck[i][state->deckCount[i]--] = curse; 
the curse is being assigned directly to the deck, but the supply count 
of the curse cards was not decremented. This is a bug that results in a 
side effect that the supply count of curse cards is the same before and 
after the call to sea_hag, which is incorrect. In cardtest3, this
bug is detected, as indicated in the result below:	
	"FAIL: number of curse cards=10, expected=9"