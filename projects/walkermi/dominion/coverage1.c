Unit Test Results:


Unit Test 1 - updateCoins

Unit Test 1: unittest1.c gcov
File 'unittest1.c'
Lines executed:100.00% of 46
Branches executed:100.00% of 30
Taken at least once:63.33% of 30
Calls executed:64.52% of 31
unittest1.c:creating 'unittest1.c.gcov'

Unit Test 1: dominion.c gcov
File 'dominion.c'
Lines executed:15.92% of 578
Branches executed:15.83% of 417
Taken at least once:13.43% of 417
Calls executed:7.45% of 94
dominion.c:creating 'dominion.c.gcov'

Unit Test 1: Analysis
	- This unit test was perfect in regards to its own line coverage: 100%
	- This unit test was perfect in regards to its own branch coverage: 100%
	- This unit test covered a small amount of dominion.c in regards to line coverage 
		but since this was just a test of one function it is was expected: 15.92%
	- This unit test covered a small amount of dominion.c in regards to branch coverage 
		but since this was just a test of one function it is was expected: 15.92%
	- No bugs were found in this function so either this was a function that had no bugs
		or my tests did not cover enough cases, since every line and branch of my unit test
		was covered 100%.


Unit Test 2 - fullDeckCount

Unit Test 2: unittest2.c gcov
File 'unittest2.c'
Lines executed:100.00% of 51
Branches executed:100.00% of 26
Taken at least once:88.46% of 26
Calls executed:84.21% of 19
unittest2.c:creating 'unittest2.c.gcov'

Unit Test 2: dominion.c gcov
File 'dominion.c'
Lines executed:17.13% of 578
Branches executed:18.71% of 417
Taken at least once:15.83% of 417
Calls executed:7.45% of 94
dominion.c:creating 'dominion.c.gcov'

Unit Test 2: Analysis
	- This unit test was perfect in regards to its own line coverage: 100%
	- This unit test was perfect in regards to its own branch coverage: 100%
	- This unit test covered a small amount of dominion.c in regards to line coverage 
		but since this was just a test of one function it is was expected: 17.13%
	- This unit test covered a small amount of dominion.c in regards to branch coverage 
		but since this was just a test of one function it is was expected: 18.71%
	- No bugs were found in this function so either this was a function that had no bugs
		or my tests did not cover enough cases, since every line and branch of my unit test
		was covered 100%.




Unit Test 3 - discardCard

Unit Test 3: unittest3.c gcov
File 'unittest3.c'
Lines executed:81.61% of 87
Branches executed:97.67% of 86
Taken at least once:72.09% of 86
Calls executed:75.00% of 28
unittest3.c:creating 'unittest3.c.gcov'

Unit Test 3: dominion.c gcov
File 'dominion.c'
Lines executed:17.65% of 578
Branches executed:17.27% of 417
Taken at least once:14.15% of 417
Calls executed:7.45% of 94
dominion.c:creating 'dominion.c.gcov'

Unit Test 3: Analysis
	- This unit test was not where I expected it to be in regards to its own line 
		coverage: 81.61%. I thought I had written a unit function in which every line
		was called. Upon further inspection of the gcov file the lower than expected line
		was due to my game state comparison function which compared game states from before
		and after calling the function being tested. This comparison function has nearly 20
		return statements which indicate a bug due to the pre and post game state not matching
		when in fact they should. Since this unit test did not uncover any bugs, these return
		statements were never called, and therefore decreasing my line coverage. 
	- This unit test was near perfect in regards to its own branch coverage: 97.67%
	- This unit test covered a small amount of dominion.c in regards to line coverage 
		but since this was just a test of one function it is was expected: 17.65%
	- This unit test covered a small amount of dominion.c in regards to branch coverage 
		but since this was just a test of one function it is was expected: 17.27%
	- No bugs were found in this function so either this was a function that had no bugs
		or my tests did not cover enough cases, since every line and branch of my unit test
		was covered near 100% (not including the return statements not called as mentioned above).




Unit Test 4 - gainCard

