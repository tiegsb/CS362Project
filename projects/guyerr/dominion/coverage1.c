Unit test 1:
	- 78.95% of lines in unittest1.c were covered and 77.27% branch coverage was reached.
	- The places where I see that sections of the code were not covered are on the following:
		-Section of the code where player is 1 or 2 and the deck count is greater than 0. This section of the code was to catch
		failures if the drawCard function did not correctly increase the hand count or decrease the deck count.
		-Failure statement to tell the user if the shuffle statement did not execute correctly.
		-Failure statement to tell the user that the drawcard function did not return a -1 when an invalid player was passed to the function.
		
Unit test 2:
	- 93.06% of lines in unittest2.c were covered and 100% branch coverage was reached.
	- The places where I see that sections of the code were not covered are on the following:
		-Section covering the case where the cost of the card in returned from the getCost function is not equal to expected.
		-Section where the getCost function doesn't return a -1 when it should (ie the card is not a valid card for the game).
		
Unit test 3:
	- 97.22% of lines in unittest3.c were covered and 100% branch coverage was reached.
	- The places where I see that sections of the code were not covered are on the following:
		-The only place where I see a section that was skipped is for the case where the updateCoins function failed to return the correct value.
		
Unit test 4:
	- 97.22% of lines in unittest4.c were covered and 100% branch coverage was reached.
	- The places where I see that sections of the code were not covered are on the following:
		-The only place where I see a section that was skipped is for the case where the shuffle function failed to return a card order different than the order passed into the function.

Card test 1:
	- 96.67% of lines in cardtest1.c were covered and 100% branch coverage was reached.
	- The places where I see that sections of the code were not covered are on the following:
		-The only place where I see a section that was skipped is for the case where the hand count should have increased by 2 after the card was used but did not.
		
Card test 2:
	- 88.46% of lines in cardtest2.c were covered and 100% branch coverage was reached.
	- The places where I see that sections of the code were not covered are on the following:
		-One section where I see a possible issue for with the actual test is where I used the == comparison to see if two values are the same. From the code, it looks like these 
		sections should have executed at least once but did not for some reason. The secitions that didn't actually execute are the count++ functions.
		-The other place where I cee code that has been skipped is in the sections that return when a test failed.
		
Card test 3:
	- 82.76% of lines in cardtest3.c were covered and 100% branch coverage was reached.
	- The places where I see that sections of the code were not covered are on the following:
		- One place where the code never reached was the case where it was player 2's turn. This is not a surprise as I did not include that case in this round of testing.
		- The other sections cover cases where the test failed.
		
Card test 4:
	- 90.63% of lines in cardtest4.c were covered and 100% branch coverage was reached.
	- The places where I see that sections of the code were not covered are on the following:
		- The only sections where I see code that was not reached is for cases where the test failed.
		
Overview:

Overall it looks like the main parts of the tests that did not execute were the cases where things failed. This is not really a surprise since the failed return would mean that there was a bug
or perhaps that the test case itself is messed up. It looks like the majority of the code written to execute the tests was executed which is a good thing but doesn't really mean much by itself.
A really simple and useless test can go through execute every statement while a complex test might only execute 50% of its lines.

One thing that I would have liked to do more of is test boundary cases. I was able to test many of them in my unit tests but more is always better. One issue I thought of while trying to test boundary cases
is the fact that many of the cases I thought of were actually testing a function inside the function I was calling. For instance, the smithy card uses the drawcard function. So, when testing the smithy function
and run into a case where the deck is empty, is an error at that point related to the smithy function or is it a deeper issue with the the drawCard function itself.

Dominion.c
Although my coverage of the unit tests was good, the coverage of the dominion.c code was pretty bad. From the looks of the test output, the average number of lines executed was about 18%. This means that
the other 82% of the code was not executed. These results are to be expected however because the scope of the unit tests we created. We were only tasked with covering 4 functions and 4 cards which is a very small set
when looking at the entire code. The better metric to look at here would be to see how much of the dominion code that relate to the function/card you were testing was actually covered. It could be that 10% coverage of the 
Dominion code actually covered all the sections that you needed to test. Maybe you were just testing the initializeGame function. If so, none of the card functions and many of the other functions would not be included
in your coverage of the code. I guess the main point is that you want to have good coverage of the code that is important for you to test. If it is unrelated to your test then its is out of scope for you.
		

		