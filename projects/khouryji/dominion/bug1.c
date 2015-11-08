'Unit Test 1 (Test for endTurn):
---------------------------------------------------------------------------------------
	I found that the handCount for the next player didnt always
	come out to 5 like its supposed to. About 1 out of 10 times
	the handCount will be something less than 5.

	Also, in terms of the design of this game, it looks like played
	cards dont get put back into the discard pile even though 
	playedCard Count gets set to 0 in this function. Only hand cards
	are put into the discard pile in this function.

Unit Test 2 (Test for drawCard):
---------------------------------------------------------------------------------------
	I found that when the deck was empty, the deckCount
	remained at 0, and then the handCount was not increased by 1.

Unit Test 3 (Test for discardCard):
---------------------------------------------------------------------------------------
	No bugs found.

Unit Test 4 (Test for gainCard):	
---------------------------------------------------------------------------------------
	No bugs found.

Card Test 1 (Smithy)
---------------------------------------------------------------------------------------
	My cardtest picks up that an unauthorized modification to a different users hand
	is happening.

	My cardtest misses, something though. The hand should be gaining three cards, but
	losing smithy, for a net gain of 2. I check if there is a netgain of 2, and there
	is, but for the wrong reason. In my refactor.c I note that I intentionally set smithy
	to draw only 2 cards. So if the function was working as it should, but with only 2
	cards drawn, it should then discard smithy for a net gain of 1, which is not what
	happened.

Card Test 2 (Adventurer)
---------------------------------------------------------------------------------------
	I had to change two of the bugs I introduced in refactor.c because they were
	preventing they were causing segfaults. (I had decreased the array size of temp hand
	and I incremented the player number which ended up incrementing out of bounds.
	I had also increase the number of treasures needed and this sent it into an infinite loop 
	so I took that out)
	
	I found that the handcount did not increment properly

	I also found that the last two hand cards were not treasure as they should have been
	
	This function doesnt seem to take the adventurer card out of the hand and put it either
	into the played deck or the discard pile for this player.

Card Test 3 (Steward)
---------------------------------------------------------------------------------------
	I picked up on both the bugs I inserted. The function draws 1 of the two cards 
	into player 1s hand. And it only add 1 coin instead of 2.

	I also picked up that the discardCount was not incrementing properly
	and the playedCards were changing for some reason.

Card Test 4 (Steward)
---------------------------------------------------------------------------------------
	I caught the bug that I introduced, incrementing playedCardCount for no reason.

	I also seem to have found that numActions does not increment properly.