/*

unittest1.c: updateCoins()

statement coverage: 100 %
branch coverage: 100 %, only 1% of the testing time was a particular card in the hand of the player, but this is a normal game condition. All three cards were tested
boundary coverage was no applied in this circumstance. I did not test the upper limits of gold coins because updateCoins is only for the hand the player currently has

unittest2.c: gainCard()

statement coverage: 100%
branch coverage: 100% branches were taken evenly.
boundary coverage was not applied in this case

unittest3.c: discardCard()

statement coverage: 100%
branch coverage: 100% branches were not taken evenly, but a good ratio. 80:20 for the first conditional, regarding the trash flag. 6:94 for the second, if the card is the last card in the array, 7:93 for the third,
if there is only one card in the player's hand. This coverage is acceptable.
boundary coverage: I tested this function with 6 cards as maxHand, more than the five in the normal game and it worked correctly.

unittest4.c: getCost function

statement coverage: I did not execute the function for all cards in the online game, I did test all cards that were currently in the deck. By testing 11 cards in range out of 26, I feel that this
is adequate testing.
branch coverage: This has similar results to statement coverage as it is a switch statement.
boundary coverage: I tested if a card not in the deck could be passed to this function and still get the value, it does. Noted in the bug report
I also tested if a enum value just outside of those specified to cards in the dominion.h file was passed if the function would fail. It did.
tested for 27 and 999. expected values are 0-26


boundary coverage for all cardtest functions: functions were tested when there was one card to five cards currently in player's hand and the card was played.
none of these functions check to see if the position of the card they are passed is actually the card it is supposed to be. This could lead to a bug where the
wrong card is discarded. no other boundary coverage was deemed necessary.

cardtest1.c smithy_play()
statement coverage: 100%
branch coverage: 100% branch 

cardtest2.c adventurer_play()
statement coverage:
branch coverage:

cardtest3.c village_play()
statement coverage: 100% statement coverage
branch coverage: 100% branch coverage (no conditional branches, trivial case)

cardtest4.c great_hall_play()
statement coverage: 100% statement coverage
branch coverage: 100% branch coverage

lines executed: 36.23% of 657
Branches executed: 33.81% of 420
Taken at least once: 27.86% of 420

*/