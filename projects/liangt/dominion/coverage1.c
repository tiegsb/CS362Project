/*

initilizeGame() takes 15.41% of 584 (90 lines)

unittest1:
	15.75% of 584 lines covered
	2 lines different from initilizeGame()
	More lines should have been executed since the deck successfully shuffled
	and shuffle() is over two dozen lines with newlines

unittest2:
	17.47% lines covered
	10 extra lines covered from previous (unittest1)
	This is not bad considering isGameOver() is 26 lines with newlines

unittest3:
	19.35% lines covered
	Again, not bad given the size of the discard function

unittest4:
	23.46% lines covered
	scoreFor is 39 lines with few newlines; the unit test adequately reflects that

cardtest1:
	24.83% lines covered
	buggySmithy() is a tiny function, so this is not unexpected

cardtest2:
	29.79% lines covered
	Though this looks like it would cover the function well, I didn't
	test if any card in the deck is not a treasure card
*/