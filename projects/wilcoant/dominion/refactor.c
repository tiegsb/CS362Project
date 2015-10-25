/*************************************************
smithy:
    cut case(smithy) out of swith in cardEffect.
    changed to function call on line 645 play_smithy if card == smithy 
    added function prototype to dominion.h line 130
    compiled and ran before introducing bug and got same results
    as previous runs.
    BUGS:
    made for loop in original dominion.c line 833 i <= 3 when
    originally written as i < 3.  Currently bug is on line
    676 within play_smithy function call. 
    ***during unit test for play_smithy, I realized that i < 3 was a bug
    as originally written when I changed it to i <=3 i fixed it accidentally.
    
    
adventurer:
    cut case (adventurer), used if card == adventurer.  Passed
    temphand array as integer pointer since used in later cases
    from cardEffect.  Put in funciton play_adventurer see dominion.h for header.  Moved variable declaration used locally for adventurer 
    only from cardEffect to play_adventurer.  Fun call on line 706 in card Effect. 
    Bug: 
    changed conditional for if(cardDrawn == copper || cardDrawn == silver || cardDrawn == gold) to if(cardDrawn == copper || (cardDrawn == silver && cardDrawn == gold)).  Game function still runs with now different
    results.
    
    
remodel:
    cut case (remodel), used if card == remodel inside of cardEffect fn to 
    make fn call to play_remodel.  Updated dominion.h with header info.
    Left variable declarations used in other cards / cases or fn's inside
    cardEffect. Logic structure unchanged.  Passed all necessary 
    variables from cardEffect to fn.  
    Bug:
    changed:
    if ( (getCost(state->hand[currentPlayer][choice1]) + 2) > getCost(choice2) )
        to:
    if ( (getCost(state->hand[currentPlayer][choice1]) + 3) > getCost(choice2) )
    Still ran but with differing results.

council room:
    cut and pasted council_room into it's own function.  No change
    to logic sturcture, using if card == council_room, changed dominion.h to include
    function header.  Passed parameters from cardEffect, 
    for loop int i the only new var declared.
    Bug:
    commented out: state->numBuys++;
    The card is supposed to increase number of buys by one, this 
    disables this feature, ran it and didn't change results but
    other inputs would certainly have an effect on the game with 
    no increase in buys for that card. 
    Code still compiling and running with all bugs. 
    
village:
    cut and pasted village from switch to play_village fn.
    used if(card == village).  See dominion.h for fn prototype. 
    Passed all vars from cardEffect.  No new vars declared.
    Bugs:
    No bugs introduced at this time, 4 /5 completed for this assignment.
*******************************************************/

test commit,making sure correct directory