I implemented the Adventurer, Smithy, Council Room, Feast, and Remodel cards. The Adventurer and Smithy cards were
chosen because of the instructions and the others were basically chosen at random. I chose to introduce bugs in the
Adventurer, Smithy, Council Room and Remodel cards.

Bugs introduced -
Adventurer:
1) z = 0 change to z = 1
2) The deck reshuffles when the number of cards is <=1 instead of <1
3) Added currentPlayer++
4) z++ moved from end of else statement to beginning of else statement so it increases
   before adding the card to the temp hand, not after.
5) Double pipes in if statement changed to single pipes and == changed to =

Smithy:
1) currentPlayer is always 0
2) trash flag changed to 1
3) i <= 3 instead of < 3

Council Room:
1) loop that draws four cars was changed to <= 4 instead of < 4
2) numBuys++ changed to numBuys--
3) switched 0 and handPos in the discardCard function call
4) introduced dummy variable z
5) replaced i with z for in the loop that allows the other players to draw an extra card

Remodel:
1) change j to i for that will hold the card to be trashed
2) switched all choice1 and choice2
3) replaced discardCard with drawCard
4) removed break statement from loop that discards trashed card 
