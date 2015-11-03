Dalena Pham
CS 362 - Assignment 4
randomhistory.c

Adventurer:
Development Notes - 
	The random test cases for the Adventurer card echoed many of the unit tests I ran on it previously,
	primarily the cases where there are 2 or more treasure cards in a deck, only 1 treasure card in a 
	deck or no treasure cards in a deck. The tests were run with the ranges of MAX_HAND and MAX_DECK.
	Additionally, because I noticed in the last reflection that I lacked some boundary testing, I ran
	the same tests over again with forced boundaries (maximum handCount = 10 and deckCount = 10) to see 
	if anything interesting happened around those edge cases. 

	I had also originally planned that the test cases were allowed to choose hands or decks between 0 - 
	MAX, however due to the way my code was set up where I had lines that read "rand() % handCount", 
	I would get Floating Exception Errors because modding by 0 in C leads to an undefined type. So in this
	random test, I had to ignore cases where the deck is equal to 0 and made the minimum 1 card in the deck. 

Individual Coverage -
	File 'dominion.c'
	Lines executed:25.22% of 575
	Branches executed:25.66% of 417
	Taken at least once:19.18% of 417
	Calls executed:12.63% of 95
	dominion.c:creating 'dominion.c.gcov'

	Compared to the 21.91% for Line Execution achieved in Unit Tests, the random tests actually show that
	more of dominion.c is being covered in these tests. 

Overall Coverage - 

	File 'dominion.c'
	Lines executed:44.17% of 575
	Branches executed:41.01% of 417
	Taken at least once:33.81% of 417
	Calls executed:26.32% of 95

	Previously, without this random tester, the  overall line execution was at 43.65%, so there is a slight
	increase in coverage with this test. All other aspects remain the same however. 

Insights and Test Results - 

	Random Adventurer Card Tests------------------------

	HandCount Failures: 1000/1000    HandCount Passes: 0/1000
	DeckCount Failures: 1/1000       DeckCount Passes: 999/1000
	PlayedCardCount Failures: 1000/1000      PlayedCardCount Passes: 0/1000
	Resulting Cards Failures: 980/980        Resulting Cards Passes: 0/980

	The random tests shows that there are definately issues with the resulting handCount, PlayedCardCount,
	and that the wrong cards are being placed in the wrong positions in the hand. There is slight worry about
	the resulting deckCounts because 99% of the time, the program passes, but 1% of the time, it fails, leading
	me to believe that the deckCount bug will be harder to catch. 

	I mentioned above that I had attempted to enforce some boundary coverage, the reason they are left out
	in the test results is because they almost always lead to a segmentation fault. The enforced boundaries
	I set up would severely limit the number of cards in the hand, deck and discard pile. In many cases, 
	none of these piles would contain a treasure card. Debugging shows the segmenation error as invalid
	memory access. Upon more investigation, it would appear that there is no measure to stop the while
	loop inside adventurer if there are no treasure cards in either deck or discard. Eventually the tempHand,
	which holds the revealed cards, will reach a point where there is no array space allocated to it. 
	This is a huge bug that should be fixed.  


Sea Hag: 
Development Notes-
	Unlike the Adventurer, the Sea Hag card does not depend on many random factors to influence it, aside
	from the number of Players in a game. Since the Sea Hag card discards the top card of each other 
	player's deck and replaces it with a curse card, I made special variables and aimed most development
	checking if opponent decks were appropriately altered. Decks for all players were randomized, and 
	only the current player's hand was randomized because the sea hag does not depend on other player's
	hands. 

Individual Coverage-

	File 'dominion.c'
	Lines executed:20.17% of 575
	Branches executed:22.78% of 417
	Taken at least once:15.59% of 417
	Calls executed:8.42% of 95

	There is a slight 1% increase in line execution coverage from this random test and no change in the
	other aspects compared to individual coverage with sea_hag off unit testing alone. 

Overall Coverage - 

	File 'dominion.c'
	Lines executed:43.83% of 575
	Branches executed:41.01% of 417
	Taken at least once:33.09% of 417
	Calls executed:25.26% of 95

	There is a very small percentage of increase in the lines executed coverage. While this is honestly
	unexpected, as I thought I had covered most cases and branches in unit testing, this shows me the
	value in random testing. 

Insights and Test Results - 

	Random Sea Hag Card Tests------------------------

	Played Pile Failures: 1000/1000  Played Pile Passes: 0/1000
	Top Deck Failures: 1000/1000     Top Deck Passes: 0/1000
	Deck Count Failures: 0/1000      Deck Count Count Passes: 1000/1000
	HandCount Failures: 1000/1000    HandCount Passes: 0/1000
	Opp. Deck Count Failures: 1000/1000      Opp. Deck Count Passes: 0/1000
	Top Card Failures: 985/1000      Top CardPasses: 15/1000

	These tests are fairly straightforward, from them I can assess that:
	- The card is not being placed in the played card pile
	- The top of opponent's cards are not curse cards
	- The handcount is off
	- The opponent deck count is off
	- Lastly, the previous top card of the deck is not at the top of the discard pile as it should be. 

	I think that the Top Card Passes may be from the off chance that top of the discard pile had a 
	card identical to to previous deck top card. 