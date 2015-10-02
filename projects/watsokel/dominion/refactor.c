CS 362 - ASSIGNMENT 2               KELVIN WATSON 
refactor.c                          ONID: watsokel      
                                    OSU ID: 932540242 
                                    github.com/watsokel 
-----------------------------------------------------------------------
Refactoring Code in switch (card) statement within cardEffect() method 


smithy switch case          Refactored to smithyEffect() method 
----------------------------------------------------------------------- 
The code originally in the switch (card) statement for the smithy switch 
case has been refactored into a function called smithyEffect(), which 
has the following parameters: current player number, game state, and 
hand position of the smithy card. The original functionality is 
preserved, i.e. three cards are added to the player's hand. A value of 0 
is returned on successful execution of the function. 

*** BUGS introduced to smithyEffect() method *** 
Instead of calling discardCard() with trashFlag value of 0 (which 
correctly places the smithy card into the discard pile), a bug has been 
introduced that calls discardCard() passing in the trashFlag with a 
value of 1 (which erroneously places the smithy card in the deck). 
Specifically, the line: 
  discardCard(handPos, currentPlayer, state, 0); //original
has been changed to: 
  discardCard(handPos, currentPlayer, state, 1); //bug introduced

  

adventurer switch case      Refactored to adventurerEffect() method 
--------------------------------------------------------------------- 
The code contained in the adventurer switch case in cardEffect() has 
been refactored to produce a function called adventurerEffect() has been 
defined. This function takes as arguments the game state, and the 
current player number. adventurerEffect() incorporates code from the 
adventurer switch case in the original dominion.c code. Because the 
variables drawntreasure, cardDrawn and z are specifically used for the 
adventurer switch case, the code was refactored so that these variables 
are initialized in adventurerEffect, rather than within cardEffect(). A 
value of 0 is returned on successful execution of the function. 

*** BUG introduced to adventurerEffect() method *** 
When evaluating the card
that was drawn, a drawn copper card no longer increments drawntreasure.
Namely, the line: 
  if (cardDrawn==copper || cardDrawn==silver || cardDrawn==gold) //original
has been changed to: 
  if (cardDrawn == silver || cardDrawn == gold) //bug introduced

  
  
council room switch case    Refactored to councilRoomEffect() method 
---------------------------------------------------------- 
The code originally contained in the council room switch case in the 
switch(card) statement has been refactored to produce a function called 
councilRoomEffect(). This function takes as arguments the current player 
and the game state. A value of 0 is returned on successful execution of 
the function. 

*** BUG introduced to councilRoomEffect() method *** 
The if statement has been removed from the for loop, resulting in all 
players, including the current player (erroneously), drawing a card. 
Specifically, the code was changed from this: 
  for (i = 0; i < state->numPlayers; i++){ 
    if ( i != currentPlayer ) drawCard(i, state); //original
  }
to this:
  for (i = 0; i < state->numPlayers; i++){
    drawCard(i, state); //bug introduced
  }


  
mine switch case             Refactored to mineEffect() method 
---------------------------------------------------------------- 
The code originally contained in the mine switch case in the 
switch(card) statement has been refactored into a new method, called 
mineEffect(). This method takes as arguments the game's state, current 
player number, the position of the card to be trashed (choice1), and the 
player's desired card to gain (choice2), and the position of the mine 
card. mineEffect() returns -1 under the following conditions: if the 
card to be trashed is not a Treasure card, if the card to be gained is 
not a valid card (not equal in integer value to one of the enumerators 
in the CARD enumerated type, or if the cost of the), otherwise, it 
returns 0, indicating that the desired card (choice2) has been added to 
the player's hand. Because the variable j is a shared variable among the 
different switch cases in cardEffect()'s switch statement, it cannot be 
removed from cardEffect(). Instead, a new variable j is declared and 
initialized in mineEffect(). In cardEffect(), the original mine switch 
case code is replaced with the line return (mineEffect(state, 
currentPlayer, choice1, choice2, handPos) == -1)? -1 : 0; in which the 
result of the call to mineEffect() is evaluated, and either -1 
(mineEffect returned -1 for the reasons stated above) or 0 is returned 
(sucess). 

***BUG introduced to mineEffect() method ***
The following if block has been removed:
  if (choice2 > treasure_map || choice2 < curse){
    return -1;
  }
Thus, the code no longer checks if choice2 is a valid card. This bug can 
only be triggered if the user intentionally enters an invalid card type 
for choice2. 



salvager switch case        Refactored in salvagerEffect()
----------------------------------------------------------
The code originally contained in the salvager switch case in the 
switch(card) statement has been refactored into a new method called 
salvagerEffect(). The salvagerEffect() method has the following 
parameters: the current player, the game's state, the position of the 
player's chosen card to trash (choice1), and the salvager card's 
position in the player's hand. The number of buys is first incremented. 
Then, the player gains the number of coins equal to the cost of the 
chosen card to be trashed (choice1). choice1 is then trashed and the 
salvager card is discarded. A value of 0 is returned on successful 
execution of the function. 

***BUG introduced to salvagerEffect() method ***
The discardCard() call passes the salvager card to the deck instead of the discard pile.
Namely, this line: 
  discardCard(handPos, currentPlayer, state, 0); //original
has been changed to this line:
  discardCard(handPos, currentPlayer, state, 1); //bug introduced