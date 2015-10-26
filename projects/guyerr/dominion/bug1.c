/*
Name: Rhett Guyer
Class: CS 362
Date: 10/25/15

Goal: Bug Report after testing.
*/

Unittest 1
	- I did not find any bugs in unit test 1 which was designed to test the drawCard function.
	
Unittest 2
	- I did not find any bugs in unit test 2 which was designed to test the getCost function. 
	
Unittest 3
	- I did not find any bugs in unit test 3 which was designed to test the updateCoins function.
	
Unittest 4
	- I did not find any bugs in unit test 4 which was designed to test the shuffle function.
	
Cardtest 1
	- I did find an issue with the smithy card. The problem seems to be when the smithy card is in a hand position greater than 2.
	I found this bug by checking to see if the smithy card was being removed and for the fourth and fifth cases it was not. 
	Hand count was correct so it could be that the wrong card is being removed.
	
Cardtest 2
	-Cardtest 2 was designed to test the adventurer card. I found an issue where the card failed to add enough treasure cards to the players hand.
	This is a card function that I changed when I removed the shuffle part of the function. The only time the adventurer card seemed to have a problem was
	when the deck count was set to 0. 
	
Cardtest 3
	- Cardtest 3 was designed to test the council room card and I did not find any bugs in the card.
	
Cardtest 4
	- Cardtest 4 tests the village card. The only issue I found with this card was that the number of coins in the gamestate was altered by this card.
	This is odd since card does not say anything about a bonus or reduction in coins.