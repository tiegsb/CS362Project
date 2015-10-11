/***********
Author:  Brian Stamm
Title:  refactor.c
Assignment:  2
Date:  10.11.15
Notes:  This file explains changes made to dominion.c and dominion.h.
************/

/****************************************

There are 5 different cards that are changed, which are listed below.  ALso. to take those
cards out of the switch statement, per assignment requirements, a larger if-else if-else statement
was created where the original switch statement was placed in the "else" portion.  The five
cards were also deleted out of the switch statement, and individual functions for each were
created.  The start of the if-else if-else statement starts at line 672.  

1.  Adventurer - The function is named adventurerMethod(), called in line 672, defined in line 1138
and returns an int.  The parameters are a pointer struct gameState, an array temphand, and int currentPlayer.
The error is in line 1156 where the while statement should be z-1 instead of just z.

2.  Smithy - The function is named smithyMethod(), called in line 677, defined in line 1160, and returns 
an int.  The parameters are pointer struct gameState, int currentPlayer, and int handPos.  The error is
in line 1165 where the for statement i should be just < rather than <=.

3.  Village - The function is named villageMethod(), called in line 682, defined in line 1172, and 
returns an int.  The parameters are pointer struct gameState, int currentPlayer, and int handPos.  There
was nothing changed in this function.  

4.  Council Room - The function is named councilMethod(), called in line 687, defined 1184, and returns 
an int.  The parameters are pointer struct gameState, int currentPlayer, and an int handPos.  The error
is in line 1200 where i should be != instead of ==.

5.  Feast - The function is named feastMethod(), called in line 692, defined in 1209, and returns an int.  
The parameters are pointer struct gameState, an array temphand, int currentPlayer, and int choice1.  The
error is in line 1224 where x should be == instead of !=.

****************************************/
