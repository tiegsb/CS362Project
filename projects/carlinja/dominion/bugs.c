James Carlin
Bugs.c
Bugs I've encountered while making my test files

I ran into a couple of bugs while writing my test files.

In shuffle(), when there are less than 3 cards in the deck, the function will not shuffle the deck. It does not shuffle the deck with 0 cards in the deck, which is the correct response from the function.

In greathallcard, the correct number of actions isn't added. The game starts with 1 action. The bug I introduced also throws this bug, but aside from that the actions are not being added correctly.

The adventure card also has a bug. THe adventure card should be adding two treasures, which would add 2 to the deck count. The card is not actually adding the two cards, so it is still at the set amount of deck count.