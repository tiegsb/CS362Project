/*
Author: Tara Massey
Date: 10/22/2015
Assignment: Quiz 2

--- Development of Random Tester ---

Problem Solving Stage:
I attempted to clarify the instructions. To the best of my understanding, the instructions stated that I
needed to build two functions, inputChar() and inputString(), in order to build the random tester. The goal
of the tester was to, eventually, reach the combination of random letters that allows the error message to
be produced.

In order for the error message to be produced, I needed the random combination of letters in the string to
form "reset". I took note that these were all lower case, and that it was checked to make sure the string
ended with a null terminator.

Next, I noted the domain for the inputChar() function. It needed to return a very limited set of possible
characters. Of these characters, all letters were also lower case.

Ideas:
My initial idea was to limit domain of allowable test characters for inputChar() to be only of those allowed.
Meaning, my random number generation would be 0 - 8, and each integer would correspond to a symbol. Ideally,
if allowed free regin, I would do this. I believe the random testing would finish much more quickly with a 
limited domain. Since I wasn't sure how literally I was to take "random values," however, I opted to not do
this.

My next thought was what I went with. I just took the range the smallest possible character could begin at
and went to the last possible character that could be found. Since I knew none of the letters I was looking
for would be capitals, I also reduced the domain to only be lower case letters.

For inputString() I simply needed to produce lower case letters, so I set my random number generator to have
a range that corresponded to the ascii lower case letters. My thought process was that I needed to keep the
domain of possible inputs as small as possible while still being random, to reduce overall time.

-
-- How the Error Message is Found --

inputChar():
We have previously determined that our range will begin at the desired character found earliest in the ascii
table, and end at the character found latest in the ascii tables. So, I produe a random number with rand()
beginning at 32 and going to 127.

Next, if the integer produced is 65 - 90, it is an upper case letter. Those are never needed. I turn 
them into lower case numbers by adding 32 to the integer, hopefully producing a more timely error code
production.

Last, I create a character and assign the interger to it. This produces the character that corresponds to 
the ascii number. I return it.


inputString():
We have determined that the string that needs to be produced is "reset\0". Starting the count at zero, that
means a variable needs to be produced that is variable[5]. I do so.

Starting at variable[0] and going until the end of the string -1, I fill in the string with a random
number. That number is in the range of lower case letters only, 97 - 122.

Since we know that a null terminator will be matched, and strings in c are evil, I add in a null terminator
at the end. The string is then returned.

When the correct combination is returned the if statement will be activated in testme() that calls the error
message we're seeking.


--- Results ---

Even with narrowing the valid domain a bit, the test can still run for minutes at a time. Ideally, I would
be allowed a liberal interpretation of what the valid domain of random characters are for inputChar(), as
I imagine that would increase efficiency. As is, the domain is so large that the rest results are quite random.
Some Samples:
Iteration: 840112
Iteration: 723498
Iteration: 3638480

This leads me to believe that, much like the lectures stated, a truly random number generator without the
restraints of a valid domain may not be ideal.

*/