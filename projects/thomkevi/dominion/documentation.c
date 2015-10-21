Documentation

smithy card:

  case smithy:
    //+3 Cards
    for (i = 0; i < 3; i++)
    {
      drawCard(currentPlayer, state);
    }

    //discard card from hand
    discardCard(handPos, currentPlayer, state, 0);
    return 0;
    
    if player plays smithy card, draw 3 cards from the players deck then discard the smithy.

adventurer card:

  case adventurer:
    while(drawntreasure<2){
      if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
        shuffle(currentPlayer, state);
      }
      drawCard(currentPlayer, state);
      cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
      if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
        drawntreasure++;
      else{
        temphand[z]=cardDrawn;
        state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
        z++;
      }
    }
    while(z-1>=0){
      state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
      z=z-1;
    }
    return 0;

    if player plays adventurer card, while the player has drawn less than 2 treasure cards, 
    shuffle deck if the deck is empty, draw a card, if the card is a copper, silver or gold card, 
    increment drawntreasure by 1 otherwise put the drawn card in a temporary hand.  Once player has
    drawn 2 treasure cards, discard cards in temporary hand.
    
discardCard method:

  int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)
  {
    
    //if card is not trashed, added to Played pile 
    if (trashFlag < 1)
      {
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
  
  If the card has not been trashed, add it to the players played card pile.  
  Reduce the players handcount by 1.  If its not the last card in hand or to be played, 
  place the last card in hand in the discarded cards position in the hand.

updateCoins method:

  int updateCoins(int player, struct gameState *state, int bonus)
  {
    int i;
    
    //reset coin count
    state->coins = 0;

    //add coins for each Treasure card in player's hand
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

    //add bonus
    state->coins += bonus;

    return 0;
  }

  Set the coin count to zero.  for each card in players hand, if copper coin then add 1 to
  players coin count, if silver coin then add 2 to players coin count, if gold add 3 to 
  players coin count.  Add any bonus to players coin count.

