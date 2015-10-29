Overall I had relatively low coverage of the dominion.c file around 17-22%
this is not unexpected as I am only accessing normally a single function
within the dominion.c. I would expect that over time as we develop
more tests for domion.c this number will increase until it gets close
to 100% if we end up testing all the code for domion.

Each one of my unit/card tests had good line execution with lowest being
87% and great branch coverage 7/8 being 100%. If I were to test my tests by
having every test pass and fail at least once then I would expect my line
execution to jump to almost 100% as the 87% line coverage is due to the fact
that if a tests passes it will normally always pass so the fail section
is not executed and the same hold true for tests that normally fail.
My taken atleast once was atleast 50% which makes sense as my tests were pass or fail

What would be very useful in the future would be to break out each function
that is being tested so that we can view what % of the function being tested is being
covered as knowing the % of the domion file that is covered is not very helpful when it
is such a small amount. For example unittest1 is for the draw card function wit ha coverage of 18.13%
while update coins have 15.89% coverage, is this because the unittest1 does a better job testing its 
function or could it be because drawcard is a more robust function so more total lines of code were executed.





File 'unittest1.c'
Lines executed:87.30% of 63
Branches executed:100.00% of 18
Taken at least once:50.00% of 18
Calls executed:66.67% of 24
unittest1.c:creating 'unittest1.c.gcov'

File 'unittest2.c'
Lines executed:89.36% of 47
Branches executed:100.00% of 10
Taken at least once:50.00% of 10
Calls executed:70.59% of 17
unittest2.c:creating 'unittest2.c.gcov'

File 'unittest3.c'
Lines executed:91.67% of 48
Branches executed:100.00% of 16
Taken at least once:93.75% of 16
Calls executed:80.00% of 10
unittest3.c:creating 'unittest3.c.gcov'

File 'unittest4.c'
Lines executed:86.21% of 58
Branches executed:100.00% of 16
Taken at least once:50.00% of 16
Calls executed:75.00% of 32
unittest4.c:creating 'unittest4.c.gcov'

File 'cardtest1.c'
Lines executed:91.67% of 36
Branches executed:87.50% of 16
Taken at least once:43.75% of 16
Calls executed:70.00% of 10
cardtest1.c:creating 'cardtest1.c.gcov'

File 'cardtest2.c'
Lines executed:92.31% of 26
Branches executed:100.00% of 4
Taken at least once:50.00% of 4
Calls executed:75.00% of 8
cardtest2.c:creating 'cardtest2.c.gcov'

File 'cardtest3.c'
Lines executed:91.67% of 24
Branches executed:100.00% of 4
Taken at least once:50.00% of 4
Calls executed:75.00% of 8
cardtest3.c:creating 'cardtest3.c.gcov'

File 'cardtest4.c'
Lines executed:90.00% of 30
Branches executed:100.00% of 6
Taken at least once:50.00% of 6
Calls executed:70.00% of 10
cardtest4.c:creating 'cardtest4.c.gcov'

