Refactor Changes

In function cardEffect()

Smithy case now calls separate function playSmithy()
 Logic error implemented: i++ is now ++i

Adventurer case now calls separate function playAdventurer()
 While loop logic operator is incorrect.  Brackets for while loop also omitted.
 
Council_Room case now calls separate function callCouncil_Room()
 When increasing the buys, numBuys++ has been changed to numBuys + 1 which will not actually change the variable.
 
Feast case now calls separate function playFeast()
 No new bugs introduced
 
Mine case now calls separate function playMine()
 Changed logic of || to && which will allow a player exchange non-treasure cards as well as treasure cards.