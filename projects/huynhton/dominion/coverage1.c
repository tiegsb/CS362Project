/* Tony Huynh	CS 362 Fall 2015	coverage1.c

In the GCov file I had outputted, it outputs my own test results and the GCov coverage percentage onto the
unittestresults.out file.  I have already talked about my own test results in the bug1.c file. To get an updated unittestresults.out, I have to manually remove it first with "rm unittestresults.out".  Running "make all" does not update the file.

For most of the unit/card tests, the lines and branches were executed less than 50% of the time.  I'd say
for most of them, the line/branch coverage hovers around 20%.  The calls executed got a higher percentage.
Except for one of my files (cardtest3.c), they all got at least an 80% call execution.

I believe what this means for the test codes is that they only test certain lines within dominion.c  In some ways, I believe this is expected, since we are doing unit tests and card tests, so they only look for certain parts of the code to run.  It sounds like a a good test suite has good coverage, so I can improve this test suite by improving my coverage, presumably by increasing the percentage that the test can cover.  I don't know if I can make the increase in code covered significant.  I can, however, at least increase it by a few percent, and I believe that would be a good start to improving coverage.  To do this, I think I would make my unit tests and card tests check for other conditions. Doing this should increase the percentage of code covered.








*/