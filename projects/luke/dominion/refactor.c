/*Kenny Lu
October 7th, 2015
CS 362
Assignment 2 
Refactor.c

In dominion.c, I moved code from the cardEffect switch statement into individual functions for
certain cards.  These cards are the adventurer card, smithy card, village card, steward card and 
the baron card.  The function definitions for each of these cards are at the very bottom of the
dominion.c code and are named: adventurerCard, smithyCard, villageCard, stewardCard and baronCard.

Intentional Bug Changes Made:
According to the instructions for this assignment, I introduced minor bugs into each of these card
functions.

adventurerCard: For this card, I altered the first while loop and made it so that drawntreasure is
compared as less than OR EQUAL to 2.  This allows the loop to run an extra time, drawing 3 cards 
instead of 2.

original code: while(drawntreasure<2)
altered code: while(drawntreasure<=2)

smithyCard:  For this card, I altered the for loop so that the i started at 1 instead of 0.  This
makes it so that the smithyCard only draws 2 cards instead of 3.

original code: for (i = 0; i < 3; i++)
altered code: for (i = 1; i < 3; i++)

villageCard: For this card, I altered the code so that 2 cards are drawn instead of one.  This is
invoked by calling drawCard() twice but hidden farther down in the function.

original code: drawCard(currentPlayer, state);
altered code: drawCard(currentPlayer, state);

stewardCard:  For this card, the code was altered so that the same two cards are discarded.

original code: discardCard(choice2, currentPlayer, state, 1);
    discardCard(choice3, currentPlayer, state, 1);

altered code: discardCard(choice2, currentPlayer, state, 1);
    discardCard(choice2, currentPlayer, state, 1);

baronCard: For this card, I altered the code so that handCount for the current player increases instead of
decreases after the card is played.

original code: state->handCount[currentPlayer]--;
altered code:  state->handCount[currentPlayer]++;