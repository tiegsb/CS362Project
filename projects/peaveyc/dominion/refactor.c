Changes:
Adventurer: During the discard of the temp hand, instead of the temp hand being discarded, the current player hand will be discarded.
Smithy: The discardCard function now has the trash flag set, so the smithy will be trashed instead of going into the discard pile.
Council Room: The for loop that controls other players drawing a card now has only the current player drawing an additional card. Also the discardCard function now has the trash flag set, so the council room will be trashed instead of going into the discard pile.
Feast: During the backup for loop, the current hand is set to 0 instead of -1 (which represents an inactive card).
Village: The discardCard function now has the trash flag set, so the feast will be trashed instead of going into the discard pile. The function of the village was also changed, so now the player draws two cards and gains only one action.
