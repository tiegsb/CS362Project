/* Name: Kathryn McDonald
 * Class: CS 362
 * File name: coverage1.c
 * Purpose: Describes coverage in card tests 1-4 and unit tests 1-4 */

dominion.c:
  28.37% statement coverage
  29.26% branch coverage
  19.42% taken at least once
  20% calls executed
  
  Overall, the coverage for dominion.c is pretty low.  That is because we were only required to write unit tests four eight functions total.  To improve coverage for dominion.c, it would be necessary to write unit tests for all functions.
  

cardtest1.c: smithyEffect()
  100% statement coverage: Every line in smithyEffect() was executed.
  100% branch coverage: Every branch in smithyEffect() was executed.
  boundary coverage: the Smithy card causes the player to draw 3 cards.  The only boundary I can think of is if there are not enough cards left in the player's deck to draw.  However, this condition would be better tested as a unit test for drawCard().
  
cardtest2.c: adventurerEffect()
  statement coverage: Several lines in adventurerEffect() were not executed:
    The deck was never empty, so line 655 that shuffles was never tested.
    Since only Treasure cards were drawn, lines 662-664 that specify what happens when Treasure cards are NOT drawn were never tested.
    Since only Treasure cards were drawn, lines 668-669 that discard additional cards drawn were never tested.
  branch coverage: Several branches in adventurerEffect() were not executed:
    Branch on line 654 when deck is empty was never tested.
    Branch on line 661 when Treasure cards are not drawn was never tested.
    Branch on line 667 where non-Treasure cards are discarded was never tested.
  boundary coverage: the Adventurer card causes the player to continue drawing cards until he/she has drawn 2 Treasure cards.  One un-tested boundary is what happens when the player does not have 2 Treasure cards in his/her deck.  Another boundary is what happens if the player goes through the entire deck while trying to draw Treasure cards, but this may be better tested as a unit test for drawCard().
    
cardtest3.c: villageEffect()
  100% statement coverage: Every line in villageEffect() was executed.
  100% branch coverage: Every branch in villageEffect() was executed.
  boundary coverage: the Village card causes the player to draw 1 card and gain 2 actions.  The only boundary I can think of would be where the player went to draw a card, but his/her deck was empty.  However, this may be better tested as a unit test for drawCard().

cardtest4.c: greathallEffect()
  100% statement coverage: Every line in greathallEffect() was executed.
  100% branch coverage: Every branch in greathallEffect() was executed.
  boundary coverage: the Great Hall card causes the player to draw 1 card.  The only boundary I can think of would be where the player went to draw a card, but his/her deck was empty.  However, this may be better tested as a unit test for drawCard().

unittest1.c: updateCoins()
  100% statement coverage: Every line in updateCoins() was executed.
  100% branch coverage: Every branch in updateCoins() was executed.
  100% boundary coverage:  I believe that every possible boundary is covered.  updateCoins() is tested for every possible combination of coins, including no coins, and bonus is also taken into account.

unittest2.c: shuffle()
  statement coverage: One line in shuffle() was not executed:
    The deck was never empty, so line 210, which specifies to return -1 if the deck is empty, was never tested.
  branch coverage: One branch in shuffle() was not executed:
    Branch on line 209 when deck is empty was never tested.
  boundary coverage: One boundary was never tested:
    Case where deck is empty was never tested.
    
unittest3.c: buyCard()
  100% statement coverage: Every line in buyCard() was executed.
  100% branch coverage: Every branch in buyCard() was executed.
  100% boundary coverage: I believe that every possible boundary is covered.  buyCard() is tested for not having enough Buys, not having enough cards, and not having enough coins.

unittest4.c: gainCard()
  100% statement coverage: Every line in gainCard() was executed.
  100% branch coverage: Every branch in gainCard() was executed.
  100% boundary coverage: I believe that every possible boundary is covered.  gainCard() is tested for not enough cards or if the card is not used in the game.  It is also tested for whether the card is added to discard, deck, or hand.
