/*
 * In writing the random test files, the most difficult thing was creating a
 * valid initialized gameState. I tried to accomplish this via a function to
 * populate the deck of each player with random cards from the kingdomCards
 * array. This generally worked very well.
 *
 * Adventurer card test: I accomplished over 20% coverage with just this
 * function, which was relatively gratifying, given that it's relatively
 * limited in scope. Two main problems were not being able to use the rngs
 * library automatically; it always prompts for a seed. I tried various routes
 * to correct this, but couldn't seem to get around it. To minimize confusion,
 * I echoed the prompt in the makefile so that the user can enter it. The
 * second problem is a memory management error that I was not able to find.
 * ./randomtestadventurer typically segfaults between iterations 10 and 30,
 * with occasional occurrences outside that range. In further testing, my
 * primary goal would be to fix this leak, as it seriously limits the power of
 * the function.
 *
 * I did catch my introduced bug in adventurer, as it caused an immediate
 * segfault in my first rounds of testing. I had to change the adventurerCard()
 * function in order to show further random test functionality, but it was
 * caught.
 *
 *
 * Feast card test: I got to 22% line coverage with this function, which I
 * thought was relatively successful. My branch coverage was 26.6%, indicating
 * at least a moderately successful test function. Randomly choosing a card to
 * be purchased was a successful route here, and did show some errors in the
 * function implementation, because it was unable to return successfully.
 *
 * I had to quiet the print statements in the feast card function, because with
 * random testing most statements would typically be "This card is too
 * expensive!"
