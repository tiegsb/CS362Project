Solomon Huynh
CS362 Assignment 2
documentation.c

Smithy Card - it is used to draw a card three times by using a for loop to draw three times. Once the card is used,
it then goes to the discard pile.

Adventurer Card - it goes through a loop to draw until there are two treasure cards and puts it to the hand. This is
done drawing a card into a temp hand and drawing until the counter treasure cards are two. It then discards all
non-treasure cards drawn as well as the adventurer card itself.

discardCard() function first checks if the trash flag is set and if it is not, it sets the marks the card as played.
Then it discards the card and readjusts the position of the cards to have the remaining cards maintain array with no
missing cards inbetween.

updateCoins() function first resets the coin count and adds all the coins on hand together based on if it's copper,
silver, or gold. Then it adds any bonuses to it.

