/******************************************************************************
coverage1.c
Sharon Kuo (kuos@oregonstate.edu)
CS362-400: Assignment 3
Description: Notes on coverage of unit tests for functions and cards,
  implemented in unittest1.c, unittest2.c, unittest3.c, unittest4.c,
  cardtest1.c, cardtest2.c, cardtest3.c, and cardtest4.c.

--------------------
unittest1.c: getCost()
--------------------
File 'unittest1.c'
Lines executed:53.44% of 131
Branches executed:100.00% of 62
Taken at least once:50.00% of 62
Calls executed:60.65% of 155
unittest1.c:creating 'unittest1.c.gcov'
----------
File 'dominion.c'
Lines executed:5.37% of 559
Branches executed:6.71% of 417
Taken at least once:6.71% of 417
Calls executed:0.00% of 95
dominion.c:creating 'dominion.c.gcov'
----------
Test each switch statement in the cost. Also tests negative values, 
out-of-bounds values, and large numbers.
The branching in unittest1.c is due to the if/else for the tests passing or
failing.
This unit test only covers a small part of dominion.c (just the getCost()
function), which does not call on other functions.

--------------------
unittest2.c: isGameOver()
--------------------
File 'unittest2.c'
Lines executed:74.29% of 105
Branches executed:100.00% of 28
Taken at least once:50.00% of 28
Calls executed:74.07% of 54
unittest2.c:creating 'unittest2.c.gcov'
----------
File 'dominion.c'
Lines executed:17.71% of 559
Branches executed:17.75% of 417
Taken at least once:14.87% of 417
Calls executed:7.37% of 95
dominion.c:creating 'dominion.c.gcov'
----------
This tests the conditions for game over; tests if game over is set at the
start of the game, if all province cards are gone, and a few combinations of
the three-pile ending (3 treasure piles gone, 3 kingdom piles gone, and 3
kingdom and treasure piles gone).
Branching in unittest2.c is due to the if/else for the tests passing or
failing.
The coverage here is higher because the game is initialized to test gameOver(). 

--------------------
unittest3.c: fullDeckCount()
--------------------
File 'unittest3.c'
Lines executed:75.73% of 103
Branches executed:100.00% of 26
Taken at least once:50.00% of 26
Calls executed:72.92% of 48
unittest3.c:creating 'unittest3.c.gcov'
----------
File 'dominion.c'
Lines executed:17.53% of 559
Branches executed:18.71% of 417
Taken at least once:15.83% of 417
Calls executed:7.37% of 95
dominion.c:creating 'dominion.c.gcov'
----------
Tests the fullDeckCount() function for various cards in a set deck. Tests
different combinations of cards (in deck, hand, and/or discard), as well as
cards not present and cards not in the list of kingdom cards.
Covers more than unittest1.c because the game is initialized to test
fullDeckCount().

--------------------
unittest4.c: scoreFor()
--------------------
File 'unittest4.c'
Lines executed:93.91% of 115
Branches executed:100.00% of 10
Taken at least once:50.00% of 10
Calls executed:81.48% of 27
unittest4.c:creating 'unittest4.c.gcov'
----------
File 'dominion.c'
Lines executed:21.82% of 559
Branches executed:28.78% of 417
Taken at least once:24.46% of 417
Calls executed:10.53% of 95
dominion.c:creating 'dominion.c.gcov'
----------
Tests the scoreFor() function for various combinations of cards in a deck.
Tests empty decks, decks with garden cards and treasure cards, decks with
garden cards and kingdom cards, and decks with all estate, duchy, province, or
curse cards.
Coverage is higher because the game is initialized to test scoreFor(), and the
function itself calls another function.

--------------------
cardtest1.c: Smithy card
--------------------
File 'cardtest1.c'
Lines executed:88.71% of 62
Branches executed:100.00% of 14
Taken at least once:50.00% of 14
Calls executed:61.11% of 18
cardtest1.c:creating 'cardtest1.c.gcov'
----------
File 'dominion.c'
Lines executed:20.39% of 559
Branches executed:23.26% of 417
Taken at least once:14.63% of 417
Calls executed:11.58% of 95
dominion.c:creating 'dominion.c.gcov'
----------
Tests a 2-player game for deck, hand, and discard counts after the smithy card
is played.
Verifies that the other player's cards are not altered.
A game is initialized and the cardEffect() function calls another function,
giving slightly higher coverage than the other unit tests.

--------------------
cardtest2.c: Adventurer card
--------------------
File 'cardtest2.c'
Lines executed:88.71% of 62
Branches executed:100.00% of 14
Taken at least once:50.00% of 14
Calls executed:61.11% of 18
cardtest2.c:creating 'cardtest2.c.gcov'
----------
File 'dominion.c'
Lines executed:19.86% of 559
Branches executed:23.74% of 417
Taken at least once:14.87% of 417
Calls executed:10.53% of 95
dominion.c:creating 'dominion.c.gcov'
----------
Tests a 2-player game for deck, hand, and discard counts after the adventurer
card is played.
Verifies that the other player's cards are not altered.
A game is initialized and the cardEffect() function calls another function,
giving slightly higher coverage than the other unit tests.

--------------------
cardtest3.c: Village card
--------------------
File 'cardtest3.c'
Lines executed:87.88% of 66
Branches executed:100.00% of 16
Taken at least once:50.00% of 16
Calls executed:60.00% of 20
cardtest3.c:creating 'cardtest3.c.gcov'
----------
File 'dominion.c'
Lines executed:20.39% of 559
Branches executed:22.78% of 417
Taken at least once:14.15% of 417
Calls executed:11.58% of 95
dominion.c:creating 'dominion.c.gcov'
----------
Tests a 2-player game for deck, hand, and discard counts after the village
card is played. Also tests the player's action count.
Verifies that the other player's cards are not altered.
A game is initialized and the cardEffect() function calls another function,
giving slightly higher coverage than the other unit tests.

--------------------
cardtest4.c: Council Room card
--------------------
File 'cardtest4.c'
Lines executed:87.88% of 66
Branches executed:100.00% of 16
Taken at least once:50.00% of 16
Calls executed:60.00% of 20
cardtest4.c:creating 'cardtest4.c.gcov'
----------
File 'dominion.c'
Lines executed:21.47% of 559
Branches executed:24.22% of 417
Taken at least once:15.59% of 417
Calls executed:12.63% of 95
dominion.c:creating 'dominion.c.gcov'
----------
Tests a 2-player game for deck, hand, and discard counts after the adventurer
card is played. Also tests the player's buy count.
Verifies that the other player's cards are altered.
A game is initialized and the cardEffect() function calls another function,
giving slightly higher coverage than the other unit tests.


******************************************************************************/