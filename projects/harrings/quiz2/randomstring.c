For my implementation I had the input char function generate a random number between 0-33 if the number was less then or equal to 
28 then I added the value to lower case to produce an  ASCII values of 97-125 then for 29-33 I had special cases to input the other
chars needed to advance the state number. For the input string function I created a dynamic char array with slots 0-4 being filled by calls
to input char with slot 5 being the null terminating char. Using this I found the reset message after 5.2 million iterations the first time.