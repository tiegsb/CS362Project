/*
Brian Tiegs
CS 362 - Assignment 2

Documentation

Smithy card
  Card effect description:
    The player draws 3 cards from the deck and adds them to their hand.

  Card implementation description:
    The smithy code starts by entering a for loop that repeats 3 times. Each loop calls the drawCard function. The drawCard function pulls a card from the player's deck and adds it to their hand. The smithy card is then discarded from the hand using the discardCard function.

Adventurer card
  Card effect description:
    The player draws cards from the deck until the player receives 2 treasure cards. All other non-treasure cards are discarded.

  Card implementation description:
    The adventurer code starts by entering a while loop. Within the loop, the deck is checked to see if there are any cards left. If not, the shuffle function is called. (This seems unnecessary since the shuffle function just shuffles the deck and does not add the discarded pile to the deck. The drawCard function, called right after, also does this check and adds the discarded pile before calling the shuffle function.) A card is then drawn from the deck and added to the player's hand using the drawCard function. The new card is stored as cardDrawn. The cardDrawn variable is checked to see if it is a treasure card. If so, drawntreasure is incremented by 1. Otherwise cardDrawn is stored in the temphand array, the card is removed from the player's hand by decrementing the handCount and the temphand index is incremented by 1. The loop continues until 2 treasure cards have been drawn. Next the cards stored in temphand are iterated through. For each card in temphand, the card is added to the discard pile and the discardCount variable is incremented by 1.

discardCard()
  Method description:
    Removes designated card from player's hand and adds it to the played card pile if not trashed.

  Method implementation description:
    The discardCard function code first checks to see if the trashFlag has been set. If not, the discarded card is added to the playedCards array and the playedCardCount is incremented by 1. If the card is trashed this step is ignored and the card will not be added to the played card pile. Next the discarded card is set to a value of -1 in the player's hand. The function then checks for the position of the discarded card in the player's hand and shuffles the cards so the discarded card is the last card in the hand. The handCount is then decremented by 1 to remove the last card (discarded card) from the player's hand.

updateCoins()
  Method description:
    Updates the number of coins currently in the player's hand.

  Method implementation description:
    The function first resets the state->coins variable to 0. Next it enters a for loop that iterates over every card in the players hand. If the card is copper then state->coins is incremented by 1, if the card is silver then state->coins is incremented by 2, and if the card is gold then state->coins is incremented by 3. Next the bonus is added to state->coins to give the total amount of coins present in the player's hand.

*/
