Brian Lamere
CS 362_400
FA_15
24 OCT 15

BUGS FOUND

For the four functions that I tested, updateCoins(), buyCard(), shuffle(), and gainCard(), I could not find any bugs. Based on my findings in coverage1.c, there are a few situations that I think did not get fully covered in my unit test functions, but even had I had the time to go back and cover those few situations, I do not expect that I would have found any bugs, as they are fairly simple functions that perform straight-forward, well-defined actions.

Yet for the cards that I tested--smithy, village, council_room, adventurer--I was able to find bugs in every one. The most prominent being the fact that, in every case, the tested card could be played, even if it wasn't in the hand of the person playing it. I think probably this stems from the fact that, during a game, a card is only ever "played" via the playCard() function, which itself calls the original cardEffect() function, based on the card that is chosen to be played. And because playCard() receives the card it's going to play based on the position of the card in the player's hand, it doesn't really need to assert that that card is what it is. But by extracting the card-playing code from the cardEffect() function and divorcing its testing from the actual playCard() function, we've created a state where it can be called without the card ever being present in the player's hand.

One other thing I want to note here is that, because I have absolutely no experience designing and composing unit tests, I don't feel as if I really got into the groove of writing these until probably the 3rd card, which was basically the next-to-last one I wrote. That being said, another bug that seems to appear in every function is the improper discarding of the played card. For 2 of these cards--smithy and council_room--I would expect this bug to appear, because I introduced it when refactoring the code, but for the other 2--adventurer & village--I didn't expect it. 

The other bugs, per card:

* smithy: 3 cards were not added to player's hand. This one doesn't make sense, because the refactored function calls drawCard() 3 times, but each time I ran it, only 2 cards were added to the player's hand.

* village: no additional bugs found beyond the 2 mentioned above. (which is curious, because the bug I introduced--drawing 2 cards instead of 1--is not caught).

* council_room: the player is given 3 cards, when he's supposed to be given 4, per the function. The function even calls drawCard() 4 times. (Again, curious that of the 3 cards tested so far, each report 1 card less than what was supposed to be drawn: not sure if this is legitimate bug, or my poor unit-test-writing skills).

* adventurer: Other than the 2 bugs mentioned above, no other bugs are found for this card, which means that my subtle bug is never caught. This is because the deck I am drawing from is not unique enough (this could be solved with randomized deck generation). To catch the bug either a silver or a smithy card would have to be drawn from the player's deck.
