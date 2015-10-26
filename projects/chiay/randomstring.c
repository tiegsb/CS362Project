/********************************
Quiz 2: Random Test for testme.c
********************************/

/*
For the inputChar() function, I added a code to return the random number betweenthe range of 32 - 126. 
Accroding to the ASCII table, the characters of this rangeis from ! to ~, which includes the characters 
for checking in the if-else statement.

	rand() % (95) + 32;

The code above will just pick a number from 0 - 95 randomly and add with 32. 
*/


/*
In the inputString() function, a char array variable is declared to hold 5 characters and the null terminator. 
A for-loop is used to fill the up the char array to form a string. Similarly, the rand() will randomize a number 
between 97 - 122, which is the ASCII code for lower case a - z. After the for-loop, the string will be filled 
with a null terminator ('\0') and return. 

	for (i = 0; i < 5; i++)
	{
   	   rand_ascii = rand() % (26) + 97;
   	   rand_str[i] = rand_ascii;
	}

	rand_str[5] = '\0';
*/

/*
The program will get one character for the state first, then when state is equal to 9, the program will start
looping for random string. The loop will terminate and show error until the word "reset" is returned. 
*/
