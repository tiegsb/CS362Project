/*
Title: Random History.c 
Author: Dustin Chase
Date: 11/8/2015
Course: CS 362 Software Engineering II
Description: The development of random testers, including improvements in coverage and and effort to check the correctness of your specification. 
*/

*************
Smithy Card:

Development of Random Testing
To develop the random testing for this card, I first examined the expected game state which should exist after the card has been played. I could see that there was 
supposed to be 2 additional cards in the player's hand and that the smithy card should no longer be in the player's hand. I decided that a good way to randomize the testing
would be to randomly select a player, randomly generate a hand, then randomly select a position for the smithy card. I could then save the game state before the card was played
 and check that against what should be different after the card was played. 
 
 By randomizing the player selected and card position of the smithy card, it should be sufficient to get good code coverage. 
 
Coverage: 
I was able to acheive all code coverage with this randomized testing:
 3000:  229:void playSmithy(struct gameState *state, int handPos) {
	-:  230:	
	-:  231:	int i; //loop counter
 3000:  232:	int currentPlayer = whoseTurn(state);
 9000:  233:	for (i = 0; i < 2; i++)
	-:  234:	{
 6000:  235:	  drawCard(currentPlayer, state);
	-:  236:	}
	-:  237:			
	-:  238:    //discard card from hand
 3000:  239:    discardCard(handPos, currentPlayer, state, 0);
	-:  240:	
 3000:  241:}
 
 Correctness: 
 The testing was able to uncover a bug which caused the player's hand count to be incorrect. With sufficient randomization of the testing we can have 
 confidence that the function otherwise works correctly. 
 **************
 
 Adventurer Card:
 
 Development of Random Testing
 To develop random testing for this card, I first examined the expected game state which should exist after the card has been played. I could see that there should
 no longer be an adventurer card in the player's hand and that additional treasure should be picked up. I tested this by randomly creating a player hand and randomly 
 generating a deck which would be guaranteed to contain a sufficient number of treasure cards so that the testing function would not run into an infinite loop. When I first
 ran the randomized test, I found that there were errors in the treasure cards being picked up. I printed out the frequencies that the treasure cards were 
 being picked up and found that one of the card types was not being counted in the loop. I also found that the adventurer card remained in the player's hand. 

 Coverage: 
 I was able to acheive full coverage with this randomized testing. The only place where the test could be improved would be to start with an empty deck for the player.  
 10:  202:void playAdventurer(struct gameState *state) {
   10:  203:	int drawntreasure = 0;
   10:  204:	int cardDrawn = 0; 
   10:  205:	int z = 0; //counter for temp hand
	-:  206:	int temphand[MAX_HAND];
   10:  207:	int currentPlayer = whoseTurn(state);
  288:  208:	  while(drawntreasure < 2){
  268:  209:	if (state->deckCount[currentPlayer] < 1){//if the deck is empty we need to shuffle discard and add to deck
#####:  210:	  shuffle(currentPlayer, state);
	-:  211:	}
  268:  212:	drawCard(currentPlayer, state);
  268:  213:	cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
  288:  214:	if (cardDrawn == copper || cardDrawn == silver)
   20:  215:	  drawntreasure++;
	-:  216:	else{
  248:  217:	  temphand[z]=cardDrawn;
  248:  218:	  state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
  248:  219:	  z++;
	-:  220:	}
	-:  221:      }
  268:  222:      while(z-1>=0){
  248:  223:	state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
  248:  224:	z=z-1;
	-:  225:      }
	-:  226:	
   10:  227:}
   
Correctness: 
The testing is fully randomized and acheives nearly complete statement coverage. With this set of randomized tests, 
we can be confident that the errors in the function have been found. The next thing to improve would be to start with an empty deck. 