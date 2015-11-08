Jody Hansen
CS362 Fall 2015

Report accompanying assignment #4 test code.

randomtestcard():

I chose the Smithy card to randomize the tests. The function alters handCount, deckCount, and
playedCardCount. However I only gave deckCount and playedCardCount random values since handCount
should be typically set at 5 for each round. The others were set as follows.

deckCount was set at a random number from 0 to 30, each of those cards were randomly set from 0
to 26 to account for all supply cards.

PlayedCardCount was randomly set from 0 to 30.

Interestingly, this approach was able to catch two bugs that were not found by the previous unit
test for the Smithy card. Every so often, in 1 in 25 iterations, the handCount is not
increased by two and the playedCardCount is not decreased by 3. These bugs go hand in hand. The
cases in which this happens is when the deckCount is set at a low number of 0 and 1, at least that
is the only numbers I observed. This brings up an interesting question. Is this a bug? I suppose
the function could check to make sure there were enough cards in the deck for the function to
behave appropriately. However, perhaps it's okay that it runs as such since the preceeding code
from cardEffect may choose not to enter that function if the deckCount is low. For exmaple the
isGameOver is checked before entering that function. If this was a requirement, than the test
could be modified so that deckCount and the number of supply cards would never get below the
specified requirements. I think this brings up an interesting case study that may mirror a real
life scenario in which limited communication between the test and development team may lead to
errors in the test cases.

My coverage stayed the same.

Previous Coverage:
Card - Smithy()
Total lines: 4
Lines executed: 4
Branches: 0 of 0

Current Coverage:
Card - Smithy()
Total lines: 4
Lines executed: 4
Branches: 0 of 0

randomtestadventurer():
I found this card exceedingly difficult to test randomly, mostly due to it's dependency on
the drawCard() function. I thought randomly testing adventurer would be easy since it seemed like
the step I needed to take was to randomize the deck. Thus, there should be at least three treasure
cards in the deck. However, my program continued to enter an infinite loop. Side note, I
refactored dominion.c and dominion.h so that the two variables, int cardDrawn_ and int temphand[]
were local variables instead of being passed as arguments. Afterwards, I manually set some values
to make sure there were three treasure cards in the deck. This still did not work! After adding
print statements to the drawCard function, I found that the deck was being evaluated at indices
10, 9, 8, 6, 4, 2 and 0. Oddly enough, 1 was always passed as a coin card. If a coin card was
not at one of these places, drawnTreaseure would not equal to 2 and the deck would evenutally
evaluate as 0 and the program would return -1. Thus, the infinite loop would begin. How do you
cleanly test a function when it depends on a buggy function? Ideally, you would test and fix all
helper functions in the code, before testing functions that depend on them. For this assignment I
didn't have this luxury. I can't give you a unit test that enters an infinite loop. That doesn't
tell you anything and gives me a 0 for the grade. If I was at work, I would mark this user story
as blocked and file a quix for a another user story to fix the bug in cardDrawn. However, for this
assignment I put a long note in my test and set three deck cards to a treasure card to avoid the
infinite loop. Included in the comment is to remove those lines once cardDrawn is properly
working. The test as is displays several bugs in the adventurer card. 

Despite a frustating experience, my line and branch coverage increased to a 100%.

Previous Coverage:
Card - Adventurer()
Total lines: 17
Lines executed: 11
Branches: 3 of 5

Current Coverage:
Card - Aventurer()
Total lines: 17
Lines executed: 17
Branches: 5 of 5
