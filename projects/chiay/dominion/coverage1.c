/************************************************************************
	   Report of code coverage for dominion's unit test
************************************************************************/

/*
unittestresults.out shows an output about total coverage of line and branches 
executed.

File 'dominion.c'
Lines executed: 35.58% of 579
Branches executed: 43.41% of 417
Taken at lease once: 33.33% of 417
Calls executed: 20.00% of 95

The total line and branches execution are 35.58% and 43.41% respectively. As my
unit testings are regarding the chosen functions, most of the lines are not executed,
so the results do make sense. Some lines in the functions that I called from my unit 
test programs may also not executed because I probably miss out some details.
*/



/*
As for the coverage of each of my unit tests, most of the lines are executed. The
only line that is not executed is the line which shows the error message of failed
testing. Unless there are bugs in the tested functions, the unit testing program will 
show failed message, and so the "successful" message will not be executed. The 
coverage results of each unit test are shown below.


-----------------------------------------------------------------------

File 'unittest1.c'
Lines executed: 98.61% of 72
Branches executed: 100% of 10
Taken at lease once: 90.00% of 10
Calls executed: 92.31% of 13
Line not executed:

     #####:   181:	printf("Test #%d failed unit test!\n\n", i + 1);

-----------------------------------------------------------------------

-----------------------------------------------------------------------

File 'unittest2.c'
Lines executed: 97.60% of 125
Branches executed: 100% of 18
Taken at lease once: 83.33% of 18
Calls executed: 85.71% of 21
Line not executed:

     #####:   204:	printf("Test #%d failed unit test!\n\n", i + 1);
     #####:   222:	printf("Test #%d failed unit test!\n\n", i + 1);
     #####:   240:	printf("Test #%d failed unit test!\n\n", i + 1);

-----------------------------------------------------------------------

-----------------------------------------------------------------------

File 'unittest3.c'
Lines executed: 93.55% of 62
Branches executed: 100% of 40
Taken at lease once: 77.50% of 40
Calls executed: 80.95% of 21
Line not executed:
     
     #####:   102:	printf("Test #%d failed unit test!\n\n", n + 1);
     #####:   112:	printf("Test #%d failed unit test!\n\n", n + 1);
     #####:   122:	printf("Test #%d failed unit test!\n\n", n + 1);
     #####:   132:	printf("Test #%d failed unit test!\n\n", n + 1);

-----------------------------------------------------------------------

-----------------------------------------------------------------------

File 'unittest4.c'
Lines executed: 97.44% of 72
Branches executed: 100% of 10
Taken at lease once: 90.00% of 10
Calls executed: 90.91% of 11
Line not executed:
     
     #####:   105:	printf("Test #%d failed unit test!\n\n", j + 1);

-----------------------------------------------------------------------

-----------------------------------------------------------------------

File 'cardtest1.c'
Lines executed: 96.49% of 57
Branches executed: 100% of 12
Taken at lease once: 83.33% of 12
Calls executed: 93.55% of 31
Line not executed:
     
     #####:    84:	printf("(Test #1 failed unit test!)\n\n");
     #####:   123:	printf("(Test #2 failed unit test!)\n\n");

-----------------------------------------------------------------------

-----------------------------------------------------------------------

File 'cardtest2.c'
Lines executed: 96.49% of 57
Branches executed: 100% of 12
Taken at lease once: 83.33% of 12
Calls executed: 94.29% of 35
Line not executed:
     
     #####:    75:	printf("(Test #1 failed unit test!)\n\n");
     #####:   118:	printf("(Test #2 failed unit test!)\n\n");

-----------------------------------------------------------------------

-----------------------------------------------------------------------

File 'cardtest3.c'
Lines executed: 90.38% of 52
Branches executed: 100% of 14
Taken at lease once: 64.29% of 14
Calls executed: 82.14% of 28
Line not executed:
     
     #####:    77:	cardNumToName(test_state.hand[1][i], name);
     #####:    78:	printf("\t%s", name);
     #####:   101:	cardNumToName(test_state.hand[1][i], name);
     #####:   102:	printf("\t%s", name);
     #####:   108:	printf("(Test #1 failed unit test!)\n\n");

-----------------------------------------------------------------------

-----------------------------------------------------------------------

File 'cardtest4.c'
Lines executed: 97.06% of 34
Branches executed: 100% of 8
Taken at lease once: 75.00% of 8
Calls executed: 94.44% of 18
Line not executed:
     
     #####:    83:	printf("(Test #1 failed unit test!)\n\n");

-----------------------------------------------------------------------
*/
