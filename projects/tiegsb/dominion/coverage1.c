/*
Brian Tiegs
CS 362 - Assignment 3

Documentation of coverage

********************************************************************************

Total coverage with all tests:

Lines executed:26.42% of 579
Branches executed:36.21% of 417
Taken at least once:29.98% of 417
Calls executed:18.95% of 95

My goal was to design my test functions to give complete statement and branch coverage. I was successful in achieving 100% branch and statement coverage for 6 out of 8 tests. I also attempted to give good boundary value coverage when needed.

After running my test suite, coverage of dominion.c showed 26.42% statement coverage and 36.21% branch coverage. These values are low and would not be sufficient for real world applications. However I was surprised I received as much coverage as I did considering I only implemented 4 unit tests and 4 card tests. To increase this coverage we would simply need to test more functions.

In the following sections I will discuss coverage pertaining to individual test functions.

********************************************************************************

unittest1: scoreFor() function

Lines executed:5.70% of 579
Branches executed:12.95% of 417
Taken at least once:12.23% of 417
Calls executed:3.16% of 95

function scoreFor called 2916 returned 100% blocks executed 100%
Statement coverage: 100%
Branch coverage: 100%

unittest1 was implemented to test the correct calculation of a player's score. This was done by setting all cards in the decks to 1 card type and iterating over the handCount, discardCount and the deckCount. Since all the cards are the same, the score can be easily calculated and compared to the score calculated from scoreFor().

Here I achieved 100% statement and branch coverage. In this case, I took a more exhaustive approach and iterated over all possible variables in the function. As a result, I was able to uncover a couple bugs. The first bug occured when varying the deckCount and discardCount. When these values are different, scoreFor() calculates the score incorrectly. The second bug occurs when scoreFor() calculates the score for decks containing the gardens card. scoreFor() returns a score of 0. This is most likely due to in incorrect usage of fullDeckCount().

I feel this test was implemented very well and provides a huge number of tests (perhaps too many). As a result I feel this test would suffice for good coverage of the scoreFor() function.

********************************************************************************

unittest2: isGameOver() function

Lines executed:1.73% of 579
Branches executed:1.92% of 417
Taken at least once:1.92% of 417
Calls executed:0.00% of 95

function isGameOver called 2927 returned 100% blocks executed 100%
Statement coverage: 100%
Branch coverage: 100%

unittest2 was implemented to test if the game ends when the province card stack is empty or if 3 other card stacks are empty. This was done by implementing a few different tests. First the test function was checks if it would continue if no card stacks were empty. Next the test function checks if the game ends when only the province card stack is empty. The test function also iterates over all possible combinations of 3 empty card stacks and tests if the game ends. Finally the test iterates over all possible combinations of 2 empty card stacks and tests if the game continues.

Here I achieved 100% statement and branch coverage. I also achieved good boundary coverage by testing if the game ends when there is 1 card in the stack or 0 cards in the stack. In addition I tested every combination of 3 empty card stacks and 2 empty card stacks. My high coverage allowed me to uncover a bug where the sea hag card stacks and the treasure map card stacks do not seem to register as empty.

I feel this test function was implemented well and provided a lot of good boundary tests. As a result I feel this test would suffice for good coverage of the isGameOver() function.

********************************************************************************
unittest3: getWinners() function

Lines executed:6.56% of 579
Branches executed:9.59% of 417
Taken at least once:7.67% of 417
Calls executed:2.11% of 95

function getWinners called 16 returned 100% blocks executed 100%
Statement coverage: 100%
Branch coverage: 100%

unittest3 was implemented to test if the getWinners function returns the correct players array in different scenarios. The test function looks at different player arrays produced when varying the number of players, whoseTurn, which player wins and if there is a tie between 2 players.

Here I achieved 100% statement and branch coverage while using much fewer tests as perform in unittest1 and unittest2. There were not too many boundary tests available for this function but I did test many important conditions including ties and altering whoseTurn. I did not uncover any bugs with this function.

Although I did not uncover any bugs I think this test function provides good coverage for the getWinners() function. Perhaps a more exhaustive test using different scenarios would increase its effectiveness.

********************************************************************************
unittest4: gainCard() function

Lines executed:2.59% of 579
Branches executed:1.44% of 417
Taken at least once:1.44% of 417
Calls executed:1.05% of 95

function gainCard called 108 returned 100% blocks executed 100%
Statement coverage: 100%
Branch coverage: 100%

unittest4 was implemented to test if gainCard() performs correctly. gainCard() should add a card to the player's appropriate deck (based on flag) and remove the card from the supply pile. The test function was implemented to iterate over every card type and iterate over every flag and check if the card was added to the appropriate pile. In addition the test function checks for failure of the function if there are no more cards in the supply pile.

 Here I again achieved 100% statement and branch coverage. I used an exhaustive approach by iterating over every possible condition and checking for the correct addition of the card. I also tested boundary coverage by setting the supply count to either 1 or 0. No bugs were uncovered with these tests however I feel more confident than unittest3 about the result.

 I feel this test function was implemented very well and provided good statement, branch and boundary coverage. Although I did not uncover any bugs I am pleased with the implementation and can not think of ways to improve.

********************************************************************************
cardtest1: Adventurer Card
Lines executed:5.53% of 579
Branches executed:8.87% of 417
Taken at least once:3.12% of 417
Calls executed:3.16% of 95

function adventurerEffect called 13 returned 100% blocks executed 79%

cardtest1 was implemented to test if the adventurer card performs correctly. The adventurer card is supposed to draw cards from the deck until the player receives 2 treasure cards. My test function first sets all cards in the player's decks to a treasure card. Since all cards are treasure cards I could easily test if the function worked by looking at the last 2 cards in the player's hand and checking the deckCount. Next the function adds 2 non-treasure cards to the top of the deck and checks if 4 cards are removed from the deck. In addition a test was performed where there were less than 2 treasure cards in the deck but this caused a segmentation fault therefore the code was commented out.

Here I achieved poor branch and statement coverage however this is most likely do to a bug in the code (that I introduced from Assignment 2). The code (shown below) never runs the code when a non treasure card is drawn. I did implement a test to check this but the bug is likely causing it not to run. Perhaps when this bug is fixed I can acheive 100% branch and statement coverage with my test function. Although I received poor coverage, I was able to detect 2 bugs. First, according to the tests, handCount is not being calculated correctly and the treasure cards are not being added to the player's hand. I also implemented a boundary test to check what happens when there are less than 2 cards in the deck. When I did this the program crashed with a segmentation fault. It looks like the function does not handle this condition.

Despite the low test coverage, I feel this test function was implemented very well and uncovered multiple errors including one that causes the program to crash. I think once the bugs are fixed I will achieve 100% branch and statement coverage. The test function could improve by writing conditions that would force call the unread code even in the presence of the bug.

Code coverage for adventurer card:

52: 1199:  while(drawntreasure<2){
26: 1200:    if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
#####: 1201:      shuffle(currentPlayer, state);
 -: 1202:    }
26: 1203:    drawCard(currentPlayer, state);
26: 1204:    cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]--];//top card of hand is most recently drawn card.
52: 1205:    if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
26: 1206:      drawntreasure++;
 -: 1207:    else{
#####: 1208:      temphand[z]=cardDrawn;
#####: 1209:      state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
#####: 1210:      z++;
 -: 1211:    }
 -: 1212:  }
26: 1213:  while(z-1>=0){
#####: 1214:    state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
#####: 1215:    z=z-1;
 -: 1216:  }

********************************************************************************

cardtest2: Smithy Card

Lines executed:4.66% of 579
Branches executed:7.43% of 417
Taken at least once:1.68% of 417
Calls executed:3.16% of 95

function smithyEffect called 108 returned 100% blocks executed 67%

cardtest2 was implemented to test if the smithy card performs correctly. The smithy card simply adds 3 cards to the player's hand and discards the smithy card from the hand. The test function iterates over different card types and players and looks at handCount, deckCount and discardCount for correctness.

Unfortunately I again achieved low branch and statement coverage. When looking at the code (shown below) it looks like the drawCard function in the loop is not being called. Since this loop should run no matter what, the problem is with the loop implementlmentation. It is clear the bug is in the for loop and the conditional statement is wrong (another bug introduced for Assignment 2). As a result it is impossible to achieve complete coverage until the bug is fixed.

Again, even though there is low test coverage, I think my test function works fairly well. The low coverage is a result of smithy being a small function and a bug making it impossible to run a line of code.

Code coverage for smithy card:

108: 1226:  for (i = 0; i > 3; i++)
  -: 1227:  {
#####: 1228:    drawCard(currentPlayer, state);
  -: 1229:  }

********************************************************************************

cardtest3: Council Room Card

Lines executed:7.08% of 579
Branches executed:8.87% of 417
Taken at least once:3.12% of 417
Calls executed:5.26% of 95

function council_roomEffect called 108 returned 100% blocks executed 100%
Statement coverage: 100%
Branch coverage: 100%

cardtest3 was implemented to test if the council room card performs correctly. The council room will allow the player to draw 4 cards, increase buys by 1 and allow all other players to draw 1 card. The test function was designed to iterate over players and card types and test the discardCount, handCount and deckCount in both the player and other players. The function also tests if the council room card is removed from the player's hand.

Here I achieved 100% statement and branch coverage. I again took an exhaustive approach and iterated over card types and players. With this test I was able to uncover a bug (again another bug I introduced for Assignment 2). The tests revealed the player would draw too many cards and the other players did not draw any. The bug is an error with the drawCard function call.

Overall I think the test function performs good coverage but I realized I did not perform any check on the number of buys. For future tests I would implement a test to make sure the function increments the number of buys.

********************************************************************************

cardtest4: Treasure Map Card

Lines executed:7.25% of 579
Branches executed:10.31% of 417
Taken at least once:4.56% of 417
Calls executed:5.26% of 95

part of switch statement
Statement coverage: 100%
Branch coverage: 100%

cardtest4 was implemented to test if the treasure map card performs correctly. The treasure map card checks if the player has another treasure card in their hand. If so, both cards are trashed and the player receives 4 gold cards. My test function tests if the function returns the correct values when 1 or 2 treasure cards are present in the player's hand. The function also tests if 4 gold cards are added to the player's deck and if both treasure map cards are trashed. Finally it checks what happens when the gold card stack is less than 4.

Here I achieved 100% statement and branch coverage. In addition, I checked boundary cases where there is only 1 treasure card or 2 treasure cards. I also tested the boundary case where there is a supply of 4 gold cards and when the supply is less than 4. I also did an exhaustive approach where I iterated over various card positions in the hand. Most tests passed with the exception of if both treasure cards get trashed. In certain card positions only 1 treasure map card gets trashed.

I think this function was implemented very well and uncovered a sneaky bug. Perhaps for completeness I would implement tests for when there are more than 2 treasure cards in the player's hand.

*/
