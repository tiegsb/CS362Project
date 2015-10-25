Changes to Dominion card code
----------------------------------------------------------

10/9/2015:

In dominion.c:

- Moved code for Smithy, Adventurer, Treasure Map, Feast, and Mine cards
  out of switch statement in cardEffect() and into their own functions.
  These functions are called from cardEffect()'s switch statement. 

- drawntreasure, cardDrawn, z, x, and temphand[] have been moved from
  cardEffect() to the functions for the cards mentioned in the previous
  bullet. They are not used elsewhere in cardEffect().


In dominion.h:

- Added function declarations for smithyCard(), adventurerCard(), treasureMapCard(),
  feastCard(), and mineCard().


10/10/2015:

In dominion.c:

- In smithyCard(), changed the trashFlag in the call to discardCard() from
  0 to 1 (sets the card as trashed). (BUG)

- In adventureCard(), changed the cardDrawn assignment to not place drawn
  card at the end of the hand. (BUG)

- In treasureMapCard(), changed the code that trashes both treasure cards
  to no longer trash them (trashFlag changed from 1 to -1). (BUG)

- In feastCard(), after gainCard(), removed the line that would set x = 0
  to signal the end of card buying. (BUG)


10/25/2015:

In dominion.c:

- In feastCard(), removed the infinite loop that resulted from the code 
  change from 10/10/2015. Noting the bug would require MANUAL testing, not 
  automated testing. Instead, I set the gainCard() call just above x=0 to
  put the gained card in the player's hand instead of the discard pile.
  (So there's still a BUG)

