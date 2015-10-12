/*
    adventurer:

        while(drawntreasure<2){ //continue to draw cards until 2 treasure cards are found.
            if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
                shuffle(currentPlayer, state);
            }
            drawCard(currentPlayer, state); //draw a card for each cycle through the while-loop
            cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
            if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold) //increment drawn treasure count if a treasure card is drawn.
              drawntreasure++;
            else{ //if a treasure card is not drawn, add it to temporary hand instead of regular hand (remove from hand and add to temphand.
              temphand[z]=cardDrawn;
              state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
              z++;
            }
        }
        while(z-1>=0){ //discard temporary hand if there are cards in temporary hand.
            state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
            z=z-1;
        }

        Continues to draw cards until two treasure cards are revealed. If a treasure card is revealed it is placed into the player's hand; if a
        non-treasure card is revealed it is placed into a temporary hand. After two treasure cards are revealed the temporary hand is discarded and
        the treasure cards remain in hand. According to the original implementation, this card does not discard upon use (?); this has been changed
        in my implementation of the adventurer class.

    smithy:
        //+3 Cards
        for (i = 0; i < 3; i++) //repeat loop 3 times
        {
            drawCard(currentPlayer, state); //draw a card for each cycle through the loop (Draw 3 cards)
        }

        //discard card from hand
        discardCard(handPos, currentPlayer, state, 0);

        The smithy card adds three cards to the user's hand, and then discards itself.

    discardCard():
        int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)
        {

          //if card is not trashed, added to Played pile
          if (trashFlag < 1){
            //add card to played pile
            state->playedCards[state->playedCardCount] = state->hand[currentPlayer][handPos];
            state->playedCardCount++;
          }

          //set played card to -1
          state->hand[currentPlayer][handPos] = -1;

          //remove card from player's hand
          if ( handPos == (state->handCount[currentPlayer] - 1) ) 	//last card in hand array is played
            {
              //reduce number of cards in hand
              state->handCount[currentPlayer]--;
            }
          else if ( state->handCount[currentPlayer] == 1 ) //only one card in hand
            {
              //reduce number of cards in hand
              state->handCount[currentPlayer]--;
            }
          else
            {
              //replace discarded card with last card in hand
              state->hand[currentPlayer][handPos] = state->hand[currentPlayer][ (state->handCount[currentPlayer] - 1)];
              //set last card to -1
              state->hand[currentPlayer][state->handCount[currentPlayer] - 1] = -1;
              //reduce number of cards in hand
              state->handCount[currentPlayer]--;
            }

          return 0;
        }

        If 'trashed' flag = 1, the card will be placed in the trash. Otherwise, the played card count will be incremented and the
        card will be registered as played. The card is then removed from hand and the number of cards in hand is decremented. The
        spot in hand that the card previously filled is then moved into the place of the played card. Returns 0.

    updateCoins():
        int updateCoins(int player, struct gameState *state, int bonus)
        {
            int i;

            //reset coin count
            state->coins = 0;

            //add coins for each Treasure card in player's hand
            for (i = 0; i < state->handCount[player]; i++){
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
            //add bonus
            state->coins += bonus;

            return 0;
        }

        Number of coins starts at 0. The function then iterates through each card in player's hand and adds
        1 for each copper, 2 for each silver, and 3 for each gold found in this way. If cards have been played
        which award bonus coins, that bonus is then added to the coin total. Returns 0.
*/
