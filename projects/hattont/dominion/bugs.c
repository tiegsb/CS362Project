Ty Hatton 
CS362-Fall15
Assignment 3

Bug Report:

adventureCard - Passes to the wrong player. This appears to be the result 
of an early shuffle, but not certain

villageCard- incorrectly increments numActions. Throws numerous errors in the
cardtest as a result. 

greatHallCard- Fails all tests. Wrong player called, numActions are off by 1.

smithyCard- smithy doesn't draw enough cards. Causing another error in the 
order of the correct users hand 

isGameOver()  - The loop counting elements == 0 in supply count.  Off by 1.


