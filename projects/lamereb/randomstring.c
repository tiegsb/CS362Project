Brian Lamere
CS362_400
Fall 2015
24 OCT 2015

WRITEUP NOTES:

So, state only changes whenever c is [, (, {,  , a, x, }, ), or ]. And error message only prints when the return of inputString() is "reset", so, first thought, why not just make inputString() return "reset"?

Second thought, regarding inputChar(). All the char's that change state (there are 9 of them), are between ASCII decimal 91 and 125, with the exception of [Space], which is decmial 32. So, I could do 2 things here: a) make an array containing all 9 state-change characters, and return one of the 9 based on a random choice between 1 and 9, or b) generate a random number between 91 and 126 (but if 126, return 32 instead). (a) will be significantly quicker, so I'm gonna do that first.

RESULTS: Well, that was super-easy. I ran it 5 to 10 times, and it errored out, on average, in 100 iterations or fewer. Gonna try it again, this time by making inputString() return a random 5-char string of lowercase letters.

TRY 2 RESULTS: Yeah, so that took way too long. I realized, a couple million iterations in, that the state changes to 9 pretty quick, and that point I am just brute-force trying to randomly generate the word 'reset', which I gave up on after 15 million iterations. So what I'm gonna do this time is limit the input characters for inputString() to the  letters r, e, s, and t.  

TRY 3 RESULTS: Ok, that, too, was pretty easy. It errored out after a couple hundred iterations, on average, with 4800 being the most it ever took. So what I think I should do this time is consider a situation where the only input options to either function are the above-mentioned state-change characters and the above-mentioned letters. 

TRY 4 RESULTS: Well, that was probably more in line with what we're supposed to be doing here. It would typically error out after a couple hundred thousand iterations.

FINAL ANALYSIS: Limiting the possible number of input characters severely increases the chance of the testme() function erroring out, while increasing the number of input characters obscures the fact that the function possesses an error state.

