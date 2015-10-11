/*
------------------------------
documentation.c
Assignment 2
jenkinch
------------------------------

Smithy:
    The Smithy is an action card that can be played to draw three cards. In the
    code, this is implemented as a for-loop that iterates three times, each time
    calling the drawCard() function for the currentPlayer. The Smithy itself is
    finally discarded with a call to the discardCard() function.
    
Adventurer:
    The Adventurer is an action card that allows the user to keep revealing cards
    from the deck until two treasure cards are found. Those two cards are added to
    the user's hand and the rest are discarded. In the code, the drawing part of
    the action is wrapped in a while loop that on each iteration checks if two
    treasure cards have been drawn. Within that loop, we first check
    currentPlayer's deckCount to ensure the deck is not empty. If it is, we call
    the shuffle() function. Next drawCard() is called and it is taken off the top 
    of currentPlayer's hand and stored in the cardDrawn variable. The cardDrawn
    is checked with an if-else block to see if it is a treasure card. If so, the 
    count of drawn treasure cards is incremented by one. Otherwise, the card is
    stored in a temporary hand and removed from the player's hand. We then
    increment by one a counter variable z. Then we leave this while-loop and
    are met with another while-loop that decrements z on each iteration until
    it reaches zero, each time a card in the temporary hand is discarded and
    the player's discard count is updated.
    
discardCard():
    This function takes in four parameters: a number indicating the position of a 
    card in a player's hand to be discarded, the currentPlayer, the game's state, 
    and a trash flag. First, it check's the trash flag, and if it is not set, the 
    card to be discarded is added to the played pile and the played card count is
    incremented by one. We mark the played card with a -1 hand position value. The 
    rest of the function plays out in an if-else block. The first if and else if
    blocks decrement the currentPlayer's handCount by one if the card played was
    the last in the player's hand or if the player only has one card in hand, 
    respectively. Otherwise, the hand position where the discarded card was 
    removed is replaced the the last card already in the hand. That card's 
    position is then given a -1 value and the currentPlayer's handCount is 
    then decremented.
    
updateCoins():
    This function takes in three parameters: a player integer, the game's state,
    and an integer bonus. The function first resets the coint count to zero. Next,
    it enters a for-loop which iterates through the cards in the player's hand. 
    At each card, it checks to see if it is a copper, silver or gold card and 
    increases the coin count by one, two or three, respectively. Finally, the
    bonus amount is added once to the coin count.
*/