Unit Test 4: unittest4.c gcov
File 'unittest4.c'
Lines executed:82.47% of 97
Branches executed:100.00% of 108
Taken at least once:74.07% of 108
Calls executed:71.79% of 39
unittest4.c:creating 'unittest4.c.gcov'

Unit Test 4: dominion.c gcov
File 'dominion.c'
Lines executed:17.82% of 578
Branches executed:16.79% of 417
Taken at least once:13.67% of 417
Calls executed:8.51% of 94
dominion.c:creating 'dominion.c.gcov'

Unit Test 4: Analysis
		- This unit test was not where I expected it to be in regards to its own line 
		coverage: 82.47%. I thought I had written a unit function in which every line
		was called. Upon further inspection of the gcov file the lower than expected line
		was due to my game state comparison function which compared game states from before
		and after calling the function being tested. This comparison function has nearly 20
		return statements which indicate a bug due to the pre and post game state not matching
		when in fact they should. Since this unit test did not uncover any bugs, these return
		statements were never called, and therefore decreasing my line coverage. 
	- This unit test was perfect in regards to its own branch coverage: 100%
	- This unit test covered a small amount of dominion.c in regards to line coverage 
		but since this was just a test of one function it is was expected: 17.82%
	- This unit test covered a small amount of dominion.c in regards to branch coverage 
		but since this was just a test of one function it is was expected: 16.79%
	- No bugs were found in this function so either this was a function that had no bugs
		or my tests did not cover enough cases, since every line and branch of my unit test
		was covered near 100% (not including the return statements not called as mentioned above).






Card Test 1 - Adventurer

Card Test 1: cardtest1.c gcov
File 'cardtest1.c'
Lines executed:84.96% of 133
Branches executed:98.44% of 128
Taken at least once:71.09% of 128
Calls executed:71.05% of 38
cardtest1.c:creating 'cardtest1.c.gcov'

Card Test 1: dominion.c gcov
File 'dominion.c'
Lines executed:23.01% of 578
Branches executed:25.18% of 417
Taken at least once:17.51% of 417
Calls executed:12.77% of 94
dominion.c:creating 'dominion.c.gcov'

Card Test 1: Analysis
		- This unit test was not where I expected it to be in regards to its own line 
		coverage: 84.96%. I thought I had written a unit function in which every line
		was called. Upon further inspection of the gcov file the lower than expected line
		was due to my game state comparison function which compared game states from before
		and after calling the function being tested. This comparison function has nearly 20
		return statements which indicate a bug due to the pre and post game state not matching
		when in fact they should. Since this unit test did not uncover any bugs, these return
		statements were never called, and therefore decreasing my line coverage. 
	- This unit test was near perfect in regards to its own branch coverage: 98.44%
	- This unit test covered a small amount of dominion.c in regards to line coverage 
		but since this was just a test of one function it is was expected: 23.01%
	- This unit test covered a small amount of dominion.c in regards to branch coverage 
		but since this was just a test of one function it is was expected: 25.18%
	- Multiple bugs were found in this function so my tests did in fact cover some important 
		cases that did end up having issues. 





Card Test 2 - Smithy

Card Test 2: cardtest2.c gcov
File 'cardtest2.c'
Lines executed:80.33% of 122
Branches executed:97.92% of 96
Taken at least once:68.75% of 96
Calls executed:71.43% of 35
cardtest2.c:creating 'cardtest2.c.gcov'

Card Test 2: dominion.c gcov
File 'dominion.c'
Lines executed:23.53% of 578
Branches executed:24.22% of 417
Taken at least once:16.31% of 417
Calls executed:12.77% of 94
dominion.c:creating 'dominion.c.gcov'

Card Test 1: Analysis
		- This unit test was not where I expected it to be in regards to its own line 
		coverage: 80.33%. I thought I had written a unit function in which every line
		was called. Upon further inspection of the gcov file the lower than expected line
		was due to my game state comparison function which compared game states from before
		and after calling the function being tested. This comparison function has nearly 20
		return statements which indicate a bug due to the pre and post game state not matching
		when in fact they should. Since this unit test did not uncover any bugs, these return
		statements were never called, and therefore decreasing my line coverage. 
	- This unit test was near perfect in regards to its own branch coverage: 97.92%
	- This unit test covered a small amount of dominion.c in regards to line coverage 
		but since this was just a test of one function it is was expected: 23.53%
	- This unit test covered a small amount of dominion.c in regards to branch coverage 
		but since this was just a test of one function it is was expected: 24.22%
	- A bug was found in this function so my tests did in fact cover at least one important 
		case that did end up having issues. 





