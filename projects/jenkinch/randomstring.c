/*
------------------------------
randomstring.c
Quiz 2
jenkinch
------------------------------

Here is how I achieved a random test that reaches the error message in a 
reasonable amount of time:

First, I limited the scope of inputChar() by adding min and max parameters
that allow the user to specify lower and upper bounds between which to 
choose random characters. To get c, my calls to inputChar() grab values
between 32 and 126, a subset of the ASCII character set containing all the
values being checked for in testme()'s if-statements that update state.

Then, to limit the scope of generating strings, I limit the length of the
created strings to the minimum requirement of six and spell out five 
character strings by calling inputChar() using only the lowercase alphabet 
characters from 'e' to 't', which is the minimum range necessary to spell
'reset'. Finally, '\0' is appended to end the string. 
*/