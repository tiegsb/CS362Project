#documentation.c
#Woo Choi
#SE II CS362F15
/*

Smithy: Draws 3 cards from deck. 
	
	
	1. getCost(int cardNumber)
		- returns the cost of the smithy card
		- case smithy returns 4
	

	2. cardEffect(int card, int choice1, int choice2, int choice 3, struct gameState *state, int handPos, int *bonus)  
	  code: 
		//////////////
		case smithy:
			for (i = 0; i< 3; i++)
			{
				drawCard(currentPlayer, state);
			}
			
			discardCard(handPos, currentPlayer, state, 0);
			return 0;
		//////////////
		
		-Under cardEffect(), is the main function of smithy.
		-for loop calls drawCard() 3 times. 
		-drawCard() draws new cards from deck.
	
	input:
	output:

*/

/*

Adventurer: draw cards from deck until you get 2 treasure cards

	1. getCost()
		-returns the cost of the adventurer card
		- case adventurer returns 6
	
	2. cardEffect()
	  code:
	//////////
		case adventurer:
			while(drawntreasure<2){
				if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
					shuffle(currentPlayer, state);
				}
				drawCard(currentPlayer, state);
				cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
				if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
					drawntreasure++;
				else{
					temphand[z]=cardDrawn;
					state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
					z++;
				}
			}
			
			while(z-1>=0){
				state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
				z=z-1;
			}
			return 0;
	///////////		
		
		-Before the switch/case, drawntreasure is set to 0.
		-First while loop
			* if less than 2 drawn treasures proceed
			* checks for the deck count of the current player, shuffle if necessary
			* draw a new card from the deck
			* check the newly drawn card
			* if it's a treasure card (copper, silver, gold) then drawntreasure++
			* if not, then do nothing to drawntreasure variable, subtract 1 from handCount (which was the top card of the deck)
		-Second while loop
			* it's for discarding all the cards in play that have been drawn.
			* z was set as 0 in declaration of z prior to above code.
	

*/

/* 

discardCard() : Validate the card being played, and remove card from player's hand
	1. checks for trashFlag
		- if card is not trashed, then add it to played pile
		- code: state->playedCards[state->playedCardCount] = state->hand[currentPlayer][handPos];
				state-> playedCardCount++;
		
	2. remove card from player's hand
	3. return 0;
	
	inputs: handPos, currentPlayer, gameState, trashFlag
	
*/

/* 

updateCoins() : Return the count of a specific card in player's discard deck and hand
	1. for loop from 0 to handCount
		- counts player's coins (copper, silver and gold)
		- and add bonus
	
	inputs: player, gameState, bonus
*/