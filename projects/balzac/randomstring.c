/*
I implemented inputChar() first by assigning a char inside the function a random number
between 0-128. The number is the ASCII value of a character and is interpreted as a character via
testme(). To test that this worked I commented out the last if statement and made a new if statement
that checked if state was 9 the error message would output and the program would exit. After I
could get the error message to show I got rid of the if statement I made and uncommented out the
if statement that checks a string.

I then began to implement *inputString() which assigns a char array index a random integer between 
97-122 which are the ASCII values for a-z inside a for loop that iterates 5 times. 
I could have made random values 0-128 but I chose to check the values a-z to make it more probable
the error message would output if a million iterations were to run.

After the two functions were implemented I tested that inputString() returned "reset" and the 
program would end if the state reached the value of 9.

The two functions works together to find the error message by first checking a sequence of
specific characters that increases the value of state. Once state equals 9 the char array or 
string is checked for the value "reset" with a /0 at the end of the array.
*/