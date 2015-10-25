Dustin Dinh
CS 362 Assignment 3

***********************************  cardtest1  ***********************************
Card: Village
Lines executed:22.88% of 577
Branches executed:25.18% of 417
Taken at least once:15.11% of 417
Calls executed:16.16% of 99

All statements were covered in the villageCard function. There were no branch
statements in this function. As a result coverage was straight forward. 

***********************************  cardtest2  ***********************************
Card: Adventurer
Lines executed:29.98% of 577
Branches executed:31.89% of 417
Taken at least once:22.30% of 417
Calls executed:27.27% of 99


Two branches were not covered. As a result 4 statements were not executed. 
The first branch contained 1 statement that checked to see if the deck needed
to be reshuffled. The second depended on not drawing a treasure card. Both of these
problems could have been solved by either manipulating the deck so that it had the
right quantities and composition or increasing the number of runs. Since it requires
less time, inceasing the number of runs is recommended.


***********************************  cardtest3  ***********************************
Card: Smithy
Lines executed:29.98% of 577
Branches executed:31.89% of 417
Taken at least once:22.30% of 417
Calls executed:27.27% of 99

All statements were covered in the smithyCard function. There were no branch
statements in this function. As a result coverage was straight forward. 

***********************************  cardtest4  ***********************************
Card: Mine
Lines executed:29.98% of 577
Branches executed:31.89% of 417
Taken at least once:22.30% of 417
Calls executed:27.27% of 99

Note: With the bug I introduced, coverage was very poor since the function exited
out as soon as it detected an invalid parameter input. If I removed the bug, only one
statement was missed. The issue was boundry checking. I did not include an input that
was outside the range of possible cards. 

***********************************  cardtest5  ***********************************
Card: Minion
Lines executed:29.98% of 577
Branches executed:31.89% of 417
Taken at least once:22.30% of 417
Calls executed:27.27% of 99

Statement coverage and branch coverage was complete until the functions that involved
the opposing players hand. I discovered that I could not measure the various
states of the other player. Either the values were missing or did not exist. As a
result I could not test those lines of code. 

***********************************  unittest1  ***********************************