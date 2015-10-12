-----------------------Dominion Documentation-----------------------

#######################
Smithy Card
#######################
Cost to purchase: 4
Description: This action card allows the player to draw 3 cards into their hand.
Code Understanding:   The cost of the smithy card is defined in the getCost()
                    method in dominion.c. Currently, the cost of the card is 4.
                      The actual code that defines what the smithy action card
                    does is in the cardEffect() method in dominion.c. cardEffect()
                    is a method that is called when a provided card is executed.
                    Within cardEffect(), there is a switch statement that checks
                    what action needs to be performed for the action card that is
                    passed in. For the smithy card, there is a loop that iterates
                    3 times, each time it draws a card for the current player.
                    After the loop finishes, the smithy card is discarded using
                    the discardCard() method in dominion.c. The last thing in the
                    case statement is a return call with the value of 0, which is
                    success.

#######################
Adventurer Card
#######################
Cost to purchase: 6
Description: This action card allows the player to reveal cards from their deck
             until they have revealed 2 treasure cards. The player keeps the 2
             treasure cards and discards the rest of the revealed cards.
Code Understanding:  The cost of the Adventurer card is defined in the getCost()
                    method in dominion.c. Currently, the cost of the card is 6.
                      The actual code that defines what the Adventurer action card
                    does is in the cardEffect() method in dominion.c. Looking at the
                    case statement that contains the Adventurer action card logic, the
                    first thing it does is execute a while statement with the condition
                    of the drawn treasure cards being less than 2. Within this while
                    statement, several things happen:
                    1. If the current player has an empty deck, then the discard pile is
                       shuffled into the deck.
                    2. If there are enough cards in the deck, then a card is drawn from
                       the deck using drawCard().
                    3. The card drawn is determined to be the top card in the players hand.
                    4. The card drawn is looked at to determine if it is a treaure or not.
                       If it is a treasure, then the treasure counter is increamented.
                       Otherwise, we remove that drawn card form the player's hand by
                       decrementing their hand count. We also all the card down to the
                       temporary hand array.
                    Once the first while loop is finished (meaning we now have found 2
                    treasures), we discard all the cards in the temporary hand array
                    containing all the cards we have drawn that weren't treasures. We
                    do this with a while loop that loops through the temp hand and adds
                    card to the current player's discard pile.

#######################
Understanding of discardCard() Method
#######################
  The purpose of the discardCard() is in dominion.c is to remove a card from a players hand
and put the card into the discard pile. The first thing that is checked in the method is
if the we are not trashing the specified card, then we will add the card to the played
card pile (in other words the discard pile). After that is done, we start removing the card
from the players hand by setting that card to -1 in the players hand. We decrement the player's
hand count when the discarded card is in the last position of the hand or if the card is the only
card in the hand. Otherwise, we replace the discarded card in the hand with the last card in the hand.
A 0 is returned if the card was successfully discarded. There are no other return alternatives.

#######################
Understanding of updateCoins() Method
#######################
  The purpose of the updateCoins() method is to update the current coin count with the number
of coins that are in the current player's hand. The first thing this method does is reset the
coin count to 0. It then iterates though to players hand to find any coppers, silvers, and
gold. If any coin types are found, then it adds the coin values to the current coin value for
the player. If updateCoins() is called with a bonus int, then the bonus amount will be added
to the player's current coin count. A 0 is returned if the coins were updated with success.

