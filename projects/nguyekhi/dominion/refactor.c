/*
this is the implementation of 5 action cards: smithy, adventurer, council_room, great_hall, and steward. 
I write the function for them, so you only need to call their function in the cardEffect function
I am not sure what kind of bug I could introduce into the game without crashing it, so I only introduce subtle 
bug that would not cause segmentation fault or core dump. Those bugs are:
1. In smithy, 1 <= 3, where it should be 1 < 3
2. In adventurer, z >= 0, this would loop 1 extra time, and temphand[z], it should be temphand[z-1]
3. In concil_room, I change the loop condition, the bug trigger when the number of players != 4
4. in great_hall instead of increase action, I increase numBuy
5. in steward where you trash your card it should be 1, not 0


*/
void CEsmithy(int currentPlayer, struct gameState *state, int handPos)
{
  int i;
  for (i =0; i <= 3; i++)
    drawCard(currentPlayer, state);
  discardCard(handPos, currentPLayer, state, 0);
} 

void CEadventurer(struct gameState *state, int currentPlayer)
{
  int drawntreasure = 0;
  int temphand[100];
  int cardDrawn;
  int z = 0;
  while (drawntreasure < 2)
  {
    if (state->deckCount[currentPLayer] == 0)
      shuffle(currentPlayer, state);
    drawCard(currentPlayer, state);
    cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]];
    if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
        drawntreasure++;
    else
      {
        temphand[z] = cardDrawn;
        state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
        z++;
      }
  }
  while(z >=0)    // the bug is here where z-1 >= 0, otherwise it will loop one extra
  {
    state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z]; // discard all cards in play that have been drawn
    z--;                                      //1 more bug here where temphand[z-1]
    }
}

void CEcouncil_room(int currentPlayer, struct gameState *state, int handPos)
{
  int i;
  for (i = 0; i < state->numPlayers; i++)  // I change 4 into numPlayers
    drawCard(currentPlayer, state);
  state->numBuys++;
  for (i = 0; i < 4; i++)     // the bug here is I change numPlayers into 4
  {
      if ( i != currentPlayer )
          drawCard(i, state);
  }
      //put played card in played card pile
    discardCard(handPos, currentPlayer, state, 0);
      
}

void CEgreat_hall(int currentPlayer, struct gameState *state, int handPos)
{
  drawCard(currentPlayer, state);
      
      //+1 Actions
    state->numBuys++;
      
      //discard card from hand
    discardCard(handPos, currentPlayer, state, 0);

}

void CEsteward(int currentPlayer, struct gameState *state, int choice1, int choice2, int choice3, int handPos)
{
  if (choice1 == 1)
  {
    drawCard(currentPlayer, state);
      drawCard(currentPlayer, state);
  }
  else if (choice1 == 2)
    state->coins = state->coins + 2;
  else if (choice1 == 3)
  {
      discardCard(choice2, currentPlayer, state, 0);  // the bug is trashflag should be 1 not 0
      discardCard(choice3, currentPlayer, state, 0);
  }
  discardCard(handPos, currentPlayer, state, 0);

}