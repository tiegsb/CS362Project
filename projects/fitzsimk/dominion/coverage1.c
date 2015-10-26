** for unit test output if expected == result, test was passed, I did not add explicit pass or fail statements to my output **
-- Overall Coverage --
( I ran gcov with the -b option )
Lines executed:40.99% of 605
Branches executed:41.72% of 441
Taken at least once:37.64% of 441
Calls executed:22.45% of 98

The four functions I tested were gainCard, scoreFor, endTurn, and isGame over. 
The four cards were smithy, adventurer, play curse, and treasure map. I tried to use
branch coverage testing when it seemed that checking all cases was necessary, but
for the most part, I tried to focus on maintaining statement coverage and block coverage at a minimum. 
I also tried to maintain that if I did not cover a statement or block, it was because I had tested it in another 
test in the test unit with similar input. 

My tests for the scoreFor()  function resulted in less branch coverage than the other unit tests. 
I tested the arithemetic for that function with one kind of each card present. Gcov said that I had 100% branch
coverage for the rest of the functions I tested. 


I could have tested many more parameter values for each of these functions, especially to check
what results from illegal input. I was trying to focus on making sure the a) rules of the game where reflected
in each function, b) logic was correct. There were parts of some functions that had DEBUG written
in a conditional, like if(DEBUG)... and I wasn't sure what to do with it? I also think there were times
where I should have tested the playedCard pile along with the discard, hand and deck piles. 

From searching on the code that did not execute, I can see that I didn't use enough of the action/ buy/
playing card related functions in my tests. I should have used tests that called on these functions to see how they could
alter behavior, instead of relying on so many treasure cards or simple action cards.