Daniel Bonnin
CS362 Fall 2015
bonnind@oregonstate.edu
bug1.c

This file contains bug reports resulting from the testing done during 
assignment 3. The bug report format in this file is excerpted from a sample bug
report at URL: softwaretestinghelp.com/sample-bug-report/.

Name:           isGameOver() returns false when 3 card types are empty. 
File:           dominion.c
Severity:       MEDIUM (High/Medium/Low)
Priority:       MEDIUM (High/Medium/Low)
Reported Date:  10/25/2015
Reason:         The for loop counting elements == 0 in supplyCount is off by 1.
                It needs to be for (i = 0; i < treasure_map + 1; i++)
Status:         OPEN
Description:    isGameOver() returns false when 3 card types are empty.
                
                According to the game rules, Dominion ends when any 3 card
                stacks are empty. However, isGameOver is returning an incorrect
                result.
Steps to Reproduce: Initialize a struct gameState with a supplyCount array
                    having > 0 of every card. Then set supplyCount[curse], 
                    supplyCount[minion], and supplyCount[treasure_map] to 0 and 
                    call isGameOver(state) on this state.
Expected Results:   Return value should be true.

Name:           adventurerCard() identifying all drawn cards as copper 
File:           dominion.c
Severity:       MEDIUM (High/Medium/Low)
Priority:       MEDIUM (High/Medium/Low)
Reported Date:  10/25/2015
Reason:         Assignment operator should be comparison
Status:         OPEN
Description:    adventurerCard() should continue to draw cards until 2 treasure
                cards are revealed or the deck has all been checked. 

                adventurerCard() is stopping after 2 draws, regardless of card
                type. 
Steps to Reproduce: Initialize a struct gameState with a deck[0] array
                    having estate, province, gold, and duchy only.

                    Set deckCount[0] = 4,  handCount[0] = 0, and 
                    discardCount = 0.
                    Call adventurerCard(state, 0) in this gameState.

Expected Results:   The gameState should have 1 gold card in hand[0] and the 
                    other 3 cards in discard[0].

Name:           adventurerCard() does not recycle cards on empty deck
File:           dominion.c
Severity:       HIGH (High/Medium/Low)
Priority:       MEDIUM (High/Medium/Low)
Reported Date:  10/25/2015
Reason:         When deckCount == 0, adventurerCard() calls shuffle(). shuffle()
                requires that the deck be full when called. 
Status:         OPEN
Description:    adventurerCard() should place all used cards into deck before
                calling shuffle. It does not currently do this, which leads
                to an infinite loop (when assignment operator bug is not present).
Steps to Reproduce: Initialize a struct gameState in which discard[0] contains 
                    estate, silver, gold, and duchy, 
                    and discardCount == 4.

                    Call adventurerCard(state, 0) in this gameState.

Expected Results:   The gameState should have handCount[0] == 2, 
                    deckCount[0] == 1, and discardCount[0] == 1.

Name:           villageCard() increments numActions incorrectly
File:           dominion.c
Severity:       MEDIUM (High/Medium/Low)
Priority:       MEDIUM (High/Medium/Low)
Reported Date:  10/25/2015
Reason:         += operator should be = operator
Status:         OPEN
Description:    If villageCard() is called on a gameState where numActions == 2
                the postcondition will be numActions ==  6.
Steps to Reproduce: Initialize a struct gameState with numActions == 2.

                    Call villageCard() on this gameState.
Expected Results:   numActions == 4


Name:           greatHallCard() draws card from incorrect user 
File:           dominion.c
Severity:       MEDIUM (High/Medium/Low)
Priority:       MEDIUM (High/Medium/Low)
Reported Date:  10/25/2015
Reason:         Player argument to drawCard is incorrect for player > 0
Status:         OPEN
Description:    If greatHallCard() is called with currentPlayer > 0, drawCard 
                is called on player (currentPlayer - 1).
Steps to Reproduce: Initialize a struct gameState in which deck[1] contains 
                    silver, province, gold, and duchy. Set hand[1][0] = 
                    great_hall. 

                    Set correct hand, deck, discard, and playedCards
                    counts.

                    Call greatHallCard(&state, 1, 0)

                    Verify that deckCount[1] == 4 (this is the incorrect value)
Expected Results:   deckCount[1] == 3. 


Name:           smithyCard() does not draw enough cards.
File:           dominion.c
Severity:       MEDIUM (High/Medium/Low)
Priority:       MEDIUM (High/Medium/Low)
Reported Date:  10/25/2015
Reason:         drawCard() loop only iterates 2 times.
Status:         OPEN
Description:    According to Dominion rules, the Smithy card should allow
                the current player to draw 3 cards. However, when smithyCard()
                is called, the drawCard function is only called 2 times. 
Steps to Reproduce: Initialize a struct gameState with a deck[0] array
                    having estate, province, gold, and duchy only.

                    Set deckCount[0] = 4,  Set hand[0][0] = smithy, 
                    handCount[0] = 1, and discardCount = 0.
                    Call smithyCard(state, 0, 0) in this gameState.
Expected Results:   handCount[0] == 3. 
