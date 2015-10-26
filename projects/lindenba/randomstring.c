//
//  randomstring.c

inputChar() wrote the function to return a ASCII value to get a random value.  I tried to do it as simple as possible by just making it in the return statement.  I am wondering if maybe putting in an array might make it faster, but I'm not sure.

inputString() wrote the function with an array that will hold the letters that the testme() function is looking for before it prints out error.  I added the \0 terminated charater to the array. Then allocated space for the randomstring.  Then put in a for loop to randomly run through and hold the values until the values looking for returned and then the program printed error.
