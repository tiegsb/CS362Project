/***********
Author:  Brian Stamm
Title:  refactor.c
Assignment:  3
Date:  10.25.15
Notes:  This file explains changes made to dominion.c and dominion.h.
************/

/******** For assignment 2 *******************

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

********************************************/


/*********** For Assignment 3 **************

Most tests, I included some random testing, which I thought would help.  I set up some initial testing
of values, and then moved into creating random number of cards or random values.  This was not
as helpful as I thought it would be, but is definitely an area where I can improved.

UnitTest1 - Covers shuffle().  Did not find any bugs in the shuffle method.

UnitTest2 - Covers updateCoins().  At least in my tests, there appears to be some type of bug with the
addition of the coins.  Both adding silver and gold behave odd, especially when the number is higher
than expected.  At this time, I cannot tell if this is in part because of issues with my test writing or
with the program writing.

UnitTest3 - Covers gainCard() method.  In the tests I set up, there were no issues found in this function.

UnitTest4 - Covers the isGameOver() method.  In the tests I set up, it did pass most of the tests,
but there was one random test that it did fail.  It is unclear to me at this time why it failed, but
in the random tests I set up, there seems to bee something off if the card number is low and the providence
cards is off.  Overall, though, it seems like this might be from an extreme case, but should be looked into
further.

cardTest1 - covers the smithyCard, and it definitely shows there is a bug with the totalling.  This is
the result of an introduced bug.

cardTest2 - It looks at the adventureCard, and it passes the tests.  Yet, there was a bug introduced in
this function and it passed a test that should have produced curious results (the final test), so there
appears to be smoke in this function/test pair.

cardTest3 - It tests the Village method, and it appears to pass everythign without issue, but the test
coverage could be better.  Further testing should be done, especially since I am not too confident in my
test making ability yet.

cardTest4 - This looks at the Council method, which I did introduced a bug into, and it fails exactly
where it would be expected.  

*******************************************/