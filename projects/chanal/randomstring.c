/*************************************************************************
The error message in testme.c will print out when it reaches state 9
and a null terminated string 'reset' is found.

In inputChar(), a randomChar is returned. The randomChar is randomly
selected from a pool of allowedChar[] (allowed characters) such as
{'[', '(', '{', ' ', 'a', 'x', '}', ')', ']', 'r', 'e', 's', 'e', 't'}.
If a returned randomChar matches with the conditions in testme, 
the state will increase according to the conditions, until a state of 9
is reached. 

After a state of 9 is reached, a randomly generated string from the
allowedChar[] pool is assigned to a static char array in randomStr of
length 6 (occurs in a loop, assigning each index a randomChar). 
Once the random string of reset with the null terminator '\0'
is randomly generated, the error message will printed.

**************************************************************************/