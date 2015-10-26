I combined all of my tests into one suite and that gave me the following numbers:

Lines executed:38.37% of 563
Branches executed:42.21% of 417
Taken at least once:36.93% of 417
Calls executed:22.00% of 100

As you can see, this is very minimal coverage. There are many functions, lines, branches that have
not been tested. We have only tested 3 cards and 4 functions. Simply adding more tests or creating
more hollistic ones would greatly add our to our coverage and to some degree, confidence, in the
correctness of our program.

cardtest1
adventurer card:
	All statments and almost all branches are covered here, which is interesting.
	The only case not covered is if a drawn card is gold. Since this is just comparing integers,
	that may not add too much value but would be trivial to consider.
	Calls Shuffle/Drawcard:
	Shuffle has full branch coverage and good line coverage. Since
	it is a supporting function, it is called many many times (385)
	Drawcard similarly is called many times, 674. It has complete branch coverage though,
	many of the brnaches are run a minium of times (1-16).

cardtest2
smithy card:
	Same story as above. They are pretty similar cards & tests.

cardtest3
village card:
	100% Branch/Line test coverage here, all thie lines within the function were ran 20 times.
	Granted, it is a very simple function and does not have any branches. This is going
	on the assumption the component funcitons are workign properly. A big takeaway here is just
	because coverage is good doesn't mean the tests are. I know the tests here could be improved
	in many many ways but coverage makes it look fantastic.

cardtest4
	Never got to it due to time constraints.

unittest1
    isGameOver() function
	100% branch coverage/statement coverage within this function. Several branches are run only 1 time.
	Due to using Fuzzing, this one actually has some pretty solid coverage metrics.
	They could be even better if you ran thsi function more times, as you might in the real
	world.

unittest2:
	discardCard() function
	Here we only have 89% branch coverage but with full statement coverage. Many of those branches have been run a minimal
	number of times. We do have strong statement coverage. I am pretty sure this is missing functionality
	to actually place the card into the discard pile and increment discard size. Coverage does not help us
	with that however since it is an error of omission.

unittest3:
	scoreFor() function
	here we have full statement coverage with 86% branch coverage. We could have easily added more
	cards of varying values to get fuller coverage. In this case, branch coverage  gives us a good
	idea of the performance of our tests since we are using simple comparitors for basic data types.


unittest4:
	getWinners()
	Called only 4 times. Executed full statement with 97% branch.
