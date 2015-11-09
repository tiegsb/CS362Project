/****************************************************************************
Author: Larissa Hahn
randomhistory.c

NOTE: Compile with "make" command, but there IS a wait time maybe 5-7 minutes
or so due to the bugs in the files which cause the tests to run slow. But they
will eventually complete with a great test report for the Adventurer
and Smithy Cards.
*****************************************************************************

randomtestadventurer.c -->
    // Initialize game with Adventurer Card
    // Initialize deck
    // Adventure card gets played now
    // TEST 1 - Check for proper discard (adventurer)
    // TEST 2 - Check for proper draw card (2)
    // TEST 3 - Check for proper treasure cards (2)

randomtestcard.c -->
    // Initialize game with Smithy Card
    // Initialize deck
    // Smithy Card played
    // TEST 1 - Check for proper discard (smithy)
    // TEST 2 - Check for proper draw card (3)
    // TEST 3 - Check for proper played card (1)

I simplified my tests by creating the same gameState g versus using a lot
of the other functions to load a player's hand with data or create a new game.
I also only tested mostly for 2 player game states and not all game states
could possibly have been even close to being covered in that respect.

Adventurer Card:
File 'dominion.c'
Lines executed:19.93% of 582
dominion.c:creating 'dominion.c.gcov'
Adventurer Card game state limits coverage-->

int drawntreasure = 0;
int temphand[MAX_HAND];
int z = 0;
int cardDrawn = 0;
int currentPlayer = 0;
int k[10] = {
smithy,
adventurer,
village,
great_hall,
council_room,
gardens,
feast,
mine,
embargo,
tribute
};
memset(&g, 23, sizeof(struct gameState));
newGame = initializeGame(2, k, 1000, &g);
g.whoseTurn = currentPlayer;
g.handCount[0] = 1;
g.hand[0][0] = adventurer;
g.deckCount[0] = 50;

*******************

Smithy Card:
File 'dominion.c'
Lines executed:20.45% of 582
dominion.c:creating 'dominion.c.gcov'
Smithy Card game state limits coverage -->

int handPos = 0;
int bonus = 0;
int k[10] = {
smithy,
adventurer,
village,
great_hall,
council_room,
gardens,
feast,
mine,
embargo,
tribute
};
memset(&g, 23, sizeof(struct gameState));
newGame = initializeGame(2, k, 1000, &g);
g.whoseTurn = 0;
g.handCount[0] = 1;
g.hand[0][0] = smithy;
g.deckCount[0] = 50;

I have yet to actually test all of the dominion.c functions and have only made
use of a few of them, so that also brings down my coverage, and for the functions
I tested, I used reasonable data but did not test for unreasonable inputs, like
negative inputs, which could still improve my coverage even more. See
randomtestadventurer.out and randomtestcard.out for detailed information on the
test failures.

// Smithy Card - void smithyCard ()
In the for loop, the i counter starts at 1 instead of 0,
and goes till less than or equal to 4 instead of less than 3.

// Adventurer Card - void adventurerCard ()
The first if statement to check if the deck is empty checks if the
state is less than 0 instead of the original less than 1.
drawntreasure gets decremented instead of incremented.
state->handCount[currentPlayer] gets incremented instead of decremented.

adventurerCard() does not correctly discard cards, but only a smaller
percentage of the time. Worth investigating this anomaly. However, there
is a draw card error 100% of the time. And only one test in which there
was no treasure card error, so more testing needs to be done to correct
and finally fix these bugs.

Based off the most recent tests, I observed that for some reason the
adventurer card draws 2505 cards. It is drawing way too many cards and causing
my tests to run slow. I would say that should be of my most primary concern
to address and fix this bug right away.

smithyCard() tests also fail 100% of the time, with the draw card test failing
100% of the time. However, it seems exactly one card is played each time so the
subtest of played card actually passes 100% of the time but overall each
test case is a failure as there is always a bug in every scenario tested.

Oddly enough, the discard card errors are only 29/1000 tests. Definitely a
weird anomaly that requires additional testing to uncover what the bug could
be so that in only occurs every so often. I suspect there is a bug in the
discard function that I didn't introduce, at least not intentionally, to my
knowledge.
****************************************************************************/
