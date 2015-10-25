/*
Kenny Lu
CS 362
Quiz 2
randomstring.c

For this quiz, I knew that I needed to creat two random tests that would test a given function
in the testme file.  The first function that I worked on was inputChar().  Before going into
coding, I thought about what I had to consider while trying to figure out how to create the test.
First, I determined the input of what needed to be tested.  It looked like what was being tested
for was individual characters.  I needed to find a way to input random characters into the function
being tested.  This was done by setting up a character array with every character including the special
ones.  Next, a random character was picked by using a random number generator which represented
the index of the character on the character array.  The random character was returned and passed
into our test function.  

NOTE: I realized later that I didn't need to create a character array after all
as all char's in c are represented by a unique number anyways.  My implementation could've led to some
super special chars being ommitted but the random test is still functional without any major 
repercussions.

For the inputString random test, I determined that the input would be the four characters r, e, s, and t.
Next, because I knew the intended result would be an array of 6 characters (including a string
escape character \0), I needed to construct an array that was just that.  I created this array by
allocating memory to randomString of 6 bytes.  From this array, I used a random number generator like from
above with a number from 0 to 3 to represent each index of the r, e, s, t array to obtain a random
character for each character in the string.  This was easily achieve with a for loop.  The last element 
in the array (index: 5) was manually set to the string escape char.  Finally, the string is returned (address
pointing to the first element is returned).
*/

