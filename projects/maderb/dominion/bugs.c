BUGS! Unit testing on dominion.c

cardtest1.c
	--Shows that the card is not added to the discard pile as it should be. Rather, the following card in the user's hand is discarded.
cardtest2.c
	--Too many treasure cards are drawn (draws 3 rather than 2).
	--Does not add itself, as it is discarded, to the discard pile.
cardtest3.c
	--Does not discard targeted card as it should AND neither card registers in the discard pile.
cardtest4.c
	--Discards incorrect card (discards the card to its' right instead of itself).
	
unittest1.c
	--None
	
unittest2.c
	--Incorrect score collected from discard pile.
	--Incorrect value collected from deck.
	--Incorrect value calculated by gardens.
	
unittest3.c
	--Player 1 does not win when winning card in deck (due to error in scoreFor not computing deck score properly)
	--Players do not tie when they should have the same score (see errors in scoreFor).
	
unittest4.c
	--None