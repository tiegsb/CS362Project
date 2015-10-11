/*
Documentation:

----Cards:
smithy
When the card smithy is played the switch statement executes a for loop which loops 3 times.
For each loop the drawCard function is called.
After the for loop the discardHand functions is called.
At the end a return statement is given to exit the cardEffect function.

adventurer
First a while statement loops while drawntreasure is less than 2
	First thing in the while loop is to check if the player's deck is empty. If it is shuffle discard into deck.
	Next, player draws a card
		if player draws a coin (silver, copper, or gold) drawntreasure is increased by 1)
		If the drawn card was not a treasure, temphand is set to the drawn card and the most recent drawn card is removed
The last part of the card code is a while loop that dicard all cards  in play that have been drawn


----Functions
discardCard()
First the function checks if the card is "trashed". If it is not the card is added to the play pile.
played card variable is set to -1 for future use.
Then a if else block is used remove card from player's hand
If the last card in the player's hand was played or they only have 1 card then their hand size is decreased by 1.
Otherwise 
	last card in hand becomes the discarded card
	last card gets set to -1
	player hand size is reduced by 1


updateCoins()
Coin count is set to 0
A for loop runs for each "treasure" in players hand.
Each time the for loop runs the program checks if the coin was copper, silver, or gold. 
The program adds 1, 2, or 3 based on the coin type.
*/
