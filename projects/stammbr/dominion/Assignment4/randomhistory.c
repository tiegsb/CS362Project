/*****************
 * Author:  Brian Stamm
 * Title:  randomhistory.c
 * Assignment:  4
 * Date:  11.1.15
 * Notes:  Refer below.  Both tests run 100,000 iterations, which only take a 
 * few seconds on my computer.
 * ****************/

 /************ randomtestadventurer.c ************

In this file, it does a random test of the Adventurer card in the Dominion game.
It is called in the adventurerMethod(), and a copy of the method can be found at
the bottom of the file.  In assignment 3, I had incorporated random testing for
this card already, so there were minor edits done to, hopefully, improve the tests
and provide better coverage.

The design of the program is it first does some basic testing to ensure that variables
were initialized and there is no issue with memory.  Then there is a while loop that
runs 100,000 loops.  In that, the player's hand is randomly filled with a random amount
and the player's deck is completely filled with random cards.  Then before calling the
adventurerMethod, I call a function that counts the total amount of treasure cards.
Then, I call the adventurereMethod and then recount the treasure cards - if the amount
has not been increased by 2, then the error number goes up.  If adventurerMethod returns
a negative number, another error number is interested as well.

The some of the changes were cutting back the initial tests.  Rather than printing 
out each correct answer, it just prints out when there is an error.  Also, rather
than having a set number for the player's deck (it was initially set to 10), I changed
it to be a random number.  This was accomplished by mirroring what I had done to fill
the player's hand.

The results from this test is is limited and puzzling.  When first making this test,
I kept on having issues with seg faults.  I retraced the errors I placed in the file, but
the error was coming from another error which I could not place - Line 1151 had z-1.  This 
made the tempHand go out of bounds.  Also, I had forgotten to reset the discardHand number.

I had gone back and completed the coverage for this test, since I did not complete the 
assignment correctly.  If I would have run the coverage for dominion, I would have had:

Lines executed:10.35% of 570
Branches executed:7.11% of 422
Taken at least once:6.16% of 422
Calls executed:5.26% of 95

This is interesting, since the coverage for the random run is quit less, and less for this
card in particular.  Looking at this card and its interactions, it does not have as much 
"involvment" as some of the other cards and tends to be concentrated in just a few lines.  
Because I randomly fill the player's hand and have the max amount of cards in the deck, there
is limited interactions.  My thoughts against making the deck number completely random was
that if there was a small amount (less than 10) and no treasure card, that could product odd
behavior - BUT I believe I checked an instance of that in the designed testing.  So, I thought
it best just to make the cards completely random.

I would probably do a few more things to improve this test - have a completely random deck and
random discard amount.  Also, I would want to double check the discard / deck piles to see that
they have been handled correctly, which I did not check.

************************************************/

/************** randomtestcard.c **************
In this file, it does a random test of the Village card in the Dominion game.
It is called in the villageMethod(), and a copy of the method can be found at
the bottom of the file.  In assignment 3, I had incorporated random testing for
this card already, so there were minor edits done to, hopefully, improve the tests
and provide better coverage.

The design of the program is that is first checks initial values to make sure the function
does what was expected.  The change in this section was that it does not print out if the
values are what was expected.  

Then, the program enters the random test, which has a while loop that has 100,000 iterations.
The deck is filled with a random amount, as is the player's hand.  Then the values which should
change are set, and then the villageMethod is called.  For each value, I have not seen any failed
tests.

The results from this test has definitely better coverage than the other test.  From what I got
on the random tests are:

Total Random Tests:  100000
villageMethod() Random Test fail number iterations:  0
villageMethod() Random Test fail number total:  0
File 'dominion.c'
Lines executed:18.60% of 570
Branches executed:17.06% of 422
Taken at least once:13.51% of 422
Calls executed:9.47% of 95

The reason why I think that the coverage is "better" than in the adventurerMethod is because of
the call to the drawCard() & discardCard() method.  Once those methods are called, it is easy for
a larger area of the dominion.c file to be called.

Improvements I would attempt would be to initialize teh values myself rather than calling the 
function in dominion.c.  I would also increase the amount of runs by alot just to see if running it
by numerous cycles would cause any errors.
************************************************/