/*
Documentation:
Smithy card.

This loop draws three cards for the current player.
for (i = 0; i < 3; i++)
{
drawCard(currentPlayer, state);
}
In each iteration of the loop, the function calls the
drawCard function and passes it the current player and
his / her state. The result is that another card is
added to the hand each time.

discardCard(handPos, currentPlayer, state, 0);
This function discardCard is called in order to discard
the Smithy card that has been played in this round.
Again, the current player's state is updated.

return 0;
The function returns 0 to indicate that there were no
run-time errors.


----------------------------------------
Adventurer card.

This while loop repeats until two treasure cards are drawn and added to the current player's deck.
while(drawntreasure<2){
    if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
      shuffle(currentPlayer, state);
    }
    If the deck is empty, the discarded cards are shuffled and added to the deck.

    drawCard(currentPlayer, state);
    A card is drawn and added to the current player's hand.

    cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];
    if (cardDrawn = copper || cardDrawn == silver || cardDrawn == gold)
      drawntreasure++;
    If the card drawn is a treasure card, the value of the drawntreasure variable is incremented
    so the while loop can exit when two treasure cards are drawn.

    else{
      temphand[z]=cardDrawn;
      state->handCount[currentPlayer]--;
      z++;
    }
    Otherwise, if the card drawn is not a treasure card, it is removed from the player's hand.
  }

  while(z-1>=0){
    state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1];
    z=z-1;
  }
  All the non-treasure cards drawn are discarded.

  return 0;
  The function returns 0 to indicate that there were no
  run-time errors.


----------------------------------------
discardCard() method.

  if (trashFlag < 1)
    {
      state->playedCards[state->playedCardCount] = state->hand[currentPlayer][handPos];
      state->playedCardCount++;
    }
  If the card is not already flagged as trashed, the above code adds it to the played pile.
  Then it is placed as the last card in the player's hand and removed below.
  state->hand[currentPlayer][handPos] = -1;
  if ( handPos == (state->handCount[currentPlayer] - 1) )
    {
      state->handCount[currentPlayer]--;
    }
  else if ( state->handCount[currentPlayer] == 1 )
    {
      state->handCount[currentPlayer]--;
    }
  else
    {
      state->hand[currentPlayer][handPos] = state->hand[currentPlayer][ (state->handCount[currentPlayer] - 1)];

      state->hand[currentPlayer][state->handCount[currentPlayer] - 1] = -1;

      state->handCount[currentPlayer]--;
    }

  return 0;
  The function returns 0 to indicate that there were no run-time errors.

----------------------------------------
updateCoins() method.

  state->coins = 0;
  The coin count is reset to zero each round.

  This loop iterate's through the player's hand and
  adds all coins in the hand to the player's coin count.
  for (i = 0; i < state->handCount[player]; i++)
    {
      if (state->hand[player][i] == copper)
	{
	  state->coins += 1;
	}
      else if (state->hand[player][i] == silver)
	{
	  state->coins += 2;
	}
      else if (state->hand[player][i] == gold)
	{
	  state->coins += 3;
	}
    }

  state->coins += bonus;
  Any bonus coins from action cards are added to the player's coin count.

  return 0;
  The function returns 0 to indicate that there were no
  run-time errors.

*/
