
Daniel Bonnin
CS362 Fall 2015
bonnind@oregonstate.edu
randomstring.c

This file contains documentation about my implementation of inputChar() 
and inputString() in the file testme.c.

This documentation and the implementations of inputChar() and inputString()
meet the requirements of Random Testing Quiz 2.

*****
inputChar():
Returns a random character from an array of allowed characters. Since testme()
does not reset the state at any point, there was no need to weight the
probability for any particular character. 

inputString():
Returns a pointer to a string containing a random ordering of the characters
in "reset". 

I left both 'e' characters in the array for readability since it does not have
an extreme effect on the number of iterations. 

Since all values of c and s[i] are compared against specific values, I
determined that there is little risk in limiting the test array to those values.  

In this test, I calculate that getting to state == 9 should take approx 81 
iterations. Then, it will take an average of 781 to get s == "reset".  
Therefore, we expect 862 iterations to get the error. 

