Jason Gourley
gourleja@oregonstate.edu
CS362-400
Assignment 2 - documentation.c

-------------------------------------------------------------------------------
Cards
-------------------------------------------------------------------------------

Smithy Card

    name:           Smithy
    value:          0
    purchase cost:  4 coins
    card type:      Action

    ability:        When used during the player's action phase the player draws
                    3 cards from their own deck, placing the 3 cards into their
                    current hand of cards


Adventurer Card

    name:           Adventurer
    value:          0
    purchase cost:  6 coins
    card type:      Action

    ability:        When used during the player's action phase the player reveals
                    cards from their deck until 2 treasure cards are revealed.
                    The 2 treasure cards are added to the current hand of cards,
                    while the rest of the cards drawn are placed in the discard pile.

                    If the deck needs to be reshuffled do not add the drawn cards to
                    the discard pile.  If after a reshuffle there is not a second
                    treasure card found the player receives only a single treasure card.

-------------------------------------------------------------------------------
Methods
-------------------------------------------------------------------------------

discardCard()

    signature:      int discardCard(int handPos, int currentPlayer, struct gameState *state,  int trashFlag);

    precondition:   Method is passed the player, the card's position in their
                    hand, current game state, and a trash flag

    postcondition:  The passed card is removed from the player's hand and placed
                    into the played cards pile or discard pile.

    description:    The method will move a player's card from their hand to either
                    the played cards pile or discard pile based on the passed
                    trashFlag.  For flag values, trashFlag == 0 move the card to
                    the played pile and where trashFlag > 0 the card is discarded.
                    The player's card count is then decreased and the game state
                    updated as needed.


updateCoins()

    signature:      int updateCoins(int player, struct gameState *state, int bonus);

    preconditions:  Method is passed the current player, current game state,
                    and any bonus coins from action cards

    postconditions: The player's coins from their current hand and any bonus
                    coins are added to the played field.

    description:    The game state coins are first reset to zero.  The player's
                    current hand is traversed and any available treasure cards
                    are added to the player's played field as well as any bonus coins.
