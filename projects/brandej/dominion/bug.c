unittest1:
    gameOver() never checks the index of treasure_map to check if it is at 0.
    This means sometimes when a game is over, it might not register.

unittest2:
    discardCard() no bugs found based on written functionality within this test suite.

unittest3:
    scoreFor() contains a bug. The gardens card causes errors due to passing
    0 to numHandsCards for the card argument and therefore not actually
    counting all cards.s

unittest4:
    Since getWinners() uses scoreFor(), it would technically have the same issue listed above.
    My tests navigated around this to test the rest of the funnctionality and no
    bugs were found.

cardtest1:
    Testing the Adventure card showed 3 bugs. It will place up to 3
    treasure cards in hand since the while loop is <= instead of <. The funciton will also
    return hand count of -1 if no adventure cards are found. This last one might be an error
    or just undefined behavior. In addition, the card does not discard itself after being played.

cardtest2:
    Testing smithy card showed 1 major bug with the dsicardCard funciton. That funciton does not place
    discarded cards in the discard pile or increment the discardCount.

cardtest3:
    tested the Village card. No bugs were found.

cardtest4:
    I was traveling for work the past 2 weeks and ran out of time.



