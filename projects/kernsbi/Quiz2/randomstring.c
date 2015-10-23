Billy Kerns
randomstring.c
Quiz 2

For the inputChar() function I just made an array that holds all the special characters that the first part of testMe() checks for.
After creating this array I created a random int that holds a number between 0 and the size of the array -1.  I then return the
array of special characters at whatever the random int is.

For the inputString() function I made an array (stringArray[]) that holds all the characters that the second part of testMe() 
checks for plus some other characters to ensure the function was working properly.  I then made a for loop that will go through 
a c string that is 6 characters long(string[6]).  Each character in string[6] is then set to equal a random character from
stringArray[].

These allow me to find the error message by first throwing random characters at the beginning if statements until state 9 is reached.
Once state 9 is reached the inputChar() function really has no use anymore.  Now the inputString() function is going to throw a
randomly constructed string at the last if statement in testMe() until the random string happens to be "reset".