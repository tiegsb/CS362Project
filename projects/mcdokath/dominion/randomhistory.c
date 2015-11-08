/* Name: Kathryn McDonald
 * Class: CS 362
 * File name: randomhistory.c
 * Purpose: Code coverage information for randomtestcard.c and randomtestadventurer.c */

randomtestcard.c:
  Coverage:
    Lines executed: 14.18% of 564
    Branches executed: 14.63% of 417
    Taken at least once: 6.71% of 417
    Calls executed: 10.53% of 95
  
    All lines and branches in dominion.c relating to the village card were executed.
    The random tester was successful 100 times out of 100 tests.
    The random test for the adventurer card executed more lines than the card test.  The card test only executed about 10.64%,
    while the random test executed 14.18%. This is mainly because I broadened the scope of the random test.
    I used the playCard() function to play the village card, whereas when I was strictly focusing on the villageEffect() function
    in the unit test, I did not call the playCard() function to play the village card.
    
    To construct the random test for the village card, I used my code for the card test with additional randomization.
    For example, the number of players is generated randomly, and then the player being tested is also generated randomly.
    That player is given a hand of randomly chosen cards, with the village randomly being inserted into a position in the hand.
    From this point, the village card is played using the playCard() function, and the game state is tested for consistency.
    If any errors are encountered, the random tester prints the type of error encountered (which part of the game state it was in),
    as well as the number of players and the tested player.
    
randomtestadventurer.c:
  Coverage:
    Lines executed: 14.01% of 564
    Branches executed: 16.07 % of 417
    Taken at least once: 7.91% of 417
    Calls executed: 9.47% of 95

   The adventurer test still fails to cover the case where the deck is empty.
   The random tester failed 100 times out of 100 tests because I introduced a bug into the adventurer card as part of a previous assignment.
   The random test for the adventurer card executed more lines than the card test.  The card test only executed about 7.80%,
   while the random test executed 14.01%. This is mainly because I broadened the scope of the random test.
   I used the playCard() function to play the adventurer card, whereas when I was strictly focusing on the adventurerEffect() function
   in the unit test, I did not call the playCard() function to play the adventurer card.
   
   To construct the random test for the adventurer card, I used my code for the card test with additional randomization.
   For example, the number of players is generated randomly, and then the player being tested is also generated randomly.
   That player is given a hand of randomly chosen cards, with the adventurer randomly being inserted into a position in the hand.
   From this point, the adventurer card is played using the playCard() function, and the game state is tested for consistency.
   If any errors are encountered, the random tester prints the type of error encountered (which part of the game state it was in),
   as well as the number of players and the tested player.