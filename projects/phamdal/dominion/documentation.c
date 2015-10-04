Dalena Pham
CS 362 - Assignment 2

Smithy - 
	When the current player wants to use the "Smithy" card, the smithy branch case will execute in the switch statement within 
	cardeffect(). "Smithy" allows the current player to draw 3 more cards to their current hand. This is accomplished in code by
	running a for loop 3 times and calling the drawCard() function each time. This adds 3 random cards to the hand. After this 
	loop, the "Smithy" card is discarded from the hand and back into the current player's deck by calling discardCard(). 

Adventurer - 
	Like the "Smithy" card, when the current player wants to use "Adventurer", the adventurer branch case will execute in the 
	switch statement within cardeffect(). 
	
  To achieve the "Adventurer" effect, the code begins with a while loop. The while loop keeps a count of the number of treasure 
  cards drawn so far, from the start this variable should be 0. The function first checks if the deck is empty. If it is, the 
  function will shuffle the discard pile and add back to the deck. After that check, it draws a card and takes note of it's
  position in the hand. If the card is indeed a treasure card, the number of drawn treasure cards is incremented. Otherwise, 
  the that was card drawn is taken out of the player's hand and put into a temporary hand. A variable that keeps count of the 
  number of non-treasure cards in the temporary hand is incremented (size of the temporary hand). 
  
  Once 2 treasure cards are finally drawn, the while loop is finished and the program then goes into another while loop to 
  discard each card from the temporary hand back into the current player's deck. This last while loop continues until there are
  no more cards in the temporary hand (size is equal to 0). 

discardCard() - 
	The first event that occurs in this code is that the function determines what kind of "discard" is going on, checking to see 
	if the card passed is going to be trashed or not. If it is not trash then the card is put into a global played cards pile. In
	either case, the function will set the state of the card to -1 so that it cannot be further used. If the discard card was not
	the last or only card in the hand, the function will switch the last card in the hand with the discard card, ensuring in the 
	process that it is equal to -1 again. In all cases the number of cards in the hand is decremented. 

updateCoins() - 
	The function begins by resetting any previous coin count to 0 and then proceeds to check for treasure cards in the current 
	player's hand. If a treasure card is found, the appropriate amount is added to the coin count. At the end, if a bonus was 
	passed into the function, this is also added into the final count. 
