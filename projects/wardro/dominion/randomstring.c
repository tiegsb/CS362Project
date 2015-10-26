Robert Ward
10/25/2015

inputChar()
I implemented inputChar to randomly pick chars from "[({ a{)]". I had it choose from this group of characters to help the test to run shorter. A random number is generated from 0 to 8 and is then put in a switch statement where one character of the selection would be picked to be returned.

inputString()
I implemented inputString to randomly pick a char from 'rest\0' and a random char. The random char in the list added testing for what happens when a unexpected character is returned. I generated a random number between 0 and 4 which corrosponded to the characters in the group. The program looped 6 times, each time adding a random character onto the end of the char array. Once 6 of the characters were choosen it returned the char*.

The way that I implemented the test it takes anywhere between 2000 and 70,000 iterations to complete.
