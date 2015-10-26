//Keenan Bishop
//coverage.c
//
//
/*

Coverage notes

Unit Tests

1. updateCoins

This test loops through all hand sizes from 1-5 of 2 players, with a bonus up to 10.  
It uses 3 arrays copper, silver, and gold, all of size MAX_HAND and increments through them all.
This will touch every statement in the function.

2. isGameOver()

This test tests the two loss conditions of any 3 piles being depleted, or the province being depleted.

It tests for province != 0, and provice = 0, which covers the first if statement.

The for loop is tested by depleting a stack one at a time.  The first 2 empty stacks cause j to be 1 and 2, and this returns 0.
At 3 stacks (or above) depleted, j >=3, which covers the if statement before the for loop.

3. scoreFor()

My test puts one of each type of card in the hand, discard and deck.  This makes sure all statements are touched.  
It doesn't test it for every possible position, but that would be extremely long, and out of the scope of this assignment.
I also test a larger array to trigger the garden card's effect of adding 1 per 10 cards in deck.

4. getCost()

This one was quite easy to test completely.  I made if statements for every case, and one for a case which does not appear.
This touches every statement.


Card tests

1. Smithy

For this test, I made up a hand for two players, and played the card.

I checked the effect of each line in smithyCard by checking the hand, deck, and discard count after the card was called.
I also checked the second players cards, which shouldn't be affected.


2. Adventurer

I did this much the same as smithy, but with a couple more tests.  This card has a loop through the deck, where it stops after 2 treasure cards have been found.  This requires a bit more testing, as the effects are harder to read.


3. great hall

I tested great_hall just like smithy, but with the addition of action counts.

4. village

I tested village just like smithy, but with the addition of action counts.


*/
