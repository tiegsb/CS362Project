/*
Brian Tiegs
CS 362 - Random Testing Quiz 2


testme() repeatedly calls inputChar() and inputString() to get random values for c and s. testme() first tests c against a set of characters and if the character at its current state matches, the state is incremented. If all of the characters tested in testme() can be reached by inputChar() then the state will be able to reach 9. Once the state equals 9, the testme() function checks if string s equals "reset". If it does the error message is printed and the program exits.

inputChar() returns a random character. Initially this function was designed to return any ASCII character however the number of iterations needed to cause the error message was too high therefore only characters used in the testme() function was used. inputChar() was implemented by declaring a cstring that contains all of the characters tested in testme(). The cstring contained 14 characters plus '/0'. Next the rand function was called to get a random number from 0 to 14. This number was then used as the index for the cstring to get a character from the array. This character was then returned.

inputString() creates a random 6 character string using random characters obtained from inputChar(). inputString() first allocates memory for the cstring. A for loop is used to iterate over each character in the string and assign a random character to it using inputChar().

testme() returned error message on iteration 3792478.
*/
