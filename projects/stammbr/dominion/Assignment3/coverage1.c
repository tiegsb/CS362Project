/**********************************
 * Author:  Brian Stamm
 * Program:  coverage1.c
 * Date:  10.25.15
 * Notes:  Refer below.
 * ******************************/

/*******************************************************

This file goes over all the tests completed in Assignment 3, and discusses
any insight I had in completing this assignment.

First, for the general overview, the coverage numbers did provide me with 
some general insight in my code writing.  First, deals with the "conciseness"
of my code, which probably speaks more to the design.  When looking at some
of the statements I wrote, I have an if/else set up - however, if I had designed
the code and phrased it better, it would help with some of the "general" coverage
numbers (i.e. line 69 in unitTest1).  It is interesting that I do not have a
100%, and it does seem hard to get to that number.  Although, as mentioned in the
lectures, 100% coverage does not mean your tests are perfect, does become an easy
number to focus on.  This sets up my test coverage to generally do well in branch
coverage, but still lack in overall coverage and call executed.  Also, I have not
made good use of assert statements, which I hope to correct.

Doing this for the first time, it is interesting to see the various coverage
numbers and what they mean.  For instance, in unitTest1, the first test I had was to 
check the first if statement in the shuffle() function.  It is a simple if/else statement
that checks to see if shuffle checks the deckCount correctly.  This test has 100% branch 
coverage, even though it never executes the else part (which signifies a failed test).

In my unitTest2, I had poor coverage (at least in the "calls executed" category), but this 
was due to the fact my tests had several if/else statements.  Still, the overall coverage was
around 80%.  Initially, I thought this was a good test, but the output and the coverage seem
to indicate to me there is some issue with this method.  I attempted to look through the test
and see if there were obvious flawed logic, but I cannot find any at this time.

For unitTest3, there is good branch coverage (meaning that at least one of the branches were used),
which is good, but it appears that most of my testing is set up to work that way.  I should learn
more techniques in testing over the course of this class, so that my tests are not just an either or
set up.  I did not find out anything more interesting about the gainCard() method, and it passed
my tests that I set up.

For unitTest4, again I have good branch coverage and some good line coverage.  

In cardTest1, I forgot this was one of the cards I introduced a bug into.  I first attempted
to test to make sure that everything worked well, and when I saw that it failed a few tests,
I included some random testing and printed out values to see where the issue was.  Come to
find out.

CardTest2, the resutls are curious, which leads me to think there are issues both with the test
and with the function.  It was one of the functions that I introduced a bug into, so it's clear
that there should have been problems, but in the tests I wrote up, it passed all of them.  It even
pased a test that should have produced some issue - there were no treasure cards available in the
deck.

CardTest3 looks at the Village Method, which passed all the initial tests.  There does not seem
to be a problem with the function, at least with ran against my tests.  But the coverage is still
not great.  It is not the worst of my tests, but it should / could be better.

CardTest4 looks at teh Council card, and it has a clear flaw in the deckCounting, which shows partly
the bug I introduced.  Again, as with all of my tests, the branch coverage is good while the line and 
calls are between 50% to 75%.

In conclusion, reviewing the tests and results I have, I feel as if my first design in testing
is okay, but there are dramatic improvements I could make.  First off, I think my coverage suffered
in part because I included random testing, which I should have waited to try and just focused on
basic testing.  Secondly, most of my designs are if/else statements, and I would be better served
in setting up tests which check values compared to what is expected.

***********************************************************/