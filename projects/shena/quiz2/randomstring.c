/*
inputChar():
I worked on this function first at it was very straightforward.
This function stores a random integer in the range 32 to 126 which
corresponds to the ASCII table for all keyboard keys. This int is
then casted to character and returned.

*inputString():
This function declares a char array then populates the first 5 spaces
with random characters using a for loop. Because the for loop itself 
stops before the end of the array, there is no need to set a null 
terminator as it is already present. The function returns the string,
which is now populated with five characters (as well as null 
terminator).

The program correcty terminates when state 9 is reached and string s
reads 'reset'

The fastest the program reached the "error" prompt was at 51187
iterations but this was by far an anomaly. For the vast majority of
trials, the number of iterations ended up in the millions.
*/