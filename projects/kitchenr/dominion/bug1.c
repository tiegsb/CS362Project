/*

Bugs found in unit testing:

Unit test 1: initializeGame
  
  All players hands should be drawn at the beginning of the game, only player 1's hand is drawn
    -> is commented out in code and copied to first turn init

  Does not check if selected kingdom cards are actually kingdom cards, accepted copper as a kingdom card


  
Unit test 2: buyCard
  No bugs found. Tested the following:
    Buying card when there is money, buys, and cards to buy
    Buying card when there isn't money, fails
    Buying card when there is not enough cards, fails
    Buying card when There are no buys left, fails
    
    State after success:
      Player's discard pile is increased, card added.
      Other player's discard untouched
      
      
Unit test 3: fullDeckCount
  Bug found:
     fullDeckCount should check the played cards pile if it is the chosen player's turn, in order to have actually searched the player's entire deck. Any played cards
     are currently ignored in the search.
  Tested array boundaries, empty piles, and multiple players

  
  
Unit test 4: endTurn
  Bugs found:
      Draws a new hand at the beginning of the turn, and discards all cards at the end.
      No cards should be drawn at the beginning, the hand should be replaced at the end of the turn
      
      Played cards are destroyed, not put on the appropriate player's discard pile
      
      Changes turn even on end of game situations, should stay the same
  

Card test 1: Smithy
  Bugs found:
      Smithy draws 4 cards instead of 3
  
  Features working:
      Smithy will only draw if there are cards left.
  
Card test 2: Adventurer
  Bugs found:
      Adventurer drew a non-treasure curse, as well as a gold, from a fixed deck
      On the first play of Adventurer, the cards were not discarded properly (the discard count was not updated) may be a problem with discardCard

Card test 3: Council
  Bugs found:
      Council room drew 5 cards for player and 1 for others.
      This means that the feature drawing 1 card drew for the player too
      
Card test 4: Village

  
  */