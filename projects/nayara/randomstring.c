/************************************
* Author: Ashok Nayar
* Class: cs362, Fall 2015
* Project: Quiz 2 - Random Testing (documentation)
************************************/

/** Approach **/
To start, I took a look at the testme() function to see what the code was doing. In this function, we see that the very last if statment 
is the one that triggers the exit() and error portion of the code. In order for this to be triggered, the state needs to equal 9 and the 
characters in the word need to spell out "reset" with a trailing "\0" character at the end. The "reset" word will eventually be created 
if the random function always returns a combination of r,e,s,t,\0 that is 6 characters long. It could take a while, but eventually it will 
happen. The second part of the code requires the state to equal 9 but in order for this to happen the state must start at 0 and pass
though each of the if statments, incrementing the state by 1. Luckily, the state does not reset itself to 0 during each iteration of 
the while loop, so whatever the state gets changed to remains until it gets changed again by the next if statement. If the state is less
than 9, it doesn't really matter what the random "word" string is since the final if statement requires the state to be 9 AND have the word
"reset". Once a state of 9 is reached, we simply wait until the inputString() function returns the correct word and then the program "fails."


inputChar()
For this function, I created a char array of the following characters: ({ ax})]. I then called the random function and performed a mod 
operation by 9 in order to get a value between 0 and 8. This returned number corresponds to an index in the char array and the character
that resides in this location is returned by the function.

inputString()
First, I allocated space for 6 characters, then performed a loop starting at 0 and ending a 5. In each iteration of the loop, I 
called the random integer function and then modded it by 6, in order to get a value between 0 and 5. This value corresponds to an index
in a char array that holds r,e,s,t,and \0. Each iteration of the loop then adds this character to the end of the string and when the loop
is complete, the string is returned. 

In my testing, this program exited with the  "error" in as little as 118 iterations and as much as 35,000 iterations.

NOTE: Please see the testme.c for comments on the code.