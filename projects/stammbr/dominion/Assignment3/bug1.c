/***********
Author:  Brian Stamm
Title:  bug1.c
Assignment:  2
Date:  10.25.15
Notes:  This file is pretty much just like the "new" refactor.c file, but it goes
over the bugs found through my tests.
************/

/******** bugs *******************

1.  Adventurer - The function is named adventurerMethod(), called in line 672, defined in line 1138
and returns an int.  The parameters are a pointer struct gameState, an array temphand, and int currentPlayer.
The error is in line 1156 where the while statement should be z-1 instead of just z.  It was looked at 
in cardTest2, and it passes the tests.  It passed a test that should have produced curious results (the 
final test), so there appears to be smoke in this function/test pair.

2.  Smithy - The function is named smithyMethod(), called in line 677, defined in line 1160, and returns 
an int.  The parameters are pointer struct gameState, int currentPlayer, and int handPos.  The error is
in line 1165 where the for statement i should be just < rather than <=.  This is seen with the totalling 
issue ran in cardTest1.

3.  Village - The function is named villageMethod(), called in line 682, defined in line 1172, and 
returns an int.  The parameters are pointer struct gameState, int currentPlayer, and int handPos.  There
was nothing changed in this function.  This was tested in cardTest3, and it appears to pass everythign 
without issue, but the test coverage could be better.  Further testing should be done, especially since 
I am not too confident in my test making ability yet.

4.  Council Room - The function is named councilMethod(), called in line 687, defined 1184, and returns 
an int.  The parameters are pointer struct gameState, int currentPlayer, and an int handPos.  The error
is in line 1200 where i should be != instead of ==.  It is tested in cardTest4, and it fails in a few
places.

5.  Feast - The function is named feastMethod(), called in line 692, defined in 1209, and returns an int.  
The parameters are pointer struct gameState, an array temphand, int currentPlayer, and int choice1.  The
error is in line 1224 where x should be == instead of !=.  This was not tested, actually.  This was an 
oversight.

6.  UnitTest1 - Covers shuffle().  Did not find any bugs in the shuffle method.

7.  UnitTest2 - Covers updateCoins().  At least in my tests, there appears to be some type of bug with the
addition of the coins.  Both adding silver and gold behave odd, especially when the number is higher
than expected.  At this time, I cannot tell if this is in part because of issues with my test writing or
with the program writing.

8.  UnitTest3 - Covers gainCard() method.  In the tests I set up, there were no issues found in this function.

9.  UnitTest4 - Covers the isGameOver() method.  In the tests I set up, it did pass most of the tests,
but there was one random test that it did fail.  It is unclear to me at this time why it failed, but
in the random tests I set up, there seems to bee something off if the card number is low and the providence
cards is off.  Overall, though, it seems like this might be from an extreme case, but should be looked into
further.

*******************************************/