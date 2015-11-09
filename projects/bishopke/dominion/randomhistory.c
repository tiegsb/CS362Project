//Keenan Bishop
//assignment 4 writeup
/*


Adventurer Card random test:

I seperated this card by the possible situations that differ in results.  This card gives you up to two treasures from your deck, if they exist.
I first counted the number of treasures in the player's hand/deck before the card took effect.  Depending on how many treasures the player had, I checked different effects.
If the player had at least two treasures, then the player should have gained two treasures as a result of the card.  If the player only had 1 or none at all, the effects would be different.
I set up a random set of cards each time, with a random number of players and a randomly selected player to play the card.
With enough iterations,  this random testing will touch boundaries and certainly give more varied tests in a shorter time than a full exhaustive iterative test would.
Compared to my cardtest from assignment3, this random test gets twice as much line coverage, 15% opposed to the assignment 3's 7%


Village Card random test:

This test has a setup that is very similar to the Adventurer card test.  It gets random player number, player, and player hand.  It then checks that the card effect increase the actions by two and cards by one.  Mine has a bug which makes about half the tests fail because it increases actions wrong.
This function tests 12% line coverage vs assignment 3's 5%.`



*/
