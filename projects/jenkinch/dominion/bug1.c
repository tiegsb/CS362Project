/*
------------------------------
bug1.c
Assignment 3
jenkinch
------------------------------

unittest1: isGameOver()
    Bugs:
        When treasure_map or sea_hag cards are one of the three piles that run out of cards
        isGameOver() does not return correctly. This is because they are enumerated as 25
        and 26 in dominion.h, respectively, and the loop that counts empty piles in
        isGameOver() only goes up to i < 25, and thus never accounts for them.

unittest2: fullDeckCount()
    Bugs:
        None discovered; all test cases passed.
        
unittest3: scoreFor()
    Bugs:
        This function failed most tests. The only successful ones were when scoring each
        singular victory card contained in a players hand, when hand/deck/discard are empty,
        and when the only card is a gardens in the deck. Mixes of victory cards across hand,
        deck, and discard would not score correctly, nor would singular cards in the discard
        or deck piles. Some issues with that function that may be causing this: the deck 
        scoring loop counts up to discardCount rather than deckCount, and gardens are 
        incorrectly scored because fullDeckCount is only summing up the cards enumerated 
        as 0 (curse).
        
unittest4: shuffle()
    Bugs:
        None discovered; all test cases passed.
        
cardtest1: cardEffect(smithy)
    Bugs:
        The card failed to correctly update handCount, discardCount, and deckCount after
        being activated. This uncovers the bugs I introduced in the earlier assignment.
        An additional i++ was added within the drawCard loop causing draws to be skipped,
        and the call to discardCard had its currentPlayer and handPos arguments switched
        causing erroneous discards.
        
cardtest2: cardEffect(adventurer)
    Bugs:
        This card failed to properly update discardCount and deckCount under normal
        conditions. It also failed to correctly update the hand/discard/deck counts
        when the deck was empty and required a reshuffle. Furthermore, under this
        scenario, the other player's handCount and deckCount were affected which
        should not have happened. These failures bring to light at least two of the 
        bugs I introduced prior--having moved the z++ from the else-statement
        in the while loop to its partner if-statement, and in the first call to 
        drawCard(), having replaced the first parameter of currentPlayer with cardDrawn.
        
cardtest3: cardEffect(village)
    Bugs:
        This card failed to correctly update discardCount and numActions. These failures
        uncover the bug I introduced prior which was updating numActions with supplyCount.
        It also reveals that something is wrong with the discardCard() function.
        
cardtest4: cardEffect(great_hall)
    Bugs:
        This card failed to correctly update discardCount. This failure further reinforces
        that there is something wrong with the discardCard() function.

*/