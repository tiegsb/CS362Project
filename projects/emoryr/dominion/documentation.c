//
//  documentation.c
//  
//
//  Created by Rebecca Emory on 10/11/15.
//
//


/*
Smithy: Cost- 4 coins
for (int i = 0; i < 4; i++) {
    drawCard;
    if (card == treasure)
        updateCoins(hand, card)
        }
discardCard()

Adventurer: Cost- 6 coins

Reveal cards from your deck until you reveal 2 Treasure cards. Put those Treasure cards into your hand and discard the other revealed cards. costs 6 coins.

int treasure = 0;
while (treasure < 2) {
    draw card from deck;
    if (card == treasure) {
        treasure++;
        updateCoins(hand, card);
    }
}
updateCoins()
lose 1 action
discardCard()

discardCard(hand, card) {
    hand = hand - card
}
takes discarded card out of hand

updateCoins(hand, card) {
    if (card == copper)
        coins += 1
        elseif (card == silver)
        coins += 2
        elseif (card == gold)
        coins += 3
        }
updates the number of coins in player’s current hand. This is the amount of money they can spend in that turn.
*/
