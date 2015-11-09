/*

Development:
In developing the random testers for the two cards - adventurer
and smity - I first looked at the card effects the card had
and what properties changed in the game. These are the game state 
properties that gets updated upon plaing the card.

For Adventurer, we know that upon playing it we can gain
up to +2 treasure cards from the deck (+ discard pile if
shuffled), and we also know that we will lose 1 card 
from our hand (the adventurer card)

For the Smithy card, we know upon playing it we can gain
+3 card from the deck to our hand. 

Therefore I designed the random testers by randomizing the
number of cards in a player hand, the cards in the hand,
and/or the cards in the deck and discard pile. Since both of
these cards are do pretty much the same thing (get cards 
from deck), it was easy enough to design a template that worked
for both.

In comparing the coverages from this week to previous week's 
assignment, we notice that this week's coverage from the 
random testing are higher. Specifically, the branches execution
are significantly higher - this is due to the fact that in randomizing
I was able to throw a large set of data that some of which
were able to trigger the fail test cases. These did not
happen in the previous assignment due to how controlled it was.


Smith
-----------------
    [10/25/2015]
    File 'dominion.c'
    Lines executed: 29.10% of 598
    Branches executed: 29.83% of 419
    Taken at least once: 22.67% of 419
    Calls Executed: 20.00% of 95

    Statement Coverage: 93.62% of 94

    Branch Coverage:
    Lines executed: 93.62% of 94
    Branches executed: 100% of 40
    Taken at least once: 90.00% of 40
    Calls executed: 84.00% of 17




adventurer
----------------
    [10/25/2015]
    File 'dominion.c'
    Lines executed: 29.10% of 598
    Branches executed: 29.83% of 419
    Taken at least once: 22.67% of 419
    Calls Executed: 20.00% of 95

    Statement Coverage: 94.78% of 115

    Branch Coverage:
    Lines executed: 94.78% of 115
    Branches executed: 100% of 58
    Taken at least once: 93.64% of 58
    Calls executed: 85.19% of 27

*/