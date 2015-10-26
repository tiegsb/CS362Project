// Keenan Bishop
// quiz 2 writeup
/*

This function is a while loop that requests a random character and a random string every iteration.
It updates a state variable if the random character matches a specified one for a specific state.
After successfully matching 9 different characters it reaches state = 9.
When state = 9, the if statement that checks the random string becomes relavent.
The if statement basically checks for the string "reset" and prints an error if it gets it.

For the random character, I made a random character switch statement with a pool of characters that included the characters the loop checked for.
The pool of characters could be increased, but this would only make the function take longer on average.

For the random string function, I just constructed a random string with a pool of characters that included the characters in the string it was looking for.
Once again, this pool could be increased, but all it would do is make the function longer.

Since the pool of characters in the switch statements contains all of the characters it needs. it is possible for the function to end.

However, it is not guaranteed to end.  The random output can potentially keep returning incorrect values and loop infinitely, but the chance of it happening decreases over time.

*/
