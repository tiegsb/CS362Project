// Rachael McConnell
// CS362 Fall 2015
// Assignment 4
// randomhistory.c

/*
For both random test functions:
-Assign random number of players 
-Assign random current player 
-Assign random deckCount for each player (0-100)
-Assign random handCount for each player (1-50)
-Assign random cards to each player's hand and deck 
-Set playedCards count to 0


RANDOMTESTADVENTURER.C - Random test for the Adventurer Card

Development of randomtestadventurer.c

Checks:
For the Current Player
 Adventurer card is in hand at start of turn
 Adventurer card is no longer in hand at end of turn 
 DeckCount has decreased by at least 2 cards (the 2 treasure cards that should be added to player's hand) 
 HandCount has increased by 2 cards (+2 treasureCards)
 # of treasure cards in hand has increased by 2 
 PlayedCardsCount increased by 1 (the adventurerCard that is played)
 DiscardCount changed as expected (before->after deckCount difference + 2 (treasureCards added))
 
For the Other Players 
 Number of cards in discardCount, handCount, and deckCount remain the same 

 
Coverage

File 'randomtestadventurer.c'
Lines executed:94.74% of 114
Branches executed:100.00% of 82
Taken at least once:85.37% of 82
Calls executed:91.67% of 36

File 'dominion.c'
Lines executed:21.39% of 575

Lines executed in dominion.c increased from the unit test by over 4%, from 17.22% to 21.39%.

In my testing I found that the players hand count was being incremented by 2, but the number of treasure cards in the players' hand was not increasing by 2 as
well. I looked further into this problem and found that on some occasions, other cards were being added to the players' hand, instead of treasure cards. This is
a problem that I had not found in the unit tests. I also realized that it was important to test the deckCount for both the current player and the other players.
When the deckCount for the current player was less than 2, the test began getting unexpected results. 


Errors found:
 -Adventurer card is not discarded from current players hand - This error occurs every time.
 -Played cards count does not increment by 1. This is because the adventurer card is not discarded.
 -Treasure cards do not always increment by 2 - This error occurs sometimes. Treasure cards are #4, 5, and 6. Card 1 (estate) is also being treated as treasure
  card, so the treasureCards count does not increment when this is the case.
 -discardCount is wrong - This error occurs sometimes. It seems to happen when the deckCount is low and runs out of cards.
 -Shuffle is not happening correctly - shuffle() is called when there are 0 cards in the deck, but shuffle() requires the deck to be full
 -When the deckCount is low (ie. 1 or less), weird things happen. This may have to do with the shuffle function. The current players' hand 
  and discard counts and the other players discard counts are very large numbers (and sometimes negative) numbers after the adventurer card is played. 
 -Segmentation fault- is occurring when one of the new treasure cards added is card #16 (great_hall, which is not a treasure card), and deck count after 
  playing the adventurer card is at 0. When this happens, the hand and discard counts for the current player get very large (4 figures and sometimes negative),
  and the discardCount for the other players becomes a huge number as well. This is the only time an error occurs with the card counts of the other players.

 
 
RANDOMTESTCARD.C - Random test for the Council Room Card

Development of the randomtestcard.c

Checks:
For the Current Player
 Council room card is in hand at start of turn
 Council room card is not in hand at end of turn 
 NumBuys has increased by 1 
 DeckCount has decreased by 4 cards
 HandCount has increased by 3 cards (+4 cards drawn, -1 council_room card) 
 DiscardCount remains the same
 PlayedCardCount increases by 1
 
For the Other Players
 DiscardCount remains the same
 HandCount has increased by 1 (+1 card drawn)
 DeckCount has decreased by 1

 
Coverage

File 'randomtestcard.c'
Lines executed:81.63% of 98
Branches executed:100.00% of 56
Taken at least once:76.79% of 56
Calls executed:78.95% of 38

File 'dominion.c'
Lines executed:22.43% of 575

Lines executed in dominion.c increased from the unit test by over 3%, from 19.13% to 22.43%.

During my testing I was finding a small number of errors (25 or less out of 6000 tests). Looking into it further, I discovered that I needed to add a 
check to make sure deckCount is at least 4 (for the currentPlayer) and at least 1 (for the other players). Once I did this, all errors went away.

Errors found:
 None










*/