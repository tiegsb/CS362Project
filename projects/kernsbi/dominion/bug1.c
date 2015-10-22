Billy Kerns
bug1.c

1.  scoreFor():
		Line 449 is "for (i = 0; i < state->discardCount[player]; i++)" and should be "for (i = 0; i < state->deckCount[player]; i++)"

2.  discardCard():
		Player discardCount is not incremented

3.  adventureCard():
		No shuffle counter so it will just run and do some weird stuff.  As per the rules the deck should be shuffled once
		and if a second treasure card is still not found then the player only gets the one treasure.

		Does not discard adventureCard after it is played.

4.  smithyCard():
		Played card count not incremented.  User implemented bug.

5.  village:
		Player discard count is off due to discardCard() function not incrementing discardCount

6.  great hall:
		Player discard count is off due to discardCard() function not incrementing discardCount
