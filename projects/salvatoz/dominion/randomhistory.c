/*
Identifying the Interface
-------------------------

To write a random tester for adventurer, I first looked at the adventurerHandler
function's input space. The only function parameter it uses is state, and 
only a subset of the fields of the state struct are used in the function's 
operation, namely:

    - whoseTurn (int),
    - deckCount[currentPlayer] (int),
    - deck[currentPlayer] (int[]),
    - discardCount[currentPlayer] (int),
    - discard[currentPlayer] (int[]),
    - handCount[currentPlayer] (int), and
    - hand[currentPlayer] (int[])

where currentPlayer is the value of state->whoseTurn.

Generating Random Inputs
------------------------
To generate useful random inputs, we must consider which inputs are interesting 
and which are not. From a scientific perspective, we consider any test as an
experiment with a hypothesis that, when proven, provides us with more 
information about the program. To be useful, the experiment's hypothesis must
be specific enough that it contributes to our theory of the program.

To frame these constraints, we need a basic operating theory of the program.
Specifically, since we are testing the program, this theory should address the 
ways in which this program will fail. Each individual test then serves as an
experiment which advances a hypothesis about an additional way that the 
program can fail. Thus, useful tests will contribute to our theory by expanding
it, rather than simply confirming what we already know (the basic theory of 
failure).

For adventurerHandler(), my theory of failure is that it will fail if its input
violates its expected preconditions. Because this is not fault-tolerant 
software, it is not expected that functions will be able to recover if the 
program state deviates from normal.

Thus, at a minimum, a good test hypothesis needs to be more specific than 
"the program will break." There are surely many inputs that would hopelessly 
break this function, but if they violate the function's preconditions, they are 
expected to break the program and thus contribute nothing to our theory.

Keeping this theory in mind, I determined that interesting inputs likely fit 
within the following constraints:

    (1) deckCount, discardCount, and handCount all accurately represent the 
        sizes of their corresponding arrays.
        
        This is an obvious precondition of adventurerHandler() and violating it
        just confirms the theory that C arrays break down without proper bounds
        checking.

    (2) 0 <= whoseTurn < numPlayers and whoseTurn refers to the player we are
        using for the test.

        This makes sense because we expect the hands, deck, and discards of all
        players other than the active player to remain the same after calling
        adventurerHandler(). If we picked one player to test with and then
        randomized whoseTurn to be another player, the results would be 
        incoherent -- the player under test should experience no changes and the
        player specified by whoseTurn would have their current hand, deck, and
        discard change, which would give us a false positive for an error.


These constraints represent my best understanding of adventurerHandler()'s
preconditions, and thus it is expected that deviating from these preconditions
is likely to result in undefined behavior.

With these constraints in place, there is still lots of room to play around. My
focus is on the contents of the player's hand, deck, and discard. Here, I've
identified several strategies I might use:
    
    (1) Generative testing: Randomize the sizes and contents of the player's
        hand, deck, and discard. A useful test oracle would be to log the
        number and position of treasure cards to determine which ones the player
        will draw. 
        Initially, I wondered how to test the case when the player has
        to shuffle in their discard pile to find two treasure cards. Because the
        discard pile must be shuffled, it is difficult to track which treasure
        cards will be drawn unless we set them all to strictly the same type.
        However, it may be possible to log the state of the player's hand, deck,
        and discard before and after, then compare them to ensure they haven't
        changed and that only two treasure cards have moved from deck/discard to
        hand.
    (2) Mutator testing:
        (a) Produce a reasonable-looking hand/deck/discard set that causes no 
            errors when run and then shuffle which cards are in which pile and
            in which order. This could use a similar test oracle to that 
            described for the generative testing approach in (1), but with the
            added benefit that we know exactly which cards the player should 
            have.
        (b) Use a prepared hand/deck/discard set, then shuffle and randomly swap
            out cards. This isn't much different from approach (1).
        (c) Null space transformation with mutator: Again start with a prepared
            hand/deck/discard set, but add only non-treasure cards to the deck.
            This can use the same oracle, but has the added benefit of checking
            specifically for bugs with non-treasure cards. Since non-treasure 
            cards should have no effect on adventurer's behavior except to cause 
            more card draw, any change in output from adventurer signifies a 
            fault.

I've selected the generative random testing approach.

Designing the Test 
------------------

Generating the player's cards:
The process of generating cards is fairly straightforward, with one small 
exeption: the distribution of treasure cards. Because adventurer allows the
player to shuffle once while searching for treasure, we want to consider a few
cases regarding treasure distribution:

    (1) At least two treasure cards in the player's deck.
    (2) One treasure card in the player's deck and at least one in the discard.
    (3) No treasure cards in the player's deck and at least two in the discard.
    (4) No treasure cards in the player's deck and one in the discard.
    (5) No treasure cards in both the player's deck and discard.

Each of these cases should happen during the course of testing to ensure that
the program can handle all cases correctly.

To account for this, the random deck generation will happen in two phases.
First, a treasure distribution will be determined. One of the five cases above
will be selected at random, and treasure cards will be allocated to the deck
and discard as required. Second, random non-treasure cards will be added to the
deck and discard, and the deck and discard will be shuffled separately.

Test oracle:
Because we know at the beginning how many treasure cards are in the player's
deck and discard, we can describe expected outcomes in terms of the cases 
outlined previously. For all cases, the following should hold:

    (1) The complete collection of cards will have the same contents. Some
        cards will move around, but there should be cards gained or lost.
    (2) The player's hand will gain up to two treasures, assuming at least two
        treasures were in their deck and discard.
    (3) The player's deck and discard will lose up to two treasures, assuming
        they contained at least two treasures to begin with.

Additionally, we can define some integrity checks to make sure that the game
state is in a coherent state by checking that the number of players, current
player, and total number of cards is equal to what it was before calling
adventurerHandler().

Test reusability:
Because we might want to rerun test cases later -- for example, to check that a
previously failing test case now passes, or for regression testing to check bugs
that we've fixed -- both of my testers have two commands: run and replay. run
takes an optional filename, to which the tester outputs its generated state.
replay takes a required filename, which should contain the generated state from 
a previous invocation of run. This allows for easy reuse of test cases as 
needed.

Correctness
-----------
Both of my testers found bugs in the cards they test. Since we are required to
have introduced bugs into the code, this makes sense.
*/