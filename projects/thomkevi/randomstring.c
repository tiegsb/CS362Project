Documentation for testme.c

char inputChar()

The inputChar function returns a random character to the calling procedure.  The
character is determined by calling the random() function, taking the modulus of 94 and
adding 32.  In the ASCII table, this results in characters from 32 'Space' to 126 '~'.

char *inputString()

The inputString function returns a pointer to a random string of 6 total characters 
consisting of the characters 'e', 'r', 's', and 't' and terminated by a null 
terminating character '\0'.

void testme()

The testme function prints an error message and exits the program based on an escalating
series of criteria.  In order to print an error message and exit, the function must
call and receive specific characters in order from the inputChar function and then
call and receive a specific string from the inputString function.  The inputChar function
was designed to randomly return characters that are in the testme criteria.  The inputString
function was designed to randomly create strings consisting only of the characters in 
the testme criteria.