/*
 * Jason Gourley
 * gourleja
 * CS362-400
 * Quiz - “randomstring.c”
*/

/*

  Overview

  In order to trigger the error message in the testme function I looked at the structure of the function and what conditions must be met to trigger the error message.  Identifying the elements needed to meet the conditions provided a path for the approach to testing.  In order to meet all necessary conditions leading up to the error message there were two important steps that were needed.  First the inputChar function would need to generate a set of random characters to operate the state change necessary to trigger the error message.  After all state change conditions had been met the inputString function would need to generate a string to exactly match the test string “reset”.


  Approach

  Looking at the conditions that needed to be met and the expected inputs I felt there were two valid approaches that could both prove to be useful in testing.  The first approach would be to only pull random characters from the limited set of expected characters.  This would help simplify setting up the code initially as the random values were from a very confined set reducing combinations and program runtime.  The second approach that would be more useful long term to detect other potential function issues would be to pull random characters from the entire set of the type of expected characters increasing possible combinations and program runtime.  This would present a much longer runtime and complexity that would be easier to introduce as some of the initial work with a limited set of characters was already in place.

  Moving forward with this approach I created a set of define directive variables to decide how to test the compiled program switching between the types of input range (TESTCHARFULLKEYBOARD, TESTSTRINGFULLALPHABET).  In order to display debug messages to ensure I could check the validity of the random numbers generated with the character output I added a define directive variable to turn the messages on and off (TESTPRINTDEBUG).


  inputChar() Code Overview

    Generating a random character to pass back to the testme function to increment the state variable.

    Test Method 1 - Limited Test Characters (TESTCHARFULLKEYBOARD=false)

      The code for this more limited test creates a random number to pull a character from a predefined string limited to the 9 characters that were actually being looked for in the condition statements "[({ ax})]".  The character at the random number position is returned to the user.

      There is a 1 in 9 chance of pulling the correct character to increment the state variable.  The test for state increment needs to be passed 9 times prior to meeting the string condition checks.  As such the likelihood of incrementing the state variable to equal a value of 9 would take between 9 and 81 times through the while loop to reach the condition check for the string.

    Test Method 2 - Full Keyboard Character Input (TESTCHARFULLKEYBOARD=true)

      The code for the full keyboard character input range generates a random number and then adds an offset.  This moves the random number range into the set of ASCII characters that correspond to keyboard input from a user. This number is assigned to a character variable which is passed to the user and will be interpreted as the correct random character.

      Pulling randomly from the full set of characters that can be generated from a keyboard there is a 1 in 96 chance of pulling the correct character to increment the state variable.  The test for state increment needs to be passed 9 times prior to meeting the string condition checks.  As such the likelihood of incrementing the state variable to equal a value of 9 would take between 9 and 864 times through the while loop to reach the condition check for the string.



  inputString() Code Overview

    Generating a string of 5 randomly generated characters with a null terminator at the end.

    As a testing design decision I chose to hard code the null terminator based on the fact that it is necessary for any c-style string we are looking for, without it in place we could introduce new bugs or crashes to the test suite. The string that’s generated is always the same length never shorter or longer to match the hard coded conditions that must be met in the testme function.

    Test Method 1 - Limited Test Characters (TESTSTRINGFULLALPHABET=false)

      The code for this limited test creates a random number to pull a character from a predefined string limited to the 4 characters that were actually being looked for in the condition statements "erst".  The code goes through a for loop which randomly generates a number, then the character in the random position of the string is copied to the newly constructed string.  Following the for loop a null terminator is added to the correct position and the string is returned to the calling function.

      With the use of 4 characters and the necessary 5 characters in the string 1024 Permutations with repetition of potential letters. Per character position there is a 1 in 4 chance of pulling the correct character to increment the state variable per character.

    Test Method 2 - Full Keyboard Lowercase Alphabet Input (TESTSTRINGFULLALPHABET=true)

      The code for the full lowercase alphabet test creates a random number and then is offset to put the random number into the ASCII range for only lowercase alphabet input.  The code goes through a for loop which randomly generates a number, then current position in the string is assigned the number corresponding to the correct ASCII character.  Following the for loop a null terminator is added to the correct position and the string is returned to the calling function.

      Pulling randomly from the full set of characters that can be generated from a keyboard there is a 1 in 26 chance of pulling the correct character per position in the string with 5 total characters. With the use of 26 characters and the necessary 5 character positions in the string there are 11,881,376 Permutations with repetition of possible letters

      I chose to limit the testing characters to the lowercase alphabet based on the fact that the testme function was only looking for lowercase and the inclusion of full keyboard input would move the number of permutations from  11,881,376 to 8,153,726,976.  This would greatly increase the time necessary to reach the error message conditions.


  Test Results

    The first method utilized for both functions is much faster since it only tested the exact set of characters that were being looked for in the testme function at random.  This is the fastest way to produce the error message usually within only a few hundred iterations of the while loop.

    The second method for both functions was much slower, however with the inclusion of a much larger set of characters the could more thoroughly test the conditions necessary to meet the error message.  This increase in time would give more opportunity to catch any failures in the testme code.  This method had a much larger range of iterations from half a million up to ten million on some executions of the code.
    Limiting the input ranges made a drastic change in overall runtime to produce the error message.  If the goal is simply to produce the error message a very limited set of expected characters will produce the results with the least computation.  However, if the goal is to test the condition statements in the testme function leading up until the error message expanding the input range will greatly increase the chance of catching bugs or crashes relating to that code.

*/
