Adventurer Card
	this card draws up to 2 treasure cards
		it draws cards until it has 2 treasure cards
		or
		until there are no more cards left in the deck (including after a reshuffle)
		
		
	First loop
		if the stack is empty, it will shuffle the discard and form a new deck
		then it draws a card
		
		if the card is a treasure card (copper, silver, or gold)
			the treasuredrawn is incremented
		else the card is placed into the 'temphand' for tracking
			the player hand is decremented 	// removing the copy from the players hand
			z is incremented 				// z is the tracker for the temphand
			
*note* there may be bugs involved with a deck that has less than 2 treasure left to be drawn from the deck and discard combined.
	
	Second loop
		temphand is emptied 1 card at a time into the current player's discard
		
	The Adventure Card is removed from the hand via function discard(...) and then placed into the discard pile from there
		
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Smithy Card
	this card draws up to 3 cards.
	*note* it is highly unlikely for there to be less than 3 cards in the deck and discard combine
			However, due to the Church card for massive card removal from play, it is possible.
			
	For loop to draw exactly 3 cards using a for loop
	
	then the Smithy Card is removed from the hand via function (discard...) and placed into the discard pile from there.
	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int updateCoins(int player, struct gameState *state, int bonus)
	initializes total coins to 0
	
	then it adds 1 to the coin total for each copper in the player hand
	then it adds 2 to the coin total for each silver in the player hand
	then it adds 3 to the coin total for each gold in the player hand
			
	then it adds any coin bonuses that there may be
	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)
	if card was trashed, send card to played pile (discard)
		increment playedCard amount
		
	set played cards to -1 			//assumed that the card is at the end of the array
	
	if the card was played from the array (or hand)
		decrement the array handCount of current player by 1
		*note* if the state of the handcount is the last card or more than 1 card
	else
		discard tg
	
	
