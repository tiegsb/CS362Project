/* I found that implementing random testing for testme() was somewhat difficult
 * to approach fairly. Being able to see the source code makes it incredibly
 * easy, in this case, to see what sort of tests are necessary. Because of
 * this, I felt like my initial solution was a type of cheating:
 *
 * Solution 1: My first option, this has inputString() not making calls to
 * inputChar(). Instead, inputChar merely randomly generates characters from
 * the particular subset needed to advance testme() to stage 9, and inputString
 * uses a for loop to set a random character from the subset of characters
 * needed to make s[] = "reset\0". This combination arrives at the error
 * message incredibly quickly, but feels unfair to the spirit of true random
 * testing, because it's so unrealistically guided.
 *
 * Solution 2: This is the brute-force solution, where inputChar returns a
 * random number, letter, or symbol. inputString makes repeated calls to
 * inputChar to assign each index value. As of writing, I have not completed a
 * raw brute-force run, despite running >35 million iterations.
 *
 * My conclusion was to use the first solution for pragmatism's sake(altering
 * it so that inputChar picked a random number/letter/symbol), and
 * recognize that in a real-life situation, this degree of limitation and
 * clarity would be extremely unlikely, forcing the use of solution 2 (modified
 * with any further information available to constrain results).
 */
