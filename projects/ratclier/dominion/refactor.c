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
