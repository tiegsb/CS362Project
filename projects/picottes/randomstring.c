The inputChar() function makes a random selection of the 10 possible characters tested
for in the testme() function. It then returns that character. 

The inputString() function allocates memory for the return string. The function then iterates
through an array of possible values of reset and the null terminator. When a value is added
to the return string it is removed from the of possible values, the remaining characters are
then shifted one over, the array count is decremented and the random value range is decremented
as well. This significantly reduces the number of random tests.