Victor Hernandez
CS_362_F15
Quiz 2 - Randomstring.c 

inputChar()-
A random ASCII character between 32 and 126 is returned. This range of characters was chosen to cover all those found in the testme function.

inputString()-
Five random ASCII characters between 97 and 122 (lowercase letters) are retrieved and then added to a char array. 

testme()-
Uses a while loop to run inputchar() to find specific characters and updates int state as characters are found until state=9. Once state=9, the contents of inputString() are checked for the word 'reset', if 'reset' is found then the error message is printed and the loop exits. The loop runs until these conditions are met.