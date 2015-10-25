/*
------------------------------
coverage1.c
Assignment 3
jenkinch
------------------------------

Comments on the individual coverage accomplishments of each function can be found below.
Overall, line coverage of the dominion.c code came to 32.76% of 577 and branch coverage
came to 41.01% of 417. Of course, many more functions need to be tested to achieve a 
robust test suite covering dominion.c. The various draw and discard functions are likely
the next best functions to write tests for as they are used so frequently, as is the initialize
function which so many of these tests rely on.

unittest1: isGameOver()
    Cumulative Coverage:
        Lines executed:17.33% of 577
        18 Branches executed:17.75% of 417
        19 Taken at least once:14.63% of 417
        20 Calls executed:7.37% of 95
        
    Statement/Branch:
        Within the isGameOver() function, I achieve 100% statement and branch coverage.
        
    Boundary Coverage and Implications:
        Boundary coverage was rather good in this function. I covered both win conditions
        and had a fairly representative array of pile mix scenarios being tested. The next
        logical improvements for this set of tests is to create a randomized loop that puts
        together different combinations of piles running out to try and find more bugs similar
        to the sea_hag/treasure_map ones.

unittest2: fullDeckCount()
    Cumulative Coverage:
        Lines executed:18.89% of 577
        36 Branches executed:20.62% of 417
        37 Taken at least once:17.75% of 417
        38 Calls executed:7.37% of 95
        
    Statement/Branch:
        Within the fullDeckCount() function, I achieve 100% statement and branch coverage.
        
    Boundary Coverage and Implications:
        Boundary coverage was rather good in that it covered a variety of deck/hand/discard mixes; 
        cards in the middle, end, and beginning of the enumeration; and covers two different players
        simultaneously to ensure to cross-player issues are occurring. It could be improved with a 
        randomized loop that counted more types of cards under various different kinds of pile mixes.
        
unittest3: scoreFor()
    Cumulative Coverage:
        Lines executed:23.05% of 577
        69 Branches executed:30.70% of 417
        70 Taken at least once:27.10% of 417
        71 Calls executed:9.47% of 95
        
    Statement/Branch:
        Within the scoreFor() function, I achieve 100% statement and almost 100% branch 
        coverage. However, three fallthrough branches never executed in the conditional
        statements responsible for scoring the deck.
        
    Boundary Coverage and Implications:
        scoreFor()'s boundary coverage is very good in that it looks at realistic mixes of piles as
        well as very specific border cases, which really pointed out a lot of bugs. It of course
        could provide even more constructive information the more specialized cases we throw at it.
        That would really allow us to pinpoint what remain somewhat ambiguous bugs.
        
unittest4: shuffle()
    Cumulative Coverage:
        Lines executed:23.40% of 577
        92 Branches executed:30.70% of 417
        93 Taken at least once:27.58% of 417
        94 Calls executed:9.47% of 95
        
    Statement/Branch:
        Within the shuffle() function, I achieve 100% statement and branch coverage.
        
    Boundary Coverage and Implications:
        This function has very good boundary coverage in that it not only verifies both player's
        various card counts, but also looks specifically confirms that the shuffle is actually
        mixing up the cards. It could be made more robust by randomizing its test such that we
        can even analyze the effectiveness of the shuffles. Also, it would be good to confirm
        that the cards in the shuffled pile are not only in a different order, but also the same 
        cards it started with.
        
cardtest1: cardEffect(smithy)
    Cumulative Coverage:
        Lines executed:28.08% of 577
        108 Branches executed:38.13% of 417
        109 Taken at least once:29.26% of 417
        110 Calls executed:13.68% of 95
        
    Statement/Branch:
        Within the smithy components of the cardEffect() function, I achieve 100% statement 
        and branch coverage.
        
    Boundary Coverage and Implications:
        The smithy boundary coverage was effective in finding the most likely causes of bugs,
        and in verifying cross-player state integrity by checking hand/deck/discard counts, but the 
        next logical enhancement would be to verify that hand/deck/discard contents match from 
        origin to destination after all transfers.
        
cardtest2: cardEffect(adventurer)
    Cumulative Coverage:
        Lines executed:31.02% of 577
        130 Branches executed:41.01% of 417
        131 Taken at least once:31.89% of 417
        132 Calls executed:16.84% of 95

    Statement/Branch:
        Within the adventurer components of the cardEffect() function, I do not achieve 100% 
        statement and branch coverage. The two statements in the else-block never fire, likely
        due to the bug that was in and around the drawCard() call. In the future it would be
        best to ensure that cards other than copper, silver, or gold are being drawn to execute
        those statements.
        
    Boundary Coverage and Implications:
        Similar to the smithy, the adventurer tests could benefit from post-transfer card checks
        to ensure no cards get changed in the process. The deck/discard/hand count tests certainly
        helped make me aware of bugs, but there needs to be more, varied trials to better pinpoint 
        them. More tests written around the empty deck scenario would also help identify bugs.
        
cardtest3: cardEffect(village)
    Cumulative Coverage:
        Lines executed:32.06% of 577
        147 Branches executed:41.01% of 417
        148 Taken at least once:32.13% of 417
        149 Calls executed:20.00% of 95        
        
    Statement/Branch:
        Within the village components of the cardEffect() function, I achieve 100% statement 
        and branch coverage.
        
    Boundary Coverage and Implications:
        The village is a rather simple function, and the tests I ran cover the boundary cases
        well enough to pinpoint the bugs at hand. Probably a randomized set of game states that
        the card could be activated on would help further tighen up this set of tests. Also,
        and this goes for several of these cards, trying to play them out of different hand 
        positions could also offer valuable insights.
        
cardtest4: cardEffect(great_hall)
    Cumulative Coverage:
        Lines executed:32.76% of 577
        164 Branches executed:41.01% of 417
        165 Taken at least once:32.37% of 417
        166 Calls executed:22.11% of 95
        
    Statement/Branch:
        Within the great_hall components of the cardEffect() function, I achieve 100% 
        statement and branch coverage.
        
    Boundary Coverage and Implications: 
        Boundary coverage on this card was very similar to the village card. In fact, having this
        case in addition to the village one helped to solidify that something is wrong with the
        discard function.
*/