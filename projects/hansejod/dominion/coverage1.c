Jody Hansen
Assignment 3

Coverage statistics of each unit and card test:

unittest1:
Function - compare()
Total lines: 5
Lines executed: 5
Branches: 2 of 2

unittest2:
Function - isGameOver()
Total lines: 9
Lines executed: 9
Branches: 3 of 3

unittest3:
Function - shuffle()
Total lines: 15
Lines executed: 15
Branches: 2 of 2

unittest4:
Function - buyCards()
Total lines: 23
Lines executed: 18
Branches: 4 of 9

cardtest1:
Card - Smithy()
Total lines: 4
Lines executed: 4
Branches: 0 of 0

cardtest2:
Card - Adventurer()
Total lines: 17
Lines executed: 11
Branches: 3 of 5

cardtest3:
Card - CouncilRoom()
Total lines: 8
Lines executed: 7
Branches: 1 of 1

cardtest4:
Card - SeaHag()
Total lines: 7
Lines executed: 7
Branches: 1 of 1

My unit tests appeared to have good branch coverage, which, according to one of our quiz
questions, implies good statement coverage. They also have good covereage in terms of executing
close to the total number of lines in the function. There are two exceptions, buyCards() and
Adeventurer(). The buyCards coverage appears to be poor because there were about 5 conditionals
that checked to see if the debug was turned on, and if so to output a statement. The debug was not
turned on so these print statements did not execute. The second case, the Adeventurer function,
the bug was to improperly pass one of the function arguments. In retrospect, I'm not sure if this
was a good choice of bug to introduce in terms of testing the internals of the function. Although
it might very realistic, because I make this mistake often. The result though, was that one of the
variables did not execute any time it was used. This caused several bugs and much of the code
to not execute.

The boundaries cases are most likely where my unit tests are lacking. In all cases I attempted to
test both positive and negative conditions. I also was able to use a randomizer in many of the
unit tests. This along with running the tests several times I believe increased my test coverage.
I will discuss each test individually below.

unittest1:
I was able to use a randomizer to test this function which covered many test cases. However, I
did not test really large numbers. Also, it's not likely that this test will randomly choose 0, so
that boundary case may not have been tested either.

unittest2:
I tested both a positive and negative test case. The positive test occured when all the supply
cards, including province had a value of 1 or more. The negative test case was implemented by
randomly setting the province card value to 0. I also tested to see if the game would end when
the 2 to 5 of the supply cards where set to 0. I might have wanted to expand this to a larger
range, such as 1 to many.

unittest3:
The first branch I tested, the function return the correct value when the cardDeckCount was
set to 0. It did not test what the function might have done to the variable it manipulated.
Testing this may have yielded more information about the bug. Again, the function tested if the
cardDeck of the 1st player was different after the function call. It could have tested more
variables to determine how different it was.

unittest4:
This unit test tested both a positive and negative test case. It tested negative test cases by
setting the variables to 0. It could have been improved by setting more than one variable to 0
at a time. In addtion, the positive test case was set at a single number. I could have tested
a range of positive numbers.

cardtests:
I'm making a general comment on the card tests, since they all seem to be rather similar.
These functions test the before and after state of several variables, including handCount,
deckCount, and playedCardCount. Most likely, I could have inproved the boundary cases by directly
manipulating these values before calling the function and later observing the state change. This
would allow me to use a randomizer and catch more boundary cases.

For all unit tests, I used only two players. An improvement would to be to try several cases that
included different numbers of players.



