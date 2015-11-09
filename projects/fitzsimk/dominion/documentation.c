/*  fitzsimk
    documentation.c
*/
  /*	Smithy
   *	Costs: 	4 coin
   *	Type: 	action card
   *	Action: user can draw three cards when played
   *
   *
   *
   * */

   /*	Adventurer
    *	Costs:	6
    *	Type: Action Card
    *	Action: player continues to draw and discard cards until two treasure cards are drawn
    *
    */


   /*	discardCard
    *   params: current player, state, trash flag, hand position
    *   1. if card is not trashed add to played pile
    *   2. set the position of the played card in the player's hand to -1
    *   3. if the discarded card was the last card or the second to the 
    *      last card, --the card count
    *      else replace discarded card to the last card in the hand
    *      set last card to -1
    *      --the card count
    */

   /*	updateCoins
    *
    *   takes player, current game state, bonus
    *   1. resets state coin coin
    *   2. iterates over each card in the player's 
    *   hand and checks if it is copper, silver,
    *   or gold (a treasure card) and adds the values
    *   of the treasure card to the state total
    *   3. adds the bonus amount to the state total
    */
