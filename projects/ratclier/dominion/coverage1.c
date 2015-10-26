10/25/2015:

Coverage for unit tests (Assignment 3)
--------------------------------------

unittest1: discardCard()

Lines executed:84.62% of 13
Branches executed:100.00% of 6
Taken at least once:66.67% of 6
No calls

Statement coverage:
-------------------

Seems to be decent, although lines that decremenet handCount[currentPlayer] 
are not executed. Will have to look into why that is, as no test failures occurred
as the result of this value not decrementing.

Branch coverage:
----------------

100% coverage was achieved, but I did not test for last card in hand or only one
card in hand. Will need to do that in future testing.

Boundary coverage:
------------------

I think boundary coverage is decent. The discardCard() function operates differently
when a card is flagged as trashed, and that's covered in the unit test. It doesn't
get much more complicated than that.


unittest2: gainCard()

Lines executed:61.54% of 13
Branches executed:66.67% of 6
Taken at least once:50.00% of 6
Calls executed:100.00% of 1

Statement coverage:
-------------------

I did not test for toFlag = 2 (add to hand) so it is understandable why statements
involving that action were not executed. I will need to add tests for that in future
iterations of the unit testing.

Branch coverage:
----------------

As with the statement coverage, I did not test for toFlag = 2 so the branches that
address that action will need to be coverd in future unit tests.

Boundary coverage:
------------------

The two primary conditions for not gaining a card are insufficient supply of cards 
and a card not being used in a game. Both are tested in this unit test.


unittest3: updateCoins()

Lines executed:81.82% of 11
Branches executed:100.00% of 8
Taken at least once:75.00% of 8
No calls

Statement coverage:
-------------------

The game state added only coppers to player 0 so statements that add silvers
and golds are not executed. It may be necessary to add tests for those in the
future, although only for completeness (action is no different for silvers and
golds than it is for coppers).

Branch coverage:
----------------

Branch coverage is 100%, and considering that the branches not covered were for
coin values listed above, covering the remaining percentage should be fairly
easy in future unit tests.

Boundary coverage:
------------------

The updateCoins() function is quite simple and does not have extreme conditions
for testing. Coins are set to 0 and then added based on what's in the player's
hand. I think boundary coverage is fine as is.


unittest4: isGameOver()

Lines executed:80.00% of 10
Branches executed:100.00% of 8
Taken at least once:75.00% of 8
No calls

Statement coverage:
-------------------

Other than the lines that are not reached when the function exits and returns
1, statements seem to be covered. I think we're in good shape here.

Branch coverage:
----------------

100% coverage, and although 75% of 8 branches are taken, it seems clear that
I am still covering all bases (I test for both exit conditions, and each one
can prematurely break out of the function by returning 1 so there are going to
be legitimate situations where branches are not reached). I am not sure what I
can add to testing to raise that 75%, and I'm not sure that it's even necessary.

Boundary coverage:
------------------

Both situations that can end a game are tested: all provinces gone, or at least
3 empty supply piles. I think boundaries are covered.


cardtest1: smithyCard()

Lines executed:100.00% of 6
Branches executed:100.00% of 2
Taken at least once:100.00% of 2
Calls executed:100.00% of 3

Statement coverage:
-------------------

Every statement executes.

Branch coverage:
----------------

100% coverage, 100% branches.

Boundary coverage:
------------------

Every boundary is covered. I don't see what I can do to add to the testing.


cardtest2: adventurerCard()

Lines executed:100.00% of 18
Branches executed:100.00% of 12
Taken at least once:83.33% of 12
Calls executed:100.00% of 3

Statement coverage:
-------------------

Every statement executes at least once. I think we're good here.

Branch coverage:
----------------

100% branch coverage. I need better coverage for treasure card testing. That
should level out testing of the branches.

Boundary coverage:
------------------

I am not sure what boundary needs to be checked here. If the player's hand is
empty, the discard pile is shuffled and supplies more cards. And it seems 
impossible to not have any treasure cards, so testing for that seems pointless.
I am open to suggestions, but I think boundaries are fairly well covered.


cardtest3: treasureMapCard()

Lines executed:92.86% of 14
Branches executed:100.00% of 10
Taken at least once:70.00% of 10
Calls executed:100.00% of 4

Statement coverage:
-------------------

My testing failed to identify a second treasure map card when more than one
exists in a hand, and this prevented me from being able to test for legitimate
handling of two discarded treasure map cards (which is the only action people
care about with treasure map cards because it gives the player 4 gold cards).
I think this has something to do with the statement coverage being off.

Branch coverage:
----------------

100% branch coverage, but as with the statement coverage above, the inability
to identify a second treasure map card has something to do with the lack of
taken branches. Future unit tests will have to address this.

Boundary coverage:
------------------

This card is fairly simple in operation: either you have one and discard it and
get nothing in return or you have two and discard both and get 4 gold cards. 
Both are tested already.


cardtest4: feastCard()

Lines executed:94.12% of 17
Branches executed:100.00% of 10
Taken at least once:80.00% of 10
Calls executed:83.33% of 6

Statement coverage:
-------------------

The only statement that was not executed but was reachable was a DEBUG 
statement. Other code wasn't reached because branches that lead to the code
weren't taken. Overall, I think we're in pretty good shape statement-wise
but it would be good to work in a test to follow the untaken branches so
those statements can be tested.

Branch coverage:
----------------

100% coverage, but I need to add tests for lack of funds for gaining cards
as well as tests for insufficient supply of cards in order to take the 
untaken branches.

Boundary coverage:
------------------

I don't currently test for cards that are < 6 coins in value. That may be a 
thing to test for in the next round.


