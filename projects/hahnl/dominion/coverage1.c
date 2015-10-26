/*
Author: Larissa Hahn
coverage1.c

Coverage: 25.8% of 582 lines
Branch coverage: 32.4% of 496 lines
Boundaries - Missing a lot of edge cases

I definitely could improve my coverage! My tests were meant to test
very specific effects of each card as well as the purpose or meanings of
the functions. So it was a very narrow test suite. I have yet to actually
test all of the dominion.c functions and have only made use of a few of them,
so that also brought down my coverage average. For the functions I did test,
I used reasonable data but did not test for unreasonable inputs, like negative
inputs, which could improve my coverage. Also, I simplified my tests by
creating the same gameState g versus using a lot of the other functions
to load a player's hand with data or create a new game. I also only tested
mostly for 2 player game states and not all game states could possibly
have been even close to being covered in that respect.
/*
