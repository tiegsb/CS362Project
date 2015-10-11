/*
 * Filename: documentation.c 
 * Author: Joseph Barlan (barlanj)
 * Description: This file contains documentation for dominion architecture.
 *
 *
 * INDEX
 * ======================================================================================================
 * 1.0 - CARDS PROFILE
 * 		1.01 - Smithy
 *		1.02 - Adventurer
 * 2.0 - METHODS
 *		2.01 - discardCard()
 *		2.02 - updateCoins()
 * ======================================================================================================
 *
 *
 *
 * ======================================================================================================
 * 1.0 - CARDS PROFILE
 * ======================================================================================================
 *
 * 1.01 - Smithy Card
 * ------------------------------------------------------------------------------------------------------
 * Cost to obtain: 4
 * Type: Action Card
 * Ability: +3 Cards
 * 
 * By playing this card, the player is allowed to draw three additional card and put them in his hand.
 * This is best played if lacking in gold to buy new card, or after playing another card with a +action
 * ability. Playing this card first will not grant any further actions to be taken after.
 *
 * dominion.h:	enum value = 12
 * dominion.c:	Inside cardEffect(), smithy's ability is defined by calling drawCard() 3 times,
 *				then the discardCard is called to discard it from the player's hand.
 * 				Cost of card is obtained from getCost, which will return 4 for smithy.
 *			   	
 *
 * 1.02 - Adventurer Card
 * ------------------------------------------------------------------------------------------------------
 * Cost to obtain: 6
 * Type: Action card
 * Ability: Reveal cards from the deck until 2 treasure cards have been revealed. 
 *          Put those Treasure card into your hand and discard the other revealed cards.
 *
 * This card allows the player to get 2 treasure cards from the deck and place them into his hand.
 * 
 * dominion.h:	enum value = 7
 * dominion.c:	Inside cardEffect() adventurer case contains a while loop that checks wether 2 treasure
 * 				cards have been revealed. While it is not the case, it first checks wether the deck is
 * 				empty - if it is then it shuffles the deck. It then calls drawCard to draw a card from the deck
 *				and the card is then check if it is a Treasure card. If it is, then the variable 'drawnTreasure'
 *				is incremented. If it is not a treasure card, then the card drawn is added to the tempHand. Once
 *				2 treasure cards have been drawn, a while loop is run to discard all drawn cards in the tempHand.
 *
 *
 *
 * ======================================================================================================
 * 2.0 - METHODS
 * ======================================================================================================
 *
 *
 * 2.01 - discardCard()
 * ------------------------------------------------------------------------------------------------------
 * Parameters: int handPos, int currentPlayer, struct gameState *state, int trashFlag
 *  
 * 				handPos - card's position in the player's hand
 *				currentPlayer - the current player's id
 *				*state -  the current game's state (see dominion.h for struct)
 *				trashFlag - <1: adds card to played pile
 *							>1: put the card in the trash
 * 
 * Description: This method first checks the trashFlag. If the flag is set to less than 1
 * 				then the card is placed into the Played Pile and the counter for played card is
 * 				incremented. The position of the current hand is then set to -1. Then if the card played
 * 				was the last card in the player's hand or it was the only card in the player's hand, then
 *				that card is removed from the player's hand. Otherwise, the discarded card is replaced
 *				with the last card in hand.
 *
 * Function: To discard a card from hand to the Played pile or the Trash pile.
 *
 *
 * 2.02 - updateCoins()
 * -----------------------------------------------------------------------------------------------------
 * Parameters: int player, struct gameState *state, int bonus
 *
 * Description:	This method loops over the handCount of the player and checks for
 *				copper, silver or gold treasure cards. When any of these are found in
 *				the player's hand, an appropriate value (c=1, s=2, g=3) is added to the
 *				game state's coin counter.
 *				After the hand's cards have been evaluated, any passed bonus amount is
 *				added to the game state's coin counter before exiting.									
 *
 * Function: To update player's played coin 'balance' for purchasing other cards from
 *			 their played Treasure cards.
 *         
 /