Method for testing testme.c:

inputChar() implementation
	-First I created a string of chatacters a-z (lowercase) and chatacters that include the characters in the if statement of the testme function.
	-Next I select a random number from 0 to the length of the allChars string.
	-Finally, a character is set to equal the character at the position of the number generated in the previous step.
	
inputString() implementation
	-First a random number between 0 and 99,999 is selected.
	-If the random number is 50,000 then the return string is "reset"
	-If the random number is not 50,000
		-Select a random number between 3 and 12. This will be the length of the random string.
		-Fill a string of the size previously calculated using the random character generator inputChar() just created
		-Set the last character in the string to \0 because that is how strings are created in C.
		-Finally return the string.
