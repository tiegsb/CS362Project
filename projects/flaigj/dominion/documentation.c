/*
Author: Jason Flaig

   Adventurer card
   Iterate through while loop when treasure cards in hand ie. drawntreasure < 2
		If the current players deck is empty
			shuffle
		Then draw a card
		cardDrawn is the last or top card drawn
		
		if the cardDrawn is a treasure card ie. copper, silver, gold
			increment drawntreasure
		
		else
			cycle through and create a temp hand and initialize the temphand 
				cards to cardDrawn or last card
			Remove the last cardDrawn
			iterate the counter for each card
	end the loop if drawntreasure < 2
	
	while player still has cards
		discard each card
		decrement the temp card counter or just remove each card

		
   Smithy card
   Draws a card 3 times if played
   or iterates the drawCard function 3 times
   
   
   Function: int discardCard
   if card is trashed
		add the current card played in position as played
		increment the playCardCount

   set the played card to -1
   
   if the last card in the hand is played 
		then decrement the number of cards in hand
   
   else if only one card in hand
		then decrement the number of cards in hand
   
   else
		Replace discarded card with the last card in the hand
		Set last card to -1
		Decrement number of cards in hand
   
   Function: int UpdateCoins 
   Coins are first initialized to 0
   Next based on whether a copper, silver or gold card is played
   the coins are incremented to the total coins by 1, 2 or 3 respectively by card
   Finally, any bonus coins from a kingdom card are incremented as additional coins
   
 * /