/*

srand is already initialized in main so we don't have to worry about that

inputChar() generates any of following characters randomly,
	with equal probability: [({ ax})]
	The point of this is to minimize the possible input range to only those
	characters that are relevant. There are only 9 possibilities for this
	function.

inputString() generates a char array of length 6. This matches how deeply
	testme() tests the string. It only uses the following characters,
	randomly for each position in the string (except the last): erst
	Again this is to minimize the input range. It always terminates with a
	null terminator - a string wouldn't be a string without one. There are
	4^5 possibilities for this function.

The probability at producing the error message with 1000 attempts is:
(1 - 1/4^5)^1000 = 37.6%

COMMENT: testme() is suppose to delete (free) the string after each iteration 
	to free up memory

*/