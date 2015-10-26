// Explanation file: randomstring.c
// Tony Huynh	CS 362	Fall 2015

// For the testme.c file, all I had to do was implement the inputString and inputChar.
// I did not write the tester-- that was already given to us. What it does is it goes through
// a while loop and check off certain characters and string.  After hitting all the characters,
// it then checks for the word "reset".  After figuring out the code, I was confident that my
// program could reach the state of error.  

// In the process of writing my code, I knew that it was be extremely unlikely for a string to turn
// out as "reset", so I had to put some limitations on it to increase the chance of hitting the 
// error condition.  My first step was to make sure the random ASCII values gave me only the 
// lower case letters.  When I tried running this, it still took a long time to reach "reset" 
// (it never reached it in my case).  So I further narrowed down the possible results that the 
// random letters could be.  It is to the point where the letters 'r', 'e', 's', and 't' will show up
// very often, so the error should show up soon.  I put comments in my program that explains how to 
// decrease the chance of finding the letter "reset".
//
// Adding this line to update for commit. Please ignore.
