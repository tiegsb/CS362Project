Ben Henning
CS 362
Assignment 3
coverage1.c

The line coverage in each test ranged from 76.92% to 86.55%.  Branch execution was 100% for all
tests except for cardtest2 (adventurer), which was 85%.  Upon inspection, most of the lines which
were not covered were print statements indicating a test passed or failed.  Therefore, the line and
branch coverage indicates that the tests mostly executed as they were supposed to.  Taken at least
once was 50% or greater for each of the tests.  Since these were pass/fail tests, 50% also shows
the tests executed as they were supposed to.

Line coverage and branch coverage of dominion.c both ranged from approximately 15% to 25%.  However,
since each test was only testing one specific card or function, this number tends to misrepresent
the effectiveness of the tests.  Running each test and looking at the particular function or card
in dominion.c that it was supposed to test revealed that line and branch coverage were actually
pretty good.

**************************************************************************************************
Unit Test 1 - shuffle()
**************************************************************************************************
File 'dominion.c'
Lines executed:15.83% of 581
Branches executed:15.83% of 417
Taken at least once:13.43% of 417
Calls executed:7.37% of 95

File 'unittest1.c'
Lines executed:78.38% of 74
Branches executed:100.00% of 26
Taken at least once:65.38% of 26
Calls executed:74.29% of 35

**************************************************************************************************
Unit Test 2 - isGameOver()
**************************************************************************************************
File 'dominion.c'
Lines executed:17.21% of 581
Branches executed:17.75% of 417
Taken at least once:14.87% of 417
Calls executed:7.37% of 95

File 'unittest2.c'
Lines executed:78.00% of 100
Branches executed:100.00% of 24
Taken at least once:50.00% of 24
Calls executed:76.00% of 50

**************************************************************************************************
Unit Test 3 - updateCoins()
**************************************************************************************************
File 'dominion.c'
Lines executed:15.83% of 581
Branches executed:15.83% of 417
Taken at least once:13.43% of 417
Calls executed:7.37% of 95

File 'unittest3.c'
Lines executed:85.93% of 135
Branches executed:100.00% of 26
Taken at least once:50.00% of 26
Calls executed:77.19% of 57

**************************************************************************************************
Unit Test 4 - buyCard()
**************************************************************************************************
File 'dominion.c'
Lines executed:20.83% of 581
Branches executed:25.42% of 417
Taken at least once:15.35% of 417
Calls executed:12.63% of 95

File 'unittest4.c'
Lines executed:77.39% of 115
Branches executed:100.00% of 28
Taken at least once:50.00% of 28
Calls executed:74.07% of 54

**************************************************************************************************
Card Test 1 - smithy
**************************************************************************************************
File 'dominion.c'
Lines executed:18.24% of 581
Branches executed:17.75% of 417
Taken at least once:14.15% of 417
Calls executed:9.47% of 95

File 'cardtest1.c'
Lines executed:78.21% of 78
Branches executed:100.00% of 28
Taken at least once:60.71% of 28
Calls executed:70.37% of 27

**************************************************************************************************
Card Test 2 - adventurer
**************************************************************************************************
File 'dominion.c'
Lines executed:21.34% of 581
Branches executed:19.66% of 417
Taken at least once:17.27% of 417
Calls executed:10.53% of 95

File 'cardtest2.c'
Lines executed:86.36% of 132
Branches executed:85.00% of 80
Taken at least once:56.25% of 80
Calls executed:76.47% of 34

**************************************************************************************************
Card Test 3 - sea hag
**************************************************************************************************
File 'dominion.c'
Lines executed:17.04% of 581
Branches executed:17.27% of 417
Taken at least once:14.15% of 417
Calls executed:7.37% of 95

File 'cardtest3.c'
Lines executed:86.55% of 119
Branches executed:100.00% of 60
Taken at least once:78.33% of 60
Calls executed:72.73% of 44

**************************************************************************************************
Card Test 4 - village
**************************************************************************************************
File 'dominion.c'
Lines executed:18.24% of 581
Branches executed:17.27% of 417
Taken at least once:13.67% of 417
Calls executed:9.47% of 95

File 'cardtest4.c'
Lines executed:76.92% of 78
Branches executed:100.00% of 26
Taken at least once:61.54% of 26
Calls executed:70.97% of 31
