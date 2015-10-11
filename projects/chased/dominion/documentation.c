/* <<<Instructions copied over for easier reference>>>
 * Submit a file called documentation.c that contains documentation of smithy, adventurer cards. Documentation should contain your 
 * understanding of smithy and adventurer cards (code). It should also contain documentation of your understanding of discardCard() 
 * and updateCoins() method. 
 * Keep your documentation short, though there is no upper limit. Documentation.txt file should contain at least 100 words.  
 */
 
 Dustin Chase
 CS 362 
 Assignment 2
 Documentation
 
 smithy card
 When played, the smithy card causes the player to draw three more cards. The code implements this action by placing the drawCard function
 into a loop which repeats three times. The smithy card is then moved to the discard pile by calling the discardCard function. 
 
 adventurer card
 When played, the adventurer card causes the player to turn over cards from the player's deck until the player reveals two 
 treasure cards. The treasure cards are placed in the player's hand and the other revealed cards are placed in the discard pile. 
 
 The code implements this card in a while loop. As long as the number of treasure cards drawn is less than two, the loop runs. First, the 
 deck is checked to make sure there are cards left. If not, the discard is shuffled and added to the deck. A card is then drawn. If the card is 
 any of the treasure cards, the count of treasure cards is incremented. Otherwise, the card is added to a temporary hand. 
 
 When the number of treasure cards reaches two, all the cards in the temporary hand are placed in the discard pile in a while loop. Note that 
 player is given 7 treasure cards on the initial deal so the player is guaranteed to have at least 2 treasure card in their hand. 
 
 discardCard() method
 This function discards a card from the player's hand. If the trashed flag is not set, the card is moved to the played pile.  
 
 The card position in the player's hand is set to -1 to indicate that it is no longer in the player's hand. The function then checks if the 
 card is the last card in the player's hand. If so, the player's hand count is decremented. The hand count is also decremented if the player 
 only has one card in their hand. If neither of these apply the the discarded card is replaced with the last card, the last card is set to be 
 no longer in the hand, and the number of cards in the hand is decremented. 
 
 updateCoins method
 This function counts the total number of coins in the player's hand. It also adds any bonus indicated in the function call. 
 The function loops through the player's hand. If the loop encounters a treasure card (copper, silver, or gold) the coin 
 count is increased by the corresponding amount. The bonus is then added to the total. 
 
 
 