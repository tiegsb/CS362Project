Adventurer Card: The first while loop tracks the number of treasure cards found in the current player's 
deck until two are drawn. First the program checks if the players deck count or number of cards in their
current deck is 0. If so shuffle is called which takes the discarded cards and adds them to the player's 
deck array. Then a card is drawn and added to the player's hand array and assigned to the cardDrawn
variable. If a treasure card is found in the deck the drawnTreasure variable is incremented. If the card
is not a treasure card it is added to a temphand array and the count of cards in the players immediate hand
is decremented. The variable z is then incremented to allow another card to be added to the temp hand array.
After that while loop is finished executing another while loop executes that iterates through all of the values
in the temphand array and adds them to the current players discarded card array.

Smithy Card: There is a for loop that has 3 iterations that call the drawCard function that adds 3 cards
to the current players hand. discardCard is then called to remove the smithy from the current hand

discardCard(): Checks the trash flag. If the flag is not set the played card is added to the played card array
and played card counter is incremented. Then the played card value is set to -1. Then if the played
card is the last array value it is removed by decrementing the hand count. If there is only one card
in the hand the count is decremented. Otherwise the the hand array position of the discarded card is replaced
with card value occupying the last value in the hand array. The last value in the hand array is set to -1
and the hand count is decremented.

updateCoins(): First the players coin count value is set to 0. Then a for loop iterates through each
card in the players hand and increments the coin count depending on the value of the card. After the for
loop executes bonus values are added to the coin count.