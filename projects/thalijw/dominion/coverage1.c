The results of my dominion.c coverage are:

1) line statement coverage is : 42.72% of 646 lines
2) Branch coverage is : 53.96% of 417


I stepped through the coverage code of dominion.c.gcov noticed that most of the lines did not get
covered for the following reasons:

1) In the test unit we didn't test all the game's function, there are still some fucntion that we did
not test yet.

2) We did not test some of the edge cases or cases that are not likely to accure (e.g when the number 
of player > MAX_PLAYERS or < 2).

3) We didn't test when the number of playes > 2 and < MAX_PLAYERS either, here we missed some initializing
lines for the estate, duchy and some other cards for the game.


I checked the branch coverage and saw that in some places it was a 100% when we only executed the conditions
in the if statements and never executed the else part, example:

      411:   80:  if (numPlayers == 2)
branch  0 taken 100%
branch  1 taken 0%

where are in some places this presentage varies based on the case , example:

4428:  535:  if (state->deckCount[player] <= 0){
branch  0 taken 1%
branch  1 taken 99%



A brief list of my findings on the not covered part of my dominion.c:

1) struct gameState* newGame() is not covered, since I greated and initialized all the game states
	inside my test units.
2) initializing the kingdomCards never exeuted, since I initialized this array inside my test units.

3) The line that checks the if the number of player ( > MAX_PLAYERS or < 2 ) is not covered.
4) Checking the selected kingdom cards are different didn't get covered since when initialized
	I set them to be different.

5) All the setting for the cards (curses, estate , duchy ..etc) for players more that 2 is not covered.

6) The handCard() did not get covered since we initialized the type of the card passed to all function 
	based on each test case, so we didn't call this function during our test the coverage resutl = 0.

7) Most of the cards code in the cardEffect() is not covered, each of those cards had some inline valriables
that is not covered also.

8) Most of the game functions did not get covered, examples(supplyCount, getCost, getWinners, isGameOver, endTurn, numHandCards and buyCard)

9) All the (DEBUG) messages did not get covered since we didn't get a case where we can test and edge case or
	a case that is out of range.
