
/*

Development of random testers:

1) I created empty source code files and added rules to Makefile.

2) I identified interfaces to test. I chose the functions smithyEffect() and 
   since these are functions I have worked with in the past, they have 
   simple interfaces and, of course, because adventurerEffect() is required
   for this assignment.

3) I wrote code to generate random inputs, asking myself questions such as:
       Which values will be random?
       What is appropriate range of values to use?
       Are all of these values interesting?
   Since I am a rank amateur at testing, I stuck close to the example code
   presented in the lectures. I looked closely at the parameters these two
   functions take. I used the trick discussed in the lecture where the 
   game state is filled with random Byte values. I then assigned random 
   values to the player, the number of cards in the deck, discard pile, and
   the player's hand before calling the function to be tested and passing
   the parameters to it. Unfortunately, this wasn't sufficient to prevent
   segmentation fault errors, so I had to add a function call to the 
   initializeGame() function to set the game state more appropriately.

4) I wrote a code check behavior on the random inputs. Following the code
   examples in the lecture material, I copied the game state in the oracle
   function before calling the function to be tested. I then made changes
   to the copy of the game state that reflect changes that are to be 
   expected if the function is working correctly. Then I compared the 
   two actual game state returned from the function with the expected 
   game state I edited in the oracle to see if the function is working
   properly. In the current version of the test oracle, only the player's
   hand is tested and compared. In the case of the Smithy card, the hand
   should have three more cards after the function call or if not should 
   have added the number of cards that were left in the deck and discard
   pile combined (0, 1, or 2 cards). A similar check is made for the
   Adventurer card. In both cases, the tests reveal that these functions
   are working properly, at least as far as adding the expected number 
   of cards to the hand. To test that my oracle is working properly, I 
   changed the expected number of cards added to a different value. For
   example, I changed the Smithy card's function so that it added four 
   cards instead of three. This registered many errors, which confirms 
   that the test oracle is in fact working properly. Of course, there are
   many other interesting values that could also be tested. I was working
   against the clock, so I was limited in what I could implement. Future
   versions would check the discard pile, check that the cards in the
   hand are the same ones that were in the deck, etc.

5) The code coverage was significantly improved in this round of testing
   as compared with the last assignment. The randomtestcard achieved a
   21.25% coverage and randomtestadventure achieved a 20.38% coverage,
   compared to a coverage of 6.27% and 5.75% for cardttest1 and cardtest2
   last time.

*/