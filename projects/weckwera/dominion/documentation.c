Smithy card:
-for loop used to draw three cards from player's deck using drawCard()
-drawn cards added to hand
-Smithy card discarded at end of function


Adventurer card:
-Counter keeps track of number treasure cards drawn
-drawCard() used to draw cards from the deck until drawnTreasure == 2
-drawnTreasure cards added to player's hand
-deck shuffled when deckCount == 0
-non-Treasure cards moved to discard
-Adventurer card discarded


discardCard() method:
-check if card is Trashed
-if not, add to played pile
-edit playedCard state to -1 (played)
-reduce number of cards in hand depending on how many cards currently in hand


updateCoins() method:
-reset coin count to 0
-add coins to counter based on Treasure cards in player hand (1 for each copper, 2 for each silver, 3 for each gold)
-add number based on "bonus" integer passed to function



