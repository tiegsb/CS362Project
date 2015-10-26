Overall Coverage:
Lines executed:45.83% of 648
-This is expected as were were only testing a select few of the functions of the program.


Individual Coverage:

unittest1 (test drawCard): 
Lines executed:89.47% of 19
Branches executed:100.00% of 4
-Because my my deck was not empty in my test, I did not get coverage of the statements 
related to starting with an empty deck (no shuffle then draw). A better test should test the 
function when the deck is empty. All statements related to a non empty
deck were covered.

unittest2 (test numHands): 
Lines executed:94.12% of 17
Branches executed:100.00% of 2
- My test determined if the function returned the proper number after a call
to drawCard. Checking for the other changes to the hand could improve this test.

unittest3(test fullDeckCount):
Lines executed:88.00% of 25
Branches executed:100.00% of 6
-I tested the state of the deck after calls to drawCard, discardCard with trash flag set and without. 

cardtest1 (test smithy): 
-100% branch coverage. All branches were evaluated.
-87.5% statement coverage. All bugs I implemented were caught however. Coverage could be improved

cardtest2(test council): 
-100% branch coverage. All branches were evaluated.
-90.62% statement coverage. This is pretty good coverage. All bugs I implemented were caught.  

cardtest3 (test adven): 
-33% branch coverage. Only a third of the branches were evaluated. This was due to the bug
I put in my code causing the number of treasure cards added to be too low.
-72.41% statement coverage This could be imroved, however all bugs I implemented were found.