/*
	According to the result of the coverage test for all the tests, the average statement coverage is 70%, that means I execute almost all the lines the
test file, some of them are printf() statement help me see the output result. However I got 100% average branch statement which the test execute all the
neccessary statement to pass the test.
	My coverage for calling the functions that I test are pretty good, they returned 100%  and block executes 100%. These result indicates that I
executes all the statement in the function that I test, and since I execute them all, if the tests passes that means it passes because there is no place for
bug to hide.
	However my coverage for dominion.c file are pretty low, average about 25% lines and branch executes. It is understandable because I did not write
the test that cover all the functions in the dominion file. This problem could improve as I write more test that cover other functions until I write tests
that cover all the functions in dominion.c file, I believe I could achieve coverage of 95% or more just like my function and test coverage.
	According to the dominion.c.gcov, the part that I didn't cover are functions: newGame(), kingdomCards(), playCard(), buyCard(), fullDeckCount(),
endTurn(), isGameOver(), scoreFor(), getWinner(), drawCard(), cardEffect(), discardCard(), gainCard(), updateCoins(), CEsteward(). I need to write test for
these functions.
	The coverage statement is helpful when the test fail but we do not cover all the part of the test, and may be the missing part in the test is the one
that trigger the bug.
	There are some case that bug overlap each other, and those test could find multiple bugs, because fixing one bug would not pass the test, so I have
to go back and find and fix some other bugs that fail that test as well. I find this difficult to write test for specific bug and only for that bug. The way
I design my test is, I write a test that cover a whole function, to see whether or not the function has a bug or not. If the function has some bugs, I write
a smaller test for large section in the function such as for loop or while loop, to see where the bug hidden. Finally I check individual single statement to
find that specific bug. Basically I write test to search the bug in big area, then reduce the size of it smaller and smaller until I find the bug.
	The most subtle bug in my opinion is the one that hide in the call function in the function that we test. For example, in cardTest1, where I test
smithy() function, the bug hide in the discardCard() function that I call to discard the smithy card after I play. I never thought there is bug in
discardCard() function, because I assume that it is working properly. The lesson I learn is that calling other functions that we haven't test yet are not
100% working, there could be bugs in them as well.
	Another problem is that I am not familiar with the program to run it, so I can only test the initial state of the game. For the future reference,
I will have to learn how to play the game on this program, and so I can write tests for the function at different state of the game, so they are more valid.



The coverage for all the tests are:

unittest1.c:
File 'dominion.c'
Lines executed:16.53% of 599
Branches executed:16.23% of 419
Taken at least once:14.80% of 419
Calls executed:6.42% of 109
dominion.c:creating 'dominion.c.gcov'

unittest2.c:
File 'dominion.c'
Lines executed:21.54% of 599
Branches executed:22.91% of 419
Taken at least once:21.48% of 419
Calls executed:6.42% of 109
dominion.c:creating 'dominion.c.gcov'

unittest3.c:
File 'dominion.c'
Lines executed:21.87% of 599
Branches executed:22.91% of 419
Taken at least once:21.96% of 419
Calls executed:6.42% of 109
dominion.c:creating 'dominion.c.gcov'

unittest4.c:
File 'dominion.c'
Lines executed:23.37% of 599
Branches executed:22.91% of 419
Taken at least once:21.96% of 419
Calls executed:8.26% of 109
dominion.c:creating 'dominion.c.gcov'

cardtest1.c:
File 'dominion.c'
Lines executed:26.04% of 599
Branches executed:24.82% of 419
Taken at least once:23.15% of 419
Calls executed:10.09% of 109
dominion.c:creating 'dominion.c.gcov'

cardtest2.c:
File 'dominion.c'
Lines executed:30.72% of 599
Branches executed:28.64% of 419
Taken at least once:26.25% of 419
Calls executed:12.84% of 109
dominion.c:creating 'dominion.c.gcov'

cardtest3.c:
File 'dominion.c'
Lines executed:32.22% of 599
Branches executed:30.07% of 419
Taken at least once:27.68% of 419
Calls executed:15.60% of 109
dominion.c:creating 'dominion.c.gcov'

cardtest4.c:
File 'dominion.c'
Lines executed:33.06% of 599
Branches executed:30.07% of 419
Taken at least once:27.68% of 419
Calls executed:17.43% of 109
dominion.c:creating 'dominion.c.gcov'

function compare called 548 returned 100% blocks executed 100%
function initializeGame called 12 returned 100% blocks executed 98%
function shuffle called 44 returned 100% blocks executed 100%
function numHandCards called 2 returned 100% blocks executed 100%
function handCard called 9 returned 100% blocks executed 100%
function supplyCount called 5 returned 100% blocks executed 100%
function drawCard called 66 returned 100% blocks executed 86%
function getCost called 28 returned 100% blocks executed 100%
function discardCard called 3 returned 100% blocks executed 75%
function updateCoins called 9 returned 100% blocks executed 80%
function CEsmithy called 1 returned 100% blocks executed 100%
function CEadventurer called 1 returned 100% blocks executed 100%
function CEcouncil_room called 1 returned 100% blocks executed 100%
function CEgreat_hall called 1 returned 100% blocks executed 100%
you can see the result in the file unittestresults.out
*/
