CS_362_Software Engineering
Quiz #2
thalijw

For this quiz we need to generate a random character and a random string, I started
with inputChar(), created a random number between 126 and 32 which are the limits for 
the ASCII characters for the all the keybaoard keys. Then I casted the number to a
character and returned it form the function.

For *inputString(), to limit the probability of taking a long time to find the "rest" string
which would be (26*26)^5 I used only the lowercase limits from the ASCII to have the probability
be (26)^5, I also knew that I have to fix the last character in the string to '\0' the termination
character. so I created a for loop to randomly assign the characters to the string with fixed last
character to '\0'.

The program ran about a minute unitl it found the right string "rest", we can make this process
faster by further restrict the seach of the random characters if we can fix one or more of the 
characters.


