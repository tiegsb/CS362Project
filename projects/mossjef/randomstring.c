/*
 * Name:	randomstring.c
 * Date:	10-20-15
 * Author:	Jeff Moss
 * Description:	Write-up for the testme random tester development
 * 		and how the testme tester finds the error message
 * Class:	CS362 Fall 2015
 */

For this exercise, I first started with the intputChar() function and implemented it by choosing an integer between 32 and 126 inclusive. This included every printable ASCII field in the ASCII table. I then cast that integer to a char and returned it from the inputChar() function. This was sufficiently deep in making it through all 9 states and making it to the final if statement for the string based if statement. 

For the inputString() function, I first started by implementing all lowercase letters in the input domain. This meant that there would be 26^5 chance of being able to hit the special condition "reset". I found that I hit reset in a few times within 2-4 minutes around the 9-20 millionth iteration. I still didn't feel like the random testing was directed enough, so I decided to restrict the domain even more and fix the first letter. Now, the error message is reached within about 1 minute. If I were able to modify more than just the input functions I might make nested loops, fixing one and random testing the others.

Lastly, I made one minor change to avoid a huge memory leak, at the end of each while statement I free the memory from allocating the memory for the string.
