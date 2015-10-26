// -----------------------Quiz 2 Documentation -------------------------------

The first thing I did was write a random number generator. I added a function
called GenerateRandomNumber() which takes a minimum number and maximum number
and it finds a number within that range including the min and max number.

Next thing I did was implement inputChar(). I looked at the ASCII table to 
determine the appropriate range to cover all of the state setting "if" 
statements. Then I tested this. The output showed that the state eventually
gets to 9. So that finishes this function.

Moving on to implement inputString(). I realized that this function returns a
char pointer. Usually a char pointer mains that we have to either pass in 
a buffer into inputString() or make testme() deallocate the allocated char
array in inputString(). Since I assumed that I cant modify testme(), both those
options were invalid. I decided to create a global char pointer, and 
allocate/deallocate that pointer within inputString(). This worked perfectly!
The first thing I do in inputString() is deallocate the global char pointer,
then I reallocate a new char array. Then, I fill up the array with 5 random 
characters and set a null terminator at the 6th position. The string is returned
to testme(). I limited the scope of the possible random strings by setting the
range as narrow as possible in order to get the word 'reset' without taking
a long time. I test all the letters between 'e' and 't'. This gets me the 
error within a reasonable amount of time.

In summery, inputChar() trys all the characters between 'space' and '~' in order
get the state to 9. Then inputString() trys to randomly create a string with 
all the letters between 'e' and 't', inclusive, to create the word 'reset.'