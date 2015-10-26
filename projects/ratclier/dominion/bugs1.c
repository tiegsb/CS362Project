10/25/2015:

Bugs found during unit testing (Assignment 3):

- gainCard(): exits as if there are insufficient cards in the supply deck 
  even if sufficient cards are present.

- smithyCard(): player 0, discarded card did not end up on the played pile 
  (not incremented).

- smithyCard(): player 1, three cards not removed from deck, three cards not
  added to hand, discarded card did not end up on the played pile 
  (not incremented).

- adventurerCard(): two new cards not added to hand, incrrect number of
  cards discarded.

- treasureMapCard(): four golds were added in spite of only discarding one 
  or fewer treasure map card(s). 

- feastCard(): gained card not added to discard pile, discard count not 
  incremented.
