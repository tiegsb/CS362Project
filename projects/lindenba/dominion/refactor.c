
The 5 cards I picked to refactor:
Adventurer
Smithy
Council_Room
Remodel
Great_Hall

The bugs introduced:
Adventurer function removed from the while loop for the temp array the equal sign so instead of looking for greater than or equal to 0, it only looks for anything greater than.

Smithy function in the for loop to add cards made i equal to 1, so the number of cards gained is off by one

Council_Room function changed the trashflag in the discardCard function to 1, so the card won't be added to the played pile

Remodel function in the gainCard function changed the choice2 card to choice1 card.  