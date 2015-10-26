Ashley Greenacre
CS362 Fall 2015
Quiz 2

For this quiz we had to implement a random tester for the function testme.c.  The 
function testme() creates a variable c from the function inputChar(), that is any 
printable character from ASCII 32-127, then it creates a variable s from the function 
inputString(), that is a string made of 5 lowercase characters and a null terminator. 

The testme() function then first checks for '[' then '(' then '{' then ' ' then 'a' 
then 'x' then '}' then ')' then ']'.  Each time it find the character it is looking 
for it increases the state number until 9.  Then it checks the string each time for the 
string "reset\0".  Once it has reached state 9, and found the string "reset\0" with the 
NULL terminator at the end, it results in printing an ERROR message.

First I read through testme.c to understand what the function did, and what I was 
supposed to do.  Then I started with the function inputChar() to return a printable 
character from ASCII value 32 to ASCII value 127.  Then I wrote the inputString function 
to create a string of 5 characters of lowercase alphabetic characters, which are from 
ASCII value 97 to ASCII value 122.  Then I just set the fifth element of the character 
array to the NULL terminator.   

I have tested it and my implemented random tester works, and it is capable of printing 
the error message.  These are the results from my tests.

Test1: 43048368 iterations
Test2: 4640479 iterations  
Test3: 3198961 iterations
Test4: 3991408 iterations
Test5: 19012992 iterations




















