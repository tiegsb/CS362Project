/******************************
Susan Lee
CS 362_400_Fall15
quiz 2 - random string
*******************************/

inputChar() uses a string of valid characters as defined by the testme() driver program.  
inputChar() randomly generates a number between 0-13, which corresponds to the indices
of the string of valid characters.  The randomly generated number determines with character
at that index is returned.  

inputString() uses the inputChar function to generate a string of 5 characters.  These characters
are placed into a string at increasing indices until 5 characters are found.  It then places a null
terminator at the last index and returns the string to the testme() driver program.

Both of these functions are pulling from the pool of characters as defined in the testme() driver 
program, thereby increasing the probability of hitting "random" characters that will ultimately 
meet the conditions for the end of the loop and printing out the error message.  Although the tester
is randomly choosing which characters and what string to pull into the testme() driver program,
it is confined to a specific set of characters that will better fit the conditions of the program.  
In this way, we can limit our test results to those that are defined, provide more substantive data,
and are more meaningful.