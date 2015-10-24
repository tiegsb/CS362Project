1. The function updateCoins is not declared in the dominin.h header. This causes a link-time warning.
2. There was a bug in my test runner. If a test failed it would be repeated ad-infinitum.
3. The adventurer card is not discarded. There are likely other bugs lurking in
the adventurer implementation, but my tests fail early.
4. The smithy card does not draw the right number of cards.
5. The council room does not add another buy.
6. The arguments to the villagerEffect function are passed in the wrong order.
