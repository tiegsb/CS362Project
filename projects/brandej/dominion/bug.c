unittest1:
    gameOver() never checks the index of treasure_map to check if it is at 0.
    This means sometimes when a game is over, it might not register.

unittest2:
    discardCard() no bugs found.

unittest3:
    scoreFor() contains a bug. The gardens card causes errors due to passing
    0 to numHandsCards for the card argument and therefore not actually
    counting all cards.

unittest4:
    Since getWinners() uses scoreFor(), it would technically have the same issue listed above.
    My tests navigated around this to test the rest of the funnctionality and no
    bugs were found.



