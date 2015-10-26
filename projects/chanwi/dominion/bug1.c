/* Bugs

isGameOver() - There instances where there are three empty stacks and the game will continue. For instance, the treasure map card is not counted towards the empty count stack. The function may not be looping over all cards for current count.

scoreFor() - The function is not counting the victory cards in the discard pile.

adventurer - I introduced a bug in assigment 2 that prevented cards from being drawn from the deck. Therefore no treasure cards can be drawn and placed into hand. TheThe unit test found the bug.

council_room - I introduced a bug that in assignment 2 that games with more than 2 players, only the second player will draw an additional card. Player 3 and so forth will not gain cards. The unit test found the bug.

discardCard() - Although I did not create a unit test for discardCard(), the all my cardtests were failing to account for the discard part of the card effect. There may be a bug where the discarded card is not being accounted for correctly.

*/