/***********************************************************************
            Report of code coverage for dominion's random tests
***********************************************************************/

****************
randomtestcard.c
**************** 

This random test was testing the case of village card under cardEffect()
function. The coverage detail is as following:

File 'randomtestcard.c'
Lines executed: 96.30% of 54
Branches executed: 100.00% of 18
Taken at least once: 83.33% of 18
Calls executed: 96.77% of 31

    #####:   106:	printf("Test #%d passed random test!)\n\n", i + 1);
    #####:   107:	pass++;


File 'dominion.c'
Lines executed: 19.69% of 579
Branches executed: 22.78% of 417
Taken at least once: 14.39% of 417
Calls executed: 10.53% of 95


I didn't try to test it in the last assignment using the unit test, so
I decided to try this switch-case using random test. By testing this 
particular test, I am able to confirm that there are bugs in the discardCard()
function.


Development:
------------
The tests were occured for a random number of times. I first randomized the 
player's handCount, deckCount, and DiscardCount, even the cards that the player
hold on hand, in the deck, or discarded, but of course the player was holding
one village card and ready to play it. The tests just displayed the pre-situation
and the post-situation of the card played to check the effects. 

The tests shown that after the player played the village card, the player will
gain a new card, and get 2 bonus actions, but the discardCount for the player 
did not increment by 1. The discardCard() function did discard the village card 
from the players hand, but it did not increment the discardCount for the player.

As all the test failed due to the discardCard() function, there were 2 lines of
codes that did not run at all, which is the "pass random test" message and the 
count for passed test. Therefore, the line executed was recored 96.30%.


Correctness:
------------
What I did for the correctness was I recorded the variables that will changed after
the village card played and display it for checking. After the play, I retreived the
data again to compare both pre and post condition.
- The number of cards should stay the same, as discard and draw is performed
- The number of actions should be incremented by 2
- The discardCount should be incremented by 1
Every condition did match except the last one. This is definately the issue that
cause failure to my tests.




**********************
randomtestadventurer.c
**********************

This random test is testing the cardEffect_adventurer() function that was
refactored. The coverage detail is as following:

File 'randomtestadventurer.c'
Lines executed: 95.92% of 49
Branches executed: 100.00% of 22
Taken at least once: 95.45% of 22
Calls executed: 96.30% of 27

    #####:   101:	printf("Test #%d passed random test!)\n\n", i + 1);
    #####:   102:	pass++;


File 'dominion.c'
Lines executed: 21.59% of 579
Branches executed: 19.66% of 417
Taken at least once: 17.51% of 417
Calls executed: 10.53% of 95

Compared to my unit test regarding the adventurer card, the lines executed dropped
by 0.5%, but the lines taken at lease once rised from 83.33% to 95.45%. 


Development:
------------

The tests were also occured a random number of times. The handCount of the player is
set to 1, which the player was holding only the adventurer card. The deckCount and
discardCount were still randomized. Again the pre condition and post condition is
recorded before and after the adventurer card was played. 

The tests shown that the player did draw some card and stop until it drawn 2 treasure
cards, but the player should also discard the adventurer card before the 2 treasure 
cards can include into player's hand. The random tests failed because the adventurer
card was not discarded, and led to wrong calculation for discardCount.

Since the random test failed, the line for the "passed" message and number of pass 
count did not run. The coverage recorded 95.92% for not running that 2 lines of 
code.


Correctness:
------------
The pre and post condition were recorded to compare the data after the tests.
- The player should gain 2 treasure cards
- The number of cards should be only 2, after discard and draw 2 cards
The second condition was not fulfilled because the adventurer card was not discarded,
which cause the random tests to fail.
