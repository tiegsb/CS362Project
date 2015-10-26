Most of my tests had around 20% code coverage. I probably could have increased this number by writing tests for functions that are called within the function I am checking. I did not do this for a lot of these tests, and relied heavily on believing the functions that were called worked. By doing this, I found a couple bugs (mainly with the discardCard function), where the outcome was not what I expected it to be. 
	
Going forward, I would focus on checking all functions that are associated with the current function I am checking, and make sure all of those are doing what they are supposed to be doing.

unittest1.c:
	Lines executed:100.00% of 72
	Branches executed:100.00% of 126
	Taken at least once:73.81% of 126
	Calls executed:17.50% of 40
	
	File 'dominion.c'
	Lines executed:5.08% of 591
	Branches executed:6.71% of 417
	Taken at least once:6.71% of 417
	Calls executed:0.00% of 101

unittest2.c:
	Lines executed:100.00% of 38
	No branches
	Calls executed:100.00% of 7
	
	File 'dominion.c'
	Lines executed:20.47% of 591
	Branches executed:25.42% of 417
	Taken at least once:15.35% of 417
	Calls executed:11.88% of 101

unittest3.c:
	Lines executed:100.00% of 35
	Branches executed:100.00% of 18
	Taken at least once:66.67% of 18
	Calls executed:70.00% of 20
	
	File 'dominion.c'
	Lines executed:16.92% of 591
	Branches executed:17.75% of 417
	Taken at least once:14.87% of 417
	Calls executed:6.93% of 101

unittest4.c:
	Lines executed:100.00% of 33
	Branches executed:100.00% of 22
	Taken at least once:50.00% of 22
	Calls executed:56.00% of 25
	
	File 'dominion.c'
	Lines executed:17.77% of 591
	Branches executed:17.27% of 417
	Taken at least once:14.39% of 417
	Calls executed:7.92% of 101

cardtest1.c:
	Lines executed:100.00% of 25
	No branches
	Calls executed:100.00% of 4
	
	File 'dominion.c'
	Lines executed:18.44% of 591
	Branches executed:17.75% of 417
	Taken at least once:14.39% of 417
	Calls executed:8.91% of 101

cardtest2.c:
	Lines executed:93.10% of 29
	Branches executed:100.00% of 4
	Taken at least once:50.00% of 4
	Calls executed:81.82% of 11
	
	File 'dominion.c'
	Lines executed:18.44% of 591
	Branches executed:17.75% of 417
	Taken at least once:14.15% of 417
	Calls executed:9.90% of 101
		
cardtest3.c:
	Lines executed:100.00% of 23
	No branches
	Calls executed:100.00% of 3
	
	File 'dominion.c'
	Lines executed:18.61% of 591
	Branches executed:17.27% of 417
	Taken at least once:13.67% of 417
	Calls executed:10.89% of 101

cardtest4.c:
	Lines executed:100.00% of 23
	No branches
	Calls executed:100.00% of 3
	
	File 'dominion.c'
	Lines executed:18.44% of 591
	Branches executed:17.27% of 417
	Taken at least once:13.67% of 417
	Calls executed:9.90% of 101

