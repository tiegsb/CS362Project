/***************************************************************************************************
Development of the adventurer card random tester:
I tested for the same things as I did in my unit tests but used random values for deckCount
and player. I did have discardCount and handCount random but this lessened my coverage so
I decided to leave these inputs static.

I created a checkAdventurerCard function which copies the game state so the game state can
be evaluated before and after the adventurer card is used. Since the adventurer card requires
drawing cards it must have cards in its deck, if this count is 0 or less the discard pile
must be shuffled back into the deck. I tested for when the deckCount after the adventurer
card is used must be greater than the pre adventurer card game state deckCount, if the pre 
deckCount is less than or equal to zero. This tested to make sure the discard pile was 
shuffled back into the deck. I allowed my deckCount be negative also to test edge cases.
To avoid a false negative I implemented an else if statement in this check to account for 
when the pre game state deck count is greater than zero.

The next thing I test for is to see if two treasure cards were drawn. I look into the player's hand
and look at the last two cards put in there and if they are copper, silver, or gold I increment
the drawnTreasure count. If the drawnTresure count is not equal to 2 then the player did not
receive the right amount of treasure cards from using the adventurer card.

The next test checks to see if two cards are actually put into the player's hand. This checks
the handCount of the post game state and the pre game state and looks to see if the
handCount is greater in the post game state by 1 or 2. I use two values to avoid a false negative 
in case the adventurer card in the player's hand is discarded.

If a test fails I increment a counter that keeps track of the total number of failures. Instead
of outputting thousands of passes I check to see if the amount of failures coming into the 
checkAdventureCard function is less than the total amount of failures after the three tests to
output only the failure messages and the values of the pre and post game state deckCount
discardCount and handCount for a better idea of what is going on. 


Improvement in coverage:
With 10,000 iterations therefore 30,000 tests. There were 967 out of 30,000 failures.
Lines executed: 21.24% of 577 in dominion.c

This resulted in an increase of coverage by 1% compared to the unit test suite.

Random Test Coverage:
Lines executed:100.00% of 54
Branches executed:88.24% of 34
Taken at least once:76.47% of 34
Calls executed:100.00% of 15

This random test increases 
line coverage by 19.30%
branch coverage by 19.01%
Taken at least once by %34.16%
Calls by 33.33%
compared to the unit test suite.

Even though the amount of lines and branches vary in number between the random and unit tests suites.
The random tester clearly covers much more cases and is a better representation of what could 
happen during a real game.


Correctness:
I checked for correctness for my tests by looking at the adventurer_card function.
Doing so I could see that the deckCount must be less than 0 in order for a shuffle to occur.
Therefore I tested for negative values too because I believe the deckCount must be shuffled if the
deckCount is less than or equal to 0. Also in the first while loop the card drawn is checked to
see if it is a coin type, if so the user has drawn a treasure. This is why I check to see if 
two treasure cards are drawn and are in the player's hand. Checking that only two cards were
added to the player's hand also ensures that the temphand array is indeed discarded not added
to the user's hand.
****************************************************************************************************/

/****************************************************************************************************
Development of steward card random tester:
I also tested for the same criteria as in my unit test suite for the steward card. This random tester
also makes a copy of the game state to have a pre game state and a post game state for after the steward
card function is called inside checkStewardCard(). The steward card's action all depends on the option
value of choice 1 is. Therefore in the checkStewardCard function I use and if, else if , else statement
to check whether choice 1 is 1, 2, or some other value.

If choice 1 equals 1 then the user draws two cards and they are added to the player's hand. Therefore
I test to see if the post game state player's hand has 1 or 2 more cards in it, counting for if the 
steward card is discarded from the players hand. If choice 1 equals 2 then the user games 2 coins to
their coin count. Therefore I just check whether the post game state has two more coins than the pre
game state. If choice 1 is not 1 or 2 then the user discards two cards from their hand. To check for this
I compare handCount again but instead of an increased handCount is should be decreased by 2 or 3, counting
for when the steward card is also discarded from the player's hand.

I output the failures only like I did with the randomtestadventurer.c random test and output the number
of failed tests out of the total number of tests ran.

In the main function I use random values for deckCount, discardCount, and handCount. And for each test
iteration I loop through three possible choice for choice 1, values 1, 2 and 3 that way all possible
choices are ran for each game.


Improvement in coverage:
With 5,000 iterations therefore 15,000 tests. There were 15,000 out of 15,000 failures.
Lines executed: 22.36% of 577 in dominion.c

100% failure was to be expected due to the bugs introduced in the second assignment.
This random test resulted in an increase of coverage by 2.92% compared to the unit test suite.

Random Test Coverage:
Lines executed:100.00% of 50
Branches executed:100.00% of 26
Taken at least once:76.92% of 26
Calls executed:100.00% of 17

This random test increases
line coverage by 10.17%
branch coverage by 0%
Taken at least once by %5.49%
Calls by 25.00%
compared to the unit test suite.

Even though the amount of lines and branches vary in number between the random and unit tests suites.
The random tester clearly covers much more cases and is a better representation of what could 
happen during a real game and the random tester uses much more of the dominion code compared to the unit tests.


Correctness:
I had to go and look back to the refactor.txt document to look at the bugs I added in the second assignment
to get an accurate representation of what the card is suppose to do. I also double checked by playing the 
game to see what the description of the card in game says the what the card is to do. After checking these
two sources I went to the source code and looked for anything else I needed to test for and to verify
constraints.

*****************************************************************************************************/





















































