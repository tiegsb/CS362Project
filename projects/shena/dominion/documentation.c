/*
Author:  Andrew Shen
File:  documentation.c
Assignment 2
Date:  11 October 15
Notes:  Documentation of smithy effect, adventurer effect, discardCard(), updateCoins()
*/

/************************************************
* Smithy - This card allows a player to draw three cards. This is done using a for loop 
*          to allow a user to draw a single card three times by calling the drawCard() function. 
*          After the loop is finished the Smithy card is then placed in the discard pile using the
*          discardCard() function.
************************************************/

/************************************************
* Adventurer Card - This card allows a player to continually draw cards until two treasure cards 
*                   are drawn. This is done using a loop that runs until two treasure cards are 
*                   placed in hand. All non-treasure cards are placed in a temp hand pile and are
*                   discarded.
************************************************/

/************************************************
* discardCard() - This function checks to see if the trash flag is set. If so, the card is trashed,
*                 that is, permanently removed from the deck. If not, the card is marked as played 
*                 then discarded. Player's card count is decremented accordingly and card positions
*                 are maintained.
************************************************/

/************************************************
*updateCoins() - This function resets coin count then sums the coin count in hand according to 
*                value the treasure cards in hand (copper, silver, gold). It then applies bonus
*                coins to the count if applicable.
************************************************/