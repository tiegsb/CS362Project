NOTES ON RANDOM TESTING
--------------------------------------------------

11/7/2015:

Converting my existing card test code to random-testing code was a bit
more work than I expected. The volume of output concerned me, as I
originally set up my non-random card tester for the Adventurer card
(cardtest2.c) to output all changes to the state of the game regardless of
errors. When I bumped up the test runs to 50,000, my Linux system killed
the process after the output file hit 50MB, which happened at around test
run 15,000. My "solution" to this problem was to limit the test runs to
13,000 and I only output state changes if a test failed. Except in random
circumstances, this allows tests to complete without removing the bug that
I added to adventurerCard() earlier this quarter (explained below).

It was actually hard figuring out what to randomize for the Adventurer
card tests. Two players are really all that's required for testing, so
random players seems pointless. I opted to randomize the deck instead.
There are three tests for Adventurer card and they are all run against
each player's deck:

    TEST 1: random deck size from 10 to MAX_DECK, no treasure cards
    TEST 2: random deck size from 10 to MAX_DECK, only one treasure card
    TEST 3: random tiny deck size up to 10, random cards

A new game is created and initialized before each test, so the tests all start
with a clean slate.

Complicating matters a bit is the forementioned bug that I added to the
Adventurer card code in dominion.c. Specifically, I eliminated a bit of
code that would put drawn cards at the end of the hand. In an effort to
test that the tests were actually testing things correctly, I changed
dominion.c back temporarily to allow cards to be added to the end of the
hand. Once I was confident that the code in the tester worked, I put the
bug back in dominion.c.

The following was carried over from Assignment 3's unit test coverage
notes for adventurerCard():

  Lines executed:100.00% of 18
  Branches executed:100.00% of 12
  Taken at least once:83.33% of 12
  Calls executed:100.00% of 3

The following was copied from a recent randomtestadventurer.out report for
adventurerCard():

  Lines executed:100.00% of 19
  Branches executed:100.00% of 12
  Taken at least once:100.00% of 12
  Calls executed:100.00% of 3

I have to assume the change from 18 to 19 in the "Lines executed..." line
is from my edits when reversing the forementioned bug. Rest assured, the
bug is in there. It is probably stating the obvious but I'll say it
anyway: I am happy with the coverage. I have to assume that the extra deck
work that I did with this tester filled holes with coverage. Notes from
Assignment 3 indicated that testing for treasure cards may be needed; now
that I am running adventurerCard() with limited or even no treasure cards,
I must be exercising the function more thoroughly.


11/8/2015:

I have discovered the reason my test runs had to be limited: not because of
output file size (which gets huge), but because I had two sets of major memory
leaks, one for each set of structs (the game state struct and the other struct
that stores the game state before it's changed). 

Before fixing the leaks, running even 12,000 tests could lock up resources and,
if it exited at all, would leave the system in an instable state. Now that the
memory leaks have been fixed, the tester runs too fast. Again, the dilemma
is the bug that I introduced into the adventurerCard() function earlier in
the quarter, the one that guarantees the testing will fail. When a test
fails, a full comparison between the original game state and the changed
game state is done and the results are reported. This, times 30,000 (the
current number of test runs), makes the output file approximately 140MB
depending on how the random number generation goes. I am going to continue
to limit the tests to 30,000 runs because of this. I could go higher, much
higher, but output file size would be prohibitive. I do not want to remove
the extended reporting, the only way to reduce output file size without
fixing the bug. I guess we're at an impasse.


11/8/2015 (later):

Got randomtestcard.c going. With randomtestadventurer going smoothly, getting
this tester set up wasn't very difficult. I'm slightly perplexed by the
coverage, though, at least on the first round.

From the coverage report in assignment 3:

  Lines executed:92.86% of 14
  Branches executed:100.00% of 10
  Taken at least once:70.00% of 10
  Calls executed:100.00% of 4

From the first test runs of randomtestcard:

  Lines executed:100.00% of 14
  Branches executed:100.00% of 10
  Taken at least once:90.00% of 10
  Calls executed:100.00% of 4

An improvement for sure, but the "Taken..." line only reports 90%. 100% of
branches are executed, though, so I'm honestly not sure this is an issue. 

As with randomtestadventurer, randomtestcard outputs quite a bit of content if
tests fail. I still feel that this is important to leave in, so rather than
limit my reporting I'm opting to limit the number of test runs to the same
number that is run with randomtestadventurer: 30,000. This results in an output
file that approaches 140MB. Perhaps this is not large by testing standards, but
it feels like a lot to me. I'm sure I'll hear if this is acceptable or if I need
to adjust the testers to output less and run longer. For now, I think I'm going
to clean up the code and submit the assignment.
