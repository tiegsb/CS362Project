/*Anthony Wilcox
CS362
Fall 2015*/
/*******************************************************************
Bug Report:
ID: #d001
smithy card: function play_smithy in dominion.c 
version: 
dominion.c in \cs362f15\projects\wilcoant\dominion\dominion.c as of 10-23-2015
1125AM
The bug occurs with function calls within the possible realm of the game.
That meaning that funcion calls between the min and max players and the 
min and max hand positions of the actual smithy card in the player's hand.
These mins and maxes are those defined in dominion.h 
The bug stated simply is that the player's handCount does not increment
by 3, it increments by 2.  
The severity of this is that it changes the rules of the game.  Albeit
it changes the rules of the game for both players, integration testing
is needed to determine second order effects, but it functions improperly
by updating player hand by 2 instead of 3 each time it's called.

ID: #d002
adventurer card: function play_adventurer in dominion.c 
version:
dominion.c in \cs362f15\projects\wilcoant\dominion\dominion.c as of 10-23-2015
1125AM
The bug occurs during function calls with parameters inside the expected
state of game play.  When called across the boundaries of all Max and min
values of number of players and hand values as defined in dominion.h.  In order
to test this card properly, counters were used in the function itself.  Calls
to draw card were counted along with the execution of the treasure card 
condition.  The temp array was counted as well (non treasure cards).  The sum
of treasure cards plus non treasure cards should have equaled the total number of 
calls to drawcard.  The logic of testing was set up so that this would return
0 if this occurred.  This was not the case.  Both the non treasuer cards 
and treasure cards themselves appear to be improperly accounted for.  This
will cause severe consequences to the game state as deck and discard counts and
positions will be off and cause potential one off max index out of boundary 
array indexing.  Although crash behaviour was not observed, integration testing
may yield crash behavior if this isn't resolved.

ID: #d003
aventurer card: function play_adventurer in dominion.c 
version:
dominion.c in \cs362f15\projects\wilcoant\dominion\dominion.c as of 10-23-2015
1125AM
The bug occurs during function calls with parameters inside the expected
state of game play.  When called across the boundaries of all Max and min
values of number of players and hand values as defined in dominion.h.  In order
to test this card properly, counters were used in the function itself.  Calls
to draw card were counted along with the execution of the treasure card 
condition.  The temp array was counted as well (non treasure cards). 
Discard count of current player indexed by variable z in while loop
may be affected by miscount of z or off indexing of temparray using z
variable.  This bug is related to bug d002 and may not be separate but
was documented for the sake of clarity between not treasure cards (d003)
and treasure cards (d002).

ID: #d004
council room card: function play_council in dominion.c
version:
dominion.c in \cs362f15\projects\wilcoant\dominion\dominion.c as of 10-23-2015
1125AM
The bug occurs during function calls with parameters inside the expected
state of game play.  When called across the boundaries of all Max and min
values of number of players and hand values as defined in dominion.h.

The state of game (struct gameState) member variable numBuys to represent 
the number of buys a player has per current turn should be incremented by
one upon playing this card.  It isn't.  This has the same effect for 
both players but second order effect and potential crash behavior isn't 
known until integration testing, but the bug currently invalidates the rules
and the card.

ID: #d005
drawCard: function drawCard 
dominion.c in \cs362f15\projects\wilcoant\dominion\dominion.c as of 10-23-2015
1125AM
The bug occurs when passing an empty player deckcount into drawCard function.
Code examination shows that this should trigger a card shuffle, but it does not.
It currently core dumps.  This test was conducted in order to increase coverage
for the testing done on the function itself as that branch was not being covered
at all during game execution.  Integration testing may be necessary to see if a
secondary condition may have caused the core dump.  Currently, however, this bug
should be labeled as severe since it crashes the system.

ID: #d006
adventurer: function play_adventurer 
dominion.c in \cs362f15\projects\wilcoant\dominion\dominion.c as of 10-23-2015
1125AM
The bug occurs over the unit test of adventurer in that the deck never empties 
during game state and shuffle is never called with all variations of gameState being
tested up to the boundaries defined in dominion.h  This is further indication that 
there is some potential bug existing in the discard function during game state. 
*******************************************************************/