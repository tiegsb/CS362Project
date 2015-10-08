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
    
    
adventurer:
    cut case (adventurer), used if card == adventurer.  Passed
    temphand array as integer pointer since used in later cases
    from cardEffect.  Put in funciton play_adventurer see dominion.h for header.  Moved variable declaration used locally for adventurer 
    only from cardEffect to play_adventurer.  Fun call on line 706 in card Effect. 
    Bug: 
    changed conditional for if(cardDrawn == copper || cardDrawn == silver || cardDrawn == gold) to if(cardDrawn == copper || cardDrawn == silver && cardDrawn == gold).  Game function still runs with now different
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
*******************************************************/