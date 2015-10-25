/**************************************************************
The basic structure of the program remains unchanged with
the exception that a main method is added.
The main method simply calls testme()
The while(1) condition in testme ensures the program will 
continue to execute until the conditions are met and the 
error message is encountered when the string is found.

I used srand and time_t to seed rand in main.  Then in order
to find 'c' and get state to '9' i used 
' ' + (rand() % 94
since space was the lowest ascii value and 125 was the highest
possible; mod 94 yields at most 93 and 32 + 93  125.

To get the string 's' I declared a local c string with size '6'.
I used a for loop to iterate over the first 5 spaces in the 
loop.  I only use the first 5 because space 6 will already
have the null terminator in it.  
For each character in the string I used
'a' + rand() % 26 
since only lower case letters were under consideration.
I did this twice to resolution, the first time took
13,142,375 times and the second one took
3,912,866 times.
There is a warning that I am returning the address of a local
variable but I didn't want to change the structure of the 
program by declaring one in main and passing it to testme et...
****************************************************************/