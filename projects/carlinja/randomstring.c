James Carlin
Randomstring.c
Quiz 2


This finds the error by producing random numbers.

my inputChar function returns a random number that fits within basic ASCII table. All characters are included in this, including the ones that will set the error message off.

So my code picks a random number from 0-95, then adds 32. This ensures that I'll eventually get one of the characters that will set off the error message.


My inputString() function has an array of chars ended with a null character. It gets filled within a for loop. After the for loop, I set the 5th position equal to a null character, as is normal in C code.