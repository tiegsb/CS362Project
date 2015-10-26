/*

unittest1.c - SmithyCard()
1 - Smithy gives four cards instead of 3
	- I introduced this error though in refactor.c
	
2 - Smithy isn't in any of player 1's piles so it's like it was discarded but 
    it didn't go anywhere in the player piles

unittest2.c - adventurerCard()
1 - Adventurer isn't removed from hand
2 - Gold cards are not removed as treasure
	- I introduced this error
	
unittest3.c - council_roomCard()
1 - 5 cards are drawn 
	- I introduced this
2 - council_room isn't in any of player 1's piles so it's like it was discarded but 
    it didn't go anywhere in the player piles
	
cardtest4.c - sea_hag()
1 - curse cards are not put ontop of player decks

2 - sea_hag isn't in any of player 1's piles so it's like it was discarded but 
    it didn't go anywhere in the player piles
	
	
unittest1.c - isGameOver()
No bugs found

unittest2.c - discardCard()
1 - Failed unittest checking if all players received a starting hand at game initialization
	- Further exploration showed endTurn() needed to be called to look at player card counts
	  according to whose turn it is
	  
2 - Discarded cards don't appear to discard correctly 
	- The discards appear to just leave the player's piles
	- Maybe it's due to whose turn it is too
	
unittest3.c - gainCard()
found no bugs but an inconsistancy
	- problem involved endTurn() not taking a hand of 5 cards until next turn
	  which technically is not the way dominion plays
			- cards are given to the player at the end of the round and waits for 
			  next turn
			  
unittest4.c - scoreFor()
1 - cards in hand are computed with the correct score, however deck and discard
	sets are not computed at all

*/