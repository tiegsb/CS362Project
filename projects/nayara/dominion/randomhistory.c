/* Ashok Nayar
* cs362, Fall 2015
* Assignment 4: Random Testing
* Write up
*/

* Random Test Development
For both the adventurer and council card, random testing was first development by making sure the relevant data was initialized correctly. 
Since I decided to forgo the use of the initialize() method as it didn’t really guarantee random data, I decided to initialize all my 
arrays and variables directly. I first made sure that the current player, deck, discard deck, hand count, and played card count was 
initialized to a random number between 0 and MAX_CARD or MAX_HAND. I also made sure that the decks had a valid card value in each card 
rather than some unreliable or incorrect data. For the adventurer, I made sure that the discard deck had only provinces in it as one of 
the tests was to verify that no coin cards were in the discard deck. The council test also had the discard deck cards initialized between 
0-6, just to make it a little cleaner to verify, if we needed to. Once the initial values were set up, I wrote a function to test for the 
following circumstances: 

For adventurer:
    - Check to see if the hand increased by two and only two
    - Check to see if any coin cards have been discarded. Coin cards should NOT be in the discard pile  
    - Check the  last two cards and make sure they are coin cards

For the council card:
    - Check if current council in hand is discarded
    - Check if number of buys is increased by 1
    - Check if current player’s hand count increases by 4
    - Check to see if other player’s hand count is increased by 1


* Coverage summary
  ** Coverage for randomtestadventurer.out: Lines executed:9.85% of 660

  ** Coverage for randomtestcard.out (council card) : Lines executed:10.15% of 660

At first glance, it appears that we have less coverage than our unit tests from the previous assignment, but this is not the case at all. 
First, in the random tests we are not using the “initialize()” function, so that means that we are not calling a significant chunk of code.
In our random testing, however, this makes little difference wince we are initializing all the variables and arrays that we need directly 
in our tests. While the percentage may appear lower, we’re actually testing portions of the code more times than we were with our direct 
unit testing. For example, my unit tests did not make extensive use of empty decks. As a result, portions of the code that ran when the 
deck was empty seldom ran, if at all. However, the random testing ensures that the decks are empty at least sometimes, thus running 
those parts of the code. In fact, in one test alone, the drawCard function ran the code for an empty deck 163, which is far more than 
our previous test. While our coverage only runs a minimal part of the dominion code outside of the functions we are testing, it still 
makes sure that the function in question is run thoroughly enough in several different situations.

* Random testing results (bugs found)

Adventurer Card
As you can see in the output, the Adventurer card failed to recognize the copper card as a coin card and was throwing it into the discard
pile. This often resulted in the hand not being increased by the correct amount of cards. 

Council Card
The bugs found in this card was that the current player's hand was increased by too many cards and the other player's hands were not 
increased at all. 


* Random test concluding summary
The hardest part about running these random tests were ensure that the correct arrays and variables had valid data in them. Several times 
the code with crash, throw an error, or behave in unpredictable ways and it was hard to tell if it was a result of the function itself 
(a valid bug) or due to a poor dataset. The drawback to this method was that setting up a random test took quite a bit of digging around 
in the code to find out what arrays and variables were needed and making sure that they were set up correctly. The trade off, however, is
 that we can easily test multiple types of situations and datasets and find any bugs. The bugs that were introduced in previous 
 assignments were caught correctly and nothing slipped by unnoticed. 
