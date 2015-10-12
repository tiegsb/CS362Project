The cards I chose to implement are: 
	Adventurer
	Smithy
	Great Hall
	Village
	Council Room
		
Adventurer:
	Changed so that a player gets 3 treasures instead of 2.
	654: while(drawntreasure<3){
		
	Changed the || to && so that no treasure is counted towards the drawntreasure
	660: if (cardDrawn == copper && cardDrawn == silver && cardDrawn == gold)
		
	Increased drawntreasure when a treasure card was not drawn
	666: drawntreasure++;
		
Smithy: 
	Changed so only 1 card is drawn for treasure
	676: for (i = 1; i < 2; i++)
				
Great Hall:
	Added 2 draw cards instead of 1
    //+1 Card
    687: drawCard(currentPlayer, state);
	
    //+1 Card
    690: drawCard(currentPlayer, state);	
	
Village:
	No changes were made to this.
	
Council Room:
	Changed it so they draw 6 cards, instead of 4
	713: for (i = 0; i < 6; i++)
	
	Changed it so it checks if i is the currentPlayer, instead of checking to see if it is not
	724: if ( i == currentPlayer )
