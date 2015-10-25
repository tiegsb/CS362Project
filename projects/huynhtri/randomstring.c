//Solomon Huynh - huynhtri
//CS362 Quiz 2

/***************************************************************
I implemented random values based on ASCII codes in order to produce random values for the testme() function.
Starting on the inputChar() function, I wanted to cover all the special characters that are used in the
testme() function so I determined that the range is from the ASCII values 32 to 125 which includes "[]",
"{}", " ", etc. I just simply return the randomly generated character back to the testme() function and
check if the program goes to state 9.

After I determined that testing inputChar worked, worked onto inputString() function to generate the word
"reset". I did this by having ASCII values 97 to 122 to generate a random letter from a to z. Then I did
a for loop to insert the random letters into an array. Once I tested this out, I found out that it was
taking forever to randomly form the word "reset". Calculating the probability to generate the word, it
was 26^5 chance to generate the word which would 1 / 11,881,376 chance of generating the word. In order
to make testing faster, I determined that the best course of action is to lower the probability by
having two of the five letters be correct randomly. This is done after it randomly generates the five
letters so it will now be a 26^3 chance instead which is a 1 / 17,576 chance instead. When I ran the
test, it worked perfectly and it tests enough combinations of letters for this function.
****************************************************************/
