/* Refactoring and Bugs
------------------------------------------------------------------
adventurerCard() bugs
1. Allows an additional card draw: 'while(drawntreasure<2)' changed to 'while(drawntreasure<=2)'
2. Always shuffles discard pile into deck. Assignment operator '=' instead of the equality operator '==' used: '(state->deckCount[currentPlayer] <1)' changed to '(state->deckCount[currentPlayer] =0)' . 

------------------------------------------------------------------
smithyCard() bugs
1. Added condition that 3 card are drawn before Smithy is discarded from hand: if(i == 3){}. In situations where player may not be able to draw 3 cards, condition will not be met and discardCard() will not run.
2. Smithy is discarded into trash: 'discardCard(handPos, currentPlayer, state, 0)' changed to 'discardCard(handPos, currentPlayer, state, 1)'

------------------------------------------------------------------
councilRoomCard() bugs
1. In two-player games, the only other player will draw 1 card as normal. When there are more than two players, only the next player will draw a card.

	for (i = 0; i < state->numPlayers; i++){
		if ( i != currentPlayer ){
			drawCard(i, state);
	    }
	}

changed to

	int nextPlayer = currentPlayer + 1;
	if (nextPlayer > state->numPlayers - 1){
		nextPlayer = 0;
	}
	drawCard(nextPlayer, state);
	
2. Added condition that 4 card are drawn before Council Room is discarded from hand: if(i == 4){}. In situations where player may not be able to draw 4 cards, condition will not be met and discardCard() will not run.
	
------------------------------------------------------------------
treasurerMapCard() bugs
1. Gold cards are added to discard pile instead of the deck: 'gainCard(gold, state, 1, currentPlayer)' changed to 'gainCard(gold, state, 0, currentPlayer)'
2. Skips checking first card to see if it is a treasure map card: 'for (i = 0; i < state->handCount[currentPlayer]; i++)' changed to 'for (i = 1; i < state->handCount[currentPlayer]; i++)'

------------------------------------------------------------------
villageCard() No bugs introduced

*/