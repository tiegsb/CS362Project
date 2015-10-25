/*
*	CS362 - Quiz #2 - random.c
*	Author: Carol D. Toro
*	Date: 10/21/2015
*/

/*
*	Development of Random Tester: 
*
*	I started off development by ensuring that the inputChar() method would only return a character
*	that could be caught by the code in testme.c. At first, I had the characters only repeated once in the
*	array of size 13. In order to improve the probability that a string would be built by mostly letters,
*	I opted for creating an array of size 22 with duplicate letters scattered throughout. For the inputString()
*	method, I built a 5 character string looping through an array and saving the character returned from the
*	input char method into the array at that location. I then copied the contents of that string into a 
*	dynamically allocated string which gets returned by the method. 
*
*	When running this random tester, I was able to trigger the error message at iteration 4261683!! 
*				Iteration 4261683: c = x, s = reset, state = 9
*				error flip1 ~/CS362/quiz2 1449%
*
*	Seeing as how 9 minutes had elapsed before finding the error! I knew I had to modify my methods so that
*	the probabilities of hitting the error message could be higher. I went back to the inputString() method
*	and made the choice to always have the last character in the string end with '\0'. Making this improvement
*	has made it much easier to trigger the error message when the string reads 'reset\0'
*
*				Iteration 504307: c = s, s = reset, state = 9
*				error flip1 ~/CS362/quiz2 1452%
*
*
*				Iteration 290130: c = (, s = aee(}, state = 9
*				Iteration 290131: c = }, s = reset, state = 9
*				error flip1 ~/CS362/quiz2 1453%
*
*				Iteration 67164: c = a, s = reset, state = 9
*				error flip1 ~/CS362/quiz2 1454%
*
*/