Card Test 3 - Great Hall

Card Test 3: cardtest3.c gcov
File 'cardtest3.c'
Lines executed:79.84% of 129
Branches executed:98.04% of 102
Taken at least once:69.61% of 102
Calls executed:65.79% of 38
cardtest3.c:creating 'cardtest3.c.gcov'

Card Test 3: dominion.c gcov
File 'dominion.c'
Lines executed:21.11% of 578
Branches executed:22.30% of 417
Taken at least once:14.63% of 417
Calls executed:11.70% of 94
dominion.c:creating 'dominion.c.gcov'

Card Test 1: Analysis
		- This unit test was not where I expected it to be in regards to its own line 
		coverage: 79.84%. I thought I had written a unit function in which every line
		was called. Upon further inspection of the gcov file the lower than expected line
		was due to my game state comparison function which compared game states from before
		and after calling the function being tested. This comparison function has nearly 20
		return statements which indicate a bug due to the pre and post game state not matching
		when in fact they should. Since this unit test did not uncover any bugs, these return
		statements were never called, and therefore decreasing my line coverage. 
	- This unit test was near perfect in regards to its own branch coverage: 98.04%
	- This unit test covered a small amount of dominion.c in regards to line coverage 
		but since this was just a test of one function it is was expected: 21.11%
	- This unit test covered a small amount of dominion.c in regards to branch coverage 
		but since this was just a test of one function it is was expected: 22.30%
	- Multiple bugs were found in this function so my tests did in fact cover some important 
		casees that did end up having issues. 




Card Test 4 - Village

Card Test 4: cardtest2.c gcov
File 'cardtest4.c'
Lines executed:79.39% of 131
Branches executed:100.00% of 102
Taken at least once:69.61% of 102
Calls executed:68.42% of 38
cardtest4.c:creating 'cardtest4.c.gcov'

Card Test 4: dominion.c gcov
File 'dominion.c'
Lines executed:23.18% of 578
Branches executed:23.74% of 417
Taken at least once:15.35% of 417
Calls executed:12.77% of 94
dominion.c:creating 'dominion.c.gcov'

Card Test 1: Analysis
		- This unit test was not where I expected it to be in regards to its own line 
		coverage: 79.39%. I thought I had written a unit function in which every line
		was called. Upon further inspection of the gcov file the lower than expected line
		was due to my game state comparison function which compared game states from before
		and after calling the function being tested. This comparison function has nearly 20
		return statements which indicate a bug due to the pre and post game state not matching
		when in fact they should. Since this unit test did not uncover any bugs, these return
		statements were never called, and therefore decreasing my line coverage. 
	- This unit test was perfect in regards to its own branch coverage: 100%
	- This unit test covered a small amount of dominion.c in regards to line coverage 
		but since this was just a test of one function it is was expected: 23.18%
	- This unit test covered a small amount of dominion.c in regards to branch coverage 
		but since this was just a test of one function it is was expected: 23.74%
	- Multiple bugs were found in this function so my tests did in fact cover some important 
		casees that did end up having issues. 


Overall - Reflection
	- Overall I am quite pleased with how my unit tests came out as well as performed. My line coverage
		in my unit tests themselves was lower than expected at first glance, however after some 
		investigation it was due to a large comparison function with many error indicating return values
		not being called since their associated errors were not present (or caught). In the future I would like
		to combine all of my unit tests into one large program and see how they all perform together and then
		view the line and branch coverage of dominion.c to see my overall coverage. To improve my coverage of dominion.c
		I would/intend to write a unit test for every card and function that is not inlcuded in the unit tests above.
		After doing so I would consider 95% line and branch coverage a success from dominion.c as a whole.

