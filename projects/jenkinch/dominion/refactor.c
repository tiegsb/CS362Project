/*
------------------------------
refactor.c
Assignment 2
jenkinch
------------------------------

Changes to card effect implementations in cardEffect():

Smithy:
    The Smithy card effect code was extracted from the switch statement and 
    placed in its own function activateSmithy(). The function accepts the 
    parameters currentPlayer, state, and handPos. The function returns zero and 
    so the switch statement simply returns the call to the function.
    
    Bugs: The currentPlayer and handPos arguments have been switched in the call
          to discardCard().
          
          An additional i++ was added within the for-loop.
    
Adventurer:
    The Adventurer card effect code was extracted from the switch statement and 
    placed in its own function activateAdventurer(). The function accepts the 
    parameters currentPlayer, state and tempHand. The variables z, drawnTreasure, 
    and cardDrawn were made local variables in the function. The function returns 
    zero and so the switch statement simply returns the call to the function.
    
    Bugs: In the first call to drawCard(), the first parameter of currentPlayer
          was replaced with cardDrawn. [UPDATE: This bug was fixed for the sake of
          Assignment 4. It would too often throw a segmentation fault and thus made
          generating the .out file inconsistent.]
          
          In the second if-else block, the "z++" was moved from the bottom of the else to the bottom of the if.
          
          In the first if-statement "<1" was changed to "<2". 
    
Village:
    The Village card effect code was extracted from the switch statement and placed 
    in its own function activateVillage(). The function accepts the parameters
    currentPlayer, state, and handPos. The function returns zero and so the switch
    statement simply returns the call to the function.
    
    Bugs: In the "+2 Actions" code, on the right side of the equal sign 
          "state->numActions" has been changed to "state->supplyCount".
    
Steward:
    The Steward card effect code was extracted from the switch statement and placed 
    in its own function activateSteward(). The function accepts the parameters
    currentPlayer, state, handPos, choice1, choice2, and choice3. The function 
    returns zero and so the switch statement simply returns the call to the 
    function.
    
    Bugs: The currentPlayer and choice arguments have been switched in the two 
          calls to discardCard() in the else statement.
    
Minion:
    The Minion card effect code was extracted from the switch statement and placed 
    in its own function activateSteward(). The function accepts the parameters
    currentPlayer, state, handPos, choice1, and choice2. The variables i and j were
    made local to the function. The function returns zero and so the switch 
    statement simply returns the call to the function.
    
    Bugs: The "draw 4 j for-loop" now uses j <= 4 instead of the j < 4.
*/