Execute your unit tests and describe any bugs:

Using the known specification for constructing the unit tests for the cards,
the unit tests found bugs in two of the cards tested.  These bugs were corrected to 
allow execution of the unittests to complete without halting on an ASSERT.

Bug 1: cardtest2.c identified a bug in the playCouncilRoom() function.
        cardtest2 validates that each player has the correct number of cards in hand
        after the councilroom card has been played.
        
        For the current player, this should be (+4 cards - Discard Council Room) = Net +3
        
        For all other players, this should be +1 card.
        
        The unittest identified that the playCouncilRoom() had a bug in that it added an
        extra card for the current player when adding a card for the other players. Thus
        giving the current player an extra card in their hand.
        
        This bug (originally added in assignment2) has now been corrected.
        
Bug 2: cardtest3.c identified a bug in the playSmithy() function.
       cardtest3 validates that the current player has the correct number of cards after
       playing the smithy card.  The smithy card adds 3 cards to the players hand.
       
       The unittest identifed that the playSmith() function had a bug in the for loop
       comparison.  The less than operator was transposed causing no extra cards to be dealt
       to the players hand.
       
       Buggy Code:
            //+3 Cards
            for (i = 0; i > 3; i++)
            {
              drawCard(currentPlayer, state);
            }
            
      Corrected:
            for (i = 0; i < 3; i++)
            
      This bug (originally added in assignment2) has now been corrected.