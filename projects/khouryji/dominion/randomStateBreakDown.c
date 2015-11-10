struct gameState {
  
/*Cases:

	case < 2
	case > MAX_PLAYERS
	BULK SHOULD BE IN BETWEEN

	changes from before
*/	
  int numPlayers; 



  //number of players
  /*Cases:

	case <= 0
	case > MAX_deck
	case changed from what it was

	changes from before
*/	
  int supplyCount[treasure_map+1];  //this is the amount of a specific type of card given a specific number.
  
  /*Cases:

	case <= 0
	case > MAX_deck
	BULK IN BETWEEN

	changes from before
*/
  int embargoTokens[treasure_map+1];
  
  /*Cases:

	case <= 0
	case > MAX_deck
	BULK IN BETWEEN

	changes from before
*/

/*Cases:

	case <= 0
	case > MAX_deck
	BULK IN BETWEEN

	changes from before
*/
  int outpostPlayed;

  /*Cases:

	case != NUMPLAYERS
	case < 2
	case > MAX_players
	BULK IN BETWEEN

	changes from before
*/
  int outpostTurn;

  /*Cases:

	case != NUMPLAYERS
	case < 2
	case > MAX_players
	BULK IN BETWEEN

	changes from before
*/
  int whoseTurn;

  /*Cases:

	case < 0
	case > 2
	BULK IN BETWEEN

	changes from before
*/
  int phase;

  /*Cases:

	case < 0
	case > 200
	BULK IN BETWEEN

	changes from before
*/
  int numActions; /* Starts at 1 each turn */

	/*Cases:

	case < 0
	case > 25
	BULK IN BETWEEN

	changes from before
*/
  int coins; /* Use as you see fit! */

	/*Cases:

	case < 0
	case > 25
	BULK IN BETWEEN

	changes from before
*/
  int numBuys; /* Starts at 1 each turn */

	/*Cases:

	completely random within card enum
	BULK IN BETWEEN

	changes from before
*/	
  int hand[MAX_PLAYERS][MAX_HAND];

  	/*Cases:

	case < 0
	case > MAX_HAND
	case > 25
	BULK IN BETWEEN

	changes from before
*/
  int handCount[MAX_PLAYERS];
  int deck[MAX_PLAYERS][MAX_DECK];

  /*Cases:

	case < 0
	case > MAX_DECK
	BULK IN BETWEEN

	changes from before
*/
  int deckCount[MAX_PLAYERS];
  int discard[MAX_PLAYERS][MAX_DECK];

  /*Cases:

	case < 0
	case > MAX_DECK
	BULK IN BETWEEN

	changes from before
*/
  int discardCount[MAX_PLAYERS];
  int playedCards[MAX_DECK];
  int playedCardCount;
};