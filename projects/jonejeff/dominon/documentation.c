Documentation of smithy & adventurer card

The smithy card allows the player to draw three cards to add to their hand. The case in the card effect function is very simple. It is a for loop that calls the drawCard() function three times. Then discards it's self when it is done.

The adventurer card allows the player to reveal cards from their deck until they reveal two treasure cards and aadd them to there hand. This is done with a while loop with a drawntreasures counter. First it checks it he deck is emtny and need to be reshuffled with shuffle function. Next it draws a card if it is a treasure card drawnTreasures goes up. Else it is added to a temp hand after amount of treasure cards is draw the temp hand is discard one by one.

Documentation of discardCard() & updateCoins()

The discardCard function allows a player discard a card when needed. It first checks the trash flag to know if the card should be trashed.  The second if else block is for lowering the hand count it has three cases.The first check is if it was the end card in there hand. The second check is if it was there last card. The third check handles a middle or first card discard.

The updateCoins function counts the amount of coins from treasure cards and add the bonufrom action card.Frist it sets coins to 0. Then the for loop goes though the hand and sums up the coins. It then adds the bonus on top
