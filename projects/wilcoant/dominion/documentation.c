/*****************************************************************
smithy:
    Description:
    Base configuration for this card has it in a switch statement with case (smithy) invoking the playing of the card.
    The card's effect on game play occurs as a result of the value of passed variable "card" to the function cardEffect.  This will remain
    unchanged, however future configurations will have conditionals that evaluate the "card" variable and if necessary, 
    a function call to play_smithy is made rather than via switch.  refactor.c will contain documentation for such changes. 
    
    Actual game functionality of the smithy card is to draw three cards. 
    It will discard the smithy card and add three new cards to the 
    current player's hand.
    Input: (none by player) integer - currentPlayer (integer result from helper: whoseTurn(state), tells whose turn it is)
    state - struct containing full game members, see dominion.h for vars
    handPos - int position in players hand of the card being played
    ** uses helpers discardCard and drawCard
    Output: none, discards smithy and adds 3 cards to players hand.
    
adventurer: 
    Description: 
    Base configuration for this card has it in a switch statement with case (adventurer) invoking the playing of the card.
    The card's effect on game play occurs as a result of the value of passed variable "card" to the function cardEffect.  This will remain
    unchanged, however future configurations will have conditionals that evaluate the "card" variable and if necessary, 
    a function call to play_adventurer is made rather than via switch.  refactor.c will contain documentation for such changes. 
    Actual game functionality of the card is to reveal cards from the deck
    until two treasure cards are revealed. Those two cards are put into 
    the players hand and then the remaining drawn (non treasure) cards are discarded.
    
    A while loop uses a drawntreasure integers to keep track of drawn
    treasures for the copper, silver, or gold cards drawn, once two are 
    drawn the loop terminates.  The deck is shuffled if the end is reached.
    A temp hand array stores all drawn cards.  It gets emptied after
    the treasure cards are added to the player's hand. 
    helpers: drawCard, shuffle
    input: gameState *state, int card 
    output: two new treasure cards are added to the players hand.

discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag):  
    Description:  cards may be either discarded to a discard pile or 
    trashed.  If not trashed they get added to the played card count.
    The function first evaluates the trash flag, if not trashed the card
    has been played and the played card count is incremented and the 
    players hand position and card count are updated.  
    Regardless of whether trashed or not, the players hand must 
    be decremented.  If the card being discarded is either the last
    card or there is only one card remaining is the player's hand,
    the player's handcount is reduced by one card.  For all other 
    player hand counts ( > 1) the player's hand is updated to replace
    the discarded card in its array pos with the last card in the player's hand
    and the last card gets the -1 sentinel. The handcount is 
    reduced by one.
    Input: none by player, integers for the player, pos in hand and the trash flag along with the pointer to gameState
    Output: the player's hand is reduced by one and appropriate updates
    are made to the players hand count and hand positions. 

updateCoins(int player, struct gameState *state, int bonus):
    Description: resets players coin count to 0.  It then 
    iterates over the player's hand using enum variables 
    copper, silver, and gold to add coins to the state member 
    variable "coins".  state->coins gets 1 for each copper, 2 
    for each silver, and 3 for each gold.  
    Player bonus coins are added to coins once iteration over
    the complete deck is concluded. 
    input: int player - which player's deck, gameState pointer which contains
    the members for the actual deck. and int bonus which is the 
    number of bonus points to add to state->coins 
    output: none, state->coins gets updated to contain the total number
    of coins the player has in their hand.
    
******************************************************************/