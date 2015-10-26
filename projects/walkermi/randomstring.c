This task was very straight forward and used simple c strings and random number generating. 

First off I wrote the inputChar function
since it was the most simple of the two fucntions to write. I declare a character and assign it a random number between 32 and 126. 
This range is based off the ascii conversion table and includes all characters typically found on a keyboard. I then returned this
random character. 

Next I moved onto the inputString function. Here I knew I had to create a string of 6 characters to return. After looking throuhg 
the code in testme() I knew I had to restrict the random characters in the random string in indexes 0-4 to 'r', 'e', 's', 't' or else
the program would run too long (odds of getting the string "reset" if using all 126 ascii characters would be ((1/94)^5)%). I also knew 
that the character at index 5 needed to always be '/0'. After this planning I created an aray housing the four possible characters to 
randomly generate for the string as well as using malloc to allocate memory for the string. I then used a loop to randomly assign characters
to the random string array. After the loop I returned. I added a line in the testme function to seed the random number generator and I also
added a line to free the memory allocated to the random string to avoid a memory leak. The code compiled and terminated after state 9 was 
reached and the random string equaled "reset."