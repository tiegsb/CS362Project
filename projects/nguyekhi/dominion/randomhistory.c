/*
Testing for function CEadventurer()

Design: According to the specification, this function will draw until it obtain 2 treasure cards. 
It will shuffle the deck when it is empty (while drawing). Once it draw two treasure cards and put 
them in player hand, it will discard all other drawn cards. 
Therefore I will compare state of the game before and after execute the CEadventurer() function,
in order to check for the validity of different parts in the function. 
	1st part: check if the function
draw 2 treasure cards or not by checking the last two cards in player in hand
	2nd part: check to see if the player discard the adventurer card or not by checking the 
number of cards in player hand
	3rd part: check the number of cards in deck and discard to see if they add up
	The randomness of this test is combination of random number of deckCount, handCount, discardCount 
and handPosition. 
	This function originally has a bug at z >=0 and temphand[z] where it should be z - 1 >= 0 and temphand[z-1]
But this bug is too severe, and it will cause segmentation fault and crash the program for this random test,
so I have to remove this bug.

Result:
518 out of 600 Tests failed
File 'dominion.c'
Lines executed:20.87% of 599
Branches executed:19.57% of 419
Taken at least once:16.95% of 419
Calls executed:9.17% of 109
dominion.c:creating 'dominion.c.gcov'
function CEadventurer called 200 returned 100% blocks executed 100%

The result is similar to my unittest for Ceadventurer() function because I actually test for all the possible 
cases in both test, valid and invalid inputs, so it will execute all the lines. The only different is that 
I have to remove one of my bug in random Test adventurer because I have no control over the randomness of the
input, so they might get out of hand and cause crash and segmentation fault as I compile the program. 
So the random test kind of reveal the severity of the bug
According to the test, It seem like the function fail all three parts, lol 

Tesing for function CEsteward()

Design: According to the specification, this function will have 3 choices: 1. draw 2 cards, 2. gain 2 coins
3. trash 2 cards. 
	Similar to CEadventurer() test I will check the cards in hand and coins of the gameState before and after the 
player play the card. 
	The randomness of this test is deckCount, handCount, discardCount, and coins

Result:
138 out of 600 Tests failed
File 'dominion.c'
Lines executed:21.37% of 599
Branches executed:19.57% of 419
Taken at least once:15.75% of 419
Calls executed:11.93% of 109
dominion.c:creating 'dominion.c.gcov'
function CEsteward called 200 returned 100% blocks executed 100%

Since I check the code for this function and know that it is working properly, which means it doesn't have any bugs.
And so it only has 1 bug that I introduce which instead of trash two cards at choice 3, but it only put them in 
discard pile. 
The test result is showing that the function have two errors, the player do not trash 2 cards at choice 3
and the player do not discard the steward card at choice 1. The random test is showing another bug that I am not 
aware of it, and when I check the function it is a bug in discardCard() function that cause the error.
*/