/*
randomtestadventurer.c
	This test had a coverage of 27.99%, which definitely is an improvement from previous
	tests from last week. I set the number of tests to 1000 for extra assurance and to
	make sure the test was covering a great amount of possible random scenarios.


randomtestcard.c
	For randomtestcard.c, I tested the Steward card. For this test, I reused the adventurer
	test from above but had some trouble with segfaults and infinite loops. Interestingly
	enough, the segfaults and infinite looping sometimes would not occur when I set MAX_TESTS
	to a lower value (like 10 or so). Once I increased the number of runs per test, nearly
	every test would end up with a segfault or infinite loop, which added a degree of trouble
	in modifying the adventurer test for the steward card. Test coverage was 24.57%, which, 
	like the adventurer test is an improvement from assignment 3.
*/	