To create my random tests I made 2 character arrrays. One with the symbols for the first part of the test "[({ ax})]". The second with the word "reset", I decided to only use the letters that are in "reset" as opposed to the entire alphabet as it increases the chances of reachin the error message

Using the rand() I get a random number and mod the remainder to get an index in the array. 

For the "reset" array I am writing over the previous array each time until rand() creates the correct array.

I have run the test many time, it ranges from reaching the error message afer 94 to reaching it after 2342.