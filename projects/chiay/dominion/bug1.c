/*****************************************************************************
 Author: CHIA, YiXuan
 Title:  bug1.c
 Desc:   Documentation of bug found in unittest(1 - 4) and cardtest(1 - 4)
 Course: CS362 Fall 2015
*****************************************************************************/

File: unittest2.c
Desc: scoreFor() function
Bug : Calculation error for score in discard pile.Third for - loop depends on 
      discardCount[player] instead of deckCount[player].

File: cardtest2.c
Desc: cardEffect_adventurer() function
Bug : Does not call discardCard() function to discard adventurer card. Number 
      of cards on player's hand not correct.

File: cardtest3.c
Desc: cardEffect_council_room() function
Bug : Bug created and documented in refactor.c for assignment 2. Council_room 
      card not discard to discard pile, and discardCount[player] not incremented.
