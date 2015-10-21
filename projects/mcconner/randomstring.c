// Random Testing Quiz 2
// Rachael McConnell
// CS362 Fall 2015

/*
The inputChar function gets a random ASCII character between 0 and 127 and returns that character.
The inputString function gets 5 random ASCII characters between 97 and 122 and adds each character 
to a char array. The testme function works in a while loop. To begin, the inputChar and inputString 
functions are called and there are a series of if statements. The inputChar and inputString functions 
are called until a specific character is found by the inputChar function. When the desired character 
is found, the variable 'state' increases by 1 and the character that we are searching for updates. Once 
state 9 is reached, the output of the inputString function is evaluated. The random tester finds the 
error message when state = 9 and the 5 characters from function inputString spell out 'reset'. The 
inputString function is called continuously until this set of characters is found. At this point, the 
error message is printed out and the program exits.
*/