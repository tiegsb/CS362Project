**for any test case, if expected == actual, the test was passed, if not it failed**
------------------------------------------------------------------------------------------------------------------------
 BUG         FILE                 FUNCTION                     DESCRIPTION   
------------------------------------------------------------------------------------------------------------------------      
    1          unittest2.c            scoreFor                Third for loop is set to iterate for discardCount
                                                                             it should be iterating for deckCount.
                                                                            
 preconditions: set deck to 6 cards, and set discard and hand counts equal to zero

-------------------------------------------------------------------------------------------------------------------------
    2           unittest2.c          scoreFor                   Test 2 is returning 12 when it should be returning
                                                                             10 for the score when only the discard pile is counted.
                                                                             Cannot see source of additional two points from this
                                                                             function.

preconditions: set discard to 6 cards, and set deck and hand counts equal to zero
-------------------------------------------------------------------------------------------------------------------------
   3             cardtest3.c     play_cutpurse                   In original dominion code (unaltered) the copper
                                                                               the copper enum might not work and might be a bug.
                                                                               **I edited the dominion.c function I created for assignment 2
                                                                              to use the numeric representation of the card (5) so that I
                                                                              could at least run one test. The test did show the bug
                                                                              I introduced, in that no coppers were found in the played 
                                                                              pile                                          
                                                                               
 preconditions: set all cards in player's hands to copper, set all other cards to silver
 counted coppers in each players played pile to see if coppers were removed
 -------------------------------------------------------------------------------------------------------------------------
   4            cardtest4.c    play_treasure_map            Test 1a on 4 players, gold cards are not
                                                                                 found in top 4 positions of deck when gained
                                                                                 suggests potential bug in gainCard function
                                                                                 
preconditions: hand at 0, and at 4 are set to treasure cards. No golds in deck
before function call.

 -------------------------------------------------------------------------------------------------------------------------
   5          unittest1.c      gainCard                         Test 2b  card returns 0 for illegal positive card
                                                                                 values. Logic in function checks if supply count
                                                                                 for the card is < 1, but garbage stored in that
                                                                                 location in memory is probably resulting in a false
                                                                                 positive.
                                                                                                              
preconditions: called function with card 1000.
 -------------------------------------------------------------------------------------------------------------------------
   6            cardtest1.c    play_smithy                       Smithy adds 2 cards to the player's hand isntead
                                                                              of 3
                                                         
                                                          
preconditions: called function with smithy card at position 0.
 -------------------------------------------------------------------------------------------------------------------------
   7            unittest3.c     endTurn                      Test 4 shows that played cards to do not make it back
                                                                           to the discard pile when endTurn is called, endTurn
                                                                           also does not check for the cleanup phase
                                                         
                                                          
preconditions: added Smithy card to played cards pile, then call end turn
 -------------------------------------------------------------------------------------------------------------------------
   8            cardtest2.c    play_adventurer                     adventurer card only adds 1 treasure card                                                                                   
                                                         
                                                          
preconditions: called function with adventurer card in p0 hand
 -------------------------------------------------------------------------------------------------------------------------
   9            cardtest4.c    play_treasure_map         Test 2 with 2 players only one treasure map card
                                                                            was discarded 
                                                                                 
preconditions: hand at 1, and at 3 are set to treasure cards. No golds in deck
before function call.
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                         BUGS DISCOVERED VIA RANDOM TESTS
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
 BUG            FILE                     FUNCTION                     DESCRIPTION   
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
  10      randomtestadventurer.c   play_adventurer           Discarded cards are not seen in player's discard pile. 
                                                                                                   Upon further inspection of the code, I realized that
                                                                                                   discardCount was not being incremented when the kingdom
                                                                                                   cards were discarded after the treasure cards were found                                                                            
Test Reproduction Conditions:
time seed: 1446752647
init seed: 48
numPlayers: 2
Player who played adventurer card: 0
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
11        randomTestCard.c              play_mine               The mine card function is allowing the player to draw a card
                                                                                                that is not a treasure from supply.

        TEST 413
Trash card (choice 1) is VALID
Gain card (choice 2) is INVALID
Expected: -1 Actual: 0
        FAILED

 Test Reproduction Conditions
 time seed: 1446857902
 init seed: 6040
 numPlayers: 3
 Player who played mine card: 2
 Card from Hand to Trash: 4
 Card from Supply to Gain: 8



