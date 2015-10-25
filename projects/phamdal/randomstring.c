/*Dalena Pham
 * CS 362 - Quiz 2
 * randomstring.c
 *
 * inputChar()
 * 	Creating inputChar was pretty straightforward. Using the ascii values
 * 	of the letters in range 32 (space) to 126 (~). This range would include
 * 	the brackets needed to achieve the error message. With this range, the
 * 	inputChar() function simply returns a random value within the range. 
 * 	To further direct tests, I could've only made it so that inputChar
 * 	chooses from the characters '[({ ax})]' but I felt that in order to
 * 	keep things relatively random, to just allow inputChar() to choose
 * 	from a large range of numbers. 
 *
 * inputString()
 * 	This is where most of the direct random testing goes. In order to reach
 * 	the error statement efficiently, I set up conditions so that only the
 * 	characters in the word 'reset' would be choosen to be placed in the
 * 	test string. Otherwise, it would take an extremely long time for testMe
 * 	to create an string that would reach the error conditions.
 *
 * 	Additionally, I purposely only allowed inputString to generate strings
 * 	that were 6 characters long and assigned the sixth character as a null
 * 	character. This was to help inputString achieve the desired string 
 * 	to reach the error condition. 
 *
 * Other notes: 
 * 	Because I allocate space in the inputString() function for the input
 * 	string, I added deallocation statements in the testMe() function to
 * 	avoid memory leaks. 
 * / 
 * 
