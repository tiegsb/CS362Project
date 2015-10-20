Random Testing Quiz 2 Documentation:

RANDOM CHARACTER
In this assignment, I started out by attempting to assign a random char from the
256 possible ASCII values and a random string of size 6 (5 letters, 1 null char)
from the 26 lower case letters.  I figured that because the 1/256 to get the 
'right' char didn't need to be sequential, the chances of making it to state 9
quickly was very high.  (The math shows log(.5)/log(255/256) = 177).  That is
to say, the average number of iterations to discover a character is 177 with 
a standard deviation of 44.5.  

This means all 9 characters can be found in roughly 1593 iterations... very
quick in linear time with a computer.

The input, of course, could be narrowed down, but it really doesn't make too much
of a difference in this case.

--

RANDOM STRING
The random string, on the other hand, does make a difference in random values.
At first, I thought that limiting the characters to only the 26 lower case values
would be enough of a constraint on the input values that we could find the 'reset'
string quickly enough.  And while I have confidence that eventually I would end up
with the end result, it would have taken more time than I would have liked.

Math shows with only the 26 lower case letters, the chances of reaching the permutation
is 1:11,881,376 .  This means, on average we would expect to see the 'reset' permutation
after 8,235,542 iterations with a standard deviation of 2,071,558.

While this is relatively fast for a computer, especially given the linear nature of the 
algorithm, the real issue is that the computer OUTPUTS its results upon every iteration,
a relatively slow process.  Without output, I measured 10,000,000 iterations (and thus the
fuzzing process) taking only a second.  I could find a test case in under a second.
With output, however, I the measured the same 10,000,000 iterations taking well over
several minutes.

That is to say, there were two ways to proceed from here:
1. Disable the output
2. Increase constraints on random values

RANDOM STRING PART 2
Because I wasn't sure if I should modify the nature of the code (maybe the output is an
essential function of the algorithm), I chose instead to further constrain the random string.
In this new case, I chose to randomly enter only the four characters that when combined in the
correct order could cause a 'crash'.  These characters were: 'e', 'r', 's', and 't'.

With the new string generation, the 'reset' permutation could be reached in 1/1024 chance...
an average of 709 iterations with a std dev of 178.

CONCLUSION
With the new random string and character generation functions, I believe the program will
break after an average of 2302 iterations.

Disclaimer: that my statistics class knowledge is a little rusty and my numbers my be off
slightly due to biased curves in the data that I don't remember how to consider ;)


