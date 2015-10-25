bugs1.c 
Dalena Pham

All unit tests for non-card functions went smoothly and without error, however all the card unit tests showed error in many things. 

Card: smithy_card
- Tests showed that after smithy was executed it was not found in the correct position in the played pile and later showed that nothing was ever placed in the played piled. 

Card: aventurer_card
- The adventurer card did not draw the correct number of cards
- Did not discard the correct number of cards
- Did not discard the correct cards
- Was not placed in the played pile

Card: council_room_card
- Was not returned succesfully
- Resulting deckCount is not what was expected
- Every other player did not draw 1 card
- The resulting deckcount in other player decks was not what was expected

Card: cardEffect for sea_hag
- sea_hag card was not placed in played pile
- the above bug probably resulting in an incorrect number of cards in hand
- Decks for player 2 and 3 contained an incorrect number of cards
- The Curse card was not at the top of the deck for players 2 and 3
- The cards that were previously at the top of the deck before the call were not found to be in the discard pile as they should have been. 