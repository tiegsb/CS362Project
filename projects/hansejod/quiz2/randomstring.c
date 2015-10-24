Jody Hansen
Quiz 2 writeup

inputChar():
This function returns a random character that beginning with the ASCII character ' '. The reasoning behind this is that the first ASCII characters are control characters, or numbers that don't represent printable characters. I use a random number generator to produce a number between 0 and 94 and add it to the value of the ' ' character (32). This gives me a range throughout the remaining ASCII values from 32 to 126. The program quickly reaches state 9. There is an alternative code that is commented out that random picks one of the special characters, but was not used because most likely the tester would not have this type of knowledge while writing the test. It would also not be very flexible in that it would not work if the developer decided to change on of the characters.


*inputString():
This funciton employees a similar approach to inputChar() function in that the method to produce a random character in the alphabet. The value range is from 92 to 122 with the idea that most strings only contain alpha characters. The difference is that the step is repeated in a for loop that fills the first five characters of the string with a random letter.

Using gcov, 96.97% of the 33 lines were covered.