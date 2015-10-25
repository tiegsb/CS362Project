coverage1.c
Dalena Pham

Overall, my test suite thus far only covers 43.65% of the dominion.c file. This was expected
by me because functions to be tested were chosen at random and sparingly, there is still many
cardeffects that need to be tested and game functions to test out. Additionally, I realize
that I need to spend a little more time and attention to giving boundary testing coverage as
a majority of my testing only focused on statement and branch coverage. 

Overall test coverage: 
File 'dominion.c'
Lines executed:43.65% of 575
Branches executed:41.01% of 417
Taken at least once:32.85% of 417
Calls executed:25.26% of 95

Individual coverage testing: 
unittest1.c, testing getCost
File 'dominion.c'
Lines executed: 5.22% of 575
Branches executed: 6.71% of 417
Taken at least once: 6.71% of 417
Calls executed: 0.00% of 95

- Statement: function getCost called 33 returned 100% blocks executed 100%
- Branch: All branches of the getCost function were accessed and executed in this unit test, 
	primarily because I had to ensure every value was correct for the card given
- Boundary: To test boundaries, I tested for the value 27 (one more than the last enum value)
	to ensure it returned an appropriate value. 

unittest2.c, testing drawCard
File 'dominion.c'
Lines executed: 19.30% of 575
Branches executed: 16.79% of 417
Taken at least once: 14.63% of 417
Calls executed: 8.42% of 95

- Statement: function drawCard called 124 returned 100% blocks executed 100%
- Branch: All branches of drawCard were accessed at least one, this was easy to achieve
	especially because drawCard is called multiple times throughout many functions
- Boundary: testing boundaries in drawCard appears to be all about the conditions of the
	exisiting deck and discard pile. To test this, I tested drawCard against an empty
	deck but not empty discard pile and then finaly with both an empty deck and discard pile

unittest3.c, testing buyCard
File 'dominion.c'
Lines executed: 21.74% of 575
Branches executed: 25.42% of 417
Taken at least once: 15.59% of 417
Calls executed: 12.63% of 95

- Statement: function buyCard called 4 returned 100% blocks executed 100%
- Branch: All branches of buyCard were accessed, these mostly included cases where
	the player did not meet the conditions to purchase a card
- Boundary: Looking back, I think I should introduce more boundary testing in the future
	for this function. In this cycle, I tested when NumBuys was 1 and 0, and a seperate test 
	when the supply count was 0 for a specific card. In the future I would implement boundary
	testing with the number of coins to purchase a card as well. 

unittest4.c, testing endTurn
File 'dominion.c'
Lines executed: 20.17% of 575
Branches executed: 17.75% of 417
Taken at least once: 14.63% of 417
Calls executed: 10.53% of 95

- Statement: function endTurn called 3 returned 100% blocks executed 100%
- Branch: All branches of endTurn were executed at least once, this was achieved by 
	creating a 3 person game and testing conditions between each player after their 
	turn was finished. 
- Boundary: I created a 3 person game to test what occured at the front, middle and
	ending conditions for the endTurn function. I did not test outside this because 
	that would be abnormal conditions for the game. 

cardtest1.c, testing smithy
File 'dominion.c'
Lines executed: 18.61% of 575
Branches executed: 17.75% of 417
Taken at least once: 14.15% of 417
Calls executed: 9.47% of 95

- Statement: function smithy_card called 1 returned 100% blocks executed 100%
- Branch: There are very little branches in smithy aside from its one for loop, 
	which must be executed with the call. 

cardtest2.c, testing adventurer
File 'dominion.c'
Lines executed: 21.91% of 575
Branches executed: 19.66% of 417
Taken at least once: 17.27% of 417
Calls executed: 10.53% of 95

- Statement: function adventurer_card called 3 returned 100% blocks executed 100%
- Branch: The only branch that was not taken during this unit test was one comparing 
	if the card examined was a copper card or not. Because I purposely wanted loaded
	the deck to be drawn from with silver and gold cards, this is to be expected as 
	I did not want to confuse a drawn copper from a copper card that may have already
	been in the hand. 
- Boundary: Boundary testing was attempted by testing cases where there were only
	1 treasure card to be found in the deck and cases where the deck was empty. 

cardtest3.c, testing council room
File 'dominion.c'
Lines executed: 19.83% of 575
Branches executed: 19.18% of 417
Taken at least once: 15.35% of 417
Calls executed: 10.53% of 95

- Statement: function council_room_card called 1 returned 100% blocks executed 100%
- Branch: All branches were called at least once in this unit test, this is easy to do
	because coucil_room_card will automatically go through all its branches

cardtest4.c, testing sea_hag card effect
File 'dominion.c'
Lines executed: 19.13% of 575
Branches executed: 22.78% of 417
Taken at least once: 14.63% of 417
Calls executed: 8.42% of 95

- Statement: for the sea_hag portion of cardeffect, sea_hag had 100% statement coverage
- Branches: Like in the case of the council_room_card, sea_hag goes through its for
	loops entirely, making for 100% branch coverage in this poriton. 