/**********************************************************************
Anthony Wilcox
CS362 Fall 2015 
Assignment 4
randomhistory.c discussion of development of randomtestcard.c and 
randomtestadventurer.c 
*both files ran inside of a while loop where the global variable MAX_RUN
defines loop control.  It is currently set to 1000.  
**using the makefile in the directory will with the command "make"
It will default to make both randomtestcard.out and randtomtestadventurer.out along with necessary executables.
With 1000 runs in each file, manipulation of that variable can shorten
or lengthen the testing output as per the tester's desire.
***"make clean" will remove the ".out" files and "make cleanall" removes
executables as well as the out files. 

Discussion:
Feedback from assignment three indicated that the tests themselves needed
to be improved.  Examination of the solution gave better understanding as
to good development for test domains along with test oracles for the 
dominion card game and particularly for unit testing of action cards. 

Both "adventurer" and "smithy" were tested.  The first step was to 
improve the domain and oracle, the second was to structure the code in 
a way that lent itself well to random input generation.  The third was 
to add the random test case generation code in order to execute it.

randomtestadventurer.c:
The adventurer card allows the player to reveal cards from their deck 
until they get two treasure cards or the deck is empty.  At that point 
the treasure cards are placed in the player's hand, and then the other 
cards that weren't treasure cards are placed in the discard pile.  

This was a bit of a challenge to come up with a good oracle since the 
player doesn't make a choice, rather the gameState has the information
needed to see what the effects of the card will be.  

I first decided to check how the adventurer card interacted with random
generation of other cards to be played.  I did so by creating an array
of all 20 possible (non treasure or kingdom cards) and randomly shuffling
that array, then populating k with index 0 - 9 from the shuffled array.
Care was taken to ensure adventurer was there by inserting it at a random
index if it had not been inserted by chance already.  

Next I did random iterations of players to see how the number of player 
decks in the game may affect outcome.  This was done prior to game 
initialization and copy to testG gameState.  

For testing, I decided to test first, the number of treasure cards the 
player should have in their hand both before and after the function call.
I did this by manually inserting a random number of between 0 and 5 
treasure cards (also randomly selected rand % 3 0 indexed array of 3 coins) in the player's deck.  I then counted from the top of the
deck down until I got two treasure cards or an empty deck.  This gave
me outputs that included the event that no treasure cards were found
prior to the deck being empty, one, and two.  It also obviously changed
the location in the deck where the cards were found. 

I also maintained the value of the treasure cards.  (copper, silver, gold).  This information known before the function call is made, I had a good baseline to check what the player's hand treasure card count was
before the call, I also counted what the VALUE of the the treasure cards
in the player's hand was.  This allowed me to check if not only the 
correct number of cards were being placed in the player's deck, but also
the right treasure cards.  

Random test generation with thousands of iterations over randomly 
generated gameStates dramatically increased code coverage from a raw 
numbers standpoint.  It revealed that there are more problems with 
drawCard than I had originally thought.  In the end, we already had 
100 % branch and line coverage through play_adventurer, but we didn't execute all conditions in drawCard and that left things unnoticed. 

All test Oracles failed.  These were known but greater coverage and 
iterations revealed more information and would streamline the process 
of debugging.  For example, the number of treasure cards was incorrect 
and had been known to be incorrect.  
However, the value of the treasure cards also fails.  If you cross check
the data, not only are the incorrect number of cards being added to the 
player's hand, but they aren't being properly evaluated either.   

Hand count, deck count, and discard count all failed.  Some iterations 
were correct and I believe these exceptions to be coincidental,
however, it shows the importance of high iterations and increased
coverage through all branches.  

In the end, the revelation of detail as to how many cards the test failed
by, was that number consistent?  Was the value consistent?  They
weren't, but the tens of thousands of lines of code that were executed 
revealed these patterns to be what they were and showed which was the
exception, the bug or the correct computation.  In all cases it was
the former.  In this case, because of the shuffled cards and changes
of card placement throughout the deck along with how they interacted, 
fault localization was not possible or revealed completely by this test.
Perhaps further data analysis of hand values would shed more light on
possible evaluation of cards and determining if maintaining specific 
other cards in the deck may be part of the problem.  This is clearly 
a case where there is a t+x-way combination of bugs that are creating 
the failure, where x is still unknown.  I don't feel that in this case
x is as high as it would be in the case of Smithy, however, I do feel 
that complete card testing with analysis of those cards would reduce
the scope of x dramatically. 

randomtestcard.c:
For this I tested Smithy.  This card allows the player to draw three 
cards.  Again, this relies on information in the gameState to change
so I decided to randomly generate gameState information as it pertained
to Smithy and then pass a modified gameState with known modifications
to Smithy to check the results compared to what they should ultimately
have been.
I also did this thousands of times with randomly generated numbers 
of players.  The number of players was more insightful for this card 
simply to compare hands after card play and ensure no one else get 
the player's cards.

I first shuffled the 20 action cards and placed the first 10 
in the k array putting Smithy at a random location in that array.

I then shuffled all 26 cards in the enumerated values and placed three of
them on top of the deck, keeping track of what they were.  I also 
totalled their enumerated values as well.  This allowed me to compare 
the deck count before and after and know which three cards the player 
would draw along with being able to compare the deck count and hand 
count before and after.  I was also able to compare the hand value which
I took as the sum of the enumerated integer values of each player's hand
to the hand value after the card was played in order to see if not only
were the correct amount of cards being played, but were the correct 
actual cards getting put into the player's hand. 

Lastly I compared all player hand counts before and after the card 
was played.  
I chose to ignore the discard pile for this test because the adjudication
of discarding doesn't occur until after the round.

Again, code coverage for the card itself was 100 % for all lines, what increased here was iterations and again, calls to drawCard.  These 
iterations along with dramatic improvements to test oracles shed a 
great deal of light what level the bugs occur and and how much 
integration testing will need to confirm what we know about drawCard.  

All test oracles failed.  The hand value or sum was incorrect.  The 
count was incorrect as well, so this would lead to an incorrect sum, 
however, looking at the actual data, you can see that the cards 
themselves are incorrect as well.  This can be seen by looking at 
randomtestcard.out 

There was a consistent inaccuracy with the other player's hand 
post play which is new, it needs further examination as to why that 
occurred.  The deck count was improperly incremented along with 
the player's hand count.  This was likely known, but the random 
test cases along with interaction with other cards and numbers of 
players may have caused this.  Each card would need to be tested 
to see in integration testing. In this case, we once again have a 
t+x-way combination to create the failure and fault localization 
seems improbable without having all unit tests completed and prior to 
integration testing.  In this case, x seems like it must be at 
least as high as it would be for testing adventurer.  This also brought
about an interesting thought with testing is the idea of regression in 
the test itself.  Regression of randomtestadventurer to include 
evaluation of other players hands may shed light on how many 
variables are causing at least that particular fault if it occurs there
as well.  If unable to localize this fault by cross checking data from 
test results from multiple units, then we will at least have known 
priorities for integration testing and a nice head start in developing 
a good domain and oracle for such.

In the end, improvement to the domain and oracles was an enormous help
to get clarity on what the bugs were and shed direction as to how
they may be localized.  The use of random test inputs along with high
iteration count didn't necessarily increase coverage, but it did increase the raw 'n' value and modification of 'n' executing those
branches and lines and I think that is what added the most value from
using the random test generator.  




************************************************************************/